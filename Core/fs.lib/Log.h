
namespace fs
{
	class Log
	{
	private:
		static Log *m_instance;
	public:
		static Log& Instance();
	public:
		Log();
		~Log();


		void Info(const std::string& p_s);
//		void Info(const char *p_sFormat, ...);
		template <typename T1, typename T2>
				void Info(const T1& p_1, const T2& p_2);
		template <typename T1, typename T2, typename T3>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3);
		template <typename T1, typename T2, typename T3, typename T4>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4);
		template <typename T1, typename T2, typename T3, typename T4, typename T5>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5);
		template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5, const T6& p_6);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					  const T6& p_6, const T7& p_7);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7, typename T8>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					  const T6& p_6, const T7& p_7, const T8& p_8);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7, typename T8, typename T9>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7, typename T8, typename T9, typename TA>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A);

		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7, typename T8, typename T9, typename TA,
			  typename TB>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
					  const TB& p_b);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7, typename T8, typename T9, typename TA,
			  typename TB, typename TC>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
					  const TB& p_b, const TC& p_c);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7, typename T8, typename T9, typename TA,
			  typename TB, typename TC, typename TD>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
					  const TB& p_b, const TC& p_c, const TD& p_d);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7, typename T8, typename T9, typename TA,
			  typename TB, typename TC, typename TD, typename TE>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
					  const TB& p_b, const TC& p_c, const TD& p_d, const TE& p_e);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7, typename T8, typename T9, typename TA,
			  typename TB, typename TC, typename TD, typename TE, typename TF>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
					  const TB& p_b, const TC& p_c, const TD& p_d, const TE& p_e, const TF& p_f);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7, typename T8, typename T9, typename TA,
			  typename TB, typename TC, typename TD, typename TE, typename TF,
			  typename TG>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
					  const TB& p_b, const TC& p_c, const TD& p_d, const TE& p_e, const TF& p_f,
					  const TG& p_g);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7, typename T8, typename T9, typename TA,
			  typename TB, typename TC, typename TD, typename TE, typename TF,
			  typename TG, typename TH>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
					  const TB& p_b, const TC& p_c, const TD& p_d, const TE& p_e, const TF& p_f,
					  const TG& p_g, const TH& p_h);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7, typename T8, typename T9, typename TA,
			  typename TB, typename TC, typename TD, typename TE, typename TF,
			  typename TG, typename TH, typename TI>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
					  const TB& p_b, const TC& p_c, const TD& p_d, const TE& p_e, const TF& p_f,
					  const TG& p_g, const TH& p_h, const TI& p_i);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7, typename T8, typename T9, typename TA,
			  typename TB, typename TC, typename TD, typename TE, typename TF,
			  typename TG, typename TH, typename TI, typename TJ>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
					  const TB& p_b, const TC& p_c, const TD& p_d, const TE& p_e, const TF& p_f,
					  const TG& p_g, const TH& p_h, const TI& p_i, const TJ& p_j);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7, typename T8, typename T9, typename TA,
			  typename TB, typename TC, typename TD, typename TE, typename TF,
			  typename TG, typename TH, typename TI, typename TJ, typename TK>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
					  const TB& p_b, const TC& p_c, const TD& p_d, const TE& p_e, const TF& p_f,
					  const TG& p_g, const TH& p_h, const TI& p_i, const TJ& p_j, const TK& p_k);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7, typename T8, typename T9, typename TA,
			  typename TB, typename TC, typename TD, typename TE, typename TF,
			  typename TG, typename TH, typename TI, typename TJ, typename TK,
			  typename TL>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
					  const TB& p_b, const TC& p_c, const TD& p_d, const TE& p_e, const TF& p_f,
					  const TG& p_g, const TH& p_h, const TI& p_i, const TJ& p_j, const TK& p_k,
					  const TL& p_l);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7, typename T8, typename T9, typename TA,
			  typename TB, typename TC, typename TD, typename TE, typename TF,
			  typename TG, typename TH, typename TI, typename TJ, typename TK,
			  typename TL, typename TM>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
					  const TB& p_b, const TC& p_c, const TD& p_d, const TE& p_e, const TF& p_f,
					  const TG& p_g, const TH& p_h, const TI& p_i, const TJ& p_j, const TK& p_k,
					  const TL& p_l, const TM& p_m);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7, typename T8, typename T9, typename TA,
			  typename TB, typename TC, typename TD, typename TE, typename TF,
			  typename TG, typename TH, typename TI, typename TJ, typename TK,
			  typename TL, typename TM, typename TN>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
					  const TB& p_b, const TC& p_c, const TD& p_d, const TE& p_e, const TF& p_f,
					  const TG& p_g, const TH& p_h, const TI& p_i, const TJ& p_j, const TK& p_k,
					  const TL& p_l, const TM& p_m, const TN& p_n);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7, typename T8, typename T9, typename TA,
			  typename TB, typename TC, typename TD, typename TE, typename TF,
			  typename TG, typename TH, typename TI, typename TJ, typename TK,
			  typename TL, typename TM, typename TN, typename TO>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
					  const TB& p_b, const TC& p_c, const TD& p_d, const TE& p_e, const TF& p_f,
					  const TG& p_g, const TH& p_h, const TI& p_i, const TJ& p_j, const TK& p_k,
					  const TL& p_l, const TM& p_m, const TN& p_n, const TO& p_o);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7, typename T8, typename T9, typename TA,
			  typename TB, typename TC, typename TD, typename TE, typename TF,
			  typename TG, typename TH, typename TI, typename TJ, typename TK,
			  typename TL, typename TM, typename TN, typename TO, typename TP>
				void Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
					  const TB& p_b, const TC& p_c, const TD& p_d, const TE& p_e, const TF& p_f,
					  const TG& p_g, const TH& p_h, const TI& p_i, const TJ& p_j, const TK& p_k,
					  const TL& p_l, const TM& p_m, const TN& p_n, const TO& p_o, const TP& p_p);

		

		void Warning(const std::string& p_s);
		template <typename T1, typename T2>
				void Warning(const T1& p_1, const T2& p_2);
		template <typename T1, typename T2, typename T3>
				void Warning(const T1& p_1, const T2& p_2, const T3& p_3);
		template <typename T1, typename T2, typename T3, typename T4>
				void Warning(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4);
		template <typename T1, typename T2, typename T3, typename T4, typename T5>
				void Warning(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5);
		template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
				void Warning(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5, const T6& p_6);


//		void Warning(const char *p_sFormat, ...);

		void Error(const std::string& p_s);
//		void Error(const char *p_sFormat, ...);
		template <typename T1, typename T2>
				void Error(const T1& p_1, const T2& p_2);
		template <typename T1, typename T2, typename T3>
				void Error(const T1& p_1, const T2& p_2, const T3& p_3);
		template <typename T1, typename T2, typename T3, typename T4>
				void Error(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4);
		template <typename T1, typename T2, typename T3, typename T4, typename T5>
				void Error(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5);
		template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
				void Error(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5, const T6& p_6);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7>
				void Error(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					   const T6& p_6, const T7& p_7);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7, typename T8>
				void Error(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					   const T6& p_6, const T7& p_7, const T8& p_8);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7, typename T8, typename T9>
				void Error(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					   const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9);
		template <typename T1, typename T2, typename T3, typename T4, typename T5,
			  typename T6, typename T7, typename T8, typename T9, typename TA>
				void Error(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					   const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A);

		class Adaptor
		{
		public:
			typedef ReferenceCountedPointer<Adaptor> RCP;
		protected:
			Adaptor();
		public:
			virtual	~Adaptor();

			virtual void Info(const char *p_s) = 0;
			virtual void Warning(const char *p_s) = 0;
			virtual void Error(const char *p_s) = 0;
		};

		void Add(const Adaptor::RCP& p_pAdaptor);
		void Remove(const Adaptor::RCP& p_pAdaptor);
	private:
		std::list<Adaptor::RCP> m_lpAdaptors;

		void i_doInfo(const char * p_s);
		void i_doWarning(const char * p_s);
		void i_doError(const char * p_s);

	public:
		typedef ReferenceCountedPointer<Log> RCP;

	private:
		struct Entry
		{
			::fs::byte m_type;
			::std::string m_message;
		};
		::std::vector<Entry> m_vEntriesPendingStart;

	private:
		bool m_started;
	public:
		void Start();

	private:
		std::vector<std::string> m_vsBanner;
	public:
		void AppendBanner(const std::string& p_sBannerLine);
	private:
		void i_displayBanner();
	};



	//
	// Info
	//

	template <typename T1, typename T2>
			void Log::Info(const T1& p_1, const T2& p_2)
	{
		std::string s = format(p_1);
		s += format(p_2);

		Info(s);
	}

	template <typename T1, typename T2, typename T3>
			void Log::Info(const T1& p_1, const T2& p_2, const T3& p_3)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);

		Info(s);
	}

	template <typename T1, typename T2, typename T3, typename T4>
			void Log::Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);

		Info(s);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5>
			void Log::Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);
		s += format(p_5);

		Info(s);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
			void Log::Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5, const T6& p_6)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);
		s += format(p_5);
		s += format(p_6);

		Info(s);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5,
		  typename T6, typename T7>
			void Log::Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
				       const T6& p_6, const T7& p_7)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);
		s += format(p_5);
		s += format(p_6);
		s += format(p_7);

		Info(s);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5,
		  typename T6, typename T7, typename T8>
			void Log::Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
				       const T6& p_6, const T7& p_7, const T8& p_8)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);
		s += format(p_5);
		s += format(p_6);
		s += format(p_7);
		s += format(p_8);

		Info(s);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5,
		  typename T6, typename T7, typename T8, typename T9>
			void Log::Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
				       const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9)
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

		Info(s);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5,
		  typename T6, typename T7, typename T8, typename T9, typename TA>
			void Log::Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
				       const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A)
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
		s += format(p_A);

		Info(s);
	}


	template <typename T1, typename T2, typename T3, typename T4, typename T5,
		  typename T6, typename T7, typename T8, typename T9, typename TA,
		  typename TB>
			void Log::Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
				  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
				  const TB& p_b)
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
		s += format(p_A);
		s += format(p_b);

		Info(s);
	}


	template <typename T1, typename T2, typename T3, typename T4, typename T5,
		  typename T6, typename T7, typename T8, typename T9, typename TA,
		  typename TB, typename TC>
			void Log::Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
				  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
				  const TB& p_b, const TC& p_c)
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
		s += format(p_A);
		s += format(p_b);
		s += format(p_c);

		Info(s);
	}


			
	template <typename T1, typename T2, typename T3, typename T4, typename T5,
		  typename T6, typename T7, typename T8, typename T9, typename TA,
		  typename TB, typename TC, typename TD>
			void Log::Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
				  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
				  const TB& p_b, const TC& p_c, const TD& p_d)
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
		s += format(p_A);
		s += format(p_b);
		s += format(p_c);
		s += format(p_d);

		Info(s);
	}



			
	template <typename T1, typename T2, typename T3, typename T4, typename T5,
		  typename T6, typename T7, typename T8, typename T9, typename TA,
		  typename TB, typename TC, typename TD, typename TE>
			void Log::Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
				  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
				  const TB& p_b, const TC& p_c, const TD& p_d, const TE& p_e)
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
		s += format(p_A);
		s += format(p_b);
		s += format(p_c);
		s += format(p_d);
		s += format(p_e);

		Info(s);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5,
		  typename T6, typename T7, typename T8, typename T9, typename TA,
		  typename TB, typename TC, typename TD, typename TE, typename TF>
			void Log::Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
				  const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
				  const TB& p_b, const TC& p_c, const TD& p_d, const TE& p_e, const TF& p_f)
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
		s += format(p_A);
		s += format(p_b);
		s += format(p_c);
		s += format(p_d);
		s += format(p_e);
		s += format(p_f);

		Info(s);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5,
		  typename T6, typename T7, typename T8, typename T9, typename TA,
		  typename TB, typename TC, typename TD, typename TE, typename TF,
		  typename TG>
			void Log::Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
				       const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
				       const TB& p_b, const TC& p_c, const TD& p_d, const TE& p_e, const TF& p_f,
				       const TG& p_g)
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
		s += format(p_A);
		s += format(p_b);
		s += format(p_c);
		s += format(p_d);
		s += format(p_e);
		s += format(p_f);
		s += format(p_g);

		Info(s);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5,
		  typename T6, typename T7, typename T8, typename T9, typename TA,
		  typename TB, typename TC, typename TD, typename TE, typename TF,
		  typename TG, typename TH>
			void Log::Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
				       const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
				       const TB& p_b, const TC& p_c, const TD& p_d, const TE& p_e, const TF& p_f,
				       const TG& p_g, const TH& p_h)
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
		s += format(p_A);
		s += format(p_b);
		s += format(p_c);
		s += format(p_d);
		s += format(p_e);
		s += format(p_f);
		s += format(p_g);
		s += format(p_h);

		Info(s);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5,
		  typename T6, typename T7, typename T8, typename T9, typename TA,
		  typename TB, typename TC, typename TD, typename TE, typename TF,
		  typename TG, typename TH, typename TI>
			void Log::Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
				       const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
				       const TB& p_b, const TC& p_c, const TD& p_d, const TE& p_e, const TF& p_f,
				       const TG& p_g, const TH& p_h, const TI& p_i)
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
		s += format(p_A);
		s += format(p_b);
		s += format(p_c);
		s += format(p_d);
		s += format(p_e);
		s += format(p_f);
		s += format(p_g);
		s += format(p_h);
		s += format(p_i);

		Info(s);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5,
		  typename T6, typename T7, typename T8, typename T9, typename TA,
		  typename TB, typename TC, typename TD, typename TE, typename TF,
		  typename TG, typename TH, typename TI, typename TJ>
			void Log::Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
				       const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
				       const TB& p_b, const TC& p_c, const TD& p_d, const TE& p_e, const TF& p_f,
				       const TG& p_g, const TH& p_h, const TI& p_i, const TJ& p_j)
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
		s += format(p_A);
		s += format(p_b);
		s += format(p_c);
		s += format(p_d);
		s += format(p_e);
		s += format(p_f);
		s += format(p_g);
		s += format(p_h);
		s += format(p_i);
		s += format(p_j);

		Info(s);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5,
		  typename T6, typename T7, typename T8, typename T9, typename TA,
		  typename TB, typename TC, typename TD, typename TE, typename TF,
		  typename TG, typename TH, typename TI, typename TJ, typename TK>
			void Log::Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
				       const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
				       const TB& p_b, const TC& p_c, const TD& p_d, const TE& p_e, const TF& p_f,
				       const TG& p_g, const TH& p_h, const TI& p_i, const TJ& p_j, const TK& p_k)
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
		s += format(p_A);
		s += format(p_b);
		s += format(p_c);
		s += format(p_d);
		s += format(p_e);
		s += format(p_f);
		s += format(p_g);
		s += format(p_h);
		s += format(p_i);
		s += format(p_j);
		s += format(p_k);

		Info(s);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5,
		  typename T6, typename T7, typename T8, typename T9, typename TA,
		  typename TB, typename TC, typename TD, typename TE, typename TF,
		  typename TG, typename TH, typename TI, typename TJ, typename TK,
		  typename TL>
			void Log::Info(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
				       const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A,
				       const TB& p_b, const TC& p_c, const TD& p_d, const TE& p_e, const TF& p_f,
				       const TG& p_g, const TH& p_h, const TI& p_i, const TJ& p_j, const TK& p_k,
				       const TL& p_l)
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
		s += format(p_A);
		s += format(p_b);
		s += format(p_c);
		s += format(p_d);
		s += format(p_e);
		s += format(p_f);
		s += format(p_g);
		s += format(p_h);
		s += format(p_i);
		s += format(p_j);
		s += format(p_k);
		s += format(p_l);

		Info(s);
	}



	//
	// Warning
	//

	template <typename T1, typename T2>
			void Log::Warning(const T1& p_1, const T2& p_2)
	{
		std::string s = format(p_1);
		s += format(p_2);

		Warning(s);
	}

	template <typename T1, typename T2, typename T3>
			void Log::Warning(const T1& p_1, const T2& p_2, const T3& p_3)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);

		Warning(s);
	}

	template <typename T1, typename T2, typename T3, typename T4>
			void Log::Warning(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);

		Warning(s);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5>
			void Log::Warning(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);
		s += format(p_5);

		Warning(s);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
			void Log::Warning(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5, const T6& p_6)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);
		s += format(p_5);
		s += format(p_6);

		Warning(s);
	}

	//
	// Error
	//

	template <typename T1, typename T2>
			void Log::Error(const T1& p_1, const T2& p_2)
	{
		std::string s = format(p_1);
		s += format(p_2);

		Error(s);
	}

	template <typename T1, typename T2, typename T3>
			void Log::Error(const T1& p_1, const T2& p_2, const T3& p_3)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);

		Error(s);
	}

	template <typename T1, typename T2, typename T3, typename T4>
			void Log::Error(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);

		Error(s);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5>
			void Log::Error(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);
		s += format(p_5);

		Error(s);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
			void Log::Error(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5, const T6& p_6)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);
		s += format(p_5);
		s += format(p_6);

		Error(s);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5,
		  typename T6, typename T7>
			void Log::Error(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					const T6& p_6, const T7& p_7)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);
		s += format(p_5);
		s += format(p_6);
		s += format(p_7);

		Error(s);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5,
		  typename T6, typename T7, typename T8>
			void Log::Error(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					const T6& p_6, const T7& p_7, const T8& p_8)
	{
		std::string s = format(p_1);
		s += format(p_2);
		s += format(p_3);
		s += format(p_4);
		s += format(p_5);
		s += format(p_6);
		s += format(p_7);
		s += format(p_8);

		Error(s);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5,
		  typename T6, typename T7, typename T8, typename T9>
			void Log::Error(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9)
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

		Error(s);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5,
		  typename T6, typename T7, typename T8, typename T9, typename TA>
			void Log::Error(const T1& p_1, const T2& p_2, const T3& p_3, const T4& p_4, const T5& p_5,
					const T6& p_6, const T7& p_7, const T8& p_8, const T9& p_9, const TA& p_A)
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
		s += format(p_A);

		Error(s);
	}


}


/* End Of File: Log.h */
