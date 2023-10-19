namespace tools
{
	class ConsoleApplication : public ::tools::CommandInterpreter::Interface
	{
	public:
		::fs::Log& GetLog();
	private:
		::fs::Log m_log;

	protected:
		StdoutLog::RCP pStdoutLog;
	private:
		ss::Filename m_fnExecutableDirectory;
	public:
		inline const ss::Filename& DirExecutable() const
		{
			return m_fnExecutableDirectory;
		}

	private:
		const std::string m_sApplicationName;
	public:
		inline const std::string& ApplicationName() const
		{
			return m_sApplicationName;
		}
	public:
		ConsoleApplication(const std::string& p_companyName,
				   const std::string& p_productLineName,
				   const std::string& p_applicationName);
		~ConsoleApplication();

	private:
		void i_specializeDataPath(::fs::Date p_date);

	protected:
		void Specialize(::fs::Date p_date, ::ss::Filename *p_pfn);
	public:
		int Run(int argc, char *argv[]);
		virtual int Run(const std::vector<std::string>& commandLine);
		virtual int RunApplication(const std::vector<std::string>& commandLine) = 0;

	private:
		Configuration m_configuration;

	public:
		Configuration& Config()

		{
			return m_configuration;
		}

	private:

		static BOOL WINAPI HandlerRoutine(DWORD dwCtrlType);
		static ConsoleApplication *m_pCurrentApplication;

		virtual bool ControlC();
		virtual bool ControlBreak();
		virtual bool Close();
		virtual bool Logoff();
		virtual bool Shutdown();

		virtual bool LogToStdOut();

		//
		// ConScript processing
		//
	public:

	private:
		/* virtual */ void Error(const std::string& p_sErrorText);
		/* virtual */ bool CanQuit();

	protected:
		void i_cmdOption(const std::vector<std::string>& p_vs);
		void i_cmdPath  (const std::vector<std::string>& p_vs);
	};
}

/* End Of File: ConsoleApplication.h */
