
namespace fs
{
	template <bool> struct CompileTimeCheck;
	template <> struct CompileTimeCheck<true> {};
}
#define ctAssert(expr, msg) do \
			    { \
				    fs::CompileTimeCheck<((expr))> ERROR_##msg;\
				    (void)ERROR_##msg; \
			    } while (false)

namespace fs
{

	struct EnvironmentSingleThreaded
	{
	};

	struct EnvironmentMultiThreaded
	{
	};

	typedef EnvironmentMultiThreaded Environment;

	//
	// Types
	//
	typedef bool boolean;


	typedef unsigned char    byte;
	typedef unsigned short   word;
	typedef unsigned long    dword;
	typedef unsigned __int64 qword;
	struct DQWord {
		qword m_hi;
		qword m_low;
		inline DQWord& operator = (const qword p_v) {
			m_hi = 0;
			m_low = p_v;
			return *this;
		}
	};
	typedef DQWord  dqword;

	typedef unsigned char    ui8;
	typedef unsigned short   ui16;
	typedef unsigned long    ui32;
	typedef unsigned __int64 ui64;
	typedef dqword ui128;

	typedef signed char      si8;
	typedef signed short     si16;
	typedef signed long      si32;
	typedef signed __int64   si64;
	typedef struct SI128 {si64 m_hi; ui64 m_low;} si128;

	typedef double Double;

	struct Overflow {};
	struct Underflow {};
	struct DivideByZero {};

	struct Guid : GUID
	{
		Guid()
		{
		}

		inline Guid(const GUID& p_rhs)
		{
			Data1 = p_rhs.Data1;
			Data2 = p_rhs.Data2;
			Data3 = p_rhs.Data3;
			Data4[0] = p_rhs.Data4[0];
			Data4[1] = p_rhs.Data4[1];
			Data4[2] = p_rhs.Data4[2];
			Data4[3] = p_rhs.Data4[3];
			Data4[4] = p_rhs.Data4[4];
			Data4[5] = p_rhs.Data4[5];
			Data4[6] = p_rhs.Data4[6];
			Data4[7] = p_rhs.Data4[7];
		}
	};

	bool lt(const GUID& p_lhs, const GUID& p_rhs);

	typedef std::string string;
	typedef std::wstring unicode;
}

inline bool operator < (const GUID& p_lhs, const GUID& p_rhs)
{
	return fs::lt(p_lhs, p_rhs);
}


namespace fs
{

	template <class U> struct Traits
	{
		static const bool isFixedSize = false;
	};

	template<> struct Traits<bool>
	{
		static const bool isFixedSize = true;
	};

#if defined(_M_IX86) // size_t is it's own type.
	template <> struct Traits<size_t>
	{
		static const bool isFixedSize = true;

		static const size_t Zero = 0;
		static const size_t Minimum = 0;
		static const size_t Maximum = 0xFFffFFff;
		static const size_t Size = 4;
		static const size_t BitCount = 32;
	};
#endif

	template<> struct Traits<double>
	{
		static const bool isFixedSize = true;
		static const double Maximum;
		static const double Minimum;
	};

	template <> struct Traits<byte>
	{
		static const bool isFixedSize = true;

		static const byte Zero = 0;
		static const byte Minimum = 0;
		static const byte Maximum = 0xFF;
		static const size_t Size = sizeof(byte);
		static const size_t BitCount = 8;

		typedef word dword_t;
	};

	template <> struct Traits<word>
	{
		static const bool isFixedSize = true;

		static const word Zero = 0;
		static const word Minimum = 0;
		static const word Maximum   = 0xFFFF;
		static const size_t Size = sizeof(word);

		typedef byte HalfWordType;
		static const size_t BitCount = Traits<byte>::BitCount * Size;
		static const HalfWordType HalfWordMask = Traits<HalfWordType>::Maximum;

		typedef byte hword_t;
		typedef dword dword_t;

		static const size_t MaxPowerOf10 = 4; // 9999 can be stored 99999 cannot
	};

	template <> struct Traits<dword>
	{
		static const bool isFixedSize = true;

		static const dword Zero = 0;
		static const dword Minimum = 0;
		static const dword Maximum = 0xFFFFFFFF;
		static const size_t Size = sizeof(dword);
		typedef word HalfWordType;
		static const size_t BitCount = Traits<byte>::BitCount * Size;
		static const HalfWordType HalfWordMask = Traits<HalfWordType>::Maximum;

		typedef word hword_t;
		typedef qword dword_t;
	};

	template <> struct Traits<qword>
	{
		static const bool isFixedSize = true;

		static const qword Zero = 0;
		static const qword Minimum = 0;
		static const qword Maximum = 0xFFffFFffFFffFFff;
		static const size_t Size = sizeof(qword);

		typedef dword HalfWordType;
		static const size_t BitCount = Traits<byte>::BitCount * Size;
		static const HalfWordType HalfWordMask = Traits<HalfWordType>::Maximum;

		typedef dword hword_t;
		typedef dqword dword_t;


	};

	template <> struct Traits<dqword>
	{
		static const bool isFixedSize = true;

		static const size_t Size = sizeof(dqword);
		typedef qword HalfWordType;
		static const HalfWordType HalfWordMask = Traits<HalfWordType>::Maximum;

		typedef qword hword_t;
	};

	template <> struct Traits<si8>
	{
		static const bool isFixedSize = true;

		static const si8 Zero = 0;
		static const si8  Maximum    = 0x7F;
		static const si8  Minimum    = 0x80i8;
		static const size_t Size = sizeof(si8);
	};

	template <> struct Traits<si16>
	{
		static const bool isFixedSize = true;

		static const si16 Zero = 0;
		static const si16 Maximum   = 0x7FFF;
		static const si16 Minimum   = 0x8000i16;
		static const size_t Size = sizeof(si16);
	};

	template <> struct Traits<si32>
	{
		static const bool isFixedSize = true;

		static const si32 Zero = 0;
		static const si32 Maximum   = 0x7FFFFFFF;
		static const si32 Minimum   = 0x80000000i32;
		static const size_t Size = sizeof(si32);
	};

	template <> struct Traits<si64>
	{
		static const bool isFixedSize = true;

		static const si64 Zero = 0;
		static const si64 Maximum   = 0x7FffFFffFFffFFff;
		static const si64 Minimum   = 0x8000000000000000i64;
		static const size_t Size = sizeof(si64);
	};

	template <> struct Traits<si128>
	{
		static const bool isFixedSize = true;

		static const size_t Size = sizeof(si128);
	};


	template <class U> struct Sizer
	{
	};
#if defined(_M_IX86)
	template <> struct Sizer<size_t>
	{
		static const size_t Size = sizeof(size_t);
	};
#endif

	template <> struct Sizer<double>
	{
		static const size_t Size = sizeof(double);
	};

	template <> struct Sizer<byte>
	{
		static const size_t Size = sizeof(byte);
	};

	template <> struct Sizer<word>
	{
		static const size_t Size = sizeof(word);
	};

	template <> struct Sizer<dword>
	{
		static const size_t Size = sizeof(dword);
	};

	template <> struct Sizer<qword>
	{
		static const size_t Size = sizeof(qword);
	};

	template <> struct Sizer<dqword>
	{
		static const size_t Size = sizeof(dqword);
	};

	template <> struct Sizer<si8>
	{
		static const size_t Size = sizeof(si8);
	};

	template <> struct Sizer<si16>
	{
		static const size_t Size = sizeof(si16);
	};

	template <> struct Sizer<si32>
	{
		static const size_t Size = sizeof(si32);
	};

	template <> struct Sizer<si64>
	{
		static const size_t Size = sizeof(si64);
	};

	template <> struct Sizer<si128>
	{
		static const size_t Size = sizeof(si128);
	};


	template <> struct Sizer<bool>
	{
		static const size_t Size = Sizer<fs::byte>::Size;
	};



	typedef wchar_t UnicodeCharacter;
	typedef std::wstring UnicodeString;

	typedef UnicodeCharacter UC;
	typedef UnicodeString    US;

/*
	//
	// Maximums
	//
	namespace maximum
	{
		const byte byte   = 0xFF;
		const word word   = 0xFFFF;
		const dword dword = 0xFFFFFFFF;
		const qword qword = 0xFFffFFffFFffFFff;

		const ui8  ui8    = 0xFF;
		const ui16 ui16   = 0xFFFF;
		const ui32 ui32   = 0xFFFFFFFF;
		const ui64 ui64   = 0xFFffFFffFFffFFff;

		const si8  si8    = 0x7F;
		const si16 si16   = 0x7FFF;
		const si32 si32   = 0x7FFFFFFF;
		const si64 si64   = 0x7FffFFffFFffFFff;
	}
*/
	template <class T>
	struct Maximum;

/*
	template <>
		struct Maximum<byte>
		{
			static const byte Value = maximum::byte;
		};

	template <>
			struct Maximum<word>
	{
		static const word Value = maximum::word;
	};

	template <>
			struct Maximum<dword>
	{
		static const dword Value = maximum::dword;
	};

	template <>
			struct Maximum<qword>
	{
		static const qword Value = maximum::qword;
	};

	template <>
			struct Maximum<si8>
	{
		static const si8 Value = maximum::si8;
	};

	template <>
			struct Maximum<si16>
	{
		static const si16 Value = maximum::si16;
	};

	template <>
			struct Maximum<si32>
	{
		static const si32 Value = maximum::si32;
	};

	template <>
			struct Maximum<si64>
	{
		static const si64 Value = maximum::si64;
	};


	template<class T>
		inline T MaximumValue(T)
	{
		return Maximum<T>::Value;
	}
*/

/*
	//
	// Minimums
	//

	namespace minimum
	{
		const byte byte   = 0;
		const word word   = 0;
		const dword dword = 0;
		const qword qword = 0;

		const ui8  ui8    = 0;
		const ui16 ui16   = 0;
		const ui32 ui32   = 0;
		const ui64 ui64   = 0;

		const si8  si8    = 0x80i8;
		const si16 si16   = 0x8000i16;
		const si32 si32   = 0x80000000i32;
		const si64 si64   = 0x8000000000000000i64;
	}

	template<typename T>
			T minimum_value(T v = 0)
	{
	}

	inline const byte  minimum_value(byte v = 0)
	{
		return minimum::byte;
	}

	inline const word  minimum_value(word v = 0)
	{
		return minimum::word;
	}

	inline const dword  minimum_value(dword v = 0)
	{
		return minimum::dword;
	}

	inline const qword minimum_value(qword v = 0)
	{
		return minimum::qword;
	}

//	inline const ui8   minimum_value(ui8 v = 0)
//	{
//		return minimum::ui8;
//	}
//
//	inline const ui16  minimum_value(ui16 v = 0)
//	{
//		return minimum::ui16;
//	}
//
//	inline const ui32  minimum_value(ui32 v = 0)
//	{
//		return minimum::ui32;
//	}
//
//	inline const ui64  minimum_value(ui64 v = 0)
//	{
//		return minimum::ui64;
//	}

	inline const si8   minimum_value(si8 v = 0)
	{
		return minimum::si8;
	}

	inline const si16  minimum_value(si16 v = 0)
	{
		return minimum::si16;
	}

	inline const si32  minimum_value(si32 v = 0)
	{
		return minimum::si32;
	}

	inline const si64  minimum_value(si64 v = 0)
	{
		return minimum::si64;
	}
*/
	template <class T>
	struct Minimum;

/*
	template <>
		struct Minimum<byte>
		{
			static const byte Value = minimum::byte;
		};

	template <>
			struct Minimum<word>
	{
		static const word Value = minimum::word;
	};

	template <>
			struct Minimum<dword>
	{
		static const dword Value = minimum::dword;
	};

	template <>
			struct Minimum<qword>
	{
		static const qword Value = minimum::qword;
	};

	template <>
			struct Minimum<si8>
	{
		static const si8 Value = minimum::si8;
	};

	template <>
			struct Minimum<si16>
	{
		static const si16 Value = minimum::si16;
	};

	template <>
			struct Minimum<si32>
	{
		static const si32 Value = minimum::si32;
	};

	template <>
			struct Minimum<si64>
	{
		static const si64 Value = minimum::si64;
	};

	template <class T>
		inline T MinimumValue(T)
	{
//		return Minimum<T>::Value;
//		return Minimum<T>::Value;
		return traits<T>::Miniumn
	}

*/
	//
	// Size for basic types
	//

	template <typename T> size_t Size(const T *)
	{
	}

	inline size_t Size(const byte *)
	{
		return sizeof(byte);
	}

	inline size_t Size(const word *)
	{
		return sizeof(word);
	}

	inline size_t Size(const dword *)
	{
		return sizeof(dword);
	}

	inline size_t Size(const qword *)
	{
		return sizeof(qword);
	}

	inline size_t Size(const dqword *)
	{
		return sizeof(dqword);
	}

	inline size_t Size(const si8 *)
	{
		return sizeof(si8);
	}

	inline size_t Size(const si16 *)
	{
		return sizeof(si16);
	}

	inline size_t Size(const si32 *)
	{
		return sizeof(si32);
	}

	inline size_t Size(const si64 *)
	{
		return sizeof(si64);
	}

	inline size_t Size(const si128 *)
	{
		return sizeof(si128);
	}

	inline size_t Size(const Double *)
	{
		return sizeof(Double);
	}

	inline size_t Size(const Guid *)
	{
		return sizeof(Guid);
	}

	std::string format(const char *p_strFormat, va_list p_arglist);
//	std::string __cdecl format(const char *strFormat, ...);
	std::string format(const char *p_s);
	std::string format(const std::string& p_s);
	std::string format(const char p_c);

	std::string format(fs::byte   p_value);
	std::string format(fs::word   p_value);
	std::string format(fs::dword  p_value);
	std::string format(fs::qword  p_value);
	std::string format(fs::dqword p_value);

	std::string format(fs::si8   p_value);
	std::string format(fs::si16  p_value);
	std::string format(fs::si32  p_value);
	std::string format(fs::si64  p_value);
	std::string format(fs::si128 p_value);

	std::string format(double p_value);
	std::string format(double p_value, ::fs::dword precision);

	std::string format(const GUID& guid);

	std::string format(const Guid& p_guid);

	std::string format(const std::wstring& p_sWide);


	std::string fill(const std::string& p_s, size_t p_width, fs::byte p_ch = ' ', bool p_trailing = true);

	bool Convert(const std::string& p_s, bool *p_pValue);
	inline bool Convert(const std::string& p_s, std::string *p_ps)
	{
		*p_ps = p_s;
		return true;
	}

	bool convertHex(const std::string& p_s, fs::byte *p_pValue);
	bool convertHex(const std::string& p_s, fs::word *p_pValue);
	bool convertHex(const std::string& p_s, fs::dword *p_pValue);
	bool convertHex(const std::string& p_s, fs::qword *p_pValue);

	bool convert(const char *p_pText, fs::byte  *p_pValue, fs::dword p_base = 10);
	bool convert(const char *p_pText, fs::word  *p_pValue, fs::dword p_base = 10);
	bool convert(const char *p_pText, fs::dword *p_pValue, fs::dword p_base = 10);
	bool convert(const char *p_pText, fs::qword *p_pValue);

	bool convert(const char *p_pText, fs::si8  *p_pValue);
	bool convert(const char *p_pText, fs::si16 *p_pValue);
	bool convert(const char *p_pText, fs::si32 *p_pValue);
	bool convert(const char *p_pText, fs::si64 *p_pValue);

	bool convert(const char *p_pText, double *p_pValue);

	bool Convert(const std::string& p_s, fs::byte *p_pValue);
	bool Convert(const std::string& p_s, fs::word *p_pValue);
	bool Convert(const std::string& p_s, fs::dword *p_pValue);
	bool Convert(const std::string& p_s, fs::qword *p_pValue);

	bool Convert(const std::string& p_s, fs::si8  *p_pValue);
	bool Convert(const std::string& p_s, fs::si16 *p_pValue);
	bool Convert(const std::string& p_s, fs::si32 *p_pValue);
	bool Convert(const std::string& p_s, fs::si64 *p_pValue);

	bool Convert(const std::string& p_s, double *p_pValue);
	void OnRaiseError(void (*p_fcn)());
	void raiseError(const char *strFileName, const si32 lineNumber, const char *strMsg);
	void assertionFailure(const char *strFileName, const si32 lineNumber, const char *strMsg);
	void traceOutput(const char *strFileName, const si32 lineNumber, const char *strMsg);
	bool IsDebuggerPresent();

	std::string JoinStrings(const std::vector<std::string>& arrStrings, const char chJoin);
	void Replace(const char p_find, const char p_replace, std::string *p_pString);


	bool IsValidGUID(const char *strGUID);
	void Convert(const char *strGUID, GUID *pGUID);
	bool Convert(const char *strUINT, UINT *pUINT);
	bool Convert(const char *strDouble, double *pDouble);
	bool Convert(const char *strInt, int *pInt);

	
	word pack(byte p_high, byte p_low);
	dword pack(word p_high, word p_low);
	qword pack(dword p_high, dword p_low);
	dqword pack(qword p_high, qword p_low);

	void unpack(word p_word, byte *p_pHighByte, byte *p_pLowByte);
	void unpack(dword p_dword, word *p_pHighWord, word *p_pLowWord);
	void unpack(qword p_qword, dword *p_pHighDword, dword *p_pLowDword);

	dword rotateLeft(dword p_value, dword p_nBits);

	dword RotateRight(dword p_value, dword p_nBits);
	qword RotateRight(qword p_value, qword p_nBits);

	dword ShiftRight(dword p_value, size_t p_nBits);
	qword ShiftRight(qword p_value, size_t p_nBits);
	dqword ShiftRight(dqword p_value, size_t p_nBits);

	dword ShiftLeft(dword p_value, size_t p_nBits);
	qword ShiftLeft(qword p_value, size_t p_nBits);

	dword bitsSet(byte b);
	dword bitsSet(word w);
	dword bitsSet(dword dw);
	dword bitsSet(qword qw);

	dword high_bit(word p_w);
	dword low_bit0(word p_w);

	template<class word_t>
			inline typename fs::Traits<word_t>::hword_t hiword(word_t p_w)
	{
		typedef typename fs::Traits<word_t>::hword_t hword_t;
		return hword_t((p_w >> fs::Traits<hword_t>::BitCount) & fs::Traits<hword_t>::Maximum);
	}

	template<class word_t>
			inline typename fs::Traits<word_t>::hword_t loword(word_t p_w)
	{
		typedef typename fs::Traits<word_t>::hword_t hword_t;
		return hword_t(p_w & fs::Traits<hword_t>::Maximum);
	}

	inline qword hiword(const dqword& p_w)
	{
		return p_w.m_hi;
	}

	inline qword loword(const dqword& p_w)
	{
		return p_w.m_low;
	}


	template <class T>
		inline typename Traits<T>::HalfWordType HighPart(T p_v)
	{
		return static_cast<Traits<T>::HalfWordType>( p_v >> (Traits<T>::BitCount / 2) & Traits<T>::HalfWordMask);
	}


	template <class T>
		inline typename Traits<T>::HalfWordType LowPart(T p_value)
	{
		return static_cast<Traits<T>::HalfWordType>((p_value & Traits<T>::HalfWordMask));
	}

	template <class T> bool IsNull(T);

	template <class T> inline bool IsNull(T* p_p)
	{
		return 0 == p_p;
	}

	class Elapsed
	{
	private:
		const fs::qword m_ticksPerSecond;
		fs::qword m_start;
	public:
		Elapsed();
		explicit Elapsed(fs::qword p_start);
		fs::qword us() const;
		fs::qword ms() const;
		void Start();
	};



	fs::qword TickCount();
	fs::qword TicksPerSecond();


	inline std::string format(const std::string& p_s)
	{
		return p_s;
	}


	inline dword rotateLeft(dword p_value, dword p_nBits)
	{
		// sPrecondition(p_nBits < 32)
		return (p_value << (p_nBits & 0x1F) | p_value >> (32 - (p_nBits & 0x1F)));
	}


	inline dword RotateRight(dword p_value, dword p_nBits)
	{
		// sPrecondition(p_nBits < 32
		return (p_value >> (p_nBits & 0x1f) | p_value << (32 - (p_nBits & 0x1F)));
	}
	inline qword RotateRight(qword p_value, qword p_nBits)
	{
		// sPrecondition(p_nBits < 64
		return (p_value >> (p_nBits & 0x3F) | p_value << (64 - (p_nBits & 0x3F)));
	}

	inline dword ShiftRight(dword p_value, size_t p_nBits)
	{
		return p_value >> p_nBits;
	}

	inline qword ShiftRight(qword p_value, size_t p_nBits)
	{
		return p_value >> p_nBits;
	}

	inline dqword ShiftRight(dqword p_value, size_t p_nBits)
	{
		dqword tmp;
		tmp.m_hi = ShiftRight(p_value.m_hi, p_nBits);
		tmp.m_low  = ShiftRight(p_value.m_low, p_nBits);
		tmp.m_low |= ShiftLeft(p_value.m_hi, 128 - p_nBits);

		return tmp;
	}

	inline dword ShiftLeft(dword p_value, size_t p_nBits)
	{
		return p_value << p_nBits;
	}

	inline qword ShiftLeft(qword p_value, size_t p_nBits)
	{
		return p_value << p_nBits;
	}


	double round(double p_value, fs::dword p_nSignificantDigits);





	inline fs::dword smaller_of(fs::dword p_a, fs::dword p_b)
	{
		if (p_a < p_b)
		{
			return p_a;
		}
		return p_b;
	}


	const byte CR = 0xD;
	const byte LF = 0xA;
	const byte TAB = 0x9;
}

inline bool not(bool expression)
{
	return !expression;
}

bool operator <  (const fs::si128& p_lhs, const fs::si128& p_rhs);
bool operator <= (const fs::si128& p_lhs, const fs::si128& p_rhs);
bool operator >  (const fs::si128& p_lhs, const fs::si128& p_rhs);
bool operator >= (const fs::si128& p_lhs, const fs::si128& p_rhs);
bool operator == (const fs::si128& p_lhs, const fs::si128& p_rhs);
bool operator != (const fs::si128& p_lhs, const fs::si128& p_rhs);


namespace fs
{
	inline fs::byte abs(fs::si8 p_v)
	{
		if (p_v < 0)
		{
			return -p_v;
		}
		return p_v;
	}

	inline fs::word abs(fs::si16 p_v)
	{
		if (p_v < 0)
		{
			return -p_v;
		}
		return p_v;
	}

	inline fs::dword abs(fs::si32 p_v)
	{
		if (p_v < 0)
		{
			return -p_v;
		}
		return p_v;
	}

	inline fs::qword abs(fs::si64 p_v)
	{
		if (p_v < 0)
		{
			return -p_v;
		}
		return p_v;
	}
}


namespace fs
{
	//
	// Arithmetic Result types - what is the result type of a
	// binary operation LeftType op RightType
	//

	template <class LeftType, class TypeRight>  struct ArithmeticResultType;

	template <> struct ArithmeticResultType<double, double>
	{
		typedef double Type;
	};

	template <> struct ArithmeticResultType<ui64, ui64>
	{
		typedef ui64 Type;
	};

	template <> struct ArithmeticResultType<si64, si64>
	{
		typedef si64 Type;
	};

	template <> struct ArithmeticResultType<si32, si32>
	{
		typedef si32 Type;
	};

	template <> struct ArithmeticResultType<si16, si16>
	{
		typedef si16 Type;
	};

	template <> struct ArithmeticResultType<si8, si8>
	{
		typedef si8 Type;
	};

	template <> struct ArithmeticResultType<double, si64>
	{
		typedef double Type;
	};

	template <> struct ArithmeticResultType<double, si32>
	{
		typedef double Type;
	};

	template <> struct ArithmeticResultType<double, si16>
	{
		typedef double Type;
	};

	template <> struct ArithmeticResultType<double, si8>
	{
		typedef double Type;
	};


	template <> struct ArithmeticResultType<si64, double>
	{
		typedef double Type;
	};

	template <> struct ArithmeticResultType<si64, si32>
	{
		typedef si64 Type;
	};

	template <> struct ArithmeticResultType<si64, si16>
	{
		typedef si64 Type;
	};

	template <> struct ArithmeticResultType<si64, si8>
	{
		typedef si64 Type;
	};



	template <class Type, class TypeResult> struct unary_op
	{
		typedef Type Type;
		typedef TypeResult TypeResult;
	};


	template <class Type> struct unary_minus : public unary_op<Type, typename ArithmeticResultType<Type, Type>::Type >
	{
		inline TypeResult operator () (Type p_) const
		{
			return - p_;
		}
	};

	template <class Type> struct unary_plus : public unary_op<Type, typename ArithmeticResultType<Type, Type>::Type >
	{
		inline TypeResult operator () (Type p_) const
		{
			return + p_;
		}
	};

	template <class Type> struct logical_not : public unary_op<Type, bool >
	{
		inline TypeResult operator () (Type p_) const
		{
			return ! p_;
		}
	};

	template <class TypeLeft, class TypeRight, class TypeResult> struct binary_op
	{
		typedef TypeLeft  TypeLeft;
		typedef TypeRight TypeRight;
		typedef TypeResult TypeResult;
	};

	template <class TypeLeft, class TypeRight>
			struct add : public binary_op<TypeLeft, TypeRight, typename ArithmeticResultType<TypeLeft, TypeRight>::Type>
	{
		inline TypeResult operator () (const TypeLeft& p_lhs, const TypeRight& p_rhs) const
		{
			return p_lhs + p_rhs;
		}
	};

	template <class TypeLeft, class TypeRight>
			struct sub : public binary_op<TypeLeft, TypeRight, typename ArithmeticResultType<TypeLeft, TypeRight>::Type>
	{
		inline TypeResult operator () (const TypeLeft& p_lhs, const TypeRight& p_rhs) const
		{
			return p_lhs - p_rhs;
		}
	};

	template <class TypeLeft, class TypeRight>
			struct mul : public binary_op<TypeLeft, TypeRight, typename ArithmeticResultType<TypeLeft, TypeRight>::Type>
	{
		inline TypeResult operator () (const TypeLeft& p_lhs, const TypeRight& p_rhs) const
		{
			return p_lhs * p_rhs;
		}
	};

	template <class TypeLeft, class TypeRight>
			struct div : public binary_op<TypeLeft, TypeRight, typename ArithmeticResultType<TypeLeft, TypeRight>::Type>
	{
		inline TypeResult operator () (const TypeLeft& p_lhs, const TypeRight& p_rhs) const
		{
			return p_lhs / p_rhs;
		}
	};

	template <class TypeLeft, class TypeRight>
			struct mod : public binary_op<TypeLeft, TypeRight, typename ArithmeticResultType<TypeLeft, TypeRight>::Type>
	{
		inline TypeResult operator () (const TypeLeft& p_lhs, const TypeRight& p_rhs) const
		{
			return p_lhs % p_rhs;
		}
	};


	template <class TypeLeft, class TypeRight>
			struct comparison_op : public binary_op<TypeLeft, TypeRight, bool>
	{
	};
			
	

	template <class TypeLeft, class TypeRight = TypeLeft>
			struct equal_to : public comparison_op<TypeLeft, TypeRight>
	{
		inline bool operator () (const TypeLeft& p_lhs, const TypeRight& p_rhs) const
		{
			return p_lhs == p_rhs;
		}
	};

	template <class TypeLeft, class TypeRight = TypeLeft>
			struct not_equal_to : public comparison_op<TypeLeft, TypeRight>
	{
		inline bool operator () (const TypeLeft& p_lhs, const TypeRight& p_rhs) const
		{
			return p_lhs != p_rhs;
		}
	};

	template <class TypeLeft, class TypeRight = TypeLeft>
			struct greater : public comparison_op<TypeLeft, TypeRight>
	{
		inline bool operator () (const TypeLeft& p_lhs, const TypeRight& p_rhs) const
		{
			return p_lhs > p_rhs;
		}
	};

	template <class TypeLeft, class TypeRight = TypeLeft>
			struct less : public comparison_op<TypeLeft, TypeRight>
	{
		inline bool operator () (const TypeLeft& p_lhs, const TypeRight& p_rhs) const
		{
			return p_lhs < p_rhs;
		}
	};

	template <class TypeLeft, class TypeRight = TypeLeft>
			struct greater_equal : public comparison_op<TypeLeft, TypeRight>
	{
		inline bool operator () (const TypeLeft& p_lhs, const TypeRight& p_rhs) const
		{
			return p_lhs >= p_rhs;
		}
	};

	template <class TypeLeft, class TypeRight = TypeLeft>
			struct less_equal : public comparison_op<TypeLeft, TypeRight>
	{
		inline bool operator () (const TypeLeft& p_lhs, const TypeRight& p_rhs) const
		{
			return p_lhs <= p_rhs;
		}
	};


	typedef binary_op<bool, bool, bool> boolean_op;

	struct logical_and : public boolean_op
	{
		inline bool operator () (const bool p_lhs, const bool p_rhs) const
		{
			return p_lhs && p_rhs;
		}
	};

	struct logical_or : public boolean_op
	{
		inline bool operator () (const bool p_lhs, const bool p_rhs) const
		{
			return p_lhs || p_rhs;
		}
	};

	struct logical_xor : public boolean_op
	{
		inline bool operator () (const bool p_lhs, const bool p_rhs) const
		{
			return (p_lhs && !p_rhs) || (!p_lhs && p_rhs);
		}
	};

	template <> struct equal_to<double, double>  : public comparison_op<double, double>
	{
		// DBL_EPSILON for 1. numbers
		// DBL_MIN for 3e numbers

		const double m_epsilon;
	public:
		equal_to(double p_epsilon = DBL_MIN)
				: m_epsilon(p_epsilon)
		{
		}

		bool operator () (double p_lhs, double p_rhs)
		{
			double delta = fabs(p_lhs - p_rhs);

			return delta < m_epsilon;
		}
	};

	template <class T> struct Type;

	template <class T> struct Operator;
}



#define sArraySize(arr) (sizeof(arr)/sizeof(arr[0]))

#if defined(NDEBUG)
//
// I remain unconvinced this is only a compiler directive.
//
//#define sAssert(exp) __assume(!(!(exp)))
//#define sAssertX(exp, args) __assume(!(!(exp)))
#define sAssert(exp)
#define sAssertX(exp, args)

#define sVerify(exp) ((void )exp)
// #define sVerifyX(exp, args) ((void ) exp)
#define sVerifyX(exp, args) (exp)
#else
#define sAssert(exp) do { \
			      if (!(exp)) { \
				      fs::assertionFailure(__FILE__, __LINE__, #exp); \
			      } \
		      } while (0)

#define sAssertX(exp, args) do { \
				      if (!(exp)) { \
					      std::string _str_dont_use_this_name = fs::format args ; \
					      fs::assertionFailure(__FILE__, __LINE__, (std::string( #exp " " ) + _str_dont_use_this_name).c_str()); \
				      } \
			      } while (0)

#define sVerify(exp) sAssert(exp)
#define sVerifyX(exp, args) sAssertX(exp, args)
#endif


#if defined(NDEBUG)
#define sTrace(args)
#define sTraceX(args)
#else
#define sTrace(args) do { \
			     std::string _str_dont_use_this_name = fs::format args ; \
			     OutputDebugString(_str_dont_use_this_name.c_str()); \
			     OutputDebugString("\n"); \
		      } while (0)

#define sTraceX(args) do { \
				 std::string _str_dont_use_this_name = fs::format args; \
				 fs::traceOutput(__FILE__, __LINE__, _str_dont_use_this_name.c_str()); \
			} while (0)
#endif


#define sRaiseError(args) do {\
				    std::string _____strError = fs::format args; \
					fs::raiseError(__FILE__, __LINE__, _____strError.c_str()); \
			   } while (0)

#define sValidate(exp, args) do { \
				      if (!(exp)) { \
					      std::string strError = fs::format args; \
					      fs::raiseError(__FILE__, __LINE__, strError.c_str()); \
				      } \
			      } while (0)

#define sValidate0(exp) do { \
				  if (!(exp)) { \
					  fs::raiseError(__FILE__, __LINE__, #exp); \
				  } \
			  } while(0)

#define sPrecondition sAssert
#define sPreconditionX sAssertX

#define sPostcondition sAssert
#define sPostconditionX sAssertX

#if !defined(NDEBUG)
#define sDebug( statement ) do { \
				    statement \
				    ; \
			    } while (false)
#else
#define sDebug( statement ) 
#endif


#define sCoerce(type, exp) ( ( type ) ( exp ) )

namespace fs
{
	template <class From, class To> struct Coerce;

	template <class T> struct Coerce<T, T>
	{
		inline T operator()(T p_v)
		{
			return p_v;
		}

		inline void operator()(T p_v, T *p_pV)
		{
			*p_pV = p_v;
		}
	};

	// should implement some debug time checks
	template <> struct Coerce<size_t, fs::byte>
	{
		fs::byte operator()(size_t p_v)
		{
			return (fs::byte)(p_v);
		}

		void operator()(size_t p_v, fs::byte *p_pV)
		{
			*p_pV = (fs::byte)(p_v);
		}
	};

	template <> struct Coerce<size_t, fs::word>
	{
		fs::word operator()(size_t p_v)
		{
			return (fs::word)(p_v);
		}

		void operator()(size_t p_v, fs::word *p_pV)
		{
			*p_pV = (fs::word)(p_v);
		}
	};

	template <> struct Coerce<size_t, fs::qword>
	{
		fs::qword operator()(size_t p_v)
		{
			return (fs::qword)(p_v);
		}

		void operator()(size_t p_v, fs::qword *p_pV)
		{
			*p_pV = (fs::qword)(p_v);
		}

		Coerce(size_t p_v, fs::qword *p_pV)
		{
			(*this)(p_v, p_pV);
		}
	};

	template <> struct Coerce<fs::qword, fs::dword>
	{
		inline Coerce(fs::qword p_v, fs::dword *p_pV)
		{
			*p_pV = (fs::dword)p_v;
		}
	};

#if defined(_M_IX86) // size_t is it's own type.
	template <> struct Coerce<fs::qword, size_t>
	{
		fs::qword operator()(fs::qword p_v)
		{
			return (size_t)(p_v);
		}

		void operator()(fs::qword p_v, size_t *p_pV)
		{
			*p_pV = (size_t)(p_v);
		}

		Coerce(fs::qword p_v, size_t *p_pV)
		{
			(*this)(p_v, p_pV);
		}
	};
#endif
#if 0
	template <> struct Coerce<fs::qword, size_t>
	{
		inline Coerce(fs::qword p_v, size_t *p_pV)
		{
			*p_pV = p_v;
		}
	};
#endif



	template <> struct Coerce<fs::dword, fs::dword>
	{
		inline Coerce(fs::dword p_v, fs::dword *p_pV)
		{
			*p_pV = p_v;
		}
	};

	template <> struct Coerce<fs::dword, fs::word>
	{
		inline Coerce(fs::dword p_v, fs::word *p_pV)
		{
			*p_pV = (fs::word) p_v;
		}
	};


#if 0
	template <class TFrom, class TTo>
		inline void Coerce(const TFrom& p_from, TTo *p_pTo)
	{
		sPrecondition(p_from <= Traits<TTo>::Maximum);
		sPrecondition(p_from >= Traits<TTo>::Minimum);

		*p_pTo = static_cast<TTo>(p_from);

	}

	inline fs::dword UNIX_time()
	{
		return sCoerce(dword, time(0));
	}
#endif
}

/* End of File: declarations.h */
