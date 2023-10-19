namespace fs
{
	namespace internal
	{
		template <typename R >
		struct BaseFunctorImplementation
		{
			typedef R ResultType;

			typedef type::Empty Parameter1;
			typedef type::Empty Parameter2;
			typedef type::Empty Parameter3;
			typedef type::Empty Parameter4;
			typedef type::Empty Parameter5;
			typedef type::Empty Parameter6;
			typedef type::Empty Parameter7;
			typedef type::Empty Parameter8;
			typedef type::Empty Parameter9;
			typedef type::Empty Parameter10;
			typedef type::Empty Parameter11;
			typedef type::Empty Parameter12;
			typedef type::Empty Parameter13;
			typedef type::Empty Parameter14;
			typedef type::Empty Parameter15;
			typedef type::Empty Parameter16;
			typedef type::Empty Parameter17;
			typedef type::Empty Parameter18;
			typedef type::Empty Parameter19;
			typedef type::Empty Parameter20;

			typedef type::Empty ActualType1;
			typedef type::Empty ActualType2;
			typedef type::Empty ActualType3;
			typedef type::Empty ActualType4;
			typedef type::Empty ActualType5;
			typedef type::Empty ActualType6;
			typedef type::Empty ActualType7;
			typedef type::Empty ActualType8;
			typedef type::Empty ActualType9;
			typedef type::Empty ActualType10;
			typedef type::Empty ActualType11;
			typedef type::Empty ActualType12;
			typedef type::Empty ActualType13;
			typedef type::Empty ActualType14;
			typedef type::Empty ActualType15;
			typedef type::Empty ActualType16;
			typedef type::Empty ActualType17;
			typedef type::Empty ActualType18;
			typedef type::Empty ActualType19;
			typedef type::Empty ActualType20;
		};
	}


	template <typename ResultType, class TypeList>
	class FunctorImplementation;


	template <typename ResultType>
	class FunctorImplementation<ResultType, type::Null> : public internal::BaseFunctorImplementation<ResultType>
	{
	public:
		virtual ResultType operator()() = 0;
	};

	template <typename R, typename P1>
	class FunctorImplementation <R, TYPELIST_1(P1) > : public internal::BaseFunctorImplementation<R>
	{
	public:
		typedef R ResultType;
		typedef typename P1 ActualType1;
		typedef typename type::Traits<P1>::ParameterType Parameter1;
		virtual R operator()(Parameter1) = 0;
	};

	template <typename R, typename P1, typename P2>
	class FunctorImplementation <R, TYPELIST_2(P1, P2) > : public internal::BaseFunctorImplementation<R>
	{
		public:
			typedef R ResultType;
			typedef typename P1 ActualType1;
			typedef typename P2 ActualType2;
			typedef typename type::Traits<P1>::ParameterType Parameter1;
			typedef typename type::Traits<P2>::ParameterType Parameter2;
			virtual R operator()(Parameter1, Parameter2) = 0;
	};

	template <typename R, typename P1, typename P2, typename P3>
	class FunctorImplementation <R, TYPELIST_3(P1, P2, P3) > : public internal::BaseFunctorImplementation<R>
	{
	public:
		typedef R ResultType;
		typedef typename P1 ActualType1;
		typedef typename P2 ActualType2;
		typedef typename P3 ActualType3;
		typedef typename type::Traits<P1>::ParameterType Parameter1;
		typedef typename type::Traits<P2>::ParameterType Parameter2;
		typedef typename type::Traits<P3>::ParameterType Parameter3;
		virtual R operator()(Parameter1, Parameter2, Parameter3) = 0;
	};

	template <typename R, typename P1, typename P2, typename P3, typename P4>
	class FunctorImplementation <R, TYPELIST_4(P1, P2, P3, P4) > : public internal::BaseFunctorImplementation<R>
	{
		public:
			typedef R ResultType;
			typedef typename P1 ActualType1;
			typedef typename P2 ActualType2;
			typedef typename P3 ActualType3;
			typedef typename P4 ActualType4;
			typedef typename type::Traits<P1>::ParameterType Parameter1;
			typedef typename type::Traits<P2>::ParameterType Parameter2;
			typedef typename type::Traits<P3>::ParameterType Parameter3;
			typedef typename type::Traits<P4>::ParameterType Parameter4;
			virtual R operator()(Parameter1, Parameter2, Parameter3, Parameter4) = 0;
	};

	template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
	class FunctorImplementation <R, TYPELIST_5(P1, P2, P3, P4, P5) > : public internal::BaseFunctorImplementation<R>
	{
		public:
			typedef R ResultType;
			typedef typename P1 ActualType1;
			typedef typename P2 ActualType2;
			typedef typename P3 ActualType3;
			typedef typename P4 ActualType4;
			typedef typename P5 ActualType5;
			typedef typename type::Traits<P1>::ParameterType Parameter1;
			typedef typename type::Traits<P2>::ParameterType Parameter2;
			typedef typename type::Traits<P3>::ParameterType Parameter3;
			typedef typename type::Traits<P4>::ParameterType Parameter4;
			typedef typename type::Traits<P5>::ParameterType Parameter5;
			virtual R operator()(Parameter1, Parameter2, Parameter3, Parameter4, Parameter5) = 0;
	};

	template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
	class FunctorImplementation <R, TYPELIST_6(P1, P2, P3, P4, P5, P6) > : public internal::BaseFunctorImplementation<R>
	{
		public:
			typedef R ResultType;
			typedef typename P1 ActualType1;
			typedef typename P2 ActualType2;
			typedef typename P3 ActualType3;
			typedef typename P4 ActualType4;
			typedef typename P5 ActualType5;
			typedef typename P6 ActualType6;
			typedef typename type::Traits<P1>::ParameterType Parameter1;
			typedef typename type::Traits<P2>::ParameterType Parameter2;
			typedef typename type::Traits<P3>::ParameterType Parameter3;
			typedef typename type::Traits<P4>::ParameterType Parameter4;
			typedef typename type::Traits<P5>::ParameterType Parameter5;
			typedef typename type::Traits<P6>::ParameterType Parameter6;
			virtual R operator()(Parameter1, Parameter2, Parameter3, Parameter4, Parameter5,
					     Parameter6) = 0;
	};

	template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
	class FunctorImplementation <R, TYPELIST_7(P1, P2, P3, P4, P5, P6, P7) > : public internal::BaseFunctorImplementation<R>
	{
		public:
			typedef R ResultType;
			typedef typename P1 ActualType1;
			typedef typename P2 ActualType2;
			typedef typename P3 ActualType3;
			typedef typename P4 ActualType4;
			typedef typename P5 ActualType5;
			typedef typename P6 ActualType6;
			typedef typename P7 ActualType7;
			typedef typename type::Traits<P1>::ParameterType Parameter1;
			typedef typename type::Traits<P2>::ParameterType Parameter2;
			typedef typename type::Traits<P3>::ParameterType Parameter3;
			typedef typename type::Traits<P4>::ParameterType Parameter4;
			typedef typename type::Traits<P5>::ParameterType Parameter5;
			typedef typename type::Traits<P6>::ParameterType Parameter6;
			typedef typename type::Traits<P7>::ParameterType Parameter7;
			virtual R operator()(Parameter1, Parameter2, Parameter3, Parameter4, Parameter5,
					     Parameter6, Parameter7) = 0;
	};

	template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
	class FunctorImplementation <R, TYPELIST_8(P1, P2, P3, P4, P5, P6, P7, P8) > : public internal::BaseFunctorImplementation<R>
	{
		public:
			typedef R ResultType;
			typedef typename P1 ActualType1;
			typedef typename P2 ActualType2;
			typedef typename P3 ActualType3;
			typedef typename P4 ActualType4;
			typedef typename P5 ActualType5;
			typedef typename P6 ActualType6;
			typedef typename P7 ActualType7;
			typedef typename P8 ActualType8;
			typedef typename type::Traits<P1>::ParameterType Parameter1;
			typedef typename type::Traits<P2>::ParameterType Parameter2;
			typedef typename type::Traits<P3>::ParameterType Parameter3;
			typedef typename type::Traits<P4>::ParameterType Parameter4;
			typedef typename type::Traits<P5>::ParameterType Parameter5;
			typedef typename type::Traits<P6>::ParameterType Parameter6;
			typedef typename type::Traits<P7>::ParameterType Parameter7;
			typedef typename type::Traits<P8>::ParameterType Parameter8;
			virtual R operator()(Parameter1, Parameter2, Parameter3, Parameter4, Parameter5,
					     Parameter6, Parameter7, Parameter8) = 0;
	};

	template <typename R,
		  typename P1, typename P2, typename P3, typename P4, typename P5,
		  typename P6, typename P7, typename P8, typename P9>
	class FunctorImplementation <R, TYPELIST_9(P1, P2, P3, P4, P5, P6, P7, P8, P9) > : public internal::BaseFunctorImplementation<R>
	{
		public:
			typedef R ResultType;
			typedef typename P1 ActualType1;
			typedef typename P2 ActualType2;
			typedef typename P3 ActualType3;
			typedef typename P4 ActualType4;
			typedef typename P5 ActualType5;
			typedef typename P6 ActualType6;
			typedef typename P7 ActualType7;
			typedef typename P8 ActualType8;
			typedef typename P9 ActualType9;
			typedef typename type::Traits<P1>::ParameterType Parameter1;
			typedef typename type::Traits<P2>::ParameterType Parameter2;
			typedef typename type::Traits<P3>::ParameterType Parameter3;
			typedef typename type::Traits<P4>::ParameterType Parameter4;
			typedef typename type::Traits<P5>::ParameterType Parameter5;
			typedef typename type::Traits<P6>::ParameterType Parameter6;
			typedef typename type::Traits<P7>::ParameterType Parameter7;
			typedef typename type::Traits<P8>::ParameterType Parameter8;
			typedef typename type::Traits<P9>::ParameterType Parameter9;
			virtual R operator()(Parameter1, Parameter2, Parameter3, Parameter4, Parameter5,
					     Parameter6, Parameter7, Parameter8, Parameter9) = 0;
	};

	template <typename R,
		  typename P1, typename P2, typename P3, typename P4, typename P5,
		  typename P6, typename P7, typename P8, typename P9, typename P10>
	class FunctorImplementation <R, TYPELIST_10(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) >
			: public internal::BaseFunctorImplementation<R>
	{
		public:
			typedef R ResultType;
			typedef typename P1  ActualType1;
			typedef typename P2  ActualType2;
			typedef typename P3  ActualType3;
			typedef typename P4  ActualType4;
			typedef typename P5  ActualType5;
			typedef typename P6  ActualType6;
			typedef typename P7  ActualType7;
			typedef typename P8  ActualType8;
			typedef typename P9  ActualType9;
			typedef typename P10 ActualType10;
			typedef typename type::Traits<P1>::ParameterType  Parameter1;
			typedef typename type::Traits<P2>::ParameterType  Parameter2;
			typedef typename type::Traits<P3>::ParameterType  Parameter3;
			typedef typename type::Traits<P4>::ParameterType  Parameter4;
			typedef typename type::Traits<P5>::ParameterType  Parameter5;
			typedef typename type::Traits<P6>::ParameterType  Parameter6;
			typedef typename type::Traits<P7>::ParameterType  Parameter7;
			typedef typename type::Traits<P8>::ParameterType  Parameter8;
			typedef typename type::Traits<P9>::ParameterType  Parameter9;
			typedef typename type::Traits<P10>::ParameterType Parameter10;

			virtual R operator()(Parameter1, Parameter2, Parameter3, Parameter4, Parameter5,
					     Parameter6, Parameter7, Parameter8, Parameter9, Parameter10) = 0;
	};

	template <typename R,
		  typename P1, typename P2, typename P3, typename P4, typename P5,
		  typename P6, typename P7, typename P8, typename P9, typename P10,
		  typename P11>
	class FunctorImplementation <R, TYPELIST_11(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) >
			: public internal::BaseFunctorImplementation<R>
	{
	public:
		typedef R ResultType;
		typedef typename P1  ActualType1;
		typedef typename P2  ActualType2;
		typedef typename P3  ActualType3;
		typedef typename P4  ActualType4;
		typedef typename P5  ActualType5;
		typedef typename P6  ActualType6;
		typedef typename P7  ActualType7;
		typedef typename P8  ActualType8;
		typedef typename P9  ActualType9;
		typedef typename P10 ActualType10;
		typedef typename P11 ActualType11;
		typedef typename type::Traits<P1>::ParameterType  Parameter1;
		typedef typename type::Traits<P2>::ParameterType  Parameter2;
		typedef typename type::Traits<P3>::ParameterType  Parameter3;
		typedef typename type::Traits<P4>::ParameterType  Parameter4;
		typedef typename type::Traits<P5>::ParameterType  Parameter5;
		typedef typename type::Traits<P6>::ParameterType  Parameter6;
		typedef typename type::Traits<P7>::ParameterType  Parameter7;
		typedef typename type::Traits<P8>::ParameterType  Parameter8;
		typedef typename type::Traits<P9>::ParameterType  Parameter9;
		typedef typename type::Traits<P10>::ParameterType Parameter10;
		typedef typename type::Traits<P11>::ParameterType Parameter11;

		virtual R operator()(Parameter1, Parameter2, Parameter3, Parameter4, Parameter5,
				     Parameter6, Parameter7, Parameter8, Parameter9, Parameter10,
				     Parameter11) = 0;
	};

	template <typename R,
		  typename P1,  typename P2, typename P3, typename P4, typename P5,
		  typename P6,  typename P7, typename P8, typename P9, typename P10,
		  typename P11, typename P12>
	class FunctorImplementation <R, TYPELIST_12(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) >
			: public internal::BaseFunctorImplementation<R>
	{
	public:
		typedef R ResultType;
		typedef typename P1  ActualType1;
		typedef typename P2  ActualType2;
		typedef typename P3  ActualType3;
		typedef typename P4  ActualType4;
		typedef typename P5  ActualType5;
		typedef typename P6  ActualType6;
		typedef typename P7  ActualType7;
		typedef typename P8  ActualType8;
		typedef typename P9  ActualType9;
		typedef typename P10 ActualType10;
		typedef typename P11 ActualType11;
		typedef typename P12 ActualType12;
		typedef typename type::Traits<P1>::ParameterType  Parameter1;
		typedef typename type::Traits<P2>::ParameterType  Parameter2;
		typedef typename type::Traits<P3>::ParameterType  Parameter3;
		typedef typename type::Traits<P4>::ParameterType  Parameter4;
		typedef typename type::Traits<P5>::ParameterType  Parameter5;
		typedef typename type::Traits<P6>::ParameterType  Parameter6;
		typedef typename type::Traits<P7>::ParameterType  Parameter7;
		typedef typename type::Traits<P8>::ParameterType  Parameter8;
		typedef typename type::Traits<P9>::ParameterType  Parameter9;
		typedef typename type::Traits<P10>::ParameterType Parameter10;
		typedef typename type::Traits<P11>::ParameterType Parameter11;
		typedef typename type::Traits<P12>::ParameterType Parameter12;

		virtual R operator()(Parameter1,  Parameter2, Parameter3, Parameter4, Parameter5,
				     Parameter6,  Parameter7, Parameter8, Parameter9, Parameter10,
				     Parameter11, Parameter12) = 0;
	};

	template <typename R,
		  typename P1,  typename P2,  typename P3, typename P4, typename P5,
		  typename P6,  typename P7,  typename P8, typename P9, typename P10,
		  typename P11, typename P12, typename P13>
	class FunctorImplementation <R, TYPELIST_13(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) >
		: public internal::BaseFunctorImplementation<R>
	{
	public:
		typedef R ResultType;
		typedef typename P1  ActualType1;
		typedef typename P2  ActualType2;
		typedef typename P3  ActualType3;
		typedef typename P4  ActualType4;
		typedef typename P5  ActualType5;
		typedef typename P6  ActualType6;
		typedef typename P7  ActualType7;
		typedef typename P8  ActualType8;
		typedef typename P9  ActualType9;
		typedef typename P10 ActualType10;
		typedef typename P11 ActualType11;
		typedef typename P12 ActualType12;
		typedef typename P13 ActualType13;
		typedef typename type::Traits<P1>::ParameterType  Parameter1;
		typedef typename type::Traits<P2>::ParameterType  Parameter2;
		typedef typename type::Traits<P3>::ParameterType  Parameter3;
		typedef typename type::Traits<P4>::ParameterType  Parameter4;
		typedef typename type::Traits<P5>::ParameterType  Parameter5;
		typedef typename type::Traits<P6>::ParameterType  Parameter6;
		typedef typename type::Traits<P7>::ParameterType  Parameter7;
		typedef typename type::Traits<P8>::ParameterType  Parameter8;
		typedef typename type::Traits<P9>::ParameterType  Parameter9;
		typedef typename type::Traits<P10>::ParameterType Parameter10;
		typedef typename type::Traits<P11>::ParameterType Parameter11;
		typedef typename type::Traits<P12>::ParameterType Parameter12;
		typedef typename type::Traits<P13>::ParameterType Parameter13;

		virtual R operator()(Parameter1,  Parameter2,  Parameter3, Parameter4, Parameter5,
				     Parameter6,  Parameter7,  Parameter8, Parameter9, Parameter10,
				     Parameter11, Parameter12, Parameter13) = 0;
	};

	template <typename R,
		  typename P1,  typename P2,  typename P3,  typename P4, typename P5,
		  typename P6,  typename P7,  typename P8,  typename P9, typename P10,
		  typename P11, typename P12, typename P13, typename P14>
	class FunctorImplementation <R, TYPELIST_14(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) >
		: public internal::BaseFunctorImplementation<R>
	{
	public:
		typedef R ResultType;
		typedef typename P1  ActualType1;
		typedef typename P2  ActualType2;
		typedef typename P3  ActualType3;
		typedef typename P4  ActualType4;
		typedef typename P5  ActualType5;
		typedef typename P6  ActualType6;
		typedef typename P7  ActualType7;
		typedef typename P8  ActualType8;
		typedef typename P9  ActualType9;
		typedef typename P10 ActualType10;
		typedef typename P11 ActualType11;
		typedef typename P12 ActualType12;
		typedef typename P13 ActualType13;
		typedef typename P14 ActualType14;
		typedef typename type::Traits<P1>::ParameterType  Parameter1;
		typedef typename type::Traits<P2>::ParameterType  Parameter2;
		typedef typename type::Traits<P3>::ParameterType  Parameter3;
		typedef typename type::Traits<P4>::ParameterType  Parameter4;
		typedef typename type::Traits<P5>::ParameterType  Parameter5;
		typedef typename type::Traits<P6>::ParameterType  Parameter6;
		typedef typename type::Traits<P7>::ParameterType  Parameter7;
		typedef typename type::Traits<P8>::ParameterType  Parameter8;
		typedef typename type::Traits<P9>::ParameterType  Parameter9;
		typedef typename type::Traits<P10>::ParameterType Parameter10;
		typedef typename type::Traits<P11>::ParameterType Parameter11;
		typedef typename type::Traits<P12>::ParameterType Parameter12;
		typedef typename type::Traits<P13>::ParameterType Parameter13;
		typedef typename type::Traits<P14>::ParameterType Parameter14;

		virtual R operator()(Parameter1,  Parameter2,  Parameter3,  Parameter4, Parameter5,
				     Parameter6,  Parameter7,  Parameter8,  Parameter9, Parameter10,
				     Parameter11, Parameter12, Parameter13, Parameter14) = 0;
	};

	template <typename R,
		  typename P1,  typename P2,  typename P3,  typename P4,  typename P5,
		  typename P6,  typename P7,  typename P8,  typename P9,  typename P10,
		  typename P11, typename P12, typename P13, typename P14, typename P15>
	class FunctorImplementation <R, TYPELIST_15(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) >
			: public internal::BaseFunctorImplementation<R>
	{
	public:
		typedef R ResultType;
		typedef typename P1  ActualType1;
		typedef typename P2  ActualType2;
		typedef typename P3  ActualType3;
		typedef typename P4  ActualType4;
		typedef typename P5  ActualType5;
		typedef typename P6  ActualType6;
		typedef typename P7  ActualType7;
		typedef typename P8  ActualType8;
		typedef typename P9  ActualType9;
		typedef typename P10 ActualType10;
		typedef typename P11 ActualType11;
		typedef typename P12 ActualType12;
		typedef typename P13 ActualType13;
		typedef typename P14 ActualType14;
		typedef typename P15 ActualType15;
		typedef typename type::Traits<P1>::ParameterType  Parameter1;
		typedef typename type::Traits<P2>::ParameterType  Parameter2;
		typedef typename type::Traits<P3>::ParameterType  Parameter3;
		typedef typename type::Traits<P4>::ParameterType  Parameter4;
		typedef typename type::Traits<P5>::ParameterType  Parameter5;
		typedef typename type::Traits<P6>::ParameterType  Parameter6;
		typedef typename type::Traits<P7>::ParameterType  Parameter7;
		typedef typename type::Traits<P8>::ParameterType  Parameter8;
		typedef typename type::Traits<P9>::ParameterType  Parameter9;
		typedef typename type::Traits<P10>::ParameterType Parameter10;
		typedef typename type::Traits<P11>::ParameterType Parameter11;
		typedef typename type::Traits<P12>::ParameterType Parameter12;
		typedef typename type::Traits<P13>::ParameterType Parameter13;
		typedef typename type::Traits<P14>::ParameterType Parameter14;
		typedef typename type::Traits<P15>::ParameterType Parameter15;

		virtual R operator()(Parameter1,  Parameter2,  Parameter3,  Parameter4,  Parameter5,
				     Parameter6,  Parameter7,  Parameter8,  Parameter9,  Parameter10,
				     Parameter11, Parameter12, Parameter13, Parameter14, Parameter15) = 0;
	};

	template <typename R,
		  typename P1,  typename P2,  typename P3,  typename P4,  typename P5,
		  typename P6,  typename P7,  typename P8,  typename P9,  typename P10,
		  typename P11, typename P12, typename P13, typename P14, typename P15,
		  typename P16>
	class FunctorImplementation <R, TYPELIST_16(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15, P16) >
		: public internal::BaseFunctorImplementation<R>
	{
	public:
		typedef R ResultType;
		typedef typename P1  ActualType1;
		typedef typename P2  ActualType2;
		typedef typename P3  ActualType3;
		typedef typename P4  ActualType4;
		typedef typename P5  ActualType5;
		typedef typename P6  ActualType6;
		typedef typename P7  ActualType7;
		typedef typename P8  ActualType8;
		typedef typename P9  ActualType9;
		typedef typename P10 ActualType10;
		typedef typename P11 ActualType11;
		typedef typename P12 ActualType12;
		typedef typename P13 ActualType13;
		typedef typename P14 ActualType14;
		typedef typename P15 ActualType15;
		typedef typename P16 ActualType16;
		typedef typename type::Traits<P1>::ParameterType  Parameter1;
		typedef typename type::Traits<P2>::ParameterType  Parameter2;
		typedef typename type::Traits<P3>::ParameterType  Parameter3;
		typedef typename type::Traits<P4>::ParameterType  Parameter4;
		typedef typename type::Traits<P5>::ParameterType  Parameter5;
		typedef typename type::Traits<P6>::ParameterType  Parameter6;
		typedef typename type::Traits<P7>::ParameterType  Parameter7;
		typedef typename type::Traits<P8>::ParameterType  Parameter8;
		typedef typename type::Traits<P9>::ParameterType  Parameter9;
		typedef typename type::Traits<P10>::ParameterType Parameter10;
		typedef typename type::Traits<P11>::ParameterType Parameter11;
		typedef typename type::Traits<P12>::ParameterType Parameter12;
		typedef typename type::Traits<P13>::ParameterType Parameter13;
		typedef typename type::Traits<P14>::ParameterType Parameter14;
		typedef typename type::Traits<P15>::ParameterType Parameter15;
		typedef typename type::Traits<P16>::ParameterType Parameter16;

		virtual R operator()(Parameter1,  Parameter2,  Parameter3,  Parameter4,  Parameter5,
				     Parameter6,  Parameter7,  Parameter8,  Parameter9,  Parameter10,
				     Parameter11, Parameter12, Parameter13, Parameter14, Parameter15,
				     Parameter16) = 0;
	};

	template <typename R,
		  typename P1,  typename P2,  typename P3,  typename P4,  typename P5,
		  typename P6,  typename P7,  typename P8,  typename P9,  typename P10,
		  typename P11, typename P12, typename P13, typename P14, typename P15,
		  typename P16, typename P17>
	class FunctorImplementation <R, TYPELIST_17(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15, P16, P17) >
		: public internal::BaseFunctorImplementation<R>
	{
	public:
		typedef R ResultType;
		typedef typename P1  ActualType1;
		typedef typename P2  ActualType2;
		typedef typename P3  ActualType3;
		typedef typename P4  ActualType4;
		typedef typename P5  ActualType5;
		typedef typename P6  ActualType6;
		typedef typename P7  ActualType7;
		typedef typename P8  ActualType8;
		typedef typename P9  ActualType9;
		typedef typename P10 ActualType10;
		typedef typename P11 ActualType11;
		typedef typename P12 ActualType12;
		typedef typename P13 ActualType13;
		typedef typename P14 ActualType14;
		typedef typename P15 ActualType15;
		typedef typename P16 ActualType16;
		typedef typename P17 ActualType17;
		typedef typename type::Traits<P1>::ParameterType  Parameter1;
		typedef typename type::Traits<P2>::ParameterType  Parameter2;
		typedef typename type::Traits<P3>::ParameterType  Parameter3;
		typedef typename type::Traits<P4>::ParameterType  Parameter4;
		typedef typename type::Traits<P5>::ParameterType  Parameter5;
		typedef typename type::Traits<P6>::ParameterType  Parameter6;
		typedef typename type::Traits<P7>::ParameterType  Parameter7;
		typedef typename type::Traits<P8>::ParameterType  Parameter8;
		typedef typename type::Traits<P9>::ParameterType  Parameter9;
		typedef typename type::Traits<P10>::ParameterType Parameter10;
		typedef typename type::Traits<P11>::ParameterType Parameter11;
		typedef typename type::Traits<P12>::ParameterType Parameter12;
		typedef typename type::Traits<P13>::ParameterType Parameter13;
		typedef typename type::Traits<P14>::ParameterType Parameter14;
		typedef typename type::Traits<P15>::ParameterType Parameter15;
		typedef typename type::Traits<P16>::ParameterType Parameter16;
		typedef typename type::Traits<P17>::ParameterType Parameter17;

		virtual R operator()(Parameter1,  Parameter2,  Parameter3,  Parameter4,  Parameter5,
				     Parameter6,  Parameter7,  Parameter8,  Parameter9,  Parameter10,
				     Parameter11, Parameter12, Parameter13, Parameter14, Parameter15,
				     Parameter16, Parameter17) = 0;
	};

	template <typename R,
		  typename P1,  typename P2,  typename P3,  typename P4,  typename P5,
		  typename P6,  typename P7,  typename P8,  typename P9,  typename P10,
		  typename P11, typename P12, typename P13, typename P14, typename P15,
		  typename P16, typename P17, typename P18>
	class FunctorImplementation <R, TYPELIST_18(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15, P16, P17, P18) >
		: public internal::BaseFunctorImplementation<R>
	{
	public:
		typedef R ResultType;
		typedef typename P1  ActualType1;
		typedef typename P2  ActualType2;
		typedef typename P3  ActualType3;
		typedef typename P4  ActualType4;
		typedef typename P5  ActualType5;
		typedef typename P6  ActualType6;
		typedef typename P7  ActualType7;
		typedef typename P8  ActualType8;
		typedef typename P9  ActualType9;
		typedef typename P10 ActualType10;
		typedef typename P11 ActualType11;
		typedef typename P12 ActualType12;
		typedef typename P13 ActualType13;
		typedef typename P14 ActualType14;
		typedef typename P15 ActualType15;
		typedef typename P16 ActualType16;
		typedef typename P17 ActualType17;
		typedef typename P18 ActualType18;
		typedef typename type::Traits<P1>::ParameterType  Parameter1;
		typedef typename type::Traits<P2>::ParameterType  Parameter2;
		typedef typename type::Traits<P3>::ParameterType  Parameter3;
		typedef typename type::Traits<P4>::ParameterType  Parameter4;
		typedef typename type::Traits<P5>::ParameterType  Parameter5;
		typedef typename type::Traits<P6>::ParameterType  Parameter6;
		typedef typename type::Traits<P7>::ParameterType  Parameter7;
		typedef typename type::Traits<P8>::ParameterType  Parameter8;
		typedef typename type::Traits<P9>::ParameterType  Parameter9;
		typedef typename type::Traits<P10>::ParameterType Parameter10;
		typedef typename type::Traits<P11>::ParameterType Parameter11;
		typedef typename type::Traits<P12>::ParameterType Parameter12;
		typedef typename type::Traits<P13>::ParameterType Parameter13;
		typedef typename type::Traits<P14>::ParameterType Parameter14;
		typedef typename type::Traits<P15>::ParameterType Parameter15;
		typedef typename type::Traits<P16>::ParameterType Parameter16;
		typedef typename type::Traits<P17>::ParameterType Parameter17;
		typedef typename type::Traits<P18>::ParameterType Parameter18;

		virtual R operator()(Parameter1,  Parameter2,  Parameter3,  Parameter4,  Parameter5,
				     Parameter6,  Parameter7,  Parameter8,  Parameter9,  Parameter10,
				     Parameter11, Parameter12, Parameter13, Parameter14, Parameter15,
				     Parameter16, Parameter17, Parameter18) = 0;
	};

	template <typename R,
		  typename P1,  typename P2,  typename P3,  typename P4,  typename P5,
		  typename P6,  typename P7,  typename P8,  typename P9,  typename P10,
		  typename P11, typename P12, typename P13, typename P14, typename P15,
		  typename P16, typename P17, typename P18, typename P19>
	class FunctorImplementation <R, TYPELIST_19(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15, P16, P17, P18, P19) >
		: public internal::BaseFunctorImplementation<R>
	{
	public:
		typedef R ResultType;
		typedef typename P1  ActualType1;
		typedef typename P2  ActualType2;
		typedef typename P3  ActualType3;
		typedef typename P4  ActualType4;
		typedef typename P5  ActualType5;
		typedef typename P6  ActualType6;
		typedef typename P7  ActualType7;
		typedef typename P8  ActualType8;
		typedef typename P9  ActualType9;
		typedef typename P10 ActualType10;
		typedef typename P11 ActualType11;
		typedef typename P12 ActualType12;
		typedef typename P13 ActualType13;
		typedef typename P14 ActualType14;
		typedef typename P15 ActualType15;
		typedef typename P16 ActualType16;
		typedef typename P17 ActualType17;
		typedef typename P18 ActualType18;
		typedef typename P19 ActualType19;
		typedef typename type::Traits<P1>::ParameterType  Parameter1;
		typedef typename type::Traits<P2>::ParameterType  Parameter2;
		typedef typename type::Traits<P3>::ParameterType  Parameter3;
		typedef typename type::Traits<P4>::ParameterType  Parameter4;
		typedef typename type::Traits<P5>::ParameterType  Parameter5;
		typedef typename type::Traits<P6>::ParameterType  Parameter6;
		typedef typename type::Traits<P7>::ParameterType  Parameter7;
		typedef typename type::Traits<P8>::ParameterType  Parameter8;
		typedef typename type::Traits<P9>::ParameterType  Parameter9;
		typedef typename type::Traits<P10>::ParameterType Parameter10;
		typedef typename type::Traits<P11>::ParameterType Parameter11;
		typedef typename type::Traits<P12>::ParameterType Parameter12;
		typedef typename type::Traits<P13>::ParameterType Parameter13;
		typedef typename type::Traits<P14>::ParameterType Parameter14;
		typedef typename type::Traits<P15>::ParameterType Parameter15;
		typedef typename type::Traits<P16>::ParameterType Parameter16;
		typedef typename type::Traits<P17>::ParameterType Parameter17;
		typedef typename type::Traits<P18>::ParameterType Parameter18;
		typedef typename type::Traits<P19>::ParameterType Parameter19;

		virtual R operator()(Parameter1,  Parameter2,  Parameter3,  Parameter4,  Parameter5,
				     Parameter6,  Parameter7,  Parameter8,  Parameter9,  Parameter10,
				     Parameter11, Parameter12, Parameter13, Parameter14, Parameter15,
				     Parameter16, Parameter17, Parameter18, Parameter19) = 0;
	};

	template <typename R,
		  typename P1,  typename P2,  typename P3,  typename P4,  typename P5,
		  typename P6,  typename P7,  typename P8,  typename P9,  typename P10,
		  typename P11, typename P12, typename P13, typename P14, typename P15,
		  typename P16, typename P17, typename P18, typename P19, typename P20>
	class FunctorImplementation <R, TYPELIST_20(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15, P16, P17, P18, P19, P20) >
		: public internal::BaseFunctorImplementation<R>
	{
	public:
		typedef R ResultType;
		typedef typename P1  ActualType1;
		typedef typename P2  ActualType2;
		typedef typename P3  ActualType3;
		typedef typename P4  ActualType4;
		typedef typename P5  ActualType5;
		typedef typename P6  ActualType6;
		typedef typename P7  ActualType7;
		typedef typename P8  ActualType8;
		typedef typename P9  ActualType9;
		typedef typename P10 ActualType10;
		typedef typename P11 ActualType11;
		typedef typename P12 ActualType12;
		typedef typename P13 ActualType13;
		typedef typename P14 ActualType14;
		typedef typename P15 ActualType15;
		typedef typename P16 ActualType16;
		typedef typename P17 ActualType17;
		typedef typename P18 ActualType18;
		typedef typename P19 ActualType19;
		typedef typename P20 ActualType20;
		typedef typename type::Traits<P1>::ParameterType  Parameter1;
		typedef typename type::Traits<P2>::ParameterType  Parameter2;
		typedef typename type::Traits<P3>::ParameterType  Parameter3;
		typedef typename type::Traits<P4>::ParameterType  Parameter4;
		typedef typename type::Traits<P5>::ParameterType  Parameter5;
		typedef typename type::Traits<P6>::ParameterType  Parameter6;
		typedef typename type::Traits<P7>::ParameterType  Parameter7;
		typedef typename type::Traits<P8>::ParameterType  Parameter8;
		typedef typename type::Traits<P9>::ParameterType  Parameter9;
		typedef typename type::Traits<P10>::ParameterType Parameter10;
		typedef typename type::Traits<P11>::ParameterType Parameter11;
		typedef typename type::Traits<P12>::ParameterType Parameter12;
		typedef typename type::Traits<P13>::ParameterType Parameter13;
		typedef typename type::Traits<P14>::ParameterType Parameter14;
		typedef typename type::Traits<P15>::ParameterType Parameter15;
		typedef typename type::Traits<P16>::ParameterType Parameter16;
		typedef typename type::Traits<P17>::ParameterType Parameter17;
		typedef typename type::Traits<P18>::ParameterType Parameter18;
		typedef typename type::Traits<P19>::ParameterType Parameter19;
		typedef typename type::Traits<P20>::ParameterType Parameter20;

		virtual R operator()(Parameter1,  Parameter2,  Parameter3,  Parameter4,  Parameter5,
				     Parameter6,  Parameter7,  Parameter8,  Parameter9,  Parameter10,
				     Parameter11, Parameter12, Parameter13, Parameter14, Parameter15,
				     Parameter16, Parameter17, Parameter18, Parameter19, Parameter20) = 0;
	};



	template <class ParentFunctor, typename F>
	class FunctorHandler : public ParentFunctor::Implementation
	{
		typedef typename ParentFunctor::Implementation Base;
	public:
		typedef typename Base::ResultType  ResultType;
		typedef typename Base::Parameter1  Parameter1;
		typedef typename Base::Parameter2  Parameter2;
		typedef typename Base::Parameter3  Parameter3;
		typedef typename Base::Parameter4  Parameter4;
		typedef typename Base::Parameter5  Parameter5;
		typedef typename Base::Parameter6  Parameter6;
		typedef typename Base::Parameter7  Parameter7;
		typedef typename Base::Parameter8  Parameter8;
		typedef typename Base::Parameter9  Parameter9;
		typedef typename Base::Parameter10 Parameter10;
		typedef typename Base::Parameter11 Parameter11;
		typedef typename Base::Parameter12 Parameter12;
		typedef typename Base::Parameter13 Parameter13;
		typedef typename Base::Parameter14 Parameter14;
		typedef typename Base::Parameter15 Parameter15;
		typedef typename Base::Parameter16 Parameter16;
		typedef typename Base::Parameter17 Parameter17;
		typedef typename Base::Parameter18 Parameter18;
		typedef typename Base::Parameter19 Parameter19;
		typedef typename Base::Parameter20 Parameter20;

		FunctorHandler(const F& p_functor)
 		  : m_functor(p_functor)
		{
		}

		ResultType operator()()
		{
			return m_functor();
		}

		ResultType operator()(Parameter1 p_p1)
		{
			return m_functor(p_p1);
		}

		ResultType operator()(Parameter1 p_p1, Parameter2 p_p2)
		{
			return m_functor(p_p1, p_p2);
		}

		ResultType operator()(Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3)
		{
			return m_functor(p_p1, p_p2, p_p3);
		}

		ResultType operator()(Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3, Parameter4 p_p4)
		{
			return m_functor(p_p1, p_p2, p_p3, p_p4);
		}

		ResultType operator()(Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3, Parameter4 p_p4, Parameter5 p_p5)
		{
			return m_functor(p_p1, p_p2, p_p3, p_p4, p_p5);
		}

		ResultType operator()(Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3, Parameter4 p_p4, Parameter5 p_p5,
				      Parameter6 p_p6)
		{
			return m_functor(p_p1, p_p2, p_p3, p_p4, p_p5, p_p6);
		}

		ResultType operator()(Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3, Parameter4 p_p4, Parameter5 p_p5,
				      Parameter6 p_p6, Parameter7 p_p7)
		{
			return m_functor(p_p1, p_p2, p_p3, p_p4, p_p5, p_p6, p_p7);
		}

		ResultType operator()(Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3, Parameter4 p_p4, Parameter5 p_p5,
				      Parameter6 p_p6, Parameter7 p_p7, Parameter8 p_p8)
		{
			return m_functor(p_p1, p_p2, p_p3, p_p4, p_p5, p_p6, p_p7, p_p8);
		}

		ResultType operator()(Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3, Parameter4 p_p4, Parameter5 p_p5,
				      Parameter6 p_p6, Parameter7 p_p7, Parameter8 p_p8, Parameter9 p_p9)
		{
			return m_functor(p_p1, p_p2, p_p3, p_p4, p_p5, p_p6, p_p7, p_p8, p_p9);
		}

		ResultType operator()(Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3, Parameter4 p_p4, Parameter5  p_p5,
				      Parameter6 p_p6, Parameter7 p_p7, Parameter8 p_p8, Parameter9 p_p9, Parameter10 p_p10)
		{
			return m_functor(p_p1, p_p2, p_p3, p_p4, p_p5, p_p6, p_p7, p_p8, p_p9, p_p10);
		}

		ResultType operator()(Parameter1  p_p1, Parameter2 p_p2, Parameter3 p_p3, Parameter4 p_p4, Parameter5  p_p5,
				      Parameter6  p_p6, Parameter7 p_p7, Parameter8 p_p8, Parameter9 p_p9, Parameter10 p_p10,
				      Parameter11 p_p11)
		{
			return m_functor(p_p1, p_p2, p_p3, p_p4, p_p5, p_p6, p_p7, p_p8, p_p9, p_p10, p_p11);
		}

		ResultType operator()(Parameter1  p_p1,  Parameter2  p_p2, Parameter3 p_p3, Parameter4 p_p4, Parameter5  p_p5,
				      Parameter6  p_p6,  Parameter7  p_p7, Parameter8 p_p8, Parameter9 p_p9, Parameter10 p_p10,
				      Parameter11 p_p11, Parameter12 p_p12)
		{
			return m_functor(p_p1, p_p2, p_p3, p_p4, p_p5, p_p6, p_p7, p_p8, p_p9, p_p10, p_p11, p_p12);
		}

		ResultType operator()(Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3, Parameter4 p_p4, Parameter5  p_p5,
				      Parameter6  p_p6,  Parameter7  p_p7,  Parameter8  p_p8, Parameter9 p_p9, Parameter10 p_p10,
				      Parameter11 p_p11, Parameter12 p_p12, Parameter13 p_p13)
		{
			return m_functor(p_p1, p_p2, p_p3, p_p4, p_p5, p_p6, p_p7, p_p8, p_p9, p_p10, p_p11, p_p12, p_p13);
		}

		ResultType operator()(Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,  Parameter4  p_p4,  Parameter5  p_p5,
				      Parameter6  p_p6,  Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,  Parameter10 p_p10,
				      Parameter11 p_p11, Parameter12 p_p12, Parameter13 p_p13, Parameter14 p_p14)
		{
			return m_functor(p_p1, p_p2, p_p3, p_p4, p_p5, p_p6, p_p7, p_p8, p_p9, p_p10, p_p11, p_p12, p_p13, p_p14);
		}

		ResultType operator()(Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,  Parameter4  p_p4,  Parameter5  p_p5,
				      Parameter6  p_p6,  Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,  Parameter10 p_p10,
				      Parameter11 p_p11, Parameter12 p_p12, Parameter13 p_p13, Parameter14 p_p14, Parameter15 p_p15)
		{
			return m_functor(p_p1, p_p2, p_p3, p_p4, p_p5, p_p6, p_p7, p_p8, p_p9, p_p10, p_p11, p_p12, p_p13, p_p14, p_p15);
		}

		ResultType operator()(Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,  Parameter4  p_p4,  Parameter5  p_p5,
				      Parameter6  p_p6,  Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,  Parameter10 p_p10,
				      Parameter11 p_p11, Parameter12 p_p12, Parameter13 p_p13, Parameter14 p_p14, Parameter15 p_p15,
				      Parameter16 p_p16)
		{
			return m_functor(p_p1,  p_p2,  p_p3,  p_p4,  p_p5,
					 p_p6,  p_p7,  p_p8,  p_p9,  p_p10,
					 p_p11, p_p12, p_p13, p_p14, p_p15,
					 p_p16);
		}

		ResultType operator()(Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,  Parameter4  p_p4,  Parameter5  p_p5,
				      Parameter6  p_p6,  Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,  Parameter10 p_p10,
				      Parameter11 p_p11, Parameter12 p_p12, Parameter13 p_p13, Parameter14 p_p14, Parameter15 p_p15,
				      Parameter16 p_p16, Parameter17 p_p17)
		{
			return m_functor(p_p1,  p_p2,  p_p3,  p_p4,  p_p5,
					 p_p6,  p_p7,  p_p8,  p_p9,  p_p10,
					 p_p11, p_p12, p_p13, p_p14, p_p15,
					 p_p16, p_p17);
		}

		ResultType operator()(Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,  Parameter4  p_p4,  Parameter5  p_p5,
				      Parameter6  p_p6,  Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,  Parameter10 p_p10,
				      Parameter11 p_p11, Parameter12 p_p12, Parameter13 p_p13, Parameter14 p_p14, Parameter15 p_p15,
				      Parameter16 p_p16, Parameter17 p_p17, Parameter18 p_p18)
		{
			return m_functor(p_p1,  p_p2,  p_p3,  p_p4,  p_p5,
					 p_p6,  p_p7,  p_p8,  p_p9,  p_p10,
					 p_p11, p_p12, p_p13, p_p14, p_p15,
					 p_p16, p_p17, p_p18);
		}

		ResultType operator()(Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,  Parameter4  p_p4,  Parameter5  p_p5,
				      Parameter6  p_p6,  Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,  Parameter10 p_p10,
				      Parameter11 p_p11, Parameter12 p_p12, Parameter13 p_p13, Parameter14 p_p14, Parameter15 p_p15,
				      Parameter16 p_p16, Parameter17 p_p17, Parameter18 p_p18, Parameter19 p_p19)
		{
			return m_functor(p_p1,  p_p2,  p_p3,  p_p4,  p_p5,
					 p_p6,  p_p7,  p_p8,  p_p9,  p_p10,
					 p_p11, p_p12, p_p13, p_p14, p_p15,
					 p_p16, p_p17, p_p18, p_p19);
		}

		ResultType operator()(Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,  Parameter4  p_p4,  Parameter5  p_p5,
				      Parameter6  p_p6,  Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,  Parameter10 p_p10,
				      Parameter11 p_p11, Parameter12 p_p12, Parameter13 p_p13, Parameter14 p_p14, Parameter15 p_p15,
				      Parameter16 p_p16, Parameter17 p_p17, Parameter18 p_p18, Parameter19 p_p19, Parameter20 p_p20)
		{
			return m_functor(p_p1,  p_p2,  p_p3,  p_p4,  p_p5,
					 p_p6,  p_p7,  p_p8,  p_p9,  p_p10,
					 p_p11, p_p12, p_p13, p_p14, p_p15,
					 p_p16, p_p17, p_p18, p_p19, p_p20);
		}

	private:
		F m_functor;
	};


	template <class ParentFunctor, typename PointerToObject,
		  typename PointerToMemberFunction>
	class MemberFunctionHandler : public ParentFunctor::Implementation
	{
		typedef typename ParentFunctor::Implementation Base;
	public:
		typedef typename Base::ResultType ResultType;
		typedef typename Base::Parameter1  Parameter1;
		typedef typename Base::Parameter2  Parameter2;
		typedef typename Base::Parameter3  Parameter3;
		typedef typename Base::Parameter4  Parameter4;
		typedef typename Base::Parameter5  Parameter5;
		typedef typename Base::Parameter6  Parameter6;
		typedef typename Base::Parameter7  Parameter7;
		typedef typename Base::Parameter8  Parameter8;
		typedef typename Base::Parameter9  Parameter9;
		typedef typename Base::Parameter10 Parameter10;
		typedef typename Base::Parameter11 Parameter11;
		typedef typename Base::Parameter12 Parameter12;
		typedef typename Base::Parameter13 Parameter13;
		typedef typename Base::Parameter14 Parameter14;
		typedef typename Base::Parameter15 Parameter15;
		typedef typename Base::Parameter16 Parameter16;
		typedef typename Base::Parameter17 Parameter17;
		typedef typename Base::Parameter18 Parameter18;
		typedef typename Base::Parameter19 Parameter19;
		typedef typename Base::Parameter20 Parameter20;

		MemberFunctionHandler(const PointerToObject& p_pObject, PointerToMemberFunction p_pMemberFunction)
				: m_pObject(p_pObject), m_pMemberFunction(p_pMemberFunction)
		{
		}

		ResultType operator()()
		{
			return ((*m_pObject).*m_pMemberFunction)();
		}

		ResultType operator()(Parameter1 p_p1)
		{
			return ((*m_pObject).*m_pMemberFunction)(p_p1);
		}

		ResultType operator()(Parameter1 p_p1, Parameter2 p_p2)
		{
			return ((*m_pObject).*m_pMemberFunction)(p_p1, p_p2);
		}

		ResultType operator()(Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3)
		{
			return ((*m_pObject).*m_pMemberFunction)(p_p1, p_p2, p_p3);
		}

		ResultType operator()(Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3, Parameter4 p_p4)
		{
			return ((*m_pObject).*m_pMemberFunction)(p_p1, p_p2, p_p3, p_p4);
		}

		ResultType operator()(Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3, Parameter4 p_p4, Parameter5 p_p5)
		{
			return ((*m_pObject).*m_pMemberFunction)(p_p1, p_p2, p_p3, p_p4, p_p5);
		}

		ResultType operator()(Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3, Parameter4 p_p4, Parameter5 p_p5,
				      Parameter6 p_p6)
		{
			return ((*m_pObject).*m_pMemberFunction)(p_p1, p_p2, p_p3, p_p4, p_p5,
				                                 p_p6); 
		}

		ResultType operator()(Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3, Parameter4 p_p4, Parameter5 p_p5,
				      Parameter6 p_p6, Parameter7 p_p7)
		{
			return ((*m_pObject).*m_pMemberFunction)(p_p1, p_p2, p_p3, p_p4, p_p5,
				                                 p_p6, p_p7); 
		}

		ResultType operator()(Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3, Parameter4 p_p4, Parameter5 p_p5,
				      Parameter6 p_p6, Parameter7 p_p7, Parameter8 p_p8)
		{
			return ((*m_pObject).*m_pMemberFunction)(p_p1, p_p2, p_p3, p_p4, p_p5,
				                                 p_p6, p_p7, p_p8); 
		}

		ResultType operator()(Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3, Parameter4 p_p4, Parameter5 p_p5,
				      Parameter6 p_p6, Parameter7 p_p7, Parameter8 p_p8, Parameter9 p_p9)
		{
			return ((*m_pObject).*m_pMemberFunction)(p_p1, p_p2, p_p3, p_p4, p_p5,
				                                 p_p6, p_p7, p_p8, p_p9);
		}

		ResultType operator()(Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3, Parameter4 p_p4, Parameter5  p_p5,
				      Parameter6 p_p6, Parameter7 p_p7, Parameter8 p_p8, Parameter9 p_p9, Parameter10 p_p10)
		{
			return ((*m_pObject).*m_pMemberFunction)(p_p1, p_p2, p_p3, p_p4, p_p5,
				                                 p_p6, p_p7, p_p8, p_p9, p_p10);
		}

		ResultType operator()(Parameter1  p_p1, Parameter2 p_p2, Parameter3 p_p3, Parameter4 p_p4, Parameter5  p_p5,
				      Parameter6  p_p6, Parameter7 p_p7, Parameter8 p_p8, Parameter9 p_p9, Parameter10 p_p10,
				      Parameter11 p_p11)
		{
			return ((*m_pObject).*m_pMemberFunction)(p_p1, p_p2, p_p3, p_p4, p_p5,
				                                 p_p6, p_p7, p_p8, p_p9, p_p10,
				                                 p_p11);
		}

		ResultType operator()(Parameter1  p_p1,  Parameter2  p_p2, Parameter3 p_p3, Parameter4 p_p4, Parameter5  p_p5,
				      Parameter6  p_p6,  Parameter7  p_p7, Parameter8 p_p8, Parameter9 p_p9, Parameter10 p_p10,
				      Parameter11 p_p11, Parameter12 p_p12)
		{
			return ((*m_pObject).*m_pMemberFunction)(p_p1,  p_p2, p_p3, p_p4, p_p5,
				                                 p_p6,  p_p7, p_p8, p_p9, p_p10,
				                                 p_p11, p_p12);
		}

		ResultType operator()(Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3, Parameter4 p_p4, Parameter5  p_p5,
				      Parameter6  p_p6,  Parameter7  p_p7,  Parameter8  p_p8, Parameter9 p_p9, Parameter10 p_p10,
				      Parameter11 p_p11, Parameter12 p_p12, Parameter13 p_p13)
		{
			return ((*m_pObject).*m_pMemberFunction)(p_p1,  p_p2,  p_p3, p_p4, p_p5,
				                                 p_p6,  p_p7,  p_p8, p_p9, p_p10,
				                                 p_p11, p_p12, p_p13);
		}

		ResultType operator()(Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,  Parameter4  p_p4, Parameter5  p_p5,
				      Parameter6  p_p6,  Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9, Parameter10 p_p10,
				      Parameter11 p_p11, Parameter12 p_p12, Parameter13 p_p13, Parameter14 p_p14)
		{
			return ((*m_pObject).*m_pMemberFunction)(p_p1,  p_p2,  p_p3,  p_p4, p_p5,
								 p_p6,  p_p7,  p_p8,  p_p9, p_p10,
								 p_p11, p_p12, p_p13, p_p14);
		}

		ResultType operator()(Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,  Parameter4  p_p4,  Parameter5  p_p5,
				      Parameter6  p_p6,  Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,  Parameter10 p_p10,
				      Parameter11 p_p11, Parameter12 p_p12, Parameter13 p_p13, Parameter14 p_p14, Parameter15 p_p15)
		{
			return ((*m_pObject).*m_pMemberFunction)(p_p1,  p_p2,  p_p3,  p_p4,  p_p5,
								 p_p6,  p_p7,  p_p8,  p_p9,  p_p10,
								 p_p11, p_p12, p_p13, p_p14, p_p15);
		}

		ResultType operator()(Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,  Parameter4  p_p4,  Parameter5  p_p5,
				      Parameter6  p_p6,  Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,  Parameter10 p_p10,
				      Parameter11 p_p11, Parameter12 p_p12, Parameter13 p_p13, Parameter14 p_p14, Parameter15 p_p15,
				      Parameter16 p_p16)
		{
			return ((*m_pObject).*m_pMemberFunction)(p_p1,  p_p2,  p_p3,  p_p4,  p_p5,
				                                 p_p6,  p_p7,  p_p8,  p_p9,  p_p10,
				                                 p_p11, p_p12, p_p13, p_p14, p_p15,
				                                 p_p16);
		}

		ResultType operator()(Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,  Parameter4  p_p4,  Parameter5  p_p5,
				      Parameter6  p_p6,  Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,  Parameter10 p_p10,
				      Parameter11 p_p11, Parameter12 p_p12, Parameter13 p_p13, Parameter14 p_p14, Parameter15 p_p15,
				      Parameter16 p_p16, Parameter17 p_p17)
		{
			return ((*m_pObject).*m_pMemberFunction)(p_p1,  p_p2,  p_p3,  p_p4,  p_p5,
				                                 p_p6,  p_p7,  p_p8,  p_p9,  p_p10,
				                                 p_p11, p_p12, p_p13, p_p14, p_p15,
				                                 p_p16, p_p17);
		}

		ResultType operator()(Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,  Parameter4  p_p4,  Parameter5  p_p5,
				      Parameter6  p_p6,  Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,  Parameter10 p_p10,
				      Parameter11 p_p11, Parameter12 p_p12, Parameter13 p_p13, Parameter14 p_p14, Parameter15 p_p15,
				      Parameter16 p_p16, Parameter17 p_p17, Parameter18 p_p18)
		{
			return ((*m_pObject).*m_pMemberFunction)(p_p1,  p_p2,  p_p3,  p_p4,  p_p5,
				                                 p_p6,  p_p7,  p_p8,  p_p9,  p_p10,
				                                 p_p11, p_p12, p_p13, p_p14, p_p15,
				                                 p_p16, p_p17, p_p18);
		}

		ResultType operator()(Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,  Parameter4  p_p4,  Parameter5  p_p5,
				      Parameter6  p_p6,  Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,  Parameter10 p_p10,
				      Parameter11 p_p11, Parameter12 p_p12, Parameter13 p_p13, Parameter14 p_p14, Parameter15 p_p15,
				      Parameter16 p_p16, Parameter17 p_p17, Parameter18 p_p18, Parameter19 p_p19)
		{
			return ((*m_pObject).*m_pMemberFunction)(p_p1,  p_p2,  p_p3,  p_p4,  p_p5,
				                                 p_p6,  p_p7,  p_p8,  p_p9,  p_p10,
				                                 p_p11, p_p12, p_p13, p_p14, p_p15,
				                                 p_p16, p_p17, p_p18, p_p19);
		}

		ResultType operator()(Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,  Parameter4  p_p4,  Parameter5  p_p5,
				      Parameter6  p_p6,  Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,  Parameter10 p_p10,
				      Parameter11 p_p11, Parameter12 p_p12, Parameter13 p_p13, Parameter14 p_p14, Parameter15 p_p15,
				      Parameter16 p_p16, Parameter17 p_p17, Parameter18 p_p18, Parameter19 p_p19, Parameter20 p_p20)
		{
			return ((*m_pObject).*m_pMemberFunction)(p_p1,  p_p2,  p_p3,  p_p4,  p_p5,
				                                 p_p6,  p_p7,  p_p8,  p_p9,  p_p10,
				                                 p_p11, p_p12, p_p13, p_p14, p_p15,
				                                 p_p16, p_p17, p_p18, p_p19, p_p20);
		}

	private:
		PointerToObject m_pObject;
		PointerToMemberFunction m_pMemberFunction;
	};



	







	template <typename ResultType, class TypeList = type::Null >
	class Functor
	{
	public:
		typedef FunctorImplementation<ResultType, TypeList> Implementation;
		typedef ResultType ResultType;
		typedef TypeList ParameterList;
		typedef TypeList TypeList;
		typedef typename Implementation::ActualType1  ActualType1;
		typedef typename Implementation::ActualType2  ActualType2;
		typedef typename Implementation::ActualType3  ActualType3;
		typedef typename Implementation::ActualType4  ActualType4;
		typedef typename Implementation::ActualType5  ActualType5;
		typedef typename Implementation::ActualType6  ActualType6;
		typedef typename Implementation::ActualType7  ActualType7;
		typedef typename Implementation::ActualType8  ActualType8;
		typedef typename Implementation::ActualType9  ActualType9;
		typedef typename Implementation::ActualType10 ActualType10;
		typedef typename Implementation::ActualType11 ActualType11;
		typedef typename Implementation::ActualType12 ActualType12;
		typedef typename Implementation::ActualType13 ActualType13;
		typedef typename Implementation::ActualType14 ActualType14;
		typedef typename Implementation::ActualType15 ActualType15;
		typedef typename Implementation::ActualType16 ActualType16;
		typedef typename Implementation::ActualType17 ActualType17;
		typedef typename Implementation::ActualType18 ActualType18;
		typedef typename Implementation::ActualType19 ActualType19;
		typedef typename Implementation::ActualType20 ActualType20;
		typedef typename Implementation::Parameter1  Parameter1;
		typedef typename Implementation::Parameter2  Parameter2;
		typedef typename Implementation::Parameter3  Parameter3;
		typedef typename Implementation::Parameter4  Parameter4;
		typedef typename Implementation::Parameter5  Parameter5;
		typedef typename Implementation::Parameter6  Parameter6;
		typedef typename Implementation::Parameter7  Parameter7;
		typedef typename Implementation::Parameter8  Parameter8;
		typedef typename Implementation::Parameter9  Parameter9;
		typedef typename Implementation::Parameter10 Parameter10;
		typedef typename Implementation::Parameter11 Parameter11;
		typedef typename Implementation::Parameter12 Parameter12;
		typedef typename Implementation::Parameter13 Parameter13;
		typedef typename Implementation::Parameter14 Parameter14;
		typedef typename Implementation::Parameter15 Parameter15;
		typedef typename Implementation::Parameter16 Parameter16;
		typedef typename Implementation::Parameter17 Parameter17;
		typedef typename Implementation::Parameter18 Parameter18;
		typedef typename Implementation::Parameter19 Parameter19;
		typedef typename Implementation::Parameter20 Parameter20;

	private:
		fs::ReferenceCountedPointer<Implementation> m_pImplementation;

	public:
		inline const bool IsNull() const
		{
			return m_pImplementation.IsNull();
		}

		Functor()
		  : m_pImplementation(0)
		{
		}
#if 0

		Functor(const Functor& p_rhs)
				: m_pImplementation(p_rhs.m_pImplementation)
		{
		}

#endif
		inline Functor(const fs::ReferenceCountedPointer<Implementation>& p_pImplementation)
		    : m_pImplementation(p_pImplementation)
		{
		}
		//
		// Functor Implementation Adaptor
		//
		template <typename F>
		Functor(F p_functor)
		  : m_pImplementation(new FunctorHandler<Functor, F>(p_functor))
		{
		}

		//
		// Member Function Implementation Adaptor
		//
		template <class PointerToObject, typename MemberFunction>
		Functor(const PointerToObject& p_p, MemberFunction p_pMemberFunction)
		  : m_pImplementation(new MemberFunctionHandler<Functor, PointerToObject, MemberFunction>(p_p, p_pMemberFunction))
		{

		}

		Functor& operator = (const Functor& p_rhs)
		{
			m_pImplementation = p_rhs.m_pImplementation;

			return *this;
		}

		ResultType operator() () const
		{
			sPrecondition(not(IsNull()));

			return (*m_pImplementation)();
		}

		ResultType operator() (Parameter1 p_p1) const
		{
			sPrecondition(not(IsNull()));

			return (*m_pImplementation)(p_p1);
		}

		ResultType operator() (Parameter1 p_p1, Parameter2 p_p2) const
		{
			sPrecondition(not(IsNull()));

			return (*m_pImplementation)(p_p1, p_p2);
		}

		ResultType operator() (Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3) const
		{
			sPrecondition(not(IsNull()));

			return (*m_pImplementation)(p_p1, p_p2, p_p3);
		}

		ResultType operator() (Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3,
				    Parameter4 p_p4) const
		{
			sPrecondition(not(IsNull()));

			return (*m_pImplementation)(p_p1, p_p2, p_p3, p_p4);
		}

		ResultType operator() (Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3,
				    Parameter4 p_p4, Parameter5 p_p5) const
		{
			sPrecondition(not(IsNull()));

			return (*m_pImplementation)(p_p1, p_p2, p_p3, p_p4, p_p5);
		}

		ResultType operator() (Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3,
				    Parameter4 p_p4, Parameter5 p_p5, Parameter6 p_p6) const
		{
			sPrecondition(not(IsNull()));

			return (*m_pImplementation)(p_p1, p_p2, p_p3, p_p4, p_p5, p_p6);
		}

		ResultType operator() (Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3,
				    Parameter4 p_p4, Parameter5 p_p5, Parameter6 p_p6,
				    Parameter7 p_p7) const
		{
			sPrecondition(not(IsNull()));

			return (*m_pImplementation)(p_p1, p_p2, p_p3, p_p4, p_p5, p_p6,
				                    p_p7);
		}

		ResultType operator() (Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3,
				    Parameter4 p_p4, Parameter5 p_p5, Parameter6 p_p6,
				    Parameter7 p_p7, Parameter8 p_p8) const
		{
			sPrecondition(not(IsNull()));

			return (*m_pImplementation)(p_p1, p_p2, p_p3, p_p4, p_p5, p_p6,
				                    p_p7, p_p8);
		}

		ResultType operator() (Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3,
				    Parameter4 p_p4, Parameter5 p_p5, Parameter6 p_p6,
				    Parameter7 p_p7, Parameter8 p_p8, Parameter9 p_p9) const
		{
			sPrecondition(not(IsNull()));

			return (*m_pImplementation)(p_p1, p_p2, p_p3, p_p4, p_p5, p_p6,
				                    p_p7, p_p8, p_p9);
		}

		ResultType operator() (Parameter1 p_p1, Parameter2 p_p2, Parameter3 p_p3,
				    Parameter4 p_p4, Parameter5 p_p5, Parameter6 p_p6,
				    Parameter7 p_p7, Parameter8 p_p8, Parameter9 p_p9,
				    Parameter10 p_p10) const
		{
			sPrecondition(not(IsNull()));

			return (*m_pImplementation)(p_p1, p_p2, p_p3, p_p4, p_p5, p_p6,
				                    p_p7, p_p8, p_p9, p_p10);
		}

		ResultType operator() (Parameter1  p_p1,  Parameter2  p_p2, Parameter3 p_p3,
				    Parameter4  p_p4,  Parameter5  p_p5, Parameter6 p_p6,
				    Parameter7  p_p7,  Parameter8  p_p8, Parameter9 p_p9,
				    Parameter10 p_p10, Parameter11 p_p11) const
		{
			sPrecondition(not(IsNull()));

			return (*m_pImplementation)(p_p1, p_p2, p_p3, p_p4,  p_p5, p_p6,
				                    p_p7, p_p8, p_p9, p_p10, p_p11);
		}

		ResultType operator() (Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,
				    Parameter4  p_p4,  Parameter5  p_p5,  Parameter6  p_p6,
				    Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,
				    Parameter10 p_p10, Parameter11 p_p11, Parameter12 p_p12) const
		{
			sPrecondition(not(IsNull()));

			return (*m_pImplementation)(p_p1, p_p2, p_p3, p_p4,  p_p5,  p_p6,
				                    p_p7, p_p8, p_p9, p_p10, p_p11, p_p12);
		}

		ResultType operator() (Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,
				    Parameter4  p_p4,  Parameter5  p_p5,  Parameter6  p_p6,
				    Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,
				    Parameter10 p_p10, Parameter11 p_p11, Parameter12 p_p12,
				    Parameter13 p_p13) const
		{
			sPrecondition(not(IsNull()));

			return (*m_pImplementation)(p_p1, p_p2, p_p3, p_p4,  p_p5,  p_p6,
				                    p_p7, p_p8, p_p9, p_p10, p_p11, p_p12,
				                    p_p13);
		}

		ResultType operator() (Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,
				    Parameter4  p_p4,  Parameter5  p_p5,  Parameter6  p_p6,
				    Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,
				    Parameter10 p_p10, Parameter11 p_p11, Parameter12 p_p12,
				    Parameter13 p_p13, Parameter14 p_p14) const
		{
			sPrecondition(not(IsNull()));

			return (*m_pImplementation)(p_p1,  p_p2, p_p3, p_p4,  p_p5,  p_p6,
				                    p_p7,  p_p8, p_p9, p_p10, p_p11, p_p12,
				                    p_p13, p_p14);
		}

		ResultType operator() (Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,
				    Parameter4  p_p4,  Parameter5  p_p5,  Parameter6  p_p6,
				    Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,
				    Parameter10 p_p10, Parameter11 p_p11, Parameter12 p_p12,
				    Parameter13 p_p13, Parameter14 p_p14, Parameter15 p_p15) const
		{
			sPrecondition(not(IsNull()));

			return (*m_pImplementation)(p_p1,  p_p2,  p_p3, p_p4,  p_p5,  p_p6,
				                    p_p7,  p_p8,  p_p9, p_p10, p_p11, p_p12,
				                    p_p13, p_p14, p_p15);
		}

		ResultType operator() (Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,
				    Parameter4  p_p4,  Parameter5  p_p5,  Parameter6  p_p6,
				    Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,
				    Parameter10 p_p10, Parameter11 p_p11, Parameter12 p_p12,
				    Parameter13 p_p13, Parameter14 p_p14, Parameter15 p_p15,
				    Parameter16 p_p16) const
		{
			sPrecondition(not(IsNull()));

			return (*m_pImplementation)(p_p1,  p_p2,  p_p3,  p_p4,  p_p5,  p_p6,
				                    p_p7,  p_p8,  p_p9,  p_p10, p_p11, p_p12,
				                    p_p13, p_p14, p_p15, p_p16);
		}

		ResultType operator() (Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,
				    Parameter4  p_p4,  Parameter5  p_p5,  Parameter6  p_p6,
				    Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,
				    Parameter10 p_p10, Parameter11 p_p11, Parameter12 p_p12,
				    Parameter13 p_p13, Parameter14 p_p14, Parameter15 p_p15,
				    Parameter16 p_p16, Parameter17 p_p17) const
		{
			sPrecondition(not(IsNull()));

			return (*m_pImplementation)(p_p1,  p_p2,  p_p3,  p_p4,  p_p5,  p_p6,
				                    p_p7,  p_p8,  p_p9,  p_p10, p_p11, p_p12,
				                    p_p13, p_p14, p_p15, p_p16, p_p17);
		}

		ResultType operator() (Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,
				    Parameter4  p_p4,  Parameter5  p_p5,  Parameter6  p_p6,
				    Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,
				    Parameter10 p_p10, Parameter11 p_p11, Parameter12 p_p12,
				    Parameter13 p_p13, Parameter14 p_p14, Parameter15 p_p15,
				    Parameter16 p_p16, Parameter17 p_p17, Parameter18 p_p18) const
		{
			sPrecondition(not(IsNull()));

			return (*m_pImplementation)(p_p1,  p_p2,  p_p3,  p_p4,  p_p5,  p_p6,
				                    p_p7,  p_p8,  p_p9,  p_p10, p_p11, p_p12,
				                    p_p13, p_p14, p_p15, p_p16, p_p17, p_p18);
		}

		ResultType operator() (Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,
				    Parameter4  p_p4,  Parameter5  p_p5,  Parameter6  p_p6,
				    Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,
				    Parameter10 p_p10, Parameter11 p_p11, Parameter12 p_p12,
				    Parameter13 p_p13, Parameter14 p_p14, Parameter15 p_p15,
				    Parameter16 p_p16, Parameter17 p_p17, Parameter18 p_p18,
				    Parameter19 p_p19) const
		{
			sPrecondition(not(IsNull()));

			return (*m_pImplementation)(p_p1,  p_p2,  p_p3,  p_p4,  p_p5,  p_p6,
				                    p_p7,  p_p8,  p_p9,  p_p10, p_p11, p_p12,
				                    p_p13, p_p14, p_p15, p_p16, p_p17, p_p18,
				                    p_p19);
		}

		ResultType operator() (Parameter1  p_p1,  Parameter2  p_p2,  Parameter3  p_p3,
				    Parameter4  p_p4,  Parameter5  p_p5,  Parameter6  p_p6,
				    Parameter7  p_p7,  Parameter8  p_p8,  Parameter9  p_p9,
				    Parameter10 p_p10, Parameter11 p_p11, Parameter12 p_p12,
				    Parameter13 p_p13, Parameter14 p_p14, Parameter15 p_p15,
				    Parameter16 p_p16, Parameter17 p_p17, Parameter18 p_p18,
				    Parameter19 p_p19, Parameter20 p_p20) const
		{
			sPrecondition(not(IsNull()));

			return (*m_pImplementation)(p_p1,  p_p2,  p_p3,  p_p4,  p_p5,  p_p6,
				                    p_p7,  p_p8,  p_p9,  p_p10, p_p11, p_p12,
				                    p_p13, p_p14, p_p15, p_p16, p_p17, p_p18,
				                    p_p19, p_p20);
		}
	};

	typedef fs::Functor<void> VFN;
	typedef fs::Functor<void, TYPELIST_1(std::string)> VFNS;


	template <class BindToFunctor>
	class BinderFirst
			: public FunctorImplementation<typename BindToFunctor::ResultType, typename BindToFunctor::ParameterList::Tail>
	{
		typedef Functor<typename BindToFunctor::ResultType, typename BindToFunctor::ParameterList::Tail> BoundFunctor;
		typedef typename BoundFunctor::Implementation Impl;
		typedef typename BindToFunctor::ActualType1 Bound;
		typedef typename BindToFunctor::ResultType ResultType;
	public:
		typedef fs::ReferenceCountedPointer<typename BoundFunctor::Implementation> RCP;
	public:
		BinderFirst(const BindToFunctor& p_bindToFunctor, Bound p_boundValue)
				: m_bindToFunctor(p_bindToFunctor)
				, m_boundValue(p_boundValue)
		{
		}
	private:
		Bound m_boundValue;
		BindToFunctor m_bindToFunctor;
	public:
		ResultType operator () ()
		{
			return m_bindToFunctor(m_boundValue);
		}

		ResultType operator () (typename Impl::Parameter1 p_1)
		{
			return m_bindToFunctor(m_boundValue, p_1);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
			typename Impl::Parameter2 p_2
			)
		{
			return m_bindToFunctor(m_boundValue, p_1, p_2);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3
				       )
		{
			return m_bindToFunctor(m_boundValue, p_1, p_2, p_3);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4
				       )
		{
			return m_bindToFunctor(m_boundValue, p_1, p_2, p_3, p_4);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5
				       )
		{
			return m_bindToFunctor(m_boundValue, p_1, p_2, p_3, p_4, p_5);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6
				       )
		{
			return m_bindToFunctor(m_boundValue, p_1, p_2, p_3, p_4, p_5, p_6);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7
				       )
		{
			return m_bindToFunctor(m_boundValue, p_1, p_2, p_3, p_4, p_5, p_6, p_7);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8
				       )
		{
			return m_bindToFunctor(m_boundValue, p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9
				       )
		{
			return m_bindToFunctor(m_boundValue, p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9,
					typename Impl::Parameter10 p_10
				       )
		{
			return m_bindToFunctor(m_boundValue, p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9,
					typename Impl::Parameter10 p_10,
					typename Impl::Parameter11 p_11
				       )
		{
			return m_bindToFunctor(m_boundValue, p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9,
					typename Impl::Parameter10 p_10,
					typename Impl::Parameter11 p_11,
					typename Impl::Parameter12 p_12
				       )
		{
			return m_bindToFunctor(m_boundValue, p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9,
					typename Impl::Parameter10 p_10,
					typename Impl::Parameter11 p_11,
					typename Impl::Parameter12 p_12,
					typename Impl::Parameter13 p_13
				       )
		{
			return m_bindToFunctor(m_boundValue, p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9,
					typename Impl::Parameter10 p_10,
					typename Impl::Parameter11 p_11,
					typename Impl::Parameter12 p_12,
					typename Impl::Parameter13 p_13,
					typename Impl::Parameter14 p_14
				       )
		{
			return m_bindToFunctor(m_boundValue, p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13, p_14);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9,
					typename Impl::Parameter10 p_10,
					typename Impl::Parameter11 p_11,
					typename Impl::Parameter12 p_12,
					typename Impl::Parameter13 p_13,
					typename Impl::Parameter14 p_14,
					typename Impl::Parameter15 p_15
				       )
		{
			return m_bindToFunctor(m_boundValue, p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13, p_14, p_15);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9,
					typename Impl::Parameter10 p_10,
					typename Impl::Parameter11 p_11,
					typename Impl::Parameter12 p_12,
					typename Impl::Parameter13 p_13,
					typename Impl::Parameter14 p_14,
					typename Impl::Parameter15 p_15,
					typename Impl::Parameter16 p_16
				       )
		{
			return m_bindToFunctor(m_boundValue, p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13, p_14, p_15, p_16);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9,
					typename Impl::Parameter10 p_10,
					typename Impl::Parameter11 p_11,
					typename Impl::Parameter12 p_12,
					typename Impl::Parameter13 p_13,
					typename Impl::Parameter14 p_14,
					typename Impl::Parameter15 p_15,
					typename Impl::Parameter16 p_16,
					typename Impl::Parameter17 p_17
				       )
		{
			return m_bindToFunctor(m_boundValue, p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9,
					typename Impl::Parameter10 p_10,
					typename Impl::Parameter11 p_11,
					typename Impl::Parameter12 p_12,
					typename Impl::Parameter13 p_13,
					typename Impl::Parameter14 p_14,
					typename Impl::Parameter15 p_15,
					typename Impl::Parameter16 p_16,
					typename Impl::Parameter17 p_17,
					typename Impl::Parameter18 p_18
				       )
		{
			return m_bindToFunctor(m_boundValue, p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17, p_18);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9,
					typename Impl::Parameter10 p_10,
					typename Impl::Parameter11 p_11,
					typename Impl::Parameter12 p_12,
					typename Impl::Parameter13 p_13,
					typename Impl::Parameter14 p_14,
					typename Impl::Parameter15 p_15,
					typename Impl::Parameter16 p_16,
					typename Impl::Parameter17 p_17,
					typename Impl::Parameter18 p_18,
					typename Impl::Parameter19 p_19
				       )
		{
			return m_bindToFunctor(m_boundValue, p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17, p_18, p_19);
		}
	};



	template <class BindToFunctor>
	class IgnoreTheFirst
			: public FunctorImplementation<typename BindToFunctor::ResultType, typename BindToFunctor::ParameterList>
	{
		typedef Functor<typename BindToFunctor::ResultType, typename BindToFunctor::ParameterList::Tail> BoundFunctor;
		typedef typename BoundFunctor::Implementation Impl;
		typedef typename BindToFunctor::ResultType ResultType;
	public:
		typedef fs::ReferenceCountedPointer<typename BoundFunctor::Implementation> RCP;
	public:
		IgnoreTheFirst(const BindToFunctor& p_bindToFunctor)
				: m_bindToFunctor(p_bindToFunctor)
		{
		}
	private:
		BindToFunctor m_bindToFunctor;
	public:
		ResultType operator () (typename Impl::Parameter1 p_1)
		{
			return m_bindToFunctor();
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
			typename Impl::Parameter2 p_2
			)
		{
			return m_bindToFunctor(p_2);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3
				       )
		{
			return m_bindToFunctor(p_2, p_3);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4
				       )
		{
			return m_bindToFunctor(p_2, p_3, p_4);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5
				       )
		{
			return m_bindToFunctor(p_2, p_3, p_4, p_5);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6
				       )
		{
			return m_bindToFunctor(p_2, p_3, p_4, p_5, p_6);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7
				       )
		{
			return m_bindToFunctor(p_2, p_3, p_4, p_5, p_6, p_7);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8
				       )
		{
			return m_bindToFunctor(p_2, p_3, p_4, p_5, p_6, p_7, p_8);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9
				       )
		{
			return m_bindToFunctor(p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9,
					typename Impl::Parameter10 p_10
				       )
		{
			return m_bindToFunctor(p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9,
					typename Impl::Parameter10 p_10,
					typename Impl::Parameter11 p_11
				       )
		{
			return m_bindToFunctor(p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9,
					typename Impl::Parameter10 p_10,
					typename Impl::Parameter11 p_11,
					typename Impl::Parameter12 p_12
				       )
		{
			return m_bindToFunctor(p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9,
					typename Impl::Parameter10 p_10,
					typename Impl::Parameter11 p_11,
					typename Impl::Parameter12 p_12,
					typename Impl::Parameter13 p_13
				       )
		{
			return m_bindToFunctor(p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9,
					typename Impl::Parameter10 p_10,
					typename Impl::Parameter11 p_11,
					typename Impl::Parameter12 p_12,
					typename Impl::Parameter13 p_13,
					typename Impl::Parameter14 p_14
				       )
		{
			return m_bindToFunctor(p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13, p_14);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9,
					typename Impl::Parameter10 p_10,
					typename Impl::Parameter11 p_11,
					typename Impl::Parameter12 p_12,
					typename Impl::Parameter13 p_13,
					typename Impl::Parameter14 p_14,
					typename Impl::Parameter15 p_15
				       )
		{
			return m_bindToFunctor(p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13, p_14, p_15);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9,
					typename Impl::Parameter10 p_10,
					typename Impl::Parameter11 p_11,
					typename Impl::Parameter12 p_12,
					typename Impl::Parameter13 p_13,
					typename Impl::Parameter14 p_14,
					typename Impl::Parameter15 p_15,
					typename Impl::Parameter16 p_16
				       )
		{
			return m_bindToFunctor(p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13, p_14, p_15, p_16);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9,
					typename Impl::Parameter10 p_10,
					typename Impl::Parameter11 p_11,
					typename Impl::Parameter12 p_12,
					typename Impl::Parameter13 p_13,
					typename Impl::Parameter14 p_14,
					typename Impl::Parameter15 p_15,
					typename Impl::Parameter16 p_16,
					typename Impl::Parameter17 p_17
				       )
		{
			return m_bindToFunctor(p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9,
					typename Impl::Parameter10 p_10,
					typename Impl::Parameter11 p_11,
					typename Impl::Parameter12 p_12,
					typename Impl::Parameter13 p_13,
					typename Impl::Parameter14 p_14,
					typename Impl::Parameter15 p_15,
					typename Impl::Parameter16 p_16,
					typename Impl::Parameter17 p_17,
					typename Impl::Parameter18 p_18
				       )
		{
			return m_bindToFunctor(p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17, p_18);
		}

		ResultType operator () (typename Impl::Parameter1 p_1,
					typename Impl::Parameter2 p_2,
					typename Impl::Parameter3 p_3,
					typename Impl::Parameter4 p_4,
					typename Impl::Parameter5 p_5,
					typename Impl::Parameter6 p_6,
					typename Impl::Parameter7 p_7,
					typename Impl::Parameter8 p_8,
					typename Impl::Parameter9 p_9,
					typename Impl::Parameter10 p_10,
					typename Impl::Parameter11 p_11,
					typename Impl::Parameter12 p_12,
					typename Impl::Parameter13 p_13,
					typename Impl::Parameter14 p_14,
					typename Impl::Parameter15 p_15,
					typename Impl::Parameter16 p_16,
					typename Impl::Parameter17 p_17,
					typename Impl::Parameter18 p_18,
					typename Impl::Parameter19 p_19
				       )
		{
			return m_bindToFunctor(p_2, p_3, p_4, p_5, p_6, p_7, p_8, p_9, p_10, p_11, p_12, p_13, p_14, p_15, p_16, p_17, p_18, p_19);
		}
	};

	namespace internal
	{
		template <class FunctorForTraits> struct BinderFirstTraits;
		template <typename R, class TList> struct BinderFirstTraits< Functor<R, TList> >
		{
			typedef typename TList::Tail ParameterList;
			typedef Functor<R, ParameterList> BoundFunctorType;
		};
	}

	template <class BindToFunctor>
			typename internal::BinderFirstTraits<BindToFunctor>::BoundFunctorType
			BindFirst(const BindToFunctor& p_bindToFunctor, typename BindToFunctor::Parameter1 p_boundValue)
	{
		typedef typename internal::BinderFirstTraits<BindToFunctor>::BoundFunctorType BFT;
		typedef typename BinderFirst<BindToFunctor>::RCP RCP;

		RCP p = RCP(new BinderFirst<BindToFunctor>(p_bindToFunctor, p_boundValue));
		return BFT(p);
	}

	template <class BindToFunctor>
			BindToFunctor
			IgnoreFirst(BindToFunctor p_ignoreFirst)
	{
		typedef  BindToFunctor BFT;
		typedef typename IgnoreTheFirst<BindToFunctor>::RCP RCP;

		RCP p = RCP(new IgnoreTheFirst<BindToFunctor>(p_ignoreFirst));
		return BFT(p);
	}

			


	template <class F = VFN>
			    struct nop
	{
	public:
		typedef F Functor;
		typedef typename F::ResultType ResultType;

		typedef typename F::Parameter1 P01;

		inline ResultType operator () () {}
//		inline Result operator () (P01) {}
	};

} /* namespace fs */



namespace fs
{
	template <class TypeFirst, class ResultFunctor> struct BindOne
	{
		typedef typename ResultFunctor::ResultType ResultType;
		typedef typename ResultFunctor::TypeList BaseTypeList;
		typedef ::fs::type::List<TypeFirst, BaseTypeList> TypeList;
		typedef ::fs::Functor<ResultType,  TypeList> Functor;
	};
}



/* End Of File: Functor.h */
