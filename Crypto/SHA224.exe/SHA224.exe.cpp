#include "precomp.h"

class SHA224 : public crypto::Application
{
	fs::FixedBuffer<28> m_digest;
public:
	SHA224()
		: crypto::Application("SHA224", HashFunctor(&crypto::SHA_224), &m_digest)
	{
	}
};

int main(int argc, char *argv[])
{
	SHA224 app;

	return app.Run(argc, argv);
}

/* End Of File: SHA224.exe.cpp */
