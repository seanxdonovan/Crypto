namespace ss
{
	class FileInformation
	{
	private:
		std::string m_filename;
		fs::dword m_attributes;
		FILETIME ftCreationTime;
		FILETIME ftLastAccessTime;
		FILETIME ftLastWriteTime;
		fs::qword m_size;
	public:
		FileInformation();
		FileInformation(const WIN32_FIND_DATA& p_ff);
		FileInformation& operator =(const WIN32_FIND_DATA& p_ff);

		const std::string FileName() const;
		fs::qword Size() const;

		bool IsDirectory() const;
		bool IsReadOnly() const;
	};
}

/* End Of File: FileInformation.h */
