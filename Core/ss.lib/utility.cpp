#include "precomp.h"
#include "Core/fs.lib/fs.lib.h"

#include "Filename.h"
#include "utility.h"

#include "FileInformation.h"
#include "FileIterator.h"

#include "File.h"
#include "FileStream.h"

namespace ss
{
	bool Exists(const Filename& p_fn)
	{
		std::string s = ToString(p_fn);

		return FileExists(s.c_str());
	}

	bool FileExists(const TCHAR *p_filename)
	{
		const auto rc = GetFileAttributes(p_filename);

		return (INVALID_FILE_ATTRIBUTES != rc);
	}

	bool IsDirectory(const TCHAR *p_filename)
	{
		fs::dword attributes = GetFileAttributes(p_filename);

		return (INVALID_FILE_ATTRIBUTES != attributes && (FILE_ATTRIBUTE_DIRECTORY == (FILE_ATTRIBUTE_DIRECTORY & attributes)));
	}

	bool IsDirectory(const Filename& p_filename)
	{
		std::string s = ToString(p_filename);

		return IsDirectory(s.c_str());
	}

	void MakeDirectory(const TCHAR *p_filename)
	{
		sValidate(CreateDirectory(p_filename, 0), ("CreateDirectory '", p_filename, "' failed, GetLastError() == ", GetLastError()));
	}

	void Delete(const TCHAR *p_filename)
	{
		sValidate(DeleteFile(p_filename), ("Failed to delete '", p_filename, "', GetLastError() == ", GetLastError(), "."));
	}

	void MakeDirectory(const Filename& p_fn)
	{
		sPrecondition(p_fn.m_filename.empty());

		std::string s;
		if (!p_fn.m_driveletter.empty())
		{
			s = p_fn.m_driveletter;
			s += ':';
		}

		for (size_t ix = 1; ix < p_fn.m_directories.size(); ++ix)
		{
			s += '/';
			s += p_fn.m_directories[ix];
			if (!FileExists(s.c_str()))
			{
				MakeDirectory(s.c_str());
			}
			else
			{
				sValidate(IsDirectory(s.c_str()), ("'", s, "' exists and is not a directory."));
			}
		}
	}

	void Delete(const Filename& p_fn)
	{
		std::string s = ToString(p_fn);

		if (p_fn.m_filename.empty())
		{
			//
			// it's a directory!
			//
			sValidate(RemoveDirectory(s.c_str()), ("RemoveDirectory(\"", s, "\") failed, GetLastError() == ", GetLastError(), "."));
		}
		else
		{
			//
			// it is a regular file
			//

			sValidate(DeleteFile(s.c_str()), ("DeleteFile(\"", s, "\") failed, GetLastError() == ", GetLastError(), "."));
		}
	}

	void Create(const Filename& p_fn)
	{
		std::string s = ToString(p_fn);

		if (p_fn.m_filename.empty())
		{
			//
			// it's a directory!
			//
			sValidate(CreateDirectory(s.c_str(), 0), ("CreateDirectory(\"", s, "\") failed, GetLastError() == ", GetLastError(), "."));
		}
		else
		{
			sRaiseError(("Use storage::File::Create() to create a file for \"", s, "\"."));
		}
	}

	void Move(const Filename& p_fnFrom, const Filename& p_fnTo)
	{
		std::string sFrom = ToString(p_fnFrom);
		std::string sTo = ToString(p_fnTo);

		sValidate(MoveFile(sFrom.c_str(), sTo.c_str()), ("MoveFile('", sFrom, "', '", sTo, "') failed. GetLastError() == ", GetLastError(), "."));
	}

	void CurrentWorkingDirectory(Filename *p_pCurrentWorkingDirectory)
	{
		fs::dword result = GetCurrentDirectory(0, 0);
		std::string s;

#if 0
		s.reserve(result);
		result = GetCurrentDirectory(result, (LPSTR)s.c_str());
#else
		fs::HeapBuffer buf(result);
		result = GetCurrentDirectory(result, (LPSTR)buf.Data());
		s = std::string((char *)buf.Data(), buf.Size() - 1);
		if ((!s.empty() && '\\' != *s.rbegin()) || s.empty())
		{
			s += "\\";
		}

#endif
		sValidate(0 != result, ("GetCurrentDirectory failed, GetLastError() == ", GetLastError()));

		Parse(s, p_pCurrentWorkingDirectory);
	}

	void ParsePath(const std::string p_path, std::vector<Filename> *p_pPaths, const char p_delimiter)
	{
		std::vector<std::string> parts;
		fs::Split(p_path, p_delimiter, &parts);

		for (size_t ix = 0; ix < parts.size(); ++ix)
		{
			const std::string& s = parts[ix];
			Filename fn;

			Parse(s, &fn);
			// if the path entry does not end with a '/' or
			// a '\', the parse code assumes that the last
			// bit is the filename. -- as designed.
			// So, we correct for it here as the path is
			// often user input.

			if (!fn.m_filename.empty())
			{
				fn.m_directories.push_back(fn.m_filename);
				fn.m_filename.clear();
			}

			p_pPaths->push_back(fn);
		}
	}

	bool FindInPath(const std::string& p_filename, const std::vector<Filename>& p_path, Filename *p_pResolvedFilename)
	{
		for (size_t ix = 0; ix < p_path.size(); ++ix)
		{
			FileInformation fi;
			FileIterator fit;
			if (fit.First(p_path[ix], p_filename, &fi))
			{
				*p_pResolvedFilename = p_path[ix];
				sAssert(p_pResolvedFilename->m_filename.empty());
				p_pResolvedFilename->m_filename = fi.FileName();

				return true;
			}
		}

		return false;
	}

	std::string i_formatForFilename(fs::Date p_date)
	{
		std::string s;
		fs::si32 year;
		fs::dword month;
		fs::dword day;
		p_date.Crack(&year, &month, &day);
		sAssert(year >= 0);
		s  = fs::fill(fs::format(year), 4, '0', false);
		s += fs::fill(fs::format(month), 2, '0', false);
		s += fs::fill(fs::format(day), 2, '0', false);
		

		return s;
	}

	std::string i_formatForFilename(fs::DateTime p_datetime)
	{
		std::string s;
		fs::si32 year;
		fs::dword month;
		fs::dword day;
		fs::dword hours;
		fs::dword minutes;
		fs::dword seconds;
		fs::dword ms;
		p_datetime.Crack(&year, &month, &day, &hours, &minutes, &seconds, &ms);
		sAssert(year >= 0);
		s  = fs::fill(fs::format(year), 4, '0', false);
		s += fs::fill(fs::format(month), 2, '0', false);
		s += fs::fill(fs::format(day), 2, '0', false);
		s += '_';
		s += fs::fill(fs::format(hours), 2, '0', false);
		s += fs::fill(fs::format(minutes), 2, '0', false);
		s += fs::fill(fs::format(seconds), 2, '0', false);

		return s;
	}

	std::string FormatForFilename(fs::DateTime p_datetime)
	{
		return i_formatForFilename(p_datetime);
	}

	void GenerateLogFilename(const Filename& p_inDirectory, const std::string& p_sBaseName, const std::string& p_sExtension, Filename *p_pLogFilename)
	{
		sPrecondition(p_inDirectory.m_filename.empty());
		sValidate(IsDirectory(p_inDirectory), ("'", ToString(p_inDirectory), "' is not a directory."));

		*p_pLogFilename = p_inDirectory;

		std::string sFilename = p_sBaseName
					+ "_"
					+ i_formatForFilename(fs::Now().DatePart())
					+ "."
					+ p_sExtension;

		p_pLogFilename->m_filename = sFilename;
		if (!Exists(*p_pLogFilename))
		{
			return;
		}

		sFilename =  p_sBaseName
			     + "_"
			     + i_formatForFilename(fs::Now())
					+ "."
			     + p_sExtension;


		p_pLogFilename->m_filename = sFilename;
		sValidate(!Exists(*p_pLogFilename) , ("'", ToString(*p_pLogFilename), "' exists!"));
	}


	std::string format(fs::Date p_date)
	{
		fs::si32 year;
		fs::dword month;
		fs::dword day;
		p_date.Crack(&year, &month, &day);

		return fs::fill(fs::format(year), 4, '0', false) + fs::fill(fs::format(month), 2, '0', false) + fs::fill(fs::format(day), 2, '0', false);
	}

	std::string format(fs::DateTime p_datetime)
	{
		return i_formatForFilename(p_datetime);
	}

	std::string format(fs::Time p_time)
	{
		fs::dword hours;
		fs::dword minutes;
		fs::dword seconds;
		fs::dword ms;

		p_time.Crack(&hours, &minutes, &seconds, &ms);
		::std::string s;
		s += fs::fill(fs::format(hours), 2, '0', false);
		s += fs::fill(fs::format(minutes), 2, '0', false);
		s += fs::fill(fs::format(seconds), 2, '0', false);

		return s;
	}

	void ReadText(::fs::PT<Filename>::T p_fn, ::std::vector<::std::string> *p_pv)
	{
		::ss::File f;
		::ss::File::Closer fc(f);

		::ss::FileStream stream(f);

		f.OpenReadOnly(p_fn);

		::fs::FixedBuffer<4096> buf;
		::fs::BufferedReader br(stream, f.Size(), buf);

		while (!br.End())
		{
			::std::string s;
			::fs::ReadLn(br, &s);

			p_pv->push_back(s);
		}
	}
}

/* End Of File: utility.cpp */

