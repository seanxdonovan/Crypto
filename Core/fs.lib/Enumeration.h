namespace fs
{
	class Enumeration
	{
	public:
		typedef ::fs::word IntegerType;
	private:
		typedef ::std::map<::std::string, IntegerType> MAP;
		MAP m_mapNameToValue;
		::std::vector<::std::string> m_vIndexToName;
	public:
		typedef MAP::iterator iterator;

		iterator begin();
		iterator end();
	public:
		void AddName(const ::std::string& p_sName, IntegerType p_value);

		bool IsName(const ::std::string& p_sName) const;
		bool IsValue(IntegerType p_value) const;

		bool Find(const ::std::string& p_sName, IntegerType *p_pv) const;
		bool Find(IntegerType p_v, ::std::string* p_psName) const;
	};
}
