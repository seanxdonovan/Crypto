namespace ss
{
	class FileIterator
	{
		HANDLE m_hFF;
		WIN32_FIND_DATA m_ff;
	public:
		FileIterator();
		~FileIterator();

		bool First(const Filename& p_directory, const std::string& p_pattern, FileInformation *p_pFirst);
		bool Next(FileInformation *p_pNext);
	};
}

/* End Of File: FileIterator.h */
