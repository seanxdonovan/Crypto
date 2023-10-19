namespace fs
{
	class NullStream : public Stream
	{
	public:
		void Write(const Buffer&);
		void Read(Buffer&);
	public:
		typedef ReferenceCountedPointerDerived<NullStream, Stream::RCP> RCP;
	};
} /* namespace fs */

/* End Of File: NullStream.h */
