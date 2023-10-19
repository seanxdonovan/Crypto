namespace tools
{
	class LogToDebugger : public fs::Log::Adaptor
	{
	public:
		void Info(const char *p_s);
		void Warning(const char *p_s);
		void Error(const char *p_s);

	private:
		void out(const char *p_sPrefix, const char *p_sMessage);

	public:
		typedef fs::ReferenceCountedPointerDerived<LogToDebugger, fs::Log::Adaptor::RCP> RCP;
	private:
		LogToDebugger();
	public:
		static RCP Make();
	};
}

