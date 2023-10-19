
namespace fs
{

	template <class Delegate, class Mutex = NoLock>
	class Notifier
	{
	public:
		typedef Delegate Functor;
		typedef typename Delegate::Parameter1  P1;
		typedef typename Delegate::Parameter2  P2;
		typedef typename Delegate::Parameter3  P3;
		typedef typename Delegate::Parameter4  P4;
		typedef typename Delegate::Parameter5  P5;
		typedef typename Delegate::Parameter6  P6;
		typedef typename Delegate::Parameter7  P7;
		typedef typename Delegate::Parameter8  P8;
		typedef typename Delegate::Parameter9  P9;
		typedef typename Delegate::Parameter10 P10;
		typedef typename Delegate::Parameter11 P11;
		typedef typename Delegate::Parameter12 P12;
		typedef typename Delegate::Parameter13 P13;
		typedef typename Delegate::Parameter14 P14;
		typedef typename Delegate::Parameter15 P15;
		typedef typename Delegate::Parameter16 P16;
		typedef typename Delegate::Parameter17 P17;
		typedef typename Delegate::Parameter18 P18;
		typedef typename Delegate::Parameter19 P19;
		typedef typename Delegate::Parameter20 P20;

		typedef size_t handle;
		static const handle handle_invalid = fs::Traits<handle>::Maximum;
	private:

		typedef std::vector<Delegate> LNI;
		typedef fs::ReferenceCountedPointer<LNI> LNIRCP;
		LNIRCP m_pNotifications;

		Mutex m_mutex;
	public:
		Notifier()
		{
			m_pNotifications = LNIRCP(new LNI);
		}

		handle Subscribe(const Delegate& p_notify)
		{
			Mutex::Locker l(m_mutex);

			LNI& lni = *m_pNotifications;
			for (size_t ix = 0; ix < lni.size(); ++ix)
			{
				if (lni[ix].IsNull())
				{
					lni[ix] = p_notify;
					return ix;
				}
			}

			handle h = lni.size();

			lni.push_back(p_notify);

			return h;
		}

		void Unsubscribe(handle p_h)
		{
			Mutex::Locker l(m_mutex);

			LNI& lni = *m_pNotifications;
			lni[p_h] = Delegate();
		}

		void Clear()
		{
			Mutex::Locker l(m_mutex);

			m_pNotifications->clear();
		}


		class Subscriber
		{
		private:
			Notifier& m_notifier;
			typename Notifier::handle m_hNotify;
		public:
			inline Subscriber(Notifier& p_notifier, const Delegate& p_notify)
					: m_notifier(p_notifier)
			{
				m_hNotify = m_notifier.Subscribe(p_notify);
			}

			inline ~Subscriber()
			{
				m_notifier.Unsubscribe(m_hNotify);
			}

			typedef ReferenceCountedPointer<Subscriber> RCP;

			static RCP Make(Notifier& p_notifier, const Delegate& p_notify)
			{
				return RCP(new Subscriber(p_notifier, p_notify));
			}

			bool operator < (const Subscriber p_rhs)
			{
				return m_hNotify < p_rhs.m_hNotify;
			}

		private:
			Subscriber(const Subscriber&); // Not implmented
			Subscriber& operator = (const Subscriber&); // Not implmented
		};

		void operator () ()
		{
			Mutex::Locker l(m_mutex);
			LNIRCP pNotify = m_pNotifications;
			LNI::iterator it = pNotify->begin();
			while (it != pNotify->end())
			{
				if (!it->IsNull())
				(*it)();
				++it;
			}
		}

		void operator () (P1 p_1)
		{
			Mutex::Locker l(m_mutex);
			LNIRCP pNotify = m_pNotifications;


			LNI& lni = *pNotify;
			for (size_t ix = 0; ix < lni.size(); ++ix)
			{
				if (!lni[ix].IsNull())
				{
					lni[ix](p_1);
				}
			}
/*

			LNI::iterator it = pNotify->begin();
			while (it != pNotify->end())
			{
				if (!it->IsNull())
				(*it)(p_1);
				++it;
			}
*/
		}

		void operator () (P1 p_1, P2 p_2)
		{
			Mutex::Locker l(m_mutex);
			LNIRCP pNotify = m_pNotifications;
			LNI::iterator it = pNotify->begin();
			while (it != pNotify->end())
			{
				if (!it->IsNull())
				(*it)(p_1, p_2);
				++it;
			}
		}

		void operator () (P1 p_1, P2 p_2, P3 p_3)
		{
			Mutex::Locker l(m_mutex);
			LNIRCP pNotify = m_pNotifications;
			LNI::iterator it = pNotify->begin();
			while (it != pNotify->end())
			{
				if (!it->IsNull())
				(*it)(p_1, p_2, p_3);
				++it;
			}
		}

		void operator () (P1 p_1, P2 p_2, P3 p_3, P4 p_4)
		{
			Mutex::Locker l(m_mutex);
			LNIRCP pNotify = m_pNotifications;
			LNI::iterator it = pNotify->begin();
			while (it != pNotify->end())
			{
				if (!it->IsNull())
				(*it)(p_1, p_2, p_3, p_4);
				++it;
			}
		}

		void operator () (P1 p_1, P2 p_2, P3 p_3, P4 p_4, P5 p_5)
		{
			Mutex::Locker l(m_mutex);
			LNIRCP pNotify = m_pNotifications;
			LNI::iterator it = pNotify->begin();
			while (it != pNotify->end())
			{
				if (!it->IsNull())
				{
					(*it)(p_1, p_2, p_3, p_4, p_5);
				}
				++it;
			}
		}

		void operator () (P1 p_1, P2 p_2, P3 p_3, P4 p_4, P5 p_5, P6 p_6)
		{
			Mutex::Locker l(m_mutex);
			LNIRCP pNotify = m_pNotifications;
			LNI::iterator it = pNotify->begin();
			while (it != pNotify->end())
			{
				if (!it->IsNull())
				(*it)(p_1, p_2, p_3, p_4, p_5, p_6);
				++it;
			}
		}

		void operator () (P1 p_1, P2 p_2, P3 p_3, P4 p_4, P5 p_5, P6 p_6, P7 p_7)
		{
			Mutex::Locker l(m_mutex);
			LNIRCP pNotify = m_pNotifications;
			LNI::iterator it = pNotify->begin();
			while (it != pNotify->end())
			{
				if (!it->IsNull())
				(*it)(p_1, p_2, p_3, p_4, p_5, p_6, p_7);
				++it;
			}
		}

		void operator () (P1 p_1, P2 p_2, P3 p_3, P4 p_4, P5 p_5, P6 p_6, P7 p_7, P8 p_8)
		{
			Mutex::Locker l(m_mutex);
			LNIRCP pNotify = m_pNotifications;
			LNI::iterator it = pNotify->begin();
			while (it != pNotify->end())
			{
				if (!it->IsNull())
				(*it)(p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8);
				++it;
			}
		}

		void operator () (P1 p_1, P2 p_2, P3 p_3, P4 p_4, P5 p_5, P6 p_6, P7 p_7, P8 p_8, P9 p_9)
		{
			Mutex::Locker l(m_mutex);
			LNIRCP pNotify = m_pNotifications;
			LNI::iterator it = pNotify->begin();
			while (it != pNotify->end())
			{
				if (!it->IsNull())
				(*it)(p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9);
				++it;
			}
		}

		void operator () (P1 p_1, P2 p_2, P3 p_3, P4 p_4, P5 p_5, P6 p_6, P7 p_7, P8 p_8, P9 p_9, P10 p_10)
		{
			Mutex::Locker l(m_mutex);
			LNIRCP pNotify = m_pNotifications;
			LNI::iterator it = pNotify->begin();
			while (it != pNotify->end())
			{
				if (!it->IsNull())
				(*it)(p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10);
				++it;
			}
		}

		void operator () (P1 p_1, P2 p_2, P3 p_3, P4 p_4, P5 p_5, P6 p_6, P7 p_7, P8 p_8, P9 p_9, P10 p_10, P11 p_11)
		{
			Mutex::Locker l(m_mutex);
			LNIRCP pNotify = m_pNotifications;
			LNI::iterator it = pNotify->begin();
			while (it != pNotify->end())
			{
				if (!it->IsNull())
				(*it)(p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11);
				++it;
			}
		}

		void operator () (P1 p_1, P2 p_2, P3 p_3, P4 p_4, P5 p_5, P6 p_6, P7 p_7, P8 p_8, P9 p_9, P10 p_10, P11 p_11, P12 p_12)
		{
			Mutex::Locker l(m_mutex);
			LNIRCP pNotify = m_pNotifications;
			LNI::iterator it = pNotify->begin();
			while (it != pNotify->end())
			{
				if (!it->IsNull())
				(*it)(p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12);
				++it;
			}
		}

		void operator () (P1 p_1, P2 p_2, P3 p_3, P4 p_4, P5 p_5, P6 p_6, P7 p_7, P8 p_8, P9 p_9, P10 p_10, P11 p_11, P12 p_12, P13 p_13)
		{
			Mutex::Locker l(m_mutex);
			LNIRCP pNotify = m_pNotifications;
			LNI::iterator it = pNotify->begin();
			while (it != pNotify->end())
			{
				if (!it->IsNull())
				(*it)(p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13);
				++it;
			}
		}

		void operator () (P1 p_1, P2 p_2, P3 p_3, P4 p_4, P5 p_5, P6 p_6, P7 p_7, P8 p_8, P9 p_9, P10 p_10, P11 p_11, P12 p_12, P13 p_13, P14 p_14)
		{
			Mutex::Locker l(m_mutex);
			LNIRCP pNotify = m_pNotifications;
			LNI::iterator it = pNotify->begin();
			while (it != pNotify->end())
			{
				if (!it->IsNull())
				(*it)(p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13, p_14);
				++it;
			}
		}

		void operator () (P1 p_1, P2 p_2, P3 p_3, P4 p_4, P5 p_5, P6 p_6, P7 p_7, P8 p_8, P9 p_9, P10 p_10, P11 p_11, P12 p_12, P13 p_13, P14 p_14, P15 p_15)
		{
			Mutex::Locker l(m_mutex);
			LNIRCP pNotify = m_pNotifications;
			LNI::iterator it = pNotify->begin();
			while (it != pNotify->end())
			{
				if (!it->IsNull())
				(*it)(p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13, p_14, p_15);
				++it;
			}
		}

		void operator () (P1 p_1, P2 p_2, P3 p_3, P4 p_4, P5 p_5, P6 p_6, P7 p_7, P8 p_8, P9 p_9, P10 p_10, P11 p_11, P12 p_12, P13 p_13, P14 p_14, P15 p_15, P16 p_16)
		{
			Mutex::Locker l(m_mutex);
			LNIRCP pNotify = m_pNotifications;
			LNI::iterator it = pNotify->begin();
			while (it != pNotify->end())
			{
				if (!it->IsNull())
				(*it)(p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13, p_14, p_15, p_16);
				++it;
			}
		}

		void operator () (P1 p_1, P2 p_2, P3 p_3, P4 p_4, P5 p_5, P6 p_6, P7 p_7, P8 p_8, P9 p_9, P10 p_10, P11 p_11, P12 p_12, P13 p_13, P14 p_14, P15 p_15, P16 p_16, P17 p_17)
		{
			Mutex::Locker l(m_mutex);
			LNIRCP pNotify = m_pNotifications;
			LNI::iterator it = pNotify->begin();
			while (it != pNotify->end())
			{
				if (!it->IsNull())
				(*it)(p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17);
				++it;
			}
		}

		void operator () (P1 p_1, P2 p_2, P3 p_3, P4 p_4, P5 p_5, P6 p_6, P7 p_7, P8 p_8, P9 p_9, P10 p_10, P11 p_11, P12 p_12, P13 p_13, P14 p_14, P15 p_15, P16 p_16, P17 p_17, P18 p_18)
		{
			Mutex::Locker l(m_mutex);
			LNIRCP pNotify = m_pNotifications;
			LNI::iterator it = pNotify->begin();
			while (it != pNotify->end())
			{
				if (!it->IsNull())
				(*it)(p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17, p_18);
				++it;
			}
		}

		void operator () (P1 p_1, P2 p_2, P3 p_3, P4 p_4, P5 p_5, P6 p_6, P7 p_7, P8 p_8, P9 p_9, P10 p_10, P11 p_11, P12 p_12, P13 p_13, P14 p_14, P15 p_15, P16 p_16, P17 p_17, P18 p_18, P19 p_19)
		{
			Mutex::Locker l(m_mutex);
			LNIRCP pNotify = m_pNotifications;
			LNI::iterator it = pNotify->begin();
			while (it != pNotify->end())
			{
				if (!it->IsNull())
				(*it)(p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17, p_18, p_19);
				++it;
			}
		}

		void operator () (P1 p_1, P2 p_2, P3 p_3, P4 p_4, P5 p_5, P6 p_6, P7 p_7, P8 p_8, P9 p_9, P10 p_10, P11 p_11, P12 p_12, P13 p_13, P14 p_14, P15 p_15, P16 p_16, P17 p_17, P18 p_18, P19 p_19, P20 p_20)
		{
			Mutex::Locker l(m_mutex);
			LNIRCP pNotify = m_pNotifications;
			LNI::iterator it = pNotify->begin();
			while (it != pNotify->end())
			{
				if (!it->IsNull())
				(*it)(p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17, p_18, p_19, p_20);
				++it;
			}
		}
	};
}

/* End of File: Notifier.h */
