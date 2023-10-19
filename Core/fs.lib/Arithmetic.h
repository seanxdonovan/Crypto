namespace fs
{
	template <class LHS, class RHS, class RT> 
	class Arithmetic
	{
	public:
		typedef typename fs::type::Traits<LHS>::ParameterType PTLHS;
		typedef typename fs::type::Traits<RHS>::ParameterType PTRHS;
	public:
		static inline RT Add(PTLHS p_lhs, PTRHS p_rhs)
		{
			return p_lhs + p_rhs;
		}
		static inline RT Sub(PTLHS p_lhs, PTRHS p_rhs)
		{
			return p_lhs - p_rhs;
		}
		static inline RT Mul(PTLHS p_lhs, PTRHS p_rhs)
		{
			return p_lhs * p_rhs;
		}
		static inline RT Div(PTLHS p_lhs, PTRHS p_rhs)
		{
			return p_lhs / p_rhs;
		}
		static inline RT Mod(PTLHS p_lhs, PTRHS p_rhs)
		{
			return p_lhs % p_rhs;
		}
	};
}
