namespace fs
{
	template <class TypeList> class Tuple;

	template <class T, class U> class Tuple< fs::type::List<T, U> > : public Tuple<U>
	{
	public:
		typedef typename T Type;
	private:
		Type m_value;
	public:
		typedef ::fs::ui32 Index;
		typedef type::List<T, U> TypeList;
		typedef Tuple<U> RightTuple;
		typedef typename Tuple< type::List<T, U> > TupleType;

		typedef ::fs::Layout<TypeList> Layout;



		Type& Value()
		{
			return m_value;
		}

		const Type& Value() const
		{
			return m_value;
		}

		template <Index index>
				typename type::At<TypeList, index>::Result&
				Field()
		{
			typedef type::Rest<TypeList, index>::List TL;
			return Tuple<TL>::Value();
		}

		template <Index index>
				const typename type::At<TypeList, index>::Result&
				Field() const
		{
			typedef type::Rest<TypeList, index>::List TL;
			return Tuple<TL>::Value();
		}

		bool operator < (const TupleType & p_v) const
		{
			if (m_value < p_v.m_value)
			{
				return true;
			}
			if (m_value == p_v.m_value)
			{
				return RightTuple::operator <(p_v);
			}
			return false;
		}

		bool operator <= (const TupleType & p_v) const
		{
			if (m_value < p_v.m_value)
			{
				return true;
			}
			if (m_value == p_v.m_value)
			{
				return RightTuple::operator <=(p_v);
			}
			return false;
		}
		
		bool operator == (const TupleType& p_v) const
		{
			if (m_value == p_v.m_value)
			{
				return RightTuple::operator==(p_v);
			}
			return false;
		}

		bool operator != (const TupleType & p_v) const
		{
			if (m_value == p_v.m_value)
			{
				return RightTuple::operator !=(p_v);
			}

			return true;
		}

	};

	template <> class Tuple<type::Null>
	{
	public:
		typedef type::Null TypeList;
		typedef Tuple< type::Null > TupleType;

		typedef ::fs::Layout<TypeList> Layout;
		size_t Size() const
		{
			return 0;
		}

		bool operator < (const Tuple<type::Null> & p_v) const
		{
			return false;
		}

		bool operator <= (const Tuple<type::Null> & p_v) const
		{
			return true;
		}

		bool operator > (const Tuple<type::Null> & p_v) const
		{
			return false;
		}

		bool operator >= (const Tuple<type::Null> & p_v) const
		{
			return true;
		}

		bool operator == (const Tuple<type::Null> & p_v) const
		{
			return true;
		}

		bool operator != (const Tuple<type::Null> & p_v) const
		{
			return false;
		}
	};


	namespace internal
	{
		template <class T> 
				std::string format(const Tuple< fs::type::List<T, type::Null> >& p_value)
		{
			return fs::format(p_value.Value());
		}

		template <class T, class U> 
				std::string format(const Tuple< fs::type::List<T, U> >& p_value)
		{
			std::string s = fs::format(p_value.Value());
			s += ",";
			const Tuple< fs::type::List<T, U> >::RightTuple& rt = p_value;
			s += internal::format(rt);
			return s;
		}
	}

	template <class T, class U> 
			std::string format(const Tuple< fs::type::List<T, U> >& p_value)
	{
		auto s = ::fs::format("(", internal::format(p_value), ")");
		return s;
	}

	template <class T, class U>
	struct Traits<Tuple<type::List<T,U> > >
	{
		static const bool isFixedSize = Traits<type::List<T,U> >::isFixedSize;
	};
	
	template <class T, class U>
			struct Sizer<Tuple<type::List<T,U> > >
	{
		static const size_t Size = Sizer<type::List<T,U> >::Size;
	};


	template <>
			struct Traits<Tuple<type::Null > >
	{
		static const bool isFixedSize = true;
	};

	template <>
			struct Sizer<Tuple<type::Null > >
	{
		static const size_t Size = 0;
	};



	template <class T, class U>
	struct Type<Tuple<type::List<T,U> > >
	{
		static const fs::type::ID ID = fs::type::id::Tuple;
	};

	template <>
			struct Type<Tuple<type::Null > >
	{
		static const fs::type::ID ID = fs::type::id::Tuple;
	};
} /* namespace fs */

namespace fs
{
	template <class T> struct io< fs::Tuple<fs::type::List<T, fs::type::Null> > >
	{
		typedef fs::Tuple<fs::type::List<T, fs::type::Null> > TT;

		static const size_t FieldOffset = fs::type::Length<TT::TypeList>::value;
		static void put(BufferWriter& p_bw, typename fs::PT<TT>::T p_v)
		{
			io<T>::put(p_bw, p_v.Value());
		}

		static void get(BufferReader& p_br, TT *p_pV)
		{
			io<T>::get(p_br, &(p_pV->Value()));
		}
	};

	template <class T, class U> struct io< fs::Tuple<fs::type::List<T, U> > >
	{
		typedef fs::Tuple<fs::type::List<T, U> > TT;
		typedef fs::Tuple<U>                     UT;

		static void put(BufferWriter& p_bw, typename fs::PT<TT>::T p_v)
		{
			fs::PT<T>::T v = p_v.Value();
			io<T>::put(p_bw, v);

			io<UT>::put(p_bw, p_v);
		}

		static void get(BufferReader& p_br, TT *p_pV)
		{
			T* p = &(p_pV->Value());
			io<T>::get(p_br, p);

			io<UT>::get(p_br, p_pV);
		}
	};
}


/* End Of File: Tuple.h */
