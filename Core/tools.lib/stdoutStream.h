namespace tools
{
	
	class stdoutStream : public fs::Stream
	{
	public:
		void Write(const fs::Buffer& p_data);
		void Read(fs::Buffer& p_into);
	};


} /* namespace tools */

/* End Of File: stdoutStream.h */
