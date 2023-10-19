#include "precomp.h"


namespace crypto
{
	void MD5(fs::Stream& p_streamInput, fs::Stream::Size p_length, fs::Buffer *p_pDigest);

	//
	// See RFC 2104 HMAC: Keyed-Hashing for Message Authentication
	//


	void HMAC_MD5(fs::Buffer p_text, fs::Buffer p_key, fs::Buffer *p_pDigest)
	{
		fs::FixedBuffer<64> key;
		key.Zero();
		if (p_key.Size() > 64)
		{
			fs::BufferStream strm(p_key);
			MD5(strm, p_key.Size(), &key);
		}
		else
		{
			fs::Copy(p_key, &key);
		}

		fs::FixedBuffer<64> key_ipad;
		key_ipad.Zero();

		fs::FixedBuffer<64> key_opad;
		key_opad.Zero();

		fs::byte ipad_byte = 0x36;
		fs::byte opad_byte = 0x5C;

		fs::Copy(key, &key_ipad);
		fs::Copy(key, &key_opad);

		for (size_t ix = 0; ix < 64; ++ix)
		{
			key_ipad[ix] ^= ipad_byte;
			key_opad[ix] ^= opad_byte;
		}

		//
		// Inner digest
		//
		fs::ExpandingBuffer eb1;
		fs::ExpandingBufferStream ebs1(eb1);
		eb1.Write(key_ipad);
		eb1.Write(p_text);
		fs::FixedBuffer<16> innerDigest;
		MD5(ebs1, eb1.DataSize(), &innerDigest);

		fs::ExpandingBuffer ebOuter;
		fs::ExpandingBufferStream ebsOuter(ebOuter);
		ebOuter.Write(key_opad);
		ebOuter.Write(innerDigest);

		MD5(ebsOuter, ebOuter.DataSize(), p_pDigest);
	}

}
