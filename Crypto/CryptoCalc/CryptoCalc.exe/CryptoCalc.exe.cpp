#include "precomp.h"


class CryptoCalcApplication : public tools::ConsoleApplication, public ErrorInterface
{
	//
	// ErrorInterface
	//
	void Info(DiagnosticCode p_code, const std::string& p_s)
	{
		sfcn();

		GetLog().Info(p_code, " ", p_s);
	}

	void Warning(DiagnosticCode p_code, const std::string& p_s)
	{
		sfcn();

		GetLog().Warning(p_code, " ", p_s);
	}

	void Error(DiagnosticCode p_code, const std::string& p_s)
	{
		sfcn();

		GetLog().Error(p_code, " ", p_s);
	}


public:
	CryptoCalcApplication()
		: tools::ConsoleApplication("sxd", "CryptoCalc", "CryptoCalc")
	{
		sfcn();
	}

	int RunApplication(const std::vector<std::string>& p_arr)
	{
		sfcn();

		std::vector<std::string> arguments;
		std::vector<std::pair<std::string, std::string> > options;

		MakeArgumentsAndOptions(p_arr, &arguments, &options);

		CryptoVM vm;

		for (size_t ix = 0; ix < arguments.size(); ++ix)
		{
			const std::string& arg = arguments[ix];

			ss::Filename fn;
			ss::Parse(arg, &fn);
			ss::File f;
			ss::File::Closer fc(f);
			ss::FileStream fs(f);
			f.OpenReadOnly(fn);


			std::vector<Command::RCP> commands;
			Parse(fs, f.Size(), vm, *this, &commands);



		}

		return 0;
	}
};

int main(int argc, char *argv[])
{
	sfcn();
	CryptoCalcApplication app;

	int rc;
	rc = app.Run(argc, argv);

	return rc;
}

/* End Of File: CryptoCalc.exe.cpp */
