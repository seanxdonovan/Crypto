#include "precomp.h"

#include "RC4.h"

namespace crypto
{
	RC4::RC4(const fs::Buffer& p_key)
	    : m_x(0)
		, m_y(0)
	{
		size_t ix;
		size_t jx;

		for (ix = 0; ix < 256; ++ix)
		{
			m_state[ix] = sCoerce(fs::byte, ix);
		}

		jx = 0;
		for (ix = 0; ix < 256; ++ix)
		{
			jx = (jx + m_state[ix] + p_key[ix % p_key.Size()]) % 256;
			fs::swap(&m_state[ix], &m_state[jx]);
		}
	}

	RC4::~RC4()
	{
		m_x = 0;
		m_y = 0;
		m_state.Zero();
	}

	void RC4::Encode(fs::Buffer *p_pInOut)
	{
		for (size_t ix = 0; ix < p_pInOut->Size(); ++ix)
		{
			m_x = (m_x + 1) % 256;
			m_y = (m_state[m_x] + m_y) % 256;
			fs::swap(&m_state[m_x], &m_state[m_y]);

			fs::byte ixCryptByte = (m_state[m_x] + m_state[m_y]) % 256;

			(*p_pInOut)[ix] ^= m_state[ixCryptByte];
		}
	}

}

/* End of File: RC4.cpp */
