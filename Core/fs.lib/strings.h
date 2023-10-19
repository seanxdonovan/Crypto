namespace fs
{

	class StringShort
	{
		byte m_size;
	public:
		byte Size() const
		{
			return m_size;
		}

		const char *c_str() const
		{
			return (const char *)(this + 1);
		}

		void Assign(const std::string& p_string);
	};
	template <> struct Type<fs::StringShort>
	{
		static const fs::type::ID ID = fs::type::id::StringShort;
	};

	std::string format(const fs::StringShort& p_s);

	class StringMedium
	{
		word m_size;
	public:
		word Size() const
		{
			return m_size;
		}


		const char *c_str() const
		{
			return (const char *)(this + 1);
		}

		void Assign(const std::string& p_string);
	};
	std::string format(const fs::StringMedium& p_s);
	template <> struct Type<fs::StringMedium>
	{
		static const fs::type::ID ID = fs::type::id::StringMedium;
	};


} /* namespace fs */

/* End Of File: strings.h */

