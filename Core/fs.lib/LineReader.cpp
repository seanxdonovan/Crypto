#include "precomp.h"
#include "declarations.h"
#include "Buffer.h"

#include "type.h"
#include "type.id.h"
#include "type.List.h"
#include "type.Traits.h"
#include "type.Conversion.h"

#include "ReferenceCountedPointer.h"
#include "Stream.h"
#include "LineReader.h"

namespace fs
{
	LineReader::LineReader(Stream& p_stream)
			: m_stream(p_stream)
			, m_storedExtra(false)
			, m_lineType(Unknown)
	{
	}

	void LineReader::Next(std::string *p_ps)
	{
		enum State {
			Reading,
			SawCR
		} state = Reading;

		if (m_storedExtra)
		{
			*p_ps += m_chExtra;
			m_storedExtra = false;
		}

		while (!m_stream.EndOfStream())
		{
			fs::byte ch;
			m_stream.Read(&ch);

			if (SawCR == state)
			{
				if (10 != ch)
				{
					m_storedExtra = true;
					m_chExtra = ch;
				}
				state = Reading;
				break;
			}
			else
			{
				if (10 == ch)
				{
					break;
				}
				else if (13 == ch)
				{
					state = SawCR;
				}
				else
				{
					*p_ps += ch;
				}
			}
		}
	}
}

/* End of File: LineReader.cpp */
