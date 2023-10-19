namespace fs
{
	template <class TypeList, size_t ix> 
			::fs::Buffer Extract(const ::fs::Buffer& p_buffer)
	{
		typedef ::fs::type::At<TypeList, ix>::Result Type;
		const auto offset = ::fs::type::Offset<TypeList, ix>::Value;
		const auto size   = ::fs::Sizer<Type>::Size;

		auto buf = p_buffer.Reference(offset, size);

		return buf;
	}
}

namespace fs
{
	template <class TypeList, ::fs::si32 ix> 
			typename ::fs::type::At<TypeList, ix>::Result *PointerTo(const ::fs::Buffer& p_buffer)
	{
		typedef ::fs::type::At<TypeList, ix>::Result Type;

		auto buf = ::fs::Extract<TypeList, ix>(p_buffer);

		Type *p = buf.Data<Type>();

		return p;
	}
}

namespace fs
{
	class layout
	{
	protected:
		layout(::fs::Buffer p_buffer);
	protected:
		::fs::Buffer m_buffer;
	};
}


namespace fs
{
	template <class T> class Layout;
}


namespace fs
{

	template <class T, class U> class Layout<::fs::type::List<T, U> >
	{
	public:
		typedef ::fs::type::List<T, U> TypeList;
	public:
		Layout(::fs::Buffer p_buffer)
				: m_buffer(p_buffer)
		{
		}

	private:
		::fs::Buffer m_buffer;

	public:
		template <size_t index> ::fs::Layout<typename ::fs::type::At<TypeList, index>::Result> Field()
		{
			typedef ::fs::type::At<TypeList, index>::Result TypeOf;
			
			auto buf = ::fs::Extract<TypeList, index>(m_buffer);
			
			return ::fs::Layout<TypeOf>(buf);
		}

		template <size_t index> const ::fs::Layout<typename ::fs::type::At<TypeList, index>::Result> Field() const
		{
			typedef ::fs::type::At<TypeList, index>::Result TypeOf;

			auto buf = ::fs::Extract<TypeList, index>(m_buffer);

			return ::fs::Layout<TypeOf>(buf);
		}
	};
}

namespace fs
{
	template <> class Layout<::fs::type::Null> : public layout
	{
	public:
		Layout(::fs::Buffer p_buffer)
				: layout(p_buffer)
		{
		}
	public:
	};
}

namespace fs
{
	template <> class Layout<::fs::byte> : public layout
	{
	public:
		Layout(::fs::Buffer p_buffer);

		::fs::byte *operator&();
		::fs::byte *operator->();
		::fs::byte& operator*();
	};
}

namespace fs
{
	template <> class Layout<::fs::word> : public layout
	{
	public:
		Layout(::fs::Buffer p_buffer);

		::fs::word *operator&();
		::fs::word *operator->();
		::fs::word& operator*();
	};
}

namespace fs
{
	template <> class Layout<::fs::dword> : public layout
	{
	public:
		Layout(::fs::Buffer p_buffer);

		::fs::dword *operator&();
		::fs::dword *operator->();
		::fs::dword& operator*();
		const ::fs::dword& operator*() const;
	};
}

namespace fs
{
	template <> class Layout<::fs::qword> : public layout
	{
	public:
		Layout(::fs::Buffer p_buffer);

		::fs::qword *operator&();
		::fs::qword *operator->();
		::fs::qword& operator*();
	};
}





namespace fs
{
	template <> class Layout<::fs::si8> : public layout
	{
	public:
		Layout(::fs::Buffer p_buffer);

		::fs::si8 *operator&();
		::fs::si8 *operator->();
		::fs::si8& operator*();
	};
}

namespace fs
{
	template <> class Layout<::fs::si16> : public layout
	{
	public:
		Layout(::fs::Buffer p_buffer);

		::fs::si16 *operator&();
		::fs::si16 *operator->();
		::fs::si16& operator*();
	};
}

namespace fs
{
	template <> class Layout<::fs::si32> : public layout
	{
	public:
		Layout(::fs::Buffer p_buffer);

		::fs::si32 *operator&();
		::fs::si32 *operator->();
		::fs::si32& operator*();
	};
}

namespace fs
{
	template <> class Layout<::fs::si64> : public layout
	{
	public:
		Layout(::fs::Buffer p_buffer);

		::fs::si64 *operator&();
		::fs::si64 *operator->();
		::fs::si64& operator*();
	};
}

namespace fs
{
	template <> class Layout<::fs::Double> : public layout
	{
	public:
		Layout(::fs::Buffer p_buffer);

		::fs::Double *operator&();
		::fs::Double *operator->();
		::fs::Double& operator*();
	};
}

namespace fs
{
	template <> class Layout<bool> : public layout
	{
	public:
		Layout(::fs::Buffer p_buffer);

		::fs::byte *operator&();
		::fs::byte *operator->();
		::fs::byte& operator*();
	};
}



