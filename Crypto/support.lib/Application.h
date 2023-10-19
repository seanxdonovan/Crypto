namespace crypto
{
	class Application : public ::tools::ConsoleApplication
	{
	public:
		typedef fs::Functor<void, TYPELIST_3(fs::Stream&, fs::Stream::Size, fs::Buffer *)>  HashFunctor;
	public:
		Application(const std::string& p_sBaseName, HashFunctor p_fnHash, fs::Buffer *p_pDigestBuffer);
		~Application();

		void DisplayUsage();
		int RunApplication(const std::vector<std::string>& p_arr);

	private:
		const std::string m_sBaseName;
		HashFunctor m_fnHash;
		fs::Buffer *m_pDigestBuffer;
		static const fs::dword m_versionNumber = 4;
	};
}
