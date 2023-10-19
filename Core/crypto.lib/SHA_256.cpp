#include "precomp.h"

namespace crypto
{

	static fs::dword K [] = {
		0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
		0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
		0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
		0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
		0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
		0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
		0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
		0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
	};

	class SHA_256Digest
	{

	private:
		fs::dword m_h0;
		fs::dword m_h1;
		fs::dword m_h2;
		fs::dword m_h3;
		fs::dword m_h4;
		fs::dword m_h5;
		fs::dword m_h6;
		fs::dword m_h7;


		fs::qword m_bitCount;

		fs::FixedBuffer<64> m_partialBlock;

		fs::FixedBuffer<64> m_padding;

		//
		// sec 4.1.2 SHA-256 Functions from FIPS180-2 p9.
		//
		inline fs::dword Ch(fs::dword p_x, fs::dword p_y, fs::dword p_z)
		{
			return (p_x & p_y) ^ (~p_x & p_z);
		}

		inline fs::dword Maj(fs::dword p_x, fs::dword p_y, fs::dword p_z)
		{
			return (p_x & p_y) ^ (p_x & p_z) ^ (p_y & p_z);
		}

		inline fs::dword Sigma0(fs::dword p_x)
		{
			return fs::RotateRight(p_x, 2) ^ fs::RotateRight(p_x, 13) ^ fs::RotateRight(p_x, 22);
		}

		inline fs::dword Sigma1(fs::dword p_x)
		{
			return fs::RotateRight(p_x, 6) ^ fs::RotateRight(p_x, 11) ^ fs::RotateRight(p_x, 25);
		}

		inline fs::dword sigma0(fs::dword p_x)
		{
			return fs::RotateRight(p_x, 7) ^ fs::RotateRight(p_x, 18) ^ fs::ShiftRight(p_x, 3);
		}

		inline fs::dword sigma1(fs::dword p_x)
		{
			return fs::RotateRight(p_x, 17) ^ fs::RotateRight(p_x, 19) ^ fs::ShiftRight(p_x, 10);
		}

	public:
		void Start()
		{
			m_h0 = 0x6A09E667;
			m_h1 = 0xBB67ae85;
			m_h2 = 0x3c6ef372;
			m_h3 = 0xa54ff53a;
			m_h4 = 0x510e527f;
			m_h5 = 0x9b05688c;
			m_h6 = 0x1f83d9ab;
			m_h7 = 0x5be0cd19;

			m_bitCount = 0;

			m_padding.Zero();
			m_padding[0] = 0x80;
		}


		void Transform(fs::Buffer p_block)
		{
			sPrecondition(p_block.Size() == 64);

			fs::dword index;
			fs::BufferStream bs(p_block);

			std::vector<fs::dword> w(64);
			for (index = 0; index < 16; ++index)
			{
				fs::readBigEndian(bs, &(w[index]));
			}

			for (index = 16; index < 64; ++index)
			{
				w[index] = sigma1(w[index - 2]) + w[index - 7] + sigma0(w[index - 15]) + w[index - 16];
			}

			fs::dword a = m_h0;
			fs::dword b = m_h1;
			fs::dword c = m_h2;
			fs::dword d = m_h3;
			fs::dword e = m_h4;
			fs::dword f = m_h5;
			fs::dword g = m_h6;
			fs::dword h = m_h7;

			for (index = 0; index < 64; ++index)
			{
				fs::dword tmp1 = h + Sigma1(e) + Ch(e, f, g) + K[index] + w[index];
				fs::dword tmp2 = Sigma0(a) + Maj(a, b, c);
				h = g;
				g = f;
				f = e;
				e = d + tmp1;
				d = c;
				c = b;
				b = a;
				a = tmp1 + tmp2;
			}
			m_h0 += a;
			m_h1 += b;
			m_h2 += c;
			m_h3 += d;
			m_h4 += e;
			m_h5 += f;
			m_h6 += g;
			m_h7 += h;
		}

		void Update(fs::Buffer p_data)
		{
			fs::Buffer::Offset offset = 0;

			fs::qword nBytes = m_bitCount >> 3;

			fs::dword ixtmp = sCoerce(fs::dword, (nBytes & 0x3f));
			if (ixtmp + p_data.Size() >= 64)
			{
				if (0 != ixtmp)
				{
					fs::dword n = fs::smaller_of(64 - ixtmp, sCoerce(fs::dword, p_data.Size()));
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
			ixtmp = sCoerce(fs::dword, ((m_bitCount >> 3) + offset) & 0x3f);

			fs::Copy(p_data.Reference(offset), &m_partialBlock.Reference(ixtmp));
			m_bitCount += (p_data.Size() << 3);
		}

		void Finish(fs::Buffer *p_pDigest)
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
			fs::writeBigEndian(bs, m_h5);
			fs::writeBigEndian(bs, m_h6);
			fs::writeBigEndian(bs, m_h7);
		}
	};


	void SHA_256(fs::Stream& p_streamInput, fs::Stream::Size p_length, fs::Buffer *p_pDigest)
	{
		sPrecondition(p_pDigest->Size() >= 32);

		SHA_256Digest SHA_256;
		SHA_256.Start();
		fs::FixedBuffer<64> chunk;

		fs::qword nChunks = p_length / chunk.Size();
		fs::dword lastChunkSize = p_length % chunk.Size();

		for (fs::qword n = 0; n < nChunks; ++n)
		{
			p_streamInput.Read(chunk);
			SHA_256.Update(chunk);
		}

		fs::Buffer tmp = chunk.Reference(0, lastChunkSize);
		p_streamInput.Read(tmp);

		SHA_256.Update(tmp);

		SHA_256.Finish(p_pDigest);
	}


	void SHA_256(::fs::Buffer p_input, fs::Buffer *p_pDigest)
	{
		sPrecondition(p_pDigest->Size() >= 32);

		SHA_256Digest SHA_256;
		SHA_256.Start();

		const size_t ChunkSize = 64;

		const auto length = p_input.Size();

		::fs::qword nChunks = length / ChunkSize;
		::fs::dword lastChunkSize = length % ChunkSize;

		for (fs::qword n = 0; n < nChunks; ++n)
		{
			auto chunk = p_input.Reference(n * ChunkSize, ChunkSize);
			SHA_256.Update(chunk);
		}

		auto tmp = p_input.Reference(nChunks * ChunkSize, lastChunkSize);

		SHA_256.Update(tmp);

		SHA_256.Finish(p_pDigest);
	}
}

/* End Of File: SHA_256.cpp */
