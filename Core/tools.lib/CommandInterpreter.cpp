#include "precomp.h"
#include "Core/fs.lib/fs.lib.h"
#include "Core/ss.lib/ss.lib.h"
#include "CommandInterpreter.h"

namespace tools
{
	const char CommandInterpreter::DefaultLineTerminator[2] = {fs::LF, 0};
	
	bool CommandInterpreter::Interface::CanQuit()
	{
		return true;
	}

	namespace
	{
		inline bool  whitespace(char ch)
		{
			return (' ' == ch || '\t' == ch);
		}
	}

	CommandInterpreter::Interface & CommandInterpreter::GetInterface()
	{
		return m_interface;
	}

	void CommandInterpreter::Error(const std::string& p_s)
	{
		m_interface.Error(p_s);
	}

	void CommandInterpreter::i_parseLine(const std::string& p_sLine, std::string *p_psCommand, std::vector<std::string>* p_pvsParameters)
	{
		enum {
			Begin,
			Command,
			CommandWS,
			Parameters,
			ParametersWS
		} state = Begin;
		std::string sCurrent;

		for (size_t ix = 0; ix < p_sLine.length(); ++ix)
		{
			char ch = p_sLine[ix];

			if (Begin == state)
			{
				if (!whitespace(ch))
				{
					state = Command;
					sCurrent = ch;
				}
			}
			else if (Command == state)
			{
				if (!whitespace(ch))
				{
					sCurrent += ch;
				}
				else
				{
					*p_psCommand = sCurrent;
					sCurrent.clear();
					state = CommandWS;
				}
			}
			else if (CommandWS == state)
			{
				if (!whitespace(ch))
				{
					sCurrent += ch;
					state = Parameters;
				}
			}
			else if (Parameters == state)
			{
				if (!whitespace(ch))
				{
					sCurrent += ch;
				}
				else
				{
					p_pvsParameters->push_back(sCurrent);
					sCurrent.clear();
					state = ParametersWS;
				}
			}
			else if (ParametersWS == state)
			{
				if (!whitespace(ch))
				{
					sCurrent += ch;
					state = Parameters;
				}
			}
			else
			{
				sRaiseError(("Ut Oh."));
			}
		}

		if (Parameters == state)
		{
			p_pvsParameters->push_back(sCurrent);
		}
		else if (Command == state)
		{
			*p_psCommand = sCurrent;
		}
	}

	void CommandInterpreter::cmdListCommands(const std::vector<std::string>& p_vs)
	{
		MAP::iterator it = m_commands.begin();
		while (it != m_commands.end())
		{
			fs::Log::Instance().Info("'", it->first, "'");
			++it;
		}
	}

	void CommandInterpreter::cmdQuit(const std::vector<std::string>& p_vs)
	{
		if (m_interface.CanQuit())
		{
			throw Quit();
		}
		else
		{
			m_interface.Error("Quit failed.");
		}
	}

	void CommandInterpreter::cmdSource(const std::vector<std::string>& p_vs)
	{
		if (p_vs.empty())
		{
			return;
		}

		const std::string& sfilename = p_vs[0];

		ss::Filename fn;

		ss::Parse(sfilename, &fn);

		if (!ss::Exists(fn))
		{
			ss::CurrentWorkingDirectory(&fn);
			fn.m_filename = sfilename;
		}

		if (!ss::Exists(fn))
		{
			fs::Log::Instance().Error("Could not find '", fn, "'.");
			return;
		}

		if (ss::IsDirectory(fn))
		{
			fs::Log::Instance().Error("'", fn, "' is a directory.");
			return;
		}

		ss::File f;
		ss::File::Closer fc(f);

		ss::FileStream stream(f);

		f.OpenReadOnly(fn);

		Process(stream);
	}

	CommandInterpreter::CommandInterpreter(Interface& p_interface)
			: m_interface(p_interface)
	{
		Register("?", Command(this, &CommandInterpreter::cmdListCommands));
		Register("Quit", Command(this, &CommandInterpreter::cmdQuit));
		Register(".", Command(this, &CommandInterpreter::cmdSource));
		Register("source", Command(this, &CommandInterpreter::cmdSource));
	}

	void CommandInterpreter::Register(const std::string p_sCommand, Command p_dispatch)
	{
		MAP::iterator it = m_commands.find(p_sCommand);
		sValidate(it == m_commands.end(), ("The command '", p_sCommand, "' is already registered."));

		m_commands.insert(MAP::value_type(p_sCommand, p_dispatch));
	}

	void CommandInterpreter::ProcessLine(const std::string& p_sLine)
	{
		if (p_sLine.empty())
		{
			return;
		}

		std::string sCommand;
		std::vector<std::string> vsParameters;
		i_parseLine(p_sLine, &sCommand, &vsParameters);

		MAP::iterator it = m_commands.find(sCommand);

		if (it == m_commands.end())
		{
			m_interface.Error(fs::format("Could not process command '", sCommand, "'."));
		}
		else
		{
			Command cmd = it->second;
			cmd(vsParameters);
		}
	}

	void CommandInterpreter::Process(fs::Stream& p_stream, const char *p_lineTerminator)
	{
		fs::LineReader lr(p_stream);

		while (!p_stream.EndOfStream())
		{
			std::string s;
			lr.Next(&s);

			ProcessLine(s);
		}
	}

	void CommandInterpreter::Process(::ss::Filename& p_fn, const char *p_lineTerminator)
	{
		::ss::File f;
		::ss::File::Closer fc(f);
		::ss::FileStream fstream(f);

		::ss::File::Parameters params;
		params.ShareMode(FILE_SHARE_READ); // allow the log to be viewed.
		params.CreationDisposition(OPEN_EXISTING);
		params.DesiredAccess(GENERIC_READ);
		params.FlagsAndAttributes(FILE_ATTRIBUTE_NORMAL);

		f.Create(p_fn, params);

		Process(fstream, p_lineTerminator);
	}
}
