namespace fs
{
	struct Date
	{
		dword m_dayCount;

		Date();
		Date(fs::si32 p_year, fs::dword p_month, fs::dword p_day);

		void Crack(fs::si32 *p_pYear, fs::dword *p_pMonth, fs::dword *p_pDay) const;
		//
		// 0 is Monday, ... , 6 is Sunday.
		//
		void DayOfWeek(fs::dword *p_dayOfWeek);
		fs::dword DayOfWeek() const;

		static const ::fs::dword Monday    = 0;
		static const ::fs::dword Tuesday   = 1;
		static const ::fs::dword Wednesday = 2;
		static const ::fs::dword Thursday  = 3;
		static const ::fs::dword Friday    = 4;
		static const ::fs::dword Saturday  = 5;
		static const ::fs::dword Sunday    = 6;

		dword operator - (const fs::Date& p_date) const
		{
			return m_dayCount - p_date.m_dayCount;
		}

		class Span
		{
			fs::si32 m_dayCount;

		public:
			inline Span(fs::si32 p_dayCount)
					: m_dayCount(p_dayCount)
			{
			}

			inline fs::si32 DayCount() const
			{
				return m_dayCount;
			}
		};

		Date& operator -= (Span p_span);
		Date& operator += (Span p_span);

		inline bool operator < (Date p_rhs) const
		{
			return m_dayCount < p_rhs.m_dayCount;
		}
	};

	inline Date::Span Days(fs::si32 p_days)
	{
		return Date::Span(p_days);
	}
	inline Date operator + (Date p_date, Date::Span p_dayCount)
	{
		Date d = p_date;
		d += p_dayCount;
		return d;
	}
	
	inline Date operator - (Date p_date, Date::Span p_dayCount)
	{
		Date d = p_date;
		d -= p_dayCount;
		return d;
	}



	inline size_t Size(const Date *)
	{
		return sizeof(Date);
	}

	void DofW(const Date& p_date, fs::dword *p_dayOfWeek);

	Date Gregorian(fs::si32 p_year, fs::dword p_month, fs::dword p_day);

	std::string format(const Date& p_date);

	bool convert(const char *p_ps, Date *p_pDate);
	bool Convert(const std::string& p_s, Date *p_pDate);

	template <> struct Type<fs::Date>
	{
		static const fs::type::ID ID = fs::type::id::Date;
	};

	template <> struct Traits<Date>
	{
		static const bool isFixedSize = true;
	};

	template <> struct Sizer<Date>
	{
		static const size_t Size = sizeof(Date);
	};

	template<> struct io<Date>
	{
		static inline void put(BufferWriter& p_bw, fs::PT<fs::Date>::T p_v)
		{
			p_bw.put(p_v.m_dayCount);
		}
		static inline void get(BufferReader& p_br, fs::Date *p_pV)
		{
			p_br.get(&(p_pV->m_dayCount));
		}
	};
}


inline bool operator == (const fs::Date& p_lhs, const fs::Date& p_rhs)
{
	return p_lhs.m_dayCount == p_rhs.m_dayCount;
}

inline bool operator != (const fs::Date& p_lhs, const fs::Date& p_rhs)
{
	return p_lhs.m_dayCount != p_rhs.m_dayCount;
}

/*ninline bool operator <  (const fs::Date& p_lhs, const fs::Date& p_rhs)
{
	return p_lhs.m_dayCount < p_rhs.m_dayCount;
}
*/
inline bool operator <= (const fs::Date& p_lhs, const fs::Date& p_rhs)
{
	return p_lhs.m_dayCount <= p_rhs.m_dayCount;
}

inline bool operator >  (const fs::Date& p_lhs, const fs::Date& p_rhs)
{
	return p_lhs.m_dayCount > p_rhs.m_dayCount;
}

inline bool operator >= (const fs::Date& p_lhs, const fs::Date& p_rhs)
{
	return p_lhs.m_dayCount >= p_rhs.m_dayCount;
}





/* End Of File: Date.h */
