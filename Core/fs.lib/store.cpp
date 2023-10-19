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
#include "format.h"


#include "FixedBuffer.h"
namespace fs
{
	void storeBigEndian(word   p_value, Buffer *p_pBuffer)
	{
		(*p_pBuffer)[0] = (byte) (p_value  >> 8);
		(*p_pBuffer)[1] = (byte) (p_value);
	}

	void storeBigEndian(dword  p_value, Buffer *p_pBuffer)
	{
		dword bytemask = 0xFF000000;
		(*p_pBuffer)[0] = (byte)((p_value & bytemask) >> (8 * 3));

		bytemask >>= 8;
		(*p_pBuffer)[1] = (byte)((p_value & bytemask) >> (8 * 2));

		bytemask >>= 8;
		(*p_pBuffer)[2] = (byte)((p_value & bytemask) >> (8 * 1));

		bytemask >>= 8;
		(*p_pBuffer)[3] = (byte)((p_value & bytemask) >> (8 * 0));
	}


	void storeBigEndian(qword  p_value, Buffer *p_pBuffer)
	{
		qword bytemask = 0xFF00000000000000;
		(*p_pBuffer)[0] = (byte)((p_value & bytemask) >> (8 * 7));

		bytemask >>= 8;
		(*p_pBuffer)[1] = (byte)((p_value & bytemask) >> (8 * 6));

		bytemask >>= 8;
		(*p_pBuffer)[2] = (byte)((p_value & bytemask) >> (8 * 5));

		bytemask >>= 8;
		(*p_pBuffer)[3] = (byte)((p_value & bytemask) >> (8 * 4));

		bytemask >>= 8;
		(*p_pBuffer)[4] = (byte)((p_value & bytemask) >> (8 * 3));

		bytemask >>= 8;
		(*p_pBuffer)[5] = (byte)((p_value & bytemask) >> (8 * 2));

		bytemask >>= 8;
		(*p_pBuffer)[6] = (byte)((p_value & bytemask) >> (8 * 1));

		bytemask >>= 8;

		(*p_pBuffer)[7] = (byte)((p_value & bytemask)); // >> (8 * 0));
	}

	void storeBigEndian(dqword p_value, Buffer *p_pBuffer)
	{
		storeBigEndian(p_value.m_hi, p_pBuffer);
		storeBigEndian(p_value.m_low, &(p_pBuffer->Reference(8, 8)));
	}


#if 0
	void storeBigEndian(dqword p_value, Buffer *p_pBuffer)
	{
	}
#endif


#if 0
	void storeLittleEndian(word   p_value, Buffer *p_pBuffer)
	{
	}
#endif
	void storeLittleEndian(word  p_value, Buffer *p_pBuffer)
	{
		dword bytemask = 0x00FF;
		(*p_pBuffer)[0] = (byte)((p_value & bytemask) >> (8 * 0));

		bytemask <<= 8;
		(*p_pBuffer)[1] = (byte)((p_value & bytemask) >> (8 * 1));
	}

	void storeLittleEndian(dword  p_value, Buffer *p_pBuffer)
	{
		dword bytemask = 0x000000FF;
		(*p_pBuffer)[0] = (byte)((p_value & bytemask) >> (8 * 0));

		bytemask <<= 8;
		(*p_pBuffer)[1] = (byte)((p_value & bytemask) >> (8 * 1));

		bytemask <<= 8;
		(*p_pBuffer)[2] = (byte)((p_value & bytemask) >> (8 * 2));

		bytemask <<= 8;
		(*p_pBuffer)[3] = (byte)((p_value & bytemask) >> (8 * 3));

	}

	void storeLittleEndian(qword  p_value, Buffer *p_pBuffer)
	{
		qword bytemask = 0x00000000000000FF;
		(*p_pBuffer)[0] = (byte)((p_value & bytemask) >> (8 * 0));

		bytemask <<= 8;
		(*p_pBuffer)[1] = (byte)((p_value & bytemask) >> (8 * 1));

		bytemask <<= 8;
		(*p_pBuffer)[2] = (byte)((p_value & bytemask) >> (8 * 2));

		bytemask <<= 8;
		(*p_pBuffer)[3] = (byte)((p_value & bytemask) >> (8 * 3));

		bytemask <<= 8;
		(*p_pBuffer)[4] = (byte)((p_value & bytemask) >> (8 * 4));

		bytemask <<= 8;
		(*p_pBuffer)[5] = (byte)((p_value & bytemask) >> (8 * 5));

		bytemask <<= 8;
		(*p_pBuffer)[6] = (byte)((p_value & bytemask) >> (8 * 6));

		bytemask <<= 8;

		(*p_pBuffer)[7] = (byte)((p_value & bytemask) >> (8 * 7));
	}




#if 0
	void storeLittleEndian(dqword p_value, Buffer *p_pBuffer)
	{
	}
#endif

	void loadLittleEndian(const Buffer& p_buffer, word   *p_pValue)
	{
		word v = p_buffer[1];
		v <<= 8;
		v |= p_buffer[0];

		*p_pValue = v;
	}

	void loadLittleEndian(const Buffer& p_buffer, dword  *p_pValue)
	{
		dword v = p_buffer[3];
		v <<= 8;
		v |= p_buffer[2];
		v <<= 8;
		v |= p_buffer[1];
		v <<= 8;
		v |= p_buffer[0];

		*p_pValue = v;
	}

	void loadLittleEndian(const Buffer& p_buffer, qword  *p_pValue)
	{
		dword v = p_buffer[7];
		v <<= 8;
		v |= p_buffer[6];
		v <<= 8;
		v |= p_buffer[5];
		v <<= 8;
		v |= p_buffer[4];
		v <<= 8;
		v |= p_buffer[3];
		v <<= 8;
		v |= p_buffer[2];
		v <<= 8;
		v |= p_buffer[1];
		v <<= 8;
		v |= p_buffer[0];

		*p_pValue = v;
	}

#if 0
	void loadLittleEndian(const Buffer& p_buffer, dqword *p_pValue)
	{
	}
#endif



	void readBigEndian(Stream& p_stream, word *p_pValue)
	{
		FixedBuffer<2> buffer;
		p_stream.Read(buffer);
		(*p_pValue) = (buffer[0] << 8 | buffer[1]);
	}

	void readBigEndian(Stream& p_stream, dword *p_pValue)
	{
		FixedBuffer<4> buffer;
		p_stream.Read(buffer);

		(*p_pValue) = (buffer[0] << 24 | buffer[1] << 16 | buffer[2] << 8 | buffer[3]);
	}

	void loadBigEndian(const Buffer& p_buffer, word *p_pValue)
	{
		sPrecondition(p_buffer.Size() >= fs::Traits<word>::Size);
		(*p_pValue) = p_buffer[0];
		(*p_pValue) <<= 8;
		(*p_pValue) |= p_buffer[1];
	}

	void loadBigEndian(const Buffer& p_buffer, qword *p_pValue)
	{
		sPrecondition(p_buffer.Size() >= fs::Traits<qword>::Size);
		(*p_pValue)  = p_buffer[0];
		(*p_pValue) <<= 8;
		(*p_pValue) |= p_buffer[1];
		(*p_pValue) <<= 8;
		(*p_pValue) |= p_buffer[2];
		(*p_pValue) <<= 8;
		(*p_pValue) |= p_buffer[3];
		(*p_pValue) <<= 8;
		(*p_pValue) |= p_buffer[4];
		(*p_pValue) <<= 8;
		(*p_pValue) |= p_buffer[5];
		(*p_pValue) <<= 8;
		(*p_pValue) |= p_buffer[6];
		(*p_pValue) <<= 8;
		(*p_pValue) |= p_buffer[7];
	}

	void readBigEndian(Stream& p_stream, qword *p_pValue)
	{
		FixedBuffer<8> buffer;
		p_stream.Read(buffer);

		loadBigEndian(buffer, p_pValue);
	}

	void writeBigEndian(Stream& p_stream, dword p_value)
	{
		fs::byte b;

		b = static_cast<fs::byte>((p_value >> 24) & 0xFF);
		p_stream.Write(b);

		b = static_cast<fs::byte>((p_value >> 16) & 0xFF);
		p_stream.Write(b);

		b = static_cast<fs::byte>((p_value >>  8) & 0xFF);
		p_stream.Write(b);

		b = static_cast<fs::byte>( p_value        & 0xFF);
		p_stream.Write(b);
	}


	void writeBigEndian(Stream& p_stream, qword p_value)
	{
		fs::FixedBuffer<8> be;
		fs::qword tmp = p_value;

		be[7] = sCoerce(fs::byte, tmp & 0xFF);
		tmp >>= 8;
		be[6] = sCoerce(fs::byte, tmp & 0xFF);
		tmp >>= 8;
		be[5] = sCoerce(fs::byte, tmp & 0xFF);
		tmp >>= 8;
		be[4] = sCoerce(fs::byte, tmp & 0xFF);
		tmp >>= 8;
		be[3] = sCoerce(fs::byte, tmp & 0xFF);
		tmp >>= 8;
		be[2] = sCoerce(fs::byte, tmp & 0xFF);
		tmp >>= 8;
		be[1] = sCoerce(fs::byte, tmp & 0xFF);
		tmp >>= 8;
		be[0] = sCoerce(fs::byte, tmp & 0xFF);
		p_stream.Write(be);
	}

	void readLittleEndian(Stream& p_stream, word *p_pValue)
	{
		fs::Buffer b(p_pValue);
		p_stream.Read(b);
	}

	void readLittleEndian(Stream& p_stream, dword *p_pValue)
	{
		fs::Buffer b(p_pValue);
		p_stream.Read(b);
#if 0
		// architecture independent
		FixedBuffer<4> buffer;
		p_stream.Read(buffer);

		(*p_pValue) = (buffer[0] | buffer[1] << 8 | buffer[2] << 16 | buffer[3] << 24);
#endif
	}

	void readLittleEndian(Stream& p_stream, qword *p_pValue)
	{
		fs::Buffer b(p_pValue);
		p_stream.Read(b);
	}

	void writeLittleEndian(Stream& p_stream, dword p_value)
	{
		fs::byte b;

		b = static_cast<fs::byte>((p_value)       & 0xFF);
		p_stream.Write(b);

		b = static_cast<fs::byte>((p_value >>  8) & 0xFF);
		p_stream.Write(b);

		b = static_cast<fs::byte>((p_value >> 16) & 0xFF);
		p_stream.Write(b);

		b = static_cast<fs::byte>( p_value >> 24  & 0xFF);
		p_stream.Write(b);
	}

} /* namespace fs */

namespace fs
{
	void dump(const Buffer& p_buffer, Stream& p_stream)
	{
		const dword bytesPerLine = 16;
		const dword spacing = 4;
		std::string line;
		for (dword index = 0; index < p_buffer.Size(); ++index)
		{
			if (0 != index)
			{
				dword m = index % bytesPerLine;
				if (0 == m)
				{
					WriteLn(p_stream, line);
					line.clear();
				}
				else if (m != 0 && 0 == m % spacing )
				{
					line += ' ';
				}
			}

			std::string s = hex(p_buffer[index]);
			line += s;

		}
		WriteLn(p_stream, line);
	}
}

/* End Of File: store.cpp */
