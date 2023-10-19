#include "precomp.h"
#include "declarations.h"
#include "Buffer.h"

#include "type.h"
#include "type.id.h"
#include "type.List.h"
#include "type.Traits.h"

#include "ReferenceCountedPointer.h"
#include "ReferenceCountedPointerDerived.h"
#include "Stream.h"
#include "NullStream.h"

namespace fs
{
	void NullStream::Write(const fs::Buffer&)
	{
	}

	void NullStream::Read(fs::Buffer&)
	{
		//
		// Shouldn't read return nbytesread?
		// in this case it would always be 0.
		//
	}

} /* namespace fundamental */

/* End Of File: NullStream.cpp */
