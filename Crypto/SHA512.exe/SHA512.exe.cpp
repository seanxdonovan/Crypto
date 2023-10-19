#include "precomp.h"

class SHA512 : public crypto::Application
{
	fs::FixedBuffer<64> m_digest;
public:
	SHA512()
		: crypto::Application("SHA512", HashFunctor(&crypto::SHA_512), &m_digest)
	{
	}

};

int main(int argc, char *argv[])
{
	SHA512 app;

	return app.Run(argc, argv);
}

/* End Of File: SHA512.exe.cpp */
