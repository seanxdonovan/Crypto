namespace ss
{
	class MapFile
	{
	public:
		~MapFile();
		MapFile(::fs::dword p_access = FILE_MAP_READ);

	private:
		const ::fs::dword m_access;
		void i_makeMapping();
	public:
		void Open(const  Filename& p_fn);
		void Create(const  Filename& p_fn, ::fs::Buffer::Offset p_size, bool p_deleteOnClose = false);

	private:
		File m_f;

		File::Mapping m_mapping;

		File::Mapping::View m_view;

	private:
		::fs::Buffer m_viewBuffer;
	public:
		::fs::Buffer View();

	public:
		void Resize(::fs::Buffer::Offset p_expandedSize);
	};
}
