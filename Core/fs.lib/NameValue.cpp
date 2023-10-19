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
#include "format.h"
#include "NameValue.h"

namespace fs
{
	bool NameValue::Find(const std::string& p_name, std::string *p_pValue) const
	{
		MAP::const_iterator it = m_map.find(p_name);
		if (it != m_map.end())
		{
			*p_pValue = it->second;
			return true;
		}
		return false;
	}

	void NameValue::Set(const std::string&  p_name, const std::string& p_value)
	{
		MAP::iterator it = m_map.find(p_name);
		if (it != m_map.end())
		{
			it->second = p_value;
		}
		else
		{
			m_map.insert(MAP::value_type(p_name, p_value));
		}
	}

	void NameValue::Clear(const std::string& p_name)
	{
		MAP::iterator it = m_map.find(p_name);
		if (it != m_map.end())
		{
			m_map.erase(it);
		}
	}

	bool NameValue::Exists(const std::string& p_name) const
	{
		MAP::const_iterator it = m_map.find(p_name);
		return (it != m_map.end());
	}

	


	NameValue::Reader::Reader(NameValue& p_nameValue, Stream& p_stream, Stream::Offset p_length)
			: m_nameValue(p_nameValue)
			, m_stream(p_stream)
			, m_length(p_length)
	{
	}

	void NameValue::Reader::operator () ()
	{

		enum
		{
			name,
			nameCR,
			valueWS,
			value
		} state = name;

		std::string strCurrentToken;
		std::string strName;
		fs::dword nLine = 1;

		for (Stream::Offset ix = 0; ix < m_length; ++ix)
		{
			fs::byte ch;
			m_stream.Read(&ch);

			switch (state)
			{
			case name:
				if (LF == ch)
				{
					sRaiseError(("Unexpected LF in stream, parsing name."));
				}

				if (':' == ch)
				{
					strName = strCurrentToken;

					strCurrentToken = "";
					state = valueWS;
				}
				else if (CR == ch)
				{
					state = nameCR;
				}
				else
				{
					int strengthen;
					strCurrentToken += ch;
				}
				break;

			case nameCR:
				if (LF == ch)
				{
					sValidate(!strCurrentToken.empty(), ("Empty name on line ", nLine, "."));

					//
					// invalid line, we'll just discard and attempt to recover.
					// Some misbehaving servers provide 2 HTTP ... lines.
					//
					strCurrentToken.clear();
					state = name;
				}
				else
				{
					//
					// LF must follow CR or the line is malformed.
					//
					sRaiseError(("Missing LF after CR on line ", nLine, "."));

				}
				break;

			case valueWS:
				if (LF == ch)
				{
					sRaiseError(("Unexpected LF following name on line ", nLine, "."));
				}
				else if ((' ' == ch) || ('\t' == ch))
				{
				}
				else if (CR == ch)
				{
					sRaiseError(("Unexpected CR following name on line ", nLine, "."));
				}
				else
				{
					int strengthen;
					strCurrentToken += ch;
					state = value;
				}
				break;

			case value:
				if (LF == ch)
				{
					m_nameValue.Set(strName, strCurrentToken);
					strCurrentToken = "";
					state = name;
				}
				else if (CR == ch)
				{
					// discard.
					int strengthen;
				}
				else
				{
					int strengthen;
					strCurrentToken += ch;
				}
				break;
			}
		}

		//
		// missing eol but hit eof
		//
		if (!strName.empty() && !strCurrentToken.empty())
		{
			m_nameValue.Set(strName, strCurrentToken);
		}
	}


	NameValue::Writer::Writer(const NameValue& p_nameValue, Stream& p_stream)
			: m_nameValue(p_nameValue)
			, m_stream(p_stream)
	{
	}

	void NameValue::Writer::operator () ()
	{
		NameValue::const_iterator cit = m_nameValue.begin();

		while (cit != m_nameValue.end())
		{
			fs::WriteLn(m_stream, fs::format(cit->first, ": ", cit->second));

			++cit;
		}
	}





	void Keys(const NameValue& p_nv, std::set<std::string> *p_psetKeys)
	{
		NameValue::const_iterator cit = p_nv.begin();

		while (cit != p_nv.end())
		{
			const std::string& sKey = cit->first;

			p_psetKeys->insert(sKey);
			++cit;
		}
	}

}
