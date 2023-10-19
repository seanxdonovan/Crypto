#include "precomp.h"

class SHA1 : public crypto::Application
{
	fs::FixedBuffer<20> m_digest;
public:
	SHA1()
		: crypto::Application("SHA1", HashFunctor(&crypto::SHA1), &m_digest)
	{
	}

};

int main(int argc, char *argv[])
{
	SHA1 app;

	return app.Run(argc, argv);
}

/* End Of File: SHA1.exe.cpp */
