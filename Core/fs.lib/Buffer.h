namespace fs
{
	class ConstBuffer
	{
	public:
		typedef size_t Offset;
	public:
		const byte *Data() const;
		template<class T> const T* Data() const
		{
			sPrecondition((Size() >= sizeof(T)));
			return (const T*) Data();
		}
		
		const Offset Size() const;
		const byte operator[](Offset p_index) const;

	public:
		ConstBuffer(const byte *p_pData, size_t p_size);
		ConstBuffer(const ConstBuffer&);
		~ConstBuffer();

	private:
		const byte *m_pData;
		Offset m_size;

	public:
		ConstBuffer& operator = (const ConstBuffer&);

		ConstBuffer Reference(Offset p_start) const;
		ConstBuffer Reference(Offset p_start, Offset p_length) const;
	};



	class Buffer
	{
	public:
		const static bool EndianBig = false;
		const static bool EndianLittle = true;
	public:
		typedef size_t Offset;
	public:
		byte *Data();

		template<class T> T* Data()
		{
			sPrecondition((Size() >= sizeof(T)));
			return (T *) Data();
		}
		template<class T> const T* Data() const
		{
			sPrecondition((Size() >= sizeof(T)));
			return (const T*) Data();
		}
		const byte *Data() const;
		const Offset Size() const;

		const byte operator[](Offset p_index) const;
		byte& operator[](Offset p_index);

		void Zero();
		void Fill(byte p_b);
		void Fill(word p_w);
		void Fill(dword p_dw);
		void Fill(qword p_qw);
		void Write(const Buffer& p_data, Offset p_atOffset = 0);

	public:
		Buffer();
		Buffer(byte *p_pData, size_t p_size);
		template<class T> explicit Buffer(T *p_pTypeData);
		Buffer(const Buffer&);
		~Buffer(); // be careful this is left as not virtual on purpose.

		Buffer Reference(Offset p_start);
		const Buffer Reference(Offset p_start) const;
		Buffer Reference(Offset p_start, Offset p_length);
		const Buffer Reference(Offset p_start, Offset p_length) const;

	protected:
		void i_setData(byte *p_pData, Offset p_size);
	private:
		byte *m_pData;
		Offset m_size;

	public:
		Buffer& operator = (const Buffer&);

		template <class T>
				static inline fs::Buffer Make(T p_array[])
		{
			return Buffer((fs::byte *)&(p_array[0]), sizeof(p_array));
		}

		void Replace(fs::byte p_value, fs::byte p_with);

	public:
		const ::fs::byte back() const;
		::fs::byte& back();
	};

	std::string format(const Buffer& p_buffer);
	bool decode(const std::string& p_hex, Buffer *p_pBuffer);

	inline bool Convert(const std::string& p_hex, Buffer *p_pBuffer)
	{
		return decode(p_hex, p_pBuffer);
	}

	void Copy(const Buffer& p_from, Buffer *p_pTo);
	void Move(const Buffer& from, Buffer *p_pTo);

	void Copy(const std::string& p_from, Buffer *p_pTo);

	void FastCopy(const Buffer& p_from, Buffer *p_pTo);

	void Find(const Buffer& p_pattern, const Buffer& p_in, std::vector<Buffer::Offset> *p_pAtOffsets);

	bool IsEqual(const Buffer& p_lhs, const Buffer& p_rhs);
	bool IsLess(const Buffer& p_lhs, const Buffer& p_rhs);



	inline byte *Buffer::Data()
	{
		return m_pData;
	}

	inline const byte *Buffer::Data() const
	{
		return m_pData;
	}

	inline const Buffer::Offset Buffer::Size() const
	{
		return m_size;
	}

	inline const byte Buffer::operator[](Offset p_index) const
	{
		sPrecondition(p_index < m_size);

		return m_pData[p_index];
	}

	inline byte& Buffer::operator[](Offset p_index)
	{
		sPrecondition(p_index < m_size);

		return m_pData[p_index];
	}


	inline void Buffer::Write(const Buffer& p_data, const Offset p_atOffset)
	{
		sPrecondition(p_data.Size() + p_atOffset <= m_size);

		Buffer tmp = Reference(p_atOffset, p_data.Size());
		FastCopy(p_data, &tmp);
	}

	inline Buffer::Buffer()
	    : m_pData(0)
	    , m_size(0)
	{
	}

	inline Buffer::Buffer(byte *p_pData, Offset p_size)
	    : m_pData(p_pData)
	    , m_size(p_size)
	{
	}

	template<class T> 
		inline Buffer::Buffer(T *p_pTypeData)
		: m_pData((fs::byte *) p_pTypeData)
		, m_size(sizeof(T))
	{
	}
	inline Buffer::Buffer(const Buffer& p_rhs)
	    : m_pData(p_rhs.m_pData)
	    , m_size(p_rhs.m_size)
	{
	}	

	inline Buffer::~Buffer()
	{
	}

	inline Buffer& Buffer::operator = (const Buffer& p_rhs)
	{
		m_pData = p_rhs.m_pData;
		m_size = p_rhs.m_size;

		return *this;
	}

	inline void Buffer::Zero()
	{
		Fill(fs::byte(0));
	}


	inline Buffer Buffer::Reference(Offset p_start)
	{
		sPrecondition(p_start <= m_size);

		return Buffer(m_pData + p_start, m_size - p_start);
	}

	inline const Buffer Buffer::Reference(Offset p_start) const
	{
		sPrecondition(p_start <= m_size);

		return Buffer(m_pData + p_start, m_size - p_start);
	}

	inline Buffer Buffer::Reference(Offset p_start, Offset p_length)
	{
		sPrecondition(p_start <= m_size);
		sPrecondition(p_start + p_length <= m_size);

		return Buffer(m_pData + p_start, p_length);
	}

	inline const Buffer Buffer::Reference(Offset p_start, Offset p_length) const
	{
		sPrecondition(p_start <= m_size);
		sPrecondition(p_start + p_length <= m_size);

		return Buffer(m_pData + p_start, p_length);
	}


	inline void Buffer::i_setData(byte *p_pData, Offset p_size)
	{
		m_pData = p_pData;
		m_size = p_size;
	}



	class BufferReader
	{
	public:
		BufferReader(fs::Buffer p_buffer, bool p_littleEndian = Buffer::EndianLittle)
				: m_buffer(p_buffer)
				, m_offset(0)
				, LittleEndian(p_littleEndian)
		{
		}

		BufferReader()
				: m_offset(0)
				, LittleEndian(Buffer::EndianLittle)
		{
		}

		void Open(fs::Buffer p_buffer, bool p_littleEndian = Buffer::EndianLittle)
		{
			m_buffer = p_buffer;
			m_offset = 0;
			LittleEndian = p_littleEndian;
		}
	private:
		fs::Buffer m_buffer;
		fs::Buffer::Offset m_offset;
		bool LittleEndian;

	public:
		void get(Buffer *p_pBuffer)
		{
			fs::Buffer src = m_buffer.Reference(m_offset, p_pBuffer->Size());
			fs::FastCopy(src, p_pBuffer);
			m_offset += p_pBuffer->Size();
		}

		void get(fs::byte *p_pv)
		{
			*p_pv = m_buffer[m_offset];
			++m_offset;
		}

		void get(fs::word *p_pv)
		{
			if (LittleEndian)
			{
				*p_pv = arch::l2m(*m_buffer.Reference(m_offset, sizeof(*p_pv)).Data<fs::word>());
			}
			else
			{
				*p_pv = arch::b2m(*m_buffer.Reference(m_offset, sizeof(*p_pv)).Data<fs::word>());
			}

			m_offset += sizeof(*p_pv);
		}

		void get(fs::dword *p_pv)
		{
			if (LittleEndian)
			{
				*p_pv = arch::l2m(*m_buffer.Reference(m_offset, sizeof(*p_pv)).Data<fs::dword>());
			}
			else
			{
				*p_pv = arch::b2m(*m_buffer.Reference(m_offset, sizeof(*p_pv)).Data<fs::dword>());
			}

			m_offset += sizeof(*p_pv);
		}

		void get(fs::qword *p_pv)
		{
			if (LittleEndian)
			{
				*p_pv = arch::l2m(*m_buffer.Reference(m_offset, sizeof(*p_pv)).Data<fs::qword>());
			}
			else
			{
				*p_pv = arch::b2m(*m_buffer.Reference(m_offset, sizeof(*p_pv)).Data<fs::qword>());
			}
			m_offset += sizeof(*p_pv);
		}

		void get(fs::si8 *p_pv)
		{
			get((fs::byte *) p_pv);
		}

		void get(fs::si16 *p_pv)
		{
			get((fs::word *) p_pv);
		}

		void get(fs::si32 *p_pv)
		{
			get((fs::dword *) p_pv);
		}

		void get(fs::si64 *p_pv)
		{
			get((fs::qword *) p_pv);
		}

		void get(bool *p_pv)
		{
			fs::byte v;
			get(&v);
			*p_pv = ('T' == v);
		}

		void get(fs::Double *p_pv)
		{
			*p_pv = *m_buffer.Reference(m_offset, sizeof(*p_pv)).Data<fs::Double>();
			m_offset += sizeof(*p_pv);
		}

		void get(std::string *p_ps)
		{
			fs::dword size;
			get(&size);
			if (size > 0)
			{
				*p_ps = std::string(m_buffer.Reference(m_offset).Data<char>(), size);
			}
			else
			{
				*p_ps = std::string();
			}
			m_offset += size;
		}

		void MoveForward(fs::Buffer::Offset p_increment)
		{
			m_offset += p_increment;
		}

		void MoveBackward(fs::Buffer::Offset p_increment)
		{
			m_offset -= p_increment;
		}

		fs::Buffer Next(fs::Buffer::Offset p_span)
		{
			fs::Buffer buf = m_buffer.Reference(m_offset, p_span);
			m_offset += p_span;
			return buf;
		}

		fs::Buffer::Offset Tell() const
		{
			return m_offset;
		}

		fs::Buffer::Offset Remainder() const
		{
			return m_buffer.Size() - m_offset;
		}

		fs::Buffer Rest() const
		{
			return m_buffer.Reference(Tell());
		}
	};

	class BufferWriter
	{
	public:
		BufferWriter(Buffer p_buffer, bool p_littleEndian = Buffer::EndianLittle)
				: m_buffer(p_buffer)
				, m_offset(0)
				, LittleEndian(p_littleEndian)
		{
		}
	private:
		Buffer m_buffer;
		Buffer::Offset m_offset;
		const bool LittleEndian;

	public:
		void put(fs::Buffer p_v)
		{
			Copy(p_v, &(m_buffer.Reference(m_offset, p_v.Size())));
			m_offset += p_v.Size();
		}

		void put(fs::byte p_v)
		{
			m_buffer[m_offset] = p_v;
			++m_offset;
		}

		void put(fs::word p_v)
		{
			fs::word *p = m_buffer.Reference(m_offset, sizeof(fs::word)).Data<word>();
			if (LittleEndian)
			{
				*p = arch::m2l(p_v);
			}
			else
			{
				*p = arch::m2b(p_v);
			}
			m_offset += sizeof(fs::word);
		}

		void put(fs::dword p_v)
		{
			fs::dword *p = m_buffer.Reference(m_offset, sizeof(fs::dword)).Data<dword>();
			if (LittleEndian)
			{
				*p = arch::m2l(p_v);
			}
			else
			{
				*p = arch::m2b(p_v);
			}
			m_offset += sizeof(fs::dword);
		}

		void put(fs::qword p_v)
		{
			fs::qword *p = m_buffer.Reference(m_offset, sizeof(fs::qword)).Data<qword>();
			if (LittleEndian)
			{
				*p = arch::m2l(p_v);
			}
			else
			{
				*p = arch::m2b(p_v);
			}
			m_offset += sizeof(fs::qword);
		}

		inline void put(fs::si8 p_v)
		{
			put((fs::byte)p_v);
		}

		inline void put(fs::si16 p_v)
		{
			put((fs::word)p_v);
		}

		inline void put(fs::si32 p_v)
		{
			put((fs::dword) p_v);
		}

		inline void put(fs::si64 p_v)
		{
			put((fs::qword) p_v);
		}

		void put(const bool p_v)
		{
			if (p_v)
			{
				put(fs::byte('T'));
			}
			else
			{
				put(fs::byte('F'));
			}
		}

		void put(const fs::Double p_v)
		{
			fs::Double *p = m_buffer.Reference(m_offset, sizeof(fs::Double)).Data<fs::Double>();
			*p = p_v;
			m_offset += sizeof(fs::Double);
		}
		void put(const std::string& p_s);

		fs::Buffer Written()
		{
			return m_buffer.Reference(0, m_offset);
		}
	};


	bool NextLine(::fs::Buffer p_buffer, ::fs::Buffer *p_pLine, ::fs::Buffer *p_pRemainder);
}

/* End Of File: Buffer.h */
