#include "precomp.h"
#include "declarations.h"


namespace fs
{
	bool less(const GUID& p_lhs, const GUID& p_rhs)
	{
		if (p_lhs.Data1 < p_rhs.Data1)
		{
			return true;
		}

		if ((p_lhs.Data1 == p_rhs.Data1)
				&& (p_lhs.Data2 < p_rhs.Data2))
		{
			return true;
		}

		if ((p_lhs.Data1 == p_rhs.Data1)
				&& (p_lhs.Data2 == p_rhs.Data2)
				&& (p_lhs.Data3 < p_rhs.Data3))
		{
			return true;
		}

		if ((p_lhs.Data1 == p_rhs.Data1)
				&& (p_lhs.Data2 == p_rhs.Data2)
				&& (p_lhs.Data3 == p_rhs.Data3)
				&& (p_lhs.Data4[0] < p_rhs.Data4[0]))
		{
			return true;
		}

		if ((p_lhs.Data1 == p_rhs.Data1)
				&& (p_lhs.Data2 == p_rhs.Data2)
				&& (p_lhs.Data3 == p_rhs.Data3)
				&& (p_lhs.Data4[0] == p_rhs.Data4[0])
				&& (p_lhs.Data4[1] < p_rhs.Data4[1]))
		{
			return true;
		}

		if ((p_lhs.Data1 == p_rhs.Data1)
				&& (p_lhs.Data2 == p_rhs.Data2)
				&& (p_lhs.Data3 == p_rhs.Data3)
				&& (p_lhs.Data4[0] == p_rhs.Data4[0])
				&& (p_lhs.Data4[1] == p_rhs.Data4[1])
				&& (p_lhs.Data4[2] < p_rhs.Data4[2]))
		{
			return true;
		}

		if ((p_lhs.Data1 == p_rhs.Data1)
				&& (p_lhs.Data2 == p_rhs.Data2)
				&& (p_lhs.Data3 == p_rhs.Data3)
				&& (p_lhs.Data4[0] == p_rhs.Data4[0])
				&& (p_lhs.Data4[1] == p_rhs.Data4[1])
				&& (p_lhs.Data4[2] == p_rhs.Data4[2])
				&& (p_lhs.Data4[3] < p_rhs.Data4[3]))
		{
			return true;
		}


		if ((p_lhs.Data1 == p_rhs.Data1)
				&& (p_lhs.Data2 == p_rhs.Data2)
				&& (p_lhs.Data3 == p_rhs.Data3)
				&& (p_lhs.Data4[0] == p_rhs.Data4[0])
				&& (p_lhs.Data4[1] == p_rhs.Data4[1])
				&& (p_lhs.Data4[2] == p_rhs.Data4[2])
				&& (p_lhs.Data4[3] == p_rhs.Data4[3])
				&& (p_lhs.Data4[4] < p_rhs.Data4[4]))
		{
			return true;
		}

		if ((p_lhs.Data1 == p_rhs.Data1)
				&& (p_lhs.Data2 == p_rhs.Data2)
				&& (p_lhs.Data3 == p_rhs.Data3)
				&& (p_lhs.Data4[0] == p_rhs.Data4[0])
				&& (p_lhs.Data4[1] == p_rhs.Data4[1])
				&& (p_lhs.Data4[2] == p_rhs.Data4[2])
				&& (p_lhs.Data4[3] == p_rhs.Data4[3])
				&& (p_lhs.Data4[4] == p_rhs.Data4[4])
				&& (p_lhs.Data4[5] < p_rhs.Data4[5]))
		{
			return true;
		}

		if ((p_lhs.Data1 == p_rhs.Data1)
				&& (p_lhs.Data2 == p_rhs.Data2)
				&& (p_lhs.Data3 == p_rhs.Data3)
				&& (p_lhs.Data4[0] == p_rhs.Data4[0])
				&& (p_lhs.Data4[1] == p_rhs.Data4[1])
				&& (p_lhs.Data4[2] == p_rhs.Data4[2])
				&& (p_lhs.Data4[3] == p_rhs.Data4[3])
				&& (p_lhs.Data4[4] == p_rhs.Data4[4])
				&& (p_lhs.Data4[5] == p_rhs.Data4[5])
				&& (p_lhs.Data4[6] < p_rhs.Data4[6]))
		{
			return true;
		}


		if ((p_lhs.Data1 == p_rhs.Data1)
				&& (p_lhs.Data2 == p_rhs.Data2)
				&& (p_lhs.Data3 == p_rhs.Data3)
				&& (p_lhs.Data4[0] == p_rhs.Data4[0])
				&& (p_lhs.Data4[1] == p_rhs.Data4[1])
				&& (p_lhs.Data4[2] == p_rhs.Data4[2])
				&& (p_lhs.Data4[3] == p_rhs.Data4[3])
				&& (p_lhs.Data4[4] == p_rhs.Data4[4])
				&& (p_lhs.Data4[5] == p_rhs.Data4[5])
				&& (p_lhs.Data4[6] == p_rhs.Data4[6])
				&& (p_lhs.Data4[7] < p_rhs.Data4[7]))
		{
			return true;
		}

		return false;
	}
}


