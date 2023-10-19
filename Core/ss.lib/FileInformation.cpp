#include "precomp.h"
#include "Core/fs.lib/fs.lib.h"

#include "FileInformation.h"

namespace ss
{
	FileInformation::FileInformation()
	{
	}

	FileInformation::FileInformation(const WIN32_FIND_DATA& p_ff)
	    : m_filename(p_ff.cFileName)
	    , m_attributes(p_ff.dwFileAttributes)
	    , ftCreationTime(p_ff.ftCreationTime)
	    , ftLastAccessTime(p_ff.ftLastAccessTime)
	    , ftLastWriteTime(p_ff.ftLastWriteTime)
	    , m_size(fs::pack(p_ff.nFileSizeHigh, p_ff.nFileSizeLow))
	{
	}

	FileInformation& FileInformation::operator =(const WIN32_FIND_DATA& p_ff)
	{
		m_filename       = p_ff.cFileName;
		m_attributes     = p_ff.dwFileAttributes;
		ftCreationTime   = p_ff.ftCreationTime;
		ftLastAccessTime = p_ff.ftLastAccessTime;
		ftLastWriteTime  = p_ff.ftLastWriteTime;
		m_size           = fs::pack(p_ff.nFileSizeHigh, p_ff.nFileSizeLow);

		return *this;
	}

	const std::string FileInformation::FileName() const
	{
		return m_filename;
	}

	fs::qword FileInformation::Size() const
	{
		return m_size;
	}

//	dwFileAttributes
//			The file attributes of a file.
//
//			This member can be one or more of the following values.
//			Attribute 	Meaning
//			FILE_ATTRIBUTE_ARCHIVE 	The file or directory is an archive file or directory.
//
//			Applications use this attribute to mark files for backup or removal.
//			FILE_ATTRIBUTE_COMPRESSED 	The file or directory is compressed.
//
//			For a file, this means that all of the data in the file is compressed.
//
//			For a directory, this means that compression is the default for newly created files and subdirectories.
//			FILE_ATTRIBUTE_DIRECTORY 	The handle identifies a directory.
//			FILE_ATTRIBUTE_ENCRYPTED 	The file or directory is encrypted.
//
//			For a file, this means that all data in the file is encrypted.
//
//			For a directory, this means that encryption is the default for newly created files and subdirectories.
//			FILE_ATTRIBUTE_HIDDEN 	The file or directory is hidden.
//
//			It is not included in an ordinary directory listing.
//			FILE_ATTRIBUTE_NORMAL 	The file or directory does not have other attributes set.
//
//			This attribute is valid only when used alone.
//			FILE_ATTRIBUTE_OFFLINE 	The file data is not available immediately.
//
//			This attribute indicates that the file data is physically moved to offline storage.
//
//			This attribute is used by Remote Storage, which is the hierarchical storage management software.
//
//			Note  Applications should not arbitrarily change this attribute.
//			FILE_ATTRIBUTE_READONLY 	The file or directory is read-only.
//
//			For a file, applications can read the file, but cannot write to it or delete it.
//
//			For a directory, applications cannot delete it.
//			FILE_ATTRIBUTE_REPARSE_POINT 	The file or directory has an associated reparse point.
//			FILE_ATTRIBUTE_SPARSE_FILE 	The file is a sparse file.
//			FILE_ATTRIBUTE_SYSTEM 	The file or directory is part of the operating system, or the operating system uses the file or directory exclusively.
//			FILE_ATTRIBUTE_TEMPORARY 	The file is being used for temporary storage.
//
//			File systems attempt to keep all of the data in memory for quick access, rather than flushing it back to mass storage.
//
//			An application should delete a temporary file as soon as it is not needed.
//

	bool FileInformation::IsDirectory() const
	{
		return (FILE_ATTRIBUTE_DIRECTORY == (FILE_ATTRIBUTE_DIRECTORY & m_attributes));
	}

	bool FileInformation::IsReadOnly() const
	{
		return (FILE_ATTRIBUTE_READONLY == (FILE_ATTRIBUTE_READONLY & m_attributes));
	}
}

/* End Of File: FileInformation.cpp */
