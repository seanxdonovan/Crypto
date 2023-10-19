namespace fs
{
	template <class Functor> class Invoke
	{
	public:
		typedef typename Functor::TypeList TypeList;
		typedef typename Functor::ResultType ResultType;
		typedef fs::Tuple<TypeList> TupleType;
		typedef Functor Functor;

		typedef typename fs::type::Traits<TupleType>::ParameterType PTT;
		typedef typename fs::type::Traits<Functor  >::ParameterType PTF;
	private:
		template <size_t count> struct Helper;

		template<> struct Helper<1>
		{
			public:
				ResultType operator () (PTT p_t, PTF p_f)
				{
					return p_f(p_t.Field<0>());
				}
		};

		template<> struct Helper<2>
		{
			public:
				ResultType operator () (PTT p_t, PTF p_f)
				{
					return p_f(p_t.Field<0>(), p_t.Field<1>());
				}
		};

		template<> struct Helper<3>
		{
			public:
				ResultType operator () (PTT p_t, PTF p_f)
				{
					return p_f(p_t.Field<0>(), p_t.Field<1>(), p_t.Field<2>());
				}
		};

		template<> struct Helper<4>
		{
			public:
				ResultType operator () (PTT p_t, PTF p_f)
				{
					return p_f(p_t.Field<0>(), p_t.Field<1>(), p_t.Field<2>(), p_t.Field<3>());
				}
		};

		template<> struct Helper<5>
		{
			public:
				ResultType operator () (PTT p_t, PTF p_f)
				{
					return p_f(p_t.Field<0>(), p_t.Field<1>(), p_t.Field<2>(), p_t.Field<3>(), p_t.Field<4>());
				}
		};

		template<> struct Helper<6>
		{
			public:
				ResultType operator () (PTT p_t, PTF p_f)
				{
					return p_f(p_t.Field<0>(), p_t.Field<1>(), p_t.Field<2>(), p_t.Field<3>(), p_t.Field<4>(), p_t.Field<5>());
				}
		};

		template<> struct Helper<7>
		{
			public:
				ResultType operator () (PTT p_t, PTF p_f)
				{
					return p_f(p_t.Field<0>(), p_t.Field<1>(), p_t.Field<2>(), p_t.Field<3>(), p_t.Field<4>(), p_t.Field<5>(), p_t.Field<6>());
				}
		};

		template<> struct Helper<8>
		{
			public:
				ResultType operator () (PTT p_t, PTF p_f)
				{
					return p_f(p_t.Field<0>(), p_t.Field<1>(), p_t.Field<2>(), p_t.Field<3>(), p_t.Field<4>(), p_t.Field<5>(), p_t.Field<6>(), p_t.Field<7>());
				}
		};

		template<> struct Helper<9>
		{
			public:
				ResultType operator () (PTT p_t, PTF p_f)
				{
					return p_f(p_t.Field<0>(), p_t.Field<1>(), p_t.Field<2>(), p_t.Field<3>(), p_t.Field<4>(), p_t.Field<5>(), p_t.Field<6>(), p_t.Field<7>(), p_t.Field<8>());
				}
		};

		template<> struct Helper<10>
		{
			public:
				ResultType operator () (PTT p_t, PTF p_f)
				{
					return p_f(p_t.Field<0>(), p_t.Field<1>(), p_t.Field<2>(), p_t.Field<3>(), p_t.Field<4>(), p_t.Field<5>(), p_t.Field<6>(), p_t.Field<7>(), p_t.Field<8>(), p_t.Field<9>());
				}
		};
	public:

		ResultType operator () (PTT p_t, PTF p_f)
		{
			return Helper<fs::type::Length<TypeList>::value>()(p_t, p_f);
		}
	};
}


