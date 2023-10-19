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

#include "Formatter.h"


namespace fs
{
	Formatter::Formatter(fs::Stream& p_stream)
			: m_stream(p_stream)
			, m_depth(0)
			, m_sIndent("\t")
	{
	}

	void Formatter::SetMargin(const std::string& p_sMargin)
	{
		m_margin = p_sMargin;
	}

	void Formatter::SetIndent(const std::string& p_sIndent)
	{
		m_sIndent = p_sIndent;
	}

	void Formatter::DepthDecrement()
	{
		sPrecondition(m_depth > 0);

		m_stackPrefix.pop_back();
		--m_depth;
	}

	void Formatter::DepthIncrement()
	{
		++m_depth;
		m_stackPrefix.push_back(m_sIndent);
	}

	const fs::dword Formatter::Depth() const
	{
		return m_depth;
	}

	void Formatter::NewLine()
	{
		WriteLn("");
	}

	void Formatter::WriteLn(const std::string& p_s)
	{
		std::string s = m_margin;

		for (size_t ix = 0; ix < m_stackPrefix.size(); ++ix)
		{
			s += m_stackPrefix[ix];
		}

		s += p_s;

		fs::WriteLn(m_stream, s);
	}
}
