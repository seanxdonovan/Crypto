#include "precomp.h"
#include "Core/fs.lib/fs.lib.h"
#include "Core/ss.lib/ss.lib.h"

#include "Configuration.h"


namespace tools
{
	void Configuration::AddConfigurationFile(const std::string& p_sConfigurationFile)
	{
		m_vsConfigurationFiles.push_back(p_sConfigurationFile);
	}

	void Configuration::PrependConfigurationFile(const std::string& p_sConfigurationFile)
	{
		m_vsConfigurationFiles.push_front(p_sConfigurationFile);
	}

	void Configuration::LoadConfigurationFiles(fs::Log& p_log)
	{
		p_log.Info("ConfigurationPath.");
		for (size_t ix = 0; ix < ConfigurationPath.size(); ++ix)
		{
			p_log.Info("[", ix, "] - '", ss::ToString(ConfigurationPath[ix]), "'.");
		}

		ss::Filename fnConfig;
		for (size_t ix = 0; ix < m_vsConfigurationFiles.size(); ++ix)
		{
			const std::string& sFilename = m_vsConfigurationFiles[ix];

			if (ConfigurationPath.Find(sFilename, &fnConfig))
			{
				p_log.Info("Using config file: '", ss::ToString(fnConfig), "'.");

				ss::File f;
				ss::File::Closer fc(f);
				ss::FileStream fs(f);
				ss::File::Parameters params;
				params.DesiredAccess(GENERIC_READ);
				params.CreationDisposition(OPEN_EXISTING);
				params.ShareMode(FILE_SHARE_READ); // allow the log to be viewed.

				f.Create(fnConfig, params);
				Options.ReadConfiguration(fs, f.Size());
			}
			else
			{
				p_log.Warning("Missing configuration file: '", sFilename, "'.");
			}
		}
	}

	void Configuration::Dump(::fs::Log& p_log)
	{
		p_log.Info("Executable: ", fnExecutable);
		p_log.Info("Temporary:  ", fnTemporaryDirectory);
		p_log.Info("Logs:       ", LogDirectory);
		p_log.Info("Data:       ", DataDirectory);
		p_log.Info("NVmem:      ", fnNVmemDirectory);

		for (size_t ix = 0; ix < DataPath.size(); ++ix)
		{
			p_log.Info("DataPath: [", ix, "] ",  DataPath[ix]);
		}

		for (size_t ix = 0; ix < ConfigurationPath.size(); ++ix)
		{
			p_log.Info("ConfigurationPath: [", ix, "] ",  ConfigurationPath[ix]);
		}

		auto itConfigFiles = m_vsConfigurationFiles.begin();
		while (itConfigFiles != m_vsConfigurationFiles.end())
		{
			::ss::Filename fn;
			if (ConfigurationPath.Find(*itConfigFiles, &fn))
			{
				p_log.Info("ConfigFile: ", *itConfigFiles, " - using - ", fn);
			}
			else
			{
				p_log.Info("ConfigFile: ", *itConfigFiles, " not found.");
			}
			++itConfigFiles;
		}

		auto itDefaults = Options.DefaultItems().begin();
		while (itDefaults != Options.DefaultItems().end())
		{
			p_log.Info("Default ['", itDefaults->first, "'] = '", itDefaults->second, "'.");
			++itDefaults;
		}

		auto itConfigurations = Options.ConfigurationItems().begin();
		while (itConfigurations != Options.ConfigurationItems().end())
		{
			p_log.Info("Config ['", itConfigurations->first, "'] = '", itConfigurations->second, "'.");
			++itConfigurations;
		}

		auto itOptions = Options.OptionItems().begin();
		while (itOptions != Options.OptionItems().end())
		{
			p_log.Info("Option ['", itOptions->first, "'] = '", itOptions->second, "'.");
			++itOptions;
		}

	}

	void Configuration::ReadArgumentsFrom(const std::string& filename, std::vector<std::string> *p_pCommandLine)
	{
		FILE *f = fopen(filename.c_str(), "rb");

		sValidate(0 != f, ("Failed to open response file '", filename, "', GetLastError() == ", GetLastError(), "."));

		fs::si32 nLine = 0;
		std::string s;

		enum State
		{
			EatingWS,
			ReadingQuotedToken,
			ReadingToken
		} state = EatingWS;

		while (!feof(f))
		{
			const char ch = fgetc(f);

			if (EatingWS == state)
			{
				if (ch != ' ' && ch != 10 && ch != 13 && ch != '\t')
				{
					s.clear();
					if ('"' == ch)
					{
						state = ReadingQuotedToken;
					}
					else
					{
						state = ReadingToken;
						s += ch;
					}
				}
				if ('\n' == ch)
				{
					++nLine;
				}
			}
			else if (ReadingQuotedToken == state)
			{
				if (ch == '"')
				{
					state = EatingWS;
					if (!s.empty())
					{
						p_pCommandLine->push_back(s);
					}
				}
				else if (10 == ch || 13 == ch)
				{
					sRaiseError(("unexpected newline in quoted token on line ", nLine, " of response file ", filename, "."));
				}
				else
				{
					s += ch;
				}
			}
			else if (ReadingToken == state)
			{
				if (10 == ch || 13 == ch || '\t' == ch || ' ' == ch)
				{
					state = EatingWS;
					if (!s.empty())
					{
						p_pCommandLine->push_back(s);
					}
				}
				else
				{
					s += ch;
				}
			}
			else
			{
				sRaiseError(("Unknown state in response file parser."));
			}
		}

		fclose(f);
	}

	void Configuration::PreProcessCommandLine(const std::vector<std::string>& p_commandLine, std::vector<std::string> *p_pCommandLine)
	{
		for (size_t ix = 0; ix < p_commandLine.size(); ++ix)
		{
			const std::string& arg = p_commandLine[ix];

			if (!arg.empty())
			{
				if ('@' == arg[0])
				{
					//
					// Response File. Open, read
					// and augment args.
					//

					std::string filename = arg.substr(1, arg.size() - 1);

					ReadArgumentsFrom(filename, p_pCommandLine);
				}
				else
				{
					p_pCommandLine->push_back(arg);
				}
			}
		}
	}

	void Configuration::ProcessCommandLine(const std::vector<std::string>& p_vs)
	{
		for (size_t ix = 0; ix < p_vs.size(); ++ix)
		{
			const std::string& s = p_vs[ix];

			if (!s.empty() && '-' == s[0]) // option
			{
				size_t offset = s.find(':', 1);
				std::string sName;
				std::string sValue;
				if (std::string::npos != offset)
				{
					sName = s.substr(1, offset - 1);
					sValue = s.substr(offset + 1);
				}
				else
				{
					sName = s.substr(1);
					sValue = "true";
				}

				ss::Filename fn;
				if ("ConfigFile" == sName)
				{
					AddConfigurationFile(sValue);
				}
				else if ("ConfigDir" == sName)
				{
					ss::Parse(sValue, &fn);
					ConfigurationPath.Append(fn);
				}
				else if ("DataDir" == sName)
				{
					ss::Parse(sValue, &fn);
					DataPath.Append(fn);
				}
				else
				{
					NotifierMap::iterator it = m_mapNotifiers.find(sName);
					if (it != m_mapNotifiers.end())
					{
						it->second(sValue);
					}
					else
					{
						::fs::Log::Instance().Info("Set '", sName, "' to '", sValue, "'.");
						Options.SetOption(sName, sValue);

					}
				}
			}
			else // arg
			{
				Arguments.push_back(s);
			}
		}
	}

	void Configuration::Hook(const std::string& p_sOption, fs::PT<OptionFunctor>::T p_fHook)
	{
		m_mapNotifiers[p_sOption].Subscribe(p_fHook);
	}


	::std::string Configuration::TemporaryDirectory()
	{
		auto s = ::fs::format(fnTemporaryDirectory);

		return s;
	}

	::std::string Configuration::GenerateTemporaryFileName()
	{
		::ss::Filename fn = fnTemporaryDirectory;

		fn.m_filename = ::fs::format(::GetCurrentProcessId(), ".", ::GetCurrentThreadId(), ".", ::fs::TickCount(),  ".temporary");

		auto dir = ::fs::format(fn);

		return dir;
	}


	void Configuration::SetTemporary(const ss::Filename& p_fn)
	{
		sValidate(::ss::IsDirectory(p_fn), ("'", ss::ToString(p_fn), "' is not a directory."));

		fnTemporaryDirectory = p_fn;
	}


	::std::string Configuration::CompanyName() const
	{
		return m_sCompanyName;
	}

	::std::string Configuration::ProductLineName() const
	{
		return m_sProductLineName;
	}

	::std::string Configuration::ApplicationName() const
	{
		return m_sApplicationName;
	}



	void Configuration::SetCompanyName    (const ::std::string& p_s)
	{
		m_sCompanyName = p_s;
	}

	void Configuration::SetProductLineName(const ::std::string& p_s)
	{
		m_sProductLineName = p_s;
	}

	void Configuration::SetApplicationName(const ::std::string& p_s)
	{
		m_sApplicationName = p_s;
	}



	::std::string Configuration::CompanyDirectory() const
	{
		return ::std::string();
	}

	::std::string Configuration::ProductLineDirectory() const
	{
		return ::std::string();
	}

	::std::string Configuration::ApplicationDirectory() const
	{
		return ::std::string();
	}


	::std::string Configuration::HomeDirectory() const
	{
		return ::fs::format(m_fnHome);
	}

	::std::string Configuration::RootDirectory() const
	{
		return ::fs::format(m_fnRoot);
	}


	void Configuration::GetRootDirectory(::ss::Filename *p_pfn)
	{
		*p_pfn = m_fnRoot;
	}

	void Configuration::GetHomeDirectory(::ss::Filename *p_pfn)
	{
		*p_pfn = m_fnHome;
	}

	void Configuration::SetRootDirectory(const ::ss::Filename& p_fn)
	{
		m_fnRoot = p_fn;
	}


	void Configuration::SetHomeDirectory(const ::ss::Filename& p_fn)
	{
		m_fnHome = p_fn;
	}

	void Configuration::LoadExecutablePath()
	{
		::tools::GetPath("PATH", &ExecutablePath);
	}

}

namespace tools
{
	void Specialize(const ::std::string& p_sName, ::fs::Date p_date, ::ss::Filename *p_pfn)
	{
		p_pfn->Append(::ss::format(p_date));
		p_pfn->Append(p_sName);
	}

	void ConfigureForDay(const ::std::string& p_sName, ::fs::Date p_date, ::tools::Configuration *p_pConfiguration)
	{
		::ss::Filename fnCWD;
		::ss::CurrentWorkingDirectory(&fnCWD);

		p_pConfiguration->LogDirectory = fnCWD;
		p_pConfiguration->DataDirectory = fnCWD;
		p_pConfiguration->fnNVmemDirectory = fnCWD;

		::std::string s;

		if (p_pConfiguration->Options.Find("LogDirectory", &s))
		{
			::ss::Parse(s, &p_pConfiguration->LogDirectory);
		}

		if (p_pConfiguration->Options.Find("DataDirectory", &s))
		{
			::ss::Parse(s, &p_pConfiguration->DataDirectory);
		}

		if (p_pConfiguration->Options.Find("NVmemDirectory", &s))
		{
			::ss::Parse(s, &p_pConfiguration->fnNVmemDirectory);
		}

		Specialize(p_sName, p_date, &p_pConfiguration->LogDirectory);
//		Specialize(p_sName, p_date, &p_pConfiguration->DataDirectory);
		Specialize(p_sName, p_date, &p_pConfiguration->fnNVmemDirectory);


		if (!::ss::Exists(p_pConfiguration->LogDirectory))
		{
			::ss::MakeDirectory(p_pConfiguration->LogDirectory);
		}

		if (!::ss::Exists(p_pConfiguration->fnNVmemDirectory))
		{
			::ss::MakeDirectory(p_pConfiguration->fnNVmemDirectory);
		}
	}
}


namespace tools
{
	bool GetPath(const std::string& p_sName, ::ss::Path *p_pPath)
	{
		std::string sPath;
		fs::HeapBuffer hb;

		DWORD n = GetEnvironmentVariable(p_sName.c_str(), hb.Data<char>(), hb.Size());
		sValidate(0 != n, ("Environment Variable '", p_sName, "' not found."));
		if (n > hb.Size())
		{
			hb.Resize(n);
			n = GetEnvironmentVariable(p_sName.c_str(), hb.Data<char>(), hb.Size());
			sValidate(n <= hb.Size(), ("Something odd happened."));
		}
		sPath = hb.Data<char>();

		p_pPath->Parse(sPath);

		return true;
	}
}

