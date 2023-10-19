
namespace fs
{
	class Stream
	{
	public:
		typedef fs::dword Size;
		typedef fs::qword Offset;

//		virtual void Write(const void *p_pData, Size p_size) = 0;
		virtual void Write(const Buffer& p_buffer) = 0;
		// must read buffer bytes
		virtual void Read(Buffer&) = 0;

		// may read up to buffer bytes, return valid read
		// buffer
		virtual void Read(Buffer p_buffer, Buffer *p_pValid);
		virtual void Seek(Offset p_offset);
		virtual Offset Tell() const;
		virtual void Flush();

		void Write(fs::byte p_value);
		void Write(fs::word p_value);
		void Write(fs::dword p_value);
		void Write(fs::qword p_value);
		void Write(fs::dqword p_value);
		void Write(fs::si8 p_value);
		void Write(fs::si16 p_value);
		void Write(fs::si32 p_value);
		void Write(fs::si64 p_value);
		void Write(fs::si128 p_value);
		void Write(fs::Double p_value);
//		void Write(fs::Date p_value);
		void Write(fs::Guid p_value);
		void Write(const std::string& p_value);

		void Read(fs::byte *p_pValue);
		void Read(fs::word *p_pValue);
		void Read(fs::dword *p_pValue);
		void Read(fs::qword *p_pValue);
		void Read(fs::dqword *p_pValue);
		void Read(fs::si8 *p_pValue);
		void Read(fs::si16 *p_pValue);
		void Read(fs::si32 *p_pValue);
		void Read(fs::si64 *p_pValue);
		void Read(fs::si128 *p_pValue);
		void Read(fs::Double *p_pValue);
//		void Read(fs::Date *p_pValue);
		void Read(fs::Guid *p_pValue);
		void Read(std::string *p_pValue);

		virtual bool EndOfStream();

	public:
		typedef ReferenceCountedPointer<Stream> RCP;
	};

	void Copy(Stream& p_from, Stream& p_to, Stream::Offset p_amount);
	void WriteLn(Stream& p_to, const std::string& p_text);
	void ReadLn(Stream& p_from, std::string *p_pText, const char *p_sTerminator = 0);

	void WriteLn(Stream& p_to, fs::dword p_depth, const std::string& p_text, fs::byte p_prefix = fs::TAB);
	void WriteLn(Stream& p_to, fs::dword p_depth, const std::string& p_text, const std::string& p_prefix);
/*
	inline void Stream::Write(const Buffer& p_buffer)
	{
		Write(p_buffer.Data(), p_buffer.Size());
	}
*/
	inline void Stream::Write(fs::byte p_value)
	{
		Write(Buffer(&p_value));
	}

	inline void Stream::Write(fs::word p_value)
	{
		Write(Buffer(&p_value));
	}


	inline void Stream::Write(fs::dword p_value)
	{
		Write(Buffer(&p_value));
	}

	inline void Stream::Write(fs::qword p_value)
	{
		Write(Buffer(&p_value));
	}

	inline void Stream::Write(fs::dqword p_value)
	{
		Write(Buffer(&p_value));
	}

	inline void Stream::Write(fs::si8 p_value)
	{
		Write(Buffer(&p_value));
	}

	inline void Stream::Write(fs::si16 p_value)
	{
		Write(Buffer(&p_value));
	}

	inline void Stream::Write(fs::si32 p_value)
	{
		Write(Buffer(&p_value));
	}

	inline void Stream::Write(fs::si64 p_value)
	{
		Write(Buffer(&p_value));
	}

	inline void Stream::Write(fs::si128 p_value)
	{
		Write(Buffer(&p_value));
	}

	inline void Stream::Write(fs::Double p_value)
	{
		Write(Buffer(&p_value));
	}

//	inline void Stream::Write(fs::Date p_value)
//	{
//		Write(Buffer(&p_value));
//	}

	inline void Stream::Write(fs::Guid p_value)
	{
		Write(Buffer(&p_value));
	}

	inline void Stream::Write(const std::string& p_value)
	{
		Write(Buffer((byte*)p_value.c_str(), static_cast<fs::dword>(p_value.size())));
	}


	inline void Stream::Read(fs::byte *p_pValue)
	{
		Read(Buffer(p_pValue));
	}

	inline void Stream::Read(fs::word *p_pValue)
	{
		Read(Buffer(p_pValue));
	}

	inline void Stream::Read(fs::dword *p_pValue)
	{
		Read(Buffer(p_pValue));
	}

	inline void Stream::Read(fs::qword *p_pValue)
	{
		Read(Buffer(p_pValue));
	}

	inline void Stream::Read(fs::dqword *p_pValue)
	{
		Read(Buffer(p_pValue));
	}

	inline void Stream::Read(fs::si8 *p_pValue)
	{
		Read(Buffer(p_pValue));
	}

	inline void Stream::Read(fs::si16 *p_pValue)
	{
		Read(Buffer(p_pValue));
	}

	inline void Stream::Read(fs::si32 *p_pValue)
	{
		Read(Buffer(p_pValue));
	}

	inline void Stream::Read(fs::si64 *p_pValue)
	{
		Read(Buffer(p_pValue));
	}

	inline void Stream::Read(fs::si128 *p_pValue)
	{
		Read(Buffer(p_pValue));
	}

	inline void Stream::Read(fs::Double *p_pValue)
	{
		Read(Buffer(p_pValue));
	}

//	inline void Stream::Read(fs::Date *p_pValue)
//	{
//		Read(Buffer(p_pValue));
//	}

	inline void Stream::Read(fs::Guid *p_pValue)
	{
		Read(Buffer(p_pValue));
	}

	inline void Stream::Read(std::string *p_pValue)
	{
		// very dangerous
		Read(Buffer((byte *)(p_pValue->data()), static_cast<fs::dword>(p_pValue->size())));
	}

} /* namespace fs */

/* End Of File: Stream.h */
