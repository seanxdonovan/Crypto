namespace crypto
{
	class RC4
	{
	public:
		RC4(const fs::Buffer& p_key);
		~RC4();

		void Encode(fs::Buffer *p_pOut);

	private:
		fs::byte m_x;
		fs::byte m_y;
		fs::FixedBuffer<256> m_state;
	};
}

/* End Of File: RC4.h */