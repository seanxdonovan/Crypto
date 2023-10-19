namespace tools
{
	class CommandInterpreter
	{
	public:
		typedef ::fs::Functor<void, TYPELIST_1(std::vector<std::string>)> Command;

		struct Quit {};

		class Interface
		{
		public:
			virtual void Error(const std::string& p_sErrorText) = 0;

			virtual bool CanQuit();
		};

	private:
		typedef std::map<std::string, Command> MAP;
		MAP m_commands;
		Interface& m_interface;
	protected:
		Interface & GetInterface();
	protected:
		void Error(const std::string& p_s);
	private:
		void i_parseLine(const std::string& p_sLine, std::string *p_psCommand, std::vector<std::string>* p_pvsParameters);

		void cmdListCommands(const std::vector<std::string>& p_vs);
		void cmdQuit(const std::vector<std::string>& p_vs);
		void cmdSource(const std::vector<std::string>& p_vs);
	public:
		CommandInterpreter(Interface& p_interface);
		void Register(const std::string p_sCommand, Command p_dispatch);

		void ProcessLine(const std::string& p_sLine);



		static const char DefaultLineTerminator[2];
		void Process(fs::Stream& p_stream, const char *p_lineTerminator  = DefaultLineTerminator);
		void Process(::ss::Filename& p_fn, const char *p_lineTerminator  = DefaultLineTerminator);
	};
}

