namespace fs
{
	namespace base60
	{
		std::string Encode(fs::qword p_value);
		bool Decode(const std::string& p_s, fs::qword *p_pValue);
	}
}
