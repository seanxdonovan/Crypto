#include "precomp.h"
#include "../fs.lib/fs.lib.h"
#include "declarations.h"

namespace tools
{
	namespace base64
	{
		namespace internal
		{
			const char output_table[] = {
				'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
				'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
				'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
				'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
				'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
				'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
				'w', 'x', 'y', 'z', '0', '1', '2', '3',
				'4', '5', '6', '7', '8', '9', '+', '/'
			};

			const bool valid_input_table [] = {
				false
			};

			const char pad = '=';
		}
		void Encode(const fs::Buffer& p_buffer, std::string *p_encoded)
		{
			const fs::dword datasize = p_buffer.Size();
			const fs::dword nWholeTriples = datasize / 3;
			fs::dword stringSize = nWholeTriples * 4;
			if (0 != datasize % 3)
			{
				stringSize += 4;
			}
			p_encoded->resize(stringSize);

			fs::dword n = 0;

			while (n < nWholeTriples)
			{
				fs::byte b1 = p_buffer[n * 3 + 0];
				fs::byte b2 = p_buffer[n * 3 + 1];
				fs::byte b3 = p_buffer[n * 3 + 2];

				(*p_encoded)[4 * n + 0] = internal::output_table[(b1 & 0xFC) >> 2];
				(*p_encoded)[4 * n + 1] = internal::output_table[((b1 & 3) << 4) | ((b2 & 0xF0) >> 4)];
				(*p_encoded)[4 * n + 2] = internal::output_table[((b2 & 0x0F) << 2) | ((b3 & 0xC0) >> 6)];
				(*p_encoded)[4 * n + 3] = internal::output_table[(b3 & 0x3F)];

				++n;
			}

			fs::dword nRemainder = datasize % 3;

			if (1 == nRemainder)
			{
				fs::byte b1 = p_buffer[n * 3 + 0];

				(*p_encoded)[4 * n + 0] = internal::output_table[(b1 & 0xFC) >> 2];
				(*p_encoded)[4 * n + 1] = internal::output_table[((b1 & 3) << 4)];
				(*p_encoded)[4 * n + 2] = internal::pad;
				(*p_encoded)[4 * n + 3] = internal::pad;
			}
			else if (2 == nRemainder)
			{
				fs::byte b1 = p_buffer[n * 3 + 0];
				fs::byte b2 = p_buffer[n * 3 + 1];

				(*p_encoded)[4 * n + 0] = internal::output_table[(b1 & 0xFC) >> 2];
				(*p_encoded)[4 * n + 1] = internal::output_table[((b1 & 3) << 4) | ((b2 & 0xF0) >> 4)];
				(*p_encoded)[4 * n + 2] = internal::output_table[((b2 & 0x0F) << 2)];
				(*p_encoded)[4 * n + 3] = internal::pad;
			}
		}

		void Decode(const std::string& p_encodedText, fs::Buffer *p_pData)
		{
			sAssert(false); //NI
		}

	} /* base64 */

} /* tools */

/* End Of File: base64.cpp */
