namespace fs
{
	class HeapBuffer : public Buffer
	{
	public:
		HeapBuffer(Offset p_initialSize = 4096);
		~HeapBuffer();

		void Resize(Offset newDataSize);

		HeapBuffer(const HeapBuffer &);
		HeapBuffer&	operator=(const HeapBuffer &);
	private:
	};

	inline HeapBuffer::HeapBuffer(Offset p_size)
	{
		byte *p = new byte[p_size];
		i_setData(p, p_size);
	}


	inline HeapBuffer::~HeapBuffer()
	{
		byte *p = Data();
		delete [] p;
	}
}

/* End Of File: HeapBuffer.h */
