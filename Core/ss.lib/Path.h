namespace ss
{
	class Path
	{
		std::vector <Filename> m_vDirectories;
	public:
		void Find(const std::string& p_sPattern, Filename::Set *p_pSet) const;
		bool Find(const std::string& p_sFilename, std::string *p_psFullPath);
		bool Find(const std::string& p_sFilename, Filename *p_pfnFullPath) const;
		void Parse(const std::string& p_sPath, const char p_delimiter = ';');

		std::string ToString(const char p_delimiter = ';') const;

		void Append(const Filename& p_fnDir);
		void Prepend(const Filename& p_fnDir);

		void Clear();

		inline size_t size() const
		{
			return m_vDirectories.size();
		}

		inline const Filename& operator[](size_t p_ix) const
		{
			sPrecondition(p_ix < size());
			return m_vDirectories[p_ix];
		}
	};
}

namespace fs
{
	std::string format(const ss::Path& p_path);
}