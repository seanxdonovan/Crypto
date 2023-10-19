#include "precomp.h"
#include "Core/fs.lib/fs.lib.h"

#include "Filename.h"
#include "File.h"
#include "FileStream.h"

namespace ss
{

	FileStream::FileStream(File& p_f)
	    : m_f(p_f)
	{
	}

	void FileStream::Write(const fs::Buffer& p_data)
	{
		m_f.Write(p_data.Data(), p_data.Size());
	}

	void FileStream::Read(fs::Buffer& p_data)
	{
		int fixFile;
		m_f.Read(p_data.Data(), p_data.Size());
	}
			      
	void FileStream::Read(fs::Buffer p_buffer, fs::Buffer *p_pValid)
	{
		m_f.Read(p_buffer, p_pValid);
	}

	void FileStream::Seek(Offset p_offset)
	{
		File::Offset offset = p_offset;
		m_f.Seek(offset);
	}

	fs::Stream::Offset FileStream::Tell() const
	{
		File::Offset tell;
		m_f.Tell(&tell);

		return tell;
	}

	void FileStream::Flush()
	{
		m_f.Flush();
	}

	bool FileStream::EndOfStream()
	{
		return m_f.Tell() == m_f.Size();
	}


	FileStream::RCP FileStream::Make(File& p_f)
	{
		RCP p = RCP(new FileStream(p_f));

		return p;
	}

} /* namespace storage */
