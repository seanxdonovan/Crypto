#include "precomp.h"

class Digester
{
public:
	virtual std::string Name() const = 0;
	virtual fs::Buffer Digest() const = 0;
	virtual void Process(fs::Stream& p_stream, fs::Stream::Size p_length)= 0;
};

class MD5Digester : public Digester
{
	std::string Name() const
	{
		return "MD5";
	}

	fs::FixedBuffer<16> m_digest;
	fs::Buffer Digest() const
	{
		return m_digest;
	}

	void Process(fs::Stream& p_stream, fs::Stream::Size p_length)
	{
		crypto::MD5(p_stream, p_length, &m_digest);
	}
};

class SHA1Digester : public Digester
{
	std::string Name() const
	{
		return "SHA1";
	}
				   
	fs::FixedBuffer<20> m_digest;
	fs::Buffer Digest() const
	{
		return m_digest;
	}

	void Process(fs::Stream& p_stream, fs::Stream::Size p_length)
	{
		crypto::SHA1(p_stream, p_length, &m_digest);
	}
};

class CRC32Digester : public Digester
{
	std::string Name() const
	{
		return "CRC32";
	}

	fs::dword m_crc32;
	fs::Buffer Digest() const
	{
		return fs::Buffer(&m_crc32);
	}

	void Process(fs::Stream& p_stream, fs::Stream::Size p_length)
	{
		m_crc32 = crypto::crc32(p_stream, p_length);
	}
};

class MD2Digester : public Digester
{
	std::string Name() const
	{
		return "MD2";
	}

	fs::FixedBuffer<16> m_digest;
	fs::Buffer Digest() const
	{
		return m_digest;
	}

	void Process(fs::Stream& p_stream, fs::Stream::Size p_length)
	{
		crypto::MD2(p_stream, p_length, &m_digest);
	}
};


class SizeDigester : public Digester
{

	std::string Name() const
	{
		return "Size";
	}

	ss::File::fileoffset_t m_size;
	fs::Buffer Digest() const
	{
		return fs::Buffer(&m_size);
	}

	void Process(fs::Stream& p_stream, fs::Stream::Size p_length)
	{
		m_size = p_length;
	}
};


void Apply(Digester *p, const std::string& p_sFilename)
{
	ss::Filename fn;
	ss::Parse(p_sFilename, &fn);

	ss::File f;
	ss::File::Closer fc(f);
	ss::FileStream fs(f);

	f.Open(fn);
	ss::File::fileoffset_t size;
	f.Size(&size);

	p->Process(fs, size);
}


class hash_app : public tools::ConsoleApplication
{
public:
	hash_app()
		: tools::ConsoleApplication("sxd", "crypto", "hash.exe")
	{
	}

	int RunApplication(const std::vector<std::string>& p_arr)
	{
		std::vector<Digester *> digesters;

		::fs::Options& o = Config().Options;
		::std::string s;


		if (o.Find("MD5", &s))
		{
			digesters.push_back(new MD5Digester());
		}
			
		if (o.Find("SHA1", &s))
		{
			digesters.push_back(new SHA1Digester());
		}
			
		if (o.Find("CRC32", &s))
		{
			digesters.push_back(new CRC32Digester());
		}
			
		if (o.Find("MD2", &s))
		{
			digesters.push_back(new MD2Digester());
		}
		else if (o.Find("SIZE", &s))
		{
			digesters.push_back(new SizeDigester());
		}
	

		FILE* fout = stdout;

		fprintf(fout, "\"file\"");
		std::vector<Digester*>::iterator it = digesters.begin();
		{
			while (it != digesters.end())
			{
				Digester *p = *it;
				fprintf(fout, ",\"%s\"", p->Name().c_str());
				++it;
			}
			fprintf(fout, "\n");
		}

		for (size_t index = 0; index < Config().Arguments.size(); ++index)
		{
			fprintf(fout, "\"%s\"", Config().Arguments[index].c_str());
			std::vector<Digester*>::iterator it = digesters.begin();
			{
				while (it != digesters.end())
				{
					Digester *p = *it;
					Apply(p, Config().Arguments[index]);
					fprintf(fout, ",\"%s\"", fs::format(p->Digest()).c_str());
					++it;
				}
				fprintf(fout, "\n");
			}
		}

		return 0;
	}
};

int main(int argc, char *argv[])
{
	hash_app app;

	return app.Run(argc, argv);
}

/* End Of File: hash.exe.cpp */
