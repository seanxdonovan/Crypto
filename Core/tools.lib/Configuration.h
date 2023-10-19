namespace tools
{
	class Configuration
	{
	private:
		::std::deque<::std::string> m_vsConfigurationFiles;
	public:
		void AddConfigurationFile(const std::string& p_sConfigurationFile);
		void PrependConfigurationFile(const std::string& p_sConfigurationFile);
		void LoadConfigurationFiles(::fs::Log& p_log);
	public:
		::fs::Options Options;
	public:
		::ss::Filename fnExecutable;

		::ss::Filename fnTemporaryDirectory;
		::ss::Path     ConfigurationPath;
		::ss::Filename LogDirectory;
		::ss::Filename DataDirectory;
		::ss::Path     DataPath;
		::ss::Filename fnNVmemDirectory;

		::ss::Path     ExecutablePath;

		::ss::Path     SourcePath;

		::std::vector<::std::string> Arguments;

		void Dump(::fs::Log& p_log);
	public:
		void PreProcessCommandLine(const std::vector<std::string>& p_commandLine, std::vector<std::string> *p_pCommandLine);
		void ReadArgumentsFrom(const std::string& filename, std::vector<std::string> *p_pCommandLine);

		void ProcessCommandLine(const std::vector<std::string>& p_vs);

		typedef ::fs::Functor<void, TYPELIST_1(::std::string) > OptionFunctor;
		typedef ::fs::Notifier<OptionFunctor> OptionNotifier;
	private:
		typedef ::std::map<::std::string, OptionNotifier> NotifierMap;

		NotifierMap m_mapNotifiers;

	public:
		void Hook(const std::string& p_sOption, fs::PT<OptionFunctor>::T p_fHook);
		
	public:
		std::string TemporaryDirectory();
		std::string GenerateTemporaryFileName();

		void SetTemporary(const ss::Filename& p_fn);

	private:
		::std::string m_sCompanyName;
		::std::string m_sProductLineName;
		::std::string m_sApplicationName;

	public:
		::std::string CompanyName() const;
		::std::string ProductLineName() const;
		::std::string ApplicationName() const;


		void SetCompanyName    (const ::std::string& p_s);
		void SetProductLineName(const ::std::string& p_s);
		void SetApplicationName(const ::std::string& p_s);

	public:
		::std::string CompanyDirectory() const;
		::std::string ProductLineDirectory() const;
		::std::string ApplicationDirectory() const;

		::std::string HomeDirectory() const;
		::std::string RootDirectory() const;


	private:
		::ss::Filename m_fnRoot;
		::ss::Filename m_fnHome;
	public:
		void GetRootDirectory(::ss::Filename *p_pfn);
		void GetHomeDirectory(::ss::Filename *p_pfn);

		void SetRootDirectory(const ::ss::Filename& p_fn);
		void SetHomeDirectory(const ::ss::Filename& p_fn);

	public:
		void LoadExecutablePath();
	};
}


namespace tools
{
	void ConfigureForDay(const ::std::string& p_sName, ::fs::Date p_date, ::tools::Configuration *p_pConfiguration);
}

namespace tools
{
	bool GetPath(const std::string& p_sName, ::ss::Path *p_pPath);
}
