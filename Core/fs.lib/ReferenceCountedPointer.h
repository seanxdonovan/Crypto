
namespace fs
{
	template <class T>
	class ReferenceCountedPointer
	{
		struct Payload
		{
			dword m_referenceCount;
			T* m_pointee;
		} *m_pPayload;

		inline void i_decrementReferenceCount()
		{
			sPrecondition(0 != m_pPayload);
			InterlockedDecrement((LONG *)&(m_pPayload->m_referenceCount));
		}

		inline void i_incrementReferenceCount()
		{
			sPrecondition(0 != m_pPayload);
			InterlockedIncrement((LONG *)&(m_pPayload->m_referenceCount));
		}

		inline void i_initialize(T *p_pointee)
		{
			sPrecondition(0 == m_pPayload);
			m_pPayload = new Payload;
			m_pPayload->m_referenceCount = 1;
			m_pPayload->m_pointee = p_pointee;
		}

		inline void i_maybeDestroy()
		{
			sPrecondition(0 != m_pPayload);
			fs::dword rc = (fs::dword) InterlockedCompareExchange((LONG *)&m_pPayload->m_referenceCount, 0, 0);
			if (0 == rc)
			{
				T* p = (T*) InterlockedCompareExchangePointer((PVOID *)&m_pPayload->m_pointee, 0, m_pPayload->m_pointee);
				delete p;

				Payload *pPayload = (Payload *)InterlockedCompareExchangePointer((PVOID *)&m_pPayload, 0, m_pPayload);
				delete pPayload;
			}
		}

	public:
		inline ReferenceCountedPointer()
		  : m_pPayload(0)
		{
			i_initialize(0);
		}

		inline explicit ReferenceCountedPointer(T* p_pointee)
		: m_pPayload(0)
		{
			i_initialize(p_pointee);
		}

		inline ~ReferenceCountedPointer()
		{
			i_decrementReferenceCount();
			i_maybeDestroy();
		}

		inline ReferenceCountedPointer(const ReferenceCountedPointer& p_rhs)
  		  : m_pPayload(p_rhs.m_pPayload)
		{
			i_incrementReferenceCount();
		}

		inline ReferenceCountedPointer& operator=(const ReferenceCountedPointer& p_rhs)
		{
			i_decrementReferenceCount();
			i_maybeDestroy();

			m_pPayload = p_rhs.m_pPayload;

			i_incrementReferenceCount();

			return *this;
		}

		inline T *operator->() const
		{
			sAssert(0 != m_pPayload);

			return m_pPayload->m_pointee;
		}

		inline T& operator*() const
		{
			sAssert(0 != m_pPayload);

			return *(m_pPayload->m_pointee);
		}

		inline bool IsNull() const
		{
			return (0 == m_pPayload) || (0 == m_pPayload->m_pointee);
		}

		inline bool IsNotNull() const
		{
			return (0 != m_pPayload) && (0 != m_pPayload->m_pointee);
		}

		inline fs::dword Count() const
		{
			if (0 == m_pPayload)
			{
				return 0;
			}

			return m_pPayload->m_referenceCount;
		}

		template <class To> 
			inline To* As()
		{
			auto *p = static_cast<To*>(operator->());
			return p;
		}

		template <class To> 
			inline To* As() const
		{
			auto *p = static_cast<To*>(operator->());
			return p;
		}

		void Release()
		{
			i_decrementReferenceCount();
			i_maybeDestroy();

			m_pPayload = 0;
			i_initialize(0);
		}

		inline const T* Pointee() const
		{
			sPrecondition(0 != m_pPayload);
			return m_pPayload->m_pointee;
		}

		inline T* Pointee()
		{
			sPrecondition(0 != m_pPayload);
			return m_pPayload->m_pointee;
		}

	public:
		typedef T Type;

	public:
		typedef ::fs::type::List<T, ::fs::type::Null> TypeList;

	public:
		template <class D> bool IsKindOf() const
		{
			if (IsNull())
			{
				return false;
			}

			Type *pB = m_pPayload->m_pointee;
			D    *pD = dynamic_cast<D *>(pB);

			return (0 != pD);
		}
	};

	template <class T> inline bool IsNull(const ReferenceCountedPointer<T>& p_p)
	{
		return p_p.IsNull();
	}

} /* namespace fs */

	template <class T>
	inline bool operator == (const fs::ReferenceCountedPointer<T>& p_pLHS, const fs::ReferenceCountedPointer<T>& p_pRHS)
	{
		return p_pLHS.Pointee() == p_pRHS.Pointee();
	}

	template <class T>
			inline bool operator != (const fs::ReferenceCountedPointer<T>& p_pLHS, const fs::ReferenceCountedPointer<T>& p_pRHS)
	{
		return p_pLHS.Pointee() != p_pRHS.Pointee();
	}

	template <class T>
			inline bool operator < (const fs::ReferenceCountedPointer<T>& p_pLHS, const fs::ReferenceCountedPointer<T>& p_pRHS)
	{
		return p_pLHS.Pointee() < p_pRHS.Pointee();
	}

/* End Of File: ReferenceCountedPointer.h */
