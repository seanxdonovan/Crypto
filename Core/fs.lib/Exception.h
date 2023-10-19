
namespace fs
{
	class Exception
	{
	public:
		Exception(const char *);
		Exception(const char *message,
			  const char *fileName,
			  si32 lineNumber,
			  const char *hostName,
			  const char *callStack);
		virtual ~Exception();

		const std::string& Message() const;
		const std::string& FileName() const;
		const std::string& HostName() const;
		const si32         LineNumber() const;
		const std::string& CallStack() const;
	private:
		std::string m_message;
		std::string m_fileName;
		si32        m_lineNumber;
		std::string m_hostName;
		std::string m_callStack;
	};
}

/* End Of File: Exception.cpp */
