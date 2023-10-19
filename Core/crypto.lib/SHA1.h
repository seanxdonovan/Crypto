namespace crypto
{
	class SHA1Digest
	{

	private:
		fs::dword m_h0;
		fs::dword m_h1;
		fs::dword m_h2;
		fs::dword m_h3;
		fs::dword m_h4;

		fs::qword m_bitCount;
		fs::FixedBuffer<64> m_partialBlock;
		fs::FixedBuffer<64> m_padding;

		void Transform(fs::Buffer p_block);
	public:
		void Start();
		void Update(fs::Buffer p_data);
		void Finish(fs::Buffer *p_pDigest);
	};

	void SHA1(fs::Stream& p_streamInput, fs::Stream::Size p_length, fs::Buffer *p_pDigest);
}

