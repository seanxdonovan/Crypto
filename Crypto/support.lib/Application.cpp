#include "precomp.h"

#include "Application.h"

namespace crypto
{
	Application::Application(const std::string& p_sBaseName /* e.g. "SHA256" */, HashFunctor p_fnHash, fs::Buffer *p_pDigestBuffer)
			: tools::ConsoleApplication("sxd", "crypto", p_sBaseName + ".exe")
			, m_sBaseName(p_sBaseName)
			, m_fnHash(p_fnHash)
			, m_pDigestBuffer(p_pDigestBuffer)
	{
		Config().Options.SetDefault("quiet", "false");
		Config().Options.SetDefault("digestOnly", "false");
		
	}

	Application::~Application()
	{
	}


	void Application::DisplayUsage()
	{
		fprintf(stdout, fs::format("Usage:\n\t", m_sBaseName, " [-quiet] [-digestOnly] filename [ ... filename ]").c_str());
	}

	int Application::RunApplication(const std::vector<std::string>& p_arr)
	{
		bool quiet = false;
		bool digestOnly = false;

		Config().Options.Require("quiet", &quiet);
		Config().Options.Require("digestOnly", &digestOnly);
		

		if (!quiet)
		{
			fprintf(stdout, "Copyright (c) 2009.  All Rights Reserved.\n");
			fprintf(stdout, fs::format(m_sBaseName, " v", m_versionNumber, " /\n\n").c_str());
		}

		if (Config().Arguments.empty())
		{
			DisplayUsage();
		}




		for (size_t index = 0; index < Config().Arguments.size(); ++index)
		{
			const std::string& sFilename = Config().Arguments[index];

			ss::Filename fn;
			ss::Parse(sFilename, &fn);
			ss::File f;
			ss::File::Closer fc(f);
			ss::FileStream fs(f);
			f.OpenReadOnly(fn);

			m_fnHash(fs, f.Size(), m_pDigestBuffer);

			std::string s;

			if (!digestOnly)
			{
				s = sFilename + ":";
			}

			s += fs::format(*m_pDigestBuffer);

			fprintf(stdout, "%s\n", s.c_str());
		}

		return 0;
	}


}
