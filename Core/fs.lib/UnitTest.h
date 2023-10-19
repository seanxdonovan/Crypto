namespace fs
{

	class UnitTest
	{
	protected:
		Log& m_log;
	private:
		dword m_successCount;
		dword m_failureCount;
		std::string m_sName;
	public:
		const dword TestCount() const;
		const dword SuccessCount() const;
		const dword FailureCount() const;

		const std::string& TestName() const;

		void SetTestName(const std::string& p_s);
	public:
		UnitTest(Log& p_log);
		void Check(bool p_condition, const std::string& p_text = "");

#define UT_Check(condition) Check((condition), #condition)


		virtual void Run() = 0;
	};

	class UnitTestManager
	{
		std::vector<UnitTest *> m_tests;
		Log& m_log;

	public:
		UnitTestManager(Log& p_log);
		~UnitTestManager();

		void Add(UnitTest *p_pUnitTest);

		void RunTests();
		void ShowSummary();
	};

} /* namespace fs */

/* End Of File: UnitTest.h */
