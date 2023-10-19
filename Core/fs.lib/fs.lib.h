#include "declarations.h"


#include "MultiplicativeTraits.h"

#include "swap.h"
#include "multiply.h"
#include "NoLock.h"

#include "Buffer.h"
#include "Zero.h"

#include "BigEndianReader.h"

#include "format.h"


#include "Enumeration.h"

#include "type.h"
#include "type.id.h"
#include "type.List.h"
#include "type.Traits.h"
#include "type.Conversion.h"

#include "ReferenceCountedPointer.h"
#include "ReferenceCountedPointerDerived.h"


#include "base60.h"

#include "io.h"


#include "Closer.h"

#include "Arithmetic.h"

#include "Layout.h"
#include "Tuple.h"


#include "Hash.h"
#include "HashTable.h"

#include "Functor.h"

#include "Invoke.h"
#include "Assign.h"


#include "Notifier.h"

#include "exception.h"
#include "StructuredExceptionHandler.h"

#include "HeapBuffer.h"
#include "ExpandingBuffer.h"
#include "FixedBuffer.h"

#include "strings.h"
#include "StringFixed.h"
#include "stringfunctions.h"

#include "BinaryTypes.h"


#include "fsTime.h"
#include "Date.h"
#include "DateTime.h"


#include "Stream.h"
#include "BufferedReader.h"

#include "store.h"

#include "NameValue.h"

#include "Options.h"



#include "NullStream.h"
#include "BufferStream.h"



#include "Log.h"

#include "UnitTest.h"


#include "ExpandingBufferStream.h"

#include "Random.h"

#include "LineReader.h"


namespace fs
{
	void dump(const Buffer& p_buffer, Stream& p_stream);
}

namespace fs
{
	template <class TypeResult, class TypeLeft, class TypeRight> class Sum : public binary_op<TypeLeft, TypeRight, TypeResult>
	{
	public:
		TypeResult operator () (typename fs::PT<TypeLeft>::T p_lhs, typename fs::PT<TypeRight>::T p_rhs) const
		{
			sfcn();

			TypeResult r = p_lhs + p_rhs;

			return r;
		}
	};
}

namespace fs
{
	template <class ResultType, class LeftType, class RightType> class Difference : public binary_op<LeftType, RightType, ResultType>
	{
	public:
		ResultType operator () (typename fs::PT<LeftType>::T p_lhs, typename fs::PT<RightType>::T p_rhs) const
		{
			sfcn();

			ResultType r = p_lhs - p_rhs;
			return r;
		}
	};
}



#include "Formatter.h"

/* End Of File: fs.lib.h */
