#include "precomp.h"

#include "declarations.h"

#include "Enumeration.h"

namespace fs
{
	Enumeration::iterator Enumeration::begin()
	{
		return m_mapNameToValue.begin();
	}

	Enumeration::iterator Enumeration::end()
	{
		return m_mapNameToValue.end();
	}


	void Enumeration::AddName(const ::std::string& p_sName, IntegerType p_value)
	{
//		sfcn();
		sPrecondition(!IsName(p_sName));
		sPrecondition(!IsValue(p_value));

		m_mapNameToValue[p_sName] = p_value;
		if (m_vIndexToName.size() <= p_value)
		{
			m_vIndexToName.resize(p_value + 1000);
		}
		m_vIndexToName[p_value] = p_sName;
	}

	bool Enumeration::IsName(const ::std::string& p_sName) const
	{
//		sfcn();

		auto it = m_mapNameToValue.find(p_sName);

		const bool found = (it != m_mapNameToValue.end());

		return found;
	}

	bool Enumeration::IsValue(IntegerType p_value) const
	{
//		sfcn();

		if (p_value < m_vIndexToName.size())
		{
			if (!m_vIndexToName[p_value].empty())
			{
				return true;
			}
		}

		return false;
	}

	bool Enumeration::Find(const ::std::string& p_sName, IntegerType *p_pv) const
	{
//		sfcn();

		auto it = m_mapNameToValue.find(p_sName);

		const bool found = (it != m_mapNameToValue.end());

		if (found)
		{
			*p_pv = it->second;
		}

		return found;
	}


	bool Enumeration::Find(IntegerType p_v, ::std::string* p_psName) const
	{
//		sfcn();

		if (p_v < m_vIndexToName.size())
		{
			if (!m_vIndexToName[p_v].empty())
			{
				*p_psName = m_vIndexToName[p_v];
				return true;
			}
		}

		return false;
	}
}
