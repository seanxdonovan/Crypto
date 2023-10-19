namespace crypto
{
	class AES
	{

		void SubBytes();
		void ShiftRows();
		void MixColumns();
		void AddRoundKey();
	public:
		AES(fs::Buffer& p_key);
		~AES();

		void Cipher(const fs::Buffer& p_plainText, fs::Buffer *p_pCipherText);
	};

	void TestAES();
};
