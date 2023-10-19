#include "precomp.h"
#include "declarations.h"
#include "Buffer.h"

namespace fs
{
	
	const byte *ConstBuffer::Data() const
	{
		return m_pData;
	}

	const ConstBuffer::Offset ConstBuffer::Size() const
	{
		return m_size;
	}

	const byte ConstBuffer::operator[](Offset p_index) const
	{
		sPrecondition(p_index < m_size);

		return m_pData[p_index];
	}

	ConstBuffer::ConstBuffer(const byte *p_pData, Offset p_size)
			: m_pData(p_pData)
			, m_size(p_size)
	{
	}

	ConstBuffer::ConstBuffer(const ConstBuffer& p_rhs)
			: m_pData(p_rhs.m_pData)
			, m_size(p_rhs.m_size)
	{
	}

	ConstBuffer::~ConstBuffer()
	{
	}

	ConstBuffer& ConstBuffer::operator = (const ConstBuffer& p_rhs)
	{
		m_pData = p_rhs.m_pData;
		m_size = p_rhs.m_size;
		return *this;
	}

	ConstBuffer ConstBuffer::Reference(Offset p_start) const
	{
		sPrecondition(p_start <= m_size);

		return ConstBuffer(m_pData + p_start, m_size - p_start);
		
	}

	ConstBuffer ConstBuffer::Reference(Offset p_start, Offset p_length) const
	{
		sPrecondition(p_start <= m_size);
		sPrecondition(p_start + p_length <= m_size);

		return ConstBuffer(m_pData + p_start, p_length);
	}






















	void Buffer::Fill(byte p_b)
	{
		sPrecondition(0 != m_pData);

		Offset size = m_size;
		byte *p = m_pData;
		while (size > 0)
		{
			*p = p_b;
			++p;
			--size;
		}
	}

	void Buffer::Fill(word p_w)
	{
		sPrecondition(0 != m_pData);

		Offset size = m_size;

		sAssert(size % sizeof(p_w) == 0); // need a word multiple to fill with a word.
		word *p = (word *) m_pData;

		while (size > 0)
		{
			*p = p_w;

			++p;
			size -= sizeof(p_w);
		}
	}

	void Buffer::Fill(dword p_dw)
	{
		sPrecondition(0 != m_pData);

		Offset size = m_size;
		sAssert(size % sizeof(p_dw) == 0); // need a dword multiple to fill with a dword.

		dword *p = (dword *) m_pData;
		while (size > 0)
		{
			*p = p_dw;

			++p;
			size -= sizeof(p_dw);
		}
	}

	void Buffer::Fill(qword p_qw)
	{
		sPrecondition(0 != m_pData);

		Offset size = m_size;
		sAssert(size % sizeof(p_qw) == 0); // need a qword multiple to fill with a qword.

		qword *p = (qword *) m_pData;
		while (size > 0)
		{
			*p = p_qw;

			++p;
			size -= sizeof(p_qw);
		}
	}

	void Buffer::Replace(fs::byte p_value, fs::byte p_with)
	{
		for (Offset ix = 0; ix < Size(); ++ix)
		{
			if (p_value == (*this)[ix])
			{
				(*this)[ix] = p_with;
			}
		}
	}

	const ::fs::byte Buffer::back() const
	{
		return (*this)[Size() - 1];
	}

	::fs::byte& Buffer::back()
	{
		return (*this)[Size() - 1];
	}


	namespace internal
	{
		static char hex_table[] = {
			'0', '1', '2', '3',
			'4', '5', '6', '7',
			'8', '9', 'a', 'b',
			'c', 'd', 'e', 'f'
		};
	}

	std::string format(const Buffer& p_buffer)
	{
		std::string s;

		s.reserve(2 * (p_buffer.Size() + 1));

		s = "";
		fs::byte b;

		for (Buffer::Offset ix = 0; ix < p_buffer.Size(); ++ix)
		{
			b = p_buffer[ix];

			s += internal::hex_table[b >> 4];
			s += internal::hex_table[b & 0xF];
		}

		return s;
	}

	namespace
	{
		int values[] = 
		{
			-1, // '\0x00'
			-1, // '\0x01'
			-1, // '\0x02'
			-1, // '\0x03'
			-1, // '\0x04'
			-1, // '\0x05'
			-1, // '\0x06'
			-1, // '\0x07'
			-1, // '\0x08'
			-1, // '\0x09'
			-1, // '\0x0a'
			-1, // '\0x0b'
			-1, // '\0x0c'
			-1, // '\0x0d'
			-1, // '\0x0e'
			-1, // '\0x0f'
			-1, // '\0x10'
			-1, // '\0x11'
			-1, // '\0x12'
			-1, // '\0x13'
			-1, // '\0x14'
			-1, // '\0x15'
			-1, // '\0x16'
			-1, // '\0x17'
			-1, // '\0x18'
			-1, // '\0x19'
			-1, // '\0x1a'
			-1, // '\0x1b'
			-1, // '\0x1c'
			-1, // '\0x1d'
			-1, // '\0x1e'
			-1, // '\0x1f'
			-1, // ' '
			-1, // '!'
			-1, // '"'
			-1, // '#'
			-1, // '$'
			-1, // '%'
			-1, // '&'
			-1, // '''
			-1, // '('
			-1, // ')'
			-1, // '*'
			-1, // '+'
			-1, // ','
			-1, // '-'
			-1, // '.'
			-1, // '/'
			0, // '0'
			1, // '1'
			2, // '2'
			3, // '3'
			4, // '4'
			5, // '5'
			6, // '6'
			7, // '7'
			8, // '8'
			9, // '9'
			-1, // ':'
			-1, // ';'
			-1, // '<'
			-1, // '='
			-1, // '>'
			-1, // '?'
			-1, // '@'
			10, // 'A'
			11, // 'B'
			12, // 'C'
			13, // 'D'
			14, // 'E'
			15, // 'F'
			16, // 'G'
			17, // 'H'
			18, // 'I'
			19, // 'J'
			20, // 'K'
			21, // 'L'
			22, // 'M'
			23, // 'N'
			24, // 'O'
			25, // 'P'
			26, // 'Q'
			27, // 'R'
			28, // 'S'
			29, // 'T'
			30, // 'U'
			31, // 'V'
			32, // 'W'
			33, // 'X'
			34, // 'Y'
			35, // 'Z'
			-1, // '['
			-1, // '\'
			-1, // ']'
			-1, // '^'
			-1, // '_'
			-1, // '`'
			10, // 'a'
			11, // 'b'
			12, // 'c'
			13, // 'd'
			14, // 'e'
			15, // 'f'
			16, // 'g'
			17, // 'h'
			18, // 'i'
			19, // 'j'
			20, // 'k'
			21, // 'l'
			22, // 'm'
			23, // 'n'
			24, // 'o'
			25, // 'p'
			26, // 'q'
			27, // 'r'
			28, // 's'
			29, // 't'
			30, // 'u'
			31, // 'v'
			32, // 'w'
			33, // 'x'
			34, // 'y'
			35, // 'z'
			-1, // '{'
			-1, // '|'
			-1, // '}'
			-1, // '~'
			-1, // '\0x7f'
			-1, // '\0x80'
			-1, // '\0x81'
			-1, // '\0x82'
			-1, // '\0x83'
			-1, // '\0x84'
			-1, // '\0x85'
			-1, // '\0x86'
			-1, // '\0x87'
			-1, // '\0x88'
			-1, // '\0x89'
			-1, // '\0x8a'
			-1, // '\0x8b'
			-1, // '\0x8c'
			-1, // '\0x8d'
			-1, // '\0x8e'
			-1, // '\0x8f'
			-1, // '\0x90'
			-1, // '\0x91'
			-1, // '\0x92'
			-1, // '\0x93'
			-1, // '\0x94'
			-1, // '\0x95'
			-1, // '\0x96'
			-1, // '\0x97'
			-1, // '\0x98'
			-1, // '\0x99'
			-1, // '\0x9a'
			-1, // '\0x9b'
			-1, // '\0x9c'
			-1, // '\0x9d'
			-1, // '\0x9e'
			-1, // '\0x9f'
			-1, // '\0xa0'
			-1, // '\0xa1'
			-1, // '\0xa2'
			-1, // '\0xa3'
			-1, // '\0xa4'
			-1, // '\0xa5'
			-1, // '\0xa6'
			-1, // '\0xa7'
			-1, // '\0xa8'
			-1, // '\0xa9'
			-1, // '\0xaa'
			-1, // '\0xab'
			-1, // '\0xac'
			-1, // '\0xad'
			-1, // '\0xae'
			-1, // '\0xaf'
			-1, // '\0xb0'
			-1, // '\0xb1'
			-1, // '\0xb2'
			-1, // '\0xb3'
			-1, // '\0xb4'
			-1, // '\0xb5'
			-1, // '\0xb6'
			-1, // '\0xb7'
			-1, // '\0xb8'
			-1, // '\0xb9'
			-1, // '\0xba'
			-1, // '\0xbb'
			-1, // '\0xbc'
			-1, // '\0xbd'
			-1, // '\0xbe'
			-1, // '\0xbf'
			-1, // '\0xc0'
			-1, // '\0xc1'
			-1, // '\0xc2'
			-1, // '\0xc3'
			-1, // '\0xc4'
			-1, // '\0xc5'
			-1, // '\0xc6'
			-1, // '\0xc7'
			-1, // '\0xc8'
			-1, // '\0xc9'
			-1, // '\0xca'
			-1, // '\0xcb'
			-1, // '\0xcc'
			-1, // '\0xcd'
			-1, // '\0xce'
			-1, // '\0xcf'
			-1, // '\0xd0'
			-1, // '\0xd1'
			-1, // '\0xd2'
			-1, // '\0xd3'
			-1, // '\0xd4'
			-1, // '\0xd5'
			-1, // '\0xd6'
			-1, // '\0xd7'
			-1, // '\0xd8'
			-1, // '\0xd9'
			-1, // '\0xda'
			-1, // '\0xdb'
			-1, // '\0xdc'
			-1, // '\0xdd'
			-1, // '\0xde'
			-1, // '\0xdf'
			-1, // '\0xe0'
			-1, // '\0xe1'
			-1, // '\0xe2'
			-1, // '\0xe3'
			-1, // '\0xe4'
			-1, // '\0xe5'
			-1, // '\0xe6'
			-1, // '\0xe7'
			-1, // '\0xe8'
			-1, // '\0xe9'
			-1, // '\0xea'
			-1, // '\0xeb'
			-1, // '\0xec'
			-1, // '\0xed'
			-1, // '\0xee'
			-1, // '\0xef'
			-1, // '\0xf0'
			-1, // '\0xf1'
			-1, // '\0xf2'
			-1, // '\0xf3'
			-1, // '\0xf4'
			-1, // '\0xf5'
			-1, // '\0xf6'
			-1, // '\0xf7'
			-1, // '\0xf8'
			-1, // '\0xf9'
			-1, // '\0xfa'
			-1, // '\0xfb'
			-1, // '\0xfc'
			-1, // '\0xfd'
			-1, // '\0xfe'
			-1, // '\0xff'
		}; // int values[]
	}

	bool decode(const std::string& p_hex, Buffer *p_pBuffer)
	{
		sPrecondition(p_hex.length() % 2 == 0);
		sPrecondition((p_hex.length() / 2 - 1) <= p_pBuffer->Size());

		if (p_hex.length() < 2)
		{
			return false;
		}
		if (p_hex[0] != '0')
		{
			return false;
		}
		if (p_hex[1] != 'x')
		{
			return false;
		}
		const size_t nBytes = (p_hex.length() - 2) / 2;

		for (dword index = 0; index < nBytes; ++index)
		{
			const char chHigh = p_hex[(index + 1) * 2];
			const char chLow = p_hex[(index + 1) * 2 + 1];
			if (!isxdigit(chHigh))
			{
				return false;
			}
			if (!isxdigit(chLow))
			{
				return false;
			}

			(*p_pBuffer)[index] =  values[chHigh] * 16 + values[chLow];
		}
		return true;
	}

	void Copy(const Buffer& p_from, Buffer* p_pTo)
	{
		sPrecondition(p_from.Size() <= p_pTo->Size());

		for (size_t index = 0; index < p_from.Size(); ++index)
		{
			(*p_pTo)[index] = p_from[index];
		}
	}

	void Move(const Buffer& p_from, Buffer *p_pTo)
	{
		sPrecondition(p_from.Size() <= p_pTo->Size());

		const byte *pEndFrom = p_from.Data() + p_from.Size();
		ptrdiff_t diff = p_pTo->Data() - pEndFrom;
		if (diff >= 0)
		{
			Copy(p_from, p_pTo);
		}
		else if (size_t(-diff) > p_from.Size())
		{
			Copy(p_from, p_pTo);
		}
		else
		{
			size_t index = p_from.Size();
			while (index > 0)
			{
				--index;
				(*p_pTo)[index] = p_from[index];
			}
		}
	}

	void Copy(const std::string& p_from, Buffer *p_pTo)
	{
		sPrecondition(p_from.length() <= p_pTo->Size());

		const fs::byte * const pData = reinterpret_cast<const fs::byte *>(p_from.c_str());
		const fs::Buffer::Offset size = p_from.length();
		fs::Buffer tmp(const_cast<fs::byte *>(pData), size);
		FastCopy(tmp, p_pTo);
	}


	void FastCopy(const Buffer& p_from, Buffer *p_pTo)
	{
		void *dest = p_pTo->Data();
		const void *src = p_from.Data();
		size_t s = p_from.Size();

#if defined(_M_IX86)
		_asm { 	       
		mov ecx, [s]
		mov esi, [src] 
		mov edi, [dest]
		shr ecx, 6 //mit mmx: 64bytes per iteration 
		jz  lower_64//if lower than 64 bytes
loop_64: //MMX transfers multiples of 64bytes 
		movq mm0,  0[ESI] //read sources
		movq mm1,  8[ESI] 
		movq mm2, 16[ESI] 
		movq mm3, 24[ESI] 
		movq mm4, 32[ESI] 
		movq mm5, 40[ESI] 
		movq mm6, 48[ESI] 
		movq mm7, 56[ESI] 
		movq  0[EDI], mm0 //write destination 
		movq  8[EDI], mm1 
		movq 16[EDI], mm2 
		movq 24[EDI], mm3 
		movq 32[EDI], mm4 
		movq 40[EDI], mm5 
		movq 48[EDI], mm6 
		movq 56[EDI], mm7 		

		add esi, 64 
		add edi, 64
		dec ecx 
		jnz loop_64    
		emms //close mmx operation
lower_64://transfer rest of buffer               
		mov ebx,esi
		sub ebx,src
		mov ecx,[s]
		sub ecx,ebx
		shr ecx, 3 //multiples of 8 bytes
		jz lower_8
loop_8:
		movq  mm0, [esi] //read source
		movq  [edi], mm0 //write destination 
		add esi, 8
		add edi, 8 
		dec ecx
		jnz loop_8
		emms //close mmx operation
lower_8:
		mov   ebx,esi
		sub   ebx,src 
		mov   ecx,[s] 
		sub   ecx,ebx	
		rep		movsb	 
ende:
		mov   eax, [dest] //return dest
		}
#else
		memcpy(p_pTo->Data(), p_from.Data(), p_from.Size());
#endif
	}

/* SSE memcpy
 *

void X_aligned_memcpy_sse2(void* dest, const void* src, const unsigned long size_t)
{

  __asm
  {
    mov esi, src;    //src pointer
    mov edi, dest;   //dest pointer

    mov ebx, size_t; //ebx is our counter 
    shr ebx, 7;      //divide by 128 (8 * 128bit registers)


    loop_copy:
      prefetchnta 128[ESI]; //SSE2 prefetch
      prefetchnta 160[ESI];
      prefetchnta 192[ESI];
      prefetchnta 224[ESI];

      movdqa xmm0, 0[ESI]; //move data from src to registers
      movdqa xmm1, 16[ESI];
      movdqa xmm2, 32[ESI];
      movdqa xmm3, 48[ESI];
      movdqa xmm4, 64[ESI];
      movdqa xmm5, 80[ESI];
      movdqa xmm6, 96[ESI];
      movdqa xmm7, 112[ESI];

      movntdq 0[EDI], xmm0; //move data from registers to dest
      movntdq 16[EDI], xmm1;
      movntdq 32[EDI], xmm2;
      movntdq 48[EDI], xmm3;
      movntdq 64[EDI], xmm4;
      movntdq 80[EDI], xmm5;
      movntdq 96[EDI], xmm6;
      movntdq 112[EDI], xmm7;

      add esi, 128;
      add edi, 128;
      dec ebx;

      jnz loop_copy; //loop please
    loop_copy_end:
  }
}

 */
	


//
	// Scan the buffer looking for literal pattern.
	//
	void Find(const Buffer& p_pattern, const Buffer& p_in, std::vector<Buffer::Offset> *p_pAtOffsets)
	{
		Buffer::Offset n = 0;

		Buffer::Offset nInPat = 0;
		Buffer::Offset nPatternStart = 0;
		while (n < p_in.Size())
		{
			sAssert((nPatternStart + nInPat) == n);
			if (p_pattern[nInPat] == p_in[n])
			{
				++nInPat;
				if (nInPat == p_pattern.Size())
				{
					p_pAtOffsets->push_back(nPatternStart);
					nInPat = 0;
					nPatternStart = n + 1;
				}
			}
			else
			{
				//
				// back up to where we started.
				//
				nInPat = 0;
				n = nPatternStart;
				++nPatternStart;
			}

			++n;
		}
	}


	bool IsEqual(const Buffer& p_lhs, const Buffer& p_rhs)
	{
		if (p_lhs.Size() != p_rhs.Size())
		{
			return false;
		}

		for (Buffer::Offset ix = 0; ix < p_lhs.Size(); ++ix)
		{
			if (p_lhs[ix] != p_rhs[ix])
			{
				return false;
			}
		}

		return true;
	}

	bool IsLess(const Buffer& p_lhs, const Buffer& p_rhs)
	{
		if (0 == p_lhs.Size() && 0 == p_rhs.Size())
		{
			return false;
		}
		if (0 == p_lhs.Size())
		{
			return true;
		}
		size_t nToCompare = p_lhs.Size();
		if (nToCompare > p_rhs.Size())
		{
			nToCompare = p_rhs.Size();
		}

		for (size_t ix = 0; ix < nToCompare; ++ix)
		{
			if (p_lhs[ix] >= p_rhs[ix])
			{
				return false;
			}
		}

		return true;
	}


	void BufferWriter::put(const std::string& p_s)
	{
		put(sCoerce(fs::dword, p_s.size()));
		strncpy(m_buffer.Reference(m_offset).Data<char>(), p_s.c_str(), p_s.size());
		m_offset += p_s.size();
	}

}

namespace fs
{
	//
	// Return Line a buffer from beginning of the buffer to the
	// NewLine either LF CRLF or CR.  Return the remainder starting
	// after the NewLine.  Return false if remainder is not valid
	// (End of Buffer was reached.)
	//
	bool NextLine(::fs::Buffer p_buffer, ::fs::Buffer *p_pLine, ::fs::Buffer *p_pRemainder)
	{
		if (0 == p_buffer.Size())
		{
			*p_pLine = p_buffer;
			return false;
		}

		const byte CR = 13;
		const byte LF = 10;

		enum State
		{
			InText,
			SawCR,
		} state = InText;

		::fs::Buffer::Offset ix = 0;
		while (ix < p_buffer.Size())
		{
			const byte b = p_buffer[ix];

			if (InText == state)
			{
				if (CR == b)
				{
					state = SawCR;
				}
				else if (LF == b)
				{
					*p_pLine = p_buffer.Reference(0, ix);
					*p_pRemainder = p_buffer.Reference(ix + 1);
					return true;
				}
			}
			else if (SawCR == state)
			{
				*p_pLine = p_buffer.Reference(0, ix - 1);
				if (LF == b)
				{
					*p_pRemainder = p_buffer.Reference(ix + 1);
				}
				else
				{
					*p_pRemainder = p_buffer.Reference(ix);
				}
				return true;
			}
			++ix;
		}

		sAssert(ix > 0);
		sAssert(ix == p_buffer.Size());

		if (13 == p_buffer[ix - 1])
		{
			*p_pLine = p_buffer.Reference(0, ix - 1);
		}
		else
		{
			*p_pLine = p_buffer;
		}

		*p_pRemainder = p_buffer.Reference(ix);

		return true;
	}
}

#if 0
namespace fs
{

	//
	// Move and make a unit test when have time.
	//
	void TestNextLine(::fs::Log& p_log)
	{
		sfcn();

		::fs::FixedBuffer<2> CRLF;
		CRLF[0] = 13;
		CRLF[1] = 10;

		::fs::FixedBuffer<1> CR;
		CR[0] = 13;

		::fs::FixedBuffer<1> LF;
		LF[0] = 10;

		::fs::Buffer empty = LF.Reference(0, 0);

		::fs::Buffer line;
		::fs::Buffer rest;

		bool r = NextLine(empty, &line, &rest);
		p_log.Info("TC 1.A ", false == r);
		p_log.Info("TC 1.B ", 0 == line.Size());

		r = NextLine(CRLF, &line, &rest);
		p_log.Info("TC 2.A ", true == r);
		p_log.Info("TC 2.B ", 0 == line.Size());
		p_log.Info("TC 2.C ", 0 == rest.Size());

		r = NextLine(rest, &line, &rest);
		p_log.Info("TC 2.D ", false == r);
		p_log.Info("TC 2.E ", 0 == line.Size());

		r = NextLine(LF, &line, &rest);
		p_log.Info("TC 3.A ", true == r);
		p_log.Info("TC 3.B ", 0 == line.Size());
		p_log.Info("TC 3.C ", 0 == rest.Size());

		r = NextLine(rest, &line, &rest);
		p_log.Info("TC 3.D ", false == r);
		p_log.Info("TC 3.E ", 0 == line.Size());

		r = NextLine(CR, &line, &rest);
		p_log.Info("TC 4.A ", true == r);
		p_log.Info("TC 4.B ", 0 == line.Size());
		p_log.Info("TC 4.C ", 0 == rest.Size());

		r = NextLine(rest, &line, &rest);
		p_log.Info("TC 4.D ", false == r);
		p_log.Info("TC 4.E ", 0 == line.Size());

		::fs::FixedBuffer<3> tc5;
		tc5[0] = 'A';
		tc5[1] = 13;
		tc5[2] = 10;

		r = NextLine(tc5, &line, &rest);
		p_log.Info("TC 5.A ", true == r);
		p_log.Info("TC 5.B ", 1 == line.Size());
		p_log.Info("TC 5.C ", 0 == rest.Size());

		r = NextLine(rest, &line, &rest);
		p_log.Info("TC 5.D ", false == r);
		p_log.Info("TC 5.E ", 0 == line.Size());

		::fs::FixedBuffer<2> tc6;
		tc6[0] = 'A';
		tc6[1] = 10;

		r = NextLine(tc6, &line, &rest);
		p_log.Info("TC 6.A ", true == r);
		p_log.Info("TC 6.B ", 1 == line.Size());
		p_log.Info("TC 6.C ", 0 == rest.Size());

		r = NextLine(rest, &line, &rest);
		p_log.Info("TC 6.D ", false == r);
		p_log.Info("TC 6.E ", 0 == line.Size());

		::fs::FixedBuffer<2> tc7;
		tc7[0] = 'A';
		tc7[1] = 13;

		r = NextLine(tc7, &line, &rest);
		p_log.Info("TC 7.A ", true == r);
		p_log.Info("TC 7.B ", 1 == line.Size());
		p_log.Info("TC 7.C ", 0 == rest.Size());

		r = NextLine(rest, &line, &rest);
		p_log.Info("TC 7.D ", false == r);
		p_log.Info("TC 7.E ", 0 == line.Size());

		::fs::FixedBuffer<5> tc8;
		tc8[0] = 'A';
		tc8[1] = 'B';
		tc8[2] = 13;
		tc8[3] = 10;
		tc8[4] = 'C';

		r = NextLine(tc8, &line, &rest);
		p_log.Info("TC 8.A ", true == r);
		p_log.Info("TC 8.B ", 2 == line.Size());
		p_log.Info("TC 8.C ", 1 == rest.Size());

		r = NextLine(rest, &line, &rest);
		p_log.Info("TC 8.D ", true == r);
		p_log.Info("TC 8.E ", 1 == line.Size());
		p_log.Info("TC 8.F ", 0 == rest.Size());

		r = NextLine(rest, &line, &rest);
		p_log.Info("TC 8.G ", false == r);
		p_log.Info("TC 8.H ", 0 == line.Size());

		::fs::FixedBuffer<4> tc9;
		tc9[0] = 'A';
		tc9[1] = 'B';
		tc9[2] = 13;
		tc9[3] = 'C';

		r = NextLine(tc9, &line, &rest);
		p_log.Info("TC 9.A ", true == r);
		p_log.Info("TC 9.B ", 2 == line.Size());
		p_log.Info("TC 9.C ", 1 == rest.Size());

		r = NextLine(rest, &line, &rest);
		p_log.Info("TC 9.D ", true == r);
		p_log.Info("TC 9.E ", 1 == line.Size());
		p_log.Info("TC 9.F ", 0 == rest.Size());

		r = NextLine(rest, &line, &rest);
		p_log.Info("TC 9.G ", false == r);
		p_log.Info("TC 9.H ", 0 == line.Size());

		::fs::FixedBuffer<4> tc10;
		tc10[0] = 'A';
		tc10[1] = 'B';
		tc10[2] = 10;
		tc10[3] = 'C';

		r = NextLine(tc10, &line, &rest);
		p_log.Info("TC 10.A ", true == r);
		p_log.Info("TC 10.B ", 2 == line.Size());
		p_log.Info("TC 10.C ", 1 == rest.Size());

		r = NextLine(rest, &line, &rest);
		p_log.Info("TC 10.D ", true == r);
		p_log.Info("TC 10.E ", 1 == line.Size());
		p_log.Info("TC 10.F ", 0 == rest.Size());

		r = NextLine(rest, &line, &rest);
		p_log.Info("TC 10.G ", false == r);
		p_log.Info("TC 10.H ", 0 == line.Size());

		volatile int j = 0;
	}

}

#endif



/* End Of File: Buffer.cpp */
