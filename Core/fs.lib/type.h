
namespace fs
{

	namespace type
	{

		class Null
		{
		};

		struct Empty
		{
		};

		template <bool flag, typename T, typename U>
		struct Select
		{
			typedef T Result;
		};
		template <typename T, typename U>
		struct Select<false, T, U>
		{
			typedef U Result;
		};


		template < class Type>
				struct TypeToType
		{
			typedef Type Type;
		};

		template <ui32 ui>
				struct ui32ToType
		{
			static const ui32 Value = ui;
		};


		inline const char *TypeName(const std::string&)
		{
			return "const std::string&";
		};

		inline const char *TypeName(std::string&)
		{
			return "std::string&";
		};

		inline const char *TypeName(si8)
		{
			return "si8";
		};

		inline const char *TypeName(si16)
		{
			return "si16";
		};

		inline const char *TypeName(si32)
		{
			return "si32";
		};

		inline const char *TypeName(si64)
		{
			return "si64";
		};

		inline const char *TypeName(byte)
		{
			return "byte";
		};

		inline const char *TypeName(word)
		{
			return "word";
		};

		inline const char *TypeName(dword)
		{
			return "dword";
		};

		inline const char *TypeName(qword)
		{
			return "qword";
		};


	} /* namespace type */

	template<> struct Traits<type::Null>
	{
		static const bool isFixedSize = true;
	};

	template<> struct Sizer<type::Null>
	{
		static const size_t Size = 0;
	};


	std::string format(fs::type::Null);
} /* namespace fs */

inline bool operator != (fs::type::Null, fs::type::Null)
{
	return false;
}



/* End Of File: type.h */
