#include "precomp.h"
#include "declarations.h"
#include "Buffer.h"
#include "HeapBuffer.h"
#include "ExpandingBuffer.h"


namespace fs
{

	ExpandingBuffer::ExpandingBuffer(const dword p_initialSize)
		: HeapBuffer(p_initialSize),
		  m_writeOffset(0)
	{ 
	}

	ExpandingBuffer::~ExpandingBuffer()
	{
	}

	void ExpandingBuffer::Write(const Buffer& p_data)
	{
		if (m_writeOffset + p_data.Size() > HeapBuffer::Size())
		{
			int considerExpansionPolicyHere;
			HeapBuffer::Resize(m_writeOffset + p_data.Size());
		}

		HeapBuffer::Write(p_data, m_writeOffset);
		m_writeOffset += p_data.Size();
	}

	void ExpandingBuffer::Write(const char *p_pString)
	{
		Write(Buffer((byte *)p_pString, strlen(p_pString)));
	}

	void ExpandingBuffer::Write(const std::string& p_s)
	{
		Write(Buffer((byte *)p_s.c_str(), p_s.size()));
	}

	void ExpandingBuffer::Seek(dword p_offset)
	{
		m_writeOffset = p_offset;
	}

	void ExpandingBuffer::Resize(dword p_newSize)
	{
		HeapBuffer::Resize(p_newSize);

		if (m_writeOffset > p_newSize)
		{
			m_writeOffset = p_newSize;
		}
	}

	Buffer::Offset ExpandingBuffer::DataSize() const
	{
		return m_writeOffset;
	}

	byte *ExpandingBuffer::Lock()
	{
		return HeapBuffer::Data();
	}

	void ExpandingBuffer::Unlock(Offset p_newWriteOffset)
	{
		sAssert(HeapBuffer::Size() >= p_newWriteOffset);
		m_writeOffset = p_newWriteOffset;
	}


	fs::Buffer ExpandingBuffer::DataBuffer()
	{
		return fs::Buffer(Data(), DataSize());
	}


} /* namespace fundamental */


/* End Of File: ExpandingBuffer.cpp */
