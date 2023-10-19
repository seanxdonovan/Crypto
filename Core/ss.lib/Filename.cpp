#include "precomp.h"
#include "Core/fs.lib/fs.lib.h"

#include "Filename.h"

namespace ss
{
	void Filename::Append(const ::std::string& p_subdirectory)
	{
		m_directories.push_back(p_subdirectory);
	}

	void Filename::Append(const ::std::vector<::std::string>& p_subdirectory)
	{
		for (size_t ix = 0; ix < p_subdirectory.size(); ++ix)
		{
			m_directories.push_back(p_subdirectory[ix]);
		}
	}

	const bool Filename::Empty() const
	{
		return m_driveletter.empty() && m_directories.empty() && m_filename.empty();
	}

	void Filename::Clear()
	{
		m_driveletter.clear();
		m_directories.clear();
		m_filename.clear();
	}



	//
	// less
	// 

	bool Filename::less::operator () (const ss::Filename& p_lhs, const ss::Filename& p_rhs) const
	{
		return _stricmp(fs::format(p_lhs).c_str(), fs::format(p_rhs).c_str()) < 0;
	}


	bool Filename::IsAbsolute() const
	{
		if (m_driveletter.empty())
		{
			return false;
		}

		if (m_directories.empty())
		{
			return false;
		}

		if (m_directories[0].empty())
		{
			return true;
		}

		return false;
	}







	::std::string ToString(const Filename& p_filename, const char p_delimiter)
	{
		::std::string s;

		if (!p_filename.m_driveletter.empty())
		{
			s = p_filename.m_driveletter;
			s += ":";
		}

		if (!p_filename.m_directories.empty())
		{
			for (size_t ix = 0; ix < p_filename.m_directories.size(); ++ix)
			{
				s += p_filename.m_directories[ix];
				s += p_delimiter;
			}
		}
		s += p_filename.m_filename;
	
		return s;
	}

	void Parse(const ::std::string& p_fn, Filename *p_pFilename)
	{
		p_pFilename->Clear();

		size_t ix = 0;

		if (p_fn.size() >= 2)
		{
			if (p_fn[1] == ':')
			{
				p_pFilename->m_driveletter = p_fn[0];
				ix = 2;
			}
		}

		::std::string sCurrent;
		while (ix < p_fn.size())
		{
			if ('\\' == p_fn[ix] || '/' == p_fn[ix])
			{
				p_pFilename->Append(sCurrent);
				sCurrent.clear();
			}
			else
			{
				sCurrent += p_fn[ix];
			}
			++ix;
		}

		p_pFilename->m_filename = sCurrent;
	}

	bool Relative(const Filename& p_fnDirectory, const Filename& p_fnCompare, Filename *p_pfn)
	{
		if (!p_fnDirectory.m_filename.empty())
		{
			return false;
		}

		if (p_fnDirectory.m_driveletter != p_fnCompare.m_driveletter)
		{
			return false;
		}

		if (p_fnDirectory.m_directories.size() > p_fnCompare.m_directories.size())
		{
			return false;
		}

		size_t ix;
		for (ix = 0; ix < p_fnDirectory.m_directories.size(); ++ix)
		{
			if (p_fnDirectory.m_directories[ix] != p_fnCompare.m_directories[ix])
			{
				return false;
			}
		}
		while (ix < p_fnCompare.m_directories.size())
		{
			p_pfn->m_directories.push_back(p_fnCompare.m_directories[ix]);
			++ix;
		}

		p_pfn->m_filename = p_fnCompare.m_filename;

		return true;
	}

	void FullRelative(const Filename& p_fnRoot, const Filename& p_fn, Filename *p_pfn)
	{
		sPrecondition(p_fnRoot.m_filename.empty());

		Filename fn = p_fnRoot;

		if (!p_fn.m_driveletter.empty())
		{
			fn.Append(p_fn.m_driveletter);
		}

		size_t ix;
		for (ix = 0; ix < p_fn.m_directories.size(); ++ix)
		{
			fn.Append(p_fn.m_directories[ix]);
		}
		fn.m_filename = p_fn.m_filename;
	}
}

namespace fs
{
	void Require(const ::std::string& p_sName, const ::fs::Options& p_options, ::ss::Filename *p_pfn)
	{
		::std::string sfn;
		Require(p_sName, p_options, &sfn);

		::ss::Parse(sfn, p_pfn);
	}
}

/* End Of File: Filename.cpp */
