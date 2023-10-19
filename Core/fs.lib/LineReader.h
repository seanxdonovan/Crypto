
namespace fs
{
	//
	// Read lines from a stream. Handles all terminations cases
	// single 10, or
	// single 13, or
	// 13, 10
	//
	class LineReader
	{
	private:
		enum LineType {
			CR,
			LF,
			CRLF,
			Unknown
		} m_lineType;
		Stream& m_stream;
		bool m_storedExtra;
		fs::byte m_chExtra;
	public:
		LineReader(Stream& p_stream);
		void Next(std::string *p_ps);
	};
}

/* End of File: LineReader.h */
