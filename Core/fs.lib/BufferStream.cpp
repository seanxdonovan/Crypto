#include "precomp.h"
#include "declarations.h"
#include "Buffer.h"

#include "type.h"
#include "type.id.h"
#include "type.List.h"
#include "type.Traits.h"
#include "type.Conversion.h"

#include "ReferenceCountedPointer.h"
#include "Stream.h"
#include "BufferStream.h"

namespace fs
{
	BufferStream::BufferStream(Buffer& p_buffer)
	    : m_buffer(p_buffer)
	    , m_currentOffset(0)
	{
	}

	void BufferStream::Write(const Buffer& p_data)
	{
		sPrecondition((m_currentOffset + p_data.Size()) <= m_buffer.Size());

		m_buffer.Write(p_data, m_currentOffset);
		m_currentOffset += p_data.Size();
	}

	void BufferStream::Read(Buffer& p_into)
	{
		sPrecondition((m_currentOffset + p_into.Size()) <= m_buffer.Size());

		Copy(m_buffer.Reference(m_currentOffset, p_into.Size()), &p_into);
		m_currentOffset += p_into.Size();
	}

	void BufferStream::Seek(Offset p_offset)
	{
		sPrecondition(p_offset <= m_buffer.Size());

		m_currentOffset = p_offset;
	}

	Stream::Offset BufferStream::Tell() const
	{
		return m_currentOffset;
	}

	void BufferStream::Flush()
	{
		// nop
	}


	bool BufferStream::EndOfStream()
	{
		return m_currentOffset >= m_buffer.Size();
	}
} /* namespace fundamental */

/* End Of File: BufferStream.cpp */
