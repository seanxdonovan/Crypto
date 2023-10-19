#include "precomp.h"

namespace crypto
{

	static fs::qword K [] = {
		0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
		0x3956c25bf348b538, 0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
		0xd807aa98a3030242, 0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
		0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 0xc19bf174cf692694,
		0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
		0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
		0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4,
		0xc6e00bf33da88fc2, 0xd5a79147930aa725, 0x06ca6351e003826f, 0x142929670a0e6e70,
		0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
		0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b,
		0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30,
		0xd192e819d6ef5218, 0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
		0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
		0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
		0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
		0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b,
		0xca273eceea26619c, 0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
		0x06f067aa72176fba, 0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
		0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
		0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817
	};

	class SHA_512Digest
	{

	private:
		fs::qword m_h0;
		fs::qword m_h1;
		fs::qword m_h2;
		fs::qword m_h3;
		fs::qword m_h4;
		fs::qword m_h5;
		fs::qword m_h6;
		fs::qword m_h7;


		fs::dqword m_bitCount;

		fs::FixedBuffer<128> m_partialBlock;

		fs::FixedBuffer<128> m_padding;

		

		inline fs::qword Ch(fs::qword p_x, fs::qword p_y, fs::qword p_z)
		{
			return (p_x & p_y) ^ (~p_x & p_z);
		}

		inline fs::qword Maj(fs::qword p_x, fs::qword p_y, fs::qword p_z)
		{
			return (p_x & p_y) ^ (p_x & p_z) ^ (p_y & p_z);
		}

		inline fs::qword Sigma0(fs::qword p_x)
		{
			return fs::RotateRight(p_x, 28) ^ fs::RotateRight(p_x, 34) ^ fs::RotateRight(p_x, 39);
		}

		inline fs::qword Sigma1(fs::qword p_x)
		{
			return fs::RotateRight(p_x, 14) ^ fs::RotateRight(p_x, 18) ^ fs::RotateRight(p_x, 41);
		}

		inline fs::qword sigma0(fs::qword p_x)
		{
			return fs::RotateRight(p_x, 1) ^ fs::RotateRight(p_x, 8) ^ fs::ShiftRight(p_x, 7);
		}

		inline fs::qword sigma1(fs::qword p_x)
		{
			return fs::RotateRight(p_x, 19) ^ fs::RotateRight(p_x, 61) ^ fs::ShiftRight(p_x, 6);
		}

	public:
		void Start()
		{
			m_h0 = 0x6a09e667f3bcc908;
			m_h1 = 0xbb67ae8584caa73b;
			m_h2 = 0x3c6ef372fe94f82b;
			m_h3 = 0xa54ff53a5f1d36f1;
			m_h4 = 0x510e527fade682d1;
			m_h5 = 0x9b05688c2b3e6c1f;
			m_h6 = 0x1f83d9abfb41bd6b;
			m_h7 = 0x5be0cd19137e2179;

			m_bitCount = 0;

			m_padding.Zero();
			m_padding[0] = 0x80;
		}


		void Transform(fs::Buffer p_block)
		{
			sPrecondition(p_block.Size() == 128);


			size_t index;
			fs::BufferStream bs(p_block);
			std::vector<fs::qword> w(80);

			for (index = 0; index < 16; ++index)
			{
				fs::readBigEndian(bs, &(w[index]));
			}

			for (index = 16; index < 80; ++index)
			{
				w[index] = sigma1(w[index - 2]) + w[index - 7] + sigma0(w[index - 15]) + w[index - 16];
			}

			fs::qword a = m_h0;
			fs::qword b = m_h1;
			fs::qword c = m_h2;
			fs::qword d = m_h3;
			fs::qword e = m_h4;
			fs::qword f = m_h5;
			fs::qword g = m_h6;
			fs::qword h = m_h7;


			for (index = 0; index < 80; ++index)
			{
				fs::qword tmp1 = h + Sigma1(e) + Ch(e, f, g) + K[index] + w[index];
				fs::qword tmp2 = Sigma0(a) + Maj(a, b, c);
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

			fs::dqword nBytes = fs::ShiftRight(m_bitCount, 3);

			fs::dword ixtmp = sCoerce(fs::byte, fs::loword(nBytes) & 0x7f);
			if (ixtmp + p_data.Size() >= 128)
			{
				if (0 != ixtmp)
				{
					size_t n = fs::smaller_of(128 - ixtmp, p_data.Size());
					fs::Copy(p_data.Reference(0, n), &m_partialBlock.Reference(ixtmp));

					Transform(m_partialBlock);
					offset = n;
				}


				while (offset + 127 < p_data.Size())
				{
					Transform(p_data.Reference(offset, 128));

					offset += 128;
				}
			}
			fs::dqword tmpCount = fs::ShiftRight(m_bitCount, 3);
			fs::AddTo(sCoerce(fs::qword, offset), &tmpCount);

			ixtmp = sCoerce(fs::byte , fs::loword(tmpCount) & 0x7f);

			fs::Copy(p_data.Reference(offset), &m_partialBlock.Reference(ixtmp));
			fs::AddTo(sCoerce(fs::qword, (p_data.Size() << 3)), &m_bitCount);
		}

		void Finish(fs::Buffer *p_pDigest)
		{
			sPrecondition(p_pDigest->Size() >= 512/8);


			fs::FixedBuffer<16> bitCount;
			fs::storeBigEndian(m_bitCount, &bitCount);

			/* Pad out to 112 mod 128.
			 */
			fs::dword index = sCoerce(fs::byte, fs::loword(fs::ShiftRight(m_bitCount, 3)) & 0x7f);
			fs::dword nPad = 240 - index;
			if (index < 112)
			{
				nPad = 112 - index;
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


	void SHA_512(fs::Stream& p_streamInput, fs::Stream::Size p_length, fs::Buffer *p_pDigest)
	{
		sPrecondition(p_pDigest->Size() >= 64);

		SHA_512Digest SHA_512;
		SHA_512.Start();
		fs::FixedBuffer<64> chunk;

		fs::qword nChunks = p_length / chunk.Size();
		fs::dword lastChunkSize = p_length % chunk.Size();

		for (fs::qword n = 0; n < nChunks; ++n)
		{
			p_streamInput.Read(chunk);
			SHA_512.Update(chunk);
		}

		fs::Buffer tmp = chunk.Reference(0, lastChunkSize);
		p_streamInput.Read(tmp);

		SHA_512.Update(tmp);

		SHA_512.Finish(p_pDigest);
	}
}

/* End Of File: SHA_512.cpp */
