
//
// Microsoft Visual C macros
// _M_IX86 - intel x86 32bit 
//     300 --> /G3 80386
//     400 --> /G4 80486 target
//     500 --> /G5 Pentium
//     600 --> /G6 Pentium Pro, Pentium II, Pentium III also /GB blend
//
// _M_X64 64bit intel x86 architecture
//


namespace arch
{
	typedef unsigned char    byte;
	typedef unsigned short   word;
	typedef unsigned long    dword;
	typedef unsigned __int64 qword;
}
