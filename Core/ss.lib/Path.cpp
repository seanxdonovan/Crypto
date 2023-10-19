#include "precomp.h"
#include "Core/fs.lib/fs.lib.h"

#include "Filename.h"
#include "utility.h"
#include "Path.h"

#include "FileInformation.h"
#include "FileIterator.h"

namespace ss
{
	void Path::Find(const std::string& p_sPattern, Filename::Set *p_pSet) const
	{
		FileInformation fi;
		for (size_t ix = 0; ix < m_vDirectories.size(); ++ix)
		{
			Filename fnDirectory = m_vDirectories[ix];
			sAssert(fnDirectory.m_filename.empty());

			FileIterator fit;
			if (fit.First(fnDirectory, p_sPattern, &fi))
			{
				do
				{
					Filename fnFound = fnDirectory;
					fnFound.m_filename = fi.FileName();
					p_pSet->insert(fnFound);
				}
				while (fit.Next(&fi));
			}
		}
	}


	bool Path::Find(const std::string& p_sFilename, Filename *p_pfnFullPath) const
	{
		Filename fnTarget;
		::ss::Parse(p_sFilename, &fnTarget);

		if (fnTarget.IsAbsolute())
		{
			return Exists(fnTarget);
		}


		for (size_t ix = 0; ix < m_vDirectories.size(); ++ix)
		{
			Filename fn = m_vDirectories[ix];
			sAssert(fn.m_filename.empty());

			for (size_t jx = 0; jx < fnTarget.m_directories.size(); ++jx)
			{
				fn.Append(fnTarget.m_directories[jx]);
			}
			fn.m_filename = fnTarget.m_filename;

			if (Exists(fn))
			{
				*p_pfnFullPath = fn;
				return true;
			}
		}

		return false;
	}

	bool Path::Find(const std::string& p_sFilename, std::string *p_psFullPath)
	{
		ss::Filename fn;
		if (Find(p_sFilename, &fn))
		{
			*p_psFullPath = ss::ToString(fn);
			return true;
		}
		return false;
	}

	void Path::Parse(const std::string& p_sPath, const char p_delimiter)
	{
		std::vector<std::string> vsDirectories;

		fs::Split(p_sPath, p_delimiter, &vsDirectories);

		for (size_t ix = 0; ix < vsDirectories.size(); ++ix)
		{
			std::string sDir = vsDirectories[ix];

			if (IsDirectory(sDir.c_str()))
			{
				Filename fn;
				ss::Parse(sDir, &fn);

				if (!fn.m_filename.empty())
				{
					fn.m_directories.push_back(fn.m_filename);
					fn.m_filename.clear();
				}

//			fs::Log::Instance().Info("[", ix, "] - '", ss::ToString(fn), "' - '", fn.m_filename, "'");
				m_vDirectories.push_back(fn);
			}
			else
			{
				// skipped ...
				int;
			}
		}
	}


	std::string Path::ToString(const char p_delimiter) const
	{
		std::string s;
		if (!m_vDirectories.empty())
		{
			s = ss::ToString(m_vDirectories[0]);

			for (size_t ix = 1; ix < m_vDirectories.size(); ++ix)
			{
				s += p_delimiter;
				s += ss::ToString(m_vDirectories[ix]);
			}
		}

		return s;
	}

	void Path::Append(const Filename& p_fnDir)
	{
		m_vDirectories.push_back(p_fnDir);
	}

	void Path::Prepend(const Filename& p_fnDir)
	{
		m_vDirectories.insert(m_vDirectories.begin(), p_fnDir);
	}

	void Path::Clear()
	{
		m_vDirectories.clear();
	}
}

namespace fs
{
	std::string format(const ss::Path& p_path)
	{
		return p_path.ToString();
	}
}
