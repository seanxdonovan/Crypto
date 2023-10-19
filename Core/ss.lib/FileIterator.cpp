#include "precomp.h"
#include "Core/fs.lib/fs.lib.h"

#include "Filename.h"
#include "FileInformation.h"
#include "FileIterator.h"

namespace ss
{
	
	FileIterator::FileIterator()
	    : m_hFF(INVALID_HANDLE_VALUE)
	{
	}

	FileIterator::~FileIterator()
	{
		if (INVALID_HANDLE_VALUE != m_hFF)
		{
			sValidate(FindClose(m_hFF), ("Failed to close file find handle, GetLastError() == ", GetLastError(), "."));
		}
	}

	bool FileIterator::First(const Filename& p_directory, const std::string& p_pattern, FileInformation *p_pFirst)
	{
		ZeroMemory(&m_ff, sizeof(m_ff));
		std::string s = ToString(p_directory);
		s += p_pattern;

		OutputDebugString(s.c_str());
		OutputDebugString("\n");
		m_hFF = FindFirstFile(s.c_str(), &m_ff);
		
		if (INVALID_HANDLE_VALUE != m_hFF)
		{
			*p_pFirst = m_ff;
			return true;
		}

		return false;
	}

	bool FileIterator::Next(FileInformation *p_pNext)
	{
		sPrecondition(INVALID_HANDLE_VALUE != m_hFF); // this function should not be called unless First was successful.

		if (FindNextFile(m_hFF, &m_ff))
		{
			*p_pNext = m_ff;
			return true;
		}

		return false;
	}
} /* namespace storage */

/* End Of File: FileIterator.cpp */
