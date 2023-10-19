#include "precomp.h"

#include "declarations.h"
#include "Buffer.h"

#include "type.h"
#include "type.List.h"

#include "Layout.h"


namespace fs
{
	layout::layout(::fs::Buffer p_buffer)
		: m_buffer(p_buffer)
	{

	}
}


namespace fs
{
	Layout<::fs::byte>::Layout(::fs::Buffer p_buffer)
			: layout(p_buffer)
	{
	}

	::fs::byte *Layout<::fs::byte>::operator&()
	{
		return m_buffer.Data<::fs::byte>();
	}
	::fs::byte *Layout<::fs::byte>::operator->()
	{
		return m_buffer.Data<::fs::byte>();
	}

	::fs::byte& Layout<::fs::byte>::operator*()
	{
		return *m_buffer.Data<::fs::byte>();
	}
}


namespace fs
{
	Layout<::fs::word>::Layout(::fs::Buffer p_buffer)
			: layout(p_buffer)
	{
	}

	::fs::word *Layout<::fs::word>::operator&()
	{
		return m_buffer.Data<::fs::word>();
	}
	::fs::word *Layout<::fs::word>::operator->()
	{
		return m_buffer.Data<::fs::word>();
	}

	::fs::word& Layout<::fs::word>::operator*()
	{
		return *m_buffer.Data<::fs::word>();
	}
}

namespace fs
{
	Layout<::fs::dword>::Layout(::fs::Buffer p_buffer)
			: layout(p_buffer)
	{
	}

	::fs::dword *Layout<::fs::dword>::operator&()
	{
		return m_buffer.Data<::fs::dword>();
	}
	::fs::dword *Layout<::fs::dword>::operator->()
	{
		return m_buffer.Data<::fs::dword>();
	}

	::fs::dword& Layout<::fs::dword>::operator*()
	{
		return *m_buffer.Data<::fs::dword>();
	}

	const ::fs::dword& Layout<::fs::dword>::operator*() const
	{
		return *m_buffer.Data<const ::fs::dword>();
	}
}

namespace fs
{
	Layout<::fs::qword>::Layout(::fs::Buffer p_buffer)
			: layout(p_buffer)
	{
	}

	::fs::qword *Layout<::fs::qword>::operator&()
	{
		return m_buffer.Data<::fs::qword>();
	}
	::fs::qword *Layout<::fs::qword>::operator->()
	{
		return m_buffer.Data<::fs::qword>();
	}

	::fs::qword& Layout<::fs::qword>::operator*()
	{
		return *m_buffer.Data<::fs::qword>();
	}
}






namespace fs
{
	Layout<::fs::si8>::Layout(::fs::Buffer p_buffer)
			: layout(p_buffer)
	{
	}

	::fs::si8 *Layout<::fs::si8>::operator&()
	{
		return m_buffer.Data<::fs::si8>();
	}
	::fs::si8 *Layout<::fs::si8>::operator->()
	{
		return m_buffer.Data<::fs::si8>();
	}

	::fs::si8& Layout<::fs::si8>::operator*()
	{
		return *m_buffer.Data<::fs::si8>();
	}
}


namespace fs
{
	Layout<::fs::si16>::Layout(::fs::Buffer p_buffer)
			: layout(p_buffer)
	{
	}

	::fs::si16 *Layout<::fs::si16>::operator&()
	{
		return m_buffer.Data<::fs::si16>();
	}
	::fs::si16 *Layout<::fs::si16>::operator->()
	{
		return m_buffer.Data<::fs::si16>();
	}

	::fs::si16& Layout<::fs::si16>::operator*()
	{
		return *m_buffer.Data<::fs::si16>();
	}
}

namespace fs
{
	Layout<::fs::si32>::Layout(::fs::Buffer p_buffer)
			: layout(p_buffer)
	{
	}

	::fs::si32 *Layout<::fs::si32>::operator&()
	{
		return m_buffer.Data<::fs::si32>();
	}
	::fs::si32 *Layout<::fs::si32>::operator->()
	{
		return m_buffer.Data<::fs::si32>();
	}

	::fs::si32& Layout<::fs::si32>::operator*()
	{
		return *m_buffer.Data<::fs::si32>();
	}
}

namespace fs
{
	Layout<::fs::si64>::Layout(::fs::Buffer p_buffer)
			: layout(p_buffer)
	{
	}

	::fs::si64 *Layout<::fs::si64>::operator&()
	{
		return m_buffer.Data<::fs::si64>();
	}
	::fs::si64 *Layout<::fs::si64>::operator->()
	{
		return m_buffer.Data<::fs::si64>();
	}

	::fs::si64& Layout<::fs::si64>::operator*()
	{
		return *m_buffer.Data<::fs::si64>();
	}
}

namespace fs
{
	Layout<::fs::Double>::Layout(::fs::Buffer p_buffer)
			: layout(p_buffer)
	{
	}

	::fs::Double *Layout<::fs::Double>::operator&()
	{
		return m_buffer.Data<::fs::Double>();
	}
	::fs::Double *Layout<::fs::Double>::operator->()
	{
		return m_buffer.Data<::fs::Double>();
	}

	::fs::Double& Layout<::fs::Double>::operator*()
	{
		return *m_buffer.Data<::fs::Double>();
	}
}

namespace fs
{
	Layout<bool>::Layout(::fs::Buffer p_buffer)
			: layout(p_buffer)
	{
	}

	::fs::byte *Layout<bool>::operator&()
	{
		return m_buffer.Data<::fs::byte>();
	}

	::fs::byte *Layout<bool>::operator->()
	{
		return m_buffer.Data<::fs::byte>();
	}

	::fs::byte& Layout<bool>::operator*()
	{
		return *m_buffer.Data<::fs::byte>();
	}
}
