namespace fs
{
	class BigEndianReader
	{
	public:
		BigEndianReader(fs::Buffer p_buffer)
				: m_buffer(p_buffer)
				, m_offset(0)
		{
		}
	private:
		fs::Buffer m_buffer;
		fs::Buffer::Offset m_offset;

	public:
		fs::byte get_byte()
		{
			sPrecondition(m_offset + sizeof(fs::byte) <= m_buffer.Size());

			fs::byte b = m_buffer[m_offset];
			++m_offset;
			return b;
		}

		fs::word get_word()
		{
			sPrecondition(m_offset + sizeof(word) <= m_buffer.Size());

			fs::word w = _byteswap_ushort(*(m_buffer.Reference(m_offset, sizeof(word)).Data<fs::word>()));
			m_offset += sizeof(fs::word);
			return w;
		}

		fs::dword get_dword()
		{
			sPrecondition(m_offset + sizeof(dword) <= m_buffer.Size());

			fs::dword w = _byteswap_ulong(*(m_buffer.Reference(m_offset, sizeof(dword)).Data<fs::dword>()));
			m_offset += sizeof(fs::dword);
			return w;
		}

		fs::Buffer get_buffer(fs::Buffer::Offset p_bytes)
		{
			sPrecondition(m_offset + p_bytes <= m_buffer.Size());

			fs::Buffer buffer = m_buffer.Reference(m_offset, p_bytes);
			m_offset += p_bytes;
			return buffer;
		}
	};
}
