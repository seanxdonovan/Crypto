namespace fs
{
	namespace type
	{
		namespace internal
		{
			template <class T, class U>
					struct ConversionHelper
			{
				typedef byte Small;
				struct Big { char dummy[2]; };
				static Big   Test(...);
				static Small Test(U);
				static T MakeT();
			};
		}



		template <class T, class U>
				struct Conversion
		{
			typedef internal::ConversionHelper<T, U> H;
			enum
			{
				exists = false
			};
			enum
			{
				exists2Way = exists && Conversion<U, T>::exists
			};

			enum {
				sameType = false
			};	
		};

		template <class T>
				struct Conversion<T, T>    
		{
			enum { exists = 1, exists2Way = 1, sameType = 1 };
		};

		template <class T>
				struct Conversion<void, T>    
		{
			enum { exists = 0, exists2Way = 0, sameType = 0 };
		};

		template <class T>
				struct Conversion<T, void>    
		{
			enum { exists = 0, exists2Way = 0, sameType = 0 };
		};

		template <>
				struct Conversion<void, void>    
		{
		public:
			enum
			{
				exists = 1,
				exists2Way = 1,
				sameType = 1
			};
		};

	} /* namespace type */
} /* namespace fs */

/* End Of File: type.Conversion.h */
