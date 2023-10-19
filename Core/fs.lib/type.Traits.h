namespace fs
{
	namespace type
	{
	template <typename T>
		class Traits
		{
		private:
			template <class U> struct PointerTraits
			{
				enum { result = false };
				typedef Null PointeeType;
			};

			template <class U> struct PointerTraits<U*>
			{
				enum { result = true };
				typedef U PointeeType;
			};
		public:
			enum { IsPointer = PointerTraits<T>::result };
			typedef typename PointerTraits<T>::PointeeType PointeeType;


			//
			// ReferenceTraits
			//
		private:
			template <class U> struct ReferenceTraits
			{
				enum { result = false };
				typedef U  ReferenceBaseType;
			};

			template <class U> struct ReferenceTraits<U&>
			{
				enum { result = true };
				typedef U ReferenceBaseType;
			};

		public:
			enum { IsReference = ReferenceTraits<T>::result };
			typedef typename ReferenceTraits<T>::ReferenceBaseType ReferenceBaseType;

			//
			// PointerToMember
			//
		private:
			template <class U> struct PointerToMember
			{
				enum { result = false };
			};

			template <class U, class V>
					struct PointerToMember<U V::*>
			{
				enum { result = true };
			};

		public:
			enum {IsMemberPointer = PointerToMember<T>::result};

		private:
			typedef TYPELIST_4(ui8, ui16, ui32, ui64) UnsignedIntegers;
			typedef TYPELIST_4(si8, si16, si32, si64) SignedIntegers;
			typedef TYPELIST_3(bool, char, wchar_t) OtherIntegers;
			typedef TYPELIST_3(float, double, long double) Floats;

		public:
			enum { IsUnsignedInteger = (IndexOf<UnsignedIntegers, T>::value >= 0) };
			enum { IsSignedInteger   = (IndexOf<SignedIntegers, T>::value >= 0) };
			enum { IsOtherInteger    = (IndexOf<OtherIntegers, T>::value >= 0) };
			enum { IsInteger         = (IsUnsignedInteger || IsSignedInteger || IsOtherInteger) };
			enum { IsFloat           = (IndexOf<Floats, T>::value >= 0) };
			enum { IsArithmetic      = (IsFloat || IsInteger) };



			//
			// isConst
			//
		public:
			template <class U> struct UnConst
			{
				typedef U Result;
				enum { isConst = 0 };
			};

			template <class U> struct UnConst<const U>
			{
				typedef U Result;
				enum { isConst = 1 };
			};

			enum { isConst = UnConst<T>::isConst };
			typedef typename UnConst<T>::Result NonConstType;

			//
			// volatile
			//
		public:
			template <class U> struct UnVolatile
			{
				typedef U Result;
				enum { isVolatile = 0 };
			};

			template <class U> struct UnVolatile<volatile U>
			{
				typedef U Result;
				enum { isVolatile = 1 };
			};


			enum { isVolatile = UnVolatile<T>::isVolatile };
			typedef typename UnVolatile<T>::Result NonVolatileType;
			typedef typename UnVolatile<typename UnConst<T>::Result>::Result 
			    UnqualifiedType;


		public:
			typedef typename 
					Select<
					IsArithmetic || IsPointer || IsMemberPointer || IsReference,
					T,
					const typename UnConst<ReferenceBaseType>::Result&
					>::Result ParameterType;

		};
	
	} /* namespace type */

} /* namespace fs */

namespace fs
{
	template <class T> struct PT
	{
		typedef typename fs::type::Traits<T>::ParameterType T;
	};
}

/* End Of File: type.Traits.h */
