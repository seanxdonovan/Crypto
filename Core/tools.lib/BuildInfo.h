namespace tools
{
	class BuildInfo
	{
		const fs::dword m_buildNumber;
		const char * const m_sDate;
		const char * const m_sTime;

		fs::DateTime m_stamp;
	public:
		BuildInfo(const char * const p_sDate, const char * const p_sTime, const fs::dword p_buildNumber);
		~BuildInfo();

		const fs::dword BuildNumber() const;
		const fs::DateTime BuildStamp() const;
	private:
		static BuildInfo *m_pInstance;
	public:
		static BuildInfo& Instance();
	};
}
