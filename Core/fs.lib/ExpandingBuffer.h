


namespace fs
{

	class ExpandingBuffer : public HeapBuffer
	{
		Offset m_writeOffset;
		
	public:
		ExpandingBuffer(const dword p_initialSize = 4096);
		~ExpandingBuffer();

		void Write(const Buffer& p_buffer);
		void Write(const char *p_pString);
		void Write(const std::string& p_s);

		void Seek(dword p_offset);

		void Resize(dword p_newSize);
		Offset DataSize() const;

		fs::byte *Lock();
		void Unlock(Offset p_newWriteOffset);

		fs::Buffer DataBuffer();

	private: // No copying
		ExpandingBuffer(const ExpandingBuffer& p_rhs);
		ExpandingBuffer& operator=(const ExpandingBuffer& p_rhs);

	};

} /* namespace fs */

/* End Of File: ExpandingBuffer.h */

