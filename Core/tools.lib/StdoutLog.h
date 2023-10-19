
namespace tools
{
	class StdoutLog : public fs::Log::Adaptor
	{
	private:
		StdoutLog();
	public:
		typedef fs::ReferenceCountedPointerDerived<StdoutLog, fs::Log::Adaptor::RCP> RCP;
		static RCP Make();
	public:
		void Info(const char *str);
		void Warning(const char *str);
		void Error(const char *str);


	private:
		bool m_timestampEntries;

	public:
		inline bool& TimeStampEntries()
		{
			return m_timestampEntries;
		}
		inline const bool TimeStampEntries() const
		{
			return m_timestampEntries;
		}

	private:
		bool m_enable;
	public:
		bool& Enable();
		const bool Enable() const;
	};
}

/* End Of FIle StdoutLog.h */
