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
#include "BufferedReader.h"


namespace fs
{
	BufferedReader::BufferedReader(Stream& p_stream, Stream::Offset p_lengthToRead, Buffer& p_buffer)
	    : m_nBuffered(0)
	    , m_nCurrentOffset(0)
	    , m_totalToRead(p_lengthToRead)
	    , m_nRead(0)
	    , m_stream(p_stream)
	    , m_buffer(p_buffer)
	{
	}

	byte BufferedReader::Get()
	{
		sPrecondition(!End());

		if (m_nCurrentOffset >= m_nBuffered)
		{
			i_fillBuffer();
		}

		const byte ch = m_buffer[m_nCurrentOffset];

		++m_nCurrentOffset;
		++m_nRead;

		return ch;
	}

	void BufferedReader::Read(::fs::Buffer p_buffer, ::fs::Buffer *p_pRead)
	{
		::fs::Buffer::Offset count = 0;
		
		while (!End() && count < p_buffer.Size())
		{
			if (m_nCurrentOffset >= m_nBuffered)
			{
				i_fillBuffer();
			}

			auto nRemainingToRead = p_buffer.Size() - count;
			auto nLeftInBuffer    = m_nBuffered - m_nCurrentOffset;

			auto nToReadThisTime = nLeftInBuffer;
			if (nToReadThisTime > nRemainingToRead)
			{
				nToReadThisTime = nRemainingToRead;
			}

			auto source = m_buffer.Reference(m_nCurrentOffset, nToReadThisTime);
			auto target = p_buffer.Reference(count, nToReadThisTime);
			::fs::FastCopy(source, &target);

			m_nCurrentOffset += nToReadThisTime;
			m_nRead          += nToReadThisTime;
			count            += nToReadThisTime;
		}

		*p_pRead = p_buffer.Reference(0, count);
	}

	bool BufferedReader::Consume(::fs::Buffer::Offset p_size, ::fs::Buffer *p_pRead)
	{
		const auto nLeftInBuffer    = m_nBuffered - m_nCurrentOffset;

		if (p_size < nLeftInBuffer)
		{
			*p_pRead = m_buffer.Reference(m_nCurrentOffset, p_size);

			m_nCurrentOffset += p_size;
			m_nRead += p_size;

			return true;
		}

		return false;
	}

#if 0
	template <> struct Coerce<fs::qword, size_t>
	{
		inline Coerce(fs::qword p_v, size_t *p_pV)
		{
			*p_pV = p_v;
		}
	};
#endif
	void BufferedReader::i_fillBuffer()
	{
		sPrecondition(m_nCurrentOffset >= m_nBuffered);

		Buffer::Offset nToRead = m_buffer.Size();
		Stream::Offset nRemainingToBeRead = m_totalToRead - m_nRead;

		if (nRemainingToBeRead < nToRead)
		{
			Coerce<Stream::Offset, Buffer::Offset>(nRemainingToBeRead, &nToRead);
		}

		m_stream.Read(m_buffer.Reference(0, nToRead));
		m_nBuffered = nToRead;
		m_nCurrentOffset = 0;
	}

	bool BufferedReader::End() const
	{
		return (m_nRead == m_totalToRead);
	}

	void ReadLn(BufferedReader& p_reader, std::string *p_pText)
	{
		const byte CR = 13;
		const byte LF = 10;

		enum State
		{
			InText,
			SawCR,
		} state = InText;

		while (!p_reader.End())
		{
			byte b = p_reader.Get();
			if (InText == state)
			{
				if (CR == b)
				{
					state = SawCR;
				}
				else if (LF == b)
				{
					return;
				}
				else
				{
					(*p_pText) += b;
				}
			}
			else if (SawCR == state)
			{
				if (LF == b)
				{
					return;
				}
				else
				{
					*p_pText += CR;
					*p_pText += b;
				}
			}
		}
	}

	void ReadLF(BufferedReader& p_reader, std::string *p_pText)
	{
		const byte LF = 10;

		while (!p_reader.End())
		{
			byte b = p_reader.Get();
			if (LF == b)
			{
				return;
			}

			(*p_pText) += b;
		}
	}
}

/* End Of File: BufferedReader.cpp */
