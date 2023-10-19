#include "precomp.h"

class SHA384 : public crypto::Application
{
	fs::FixedBuffer<48> m_digest;
public:
	SHA384()
		: crypto::Application("SHA384", HashFunctor(&crypto::SHA_384), &m_digest)
	{
	}
};

int main(int argc, char *argv[])
{
	SHA384 app;

	return app.Run(argc, argv);
}

/* End Of File: SHA384.exe.cpp */
