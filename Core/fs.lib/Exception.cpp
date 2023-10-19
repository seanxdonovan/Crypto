#include "precomp.h"
#include "declarations.h"
#include "exception.h"

namespace fs
{
	Exception::Exception(const char * message)
		: m_message(message)
	{
	}

	Exception::Exception(const char * message, const char * fileName, si32 lineNumber, const char *hostName, const char *callStack)
	    : m_message(message),
	      m_fileName(fileName),
	      m_lineNumber(lineNumber),
	      m_hostName(hostName),
	      m_callStack(callStack)
	{
	}

	Exception::~Exception()
	{
	}

	const std::string& Exception::Message() const
	{
		return m_message;
	}

	const std::string& Exception::FileName() const
	{
		return m_fileName;
	}

	const std::string& Exception::HostName() const
	{
		return m_hostName;
	}

	const si32 Exception::LineNumber() const
	{
		return m_lineNumber;
	}

	const std::string& Exception::CallStack() const
	{
		return m_callStack;
	}
}



/* End Of File: Exception.cpp */
