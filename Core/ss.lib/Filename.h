namespace ss
{
	struct Filename
	{
	public:
		::std::string m_driveletter;
		::std::vector<::std::string> m_directories;
		::std::string m_filename;

	public:
		void Append(const ::std::string& p_subdirectory);
		void Append(const ::std::vector<::std::string>& p_subdirectory);

		const ::std::string& DriveLetter() const;

		const bool Empty() const;
		void Clear();

		struct less
		{
			bool operator () (const Filename& p_lhs, const Filename& p_rhs) const;
		};

		typedef ::std::set<Filename, less> Set;

	public:
		bool IsAbsolute() const;
	};

	inline const ::std::string& Filename::DriveLetter() const
	{
		return m_driveletter;
	}

	::std::string ToString(const Filename& p_filename, const char p_delimiter = '/');
	void Parse(const ::std::string& p_fn, Filename *p_pFilename);

	bool Relative(const Filename& p_fna, const Filename& p_fnb, Filename *p_pfn);
	void FullRelative(const Filename& p_fnRoot, const Filename& p_fn, Filename *p_pfn);
}

namespace fs
{
	inline ::std::string format(const ::ss::Filename& p_fn)
	{
		return ::ss::ToString(p_fn);
	}
}

namespace fs
{
	void Require(const ::std::string& p_sName, const ::fs::Options& p_options, ::ss::Filename *p_pfn);
}
/* End Of File: Filename.h */
