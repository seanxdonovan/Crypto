namespace fs
{
	template <size_t size>
	struct BinaryFixed
	{
	public:
		static const size_t Size = size;

		inline Buffer Buffer() const
		{
			return fs::Buffer((fs::byte *) this, size);
		}

	private:
		byte data[Size];
	};


	template <size_t size>
	struct Traits<BinaryFixed<size> >
	{
		static const bool isFixedSize = true;
	};

	template <size_t size> struct Sizer<BinaryFixed<size> >
	{
		static const size_t Size = size;
	};


	template<size_t size>
	std::string format(const BinaryFixed<size>& p_b)
	{
		return format(p_b.Buffer());
	}

	class BinaryShort
	{
		byte m_size;
	public:
		byte Size() const
		{
			return m_size;
		}

		void Assign(const fs::HeapBuffer& p_data);

		inline Buffer Buffer() const
		{
			return fs::Buffer((fs::byte *) (this + 1), m_size);
		}
	};

	template <> struct Type<fs::BinaryShort>
	{
		static const fs::type::ID ID = fs::type::id::BinaryShort;
	};

	std::string format(const fs::BinaryShort& p_s);

	class BinaryMedium
	{
		word m_size;
	public:
		word Size() const
		{
			return m_size;
		}

		void Assign(const fs::HeapBuffer& p_string);

		inline Buffer Buffer() const
		{
			return fs::Buffer((fs::byte *) (this + 1), m_size);
		}
	};

	template <> struct Type<fs::BinaryMedium>
	{
		static const fs::type::ID ID = fs::type::id::BinaryMedium;
	};


} /* namespace fs */

template<size_t size>
bool operator == (const fs::BinaryFixed<size>& p_rhs, const fs::BinaryFixed<size>& p_lhs)
{
	return 0 == memcmp(p_lhs.Buffer().Data(), p_rhs.Buffer().Data(), size);
}


/* End Of File: BinaryTypes.h */

