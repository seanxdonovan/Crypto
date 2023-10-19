#include "precomp.h"
#include "Core/fs.lib/fs.lib.h"
#include "Core/ss.lib/ss.lib.h"
#include "StdoutLog.h"
#include "Configuration.h"
#include "CommandInterpreter.h"
#include "ConsoleApplication.h"

namespace tools
{
	::fs::Log& ConsoleApplication::GetLog()
	{
		return m_log;
	}



	static void i_checkOrMake(const ss::Filename& p_base, const std::string& p_sub, ss::Filename *p_pfn)
	{
		*p_pfn = p_base;
		p_pfn->Append(p_sub);

		if (ss::Exists(*p_pfn) && !ss::IsDirectory(*p_pfn))
		{
			sRaiseError(("'", ss::ToString(*p_pfn), "' exists and is not a directory."));
		}

		ss::MakeDirectory(*p_pfn);
	}


	ConsoleApplication::ConsoleApplication(const std::string& p_sCompanyName,
				   const std::string& p_sProductLineName,
				   const std::string& p_sApplicationName)
	{
		sAssert(0 == m_pCurrentApplication);
		m_pCurrentApplication = this;

		m_configuration.SetCompanyName    (p_sCompanyName);
		m_configuration.SetProductLineName(p_sProductLineName);
		m_configuration.SetApplicationName(p_sApplicationName);
	}

	ConsoleApplication::~ConsoleApplication()
	{
		m_pCurrentApplication = 0;
	}


	void ConsoleApplication::i_specializeDataPath(::fs::Date p_date)
	{
		//
		// Look at two representations for the date
		//
		// YYYYMMDD and
		// YYYY/MM/DD
		//
		

		::std::string sDate = ::fs::format(p_date);

		::std::vector<::std::string> vsDate;

		::fs::si32 year;
		::fs::dword month;
		::fs::dword day;

		p_date.Crack(&year, &month, &day);

		vsDate.push_back(::fs::format(year));
		vsDate.push_back(::fs::fill(::fs::format(month), 2, '0', false));
		vsDate.push_back(::fs::fill(::fs::format(day),   2, '0', false));

		::ss::Path dataPath;
		for (size_t ix = 0; ix < Config().DataPath.size(); ++ix)
		{
			::ss::Filename fnMulti = Config().DataPath[ix];
			fnMulti.Append(vsDate);
			if (::ss::Exists(fnMulti) && ::ss::IsDirectory(fnMulti))
			{
				GetLog().Info("Adding Specialzation '", fnMulti, "' to DataPath.");
				dataPath.Append(fnMulti);
			}

			::ss::Filename fnOne = Config().DataPath[ix];
			fnOne.Append(sDate);
			if (::ss::Exists(fnOne) && ::ss::IsDirectory(fnOne))
			{
				GetLog().Info("Adding Specialzation '", fnOne, "' to DataPath.");
				dataPath.Append(fnOne);
			}
			dataPath.Append(Config().DataPath[ix]);
		}

		//
		// Not a true comparison, but this only
		// adds directories and preserves the existing.
		//

		if (Config().DataPath.size() != dataPath.size())
		{
			sDebug(GetLog().Info("Replacing '", Config().DataPath, "' with '", dataPath, "'."));
			Config().DataPath = dataPath;
		}
	}

	void ConsoleApplication::Specialize(::fs::Date p_date, ::ss::Filename *p_pfn)
	{
		::std::vector<::std::string> vsDate;

		::fs::si32 year;
		::fs::dword month;
		::fs::dword day;

		p_date.Crack(&year, &month, &day);

		vsDate.push_back(::fs::format(year));
		vsDate.push_back(::fs::fill(::fs::format(month), 2, '0', false));
		vsDate.push_back(::fs::fill(::fs::format(day), 2, '0', false));

		p_pfn->Append(vsDate);
	}





	int ConsoleApplication::Run(int argc, char *argv[])
	{
		::std::string stmp;
		char buf[1000];

		DWORD n = ::GetEnvironmentVariable("TMP", buf, sizeof(buf));
		sValidate(n > 0, ("Environment Variable 'TMP' not found."));
		stmp = buf;

		::fs::Replace('\\', '/', &stmp);

		sValidate(!stmp.empty(), ("'TMP' is empty."));
		if (stmp[stmp.size() - 1] != '/')
		{
			stmp += '/';
		}
		::ss::Filename fnTMP;
		::ss::Parse(stmp, &fnTMP);
		Config().SetTemporary(fnTMP);



		TCHAR path_buf[_MAX_PATH];
		DWORD dw = ::GetModuleFileName(0, path_buf, sArraySize(path_buf));
		sValidate(dw > 0, ("GetModuleFileName() failed, GetLastError() = ", ::GetLastError(), "."));
		::ss::Parse(path_buf, &m_fnExecutableDirectory);
		::ss::Filename fnEnv = m_fnExecutableDirectory;
		fnEnv.m_filename += ".environment";
		m_fnExecutableDirectory.m_filename.clear();

		//
		// We look for the .environment file next to the
		// executable for environment overrides.
		//
		if (::ss::Exists(fnEnv))
		{
			::ss::File f;
			::ss::File::Closer fc(f);
			::ss::FileStream fs(f);
			f.OpenReadOnly(fnEnv);
			::fs::NameValue nvEnv;
			::fs::NameValue::Reader r(nvEnv, fs, f.Size());

			r();

			::fs::NameValue::iterator it = nvEnv.begin();
			while (it != nvEnv.end())
			{
				BOOL r = ::SetEnvironmentVariable(it->first.c_str(), it->second.c_str());
				sValidate(r, ("Failed to SetEnvironmentVariable('", it->first, "', '", it->second, "'."));
				++it;
			}
		}

		::ss::Filename fn;
		
		::ss::CurrentWorkingDirectory(&fn);

		Config().SourcePath.Append(fn);

		n = ::GetEnvironmentVariable("USERPROFILE", buf, sizeof(buf));
		if (n > 0)
		{
			stmp = buf;

			::fs::Replace('\\', '/', &stmp);
			if (stmp[stmp.size() - 1] != '/')
			{
				stmp += '/';
			}

			::ss::Parse(stmp, &fn);

			Config().SourcePath.Append(fn);
		}
		Config().SetHomeDirectory(fn);


		::ss::CurrentWorkingDirectory(&fn);
		n = ::GetEnvironmentVariable("SEDOROOT", buf, sizeof(buf));
		if (n > 0)
		{
			sDebug(GetLog().Info("SEDOROOT=", fn));

			::ss::Parse(buf, &fn);

			Config().SourcePath.Append(fn);
		}
		Config().SetRootDirectory(fn);



		::std::vector<::std::string> vsDirectories;
		vsDirectories.push_back(Config().HomeDirectory());
		vsDirectories.push_back(Config().RootDirectory());
//		vsDirectories.push_back(Config().ApplicationDirectory());
//		vsDirectories.push_back(Config().ProductLineDirectory());
//		vsDirectories.push_back(Config().CompanyDirectory());

		::ss::Path pathConScript;

		for (size_t ixDir = 0; ixDir < vsDirectories.size(); ++ixDir)
		{
			::ss::Filename fn;
			::ss::Parse(vsDirectories[ixDir], &fn);

			if (::ss::Exists(fn) && ::ss::IsDirectory(fn))
			{
				pathConScript.Append(fn);
			}
		}


		::std::vector<std::string> vsConScript;

		vsConScript.push_back(::fs::format(Config().CompanyName(),     ".conscript"));
		vsConScript.push_back(::fs::format(Config().ProductLineName(), ".conscript"));
		vsConScript.push_back(::fs::format(Config().ApplicationName(), ".conscript"));

		for (size_t ixScript = 0; ixScript < vsConScript.size(); ++ixScript)
		{
			::ss::Filename fnScript;
			if (pathConScript.Find(vsConScript[ixScript], &fnScript))
			{
				GetLog().Info("Found '", fnScript, "'.");
				
			
				::tools::CommandInterpreter csp(*this);
				csp.Register("option", ::tools::CommandInterpreter::Command(this, &ConsoleApplication::i_cmdOption));
				csp.Register("path",   ::tools::CommandInterpreter::Command(this, &ConsoleApplication::i_cmdPath));

				csp.Process(fnScript);
			}
		}

//		char *tmp = strrchr(path_buf, '\\');
//		sValidate(0 != tmp, ("The path is not configured correctly."));
//		*tmp = 0;
//		tmp = strrchr(path_buf, '\\');
//		sValidate(0 != tmp, ("The path is not configured correctly."));
//		*(tmp + 1) = 0;


		::std::vector<std::string> args;

		for (int ix = 1; ix < argc; ++ix)
		{
			args.push_back(argv[ix]);
		}

		return Run(args);
	}
	

	int ConsoleApplication::Run(const std::vector<std::string>& p_commandLine)
	{
		int rc = 0;

		try
		{
			pStdoutLog = StdoutLog::Make();
//			pStdoutLog->TimeStampEntries() = true;
			pStdoutLog->TimeStampEntries() = false;

			GetLog().Add(pStdoutLog);


			sValidate(SetConsoleCtrlHandler(&ConsoleApplication::HandlerRoutine, TRUE), ("SetConsoleCtrlHandler() failed, GetLastError() == ", GetLastError(), "."));


//			GetLog().Info("Executable Directory: ", ss::ToString(m_fnExecutableDirectory));
			::std::vector<std::string> p_expandedCommandLine;

			m_configuration.PreProcessCommandLine(p_commandLine, &p_expandedCommandLine);

			//
			// Set up tmp dir
			//

			std::string stmp = Config().TemporaryDirectory();
			if (ss::FileExists(stmp.c_str()))
			{
				sValidate(ss::IsDirectory(stmp.c_str()), ("The temporary directory '", stmp, "' exists but is not a directory."));
			}
			else
			{
				//
				// create directory
				//

				sValidate(CreateDirectory(stmp.c_str(), 0), ("Failed to create directory '", stmp, "', GetLastError() == ", GetLastError(), "."));
			}

			m_configuration.ProcessCommandLine(p_expandedCommandLine);



			::fs::Date dt = ::fs::Local().DatePart();

			::std::string sDate;
			if (Config().Options.Find("Date", &sDate))
			{
				if (!::fs::Convert(sDate, &dt))
				{
					GetLog().Warning("'", sDate, "' not a valid date.");
				}
			}

			i_specializeDataPath(dt);

			GetLog().Start();

			int should_do_away_with_passing_args;
			rc = RunApplication(Config().Arguments);

//			sValidate(SetConsoleCtrlHandler(&ConsoleApplication::HandlerRoutine, FALSE), ("SetConsoleCtrlHandler() failed, GetLastError() == ", GetLastError(), "."));
		}
		catch (fs::Exception& x)
		{
			fprintf(stderr, "A fatal exception occured: %s", x.Message().c_str());
		}
		catch (::tools::CommandInterpreter::Quit &)
		{

		}

		return rc;
	}


	BOOL WINAPI ConsoleApplication::HandlerRoutine(DWORD dwCtrlType)
	{
		if (0 == ConsoleApplication::m_pCurrentApplication)
		{
			return FALSE;
		}
		ConsoleApplication *pApp = ConsoleApplication::m_pCurrentApplication;

		bool handled = false;
		switch (dwCtrlType)
		{
		case CTRL_C_EVENT:      // 0 	A CTRL+C signal was received, either from keyboard input or from a signal generated by the GenerateConsoleCtrlEvent function.
			handled = pApp->ControlC();
			break;

		case CTRL_BREAK_EVENT:  // 1 	A CTRL+BREAK signal was received, either from keyboard input or from a signal generated by GenerateConsoleCtrlEvent.
			handled = pApp->ControlBreak();
			break;

		case CTRL_CLOSE_EVENT:  // 2 	A signal that the system sends to all processes attached to a console when the user closes the console (either by clicking Close on the console window's window menu, or by clicking the End Task button command from Task Manager).
			handled = pApp->Close();
			break;

		case CTRL_LOGOFF_EVENT: // 5 	A signal that the system sends to all console processes when a user is logging off. This signal does not indicate which user is logging off, so no assumptions can be made.
			                //	Note that this signal is received only by services. Interactive applications are terminated at logoff, so they are not present when the system sends this signal.
			handled = pApp->Logoff();
			break;

		case CTRL_SHUTDOWN_EVENT:
			handled = pApp->Shutdown();
			break;
		}
		if (handled)
		{
			return TRUE;
		}

		return FALSE;
	}

	ConsoleApplication *ConsoleApplication::m_pCurrentApplication;

	bool ConsoleApplication::ControlC()
	{
		GetLog().Info("ControlC event not handled.");
		return false;
	}

	bool ConsoleApplication::ControlBreak()
	{
		GetLog().Info("ControlBreak event not handled.");
		return false;
	}

	bool ConsoleApplication::Close()
	{
		GetLog().Info("Close event not handled.");
		return false;
	}

	bool ConsoleApplication::Logoff()
	{
		GetLog().Info("Logoff event not handled.");
		return false;
	}

	bool ConsoleApplication::Shutdown()
	{
		GetLog().Info("Shutdown event not handled.");
		return false;
	}

	bool ConsoleApplication::LogToStdOut()
	{
		return true;
	}


	void ConsoleApplication::i_cmdOption(const std::vector<std::string>& p_vs)
	{
		if (p_vs.empty())
		{
			GetLog().Error("Expected at least one argument to option command.");
			return;
		}

		if (1 == p_vs.size())
		{
			Config().Options.SetOption(p_vs[0], "true");
		}

		if (2 == p_vs.size())
		{
			Config().Options.SetOption(p_vs[0], p_vs[1]);
		}

		if (p_vs.size() > 2)
		{
			GetLog().Error("Too many arguments for option command.");
		}
	}

	void ConsoleApplication::i_cmdPath(const std::vector<std::string>& p_vs)
	{
		if (p_vs.size() < 3)
		{
			GetLog().Error("path retures at least three arguments.");
			return;
		}
		const ::std::string& sCmd  = p_vs[0];
		const ::std::string& sPath = p_vs[1];
		
		if ("data" != sPath)
		{
			GetLog().Error("'", sPath, "' is not a valid path name.");
			return;
		}

		if ("append" != sCmd)
		{
			GetLog().Error("'", sPath, "' is not a valid sub command to path.");
			return;
		}
			
		
		for (size_t ix = 2; ix < p_vs.size(); ++ix)
		{
			::ss::Filename fn;
			::ss::Parse(p_vs[ix], &fn);

			if (::ss::Exists(fn) && ::ss::IsDirectory(fn))
			{
				Config().DataPath.Append(fn);
			}
			else
			{
				GetLog().Warning("'", fn, "' not a valid directory. Not appending to ", sPath, " path.");
			}
		}
	}

	void ConsoleApplication::Error(const std::string& p_sErrorText)
	{
		GetLog().Error(p_sErrorText);
	}

	bool ConsoleApplication::CanQuit()
	{
		return true;
	}
}

/* End Of File: ConsoleApplication.cpp */
