namespace fs
{
	template <class T> void Zero(T& p_pod)
	{
		fs::Buffer buff(&p_pod);
		buff.Zero();
	}
}
