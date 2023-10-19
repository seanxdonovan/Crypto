#include "precomp.h"

namespace crypto
{
	fs::dword crc32(fs::Stream& p_streamInput, fs::Stream::Size p_length, fs::dword p_polynominal)
	{
		fs::dword crc32 = 0xFFffFFff;

		for (size_t index = 0; index < p_length; ++index)
		{
			fs::byte current;
			p_streamInput.Read(&current);

			crc32 ^= (current << 24);

			for (size_t bit = 0; bit < 8; ++bit)
			{
				if (crc32 & 0x80000000)
				{
					crc32 = (crc32 << 1);
					crc32 ^= p_polynominal;
				}
				else
				{
					crc32 = crc32 << 1;
				}
			}
		}

		return crc32 ^ 0xFFffFFff;
	}
}

/* End Of File: crc32.cpp */

#if 0
Appendix A:  CRC Generation

    The following unoptimized code generates proper CRC-16 and CRC-32
    values for SDL messages.  Note that the polynomial bits are numbered
    in big-endian order for SDL CRCs; bit 0 is the MSB.

    typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
#define POLY16  0x1021
#define POLY32  0x04C11DB7

u16
   crc16(u16 crcval, u8 cval)
{
	int i;

	crcval ^= cval << 8;
	for (i = 8; i--; )
		crcval = crcval & 0x8000 ? (crcval << 1) ^ POLY16 :
			 crcval << 1;
	return crcval;
}

u32
   crc32(u32 crcval, u8 cval)
{
	int i;

	crcval ^= cval << 24;
	for (i = 8; i--; )
		crcval = crcval & 0x80000000 ? (crcval << 1) ^ POLY32 :
			 crcval << 1;
	return crcval;
}

u16
   crc16_special(u8 *buffer, int len)
{
	u16 crc;

	crc = 0;
	while (--len >= 0)
		crc = crc16(crc,*buffer++);
	return crc;
}




Carlson, et al.             expires May 1999                   [Page 16]

   INTERNET DRAFT            PPP SDL on SONET/SDH             November 1998


   u16
   crc16_payload(u8 *buffer, int len)
{
	u16 crc;

	crc = 0xFFFF;
	while (--len >= 0)
		crc = crc16(crc,*buffer++);
	return crc ^ 0xFFFF;
}

u32
   crc32_payload(u8 *buffer, int len)
{
	u32 crc;

	crc = 0xFFFFFFFFul;
	while (--len >= 0)
		crc = crc32(crc,*buffer++);
	return crc ^ 0xFFFFFFFFul;
}

#endif