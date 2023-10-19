namespace fs
{
	class ExpandingBufferStream : public Stream
	{
	public:
		typedef fs::ReferenceCountedPointerDerived<ExpandingBufferStream, Stream::RCP> RCP;
	public:
		static RCP Make(ExpandingBuffer& p_buffer);

	private:
		ExpandingBuffer& m_buffer;
		fs::dword m_readOffset;
	public:
		ExpandingBufferStream(ExpandingBuffer& p_buffer);
		void Write(const Buffer& p_data);
		void Read(Buffer& p_into); // need bytes read!

	};

	inline ExpandingBufferStream::ExpandingBufferStream(ExpandingBuffer& p_buffer)
	    : m_buffer(p_buffer)
	    , m_readOffset(0)
	{
		m_buffer.Seek(0);
	}

	inline void ExpandingBufferStream::Write(const Buffer& p_data)
	{
		m_buffer.Write(p_data);
	}

} /* namespace fs */

/* End Of File: ExpandingBufferStream.h */
