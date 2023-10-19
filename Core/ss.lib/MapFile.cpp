#include "precomp.h"
#include "Core/fs.lib/fs.lib.h"

#include "Filename.h"
#include "File.h"

#include "MapFile.h"

namespace ss
{
	MapFile::MapFile(::fs::dword p_access)
			: m_mapping(m_f)
			, m_view(m_mapping)
			, m_access(p_access)
	{
	}

	MapFile::~MapFile()
	{
		m_view.Unmap();
		m_mapping.Close();
		m_f.Close();
	}

	void MapFile::i_makeMapping()
	{
		const auto size = m_f.Size();
		m_mapping.Create(size);
		m_view.Map(0, 0, m_access); // start at 0 and map the whole file.
		m_viewBuffer = ::fs::Buffer(m_view.Buffer().Data(), size);
	}

	void MapFile::Open(const  Filename& p_fn)
	{
		m_f.Open(p_fn);

		i_makeMapping();
	}

	void MapFile::Create(const  Filename& p_fn, ::fs::Buffer::Offset p_size, bool p_deleteOnClose)
	{
		::ss::File::Parameters parameters;

		parameters.DesiredAccess(GENERIC_READ | GENERIC_WRITE);
		parameters.CreationDisposition(CREATE_NEW);
		if (p_deleteOnClose)
		{
			parameters.FlagsAndAttributes(FILE_ATTRIBUTE_TEMPORARY | FILE_FLAG_DELETE_ON_CLOSE);
		}
		else
		{
			parameters.FlagsAndAttributes(FILE_ATTRIBUTE_NORMAL);
		}

		m_f.Create(p_fn, parameters);

		m_f.Seek(p_size);
		m_f.SetEOF();

		i_makeMapping();
	}


	::fs::Buffer MapFile::View()
	{
		return m_viewBuffer;
	}


	void MapFile::Resize(::fs::Buffer::Offset p_newSize)
	{
		m_view.Unmap();
		m_mapping.Close();

		m_f.Seek(p_newSize);
		m_f.SetEOF();

		i_makeMapping();
	}
}
