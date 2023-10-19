#include "precomp.h"

#include "declarations.h"
#include "MultiplicativeTraits.h"

namespace fs
{
	const double Traits<double>::Maximum = DBL_MAX;
	const double Traits<double>::Minimum = DBL_MIN;


	const double MultiplicativeTraits<double>::Zero = 0.;
	const double MultiplicativeTraits<double>::One = 1.;
}

