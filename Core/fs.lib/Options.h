namespace fs
{
	class Options
	{
	private:
		fs::NameValue m_defaults;
		fs::NameValue m_configuration;
		fs::NameValue m_options;

	public:
		const fs::NameValue& DefaultItems() const;
		const fs::NameValue& ConfigurationItems() const;
		const fs::NameValue& OptionItems() const;

	public:
		void Merge(const ::fs::Options& p_options);
	public:
		void SetDefault(const std::string& p_sName, const std::string& p_sValue);
		void SetOption(const std::string& p_sName, const std::string& p_sValue);
		void ReadConfiguration(fs::Stream& p_input, const fs::Stream::Offset p_inputSize);

		bool Find(const std::string& p_sName, std::string *p_sValue) const;

		void Require(const std::string& p_sName, std::string    *p_pValue) const;
		void Require(const std::string& p_sName, bool           *p_pValue) const;
		void Require(const std::string& p_sName, fs::byte       *p_pValue) const;
		void Require(const std::string& p_sName, fs::word       *p_pValue) const;
		void Require(const std::string& p_sName, fs::dword      *p_pValue) const;
		void Require(const std::string& p_sName, fs::qword      *p_pValue) const;
		void Require(const std::string& p_sName, fs::si8        *p_pValue) const;
		void Require(const std::string& p_sName, fs::si16       *p_pValue) const;
		void Require(const std::string& p_sName, fs::si32       *p_pValue) const;
		void Require(const std::string& p_sName, fs::si64       *p_pValue) const;
		void Require(const std::string& p_sName, fs::Double     *p_pValue) const;
		void Require(const std::string& p_sName, fs::Time       *p_pValue) const;
		void Require(const std::string& p_sName, fs::Time::Span *p_pValue) const;
		void Require(const std::string& p_sName, fs::Date       *p_pValue) const;
		void Require(const std::string& p_sName, fs::DateTime   *p_pValue) const;

		void Require(const std::string& p_sName, fs::DateTime::Span *p_pValue) const;
	};


	inline void Require(const std::string& p_sName, const ::fs::Options& p_options, std::string    *p_pValue)
	{
		p_options.Require(p_sName, p_pValue);
	}


	inline void Require(const std::string& p_sName, const ::fs::Options& p_options, bool           *p_pValue)
	{
		p_options.Require(p_sName, p_pValue);
	}

	inline void Require(const std::string& p_sName, const ::fs::Options& p_options, fs::byte       *p_pValue)
	{
		p_options.Require(p_sName, p_pValue);
	}

	inline void Require(const std::string& p_sName, const ::fs::Options& p_options, fs::word       *p_pValue)
	{
		p_options.Require(p_sName, p_pValue);
	}

	inline void Require(const std::string& p_sName, const ::fs::Options& p_options, fs::dword      *p_pValue)
	{
		p_options.Require(p_sName, p_pValue);
	}

	inline void Require(const std::string& p_sName, const ::fs::Options& p_options, fs::qword      *p_pValue)
	{
		p_options.Require(p_sName, p_pValue);
	}

	inline void Require(const std::string& p_sName, const ::fs::Options& p_options, fs::si8        *p_pValue)
	{
		p_options.Require(p_sName, p_pValue);
	}

	inline void Require(const std::string& p_sName, const ::fs::Options& p_options, fs::si16       *p_pValue)
	{
		p_options.Require(p_sName, p_pValue);
	}

	inline void Require(const std::string& p_sName, const ::fs::Options& p_options, fs::si32       *p_pValue)
	{
		p_options.Require(p_sName, p_pValue);
	}

	inline void Require(const std::string& p_sName, const ::fs::Options& p_options, fs::si64       *p_pValue)
	{
		p_options.Require(p_sName, p_pValue);
	}

	inline void Require(const std::string& p_sName, const ::fs::Options& p_options, fs::Double     *p_pValue)
	{
		p_options.Require(p_sName, p_pValue);
	}

	inline void Require(const std::string& p_sName, const ::fs::Options& p_options, fs::Time       *p_pValue)
	{
		p_options.Require(p_sName, p_pValue);
	}

	inline void Require(const std::string& p_sName, const ::fs::Options& p_options, fs::Time::Span *p_pValue)
	{
		p_options.Require(p_sName, p_pValue);
	}

	inline void Require(const std::string& p_sName, const ::fs::Options& p_options, fs::Date       *p_pValue)
	{
		p_options.Require(p_sName, p_pValue);
	}

	inline void Require(const std::string& p_sName, const ::fs::Options& p_options, fs::DateTime   *p_pValue)
	{
		p_options.Require(p_sName, p_pValue);
	}


	inline void Require(const std::string& p_sName, const ::fs::Options& p_options, fs::DateTime::Span *p_pValue)
	{
		p_options.Require(p_sName, p_pValue);
	}

}
