#include "precomp.h"
#include "declarations.h"
#include "format.h"
#include "exception.h"

#include "StructuredExceptionHandler.h"

#include <eh.h>

namespace fs
{
	void translateStructuredException(unsigned int u, _EXCEPTION_POINTERS* pExp)
	{
		const char *pError = "Unknown.";

		switch(u)
		{
		case STATUS_ACCESS_VIOLATION:
			pError = "Access Violation." ;
			break;

		case STATUS_FLOAT_DIVIDE_BY_ZERO:
			_fpreset();
			pError = "Floating division by Zero." ;
			break;

		case STATUS_FLOAT_OVERFLOW:
			_fpreset();
			pError = "Floating Overflow." ;
			break;

		case STATUS_FLOAT_UNDERFLOW:
			_fpreset();
			pError = "Floating Underflow." ;
			break;

		case STATUS_ILLEGAL_INSTRUCTION:
			pError = "Illegal Instruction." ;
			break;

		case STATUS_PRIVILEGED_INSTRUCTION:
			pError = "Privileged Instruction." ;
			break;

		case STATUS_INTEGER_DIVIDE_BY_ZERO:
			pError = "Integer division by Zero." ;
			break;

		case STATUS_INTEGER_OVERFLOW:
			pError = "Integer overflow." ;
			break;

		case STATUS_STACK_OVERFLOW:
			pError = "Stack overflow." ;
			break;

		case STATUS_FLOAT_STACK_CHECK:
			_fpreset();
			pError = "Float stack check." ;
			break;

		case STATUS_FLOAT_INEXACT_RESULT:
			_fpreset();
			pError = "Inexact Float results." ;
			break;

		case STATUS_FLOAT_INVALID_OPERATION:
			_fpreset();
			pError = "Invalid Float operation." ;
			break;

		default:
			;
		}

		sRaiseError(("Structured Exeception: ", pError));
	}

	StructuredExceptionHandler::StructuredExceptionHandler()
	{
#ifdef _DEBUG
		// catch all kinds of nifty floating point exceptions
//		_controlfp(0, _MCW_EM & (~_EM_INEXACT) );
#endif
		m_se_translator = _set_se_translator( translateStructuredException );
	}

	StructuredExceptionHandler::~StructuredExceptionHandler()
	{
		_se_translator_function tmp;
		tmp = _set_se_translator( m_se_translator );
		sAssert(tmp == translateStructuredException);
	}
}

