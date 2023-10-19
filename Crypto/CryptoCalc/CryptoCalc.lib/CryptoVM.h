

class CryptoVM
{
	std::vector<fs::ui> m_registers; // r[0 -- 255]
	fs::ui m_accumulator; // acc
	fs::ui m_accumulator_b; // bcc
	bool m_conditionFlag; // set based on result of a condition primative

	fs::ui& i_reg(size_t p_nRegister);
	const fs::ui& i_reg(size_t p_nRegister) const;
	fs::ui& i_a();
	const fs::ui& i_a() const;
	fs::ui& i_b();
	const fs::ui& i_b() const;

	bool& i_condition();
	const bool i_condition() const;
public:
	CryptoVM();
	~CryptoVM();

	const fs::ui& acc() const;
	const fs::ui& bcc() const; // alternate accumulator
	const fs::ui& r(size_t ix) const;


	void STA(size_t p_nRegister); // acc --> r[n]
	void STB(size_t p_nRegister); // bcc --> r[n]

	void LDA(size_t p_nRegister); // acc <-- r[n]
	void LDA(const fs::ui& p_value); // acc <-- p_value

	void LDB(size_t p_nRegister); // bcc <-- r[n]
	void LDB(const fs::ui& p_value); // bcc <-- p_value

	void Move(size_t p_nFrom, size_t p_nTo); // r[p_nFrom] --> r[p_nTo]
	void Swap(size_t p_n1); // swap acc with r1
	void Swap(size_t p_n1, size_t p_n2); // swap r1 with r2

	void Add(const fs::ui& p_addend); // add to acc
	void Add(size_t p_n1); // acc = acc + r[n1];
	void Add(size_t p_n1, size_t p_n2); // acc = r[n1] + r[n2]
	void Add(size_t p_n1, size_t p_n2, size_t p_n3); // r[n3] = r[n1] + r[n2]

	void Sub(const fs::ui& p_subtractend); // sub from acc
	void Sub(size_t p_n1); // acc = acc - r[n1]
	void Sub(size_t p_n1, size_t p_n2); // acc = r[n1] - r[n2]
	void Sub(size_t p_n1, size_t p_n2, size_t p_n3); // r[n3] = r[n1] - r[n2]

	void Mul(const fs::ui& p_x); // acc = acc * p_x
	void Mul(size_t p_n1); // acc = acc * r[n1]
	void Mul(size_t p_n1, size_t p_n2); // acc = r[n1] * r[n2]
	void Mul(size_t p_n1, size_t p_n2, size_t p_n3); // r[n3] = r[n1] * r[n2]

	void Div(const fs::ui& p_divisor); // acc = acc / p_divisor bcc = acc % p_divisor
	void Div(size_t p_n1); // acc = acc / r[n1] bcc = acc % r[n1]
	void Div(size_t p_n1, size_t p_n2); // acc = r[n1]/r[n2], bcc = r[n1]%r[n2]
	void Div(size_t p_n1, size_t p_n2, size_t p_n3); // r[n3] = r[n1]/r[n2], bcc = r[n1]%r[n2]
	void Div(size_t p_n1, size_t p_n2, size_t p_n3, size_t p_n4); // r[n3] = r[n1]/r[n2], r[n4] = r[n1]%r[n2]

	void Pow(const fs::ui& p_e);
	void Pow(size_t p_n1); // acc = acc^r[n1] - exponentiate
	void Pow(size_t p_n1, size_t p_n2);
	void Pow(size_t p_n1, size_t p_n2, size_t p_n3);
	
	void xor(const fs::ui& p_literal);
	void xor(size_t p_n1); // acc = acc ^ r[n1]
	void xor(size_t p_n1, size_t p_n2); // acc = r[n1] ^ r[n2]
	void xor(size_t p_n1, size_t p_n2, size_t p_n3); // r[n3] = r[n1] ^ r[n2]

	void or(const fs::ui& p_literal);
	void or(size_t p_n1); // acc = acc | r[n1]
	void or(size_t p_n1, size_t p_n2); // acc = r[n1] | r[n2]
	void or(size_t p_n1, size_t p_n2, size_t p_n3); // r[n3] = r[n1] | r[n2]

	void and(const fs::ui& p_literal);
	void and(size_t p_n1); // acc = acc & r[n1]
	void and(size_t p_n1, size_t p_n2); // acc = r[n1] & r[n2]
	void and(size_t p_n1, size_t p_n2, size_t p_n3); // r[n3] = r[n1] & r[n2]

	void neg(); // acc = ~acc
	void neg(size_t p_n1); // r[n1] = ~r[n1]

	void ShiftRight(const fs::ui& p_literal); // acc >>= n
	void ShiftRight(size_t p_n1, const fs::ui& p_literal); // r[n1] = r[n1] >> n
	void ShiftRight(size_t p_n); // acc >>= r[n]
	void ShiftRight(size_t p_n1, size_t p_n); // r[n1] = r[n1] >> r2[n]

	void ShiftLeft(const fs::ui& p_literal); // acc >>= n
	void ShiftLeft(size_t p_n1, const fs::ui& p_literal); // r[n1] = r[n1] >> n
	void ShiftLeft(size_t p_n); // acc <<= n
	void ShiftLeft(size_t p_n1, size_t p_n); // r[n1] <<= n

	void ModAdd(const fs::ui& p_a); // acc = (acc + p_a) mod bcc
	void ModAdd(size_t p_n); // acc = (acc + r[n]) mod bcc
	void ModAdd(size_t p_n1, size_t p_n2); // acc = (r[n1] + r[n2]) mod bcc
	void ModAdd(size_t p_n1, size_t p_n2, size_t p_n3); // r[n3] = (r[n1] + r[n2]) mod bcc
	void ModAdd(size_t p_n1, size_t p_n2, size_t p_n3, size_t); // r[n3] = (r[n1] + r[n2]) mod r[n4]

	void ModMul(const fs::ui& p_a); // acc = (acc * p_a) mod bcc
	void ModMul(size_t p_n); // acc = (acc * r[n]) mod bcc
	void ModMul(size_t p_n1, size_t p_n2); // acc = (r[n1] * r[n2]) mod bcc
	void ModMul(size_t p_n1, size_t p_n2, size_t p_n3); // r[n3] = (r[n1] * r[n2]) mod bcc
	void ModMul(size_t p_n1, size_t p_n2, size_t p_n3, size_t); // r[n3] = (r[n1] * r[n2]) mod r[n4]

	void ModExp(const fs::ui& p_a); // acc = (acc ^ p_a) mod bcc
	void ModExp(size_t p_n); // acc = (acc ^ r[n]) mod bcc
	void ModExp(size_t p_n1, size_t p_n2); // acc = (r[n1] ^ r[n2]) mod bcc
	void ModExp(size_t p_n1, size_t p_n2, size_t p_n3); // r[n3] = (r[n1] ^ r[n2]) mod bcc
	void ModExp(size_t p_n1, size_t p_n2, size_t p_n3, size_t); // r[n3] = (r[n1] ^ r[n2]) mod r[n4]

	void Rnd(const fs::ui& p_kBits);
	void Rnd(size_t p_n1, const fs::ui& p_kBits);


	// condition true if MR prime false if composite
	void MillerRabin(const fs::ui& p_n, const fs::ui& p_t);
	void MillerRabin(const fs::ui& p_t);
	void MillerRabin(size_t p_nRegister, const fs::ui& p_t);
};
