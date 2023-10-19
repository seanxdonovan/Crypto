namespace fs
{
	template <class T>
			struct io
	{
	public:
		static void put(BufferWriter& p_bw, typename fs::PT<T>::T p_v)
		{
			p_bw.put(p_v);
		}

		static void get(BufferReader& p_br, T *p_pV)
		{
			p_br.get(p_pV);
		}
	};

	template<> struct io<type::Null>
	{
		static inline void put(BufferWriter& p_bw, type::Null)
		{
		}
		static inline void get(BufferReader& p_br, type::Null *)
		{
		}
	};

	template<> struct io<type::Empty>
	{
		static inline void put(BufferWriter& p_bw, type::Empty)
		{
		}
		static inline void get(BufferReader& p_br, type::Empty *)
		{
		}
	};
}

namespace fs
{
	template <class T> void get(::fs::BufferReader& p_br, T *p_pv)
	{
		::fs::io<T>::get(p_br, p_pv);
	}

	template <class T> void put(::fs::BufferWriter& p_bw, const T& p_v)
	{
		::fs::io<T>::put(p_bw, p_v);
	}
}

