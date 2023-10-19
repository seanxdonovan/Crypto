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

#include "HeapBuffer.h"

namespace fs
{
	void Stream::Read(Buffer p_buffer, Buffer *p_pValid)
	{
		sRaiseError(("Read not supported on this stream type."));
	}

	void Stream::Seek(Offset p_offset)
	{
		sRaiseError(("Cannot Seek on this stream type."));
	}

	void Stream::Flush()
	{
		sRaiseError(("Not supported"));
	}

	Stream::Offset Stream::Tell() const
	{
		sRaiseError(("Not supported"));
		
		return -1;
	}

	bool Stream::EndOfStream()
	{
		return false;
	}

	void Copy(Stream& p_from, Stream& p_to, Stream::Offset p_amount)
	{
		HeapBuffer b(8192);

		Stream::Offset nChunks = p_amount / b.Size();
		dword nRemaining = p_amount % b.Size();

		for (Stream::Offset n = 0; n < nChunks; ++n)
		{
			p_from.Read(b);
			p_to.Write(b);
		}

		if (nRemaining > 0)
		{
			b.Resize(nRemaining);

			p_from.Read(b);
			p_to.Write(b);
		}
	}

	static const char lineTerminator[] = {13, 10, 0};
	void WriteLn(Stream& p_to, const std::string& p_text)
	{
		p_to.Write(p_text);
		p_to.Write(Buffer((byte *)lineTerminator, 2));
	}

	void WriteLn(Stream& p_to, fs::dword p_depth, const std::string& p_text, fs::byte p_prefix)
	{
		if (p_depth > 0)
		{
			fs::HeapBuffer hb(p_depth);
			hb.Fill(p_prefix);
			p_to.Write(hb);
		}

		WriteLn(p_to, p_text);
	}

	void WriteLn(Stream& p_to, fs::dword p_depth, const std::string& p_text, const std::string& p_prefix)
	{
		fs::dword count = p_depth;
		while (count > 0)
		{
			p_to.Write(p_prefix);
			--count;
		}
		WriteLn(p_to, p_text);
	}

	//
	// not robust does not back track to the orgination of a
	// partial termination point. Use LineReader instead.
	//

	void ReadLn(Stream& p_from, std::string *p_pText, const char *p_sTerminator /* = 0 */)
	{
		if (0 == p_sTerminator)
		{
			p_sTerminator = lineTerminator;
		}

		size_t terminatorDepth = 0;

		std::string tmp;
		while (p_sTerminator[terminatorDepth] && !p_from.EndOfStream())
		{
			fs::byte b;
			p_from.Read(&b);

			if (terminatorDepth > 0)
			{
				if (p_sTerminator[terminatorDepth] == b)
				{
					++terminatorDepth;
					tmp += b;
				}
				else
				{
					terminatorDepth = 0;
					(*p_pText) += tmp;
					(*p_pText) += b;
					tmp.clear();
				}
			}
			else
			{
				if (b == p_sTerminator[0])
				{
					terminatorDepth = 1;
					tmp = b;
				}
				else
				{
					(*p_pText) += b;
				}
			}
		}
	}
}

/* End Of File: Stream.cpp */
