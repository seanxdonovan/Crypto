#include "precomp.h"
#include "declarations.h"

namespace fs
{
	dword high_bit(word p_w)
	{
		word result = 0xFFFF;

#if defined(_M_IX86)
		_asm {
			BSR AX, p_w
			JZ zero
			INC AX
			JNZ end
zero:		MOV AX, 0
end:		MOV result, AX
		}
#else
		int need_to_port_to_x64;
		volatile byte *p = 0;
		*p = 1;
#endif

		
		return result;
		
	}

	dword low_bit0(word p_w)
	{
		word result = 0x1789;
#if defined(_M_IX86)
		_asm {
			BSF AX, p_w
			JNZ done
			MOV AX, 0
done:			MOV result, AX
		}
#else
		// need to port
		volatile byte *p = 0;
		*p = 1;
#endif

		return result;
	}

}


