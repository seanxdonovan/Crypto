

class Command
{
protected:
	CryptoVM& m_vm;
public:
	Command(CryptoVM& p_vm);
	virtual ~Command();
	virtual void Execute() = 0;
	virtual void Print(fs::Stream& p_s) = 0;

	typedef fs::ReferenceCountedPointer<Command> RCP;
};
