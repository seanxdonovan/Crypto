namespace fs
{
	class NameValue
	{
		typedef std::map<std::string, std::string> MAP;

		MAP m_map;
	public:
		bool Find(const std::string& p_name, std::string *p_pValue) const;
		void Set(const std::string&  p_name, const std::string& p_value);
		void Clear(const std::string& p_name);
		bool Exists(const std::string& p_name) const;

		typedef MAP::iterator iterator;
		typedef MAP::const_iterator const_iterator;

		inline iterator begin()
		{
			return m_map.begin();
		}

		inline const_iterator begin() const
		{
			return m_map.begin();
		}

		inline iterator end()
		{
			return m_map.end();
		}

		inline const_iterator end() const
		{
			return m_map.end();
		}

		class Reader
		{
			NameValue& m_nameValue;
			Stream& m_stream;
			Stream::Offset m_length;

		public:
			Reader(NameValue& p_nameValue, Stream& p_stream, Stream::Offset p_length);

			void operator () ();
		};

		class Writer
		{
			const NameValue& m_nameValue;
			Stream& m_stream;
		public:
			Writer(const NameValue& p_nameValue, Stream& p_stream);

			void operator () ();
		};

	};

	void Keys(const NameValue& p_nv, std::set<std::string> *p_psetKeys);
}
