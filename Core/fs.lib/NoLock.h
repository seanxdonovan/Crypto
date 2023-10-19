namespace fs
{
	//
	// NoLock is a mutex that does not lock. Its purpose is to
	// provide locking semantics for a single threaded program.
	//
	//
	class NoLock
	{
	public:
		inline void Acquire()
		{
		}
		inline void Release()
		{
		}
		class Locker
		{
		public:
			inline Locker(NoLock& cs)
			{
			}
			inline ~Locker()
			{
			}
		};
	};
};

/* End of File: NoLock.h */
