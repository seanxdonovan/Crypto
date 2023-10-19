namespace fs
{
	class BufferedReader
	{
	public:
		BufferedReader(Stream& p_stream, Stream::Offset p_lengthToRead, Buffer& p_buffer);

		byte Get();

		bool End() const;
	private:
		void i_fillBuffer();

		Stream::Offset m_nBuffered;
		Stream::Offset m_nCurrentOffset;
		const Stream::Offset m_totalToRead;
		Stream::Offset m_nRead;
		Stream& m_stream;
		Buffer& m_buffer;
	public:
		void Read(::fs::Buffer p_buffer, ::fs::Buffer *p_pRead);
		bool Consume(::fs::Buffer::Offset p_size, ::fs::Buffer *p_pRead);
	};

	void ReadLn(BufferedReader& p_reader, std::string *p_pText);
	void ReadLF(BufferedReader& p_reader, std::string *p_pText);
}

/* End Of File: BufferedReader.h */
