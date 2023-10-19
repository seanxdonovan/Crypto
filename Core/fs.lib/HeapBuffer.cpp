#include "precomp.h"
#include "declarations.h"
#include "Buffer.h"
#include "HeapBuffer.h"

namespace fs
{
	const Buffer::Offset expansionSize = 4096;

	void HeapBuffer::Resize(Offset newDataSize)
	{
		const byte *pData = Data();
		size_t currentSize = Size();

		byte *pNewData = new byte[newDataSize];
		
		Offset copySize;
		if (currentSize >= newDataSize)
		{
			copySize = newDataSize;
		}
		else
		{
			copySize = currentSize;
		}
		Buffer s((fs::byte *)pData, copySize);
		Buffer d(pNewData, copySize);
		FastCopy(s, &d);

		i_setData(pNewData, newDataSize);
	
		delete [] pData;
	}

	HeapBuffer::HeapBuffer(const HeapBuffer &p_rhs)
	{
		byte *p = new byte[p_rhs.Size()];
		i_setData(p, p_rhs.Size());
		Copy(p_rhs, this);
	}

	HeapBuffer&	HeapBuffer::operator=(const HeapBuffer &p_rhs)
	{
		if (p_rhs.Data() != Data())
		{
			Resize(p_rhs.Size());
			Copy(p_rhs, this);
		}

		return *this;
	}

} /* namespace fs */

/* End Of File: HeapBuffer.cpp */
