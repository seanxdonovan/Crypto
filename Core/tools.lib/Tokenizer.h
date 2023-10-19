namespace tools
{
	class Tokenizer
	{
	public:
		Tokenizer();
		~Tokenizer();

		void Tokens(const std::string& p_string, std::vector<std::string> *p_pTokens);
	};
}
