namespace fs
{
	struct Time
	{
		fs::dword m_tickCount; // milliseconds 1kHz.

	public:
		inline fs::dword TickCount() const
		{
			return m_tickCount;
		}

		
		inline Time(fs::dword p_tickCount = 0)
				: m_tickCount(p_tickCount)
		{
		}

		Time(fs::dword p_hours, fs::dword p_minutes, fs::dword p_seconds = 0, fs::dword p_ms = 0);

		void Crack(fs::dword *p_pHours, fs::dword *p_pMinutes, fs::dword *p_pSeconds, fs::dword *p_pms) const;

		struct Span
		{
			fs::si32 m_ticks;

		public:
			inline Span() {}
			inline Span(fs::si32 p_ticks)
			: m_ticks(p_ticks)
			{
			}

			inline fs::si32 TickCount() const
			{
				return m_ticks;
			}


			inline Span& operator *= (dword p_scalar)
			{
				m_ticks *= p_scalar;
				return *this;
			}

			inline Span& operator /= (dword p_scalar)
			{
				m_ticks /= p_scalar;
				return *this;
			}

			inline Span operator -()
			{
				return Span(-m_ticks);
			}

		public:
			Span abs() const;
		};

		Time LowerBound(Span p_span) const;
		Time UpperBound(Span p_span) const;

		inline Time& operator +=(Span p_span)
		{
			m_tickCount += p_span.m_ticks;
			return *this;
		}

		inline Time& operator -= (Span p_span)
		{
			m_tickCount -= p_span.m_ticks;
			return *this;
		}

		static const Span DaySpan;
	};

	Time::Span operator - (fs::Time p_lhs, fs::Time p_rhs);

	inline Time operator + (fs::Time p_time, fs::Time::Span p_span)
	{
		Time time = p_time;
		time += p_span;
		return time;
	}

	inline Time operator + (fs::Time::Span p_span, fs::Time p_time)
	{
		Time time = p_time;
		time += p_span;
		return time;
	}



	Time::Span operator + (const Time::Span& p_a, const Time::Span& p_b);

	inline Time::Span operator * (const Time::Span& p_a, fs::dword p_scalar)
	{
		Time::Span span = p_a;
		span *= p_scalar;
		return span;
	}

	inline Time::Span operator * (fs::dword p_scalar, const Time::Span& p_a)
	{
		Time::Span span = p_a;
		span *= p_scalar;
		return span;
	}


	fs::dword operator / (const Time::Span& p_a, const Time::Span& p_b);

	Time::Span Hours(::fs::si32 p_nHours);
	Time::Span Minutes(::fs::si32 p_nMinutes);
	Time::Span Seconds(::fs::si32 p_nSeconds);
	Time::Span MilliSeconds(::fs::si32 p_nms);

	// Time::Span interval = Hours(10) + Minutes(33) + Seconds(1);

	inline Time::Span abs(const ::fs::Time::Span& p_span)
	{
		return p_span.abs();
	}

	fs::dword PeriodsPer(fs::Time::Span p_period, fs::Time::Span p_total);

	std::string format(const fs::Time& p_time);

	template <> struct Traits<Time>
	{
		static const bool isFixedSize = true;
	};

	template <> struct Sizer<Time>
	{
		static const size_t Size = sizeof(Time);
	};


	bool Convert(const std::string& p_s, Time *p_pTime);
	bool convert(const char *p_ps, Time *p_pTime);
	bool Convert(const std::string& p_s, fs::Time::Span *p_pInterval);

	template <> struct Type<fs::Time>
	{
		static const fs::type::ID ID = fs::type::id::Time;
	};





	template <> struct Traits<Time::Span>
	{
		static const bool isFixedSize = true;
	};

	template <> struct Sizer<Time::Span>
	{
		static const size_t Size = sizeof(Time::Span);
	};


	inline void Load(fs::Buffer p_from, fs::Time::Span *p_pTo)
	{
		fs::dword *p = p_from.Data<fs::dword>();
		*p_pTo = Time::Span(*p);
	}

	inline void Store(fs::Time::Span p_from, fs::Buffer *p_pTo)
	{
		fs::dword *p = p_pTo->Data<fs::dword>();
		*p = p_from.TickCount();
	}


	template <> struct Type<fs::Time::Span>
	{
		static const fs::type::ID ID = fs::type::id::Time_Span;
	};

	template<> struct io<Time>
	{
		static inline void put(BufferWriter& p_bw, fs::PT<Time>::T p_v)
		{
			p_bw.put(p_v.TickCount());
		}
		static inline void get(BufferReader& p_br, Time *p_pV)
		{
			fs::dword dw;
			p_br.get(&dw);
			*p_pV = fs::Time(dw);
		}
	};

	template<> struct io<Time::Span>
	{
		static inline void put(BufferWriter& p_bw, fs::PT<Time::Span>::T p_v)
		{
			p_bw.put(p_v.TickCount());
		}
		static inline void get(BufferReader& p_br, Time::Span *p_pV)
		{
			fs::dword dw;
			p_br.get(&dw);
			*p_pV = fs::Time::Span(dw);
		}
	};

	double ExcelTime(fs::Time p_tm);
}


inline bool operator == (const fs::Time& p_lhs, const fs::Time& p_rhs)
{
	return p_lhs.m_tickCount == p_rhs.m_tickCount;
}
inline bool operator != (const fs::Time& p_lhs, const fs::Time& p_rhs)
{
	return p_lhs.m_tickCount != p_rhs.m_tickCount;
}

inline bool operator > (const fs::Time& p_lhs, const fs::Time& p_rhs)
{
	return p_lhs.m_tickCount > p_rhs.m_tickCount;
}

inline bool operator >= (const fs::Time& p_lhs, const fs::Time& p_rhs)
{
	return p_lhs.m_tickCount >= p_rhs.m_tickCount;
}

inline bool operator <(const fs::Time& p_lhs, const fs::Time& p_rhs)
{
	return p_lhs.m_tickCount < p_rhs.m_tickCount;
}
inline bool operator <=(const fs::Time& p_lhs, const fs::Time& p_rhs)
{
	return p_lhs.m_tickCount <= p_rhs.m_tickCount;
}

inline fs::Time::Span operator - (fs::Time::Span p_l, fs::Time::Span p_r)
{
	fs::Time::Span diff = p_l.TickCount() - p_r.TickCount();

	return diff;
}

namespace fs
{
	template <> struct add<fs::Time, fs::Time::Span> : public binary_op<fs::Time, fs::Time::Span, fs::Time>
	{
	public:
		inline fs::Time operator() (fs::PT<fs::Time>::T p_time, fs::PT<fs::Time::Span>::T p_span)
		{
			fs::Time r = p_time;
			r += p_span;

			return r;
		}
	};
}


namespace fs
{
	template <> class Layout<::fs::Time> : public ::fs::layout
	{
	public:
		Layout(::fs::Buffer p_buffer)
				: layout(p_buffer)
		{
		}

	public:
		::fs::dword *operator&()
		{
			return m_buffer.Data<::fs::dword>();
		}

		::fs::dword *operator->()
		{
			return m_buffer.Data<::fs::dword>();
		}

		::fs::dword& operator*()
		{
			return *m_buffer.Data<::fs::dword>();
		}
	};
}

namespace fs
{
	template <> class Layout<::fs::Time::Span> : public ::fs::layout
	{
	public:
		Layout(::fs::Buffer p_buffer)
				: layout(p_buffer)
		{
		}

	public:
		::fs::si32 *operator&()
		{
			return m_buffer.Data<::fs::si32>();
		}

		::fs::si32 *operator->()
		{
			return m_buffer.Data<::fs::si32>();
		}

		::fs::si32& operator*()
		{
			return *m_buffer.Data<::fs::si32>();
		}
	};
}

/* End of File: fsTime.h */
