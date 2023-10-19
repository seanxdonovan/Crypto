#include "precomp.h"


//
// MD5 see RFC1321
//

namespace crypto
{
	namespace
	{
		static const fs::dword S11 =  7;
		static const fs::dword S12 = 12;
		static const fs::dword S13 = 17;
		static const fs::dword S14 = 22;
		static const fs::dword S21 =  5;
		static const fs::dword S22 =  9;
		static const fs::dword S23 = 14;
		static const fs::dword S24 = 20;
		static const fs::dword S31 =  4;
		static const fs::dword S32 = 11;
		static const fs::dword S33 = 16;
		static const fs::dword S34 = 23;
		static const fs::dword S41 =  6;
		static const fs::dword S42 = 10;
		static const fs::dword S43 = 15;
		static const fs::dword S44 = 21;


		/* F, G, H and I are basic MD5 functions.
		 */
		inline fs::dword F(fs::dword x, fs::dword y, fs::dword z)
		{
			return (((x) & (y)) | ((~x) & (z)));
		}

		inline fs::dword G(fs::dword x, fs::dword y, fs::dword z)
		{
			return (((x) & (z)) | ((y) & (~z)));
		}

		inline fs::dword H(fs::dword x, fs::dword y, fs::dword z)
		{
			return ((x) ^ (y) ^ (z));
		}

		inline fs::dword I(fs::dword x, fs::dword y, fs::dword z)
		{
			return ((y) ^ ((x) | (~z)));
		}


		/* FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4.
		 * Rotation is separate from addition to prevent recomputation.
		 */
		inline void FF(fs::dword *p_pa, fs::dword b, fs::dword c, fs::dword d, fs::dword x, fs::dword s, fs::dword ac)
		{
			*p_pa += F (b, c, d) + x + ac;
			*p_pa = fs::rotateLeft(*p_pa, s);
			*p_pa += b;
		}
		inline void GG(fs::dword *p_pa, fs::dword b, fs::dword c, fs::dword d, fs::dword x, fs::dword s, fs::dword ac)
		{
			*p_pa += G(b, c, d) + x + ac;
			*p_pa = fs::rotateLeft(*p_pa, s);
			*p_pa += b;
		}

		inline void HH(fs::dword *p_pa, fs::dword b, fs::dword c, fs::dword d, fs::dword x, fs::dword s, fs::dword ac)
		{
			*p_pa += H(b, c, d) + x + ac;
			*p_pa = fs::rotateLeft(*p_pa, s);
			*p_pa += b;
		}

		inline void II(fs::dword *p_pa, fs::dword b, fs::dword c, fs::dword d, fs::dword x, fs::dword s, fs::dword ac)
		{
			*p_pa += I (b, c, d) + x + ac;
			*p_pa = fs::rotateLeft(*p_pa, s);
			*p_pa += b;
		}
	} /* internal namespace */


	class MD5Digest
	{
		fs::qword m_count;
		fs::FixedBuffer<16> m_digest;

		fs::dword m_h0;
		fs::dword m_h1;
		fs::dword m_h2;
		fs::dword m_h3;

	private:
		fs::FixedBuffer<64> m_currentBlock;

	public:
		const fs::Buffer Digest() const
		{
			return m_digest;
		}

		MD5Digest()
				: m_count(0)
		{
			m_padding.Zero();
			m_padding[0] = 0x80;
		}


		/* Constants for MD5Transform routine.
		 */


		fs::FixedBuffer<64> m_padding;


		/* MD5 initialization. Begins an MD5 operation, writing a new context.
		 */
		void Start()
		{
			m_count = 0;
			/* Load magic initialization constants.
			 */
			m_h0 = 0x67452301;
			m_h1 = 0xefcdab89;
			m_h2 = 0x98badcfe;
			m_h3 = 0x10325476;
		}

		/* MD5 block update operation. Continues an MD5 message-digest
		 * operation, processing another message block, and updating the
		 * context.
		 */

		/* MD5 finalization. Ends an MD5 message-digest operation, writing the
		 * the message digest and zeroizing the context.
		 */
		void Transform (fs::Buffer p_block)
		{
			sPrecondition(p_block.Size() == 64);

			fs::dword a = m_h0;
			fs::dword b = m_h1;
			fs::dword c = m_h2;
			fs::dword d = m_h3;

			fs::dword x[16];

			
			fs::BufferStream bs(p_block);
			for (fs::dword index = 0; index < 16; ++index)
			{
				fs::readLittleEndian(bs, &(x[index]));
			}

			/* Round 1 */
			FF (&a, b, c, d, x[ 0], S11, 0xd76aa478); /* 1 */
			FF (&d, a, b, c, x[ 1], S12, 0xe8c7b756); /* 2 */
			FF (&c, d, a, b, x[ 2], S13, 0x242070db); /* 3 */
			FF (&b, c, d, a, x[ 3], S14, 0xc1bdceee); /* 4 */
			FF (&a, b, c, d, x[ 4], S11, 0xf57c0faf); /* 5 */
			FF (&d, a, b, c, x[ 5], S12, 0x4787c62a); /* 6 */
			FF (&c, d, a, b, x[ 6], S13, 0xa8304613); /* 7 */
			FF (&b, c, d, a, x[ 7], S14, 0xfd469501); /* 8 */
			FF (&a, b, c, d, x[ 8], S11, 0x698098d8); /* 9 */
			FF (&d, a, b, c, x[ 9], S12, 0x8b44f7af); /* 10 */
			FF (&c, d, a, b, x[10], S13, 0xffff5bb1); /* 11 */
			FF (&b, c, d, a, x[11], S14, 0x895cd7be); /* 12 */
			FF (&a, b, c, d, x[12], S11, 0x6b901122); /* 13 */
			FF (&d, a, b, c, x[13], S12, 0xfd987193); /* 14 */
			FF (&c, d, a, b, x[14], S13, 0xa679438e); /* 15 */
			FF (&b, c, d, a, x[15], S14, 0x49b40821); /* 16 */

			/* Round 2 */
			GG (&a, b, c, d, x[ 1], S21, 0xf61e2562); /* 17 */
			GG (&d, a, b, c, x[ 6], S22, 0xc040b340); /* 18 */
			GG (&c, d, a, b, x[11], S23, 0x265e5a51); /* 19 */
			GG (&b, c, d, a, x[ 0], S24, 0xe9b6c7aa); /* 20 */
			GG (&a, b, c, d, x[ 5], S21, 0xd62f105d); /* 21 */
			GG (&d, a, b, c, x[10], S22,  0x2441453); /* 22 */
			GG (&c, d, a, b, x[15], S23, 0xd8a1e681); /* 23 */
			GG (&b, c, d, a, x[ 4], S24, 0xe7d3fbc8); /* 24 */
			GG (&a, b, c, d, x[ 9], S21, 0x21e1cde6); /* 25 */
			GG (&d, a, b, c, x[14], S22, 0xc33707d6); /* 26 */
			GG (&c, d, a, b, x[ 3], S23, 0xf4d50d87); /* 27 */
			GG (&b, c, d, a, x[ 8], S24, 0x455a14ed); /* 28 */
			GG (&a, b, c, d, x[13], S21, 0xa9e3e905); /* 29 */
			GG (&d, a, b, c, x[ 2], S22, 0xfcefa3f8); /* 30 */
			GG (&c, d, a, b, x[ 7], S23, 0x676f02d9); /* 31 */
			GG (&b, c, d, a, x[12], S24, 0x8d2a4c8a); /* 32 */

			/* Round 3 */
			HH (&a, b, c, d, x[ 5], S31, 0xfffa3942); /* 33 */
			HH (&d, a, b, c, x[ 8], S32, 0x8771f681); /* 34 */
			HH (&c, d, a, b, x[11], S33, 0x6d9d6122); /* 35 */
			HH (&b, c, d, a, x[14], S34, 0xfde5380c); /* 36 */
			HH (&a, b, c, d, x[ 1], S31, 0xa4beea44); /* 37 */
			HH (&d, a, b, c, x[ 4], S32, 0x4bdecfa9); /* 38 */
			HH (&c, d, a, b, x[ 7], S33, 0xf6bb4b60); /* 39 */
			HH (&b, c, d, a, x[10], S34, 0xbebfbc70); /* 40 */
			HH (&a, b, c, d, x[13], S31, 0x289b7ec6); /* 41 */
			HH (&d, a, b, c, x[ 0], S32, 0xeaa127fa); /* 42 */
			HH (&c, d, a, b, x[ 3], S33, 0xd4ef3085); /* 43 */
			HH (&b, c, d, a, x[ 6], S34,  0x4881d05); /* 44 */
			HH (&a, b, c, d, x[ 9], S31, 0xd9d4d039); /* 45 */
			HH (&d, a, b, c, x[12], S32, 0xe6db99e5); /* 46 */
			HH (&c, d, a, b, x[15], S33, 0x1fa27cf8); /* 47 */
			HH (&b, c, d, a, x[ 2], S34, 0xc4ac5665); /* 48 */

			/* Round 4 */
			II (&a, b, c, d, x[ 0], S41, 0xf4292244); /* 49 */
			II (&d, a, b, c, x[ 7], S42, 0x432aff97); /* 50 */
			II (&c, d, a, b, x[14], S43, 0xab9423a7); /* 51 */
			II (&b, c, d, a, x[ 5], S44, 0xfc93a039); /* 52 */
			II (&a, b, c, d, x[12], S41, 0x655b59c3); /* 53 */
			II (&d, a, b, c, x[ 3], S42, 0x8f0ccc92); /* 54 */
			II (&c, d, a, b, x[10], S43, 0xffeff47d); /* 55 */
			II (&b, c, d, a, x[ 1], S44, 0x85845dd1); /* 56 */
			II (&a, b, c, d, x[ 8], S41, 0x6fa87e4f); /* 57 */
			II (&d, a, b, c, x[15], S42, 0xfe2ce6e0); /* 58 */
			II (&c, d, a, b, x[ 6], S43, 0xa3014314); /* 59 */
			II (&b, c, d, a, x[13], S44, 0x4e0811a1); /* 60 */
			II (&a, b, c, d, x[ 4], S41, 0xf7537e82); /* 61 */
			II (&d, a, b, c, x[11], S42, 0xbd3af235); /* 62 */
			II (&c, d, a, b, x[ 2], S43, 0x2ad7d2bb); /* 63 */
			II (&b, c, d, a, x[ 9], S44, 0xeb86d391); /* 64 */

			m_h0 += a;
			m_h1 += b;
			m_h2 += c;
			m_h3 += d;
		}


		void Update(fs::Buffer p_data)
		{
			fs::dword i;
			fs::dword index;
			fs::dword partLen;

			/* Compute number of bytes mod 64 */
			index = (fs::dword)((m_count >> 3) & 0x3F);

			/* Update number of bits */
			m_count += (p_data.Size() << 3);

			partLen = 64 - index;

			/* Transform as many times as possible.
			 */
			if (p_data.Size() >= partLen)
			{
				//
				// fill out buffer
				//
				fs::Copy(p_data.Reference(0, partLen), &m_currentBlock.Reference(index, partLen));
				Transform(m_currentBlock);

				for (i = partLen; i + 63 < p_data.Size(); i += 64)
				{
					Transform(p_data.Reference(i, 64));
				}
				index = 0;
			}
			else
			{
				i = 0;
			}

			/* Buffer remaining input */
			fs::Copy(p_data.Reference(i, p_data.Size() - i), &m_currentBlock.Reference(index, p_data.Size() - i));
		}


		void Finish()
		{
			//
			// Capture the bitcount before we update the
			// last block. We want the actual message size,
			// not the message size + the pad.
			//
			fs::FixedBuffer<8> bitCount;
			fs::storeLittleEndian(m_count, &bitCount);

			unsigned int index, padLen;

			/* Pad out to 56 mod 64.
			 */
			index = (unsigned int)((m_count >> 3) & 0x3f);
			padLen = 120 - index;
			if (index < 56)
			{
				padLen = 56 - index;
			}
			Update(m_padding.Reference(0, padLen));

			Update(bitCount);





			//
			// Store the digest.
			//

			fs::BufferStream bs(m_digest);

			fs::writeLittleEndian(bs, m_h0);
			fs::writeLittleEndian(bs, m_h1);
			fs::writeLittleEndian(bs, m_h2);
			fs::writeLittleEndian(bs, m_h3);
		}
	};



	void MD5(fs::Stream& p_streamInput, fs::Stream::Size p_length, fs::Buffer *p_pDigest)
	{
		MD5Digest md5;
		md5.Start();

		fs::FixedBuffer<64> chunk;

		const fs::qword nChunks = p_length >> 6;
		fs::dword lastChunkSize = p_length & 0x3f;
		sAssert(lastChunkSize < 64);

		for (fs::qword n = 0; n < nChunks; ++n)
		{
			p_streamInput.Read(chunk);
			md5.Update(chunk);
		}

		if (lastChunkSize > 0)
		{
			fs::Buffer tmp = chunk.Reference(0, lastChunkSize);
			p_streamInput.Read(tmp);
			md5.Update(tmp);
		}

		md5.Finish();

		fs::Copy(md5.Digest(), p_pDigest);
	}


/*	void MD5(fs::Stream& p_streamInput, fs::Stream::Size p_length, fs::Buffer *p_pDigest)
	{
		sfcn();
		sPrecondition(p_pDigest->Size() >= 16);
		//Note: All variables are unsigned 32 bits and wrap modulo 2^32 when calculating

		//Define r as the following
		fs::dword r[64] = {
			7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
			5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
			4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
			6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21
		};
		fs::dword k[64];

		for (fs::dword i = 0; i < 64; ++i)
		{
			double acc = (0x100000000 * abs(sin((double)i + 1)));
			k[i] = static_cast<fs::dword>(floor(acc));
		}

		fs::dword h0 = 0x67452301;
		fs::dword h1 = 0xEFCDAB89;
		fs::dword h2 = 0x98BADCFE;
		fs::dword h3 = 0x10325476;

		const fs::Stream::Size fullLength = p_length + 9;
		fs::dword nChunks = (fullLength) / (512/8);
		if (0 != (fullLength) % (512/8))
		{
			++nChunks;
		}




		for (fs::dword n = 0; n < nChunks; ++n)
		{
			fs::FixedBuffer<64> chunk;
			if (n + 1 == nChunks)
			{
				//
				// last chunk
				//
				chunk.Fill((fs::dword)0);

				fs::dword lastChunkDataSize = p_length % 64;
				sAssert(lastChunkDataSize <= 64 - 9);

				p_streamInput.Read(chunk.Reference(0, lastChunkDataSize));

				//
				// append a single '1' to the message
				//
				chunk[lastChunkDataSize] = 0x80;

				fs::qword messageSize = p_length * 8;
				fs::Buffer length = chunk.Reference(chunk.Size() - 8, 8);
				fs::storeLittleEndian(messageSize, &length);
			}
			else
			{
				p_streamInput.Read(chunk);
			}

			fs::dword w[16];
			fs::BufferStream bs(chunk);
			for (fs::dword index = 0; index < 16; ++index)
			{
				fs::readLittleEndian(bs, &(w[index]));
			}

			fs::dword a = h0;
			fs::dword b = h1;
			fs::dword c = h2;
			fs::dword d = h3;
			fs::dword f,g;

			for (fs::dword index = 0; index < 64; ++index)
			{
				if (index > 47)
				{
					f = c ^ (b | (~d));
					g = (7 * index) % 16;
				}
				else if (index > 31)
				{
					f = b ^ c ^ d;
					g = (3 * index + 5) % 16;
				}
				else if (index > 15)
				{
					f = (d & b) | ((~d) & c);
					g = (5*index + 1) % 16;
				}
				else // index >= 0
				{
					f = (b & c) | ((~b) & d);
					g = index;
				}

				fs::dword temp = d;
				d = c;
				c = b;
				b = fs::rotateLeft((a + f + k[index] + w[g]), r[index]) + b;
				a = temp;
			}

			h0 = h0 + a;
			h1 = h1 + b;
			h2 = h2 + c;
			h3 = h3 + d;
		}

		fs::BufferStream bs(*p_pDigest);

		fs::writeLittleEndian(bs, h0);
		fs::writeLittleEndian(bs, h1);
		fs::writeLittleEndian(bs, h2);
		fs::writeLittleEndian(bs, h3);
	}
*/
}

/* End Of File: MD5.cpp */
