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
#include "UnitTest.h"

namespace fs
{

	const dword UnitTest::TestCount() const
	{
		return m_successCount + m_failureCount;
	}

	const dword UnitTest::SuccessCount() const
	{
		return m_successCount;
	}

	const dword UnitTest::FailureCount() const
	{
		return m_failureCount;
	}

	const std::string& UnitTest::TestName() const
	{
		return m_sName;
	}


	void UnitTest::SetTestName(const std::string& p_s)
	{
		m_sName = p_s;
	}

	UnitTest::UnitTest(Log& p_log)
	    : m_log(p_log),
	      m_successCount(0),
	    m_failureCount(0)
	{
	}

	void UnitTest::Check(bool p_condition, const std::string& p_text)
	{
		if (p_condition)
		{
			m_log.Info( "S! ", p_text);
			++m_successCount;
		}
		else
		{
			m_log.Error( "F! ", p_text);
			++m_failureCount;
		}
	}

	UnitTestManager::UnitTestManager(Log& p_log)
	    : m_log(p_log)
	{
	}

	UnitTestManager::~UnitTestManager()
	{
		for (size_t ix = 0; ix < m_tests.size(); ++ix)
		{
			UnitTest *p = m_tests[ix];

			delete p;
		}

		m_tests.clear();
	}

	void UnitTestManager::Add(UnitTest *p_pUnitTest)
	{
		m_tests.push_back(p_pUnitTest);
	}

	void UnitTestManager::RunTests()
	{
		for (size_t ix = 0; ix < m_tests.size(); ++ix)
		{
			UnitTest *p = m_tests[ix];

			p->Run();
		}
	}

	void UnitTestManager::ShowSummary()
	{
		fs::dword nTotalSuitesFailing = 0;

		for (size_t ix = 0; ix < m_tests.size(); ++ix)
		{
			UnitTest *p = m_tests[ix];

			m_log.Info(p->FailureCount(), " of ", p->TestCount(), " test cases failed for '", p->TestName(), "'.");
			if (p->FailureCount() > 0)
			{
				++nTotalSuitesFailing;
			}
		}
		
	}
} /* namespace fs */

/* UnitTest.cpp */
