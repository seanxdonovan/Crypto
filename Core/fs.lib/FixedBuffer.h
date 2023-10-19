namespace fs
{
	template <dword size>
	class FixedBuffer : public Buffer
	{
	public:
		inline FixedBuffer()
	    : Buffer(m_data, size)
		{
		}

		inline ~FixedBuffer()
		{
		}

	private:
		byte m_data[size];
	};
}

/* End Of File: FixedBuffer.h */
