#include "precomp.h"
#include "declarations.h"
#include "type.h"
#include "type.id.h"
#include "Buffer.h"

#include "HeapBuffer.h"

#include "BinaryTypes.h"

namespace fs
{

	void BinaryShort::Assign(const fs::HeapBuffer& p_data)
	{
		sPrecondition(p_data.Size() <= Traits<byte>::Maximum);
		m_size = Coerce<size_t, fs::byte>()(p_data.Size());

		fs::Copy(p_data, &Buffer());
	}

	std::string format(const fs::BinaryShort& p_s)
	{
		return "BinaryShort";
	}


	void BinaryMedium::Assign(const fs::HeapBuffer& p_data)
	{
		sPrecondition(p_data.Size() <= Traits<word>::Maximum);
		m_size = Coerce<size_t, fs::word>()(p_data.Size());

		fs::Copy(p_data, &Buffer());
	}


	std::string format(const fs::BinaryMedium& p_s)
	{
		return "BinaryMedium";
	}

} /* namespace fs */


/* End Of File: BinaryTypes.cpp */
