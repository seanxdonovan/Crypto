#include "precomp.h"
#include "CryptoVM.h"
#include "Command.h"
#include "Commands.h"
#include "Parse.h"

namespace
{

	bool IsLiteral(const std::string& p_s, fs::ui *p_pLiteral)
	{
		sfcn();

		if (!p_s.empty())
		{
			if (p_s.length() > 2 && '0' == p_s[0] && 'x' == p_s[1])
			{
				// may be hex literal

				if (fs::convertHex(p_s, p_pLiteral))
				{
					return true;
				}
			}

			if (fs::convert(p_s, p_pLiteral))
			{
				return true;
			}
		}
		return false;
	}

	bool IsRegister(const std::string& p_s, fs::dword *p_pNumber)
	{
		sfcn();

		if (!p_s.empty())
		{
			if ('r' == p_s[0] || 'R' == p_s[0])
			{
				std::string sNumber = p_s.substr(1);
				return fs::convert(sNumber.c_str(), p_pNumber);
			}
		}

		return false;
	}

	bool IsDataRegister(const std::string& p_s, fs::dword *p_pNumber)
	{
		sfcn();

		if (!p_s.empty())
		{
			if ('d' == p_s[0] || 'D' == p_s[0])
			{
				std::string sNumber = p_s.substr(1);
				return fs::convert(sNumber.c_str(), p_pNumber);
			}
		}

		return false;
	}

	class CommandMaker
	{
	public:
		typedef fs::ReferenceCountedPointer<CommandMaker> RCP;

		virtual bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand) = 0;

	};

	class BlankMaker : public CommandMaker
	{
		public:
			bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
			{
				sfcn();

				*p_pCommand = Blank::Make(p_vm);
				return true;
			}


			static RCP Make()
			{
				sfcn();

				return RCP(new BlankMaker);
			}
	};

	class AddMaker : public CommandMaker
	{
	public:
		bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
		{
			sfcn();

			if (0 == p_args.size())
			{
				p_ef.Error(NumberOfParameters, "");
				return false;
			}
			fs::ui literal;
			fs::dword r1;
			fs::dword r2;
			fs::dword r3;

			if (1 == p_args.size())
			{
				if (IsLiteral(p_args[0], &literal))
				{
					*p_pCommand = Add_al::Make(p_vm, literal);
					return true;
				}

				if (IsRegister(p_args[0], &r1))
				{
					*p_pCommand = Add_ar::Make(p_vm, r1);
					return true;
				}

				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1 '", p_args[0], "'."));
				return false;
			}
			if (2 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				*p_pCommand = Add_rr::Make(p_vm, r1, r2);
				return true;
			}
			if (3 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				if (!IsRegister(p_args[2], &r3))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 3, register expected '", p_args[2], "'."));

					return false;
				}

				*p_pCommand = Add_rrr::Make(p_vm, r1, r2, r3);
				return true;
			}

			return false;
		}
		static RCP Make()
		{
			sfcn();

			return RCP(new AddMaker);
		}
	};

	class SubMaker : public CommandMaker
	{
	public:
		bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
		{
			sfcn();

			if (0 == p_args.size())
			{
				p_ef.Error(NumberOfParameters, "");
				return false;
			}
			fs::ui literal;
			fs::dword r1;
			fs::dword r2;
			fs::dword r3;

			if (1 == p_args.size())
			{
				if (IsLiteral(p_args[0], &literal))
				{
					*p_pCommand = Sub_al::Make(p_vm, literal);
					return true;
				}

				if (IsRegister(p_args[0], &r1))
				{
					*p_pCommand = Sub_ar::Make(p_vm, r1);
					return true;
				}

				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1 '", p_args[0], "'."));
				return false;
			}
			if (2 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				*p_pCommand = Sub_rr::Make(p_vm, r1, r2);
				return true;
			}
			if (3 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				if (!IsRegister(p_args[2], &r3))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 3, register expected '", p_args[2], "'."));

					return false;
				}

				*p_pCommand = Sub_rrr::Make(p_vm, r1, r2, r3);
				return true;
			}

			return false;
		}
		static RCP Make()
		{
			sfcn();

			return RCP(new SubMaker);
		}
	};



	class MulMaker : public CommandMaker
	{
	public:
		bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
		{
			sfcn();

			if (0 == p_args.size())
			{
				p_ef.Error(NumberOfParameters, "");
				return false;
			}
			fs::ui literal;
			fs::dword r1;
			fs::dword r2;
			fs::dword r3;

			if (1 == p_args.size())
			{
				if (IsLiteral(p_args[0], &literal))
				{
					*p_pCommand = Mul_al::Make(p_vm, literal);
					return true;
				}

				if (IsRegister(p_args[0], &r1))
				{
					*p_pCommand = Mul_ar::Make(p_vm, r1);
					return true;
				}

				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1 '", p_args[0], "'."));
				return false;
			}
			if (2 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				*p_pCommand = Mul_rr::Make(p_vm, r1, r2);
				return true;
			}
			if (3 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				if (!IsRegister(p_args[2], &r3))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 3, register expected '", p_args[2], "'."));

					return false;
				}

				*p_pCommand = Mul_rrr::Make(p_vm, r1, r2, r3);
				return true;
			}

			return false;
		}
		static RCP Make()
		{
			sfcn();

			return RCP(new MulMaker);
		}
	};



	class DivMaker : public CommandMaker
	{
	public:
		bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
		{
			sfcn();

			if (0 == p_args.size())
			{
				p_ef.Error(NumberOfParameters, "");
				return false;
			}
			fs::ui literal;
			fs::dword r1;
			fs::dword r2;
			fs::dword r3;
			fs::dword r4;

			if (1 == p_args.size())
			{
				if (IsLiteral(p_args[0], &literal))
				{
					*p_pCommand = Div_al::Make(p_vm, literal);
					return true;
				}

				if (IsRegister(p_args[0], &r1))
				{
					*p_pCommand = Div_ar::Make(p_vm, r1);
					return true;
				}

				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1 '", p_args[0], "'."));
				return false;
			}
			if (2 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				*p_pCommand = Div_rr::Make(p_vm, r1, r2);
				return true;
			}
			if (3 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				if (!IsRegister(p_args[2], &r3))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 3, register expected '", p_args[2], "'."));

					return false;
				}

				*p_pCommand = Div_rrr::Make(p_vm, r1, r2, r3);
				return true;
			}

			if (4 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				if (!IsRegister(p_args[2], &r3))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 3, register expected '", p_args[2], "'."));

					return false;
				}

				if (!IsRegister(p_args[3], &r4))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 4, register expected '", p_args[3], "'."));

					return false;
				}

				*p_pCommand = Div_rrrr::Make(p_vm, r1, r2, r3, r4);
				return true;
			}

			return false;
		}
		static RCP Make()
		{
			sfcn();

			return RCP(new DivMaker);
		}
	};

	class STA_Maker : public CommandMaker
	{
	public:
		bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
		{
			sfcn();

			if (0 == p_args.size())
			{
				p_ef.Error(NumberOfParameters, "");
				return false;
			}
			fs::dword r1;


			if (1 == p_args.size())
			{
				if (IsRegister(p_args[0], &r1))
				{
					*p_pCommand = STA_r::Make(p_vm, r1);
					return true;
				}

				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1 '", p_args[0], "'."));
				return false;
			}

			return false;
		}
		static RCP Make()
		{
			sfcn();

			return RCP(new STA_Maker);
		}
	};

	class STB_Maker : public CommandMaker
	{
	public:
		bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
		{
			sfcn();

			if (0 == p_args.size())
			{
				p_ef.Error(NumberOfParameters, "");
				return false;
			}
			fs::dword r1;


			if (1 == p_args.size())
			{
				if (IsRegister(p_args[0], &r1))
				{
					*p_pCommand = STB_r::Make(p_vm, r1);
					return true;
				}

				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1 '", p_args[0], "'."));
				return false;
			}

			return false;
		}

		static RCP Make()
		{
			sfcn();

			return RCP(new STB_Maker);
		}
	};


	class LDA_Maker : public CommandMaker
	{
	public:
		bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
		{
			sfcn();

			if (0 == p_args.size())
			{
				p_ef.Error(NumberOfParameters, "");
				return false;
			}
			fs::dword r1;
			fs::ui l;


			if (1 == p_args.size())
			{
				if (IsRegister(p_args[0], &r1))
				{
					*p_pCommand = LDA_r::Make(p_vm, r1);
					return true;
				}
				if (IsLiteral(p_args[0], &l))
				{
					*p_pCommand = LDA_l::Make(p_vm, l);
					return true;
				}

				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1 '", p_args[0], "'."));
				return false;
			}

			return false;
		}

		static RCP Make()
		{
			sfcn();

			return RCP(new LDA_Maker);
		}
	};


	class LDB_Maker : public CommandMaker
	{
	public:
		bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
		{
			sfcn();

			if (0 == p_args.size())
			{
				p_ef.Error(NumberOfParameters, "");
				return false;
			}
			fs::dword r1;
			fs::ui l;


			if (1 == p_args.size())
			{
				if (IsRegister(p_args[0], &r1))
				{
					*p_pCommand = LDB_r::Make(p_vm, r1);
					return true;
				}
				if (IsLiteral(p_args[0], &l))
				{
					*p_pCommand = LDB_l::Make(p_vm, l);
					return true;
				}

				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1 '", p_args[0], "'."));
				return false;
			}

			return false;
		}

		static RCP Make()
		{
			sfcn();

			return RCP(new LDB_Maker);
		}
	};

	class MOV_Maker : public CommandMaker
	{
	public:
		bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
		{
			sfcn();

			if (2 != p_args.size())
			{
				p_ef.Error(NumberOfParameters, "");
				return false;
			}
			fs::dword r1;
			fs::dword r2;

			if (!IsRegister(p_args[0], &r1))
			{
				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1 '", p_args[0], "'."));
				return false;
			}

			if (!IsRegister(p_args[1], &r2))
			{
				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2 '", p_args[1], "'."));
				return false;
			}

			*p_pCommand = MOV_rr::Make(p_vm, r1, r2);
			return true;
		}

		static RCP Make()
		{
			sfcn();

			return RCP(new MOV_Maker);
		}
	};

	class SWP_Maker : public CommandMaker
	{
	public:
		bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
		{
			sfcn();

			if (p_args.size() < 1 || p_args.size() > 2)
			{
				p_ef.Error(NumberOfParameters, "");
				return false;
			}
			fs::dword r1;
			fs::dword r2;

			if (!IsRegister(p_args[0], &r1))
			{
				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1 '", p_args[0], "'."));
				return false;
			}
			
			if (p_args.size() != 1)
			{
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2 '", p_args[1], "'."));
					return false;
				}
				*p_pCommand = SWP_rr::Make(p_vm, r1, r2);
			}
			else
			{
				*p_pCommand = SWP_r::Make(p_vm, r1);
			}
			return true;
		}

		static RCP Make()
		{
			sfcn();

			return RCP(new SWP_Maker);
		}
	};


	class PowMaker : public CommandMaker
	{
	public:
		bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
		{
			sfcn();

			if (0 == p_args.size())
			{
				p_ef.Error(NumberOfParameters, "");
				return false;
			}
			fs::ui literal;
			fs::dword r1;
			fs::dword r2;
			fs::dword r3;

			if (1 == p_args.size())
			{
				if (IsLiteral(p_args[0], &literal))
				{
					*p_pCommand = Pow_al::Make(p_vm, literal);
					return true;
				}

				if (IsRegister(p_args[0], &r1))
				{
					*p_pCommand = Pow_ar::Make(p_vm, r1);
					return true;
				}

				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1 '", p_args[0], "'."));
				return false;
			}
			if (2 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				*p_pCommand = Pow_rr::Make(p_vm, r1, r2);
				return true;
			}
			if (3 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				if (!IsRegister(p_args[2], &r3))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 3, register expected '", p_args[2], "'."));

					return false;
				}

				*p_pCommand = Pow_rrr::Make(p_vm, r1, r2, r3);
				return true;
			}

			return false;
		}
		static RCP Make()
		{
			sfcn();

			return RCP(new PowMaker);
		}
	};

	class XOR_Maker : public CommandMaker
	{
	public:
		bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
		{
			sfcn();

			if (0 == p_args.size())
			{
				p_ef.Error(NumberOfParameters, "");
				return false;
			}
			fs::ui literal;
			fs::dword r1;
			fs::dword r2;
			fs::dword r3;

			if (1 == p_args.size())
			{
				if (IsLiteral(p_args[0], &literal))
				{
					*p_pCommand = XOR_al::Make(p_vm, literal);
					return true;
				}

				if (IsRegister(p_args[0], &r1))
				{
					*p_pCommand = XOR_ar::Make(p_vm, r1);
					return true;
				}

				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1 '", p_args[0], "'."));
				return false;
			}
			if (2 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				*p_pCommand = XOR_rr::Make(p_vm, r1, r2);
				return true;
			}
			if (3 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				if (!IsRegister(p_args[2], &r3))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 3, register expected '", p_args[2], "'."));

					return false;
				}

				*p_pCommand = XOR_rrr::Make(p_vm, r1, r2, r3);
				return true;
			}

			return false;
		}
		static RCP Make()
		{
			sfcn();

			return RCP(new XOR_Maker);
		}
	};

	class OR_Maker : public CommandMaker
	{
	public:
		bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
		{
			sfcn();

			if (0 == p_args.size())
			{
				p_ef.Error(NumberOfParameters, "");
				return false;
			}
			fs::ui literal;
			fs::dword r1;
			fs::dword r2;
			fs::dword r3;

			if (1 == p_args.size())
			{
				if (IsLiteral(p_args[0], &literal))
				{
					*p_pCommand = OR_al::Make(p_vm, literal);
					return true;
				}

				if (IsRegister(p_args[0], &r1))
				{
					*p_pCommand = OR_ar::Make(p_vm, r1);
					return true;
				}

				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1 '", p_args[0], "'."));
				return false;
			}
			if (2 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				*p_pCommand = OR_rr::Make(p_vm, r1, r2);
				return true;
			}
			if (3 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				if (!IsRegister(p_args[2], &r3))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 3, register expected '", p_args[2], "'."));

					return false;
				}

				*p_pCommand = OR_rrr::Make(p_vm, r1, r2, r3);
				return true;
			}

			return false;
		}
		static RCP Make()
		{
			sfcn();

			return RCP(new OR_Maker);
		}
	};


	class AND_Maker : public CommandMaker
	{
	public:
		bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
		{
			sfcn();

			if (0 == p_args.size())
			{
				p_ef.Error(NumberOfParameters, "");
				return false;
			}
			fs::ui literal;
			fs::dword r1;
			fs::dword r2;
			fs::dword r3;

			if (1 == p_args.size())
			{
				if (IsLiteral(p_args[0], &literal))
				{
					*p_pCommand = AND_al::Make(p_vm, literal);
					return true;
				}

				if (IsRegister(p_args[0], &r1))
				{
					*p_pCommand = AND_ar::Make(p_vm, r1);
					return true;
				}

				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1 '", p_args[0], "'."));
				return false;
			}
			if (2 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				*p_pCommand = AND_rr::Make(p_vm, r1, r2);
				return true;
			}
			if (3 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				if (!IsRegister(p_args[2], &r3))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 3, register expected '", p_args[2], "'."));

					return false;
				}

				*p_pCommand = AND_rrr::Make(p_vm, r1, r2, r3);
				return true;
			}

			return false;
		}
		static RCP Make()
		{
			sfcn();

			return RCP(new AND_Maker);
		}
	};




	class NEG_Maker : public CommandMaker
	{
	public:
		bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
		{
			sfcn();

			if (0 == p_args.size())
			{
				*p_pCommand = NEG_a::Make(p_vm);
				return true;
			}

			fs::dword r1;
			if (1 == p_args.size())
			{
				if (IsRegister(p_args[0], &r1))
				{
					*p_pCommand = NEG_r::Make(p_vm, r1);
					return true;
				}

				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1 '", p_args[0], "'."));
				return false;
			}

			p_ef.Error(NumberOfParameters, "");
			return false;
		}

		static RCP Make()
		{
			sfcn();

			return RCP(new NEG_Maker);
		}
	};

	class SHR_Maker : public CommandMaker
	{
	public:
		bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
		{
			sfcn();

			if (0 == p_args.size())
			{
				p_ef.Error(NumberOfParameters, "");
				return false;
			}

			fs::ui literal;
			fs::dword r1;
			fs::dword r2;

			if (1 == p_args.size())
			{
				if (IsLiteral(p_args[0], &literal))
				{
					*p_pCommand = SHR_al::Make(p_vm, literal);
					return true;
				}

				if (IsRegister(p_args[0], &r1))
				{
					*p_pCommand = SHR_ar::Make(p_vm, r1);
					return true;
				}

				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1 '", p_args[0], "'."));
				return false;
			}

			if (2 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));
					return false;
				}
				if (IsRegister(p_args[1], &r2))
				{
					*p_pCommand = SHR_rr::Make(p_vm, r1, r2);
					return true;
				}

				if (IsLiteral(p_args[1], &literal))
				{
					*p_pCommand = SHR_rl::Make(p_vm, r1, literal);
					return true;
				}

				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register or literal expected '", p_args[1], "'."));
				return false;
			}

			p_ef.Error(NumberOfParameters, "");
			return false;
		}

		static RCP Make()
		{
			sfcn();

			return RCP(new SHR_Maker());
		}
	};



	class SHL_Maker : public CommandMaker
	{
	public:
		bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
		{
			sfcn();

			if (0 == p_args.size())
			{
				p_ef.Error(NumberOfParameters, "");
				return false;
			}

			fs::ui literal;
			fs::dword r1;
			fs::dword r2;

			if (1 == p_args.size())
			{
				if (IsLiteral(p_args[0], &literal))
				{
					*p_pCommand = SHL_al::Make(p_vm, literal);
					return true;
				}

				if (IsRegister(p_args[0], &r1))
				{
					*p_pCommand = SHL_ar::Make(p_vm, r1);
					return true;
				}

				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1 '", p_args[0], "'."));
				return false;
			}

			if (2 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));
					return false;
				}
				if (IsRegister(p_args[1], &r2))
				{
					*p_pCommand = SHL_rr::Make(p_vm, r1, r2);
					return true;
				}

				if (IsLiteral(p_args[1], &literal))
				{
					*p_pCommand = SHL_rl::Make(p_vm, r1, literal);
					return true;
				}

				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register or literal expected '", p_args[1], "'."));
				return false;
			}

			p_ef.Error(NumberOfParameters, "");
			return false;
		}

		static RCP Make()
		{
			sfcn();

			return RCP(new SHL_Maker());
		}
	};





	class MODADD_Maker : public CommandMaker
	{
	public:
		bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
		{
			sfcn();

			if (0 == p_args.size())
			{
				p_ef.Error(NumberOfParameters, "");
				return false;
			}
			fs::ui literal;
			fs::dword r1;
			fs::dword r2;
			fs::dword r3;
			fs::dword r4;

			if (1 == p_args.size())
			{
				if (IsLiteral(p_args[0], &literal))
				{
					*p_pCommand = MODADD_al::Make(p_vm, literal);
					return true;
				}

				if (IsRegister(p_args[0], &r1))
				{
					*p_pCommand = MODADD_ar::Make(p_vm, r1);
					return true;
				}

				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1 '", p_args[0], "'."));
				return false;
			}
			if (2 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				*p_pCommand = MODADD_rr::Make(p_vm, r1, r2);
				return true;
			}
			if (3 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				if (!IsRegister(p_args[2], &r3))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 3, register expected '", p_args[2], "'."));

					return false;
				}

				*p_pCommand = MODADD_rrr::Make(p_vm, r1, r2, r3);
				return true;
			}

			if (4 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				if (!IsRegister(p_args[2], &r3))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 3, register expected '", p_args[2], "'."));

					return false;
				}

				if (!IsRegister(p_args[3], &r4))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 4, register expected '", p_args[3], "'."));

					return false;
				}

				*p_pCommand = MODADD_rrrr::Make(p_vm, r1, r2, r3, r4);
				return true;
			}

			p_ef.Error(NumberOfParameters, "To many");
			return false;
		}
		static RCP Make()
		{
			sfcn();

			return RCP(new MODADD_Maker);
		}
	};






	class MODMUL_Maker : public CommandMaker
	{
	public:
		bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
		{
			sfcn();

			if (0 == p_args.size())
			{
				p_ef.Error(NumberOfParameters, "");
				return false;
			}
			fs::ui literal;
			fs::dword r1;
			fs::dword r2;
			fs::dword r3;
			fs::dword r4;

			if (1 == p_args.size())
			{
				if (IsLiteral(p_args[0], &literal))
				{
					*p_pCommand = MODMUL_al::Make(p_vm, literal);
					return true;
				}

				if (IsRegister(p_args[0], &r1))
				{
					*p_pCommand = MODMUL_ar::Make(p_vm, r1);
					return true;
				}

				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1 '", p_args[0], "'."));
				return false;
			}
			if (2 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				*p_pCommand = MODMUL_rr::Make(p_vm, r1, r2);
				return true;
			}
			if (3 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				if (!IsRegister(p_args[2], &r3))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 3, register expected '", p_args[2], "'."));

					return false;
				}

				*p_pCommand = MODMUL_rrr::Make(p_vm, r1, r2, r3);
				return true;
			}

			if (4 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

					return false;
				}
				if (!IsRegister(p_args[1], &r2))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

					return false;
				}

				if (!IsRegister(p_args[2], &r3))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 3, register expected '", p_args[2], "'."));

					return false;
				}

				if (!IsRegister(p_args[3], &r4))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 4, register expected '", p_args[3], "'."));

					return false;
				}

				*p_pCommand = MODMUL_rrrr::Make(p_vm, r1, r2, r3, r4);
				return true;
			}

			p_ef.Error(NumberOfParameters, "To many");
			return false;
		}
		static RCP Make()
		{
			sfcn();

			return RCP(new MODMUL_Maker);
		}
	};






	class MODEXP_Maker : public CommandMaker
	{
		public:
			bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
			{
				sfcn();

				if (0 == p_args.size())
				{
					p_ef.Error(NumberOfParameters, "");
					return false;
				}
				fs::ui literal;
				fs::dword r1;
				fs::dword r2;
				fs::dword r3;
				fs::dword r4;

				if (1 == p_args.size())
				{
					if (IsLiteral(p_args[0], &literal))
					{
						*p_pCommand = MODEXP_al::Make(p_vm, literal);
						return true;
					}

					if (IsRegister(p_args[0], &r1))
					{
						*p_pCommand = MODEXP_ar::Make(p_vm, r1);
						return true;
					}

					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1 '", p_args[0], "'."));
					return false;
				}
				if (2 == p_args.size())
				{
					if (!IsRegister(p_args[0], &r1))
					{
						p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

						return false;
					}
					if (!IsRegister(p_args[1], &r2))
					{
						p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

						return false;
					}

					*p_pCommand = MODEXP_rr::Make(p_vm, r1, r2);
					return true;
				}
				if (3 == p_args.size())
				{
					if (!IsRegister(p_args[0], &r1))
					{
						p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

						return false;
					}
					if (!IsRegister(p_args[1], &r2))
					{
						p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

						return false;
					}

					if (!IsRegister(p_args[2], &r3))
					{
						p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 3, register expected '", p_args[2], "'."));

						return false;
					}

					*p_pCommand = MODEXP_rrr::Make(p_vm, r1, r2, r3);
					return true;
				}

				if (4 == p_args.size())
				{
					if (!IsRegister(p_args[0], &r1))
					{
						p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));

						return false;
					}
					if (!IsRegister(p_args[1], &r2))
					{
						p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register expected '", p_args[1], "'."));

						return false;
					}

					if (!IsRegister(p_args[2], &r3))
					{
						p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 3, register expected '", p_args[2], "'."));

						return false;
					}

					if (!IsRegister(p_args[3], &r4))
					{
						p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 4, register expected '", p_args[3], "'."));

						return false;
					}

					*p_pCommand = MODEXP_rrrr::Make(p_vm, r1, r2, r3, r4);
					return true;
				}

				p_ef.Error(NumberOfParameters, "To many");
				return false;
			}
			static RCP Make()
			{
				sfcn();

				return RCP(new MODEXP_Maker);
			}
	};


	class RND_Maker : public CommandMaker
	{
	public:
		bool Build(const std::vector<std::string>& p_args, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
		{
			sfcn();

			if (0 == p_args.size())
			{
				p_ef.Error(NumberOfParameters, "");
				return false;
			}

			fs::ui literal;
			fs::dword r1;

			if (1 == p_args.size())
			{
				if (IsLiteral(p_args[0], &literal))
				{
					*p_pCommand = RND_al::Make(p_vm, literal);
					return true;
				}

				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1 '", p_args[0], "'."));
				return false;
			}

			if (2 == p_args.size())
			{
				if (!IsRegister(p_args[0], &r1))
				{
					p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 1, register expected '", p_args[0], "'."));
					return false;
				}
				if (IsLiteral(p_args[1], &literal))
				{
					*p_pCommand = RND_rl::Make(p_vm, r1, literal);
					return true;
				}

				p_ef.Error(ParameterType, fs::format("Incorrect parameter type for parameter 2, register or literal expected '", p_args[1], "'."));
				return false;
			}

			p_ef.Error(NumberOfParameters, "");
			return false;
		}

		static RCP Make()
		{
			sfcn();

			return RCP(new RND_Maker());
		}
	};









	bool DetermineCommand(const std::string& p_sCommand, CommandMaker::RCP *p_pCommandMaker)
	{
		sfcn();

		if ("ADD" == p_sCommand)
		{
			*p_pCommandMaker = AddMaker::Make();
			return true;
		}
		else if ("SUB" == p_sCommand)
		{
			*p_pCommandMaker = SubMaker::Make();
			return true;
		}
		else if ("MUL" == p_sCommand)
		{
			*p_pCommandMaker = MulMaker::Make();
			return true;
		}
		else if ("DIV" == p_sCommand)
		{
			*p_pCommandMaker = DivMaker::Make();
			return true;
		}
		else if ("STA" == p_sCommand)
		{
			*p_pCommandMaker = STA_Maker::Make();
			return true;
		}
		else if ("STB" == p_sCommand)
		{
			*p_pCommandMaker = STB_Maker::Make();
			return true;
		}
		else if ("LDA" == p_sCommand)
		{
			*p_pCommandMaker = LDA_Maker::Make();
			return true;
		}
		else if ("LDB" == p_sCommand)
		{
			*p_pCommandMaker = LDB_Maker::Make();
			return true;
		}
		else if ("MOV" == p_sCommand)
		{
			*p_pCommandMaker = MOV_Maker::Make();
			return true;
		}
		else if ("SWP" == p_sCommand)
		{
			*p_pCommandMaker = SWP_Maker::Make();
			return true;
		}
		else if ("POW" == p_sCommand)
		{
			*p_pCommandMaker = PowMaker::Make();
			return true;
		}
		else if ("XOR" == p_sCommand)
		{
			*p_pCommandMaker = XOR_Maker::Make();
			return true;
		}
		else if ("OR" == p_sCommand)
		{
			*p_pCommandMaker = OR_Maker::Make();
			return true;
		}
		else if ("AND" == p_sCommand)
		{
			*p_pCommandMaker = AND_Maker::Make();
			return true;
		}
		else if ("NEG" == p_sCommand)
		{
			*p_pCommandMaker = NEG_Maker::Make();
			return true;
		}
		else if ("SHR" == p_sCommand)
		{
			*p_pCommandMaker = SHR_Maker::Make();
			return true;
		}
		else if ("SHL" == p_sCommand)
		{
			*p_pCommandMaker = SHL_Maker::Make();
			return true;
		}
		else if ("MODADD" == p_sCommand)
		{
			*p_pCommandMaker = MODADD_Maker::Make();
			return true;
		}
		else if ("MODMUL" == p_sCommand)
		{
			*p_pCommandMaker = MODMUL_Maker::Make();
			return true;
		}
		else if ("MODEXP" == p_sCommand)
		{
			*p_pCommandMaker = MODEXP_Maker::Make();
			return true;
		}
		else if ("RND" == p_sCommand)
		{
			*p_pCommandMaker = RND_Maker::Make();
			return true;
		}
		else if ("MillerRabin" == p_sCommand)
		{
			*p_pCommandMaker = RND_Maker::Make();
			return true;
		}
		else if (p_sCommand.empty())
		{
			*p_pCommandMaker = BlankMaker::Make();
			return true;
		}

		return false;
	}

}


bool ParseLine(const std::string& p_s, CryptoVM& p_vm, ErrorInterface& p_ef, Command::RCP *p_pCommand)
{
	sfcn();

	std::string cmd;
	std::string comment;

	enum State
	{
		BOL,
		Command,
		NotArg,
		Arg,
		Comment,
		InvalidLine
	} state = BOL;

	std::vector<std::string> args;
	std::string arg;

	for (size_t ix = 0; ix < p_s.length(); ++ix)
	{
		const char ch = p_s[ix];
		if (BOL == state)
		{
			if (' ' == ch || '\t' == ch)
			{
			}
			else if (isalpha(ch))
			{
				state = Command;
				cmd = ch;
			}
			else if ('%' == ch)
			{
				state = Comment;
			}
			else
			{
				state = InvalidLine;
			}
		}
		else if (Command == state)
		{
			if (' ' == ch || '\t' == ch)
			{
				state = NotArg;
			}
			else if (isalpha(ch))
			{
				state = Command;
				cmd += ch;
			}
			else if ('%' == ch)
			{
				state = Comment;
				comment = ch;
			}
			else
			{
				state = InvalidLine;
			}
		}
		else if (NotArg == state)
		{
			if (' ' == ch || '\t' == ch)
			{
			}
			else if (isalnum(ch))
			{
				arg = ch;
				state = Arg;
			}
			else if ('%' == ch)
			{
				comment = ch;
				state = Comment;
			}
			else
			{
				state = InvalidLine;
			}
		}
		else if (Arg == state)
		{
			if (' ' == ch || '\t' == ch)
			{
				state = NotArg;
				args.push_back(arg);
			}
			else if ('%' == ch)
			{
				state = Comment;
				args.push_back(arg);
			}
			else if (isalnum(ch))
			{
				arg += ch;
			}
			else
			{
				args.push_back(arg);
				state = InvalidLine;
			}
		}
		else if (Comment == state)
		{
			comment += ch;
		}
		else if (InvalidLine == state)
		{
		}
	}

	if (Arg == state)
	{
		args.push_back(arg);
	}
	if (InvalidLine == state)
	{
		return false;
	}

	CommandMaker::RCP pCommandMaker;
	if (DetermineCommand(cmd, &pCommandMaker))
	{
		if (pCommandMaker->Build(args, p_vm, p_ef, p_pCommand))
		{
			return true;
		}
		p_ef.Error(BuildCommandFailed, p_s);
		return false;
	}

	p_ef.Error(UnknownCommand, p_s);
	return false;
}

void Parse(fs::Stream& p_stream, fs::Stream::Offset p_length, CryptoVM& p_vm, ErrorInterface& p_ef, std::vector<Command::RCP> *p_pvCommands)
{
	while (p_stream.Tell() < p_length)
	{
		std::string s;

		fs::ReadLn(p_stream, &s);
		Command::RCP cmd;
		if (ParseLine(s, p_vm, p_ef, &cmd))
		{
			p_ef.Info(ReadLine, s);
			p_pvCommands->push_back(cmd);
		}
		else
		{
			p_ef.Error(ParseLineFailed, s);
		}
	}
}

namespace fs
{
	std::string format(DiagnosticCode p_code)
	{
		std::string s = "not-translated";
		if (OK == p_code)
			s = "OK";
		else if (ReadLine == p_code)
			s = "ReadLine";
		else if (ParseLineFailed == p_code)
			s = "ParseLineFailed";
		else if (BuildCommandFailed == p_code)
			s = "BuildCommandFailed";
		else if (UnknownCommand == p_code)
			s = "UnknownCommand";
		else if (NumberOfParameters == p_code)
			s = "NumberOfParameters";
		else
			s = "unknown";
		return s;
	}
}
