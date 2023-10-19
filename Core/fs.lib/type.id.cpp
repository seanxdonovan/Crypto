#include "precomp.h"

#include "declarations.h"
#include "type.h"

#include "type.id.h"


namespace fs
{
	namespace type
	{
		namespace id
		{
			namespace
			{
				struct
				{
					ID id;
					const char *name;
				} names [] = {
					{ null,   "null"},

					{ byte,   "byte"},
					{ word,   "word"},
					{ dword,  "dword"},
					{ qword,  "qword"},
					{ dqword, "dqword"},
					{ ui256,  "ui256"},

					{si8, "si8"},
					{si16, "si16"},
					{si32, "si32"},
					{si64, "si64"},
					{si128, "si128"},
					{si256, "si256"},


					{StringShort, "StringShort"},
					{StringMedium, "StringMedium"},
					{StringFixed, "StringFixed"},

					{BinaryShort, "BinaryShort"},
					{BinaryMedium, "BinaryMedium"},
					{BinaryFixed, "BinaryFixed"},

					{boolean, "boolean"},
					{Double, "Double"},
					{FixedPoint, "FixedPoint"},

					{Date, "Date"},
					{Time, "Time"},
					{DateTime, "DateTime"},
					{DateTime_Span, "DateTime_Span"},
					{DateTime_Epoch, "DateTime_Epoch"},

					{Time_Span, "Time_Span"},

					{std_string, "std_string"},
					{Tuple, "Tuple"},
					{Namespace, "namespace"},
					{UDT, "udt"}
				};
				const char * i_find_name(ID p_id)
				{
					for (size_t ix = 0; ix < sArraySize(names); ++ix)
					{
						if (names[ix].id == p_id)
						{
							return names[ix].name;
						}
					}

					return "unknown";
				}
			}


			const char * name(ID p_id)
			{
				return i_find_name(p_id);
			}

			bool convert(const char *p_s, ID *p_pid)
			{
				for (size_t ix = 0; ix < sArraySize(names); ++ix)
				{
					if (0 == strcmp(names[ix].name, p_s))
					{
						*p_pid = names[ix].id;
						return true;
					}
				}

				return false;
			}
		}

		namespace operator_id
		{
			namespace
			{
				struct
				{
					ID id;
					const char *name;
				} names [] = {
					{ nop,   "nop"},

					{ less_than,   "less_than"},
					{ less_than_or_equal,   "less_than_or_equal"},
					{ greater_than,  "greater_than"},
					{ greater_than_or_equal, "greater_than_or_equal"},
					{equal, "equal"},
					{not_equal, "not_equal"},

					{logical_and, "logical_and"},
					{logical_or, "logical_or"},
					{logical_xor, "logical_xor"},
					{logical_not, "logical_not"},

					{bitwise_not, "bitwise_not"},
					{bitwise_and, "bitwise_and"},
					{bitwise_or, "bitwise_or"},
					{bitwise_xor, "bitwise_xor"},

					{bitwise_shiftleft, "bitwise_shiftleft"},
					{bitwise_shiftright, "bitwise_shiftright"},

					{postfix_increment, "postfix_increment"},
					{postfix_decrement, "postfix_decrement"},
					{prefix_increment, "prefix_increment"},
					{prefix_decrement, "prefix_decrement"},

					{multiply, "multiply"},
					{divide, "divide"},
					{modulus, "modulus"},
					{subtract, "subtract"},
					{add, "add"},
					{unary_minus, "unary_minus"},
					{unary_plus, "unary_plus"}
				};
				const char * i_find_name(ID p_id)
				{
					for (size_t ix = 0; ix < sArraySize(names); ++ix)
					{
						if (names[ix].id == p_id)
						{
							return names[ix].name;
						}
					}

					return "unknown";
				}
			}


			const char * name(ID p_id)
			{
				return i_find_name(p_id);
			}
		}
	}
}



