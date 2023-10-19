
enum DiagnosticCode
{
	OK,
	ReadLine,
	ParseLineFailed,
	BuildCommandFailed,
	UnknownCommand,
	NumberOfParameters,
	ParameterType
	
};



class ErrorInterface
{
public:
	virtual void Info(DiagnosticCode p_code, const std::string& p_s) = 0;
	virtual void Warning(DiagnosticCode p_code, const std::string& p_s) = 0;
	virtual void Error(DiagnosticCode p_code, const std::string& p_s)= 0;
};



Command::RCP ParseLine(const std::string& p_s, CryptoVM& p_vm, ErrorInterface& p_ef);

void Parse(fs::Stream& p_stream, fs::Stream::Offset p_length, CryptoVM& p_vm, ErrorInterface& p_ef, std::vector<Command::RCP> *p_pvCommands);

namespace fs
{
	std::string format(DiagnosticCode p_code);
}
   