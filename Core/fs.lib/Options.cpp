#include "precomp.h"
#include "declarations.h"
#include "type.h"
#include "type.id.h"
#include "type.List.h"
#include "type.Traits.h"
#include "type.Conversion.h"

#include "Buffer.h"

#include "ReferenceCountedPointer.h"
#include "Stream.h"

#include "format.h"
#include "NameValue.h"
#include "io.h"
#include "Layout.h"

#include "fsTime.h"
#include "Date.h"
#include "DateTime.h"

#include "Options.h"

namespace fs
{
	void Options::Merge(const ::fs::Options& p_options)
	{
		::std::string s;

		auto itDefault = p_options.DefaultItems().begin();
		while (itDefault != p_options.DefaultItems().end())
		{
			if (!m_defaults.Find(itDefault->first, &s))
			{
				m_defaults.Set(itDefault->first, itDefault->second);
			}

			++itDefault;
		}

		auto itConfig = p_options.ConfigurationItems().begin();
		while (itConfig != p_options.ConfigurationItems().end())
		{
			if (!m_configuration.Find(itConfig->first, &s))
			{
				m_configuration.Set(itConfig->first, itConfig->second);
			}

			++itConfig;
		}

		auto itOption = p_options.OptionItems().begin();
		while (itOption != p_options.OptionItems().end())
		{
			if (!m_options.Find(itOption->first, &s))
			{
				m_options.Set(itOption->first, itOption->second);
			}

			++itOption;
		}
	}


	const fs::NameValue& Options::DefaultItems() const
	{
		return m_defaults;
	}

	const fs::NameValue& Options::ConfigurationItems() const
	{
		return m_configuration;
	}

	const fs::NameValue& Options::OptionItems() const
	{
		return m_options;
	}

	void Options::SetDefault(const std::string& p_sName, const std::string& p_sValue)
	{
		m_defaults.Set(p_sName, p_sValue);
	}

	void Options::SetOption(const std::string& p_sName, const std::string& p_sValue)
	{
		m_options.Set(p_sName, p_sValue);
	}

	void Options::ReadConfiguration(fs::Stream& p_input, const fs::Stream::Offset p_inputSize)
	{
		fs::NameValue::Reader  r(m_configuration, p_input, p_inputSize);
		r();
	}

	bool Options::Find(const std::string& p_sName, std::string *p_psValue) const
	{
		if (m_options.Find(p_sName, p_psValue))
		{
			return true;
		}

		if (m_configuration.Find(p_sName, p_psValue))
		{
			return true;
		}

		if (m_defaults.Find(p_sName, p_psValue))
		{
			return true;
		}

		return false;
	}

	void Options::Require(const std::string& p_sName, std::string    *p_pValue) const
	{
		sValidate(Find(p_sName, p_pValue), ("Could not find Required Option '", p_sName, "'."));
	}

	void Options::Require(const std::string& p_sName, bool           *p_pValue) const
	{
		std::string s;
		Require(p_sName, &s);
		sValidate(fs::Convert(s, p_pValue), ("Could not Convert Required Option '", p_sName, "' == '", s, "' to bool."));
	}

	void Options::Require(const std::string& p_sName, fs::byte       *p_pValue) const
	{
		std::string s;
		Require(p_sName, &s);
		sValidate(fs::Convert(s, p_pValue), ("Could not Convert Required Option '", p_sName, "' == '", s, "' to fs::byte."));
	}

	void Options::Require(const std::string& p_sName, fs::word       *p_pValue) const
	{
		std::string s;
		Require(p_sName, &s);
		sValidate(fs::Convert(s, p_pValue), ("Could not Convert Required Option '", p_sName, "' == '", s, "' to fs::word."));
	}

	void Options::Require(const std::string& p_sName, fs::dword      *p_pValue) const
	{
		std::string s;
		Require(p_sName, &s);
		sValidate(fs::Convert(s, p_pValue), ("Could not Convert Required Option '", p_sName, "' == '", s, "' to fs::dword."));
	}

	void Options::Require(const std::string& p_sName, fs::qword      *p_pValue) const
	{
		std::string s;
		Require(p_sName, &s);
		sValidate(fs::Convert(s, p_pValue), ("Could not Convert Required Option '", p_sName, "' == '", s, "' to fs::qword."));
	}

#if 0
	void Options::Require(const std::string& p_sName, fs::si8        *p_pValue) const
	{
		std::string s;
		Require(p_sName, &s);
		sValidate(fs::Convert(s, p_pValue), ("Could not Convert Required Option '", p_sName, "' == '", s, "' to fs::si8."));
	}
#endif

#if 0
	void Options::Require(const std::string& p_sName, fs::si16       *p_pValue) const
	{
		std::string s;
		Require(p_sName, &s);
		sValidate(fs::Convert(s, p_pValue), ("Could not Convert Required Option '", p_sName, "' == '", s, "' to fs::si16."));
	}
#endif

#if 0
	void Options::Require(const std::string& p_sName, fs::si32       *p_pValue) const
	{
		std::string s;
		Require(p_sName, &s);
		sValidate(fs::Convert(s, p_pValue), ("Could not Convert Required Option '", p_sName, "' == '", s, "' to fs::si32."));
	}
#endif
	void Options::Require(const std::string& p_sName, fs::si64       *p_pValue) const
	{
		std::string s;
		Require(p_sName, &s);
		sValidate(fs::Convert(s, p_pValue), ("Could not Convert Required Option '", p_sName, "' == '", s, "' to fs::si64."));
	}


	void Options::Require(const std::string& p_sName, fs::Double     *p_pValue) const
	{
		std::string s;
		sValidate(Find(p_sName, &s), ("Could not find Required Option '", p_sName, "'."));
		sValidate(fs::Convert(s, p_pValue), ("Could not Convert Required Option '", p_sName, "' == '", s, "' to fs::Double."));
	}

	void Options::Require(const std::string& p_sName, fs::Time       *p_pValue) const
	{
		std::string s;
		sValidate(Find(p_sName, &s), ("Could not find Required Option '", p_sName, "'."));
		sValidate(fs::Convert(s, p_pValue), ("Could not Convert Required Option '", p_sName, "' == '", s, "' to fs::Time."));
	}

	void Options::Require(const std::string& p_sName, fs::Time::Span *p_pValue) const
	{
		std::string s;
		sValidate(Find(p_sName, &s), ("Could not find Required Option '", p_sName, "'."));
		sValidate(fs::Convert(s, p_pValue), ("Could not Convert Required Option '", p_sName, "' == '", s, "' to fs::Time::Span."));
	}


	void Options::Require(const std::string& p_sName, fs::Date       *p_pValue) const
	{
		std::string s;
		sValidate(Find(p_sName, &s), ("Could not find Required Option '", p_sName, "'."));
		sValidate(fs::Convert(s, p_pValue), ("Could not Convert Required Option '", p_sName, "' == '", s, "' to fs::Date::Span."));
	}
	void Options::Require(const std::string& p_sName, fs::DateTime   *p_pValue) const
	{
		std::string s;
		sValidate(Find(p_sName, &s), ("Could not find Required Option '", p_sName, "'."));
		sValidate(fs::Convert(s, p_pValue), ("Could not Convert Required Option '", p_sName, "' == '", s, "' to fs::DateTime."));
	}

	void Options::Require(const std::string& p_sName, fs::DateTime::Span *p_pValue) const
	{
		std::string s;
		sValidate(Find(p_sName, &s), ("Could not find Required Option '", p_sName, "'."));
		sValidate(fs::Convert(s, p_pValue), ("Could not Convert Required Option '", p_sName, "' == '", s, "' to fs::DateTime::Span."));
	}
}
