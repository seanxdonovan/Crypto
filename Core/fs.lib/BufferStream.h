namespace fs
{

	class BufferStream : public Stream
	{
		Buffer& m_buffer;
		Offset m_currentOffset;
	public:
		BufferStream(Buffer& p_buffer);

		void Read(Buffer& p_into);
		void Write(const Buffer& p_data);

		void Seek(Offset p_offset);
		Offset Tell() const;
		void Flush();

		bool EndOfStream();
	};

} /* namespace fs */

/* End Of File: BufferStream.h */
