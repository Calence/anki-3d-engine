// Copyright (C) 2009-2015, Panagiotis Christopoulos Charitos.
// All rights reserved.
// Code licensed under the BSD License.
// http://www.anki3d.org/LICENSE

#include "anki/resource/GenericResource.h"

namespace anki {

//==============================================================================
GenericResource::~GenericResource()
{
	m_data.destroy(getAllocator());
}

//==============================================================================
Error GenericResource::load(const ResourceFilename& filename)
{
	ResourceFilePtr file;
	ANKI_CHECK(openFile(filename, file));

	PtrSize size = file->getSize();
	m_data.create(getAllocator(), size);
	ANKI_CHECK(file->read(&m_data[0], size));

	return ErrorCode::NONE;
}

} // end namespace anki

