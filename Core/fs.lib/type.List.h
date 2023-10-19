

namespace fs
{
	namespace type
	{
		template <class T, class U>
		struct List
		{
			typedef T Head;
			typedef U Tail;
		};

		//
		// Length
		//
		template <class Tlist> struct Length;
		template <> struct Length<Null>
		{
			enum { value = 0 };
		};
		template <class T, class U>
			struct Length< List<T, U> >
		{
			enum { value = 1 + Length<U>::value };
		};


		//
		// At
		//
        template <class TList, ui32 index> struct At;

		template <class Head, class Tail>
				struct At< List<Head, Tail>, 0>
		{
			typedef Head Result;
		};
		template <class Head, class Tail, ui32 ix>
		struct At< List<Head, Tail>, ix>
		{
			typedef typename At<Tail, ix - 1>::Result Result;
		};

		//
		// IndexOf
		//
		template <class TList, class T> struct IndexOf;

		template <class T>
		struct IndexOf<Null, T>
		{
			enum { value = -1 };
		};

		template <class T, class Tail>
		struct IndexOf< List<T, Tail>, T >
		{
			enum { value = 0 };
		};

		template <class Head, class Tail, class T >
		struct IndexOf< List<Head, Tail>, T>
		{
		private:
			enum { tmp = IndexOf<Tail, T>::value };
		public:
			enum { value = (tmp == -1 ? -1 : 1 + tmp) };
		};


		//
		// Rest of the list starting at index
		// Rest<TypeList, 0>::List is the whole list.
		//
		template <class TL, size_t start> struct Rest;

		template <class T, class U> struct Rest<List<T, U>, 0>
		{
			typedef List<T, U> List;
		};

		template <class T, class U, size_t ix> struct Rest<List<T, U>, ix>
		{
			typedef typename Rest<U, ix - 1>::List List;
		};



		//
		// First count types of type list. First 0 is Null.
		// First<TL, Length<TL> is the TL
		//
		template <class TL, size_t count> struct First;
		template <class T, class U> struct First<List<T, U>, 0>
		{
			typedef Null List;
		};

		template <class T> struct First<List<T, ::fs::type::Null>, 1>
		{
			typedef List<T, Null> List;
		};

		template <class T, class U, size_t count> struct First<List<T, U>, count>
		{
			typedef List<T, typename First<U, count - 1>::List> List;
		};


		//
		// Offset<typelist, ix> returns the packed offset of
		// the ix element in the list. TypeList must contain
		// only fixed size elements.
		//
		template <class TypeList, size_t ix>
				struct Offset;

		template <class T, class U>
				struct Offset<fs::type::List<T, U>, 0>
		{
			static const size_t Value = 0;
		};

		template <class T, class U, size_t ix>
				struct Offset<fs::type::List<T, U>, ix>
		{
			// Check to see if this type hase size. Needed to generate and error when the tail is variable
			typedef typename fs::type::At< fs::type::List<T, U>, ix - 1>::Result LeftType;
			static const size_t Value = fs::Sizer<LeftType>::Size
				+ Offset<fs::type::List<T, U>, ix - 1>::Value;
		};

	}

	template <class T, class U> struct Traits<type::List<T,U> >
	{
		static const bool isFixedSize = Traits<T>::isFixedSize && Traits<U>::isFixedSize;
	};

	template <class T, class U> struct Sizer<type::List<T,U> >
	{
		static const size_t Size = Sizer<T>::Size + Sizer<U>::Size;
	};




} /* namespace fs */


#define TYPELIST_0() ::fs::type::Null
#define TYPELIST_1(T1) ::fs::type::List<T1, fs::type::Null>
#define TYPELIST_2(T1, T2) ::fs::type::List<T1, TYPELIST_1(T2) >
#define TYPELIST_3(T1, T2, T3) ::fs::type::List<T1, TYPELIST_2(T2, T3) >
#define TYPELIST_4(T1, T2, T3, T4) ::fs::type::List<T1, TYPELIST_3(T2, T3, T4) >
#define TYPELIST_5(T1, T2, T3, T4, T5) ::fs::type::List<T1, TYPELIST_4(T2, T3, T4, T5) >
#define TYPELIST_6(T1, T2, T3, T4, T5, T6) ::fs::type::List<T1, TYPELIST_5(T2, T3, T4, T5, T6) >
#define TYPELIST_7(T1, T2, T3, T4, T5, T6, T7) ::fs::type::List<T1, TYPELIST_6(T2, T3, T4, T5, T6, T7) >
#define TYPELIST_8(T1, T2, T3, T4, T5, T6, T7, T8) ::fs::type::List<T1, TYPELIST_7(T2, T3, T4, T5, T6, T7, T8) >
#define TYPELIST_9(T1, T2, T3, T4, T5, T6, T7, T8, T9) ::fs::type::List<T1, TYPELIST_8(T2, T3, T4, T5, T6, T7, T8, T9) >
#define TYPELIST_10(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) ::fs::type::List<T1, TYPELIST_9(T2, T3, T4, T5, T6, T7, T8, T9, T10) >
#define TYPELIST_11(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11) ::fs::type::List<T1, TYPELIST_10(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11) >
#define TYPELIST_12(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12) ::fs::type::List<T1, TYPELIST_11(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12) >
#define TYPELIST_13(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13) ::fs::type::List<T1, TYPELIST_12(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13) >
#define TYPELIST_14(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14) ::fs::type::List<T1, TYPELIST_13(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14) >
#define TYPELIST_15(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15) ::fs::type::List<T1, TYPELIST_14(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15) >
#define TYPELIST_16(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16) ::fs::type::List<T1, TYPELIST_15(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16) >
#define TYPELIST_17(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17) ::fs::type::List<T1, TYPELIST_16(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17) >
#define TYPELIST_18(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18) ::fs::type::List<T1, TYPELIST_17(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18) >
#define TYPELIST_19(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19) ::fs::type::List<T1, TYPELIST_18(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19) >
#define TYPELIST_20(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20) ::fs::type::List<T1, TYPELIST_19(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20) >
#define TYPELIST_21(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21) ::fs::type::List<T1, TYPELIST_20(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21) >
#define TYPELIST_22(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22) ::fs::type::List<T1, TYPELIST_21(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22) >
#define TYPELIST_23(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23) ::fs::type::List<T1, TYPELIST_22(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23) >
#define TYPELIST_24(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24) ::fs::type::List<T1, TYPELIST_23(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24) >
#define TYPELIST_25(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25) ::fs::type::List<T1, TYPELIST_24(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25) >
#define TYPELIST_26(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26) ::fs::type::List<T1, TYPELIST_25(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26) >
#define TYPELIST_27(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27) ::fs::type::List<T1, TYPELIST_26(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27) >
#define TYPELIST_28(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28) ::fs::type::List<T1, TYPELIST_27(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28) >


/* End Of File: type.List.h */
