namespace tools
{
	::std::string SystemDate();
	::std::string LocalDate();
	::std::string SystemDateTime();
	::std::string LocalDateTime();
	::std::string LocalTime();

	namespace base64
	{
		void Encode(const fs::Buffer& p_buffer, std::string *p_encoded);
		void Decode(const std::string& p_encodedText, fs::Buffer *p_pData);
	}

	void WriteCSVLine(FILE *p_foutLog, const std::vector<std::string>& values);
	void WriteCSVLine(fs::Stream&, const std::vector<std::string>& values);
}

/* End Of File: declarations.h */
