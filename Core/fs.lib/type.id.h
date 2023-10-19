namespace fs
{
	namespace type
	{
		typedef fs::dword ID;

		namespace id
		{
			const ID null           = 0x00;

			const ID byte           = 0x01;
			const ID word           = 0x02;
			const ID dword          = 0x03;
			const ID qword          = 0x04;
			const ID dqword         = 0x05;
			const ID ui256          = 0x06;

			const ID si8            = 0x07;
			const ID si16           = 0x08;
			const ID si32           = 0x09;
			const ID si64           = 0x0A;
			const ID si128          = 0x0B;
			const ID si256          = 0x0C;


			const ID StringShort    = 0x0D;
			const ID StringMedium   = 0x0E;
			const ID StringFixed    = 0x0F;

			const ID BinaryShort    = 0x10;
			const ID BinaryMedium   = 0x11;
			const ID BinaryFixed    = 0x12;

			const ID boolean        = 0x13;
			const ID Double         = 0x14;
			const ID FixedPoint     = 0x15;

			const ID Date           = 0x16;
			const ID Time           = 0x17;
			const ID DateTime       = 0x18;
			const ID DateTime_Span  = 0x19;
			const ID DateTime_Epoch = 0x1A;
			const ID Time_Span      = 0x1B;

			const ID std_string     = 0x20;
			const ID Tuple          = 0x30;
			const ID Namespace      = 0x31;
			const ID UDT            = 0x32;

			const ID Enumeration    = 0xE1;

			const char * name(ID p_id);
			bool convert(const char *p_s, ID *p_pid);
		}

		namespace operator_id
		{
			const ID nop                   = 0x00;

			const ID less_than             = 0x01;
			const ID less_than_or_equal    = 0x02;
			const ID greater_than          = 0x03;
			const ID greater_than_or_equal = 0x04;
			const ID equal                 = 0x05;
			const ID not_equal             = 0x06;

			const ID logical_and           = 0x08; // &&
			const ID logical_or            = 0x09; // ||
			const ID logical_xor           = 0x0A; // !
			const ID logical_not           = 0x0B; // !
			
			const ID bitwise_not           = 0x11; // ~
			const ID bitwise_and           = 0x12; // &
			const ID bitwise_or            = 0x13; // |
			const ID bitwise_xor           = 0x14; // ^
			const ID bitwise_shiftleft     = 0x15;
			const ID bitwise_shiftright    = 0x16;
			
			const ID postfix_increment     = 0x21;
			const ID postfix_decrement     = 0x22;
			const ID prefix_increment      = 0x23;
			const ID prefix_decrement      = 0x24;

			const ID multiply              = 0x25;
			const ID divide                = 0x26;
			const ID modulus               = 0x27;
			const ID subtract              = 0x28;
			const ID add                   = 0x29;
			const ID unary_minus           = 0x2A;
			const ID unary_plus            = 0x2B;

			const char * name(ID p_id);
		}
	}

	template <> struct Type<fs::type::Null>
	{
		static const fs::type::ID ID = fs::type::id::null;
	};

}
