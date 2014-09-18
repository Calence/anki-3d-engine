// Copyright (C) 2014, Panagiotis Christopoulos Charitos.
// All rights reserved.
// Code licensed under the BSD License.
// http://www.anki3d.org/LICENSE

#include "anki/renderer/Renderer.h"
#include "anki/util/Exception.h"
#include "anki/scene/Camera.h"
#include "anki/scene/SceneGraph.h"
#include "anki/core/Counters.h"
#include "anki/misc/ConfigSet.h"

namespace anki {

//==============================================================================
Renderer::Renderer(
	Threadpool* threadpool, 
	ResourceManager* resources,
	GlDevice* gl,
	HeapAllocator<U8>& alloc,
	const ConfigSet& config)
:	m_threadpool(threadpool),
	m_resources(resources),
	m_gl(gl),
	m_alloc(alloc),
	m_ms(this), 
	m_is(this),
	m_pps(this),
	m_bs(this),
	m_dbg(this), 
	m_tiler(this),
	m_sceneDrawer(this)
{}

//==============================================================================
Renderer::~Renderer()
{}

//==============================================================================
void Renderer::init(const ConfigSet& config)
{
	// Set from the config
	m_width = config.get("width");
	m_height = config.get("height");
	m_lodDistance = config.get("lodDistance");
	m_framesNum = 0;
	m_samples = config.get("samples");
	m_isOffscreen = config.get("offscreen");
	m_renderingQuality = config.get("renderingQuality");
	m_tilesCount.x() = config.get("tilesXCount");
	m_tilesCount.y() = config.get("tilesYCount");

	m_tessellation = config.get("tessellation");

	// A few sanity checks
	if(m_samples != 1 && m_samples != 4 && m_samples != 8 && m_samples != 16
		&& m_samples != 32)
	{
		throw ANKI_EXCEPTION("Incorrect samples");
	}

	if(m_width < 10 || m_height < 10)
	{
		throw ANKI_EXCEPTION("Incorrect sizes");
	}

	// quad setup
	static const F32 quadVertCoords[][2] = {{1.0, 1.0}, {-1.0, 1.0}, 
		{1.0, -1.0}, {-1.0, -1.0}};

	GlCommandBufferHandle cmdBuff(m_gl);

	GlClientBufferHandle tmpBuff = GlClientBufferHandle(cmdBuff, 
		sizeof(quadVertCoords), (void*)&quadVertCoords[0][0]);

	m_quadPositionsBuff = GlBufferHandle(cmdBuff, GL_ARRAY_BUFFER, 
		tmpBuff, 0);

	m_drawQuadVert.load("shaders/Quad.vert.glsl", m_resources);

	// Init the stages. Careful with the order!!!!!!!!!!
	m_tiler.init();

	m_ms.init(config);
	m_is.init(config);
	m_bs.init(config);
	m_pps.init(config);
	m_dbg.init(config);

	// Default FB
	m_defaultFb = GlFramebufferHandle(cmdBuff, {});

	cmdBuff.finish();
}

//==============================================================================
void Renderer::render(SceneGraph& scene, 
	Array<GlCommandBufferHandle, JOB_CHAINS_COUNT>& cmdBuff)
{
	m_scene = &scene;
	Camera& cam = m_scene->getActiveCamera();

	// Calc a few vars
	//
	Timestamp camUpdateTimestamp = cam.FrustumComponent::getTimestamp();
	if(m_projectionParamsUpdateTimestamp 
			< m_scene->getActiveCameraChangeTimestamp()
		|| m_projectionParamsUpdateTimestamp < camUpdateTimestamp
		|| m_projectionParamsUpdateTimestamp == 1)
	{
		ANKI_ASSERT(cam.getCameraType() == Camera::Type::PERSPECTIVE);
		computeProjectionParams(cam.getProjectionMatrix());
		m_projectionParamsUpdateTimestamp = getGlobTimestamp();
	}

	ANKI_COUNTER_START_TIMER(RENDERER_MS_TIME);
	m_ms.run(cmdBuff[0]);
	ANKI_ASSERT(cmdBuff[0].getReferenceCount() == 1);
	cmdBuff[0].flush();
	ANKI_COUNTER_STOP_TIMER_INC(RENDERER_MS_TIME);

	m_tiler.runMinMax(m_ms._getDepthRt());

	ANKI_COUNTER_START_TIMER(RENDERER_IS_TIME);
	m_is.run(cmdBuff[1]);
	ANKI_COUNTER_STOP_TIMER_INC(RENDERER_IS_TIME);

	m_bs.run(cmdBuff[1]);

	ANKI_COUNTER_START_TIMER(RENDERER_PPS_TIME);
	if(m_pps.getEnabled())
	{
		m_pps.run(cmdBuff[1]);
	}
	ANKI_COUNTER_STOP_TIMER_INC(RENDERER_PPS_TIME);

	if(m_dbg.getEnabled())
	{
		m_dbg.run(cmdBuff[1]);
	}

	++m_framesNum;
}

//==============================================================================
void Renderer::drawQuad(GlCommandBufferHandle& cmdBuff)
{
	drawQuadInstanced(cmdBuff, 1);
}

//==============================================================================
void Renderer::drawQuadInstanced(
	GlCommandBufferHandle& cmdBuff, U32 primitiveCount)
{
	m_quadPositionsBuff.bindVertexBuffer(cmdBuff, 2, GL_FLOAT, false, 0, 0, 0);

	cmdBuff.drawArrays(GL_TRIANGLE_STRIP, 4, primitiveCount);
}

//==============================================================================
Vec3 Renderer::unproject(const Vec3& windowCoords, const Mat4& modelViewMat,
	const Mat4& projectionMat, const int view[4])
{
	Mat4 invPm = projectionMat * modelViewMat;
	invPm.invert();

	// the vec is in NDC space meaning: -1<=vec.x<=1 -1<=vec.y<=1 -1<=vec.z<=1
	Vec4 vec;
	vec.x() = (2.0 * (windowCoords.x() - view[0])) / view[2] - 1.0;
	vec.y() = (2.0 * (windowCoords.y() - view[1])) / view[3] - 1.0;
	vec.z() = 2.0 * windowCoords.z() - 1.0;
	vec.w() = 1.0;

	Vec4 out = invPm * vec;
	out /= out.w();
	return out.xyz();
}

//==============================================================================
void Renderer::computeProjectionParams(const Mat4& m)
{
	// First, z' = (m * Pv) / 2 + 0.5 where Pv is the view space position.
	// Solving that for Pv.z we get
	// Pv.z = A / (z' + B)
	// where A = (-m23 / 2) and B = (m22/2 - 0.5)
	// so we save the A and B in the projection params vector
	m_projectionParams.z() = -m(2, 3) * 0.5;
	m_projectionParams.w() = m(2, 2) * 0.5 - 0.5;

	// Using the same logic the Pv.x = x' * w / m00
	// so Pv.x = x' * Pv.z * (-1 / m00)
	m_projectionParams.x() = -1.0 / m(0, 0);

	// Same for y
	m_projectionParams.y() = -1.0 / m(1, 1);
}

//==============================================================================
void Renderer::createRenderTarget(U32 w, U32 h, GLenum internalFormat, 
	GLenum format, GLenum type, U32 samples, GlTextureHandle& rt)
{
	// Not very important but keep the resulution of render targets aligned to
	// 16
	if(0)
	{
		ANKI_ASSERT(isAligned(16, w));
		ANKI_ASSERT(isAligned(16, h));
	}

	GlTextureHandle::Initializer init;

	init.m_width = w;
	init.m_height = h;
	init.m_depth = 0;
#if ANKI_GL == ANKI_GL_DESKTOP
	init.m_target = (samples == 1) ? GL_TEXTURE_2D : GL_TEXTURE_2D_MULTISAMPLE;
#else
	ANKI_ASSERT(samples == 1);
	init.m_target = GL_TEXTURE_2D;
#endif
	init.m_internalFormat = internalFormat;
	init.m_format = format;
	init.m_type = type;
	init.m_mipmapsCount = 1;
	init.m_filterType = GlTextureHandle::Filter::NEAREST;
	init.m_repeat = false;
	init.m_anisotropyLevel = 0;
	init.m_genMipmaps = false;
	init.m_samples = samples;

	GlCommandBufferHandle cmdBuff(m_gl);
	rt = GlTextureHandle(cmdBuff, init);
	cmdBuff.finish();
}

//==============================================================================
GlProgramPipelineHandle Renderer::createDrawQuadProgramPipeline(
	GlProgramHandle frag)
{
	GlCommandBufferHandle cmdBuff(m_gl);

	Array<GlProgramHandle, 2> progs = {{m_drawQuadVert->getGlProgram(), frag}};

	GlProgramPipelineHandle ppline(cmdBuff, &progs[0], &progs[0] + 2);
	cmdBuff.finish();

	return ppline;
}

} // end namespace anki
