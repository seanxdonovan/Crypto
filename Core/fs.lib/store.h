


namespace fs
{
	void storeBigEndian(word   p_value, Buffer *p_pBuffer);
	void storeBigEndian(dword  p_value, Buffer *p_pBuffer);
	void storeBigEndian(qword  p_value, Buffer *p_pBuffer);
	void storeBigEndian(dqword p_value, Buffer *p_pBuffer);

	void loadBigEndian(const Buffer& p_buffer, word *p_pValue);
	void loadBigEndian(const Buffer& p_buffer, dword *p_pValue);
	void loadBigEndian(const Buffer& p_buffer, qword *p_pValue);

	void readBigEndian(Stream& p_stream, word *p_pValue);

	void readBigEndian(Stream& p_stream, dword *p_pValue);
	void writeBigEndian(Stream& p_stream, dword p_value);

	void readBigEndian(Stream& p_stream, qword *p_pValue);
	void writeBigEndian(Stream& p_stream, qword p_value);


	void storeLittleEndian(word   p_value, Buffer *p_pBuffer);
	void storeLittleEndian(dword  p_value, Buffer *p_pBuffer);
	void storeLittleEndian(qword  p_value, Buffer *p_pBuffer);
	void storeLittleEndian(dqword p_value, Buffer *p_pBuffer);

	void loadLittleEndian(const Buffer& p_buffer, word   *p_pValue);
	void loadLittleEndian(const Buffer& p_buffer, dword  *p_pValue);
	void loadLittleEndian(const Buffer& p_buffer, qword  *p_pValue);
	void loadLittleEndian(const Buffer& p_buffer, dqword *p_pValue);

	void readLittleEndian(Stream& p_stream, word *p_pValue);
	void readLittleEndian(Stream& p_stream, dword *p_pValue);
	void readLittleEndian(Stream& p_stream, qword *p_pValue);
	void writeLittleEndian(Stream& p_stream, dword p_value);
}

