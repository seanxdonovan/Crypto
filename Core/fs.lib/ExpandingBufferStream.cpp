#include "precomp.h"
#include "declarations.h"
#include "Buffer.h"

#include "type.h"
#include "type.id.h"
#include "type.List.h"
#include "type.Traits.h"

#include "ReferenceCountedPointer.h"
#include "ReferenceCountedPointerDerived.h"
#include "HeapBuffer.h"
#include "ExpandingBuffer.h"
#include "Stream.h"
#include "ExpandingBufferStream.h"

namespace fs
{
	ExpandingBufferStream::RCP ExpandingBufferStream::Make(ExpandingBuffer& p_buffer)
	{

		RCP p = RCP(new ExpandingBufferStream(p_buffer));

		return p;
	}


	void ExpandingBufferStream::Read(Buffer& p_into)
	{
		sPrecondition(m_readOffset + p_into.Size() <= m_buffer.Size());
		
		Copy(m_buffer.Reference(m_readOffset, p_into.Size()), &p_into);
		m_readOffset += p_into.Size();
	}


} /* namespace fs */

/* End Of File: ExpandingBufferStream.cpp */
