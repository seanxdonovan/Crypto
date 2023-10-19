namespace fs
{
	class Random
	{
		ui32 m_current;
	public:
		Random(ui32 p_seed);

		ui32 Next();

	private: // not implemented.
		Random(const Random&);
		Random& operator =(const Random&);
	};

}
/* End Of File: Random.h */
