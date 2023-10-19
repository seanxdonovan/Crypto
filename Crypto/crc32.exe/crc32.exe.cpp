#include "precomp.h"

class crc32app : public tools::ConsoleApplication
{
public:
	crc32app()
		: tools::ConsoleApplication("sxd", "crypto", "crc32.exe")
	{
	}

	int RunApplication(const std::vector<std::string>& p_arr)
	{
		for (size_t index = 0; index < Config().Arguments.size(); ++index)
		{
			ss::Filename fn;
			ss::Parse(Config().Arguments[index], &fn);

			ss::File f;
			ss::File::Closer fc(f);
			ss::FileStream fs(f);
			int;
			ss::File::fileoffset_t filesize;
//			fs::Stream::Offset filesize;
			f.Open(fn);
			f.Size(&filesize);

			fs::dword crc32 = crypto::crc32(fs, filesize);
			fprintf(stdout, "%s: %08x\n", Config().Arguments[index].c_str(), crc32);
		}

		return 0;
	}
};

int main(int argc, char *argv[])
{
	crc32app app;

	return app.Run(argc, argv);
}

/* End Of File: crc32.exe.cpp */
