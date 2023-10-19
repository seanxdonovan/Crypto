namespace fs
{
	template <size_t size>
	struct StringFixed
	{
	public:
		static const size_t Size = size;
		const char *c_str() const
		{
			return (const char *) data;
		}

		char *str()
		{
			return (char *) data;
		}

		StringFixed& operator = (const StringFixed& p_rhs)
		{
			for (size_t ix = 0; ix < size; ++ix)
			{
				data[ix] = p_rhs.data[ix];
			}

			return *this;
		}

		void operator = (const std::string& p_s)
		{
			size_t ix = 0;
			while (ix < Size && ix < p_s.length())
			{
				data[ix] = p_s[ix];
				++ix;
			}
			while (ix < Size)
			{
				data[ix] = 0;
				++ix;
			}
		}

		void operator = (const char *p_pS)
		{
			size_t ix = 0;
			while (ix < Size && 0 != p_pS[ix])
			{
				data[ix] = p_pS[ix];
				++ix;
			}
			while (ix < Size)
			{
				data[ix] = 0;
				++ix;
			}
		}

		StringFixed()
		{
#if !defined(NDEBUG)
			for(size_t ix = 0; ix < size - 1; ++ix)
			{
				data[ix] = 'X';
			}
#endif
		}

		StringFixed(const char *p_pS)
		{
			size_t ix = 0;
			while (ix < Size && 0 != p_pS[ix])
			{
				data[ix] = p_pS[ix];
				++ix;
			}
			while (ix < Size)
			{
				data[ix] = 0;
				++ix;
			}
		}

		StringFixed(const std::string& p_s)
		{
			size_t ix = 0;
			while (ix < Size && ix < p_s.length())
			{
				data[ix] = p_s[ix];
				++ix;
			}
			while (ix < Size)
			{
				data[ix] = 0;
				++ix;
			}
		}

		inline Buffer Buffer()
		{
			return fs::Buffer((fs::byte *)data, Size);
		}

		inline const fs::Buffer Buffer() const
		{
			return fs::Buffer((fs::byte *)data, Size);
		}

		inline const byte operator [] (size_t p_ix) const
		{
			return data[p_ix];
		}

		inline byte& operator [] (size_t p_ix)
		{
			return data[p_ix];
		}
	private:
		byte data[Size];
	};


	template <size_t size>
			struct Traits<StringFixed<size> >
	{
		static const bool isFixedSize = true;
		static const size_t Size = StringFixed<size>::Size;
	};

	template <size_t size> struct Sizer<StringFixed<size> >
	{
		static const size_t Size = size;
	};

	template <size_t size>
			std::string format(const StringFixed<size>& p_s)
	{
#if 0
		size_t l = size;
		while (l > 0 && p_s[l - 1] == 0)
		{
			--l;
		}

		return std::string(p_s.c_str(), l);
#else
		std::string s;
		s.reserve(size);

		size_t l = 0;
		while (l < size && p_s[l] != 0)
		{
			s += p_s[l];
			++l;
		}

		return s;
#endif
	}

	template <size_t size> inline
			bool Convert(const std::string& p_s, StringFixed<size> *p_pValue)
	{
		if (p_s.length() <= size)
		{
			*p_pValue = p_s;
			return true;
		}
		return false;
	}

	template <size_t size> struct Type<StringFixed<size> >
	{
		static const fs::type::ID ID = fs::type::id::StringFixed | (size << 8);
	};


	template <size_t size> struct io<StringFixed<size> >
	{
	public:
		typedef StringFixed<size> SF;
	public:
		static void get(BufferReader& p_br, SF *p_pSF)
		{
			fs::Buffer b = p_br.Next(size);
			fs::FastCopy(b, &(p_pSF->Buffer()));
		}

		static void put(BufferWriter& p_bw, const SF& p_sf)
		{
			p_bw.put(p_sf.Buffer());
		}
	};

} /* namespace fs */

namespace fs
{
	template <size_t StringSize> void Copy(const ::std::string& p_sFrom, ::fs::StringFixed<StringSize> *p_psTo, char p_fill = ' ')
	{
		size_t ix = 0;
		while (ix < StringSize && ix < p_sFrom.length())
		{
			(*p_psTo)[ix] = p_sFrom[ix];
			++ix;
		}
		while (ix < StringSize)
		{
			(*p_psTo)[ix] = p_fill;
			++ix;
		}
	}
}



template <size_t size>
bool operator < (const fs::StringFixed<size>& p_lhs, const fs::StringFixed<size>& p_rhs)
{
	return strncmp(p_lhs.c_str(), p_rhs.c_str(), size) < 0;
}

#if 0
namespace std
{
	template <size_t size>
			bool operator < (const fs::StringFixed<size>& p_lhs, const fs::StringFixed<size>& p_rhs)
	{
		return strncmp(p_lhs.c_str(), p_rhs.c_str(), size) < 0;
	}
}
#endif

template <size_t size>
bool operator == (const fs::StringFixed<size>& p_lhs, const fs::StringFixed<size>& p_rhs)
{
	return strncmp(p_lhs.c_str(), p_rhs.c_str(), size) == 0;
}

template <size_t size>
bool operator != (const fs::StringFixed<size>& p_lhs, const fs::StringFixed<size>& p_rhs)
{
	return strncmp(p_lhs.c_str(), p_rhs.c_str(), size) != 0;
}



namespace fs
{
	template <size_t size> struct Layout<StringFixed<size> > : layout
	{
	public:
		typedef StringFixed<size> SF;
	public:
		Layout(::fs::Buffer p_buffer)
			: layout(p_buffer)
		{
		}
		
		SF *operator&()
		{
			return m_buffer.Data<SF>();
		}

		SF *operator->()
		{
			return m_buffer.Data<SF>();
		}

		SF& operator*()
		{
			return *m_buffer.Data<SF>();
		}
	
	};
}



/* End Of File: StringFixed.h */
