#include "precomp.h"
#include "CryptoVM.h"

#include "Command.h"

Command::Command(CryptoVM& p_vm)
: m_vm(p_vm)
{
	sfcn();
}

Command::~Command()
{
	sfcn();
}

void Command::Execute()
{
	sfcn();
	sRaiseError(("oops"));
}
