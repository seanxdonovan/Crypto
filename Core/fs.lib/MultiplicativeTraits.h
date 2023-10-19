namespace fs
{
	template <class T> struct MultiplicativeTraits
	{
		public:
			static const T Zero = T(0);
			static const T One = T(1);
	};

	template <> struct MultiplicativeTraits<double>
	{
		public:
			static const double Zero;
			static const double One;
	};
}

