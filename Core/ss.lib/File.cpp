#include "precomp.h"
#include "Core/fs.lib/fs.lib.h"

#include "Filename.h"
#include "File.h"

namespace ss
{
	HANDLE File::CreateFileMapping(
				       __in_opt  LPSECURITY_ATTRIBUTES lpAttributes,
				       __in      DWORD flProtect,
				       __in      DWORD dwMaximumSizeHigh,
				       __in      DWORD dwMaximumSizeLow,
				       __in_opt  LPCTSTR lpName
				      )
	{
		return ::CreateFileMapping(m_hFile, lpAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName);
	}

	File::Parameters::Parameters()
			: m_desiredAccess(GENERIC_READ | GENERIC_WRITE)
			, m_shareMode(0)
			, m_useSecurityAttributes(FALSE)
			, m_creationDisposition(CREATE_ALWAYS)
			, m_flagsAndAttributes(FILE_ATTRIBUTE_NORMAL)
			, m_hTemplateFile(0)
	{
	}

	const DWORD File::Parameters::DesiredAccess() const
	{
		return m_desiredAccess;
	}

	const DWORD File::Parameters::ShareMode() const
	{
		return m_shareMode;
	}

	const bool File::Parameters::UseSecurityAttributes() const
	{
		return m_useSecurityAttributes;
	}

	SECURITY_ATTRIBUTES *File::Parameters::SecurityAttributes() const
	{
		sPrecondition(m_useSecurityAttributes);

		return const_cast<SECURITY_ATTRIBUTES *>(&m_securityAttributes);
	}

	const DWORD File::Parameters::CreationDisposition() const
	{
		return m_creationDisposition;
	}

	const DWORD File::Parameters::FlagsAndAttributes() const
	{
		return m_flagsAndAttributes;
	}

	HANDLE File::Parameters::hTemplate() const
	{
		return m_hTemplateFile;
	}


	void File::Parameters::DesiredAccess(DWORD p_access)
	{
		m_desiredAccess = p_access;
	}

	void File::Parameters::ShareMode(DWORD p_shareMode)
	{
		m_shareMode = p_shareMode;
	}

	void File::Parameters::CreationDisposition(DWORD p_creationDisposition)
	{
		m_creationDisposition = p_creationDisposition;
	}

	void File::Parameters::FlagsAndAttributes(DWORD p_flagsAndAttributes)
	{
		m_flagsAndAttributes = p_flagsAndAttributes;
	}

	File::File()
	    : m_hFile(INVALID_HANDLE_VALUE)
	{
	}

	File::~File()
	{
		sAssert(INVALID_HANDLE_VALUE == m_hFile); // did you forget to close your file?
	}

	File::RCP File::Make()
	{
		RCP p = RCP(new File());

		return p;
	}

	const bool File::IsOpen() const
	{
		return (INVALID_HANDLE_VALUE != m_hFile);
	}


	void File::Create(const Filename& p_filename, const Parameters& p_parameters)
	{
		sPrecondition(INVALID_HANDLE_VALUE == m_hFile);
		std::string s = ToString(p_filename);

		LPSECURITY_ATTRIBUTES pSecurityAttributes = 0;
		if (p_parameters.UseSecurityAttributes())
		{
			pSecurityAttributes = p_parameters.SecurityAttributes();
		}

		m_hFile = ::CreateFile(s.c_str(),
				       p_parameters.DesiredAccess(),
				       p_parameters.ShareMode(),
				       pSecurityAttributes,
				       p_parameters.CreationDisposition(),
				       p_parameters.FlagsAndAttributes(),
				       p_parameters.hTemplate());

		sValidate(INVALID_HANDLE_VALUE != m_hFile, ("CreateFile for '", s,"' failed; GetLastError() == ", GetLastError(), "."));
	}

	void File::Create(const std::string& p_filename)
	{
		Filename fn;
		Parse(p_filename, &fn);

		Parameters parameters;

		parameters.DesiredAccess(GENERIC_READ | GENERIC_WRITE);
		parameters.CreationDisposition(CREATE_NEW);
		parameters.FlagsAndAttributes(FILE_ATTRIBUTE_NORMAL);

		Create(fn, parameters);
	}

	void File::Create(const Filename& p_filename, fs::dword p_flags)
	{
		Parameters parameters;

		parameters.DesiredAccess(GENERIC_READ | GENERIC_WRITE);
		parameters.CreationDisposition(CREATE_NEW);
		parameters.FlagsAndAttributes(p_flags);

		Create(p_filename, parameters);
	}


	void File::CreateTemporary(const std::string& p_filename)
	{
		Filename fn;
		Parse(p_filename, &fn);

		Parameters parameters;

		parameters.DesiredAccess(GENERIC_READ | GENERIC_WRITE);
		parameters.CreationDisposition(CREATE_NEW);
		parameters.FlagsAndAttributes(FILE_ATTRIBUTE_TEMPORARY | FILE_FLAG_DELETE_ON_CLOSE);

		Create(fn, parameters);
	}

	void File::Open(const std::string& p_filename)
	{
		Filename fn;
		Parse(p_filename, &fn);

		Parameters parameters;

		parameters.DesiredAccess(GENERIC_READ | GENERIC_WRITE);
		parameters.CreationDisposition(OPEN_EXISTING);
		parameters.FlagsAndAttributes(FILE_ATTRIBUTE_NORMAL);

		Create(fn, parameters);
	}

	void File::Open(const Filename& p_filename, fs::dword p_flags)
	{
		Parameters parameters;

		parameters.DesiredAccess(GENERIC_READ | GENERIC_WRITE);
		parameters.CreationDisposition(OPEN_EXISTING);
		parameters.FlagsAndAttributes(p_flags);

		Create(p_filename, parameters);
	}

	void File::OpenReadOnly(const std::string& p_filename)
	{
		Filename fn;
		Parse(p_filename, &fn);

		Parameters parameters;

		parameters.DesiredAccess(GENERIC_READ);
		parameters.CreationDisposition(OPEN_EXISTING);
		parameters.FlagsAndAttributes(FILE_ATTRIBUTE_NORMAL);

		Create(fn, parameters);
	}

	void File::OpenReadOnly(const Filename& p_filename)
	{
		Parameters parameters;

		parameters.DesiredAccess(GENERIC_READ);
		parameters.CreationDisposition(OPEN_EXISTING);
		parameters.FlagsAndAttributes(FILE_ATTRIBUTE_NORMAL);

		Create(p_filename, parameters);
	}

	void File::Close()
	{
		if (INVALID_HANDLE_VALUE != m_hFile)
		{
			sValidate(CloseHandle(m_hFile), ("CloseHandle() failed GetLastError() == ", GetLastError(), "."));
			m_hFile = INVALID_HANDLE_VALUE;
		}
	}

	void File::SetEOF()
	{
		sPrecondition(INVALID_HANDLE_VALUE != m_hFile);

		sValidate(SetEndOfFile(m_hFile), ("SetEndOfFile failed, GetLastError() == ", GetLastError(), "."));
	}


	void File::Seek(fileoffset_t p_position)
	{
		sPrecondition(INVALID_HANDLE_VALUE != m_hFile);

		DWORD lowPosition = (DWORD)(p_position & 0xFFffFFff);
		LONG highPosition = (DWORD)((p_position >> 32) & 0xFFffFFff);
		DWORD ret = SetFilePointer(m_hFile, lowPosition, &highPosition, FILE_BEGIN);
		sValidate(ret != INVALID_SET_FILE_POINTER || (ret == INVALID_SET_FILE_POINTER && 0 == GetLastError()), ("SetFilePointer() to ", fs::hex(static_cast<fs::dword>(highPosition)), ":", fs::hex(lowPosition), " failed; GetLastError() == ", GetLastError(), "."));
	}

	void File::Tell(fileoffset_t *p_pPosition)
	{
		sPrecondition(INVALID_HANDLE_VALUE != m_hFile);

		DWORD lowPosition = 0;
		LONG highPosition = 0;
		
		lowPosition = SetFilePointer(m_hFile, 0, &highPosition, FILE_CURRENT);
		sValidate(lowPosition != INVALID_SET_FILE_POINTER || (lowPosition == INVALID_SET_FILE_POINTER && 0 == GetLastError()), ("SetFilePointer() to ", fs::hex(static_cast<fs::dword>(highPosition)), ":", fs::hex(lowPosition), " failed; GetLastError() == ", GetLastError(), "."));

		*p_pPosition = ((fileoffset_t) highPosition << 32 ) | lowPosition;
	}

	fs::Stream::Offset File::Tell()
	{
		fileoffset_t offset;
		Tell(&offset);
		return offset;
	}


	void File::Size(fileoffset_t *p_pSize)
	{
		sPrecondition(INVALID_HANDLE_VALUE != m_hFile);

		DWORD highSize = 0;
		DWORD lowSize = GetFileSize(m_hFile, &highSize);

		int ERROR_CHECK; // !!!!!!
		*p_pSize = fs::pack(highSize, lowSize);

	}
	fs::Stream::Offset File::Size()
	{
		sPrecondition(INVALID_HANDLE_VALUE != m_hFile);

		DWORD highSize = 0;
		DWORD lowSize = GetFileSize(m_hFile, &highSize);

		return fs::pack(highSize, lowSize);
	}


	void File::Write(const std::string& p_s)
	{
		fs::Buffer b((fs::byte *)p_s.c_str(), p_s.length());
		Write(b);
	}

	void File::Write(const fs::Buffer& p_buffer)
	{
		Write(p_buffer.Data(), p_buffer.Size());
	}

	void File::Read(fs::Buffer *p_pBuffer, fileoffset_t nBytesToRead)
	{
		sPrecondition(nBytesToRead <= p_pBuffer->Size());

		Read(p_pBuffer->Data(), nBytesToRead);
	}

	void File::Read(fs::PT<fs::Buffer>::T p_buffer, fs::Buffer *p_pRead)
	{
		sPrecondition(INVALID_HANDLE_VALUE != m_hFile);

		DWORD nBytesRead;
		sValidate(ReadFile(m_hFile, (fs::byte *)p_buffer.Data(), p_buffer.Size(), &nBytesRead, 0), ("ReadFile failed GetLastError() == ", GetLastError(), "."));
		*p_pRead = p_buffer.Reference(0, nBytesRead);
	}

	void File::Write(const void *p_pData, fileoffset_t p_size)
	{
		sPrecondition(INVALID_HANDLE_VALUE != m_hFile);

		DWORD nBytesWritten;
		sValidate(WriteFile(m_hFile, p_pData, p_size, &nBytesWritten, 0), ("WriteFile failed, GetLastError() == ", GetLastError(), "."));
		sValidate(nBytesWritten == p_size, ("WriteFile failed, tried to write ", p_size, " bytes ", nBytesWritten, " written; GetLastError() == ", GetLastError(), "."));
	}

	void File::Read(void *p_pData, fileoffset_t nBytesToRead)
	{
		sPrecondition(INVALID_HANDLE_VALUE != m_hFile);
		int nAttention; // do we have a case where nBytesToRead is greater than max_dword?
		sPrecondition(nBytesToRead < fs::Traits<fs::dword>::Maximum);

		DWORD nBytesRead;
		sValidate(ReadFile(m_hFile, p_pData, nBytesToRead, &nBytesRead, 0), ("ReadFile failed GetLastError() == ", GetLastError(), "."));
		sValidate(nBytesRead == nBytesToRead, ("ReadFile failed, tried to read ", nBytesToRead, " bytes but only ", nBytesRead, " were read."));
	}

	void File::Flush()
	{
		sPrecondition(INVALID_HANDLE_VALUE != m_hFile);
		sValidate(FlushFileBuffers(m_hFile), ("FlushFileBuffers failed, GetLastError() = ", GetLastError(), "."));
	}

	File::Closer::Closer(File& p_file)
	    : m_file(p_file)
	{
	}

	File::Closer::~Closer()
	{
		m_file.Close();
	}

	LPVOID WINAPI File::Mapping::MapViewOfFileEx(
		__in      DWORD dwDesiredAccess,
		__in      DWORD dwFileOffsetHigh,
		__in      DWORD dwFileOffsetLow,
		__in      SIZE_T dwNumberOfBytesToMap,
		__in_opt  LPVOID lpBaseAddress
		)
	{
		sPrecondition(0 != m_hMapping);

		return ::MapViewOfFileEx(m_hMapping, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap, lpBaseAddress);
	}

	File::Mapping::Mapping(File& p_f)
			: m_f(p_f)
			, m_hMapping(0)
	{
	}

	File::Mapping::~Mapping()
	{
		if (0 != m_hMapping)
		{
			Close();
		}
	}

	void File::Mapping::Create(fs::qword p_maximumSize)
	{
		sPrecondition(0 == m_hMapping);

		m_hMapping = m_f.CreateFileMapping(0, PAGE_READWRITE, fs::hiword(p_maximumSize), fs::loword(p_maximumSize), 0);
		sValidate(0 != m_hMapping, ("CreateFileMapping failed, ", GetLastError()));
		m_size = p_maximumSize;
	}

	void File::Mapping::Close()
	{
		if (0 != m_hMapping)
		{
			sValidate(CloseHandle(m_hMapping), ("CloseHandle failed, ", GetLastError()));
			m_hMapping = 0;
		}
	}

	fs::qword File::Mapping::Size() const
	{
		return m_size;
	}

	File::Mapping::View::View(Mapping& p_mapping)
			: m_mapping(p_mapping)
			, m_pMem(0)
	{
	}

	File::Mapping::View::~View()
	{
		if (0 != m_pMem)
		{
			Unmap();
		}
	}


	void File::Mapping::View::Unmap()
	{
		if (0 != m_pMem)
		{
			sValidate(UnmapViewOfFile(m_pMem), ("UnmapViewOfFile failed, ", GetLastError()));
			m_pMem = 0;
			m_buffer = fs::Buffer();
		}
	}

	void File::Mapping::View::Map(fs::qword p_start, fs::dword p_size, fs::dword p_access)
	{
		if (0 != m_pMem)
		{
			Unmap();
		}
		
		m_pMem = m_mapping.MapViewOfFileEx(p_access, fs::hiword(p_start), fs::loword(p_start), p_size, 0);
		sValidate(0 != m_pMem, ("MapViewOfFile failed, ", GetLastError()));
		m_buffer = fs::Buffer((fs::byte *)m_pMem, p_size);
	}

	fs::Buffer File::Mapping::View::Buffer() const
	{
		return m_buffer;
	}


	void File::Mapping::View::Flush()
	{
		auto rc = ::FlushViewOfFile(m_pMem, 0);

		sValidate(0 != rc, ("FlushViewOfFile() failed, ", GetLastError()));

	}
} /* namespace ss */

/* End Of File: File.cpp */
