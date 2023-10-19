namespace fs
{
	class DateTime
	{

	private:
		fs::qword m_ticks;
	public:
		static const qword TicksPerDay         = 1000 * 60 * 60 * 24;
		static const qword TicksPerHour        = 1000 * 60 * 60;
		static const qword TicksPerMinute      = 1000 * 60;
		static const qword TicksPerSecond      = 1000;

	public:



		inline DateTime()
				: m_ticks(0)
		{
		}

		inline DateTime(Date p_date)
		{
			m_ticks =  p_date.m_dayCount;
			m_ticks *= TicksPerDay;
		}

		inline DateTime(Date p_date, Time p_time)
		{
			m_ticks =  p_date.m_dayCount;
			m_ticks *= TicksPerDay;
			m_ticks += p_time.m_tickCount;
		}

		inline explicit DateTime(fs::qword p_ticks)
			: m_ticks(p_ticks)
		{
		}
		DateTime(fs::si32 p_year, fs::dword p_month, fs::dword p_day, fs::dword p_hour = 0, fs::dword p_minute = 0, fs::dword p_seconds = 0, fs::dword p_ms = 0);

		inline fs::qword TickCount() const
		{
			return m_ticks;
		}
				

		void Crack(fs::si32 *p_pYear, fs::dword *p_pMonth, fs::dword *p_pDay, fs::dword *p_pHours, fs::dword *p_pMinutes, fs::dword *p_pSeconds, fs::dword *p_pms) const;

		Date DatePart() const;
		Time TimePart() const;

		void Set(fs::si32 p_year, fs::dword p_month, fs::dword p_day, fs::dword p_hour = 0, fs::dword p_minute = 0, fs::dword p_seconds = 0, fs::dword p_ms = 0);

		DateTime& operator +=(const Time::Span& p_span);

		class Span
		{
			si64 m_tickCount;
		public:
			inline Span()
					: m_tickCount(0)
			{
			}

			Span(Date::Span p_span);
			Span(Time::Span p_span);
			Span(fs::si64 p_tickCount)
					: m_tickCount(p_tickCount)
			{
			}

			void Crack(fs::dword *p_pDayCount, fs::dword *p_pTickCount);
			inline si64 TickCount() const
			{
				return m_tickCount;
			}

			Span& operator *=(fs::si64 p_scalar);

			inline fs::si64 MilliSeconds() const
			{
				return m_tickCount;
			}
		};

		//
		// we do not provide years or months as they are not of
		// fixed size. They are date relative.
		//

		static Span Days(fs::si64 p_nDays);
		static Span Hours(fs::si64 p_nHours);
		static Span Minutes(fs::si64 p_nMinutes);
		static Span Seconds(fs::si64 p_nSeconds);
		static Span NanoSeconds(::fs::qword p_nSeconds);

		inline static Span MilliSeconds(fs::si64 p_nMilliSeconds)
		{
			return Span(p_nMilliSeconds);
		}

		DateTime& operator +=(Span p_span);
		DateTime& operator -=(Span p_span);

		DateTime LowerBound(Span p_span) const;
		DateTime UpperBound(Span p_span) const;

		static const DateTime BeginningOfTime;

		// inclusive between
		bool Between(fs::DateTime p_leftBound, fs::DateTime p_rightBound) const;

		class Epoch
		{
		public:
			typedef fs::qword Ordinal;
		private:
			Ordinal m_nEpoch;

		public:
			inline Epoch(Ordinal p_nEpoch = 0)
					: m_nEpoch(p_nEpoch)
			{
			}
			inline const Ordinal Count() const
			{
				return m_nEpoch;
			}

			inline Epoch& operator +=(Ordinal p_n)
			{
				m_nEpoch += p_n;
				return *this;
			}

			Epoch operator -- ()
			{
				--m_nEpoch;
				return *this;
			}
		};
	};

	inline Date DateTime::DatePart() const
	{
		Date dt;
		dt.m_dayCount = sCoerce(fs::dword, TickCount() / TicksPerDay);
		return dt;
	}

	inline Time DateTime::TimePart() const
	{
		Time tm;
		tm.m_tickCount = sCoerce(dword, TickCount() % TicksPerDay);
		return tm;
	}

	inline DateTime::Span operator - (DateTime p_a, DateTime p_b)
	{
		return p_a.TickCount() - p_b.TickCount();
	}
	DateTime operator - (DateTime p_a, DateTime::Span p_b);
	DateTime operator + (DateTime p_a, DateTime::Span p_b);

	inline size_t Size(const DateTime *)
	{
		return sizeof(DateTime);
	}


	//
	// operations on Span
	//

	DateTime::Span operator *(const DateTime::Span& p_span, si64 p_multiplier);
	DateTime::Span operator *(si64 p_multiplier, const DateTime::Span& p_span);

	si64 operator / (DateTime::Span p_l, DateTime::Span p_r);
	si64 operator % (DateTime::Span p_l, DateTime::Span p_r);


	//
	//
	//

	void convert(const DateTime& p_datetime, SYSTEMTIME *p_pSystemTime);
	void convert(const SYSTEMTIME& p_systemtime, DateTime *p_pDatetime);

	DateTime Now();
	DateTime Local();

	Date Today(fs::dword p_hoursOffsetUTC = 0, fs::dword p_minutesOffsetUTC = 0);
	Date Yesterday(fs::dword p_hoursOffsetUTC = 0, fs::dword p_minutesOffsetUTC = 0);
	Date Tomorrow(fs::dword p_hoursOffsetUTC = 0, fs::dword p_minutesOffsetUTC = 0);

	fs::si64 Minutes(const DateTime::Span& p_span);

	fs::qword PeriodsPer(fs::DateTime::Span p_period, fs::DateTime::Span p_total);


	template <> struct Traits<DateTime>
	{
		static const bool isFixedSize = true;

		static const size_t Size = sizeof(DateTime);
	};

	template <> struct Traits<DateTime::Span>
	{
		static const bool isFixedSize = true;
	};

	template <> struct Traits<DateTime::Epoch>
	{
		static const bool isFixedSize = true;
	};

	template <> struct Sizer<DateTime>
	{
		static const size_t Size = sizeof(DateTime);
	};

	template <> struct Sizer<DateTime::Span>
	{
		static const size_t Size = sizeof(DateTime::Span);
	};

	template <> struct Sizer<DateTime::Epoch>
	{
		static const size_t Size = sizeof(DateTime::Epoch::Ordinal);
	};

	std::string format(const DateTime& p_datetime);
	std::string format(DateTime::Span p_span);
	std::string format(DateTime::Epoch p_span);

	bool Convert(const std::string& p_s, fs::DateTime *p_pDateTime);
	bool Convert(const std::string& p_s, fs::DateTime::Span *p_pInterval);
	bool Convert(const std::string& p_s, fs::DateTime::Epoch *p_pEpoch);


	inline fs::DateTime::Epoch operator / (fs::DateTime p_datetime, fs::DateTime::Span p_span)
	{
		fs::DateTime::Epoch::Ordinal n = p_datetime.TickCount() / fs::abs(p_span.TickCount());

		return fs::DateTime::Epoch(n);
	}

	inline fs::DateTime operator * (fs::DateTime::Epoch p_epoch, fs::DateTime::Span p_span)
	{
		return fs::DateTime(p_epoch.Count() * abs(p_span.TickCount()));
	}

	inline fs::DateTime operator * (fs::DateTime::Span p_span, fs::DateTime::Epoch p_epoch)
	{
		return fs::DateTime(abs(p_span.TickCount()) * p_epoch.Count());
	}

	template <> struct Type<fs::DateTime>
	{
		static const fs::type::ID ID = fs::type::id::DateTime;
	};

	template <> struct Type<fs::DateTime::Span>
	{
		static const fs::type::ID ID = fs::type::id::DateTime_Span;
	};

	template <> struct Type<fs::DateTime::Epoch>
	{
		static const fs::type::ID ID = fs::type::id::DateTime_Epoch;
	};


	template<> struct io<DateTime>
	{
		static inline void put(BufferWriter& p_bw, fs::PT<DateTime>::T p_v)
		{
			p_bw.put(p_v.TickCount());
		}
		static inline void get(BufferReader& p_br, DateTime *p_pV)
		{
			fs::qword v;
			p_br.get(&v);
			*p_pV = fs::DateTime(v);
		}
	};

	template<> struct io<DateTime::Span>
	{
		static inline void put(BufferWriter& p_bw, fs::PT<DateTime::Span>::T p_v)
		{
			p_bw.put(p_v.TickCount());
		}
		static inline void get(BufferReader& p_br, DateTime::Span *p_pV)
		{
			fs::qword v;
			p_br.get(&v);
			*p_pV = DateTime::Span(v);
		}
	};

	template<> struct io<DateTime::Epoch>
	{
		static inline void put(BufferWriter& p_bw, fs::PT<DateTime::Epoch>::T p_v)
		{
			p_bw.put(p_v.Count());
		}
		static inline void get(BufferReader& p_br, DateTime::Epoch *p_pV)
		{
			fs::qword v;
			p_br.get(&v);
			*p_pV = DateTime::Epoch(v);
		}
	};
}




//
// fs::DateTime
//

inline bool operator < (const fs::DateTime& p_lhs, const fs::DateTime& p_rhs)
{
	return p_lhs.TickCount() < p_rhs.TickCount();
}

inline bool operator <= (const fs::DateTime& p_lhs, const fs::DateTime& p_rhs)
{
	return p_lhs.TickCount() <= p_rhs.TickCount();
}

inline bool operator > (const fs::DateTime& p_lhs, const fs::DateTime& p_rhs)
{
	return p_lhs.TickCount() > p_rhs.TickCount();
}

inline bool operator >= (const fs::DateTime& p_lhs, const fs::DateTime& p_rhs)
{
	return p_lhs.TickCount() >= p_rhs.TickCount();
}

inline bool operator != (const fs::DateTime& p_lhs, const fs::DateTime& p_rhs)
{
	return p_lhs.TickCount() != p_rhs.TickCount();
}

inline bool operator == (const fs::DateTime& p_lhs, const fs::DateTime& p_rhs)
{
	return p_lhs.TickCount() == p_rhs.TickCount();
}




//
// fs::DateTime::Span
//

inline bool operator < (const fs::DateTime::Span& p_lhs, const fs::DateTime::Span& p_rhs)
{
	return p_lhs.TickCount() < p_rhs.TickCount();
}

inline bool operator <= (const fs::DateTime::Span& p_lhs, const fs::DateTime::Span& p_rhs)
{
	return p_lhs.TickCount() <= p_rhs.TickCount();
}

inline bool operator > (const fs::DateTime::Span& p_lhs, const fs::DateTime::Span& p_rhs)
{
	return p_lhs.TickCount() > p_rhs.TickCount();
}

inline bool operator >= (const fs::DateTime::Span& p_lhs, const fs::DateTime::Span& p_rhs)
{
	return p_lhs.TickCount() >= p_rhs.TickCount();
}

inline bool operator != (const fs::DateTime::Span& p_lhs, const fs::DateTime::Span& p_rhs)
{
	return p_lhs.TickCount() != p_rhs.TickCount();
}

inline bool operator == (const fs::DateTime::Span& p_lhs, const fs::DateTime::Span& p_rhs)
{
	return p_lhs.TickCount() == p_rhs.TickCount();
}


//
// fs::DateTime::Epoch
//

inline bool operator < (const fs::DateTime::Epoch& p_lhs, const fs::DateTime::Epoch& p_rhs)
{
	return p_lhs.Count() < p_rhs.Count();
}

inline bool operator <= (const fs::DateTime::Epoch& p_lhs, const fs::DateTime::Epoch& p_rhs)
{
	return p_lhs.Count() <= p_rhs.Count();
}

inline bool operator > (const fs::DateTime::Epoch& p_lhs, const fs::DateTime::Epoch& p_rhs)
{
	return p_lhs.Count() > p_rhs.Count();
}

inline bool operator >= (const fs::DateTime::Epoch& p_lhs, const fs::DateTime::Epoch& p_rhs)
{
	return p_lhs.Count() >= p_rhs.Count();
}

inline bool operator != (const fs::DateTime::Epoch& p_lhs, const fs::DateTime::Epoch& p_rhs)
{
	return p_lhs.Count() != p_rhs.Count();
}

inline bool operator == (const fs::DateTime::Epoch& p_lhs, const fs::DateTime::Epoch& p_rhs)
{
	return p_lhs.Count() == p_rhs.Count();
}



namespace fs
{
	template <> class Layout<::fs::DateTime> : public ::fs::layout
	{
	public:
		Layout(::fs::Buffer p_buffer)
				: layout(p_buffer)
		{
		}

	public:
		::fs::qword *operator&()
		{
			return m_buffer.Data<::fs::qword>();
		}

		::fs::qword *operator->()
		{
			return m_buffer.Data<::fs::qword>();
		}

		::fs::qword& operator*()
		{
			return *m_buffer.Data<::fs::qword>();
		}
	};
}

namespace fs
{
	template <> class Layout<::fs::DateTime::Span> : public ::fs::layout
	{
	public:
		Layout(::fs::Buffer p_buffer)
				: layout(p_buffer)
		{
		}

	public:
		::fs::si64 *operator&()
		{
			return m_buffer.Data<::fs::si64>();
		}

		::fs::si64 *operator->()
		{
			return m_buffer.Data<::fs::si64>();
		}

		::fs::si64& operator*()
		{
			return *m_buffer.Data<::fs::si64>();
		}
	};
}


/* End Of File: DateTime.h */
