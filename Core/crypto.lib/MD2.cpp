#include "precomp.h"


namespace crypto
{

	namespace
	{
		/* Permutation of 0..255 constructed from the digits of pi. It gives a
		   "random" nonlinear byte substitution operation.
		 */
		static unsigned char PI_SUBST[256] = {
			 41,  46,  67, 201, 162, 216, 124,   1,  61,  54,  84, 161, 236, 240, 6,
			 19,  98, 167,   5, 243, 192, 199, 115, 140, 152, 147,  43, 217, 188,
			 76, 130, 202,  30, 155,  87,  60, 253, 212, 224,  22, 103,  66, 111, 24,
			138,  23, 229,  18, 190,  78, 196, 214, 218, 158, 222,  73, 160, 251,
			245, 142, 187,  47, 238, 122, 169, 104, 121, 145,  21, 178,   7,  63,
			148, 194,  16, 137,  11,  34,  95,  33, 128, 127,  93, 154,  90, 144, 50,
			 39,  53,  62, 204, 231, 191, 247, 151,   3, 255,  25,  48, 179,  72, 165,
			181, 209, 215,  94, 146,  42, 172,  86, 170, 198,  79, 184,  56, 210,
			150, 164, 125, 182, 118, 252, 107, 226, 156, 116,   4, 241,  69, 157,
			112,  89, 100, 113, 135,  32, 134,  91, 207, 101, 230,  45, 168,   2, 27,
			 96,  37, 173, 174, 176, 185, 246,  28,  70,  97, 105,  52,  64, 126, 15,
			 85,  71, 163,  35, 221,  81, 175,  58, 195,  92, 249, 206, 186, 197,
			234,  38,  44,  83,  13, 110, 133,  40, 132,   9, 211, 223, 205, 244, 65,
			129,  77,  82, 106, 220,  55, 200, 108, 193, 171, 250,  36, 225, 123,
			  8,  12, 189, 177,  74, 120, 136, 149, 139, 227,  99, 232, 109, 233,
			203, 213, 254,  59,   0,  29,  57, 242, 239, 183,  14, 102,  88, 208, 228,
			166, 119, 114, 248, 235, 117,  75,  10,  49,  68,  80, 180, 143, 237,
			 31,  26, 219, 153, 141,  51, 159,  17, 131,  20
		};

		static fs::byte *PADDING[] = {
			(fs::byte *)"",
			(fs::byte *)"\001",
			(fs::byte *)"\002\002",
			(fs::byte *)"\003\003\003",
			(fs::byte *)"\004\004\004\004",
			(fs::byte *)"\005\005\005\005\005",
			(fs::byte *)"\006\006\006\006\006\006",
			(fs::byte *)"\007\007\007\007\007\007\007",
			(fs::byte *)"\010\010\010\010\010\010\010\010",
			(fs::byte *)"\011\011\011\011\011\011\011\011\011",
			(fs::byte *)"\012\012\012\012\012\012\012\012\012\012",
			(fs::byte *)"\013\013\013\013\013\013\013\013\013\013\013",
			(fs::byte *)"\014\014\014\014\014\014\014\014\014\014\014\014",
			(fs::byte *)"\015\015\015\015\015\015\015\015\015\015\015\015\015",
			(fs::byte *)"\016\016\016\016\016\016\016\016\016\016\016\016\016\016",
			(fs::byte *)"\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017",
			(fs::byte *)"\020\020\020\020\020\020\020\020\020\020\020\020\020\020\020\020"
		};
	}

	class MD2Digest
	{
		fs::dword m_count;
		fs::FixedBuffer<16> m_digest;
	public:
		const fs::Buffer Digest() const
		{
			return m_digest;
		}

		void Update(fs::Buffer p_data)
		{
			fs::Buffer::Offset i, index, partLen;


			/* Update number of bytes mod 16 */
			index = m_count;
			m_count = (index + p_data.Size()) & 0xf;

			partLen = 16 - index;

			/* Transform as many times as possible.
			 */
			if (p_data.Size() >= partLen)
			{
				
				fs::Copy(p_data.Reference(0, partLen), &(m_block.Reference(index, partLen)));
				i_transform(m_block);

				for (i = partLen; i + 15 < p_data.Size(); i += 16)
					i_transform(p_data.Reference(i, 16));
				index = 0;
			}
			else
			{
				i = 0;
			}

			/* Buffer remaining input */
			const fs::Buffer::Offset nRemaining = p_data.Size() - i;
			fs::Copy(p_data.Reference(i, nRemaining), &(m_block.Reference(index, nRemaining)));
		}

		void Finish()
		{
			fs::dword index, padLen;

			/* Pad out to multiple of 16.
			 */
			index = m_count;
			padLen = 16 - index;
			Update(fs::Buffer(PADDING[padLen], padLen));

			Update (m_checksum);			/* Extend with checksum */

			fs::Copy(m_state, &m_digest);			/* Store state in digest */

			m_block.Zero();
			m_checksum.Zero();
			m_state.Zero();
		}

		MD2Digest()
				: m_count(0)
		{
			m_block.Zero();
			m_checksum.Zero();
			m_state.Zero();
		}
	private:
		fs::FixedBuffer<16> m_state;
		fs::FixedBuffer<16> m_checksum;
		fs::FixedBuffer<16> m_block;


		void i_transform(const fs::Buffer& p_block)
		{
			sPrecondition(16 == p_block.Size());
			unsigned int i, j, t;
			fs::FixedBuffer<48> x;

			/* Form encryption block from state, block, state ^ block.
			 */
			fs::Copy(m_state, &(x.Reference(0, 16)));
			fs::Copy(p_block, &(x.Reference(16, 16)));
			for (i = 0; i < 16; i++)
			{
				x[i+32] = m_state[i] ^ p_block[i];
			}

			/* Encrypt block (18 rounds).
			 */
			t = 0;
			for (i = 0; i < 18; i++)
			{
				for (j = 0; j < 48; j++)
				{
					t = x[j] ^= PI_SUBST[t];
				}
				t = (t + i) & 0xff;
			}

			fs::Copy(x.Reference(0, 16), &m_state);

			/* Update checksum.
			 */
			t = m_checksum[15];
			for (i = 0; i < 16; i++)
			{
				t = m_checksum[i] ^= PI_SUBST[p_block[i] ^ t];
			}

			x.Zero();
		}
	};

	void MD2(fs::Stream& p_streamInput, fs::Stream::Size p_length, fs::Buffer *p_pDigest)
	{
		MD2Digest md;

		fs::FixedBuffer<4096> page;

		fs::Stream::Size nRead = 0;

		while (nRead < p_length)
		{
			size_t nToRead = p_length - nRead;
			if (nToRead > page.Size())
			{
				nToRead = page.Size();
			}

			fs::Buffer b = page.Reference(0, nToRead);
			p_streamInput.Read(b);

			md.Update(b);
			nRead += nToRead;
		}
		md.Finish();

		fs::Copy(md.Digest(), p_pDigest);
	}
}

/* End of File: MD2.cpp */
