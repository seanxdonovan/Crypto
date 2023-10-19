
namespace crypto
{
	namespace base64
	{
		void Encode(const fs::Buffer& p_buffer, std::string *p_encoded);
		void Decode(const std::string& p_encodedText, fs::Buffer *p_pData);

		size_t DecodedBufferSize(const std::string& p_encodedText);

		void Encode(fs::Stream& p_from, fs::Stream& p_to, fs::Stream::Offset p_length);
		void Decode(fs::Stream& p_from, fs::Stream& p_to, fs::Stream::Offset p_length);
	}

	void SHA_512(fs::Stream& p_streamInput, fs::Stream::Size p_length, fs::Buffer *p_pDigest);
	void SHA_384(fs::Stream& p_streamInput, fs::Stream::Size p_length, fs::Buffer *p_pDigest);
	void SHA_256(fs::Stream& p_streamInput, fs::Stream::Size p_length, fs::Buffer *p_pDigest);
	void SHA_224(fs::Stream& p_streamInput, fs::Stream::Size p_length, fs::Buffer *p_pDigest);
	void MD5(fs::Stream& p_streamInput, fs::Stream::Size p_length, fs::Buffer *p_pDigest);
	void MD2(fs::Stream& p_streamInput, fs::Stream::Size p_length, fs::Buffer *p_pDigest);

	const fs::dword crc32_polynominal = 0x04C11DB7;

	fs::dword crc32(const fs::Buffer&, fs::dword p_crc , fs::dword p_polynominal);
	fs::dword crc32(fs::Stream& p_streamInput, fs::Stream::Size p_length, fs::dword p_polynominal = crc32_polynominal);


	void HMAC_MD5(fs::Buffer p_test, fs::Buffer p_key, fs::Buffer *p_pDigest);
}

#include "SHA1.h"
#include "RC4.h"

#include "AES.h"

/* End Of File: crypto.lib.h */
