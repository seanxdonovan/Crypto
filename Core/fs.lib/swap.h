namespace fs
{
	template <class T>
			inline void swap(T* p_pA, T* p_pB)
	{
		T tmp = *p_pA;
		*p_pA = *p_pB;
		*p_pB = tmp;
	}
}

/* End of File: swap.h */
