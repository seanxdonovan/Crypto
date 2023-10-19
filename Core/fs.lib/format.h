

namespace fs
{
	std::string format(size_t p_n);
	std::string format(bool p_b);
//	std::string format(const char const*p_s);

	std::string hex(byte p_value);
	std::string hex(word p_value);
	std::string hex(dword p_value);
	std::string hex(qword p_value);
	std::string hex_(qword p_value);
	std::string hex(dqword p_value);
	std::string hex(const void * const p_p);

	template <typename T1, typename T2>
			std::string format(const T1& p_1, const T2& p_2)
	{
		std::string s = format(p_1);
		s += format(p_2);
		return s;
	}

	template <typename T1, typename T2, typename T3>
			std::string format(const T1& p_1, const T2& p_2, const T3& p_3)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		return s;
	}

	template <typename T1, typename T2, typename T3, typename T4>
			std::string format(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);
		return s;
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5>
			std::string format(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);
		s += format(p_5);
		return s;
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
			std::string format(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5, const T6& p_6)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);
		s += format(p_5);
		s += format(p_6);
		return s;
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
			std::string format(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5, const T6& p_6, const T7& p_7)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);
		s += format(p_5);
		s += format(p_6);
		s += format(p_7);
		return s;
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
			std::string format(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5, const T6& p_6, const T7& p_7, const T8& p_8)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);
		s += format(p_5);
		s += format(p_6);
		s += format(p_7);
		s += format(p_8);
		return s;
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
			std::string format(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5, const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);
		s += format(p_5);
		s += format(p_6);
		s += format(p_7);
		s += format(p_8);
		s += format(p_9);
		return s;
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
			std::string format(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5, const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const T10& p_10)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);
		s += format(p_5);
		s += format(p_6);
		s += format(p_7);
		s += format(p_8);
		s += format(p_9);
		s += format(p_10);
		return s;
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9,
		  typename T10, typename T11>
			std::string format(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5, const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9,
					   const T10& p_10, const T11& p_11)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);
		s += format(p_5);
		s += format(p_6);
		s += format(p_7);
		s += format(p_8);
		s += format(p_9);
		s += format(p_10);
		s += format(p_11);
		return s;
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9,
		  typename T10, typename T11, typename T12>
			std::string format(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5, const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9,
					   const T10& p_10, const T11& p_11, const T12& p_12)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);
		s += format(p_5);
		s += format(p_6);
		s += format(p_7);
		s += format(p_8);
		s += format(p_9);
		s += format(p_10);
		s += format(p_11);
		s += format(p_12);
		return s;
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9,
		  typename T10, typename T11, typename T12, typename T13>
			std::string format(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5, const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9,
					   const T10& p_10, const T11& p_11, const T12& p_12, const T13& p_13)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);
		s += format(p_5);
		s += format(p_6);
		s += format(p_7);
		s += format(p_8);
		s += format(p_9);
		s += format(p_10);
		s += format(p_11);
		s += format(p_12);
		s += format(p_13);
		return s;
	}

	}

/* End Of File: format.h */
