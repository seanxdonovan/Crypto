#include "precomp.h"

class MD5app : public crypto::Application
{
	fs::FixedBuffer<16> m_digest;
public:
	MD5app()
			: crypto::Application("MD5", HashFunctor(&crypto::MD5), &m_digest)
	{
	}

};

int main(int argc, char *argv[])
{
	MD5app app;

	return app.Run(argc, argv);
}

/* End Of File: MD5.exe.cpp */
