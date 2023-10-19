namespace fs
{
	template <class To, class From> struct Co
	{
	public:

		To operator () (From p_pFrom);
	};

	template <class To> struct Co<To, To>
	{
	public:
		To operator() (typename To p)
		{
			return p;
		}
	};

#if 0
			{
			To::RCPB p_pParent = Co<To::RCPB, From>() (p_pFrom);

			return (p_pParent);
		}
#endif
	template <class To, class From> To Co<To, From>::operator () (From p_pFrom)
	{
		To::RCPB p_pParent = Co<To::RCPB, From>() (p_pFrom);
		
		return To(p_pParent);
	}
}



namespace fs
{
	template <class Derived, class BaseRCP>
	class ReferenceCountedPointerDerived : public BaseRCP
	{
	public:
		typedef BaseRCP RCPB;
		typedef ReferenceCountedPointerDerived RCPD;
		typedef typename BaseRCP::Type TypeB;
		typedef Derived       TypeD;
		typedef Derived       Type;

	public:
		typedef ::fs::type::List<Type, typename BaseRCP::TypeList> TypeList;

	public:
		inline ReferenceCountedPointerDerived()
				: BaseRCP()
		{
		}

		inline explicit ReferenceCountedPointerDerived(TypeD* p_p)
				: BaseRCP(p_p)
		{
		}

		inline explicit ReferenceCountedPointerDerived(const RCPB& p_p)
				: BaseRCP(p_p)
		{
		}

		inline ReferenceCountedPointerDerived(const ReferenceCountedPointerDerived& p_p)
				: BaseRCP(p_p)
		{
		}

		/*
		inline explicit ReferenceCountedPointerDerived(const ReferenceCountedPointer<Type>& p_p)
				: BaseRCP(p_p)
		{
			Type *p = p_p.operator->();
			TypeD *pD = dynamic_cast<TypeD*>(p); // dynamic_cast is required for vbc.
			sAssert(0 != pD);
		}
		*/
		inline TypeD *operator->() const
		{
#if defined(NDEBUG)
			return As<TypeD>();
#else
			TypeB *p = RCPB::operator->();
			TypeD *pD = dynamic_cast<TypeD*>(p); // dynamic_cast is required for vbc.
			sAssert(0 != pD);

			return pD;
#endif
		}

		inline TypeD& operator*() const
		{
			TypeB& b = RCPB::operator*();
			TypeD& d = static_cast<TypeD&>(b);

			return d;
		}

		inline const TypeD* Pointee() const
		{
			const TypeB *p = RCPB::Pointee();
			const TypeD *pD = dynamic_cast<const TypeD*>(p); // dynamic_cast is required for vbc.

			return pD;
		}

		inline TypeD* Pointee()
		{
			TypeB *p = RCPB::Pointee();
			TypeD *pD = dynamic_cast<TypeD*>(p); // dynamic_cast is required for vbc.

			return pD;
		}
	};

	template <class Derived, class BaseRCP> inline bool IsNull(const ReferenceCountedPointerDerived<Derived, BaseRCP>& p_p)
	{
		return p_p.IsNull();
	}
}


//
// pDerived = fs::Coerce<RCPT1, RCPT2>()(pBase);
//
// Casting down from a RCP of Base to a RCP of Derived where Base is a
// superclass of Derived and there may be other superclasses between
// Derived and Base
//

namespace fs
{
	template <class B, class D>
			struct Coerce< fs::ReferenceCountedPointer<B> ,
		  fs::ReferenceCountedPointerDerived<D, fs::ReferenceCountedPointer<B> >
		  >
	{
		typedef fs::ReferenceCountedPointer<B> RCPB;
		typedef fs::ReferenceCountedPointerDerived<D, fs::ReferenceCountedPointer<B> > RCPD;

		RCPD operator() (typename fs::PT<RCPB>::T p_p)
		{
			RCPD p = RCPD(p_p);

			return p;
		}
	};

	template <class B, class D, class RCPDB>
			struct Coerce< fs::ReferenceCountedPointer<B> ,
		  fs::ReferenceCountedPointerDerived<D, RCPDB >
		  >
	{
		typedef fs::ReferenceCountedPointer<B> RCPB;
		typedef fs::ReferenceCountedPointerDerived<D, RCPDB > RCPD;

		RCPD operator() (typename fs::PT<RCPB>::T p_p)
		{
			RCPDB pB = Coerce<RCPB, RCPDB>()(p_p);

			RCPD p(pB);

			return p;
		}
	};


	template <class RCPB1, class D1, class RCPB2, class D2>
			struct Coerce< fs::ReferenceCountedPointerDerived<D1, RCPB1 > ,
		  fs::ReferenceCountedPointerDerived<D2, RCPB2 >
		  >
	{
		typedef fs::ReferenceCountedPointerDerived<D1, RCPB1 > RCPD1;
		typedef fs::ReferenceCountedPointerDerived<D2, RCPB2 > RCPD2;

		RCPD2 operator() (typename fs::PT<RCPD1>::T p_p)
		{
			RCPB2 pBase = Coerce<RCPD1, RCPB2>(p_p);
			RCPD2 p(pBase);// = c(p_p);

			return p;
		}
	};
}
