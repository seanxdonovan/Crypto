namespace fs
{
	template <class T> struct Closer
	{
	private:
		T& m_t;
	public:
		Closer(T& p_t)
				: m_t(p_t)
		{
			sfcn();
		}
		~Closer()
		{
			sfcn();
			m_t.Close();
		}
	};
}

