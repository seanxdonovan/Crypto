namespace ss
{
	class FileStream : public fs::Stream
	{
	private:
		File& m_f;
	public:
		FileStream(File& p_f);


		//
		// Overrides from fundamental::Stream
		//
		void Write(const fs::Buffer& p_data);
		void Read(fs::Buffer& p_data);
		void Read(fs::Buffer p_buffer, fs::Buffer *p_pValid);
		void Seek(Offset p_offset);
		Offset Tell() const;
		void Flush();

		bool EndOfStream();

	public:
		typedef fs::ReferenceCountedPointerDerived<FileStream, fs::Stream::RCP> RCP;

		static RCP Make(File& p_f);
	};

} /* namespace storage */

/* End Of File: FileStream.h */
