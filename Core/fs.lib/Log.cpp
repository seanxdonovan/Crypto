#include "precomp.h"
#include "declarations.h"
#include "Buffer.h"

#include "type.h"
#include "type.id.h"
#include "type.List.h"
#include "type.Traits.h"
#include "type.Conversion.h"

#include "ReferenceCountedPointer.h"

#include "Log.h"

namespace fs
{
	namespace
	{
		const ::fs::byte Log_Type_Info    = 1;
		const ::fs::byte Log_Type_Warning = 2;
		const ::fs::byte Log_Type_Error   = 3;
	}

	Log *Log::m_instance;
	Log& Log::Instance()
	{
		if (0 == m_instance)
		{
			sRaiseError(("NULL Instance for singleton accessor"));
		}
		return *m_instance;
	}


	Log::Log()
			: m_started(false)
	{
		sValidate(0 == m_instance, ("There can be only one instance of Log"));
		m_instance = this;
	}

	Log::~Log()
	{
		m_lpAdaptors.clear();
		m_instance = 0;
	}

	void Log::Add(const Adaptor::RCP& p_pAdaptor)
	{
		m_lpAdaptors.push_back(p_pAdaptor);
	}

	void Log::Remove(const Adaptor::RCP& p_pAdaptor)
	{
		std::list<Adaptor::RCP>::iterator it = m_lpAdaptors.begin();
		while (it != m_lpAdaptors.end())
		{
			if (*it == p_pAdaptor)
			{
				m_lpAdaptors.erase(it);
				return;
			}
			++it;
		}
	}

	void Log::Info(const std::string& p_s)
	{
		if (m_started)
		{
			i_doInfo(p_s.c_str());
		}
		else
		{
			Entry e;
			e.m_type = Log_Type_Info;
			e.m_message = p_s;
			m_vEntriesPendingStart.push_back(e);
		}
	}


	void Log::i_doInfo(const char * p_s)
	{
		std::list<Adaptor::RCP>::iterator it = m_lpAdaptors.begin();
		while (it != m_lpAdaptors.end())
		{
			const Adaptor::RCP& p = *it;

			p->Info(p_s);
			++it;
		}
	}


	void Log::Warning(const std::string& p_s)
	{
		if (m_started)
		{
			i_doWarning(p_s.c_str());
		}
		else
		{
			Entry e;
			e.m_type = Log_Type_Warning;
			e.m_message = p_s;
			m_vEntriesPendingStart.push_back(e);
		}
	}

	void Log::i_doWarning(const char * p_s)
	{
		std::list<Adaptor::RCP>::iterator it = m_lpAdaptors.begin();
		while (it != m_lpAdaptors.end())
		{
			const Adaptor::RCP& p = *it;

			p->Warning(p_s);
			++it;
		}
	}

	void Log::Error(const std::string& p_s)
	{
		if (m_started)
		{
			i_doError(p_s.c_str());
		}
		else
		{
			Entry e;
			e.m_type = Log_Type_Error;
			e.m_message = p_s;
			m_vEntriesPendingStart.push_back(e);
		}
	}

	void Log::i_doError(const char * p_s)
	{
		std::list<Adaptor::RCP>::iterator it = m_lpAdaptors.begin();
		while (it != m_lpAdaptors.end())
		{
			const Adaptor::RCP& p = *it;

			p->Error(p_s);
			++it;
		}
	}

	Log::Adaptor::Adaptor()
	{
	}

	Log::Adaptor::~Adaptor()
	{
	}


	void Log::Start()
	{
		m_started = true;

		i_displayBanner();

		for (size_t ix = 0; ix < m_vEntriesPendingStart.size(); ++ix)
		{
			const auto & e = m_vEntriesPendingStart[ix];
			switch (e.m_type)
			{
			case Log_Type_Info:
				Info(e.m_message);
				break;

			case Log_Type_Warning:
				Warning(e.m_message);
				break;

			case Log_Type_Error:
				Error(e.m_message);
				break;
			}
		}
	}

	void Log::AppendBanner(const std::string& p_sBannerLine)
	{
		m_vsBanner.push_back(p_sBannerLine);
	}

	void Log::i_displayBanner()
	{
		for (size_t ix = 0; ix < m_vsBanner.size(); ++ix)
		{
			Info(m_vsBanner[ix]);
		}
	}

}

/* End Of File: Log.cpp */
