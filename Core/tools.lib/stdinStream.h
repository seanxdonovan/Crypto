namespace tools
{
	
	class stdinStream : public fs::Stream
	{
	public:
		void Write(const fs::Buffer& p_buffer);
		void Read(fs::Buffer& p_buffer);

		bool EndOfFile();

		bool EndOfStream();
	};


} /* namespace tools */

/* End Of File: stdinStream.h */
