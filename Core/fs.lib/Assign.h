
namespace fs
{
	template <class TypeList> class Assign
	{
	public:
		typedef fs::Tuple<TypeList> TupleType;

		typedef fs::Functor<void, TypeList> FunctorType;

	private:
		TupleType& m_t;
	public:
		Assign(TupleType& p_t)
				: m_t(p_t)
		{
		}

		void operator () (typename FunctorType::Parameter1 p_1)
		{
			m_t.Field<0>() = p_1;
		}

		void operator () (typename FunctorType::Parameter1 p_1, typename FunctorType::Parameter2 p_2)
		{
			m_t.Field<0>() = p_1;
			m_t.Field<1>() = p_2;
		}

		void operator () (typename FunctorType::Parameter1 p_1, typename FunctorType::Parameter2 p_2, typename FunctorType::Parameter3 p_3)
		{
			m_t.Field<0>() = p_1;
			m_t.Field<1>() = p_2;
			m_t.Field<2>() = p_3;
		}

		void operator () (typename FunctorType::Parameter1 p_1, typename FunctorType::Parameter2 p_2, typename FunctorType::Parameter3 p_3, typename FunctorType::Parameter4 p_4)
		{
			m_t.Field<0>() = p_1;
			m_t.Field<1>() = p_2;
			m_t.Field<2>() = p_3;
			m_t.Field<3>() = p_4;
		}

		void operator () (typename FunctorType::Parameter1 p_1, typename FunctorType::Parameter2 p_2, typename FunctorType::Parameter3 p_3, typename FunctorType::Parameter4 p_4, typename FunctorType::Parameter5 p_5)
		{
			m_t.Field<0>() = p_1;
			m_t.Field<1>() = p_2;
			m_t.Field<2>() = p_3;
			m_t.Field<3>() = p_4;
			m_t.Field<4>() = p_5;
		}

		void operator () (typename FunctorType::Parameter1 p_1, typename FunctorType::Parameter2 p_2, typename FunctorType::Parameter3 p_3, typename FunctorType::Parameter4 p_4, typename FunctorType::Parameter5 p_5, typename FunctorType::Parameter6 p_6)
		{
			m_t.Field<0>() = p_1;
			m_t.Field<1>() = p_2;
			m_t.Field<2>() = p_3;
			m_t.Field<3>() = p_4;
			m_t.Field<4>() = p_5;
			m_t.Field<5>() = p_6;
		}

		void operator () (typename FunctorType::Parameter1 p_1, typename FunctorType::Parameter2 p_2, typename FunctorType::Parameter3 p_3, typename FunctorType::Parameter4 p_4, typename FunctorType::Parameter5 p_5, typename FunctorType::Parameter6 p_6, typename FunctorType::Parameter7 p_7)
		{
			m_t.Field<0>() = p_1;
			m_t.Field<1>() = p_2;
			m_t.Field<2>() = p_3;
			m_t.Field<3>() = p_4;
			m_t.Field<4>() = p_5;
			m_t.Field<5>() = p_6;
			m_t.Field<6>() = p_7;
		}

		void operator () (typename FunctorType::Parameter1 p_1, typename FunctorType::Parameter2 p_2, typename FunctorType::Parameter3 p_3, typename FunctorType::Parameter4 p_4, typename FunctorType::Parameter5 p_5, typename FunctorType::Parameter6 p_6, typename FunctorType::Parameter7 p_7, typename FunctorType::Parameter8 p_8)
		{
			m_t.Field<0>() = p_1;
			m_t.Field<1>() = p_2;
			m_t.Field<2>() = p_3;
			m_t.Field<3>() = p_4;
			m_t.Field<4>() = p_5;
			m_t.Field<5>() = p_6;
			m_t.Field<6>() = p_7;
			m_t.Field<7>() = p_8;
		}

		void operator () (typename FunctorType::Parameter1 p_1, typename FunctorType::Parameter2 p_2, typename FunctorType::Parameter3 p_3, typename FunctorType::Parameter4 p_4, typename FunctorType::Parameter5 p_5, typename FunctorType::Parameter6 p_6, typename FunctorType::Parameter7 p_7, typename FunctorType::Parameter8 p_8, typename FunctorType::Parameter9 p_9)
		{
			m_t.Field<0>() = p_1;
			m_t.Field<1>() = p_2;
			m_t.Field<2>() = p_3;
			m_t.Field<3>() = p_4;
			m_t.Field<4>() = p_5;
			m_t.Field<5>() = p_6;
			m_t.Field<6>() = p_7;
			m_t.Field<7>() = p_8;
			m_t.Field<8>() = p_9;
		}

		void operator () (typename FunctorType::Parameter1 p_1, typename FunctorType::Parameter2 p_2, typename FunctorType::Parameter3 p_3, typename FunctorType::Parameter4 p_4, typename FunctorType::Parameter5 p_5, typename FunctorType::Parameter6 p_6, typename FunctorType::Parameter7 p_7, typename FunctorType::Parameter8 p_8, typename FunctorType::Parameter9 p_9, typename FunctorType::Parameter10 p_10)
		{
			m_t.Field<0>() = p_1;
			m_t.Field<1>() = p_2;
			m_t.Field<2>() = p_3;
			m_t.Field<3>() = p_4;
			m_t.Field<4>() = p_5;
			m_t.Field<5>() = p_6;
			m_t.Field<6>() = p_7;
			m_t.Field<7>() = p_8;
			m_t.Field<8>() = p_9;
			m_t.Field<9>() = p_10;
		}
	};
}
