


namespace fs
{
	std::string toUpper(const std::string& p_s);
	std::string toLower(const std::string& p_s);

	inline std::string Join(const std::vector<std::string>& p_vs, const char p_ch)
	{
		return JoinStrings(p_vs, p_ch);
	}

	void Split(const std::string& p_toSplit, const char p_splitChar, std::vector<std::string> *m_pSplits);
	void Tokenize(const std::string& p_sInput, const std::string& p_sDelimiters, std::vector<std::string> *p_pvsTokens);

	std::string Trim(const std::string& p_s, const std::string& p_sTrimCharacters = " \n\t");
	std::string StripQuotes(const std::string& p_s);

	size_t StringCopy(wchar_t *p_sTo, const wchar_t *p_sFrom, size_t p_nMax);

	bool IsAlphaNum(const std::string& p_s);
}

/* End Of File: StringFunctions.h */
