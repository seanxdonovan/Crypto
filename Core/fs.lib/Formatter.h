namespace fs
{
	class Formatter
	{
	public:
		Formatter(fs::Stream& p_stream);
	private:
		fs::Stream& m_stream;

	private:
		std::string m_margin;
	public:
		void SetMargin(const std::string& p_sMargin);
	private:
		std::vector<std::string> m_stackPrefix;

	public:
		void PrefixPush(const std::string& p_sPrefix);
		void PrefixPop();

	private:
		std::string m_sIndent;
	public:
		void SetIndent(const std::string& p_s);
	public:
		void DepthDecrement();
		void DepthIncrement();
	private:
		fs::dword m_depth;
	public:
		const fs::dword Depth() const;

	public:
		void NewLine();
		void WriteLn(const std::string& p_s);
	};
}
