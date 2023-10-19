

/*
	Minimum system required 			Macros to define
	Windows Server 2003 				_WIN32_WINNT>=0x0502
										WINVER>=0x0502

	Windows XP 							_WIN32_WINNT>=0x0501
										WINVER>=0x0501

	Windows 2000 						_WIN32_WINNT>=0x0500
										WINVER>=0x0500

	Windows NT 4.0 						_WIN32_WINNT>=0x0400
										WINVER>=0x0400

	Windows Me							_WIN32_WINDOWS=0x0500
										WINVER>=0x0500

	Windows 98							_WIN32_WINDOWS>=0x0410
										WINVER>=0x0410

	Windows 95							_WIN32_WINDOWS>=0x0400
										WINVER>=0x0400

	Internet Explorer 6.0 				_WIN32_IE>=0x0600
	Internet Explorer 5.6 				_WIN32_IE>=0x0560
	Internet Explorer 5.01, 5.5 		_WIN32_IE>=0x0501
	Internet Explorer 5.0, 5.0a, 5.0b 	_WIN32_IE>=0x0500
	Internet Explorer 4.01 				_WIN32_IE>=0x0401
	Internet Explorer 4.0	 			_WIN32_IE>=0x0400
	Internet Explorer 3.0, 3.01, 3.02 	_WIN32_IE>=0x0300
*/

//
// No need to support win nt 4.0 anymore.
//
//#define _WIN32_WINNT 0x0502
#define _WIN32_WINNT 0x0600

#if !defined(_WIN32_WINNT)
#define _WIN32_WINNT 0x0400
#endif
#if !defined(_WIN32_WINDOWS)
#define _WIN32_WINDOWS 0x0500
#endif




#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <Winsock2.h>
#pragma comment( lib, "Ws2_32.lib" )

#include <stdarg.h>
#include <math.h>
#include <float.h>

//
// STL
//

#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <memory>
#include <locale>


#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <comdef.h>
#include <process.h>
#include <sqlext.h>


//#include <wininet.h>
//#pragma comment( lib, "wininet.lib" )

//multi-media accuracy timers
#include <Mmsystem.h>
#pragma comment( lib, "winmm.lib" )


// this used in base member initializer list
// it also trigers when you pass this to member variable
// we turn it off becuase we use it all the time for subject based
// things. Turn it on if you please.
#pragma warning(disable : 4355)


//
// enable as needed. As usual MFC and the regular world do not get
// along.
//
#if 0 && !defined(NDEBUG)

#include <crtdbg.h>

#define FS_DEBUG_NEW new (_CLIENT_BLOCK, __FILE__, __LINE__)

#define new FS_DEBUG_NEW




#endif



#include "Core/arch.lib/arch.lib.h"
