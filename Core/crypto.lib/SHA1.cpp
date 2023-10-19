#include "precomp.h"
#include "SHA1.h"

//
// References
//
// FIPS 180-1 "Secure Hash Standard" USA
//
// RFC 3174 - US Secure Hash Algorithm 1 (SHA1) Sep 2001.
//


namespace crypto
{
	void SHA1Digest::Start()
	{
		m_h0 = 0x67452301;
		m_h1 = 0xEFCDAB89;
		m_h2 = 0x98BADCFE;
		m_h3 = 0x10325476;
		m_h4 = 0xC3D2E1F0;
		m_bitCount = 0;

		m_padding.Zero();
		m_padding[0] = 0x80;
	}

	void SHA1Digest::Transform(fs::Buffer p_block)
	{
		sPrecondition(p_block.Size() == 64);


		std::vector<fs::dword> w(80);

		fs::dword index;
		fs::BufferStream bs(p_block);
		for (index = 0; index < 16; ++index)
		{
			fs::readBigEndian(bs, &(w[index]));
		}

		for (index = 16; index < 80; ++index)
		{
			fs::dword value = w[index - 3] ^ w[index - 8] ^ w[index - 14] ^ w[index - 16];
			w[index] = fs::rotateLeft(value, 1 );
		}

		fs::dword a = m_h0;
		fs::dword b = m_h1;
		fs::dword c = m_h2;
		fs::dword d = m_h3;
		fs::dword e = m_h4;


		for (index = 0; index < 80; ++index)
		{
			fs::dword f;
			fs::dword k;
			if (index <= 19)
			{
				f = ((b & c) | ((~b) & d));
				k = 0x5A827999;
			}
			else if (index <= 39)
			{
				f = (b ^ c ^ d);
				k = 0x6ED9EBA1;
			}	
			else if (index <= 59)
			{
				f = ((b & c) | (b & d) | (c & d));
				k = 0x8F1BBCDC;
			}
			else
			{
				f = (b ^ c ^ d);
				k = 0xCA62C1D6;
			}

			fs::dword temp = fs::rotateLeft(a, 5) + f + e + k + w[index];
			e = d;
			d = c;
			c = fs::rotateLeft(b, 30);
			b = a;
			a = temp;
		}
		m_h0 += a;
		m_h1 += b;
		m_h2 += c;
		m_h3 += d;
		m_h4 += e;
	}

	void SHA1Digest::Update(fs::Buffer p_data)
	{
		fs::Buffer::Offset offset = 0;

		fs::qword nBytes = m_bitCount >> 3;

		fs::dword ixtmp = (nBytes & 0x3f);
		if (ixtmp + p_data.Size() >= 64)
		{
			if (0 != ixtmp)
			{
				fs::dword n = fs::smaller_of(64 - ixtmp, p_data.Size());
				fs::Copy(p_data.Reference(0, n), &m_partialBlock.Reference(ixtmp));

				Transform(m_partialBlock);
				offset = n;
			}


			while (offset + 63 < p_data.Size())
			{
				Transform(p_data.Reference(offset, 64));

				offset += 64;
			}
		}
		ixtmp = ((m_bitCount >> 3) + offset) & 0x3f;

		fs::Copy(p_data.Reference(offset), &m_partialBlock.Reference(ixtmp));
		m_bitCount += (p_data.Size() << 3);
	}

	void SHA1Digest::Finish(fs::Buffer *p_pDigest)
	{
		sPrecondition(p_pDigest->Size() >= 20);


		fs::FixedBuffer<8> bitCount;
		fs::storeBigEndian(m_bitCount, &bitCount);

		/* Pad out to 56 mod 64.
		 */
		fs::dword index = (fs::dword)((m_bitCount >> 3) & 0x3f);
		fs::dword nPad = 120 - index;
		if (index < 56)
		{
			nPad = 56 - index;
		}

		Update(m_padding.Reference(0, nPad));
		Update(bitCount);


		fs::BufferStream bs(*p_pDigest);

		fs::writeBigEndian(bs, m_h0);
		fs::writeBigEndian(bs, m_h1);
		fs::writeBigEndian(bs, m_h2);
		fs::writeBigEndian(bs, m_h3);
		fs::writeBigEndian(bs, m_h4);
	}


	void SHA1(fs::Stream& p_streamInput, fs::Stream::Size p_length, fs::Buffer *p_pDigest)
	{
		SHA1Digest sha1;
		sha1.Start();
		fs::FixedBuffer<64> chunk;

		fs::qword nChunks = p_length / chunk.Size();
		fs::dword lastChunkSize = p_length % chunk.Size();

		for (fs::qword n = 0; n < nChunks; ++n)
		{
			p_streamInput.Read(chunk);
			sha1.Update(chunk);
		}

		fs::Buffer tmp = chunk.Reference(0, lastChunkSize);
		p_streamInput.Read(tmp);

		sha1.Update(tmp);

		sha1.Finish(p_pDigest);
	}
}

/* End Of File: SHA1.cpp */
