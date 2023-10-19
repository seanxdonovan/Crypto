namespace ss
{
	class File
	{
	public:
		HANDLE CreateFileMapping(
					 __in_opt  LPSECURITY_ATTRIBUTES lpAttributes,
					 __in      DWORD flProtect,
					 __in      DWORD dwMaximumSizeHigh,
					 __in      DWORD dwMaximumSizeLow,
					 __in_opt  LPCTSTR lpName
					);
	public:
		class Parameters
		{
			DWORD m_desiredAccess;
			DWORD m_shareMode;
			bool m_useSecurityAttributes;
			SECURITY_ATTRIBUTES m_securityAttributes;
			DWORD m_creationDisposition;
			DWORD m_flagsAndAttributes;
			HANDLE m_hTemplateFile;
		public:
			Parameters();

			const DWORD DesiredAccess() const;
			const DWORD ShareMode() const;
			const bool UseSecurityAttributes() const;
			SECURITY_ATTRIBUTES *SecurityAttributes() const;
			const DWORD CreationDisposition() const;
			const DWORD FlagsAndAttributes() const;
			HANDLE hTemplate() const;

			void DesiredAccess(DWORD p_access);
			void ShareMode(DWORD p_shareMode);
			void CreationDisposition(DWORD p_creationDisposition);
			void FlagsAndAttributes(DWORD p_flagsAndAttributes);
		};

	protected:
		HANDLE m_hFile;
	public:
		typedef __int64 fileoffset_t;
		typedef __int64 Offset;

	public:
		typedef fs::ReferenceCountedPointer<File> RCP;
	public:
		File();
	public:
		static RCP Make();
	public:
		virtual ~File();

		const bool IsOpen() const;

		virtual void Create(const Filename& p_filename, const Parameters& p_parameters);

		void Create(const std::string& p_filename);
		void Create(const Filename& p_filename, fs::dword p_flags = FILE_ATTRIBUTE_NORMAL);
		void CreateTemporary(const std::string& p_filename);
		void Open(const std::string& p_filename);
		void Open(const Filename& p_filename, fs::dword p_flags = FILE_ATTRIBUTE_NORMAL);
		void OpenReadOnly(const std::string& p_filename);
		void OpenReadOnly(const Filename& p_filename);
		void Close();

		void SetEOF();
		void Seek(fileoffset_t p_position);
		void Tell(fileoffset_t *p_pPosition);
		virtual ::fs::Stream::Offset Tell();
		void Size(fileoffset_t *p_pSize);
		::fs::Stream::Offset Size();


		virtual void Write(fs::PT<fs::Buffer>::T p_buffer);
		virtual void Read (fs::PT<fs::Buffer>::T p_buffer, fs::Buffer *p_pRead);

		void Write(const std::string& p_s);
		void Read(fs::Buffer *p_pBuffer, fileoffset_t nBytesToRead);

		void Write(const void *p_pData, fileoffset_t p_size);
		void Read(void *p_pData, fileoffset_t p_size);

		void Flush();

		class Closer
		{
			File& m_file;
		public:
			Closer(File& p_file);
			~Closer();
		};


		class Mapping
		{
		public:
			LPVOID WINAPI MapViewOfFileEx(
				__in      DWORD dwDesiredAccess,
				__in      DWORD dwFileOffsetHigh,
				__in      DWORD dwFileOffsetLow,
				__in      SIZE_T dwNumberOfBytesToMap,
				__in_opt  LPVOID lpBaseAddress
				);
		private:
			File& m_f;
			HANDLE m_hMapping;
			
			fs::qword m_size;
		public:
			Mapping(File& p_f);
			~Mapping();

			void Create(fs::qword p_maximumSize);
			void Close();

			fs::qword Size() const;

			class View
			{
				Mapping& m_mapping;
				LPVOID m_pMem;
				fs::Buffer m_buffer;
			public:
				View(Mapping& p_mapping);

				void Unmap();
				void Map(fs::qword p_start, fs::dword p_size, fs::dword p_access = FILE_MAP_READ);
//#define FILE_MAP_COPY       SECTION_QUERY
//#define FILE_MAP_WRITE      SECTION_MAP_WRITE
//#define FILE_MAP_READ       SECTION_MAP_READ
//#define FILE_MAP_ALL_ACCESS SECTION_ALL_ACCESS
//#define FILE_MAP_EXECUTE    SECTION_MAP_EXECUTE_EXPLICIT    // not included in FILE_MAP_ALL_ACCESS

				~View();

				fs::Buffer Buffer() const;

				void Flush();
			};
		};
	};

} /* namespace ss */

/* End Of File: File.h */
