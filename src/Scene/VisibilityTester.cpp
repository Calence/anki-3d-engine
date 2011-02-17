#include <boost/foreach.hpp>
#include "VisibilityTester.h"
#include "Scene.h"
#include "ModelNode.h"
#include "ModelPatchNode.h"
#include "Material.h"
#include "Sphere.h"
#include "PointLight.h"
#include "SpotLight.h"


//======================================================================================================================
// CmpDistanceFromOrigin::operator()                                                                                   =
//======================================================================================================================
bool VisibilityTester::CmpDistanceFromOrigin::operator()(const RenderableNode* a, const RenderableNode* b) const
{
	return (a->getWorldTransform().getOrigin() - o).getLengthSquared() <
	       (b->getWorldTransform().getOrigin() - o).getLengthSquared();
}


//======================================================================================================================
// Constructor                                                                                                         =
//======================================================================================================================
VisibilityTester::VisibilityTester(Scene& scene_):
	scene(scene_)
{}


//======================================================================================================================
// test                                                                                                                =
//======================================================================================================================
void VisibilityTester::test(Camera& cam)
{
	//
	// Collect the lights for the main cam
	//
	cam.getVisiblePointLights().clear();
	cam.getVisibleSpotLights().clear();

	BOOST_FOREACH(Light* light, scene.getLights())
	{
		switch(light->getType())
		{
			// Point
			case Light::LT_POINT:
			{
				PointLight* pointl = static_cast<PointLight*>(light);

				Sphere sphere(pointl->getWorldTransform().getOrigin(), pointl->getRadius());
				if(cam.insideFrustum(sphere))
				{
					cam.getVisiblePointLights().push_back(pointl);
				}
				break;
			}
			// Spot
			case Light::LT_SPOT:
			{
				SpotLight* spotl = static_cast<SpotLight*>(light);

				if(cam.insideFrustum(spotl->getCamera()))
				{
					cam.getVisibleSpotLights().push_back(spotl);
				}
				break;
			}
		} // end switch
	} // end for all lights

	//
	// Get the renderables for the main cam
	//
	getRenderableNodes(false, cam);

	//
	// For every spot light camera collect the renderable nodes
	//
	BOOST_FOREACH(SpotLight* spot, cam.getVisibleSpotLights())
	{
		getRenderableNodes(true, spot->getCamera());
	}
}


//======================================================================================================================
// test                                                                                                                =
//======================================================================================================================
template<typename Type>
bool VisibilityTester::test(const Type& tested, const Camera& cam)
{
	return cam.insideFrustum(tested.getBoundingShapeWSpace());
}


//======================================================================================================================
// getRenderableNodes                                                                                                  =
//======================================================================================================================
void VisibilityTester::getRenderableNodes(bool skipShadowless, Camera& cam)
{
	cam.getVisibleMsRenderableNodes().clear();
	cam.getVisibleBsRenderableNodes().clear();

	BOOST_FOREACH(const ModelNode* node, scene.getModelNodes())
	{
		// Skip if the ModeNode is not visible
		if(!test(*node, cam))
		{
			continue;
		}

		// If not test every patch individually
		BOOST_FOREACH(const ModelPatchNode* modelPatchNode, node->getModelPatchNodes())
		{
			// Skip shadowless
			if(skipShadowless && !modelPatchNode->getCpMtl().isShadowCaster())
			{
				continue;
			}

			// Test if visible by main camera
			if(test(*modelPatchNode, cam))
			{
				if(modelPatchNode->getCpMtl().isBlendingEnabled())
				{
					cam.getVisibleBsRenderableNodes().push_back(modelPatchNode);
				}
				else
				{
					cam.getVisibleMsRenderableNodes().push_back(modelPatchNode);
				}
			}
		}
	}

	//
	// Sort the renderables from closest to the camera to the farthest
	//
	std::sort(cam.getVisibleMsRenderableNodes().begin(), cam.getVisibleMsRenderableNodes().end(),
	          CmpDistanceFromOrigin(cam.getWorldTransform().getOrigin()));
	std::sort(cam.getVisibleBsRenderableNodes().begin(), cam.getVisibleBsRenderableNodes().end(),
	          CmpDistanceFromOrigin(cam.getWorldTransform().getOrigin()));
}
