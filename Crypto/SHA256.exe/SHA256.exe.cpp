#include "precomp.h"

class SHA256 : public crypto::Application
{
private:
		fs::FixedBuffer<32> m_digest;
public:
	SHA256()
		: crypto::Application("SHA256", HashFunctor(&::crypto::SHA_256), &m_digest)
	{
	}

};

int main(int argc, char *argv[])
{
	SHA256 app;

	return app.Run(argc, argv);
}

/* End Of File: SHA256.exe.cpp */
