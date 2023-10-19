#include "precomp.h"
#include "CryptoVM.h"



fs::ui& CryptoVM::i_reg(size_t p_nRegister)
{
	sfcn();
	sPrecondition(p_nRegister < m_registers.size());

	return m_registers[p_nRegister];
}

const fs::ui& CryptoVM::i_reg(size_t p_nRegister) const
{
	sfcn();
	sPrecondition(p_nRegister < m_registers.size());

	return m_registers[p_nRegister];
}

fs::ui& CryptoVM::i_a()
{
	sfcn();

	return m_accumulator;
}

const fs::ui& CryptoVM::i_a() const
{
	sfcn();

	return m_accumulator;
}

fs::ui& CryptoVM::i_b()
{
	sfcn();

	return m_accumulator_b;
}

const fs::ui& CryptoVM::i_b() const
{
	sfcn();

	return m_accumulator_b;
}



CryptoVM::CryptoVM()
{
	sfcn();
}

CryptoVM::~CryptoVM()
{
	sfcn();
}


const fs::ui& CryptoVM::acc() const
{
	sfcn();
	return m_accumulator;
}

const fs::ui& CryptoVM::bcc() const
{
	sfcn();

	return m_accumulator_b;
}

const fs::ui& CryptoVM::r(size_t p_ix) const
{
	sfcn();

	return i_reg(p_ix);
}



void CryptoVM::STA(size_t p_nRegister)
{
	sfcn();

	i_reg(p_nRegister) = i_a();
}

void CryptoVM::STB(size_t p_nRegister)
{
	sfcn();

	i_reg(p_nRegister) = i_b();
}


void CryptoVM::LDA(size_t p_nRegister)
{
	sfcn();

	i_a() = i_reg(p_nRegister);
}

void CryptoVM::LDA(const fs::ui& p_value)
{
	sfcn();

	i_a() = p_value;
}


void CryptoVM::LDB(size_t p_nRegister)
{
	sfcn();

	i_b() = i_reg(p_nRegister);
}

void CryptoVM::LDB(const fs::ui& p_value)
{
	sfcn();

	i_b() = p_value;
}


void CryptoVM::Move(size_t p_nFrom, size_t p_nTo)
{
	sfcn();

	i_reg(p_nFrom) = i_reg(p_nTo);
}

void CryptoVM::Swap(size_t p_n1)
{
	sfcn();

	fs::ui tmp = i_reg(p_n1);
	i_reg(p_n1) = i_a();
	i_a() = tmp;
}

void CryptoVM::Swap(size_t p_n1, size_t p_n2)
{
	sfcn();

	fs::ui tmp = i_reg(p_n1);
	i_reg(p_n1) = i_reg(p_n2);
	i_reg(p_n2) = tmp;
}




void CryptoVM::Add(const fs::ui& p_addend)
{
	sfcn();

	i_a() += p_addend;
}

void CryptoVM::Sub(const fs::ui& p_subtractend)
{
	sfcn();

	i_a() -= p_subtractend;
}

void CryptoVM::Mul(const fs::ui& p_x)
{
	sfcn();

	i_a() *= p_x;
}

void CryptoVM::Div(const fs::ui& p_divisor)
{
	sfcn();

	fs::ui tmp = i_a();
	tmp.Divide(p_divisor, &i_a(), &i_b());
}


void CryptoVM::Add(size_t p_n1)
{
	sfcn();
	i_a() += i_reg(p_n1);
}

void CryptoVM::Add(size_t p_n1, size_t p_n2)
{
	sfcn();

	i_a() = i_reg(p_n1) + i_reg(p_n2);
}

void CryptoVM::Add(size_t p_n1, size_t p_n2, size_t p_n3)
{
	sfcn();

	i_reg(p_n3) = i_reg(p_n1) + i_reg(p_n2);
}


void CryptoVM::Sub(size_t p_n1)
{
	sfcn();

	i_a() -= i_reg(p_n1);
}

void CryptoVM::Sub(size_t p_n1, size_t p_n2)
{
	sfcn();

	i_a() = i_reg(p_n1) - i_reg(p_n2);
}

void CryptoVM::Sub(size_t p_n1, size_t p_n2, size_t p_n3)
{
	sfcn();

	i_reg(p_n3) = i_reg(p_n1) - i_reg(p_n2);
}


void CryptoVM::Mul(size_t p_n1)
{
	sfcn();

	i_a() *= i_reg(p_n1);
}

void CryptoVM::Mul(size_t p_n1, size_t p_n2)
{
	sfcn();

	i_a() = i_reg(p_n1) * i_reg(p_n2);
}

void CryptoVM::Mul(size_t p_n1, size_t p_n2, size_t p_n3)
{
	sfcn();

	i_reg(p_n3) = i_reg(p_n1) * i_reg(p_n2);
}


void CryptoVM::Div(size_t p_n1)
{
	sfcn();

	fs::ui tmp = i_a();
	tmp.Divide(i_reg(p_n1), &i_a(), &i_b());
}

void CryptoVM::Div(size_t p_n1, size_t p_n2)
{
	sfcn();

	i_reg(p_n1).Divide(i_reg(p_n2), &i_a(), &i_b());
}

void CryptoVM::Div(size_t p_n1, size_t p_n2, size_t p_n3)
{
	sfcn();

	i_reg(p_n1).Divide(i_reg(p_n2), &i_reg(p_n3), &i_b());
}

void CryptoVM::Div(size_t p_n1, size_t p_n2, size_t p_n3, size_t p_n4)
{
	sfcn();

	i_reg(p_n1).Divide(i_reg(p_n2), &i_reg(p_n3), &i_reg(p_n4));
}


void CryptoVM::Pow(const fs::ui& p_e)
{
	sfcn();

	fs::qword exponent;
	fs::Coerce(p_e, &exponent);
	fs::ui tmp = fs::Pow(i_a(), exponent);
	i_a() = tmp;
}

void CryptoVM::Pow(size_t p_n1)
{
	sfcn();

	fs::qword exponent;
	fs::Coerce(i_reg(p_n1), &exponent);
	fs::ui tmp = fs::Pow(i_a(), exponent);
	i_a() = tmp;
}

void CryptoVM::Pow(size_t p_n1, size_t p_n2)
{
	sfcn();
	fs::qword exponent;
	fs::Coerce(i_reg(p_n2), &exponent);
	i_a() = fs::Pow(i_reg(p_n1), exponent);

}

void CryptoVM::Pow(size_t p_n1, size_t p_n2, size_t p_n3)
{
	sfcn();

	fs::qword exponent;
	fs::Coerce(i_reg(p_n2), &exponent);
	i_reg(p_n3) = fs::Pow(i_reg(p_n1), exponent);
}



void CryptoVM::xor(const fs::ui& p_literal)
{
	sfcn();

	i_a() ^= p_literal;
}

void CryptoVM::xor(size_t p_n1)
{
	sfcn();

	i_a() ^= i_reg(p_n1);
}

void CryptoVM::xor(size_t p_n1, size_t p_n2)
{
	sfcn();

	i_a() = i_reg(p_n1) ^ i_reg(p_n2);
}

void CryptoVM::xor(size_t p_n1, size_t p_n2, size_t p_n3)
{
	sfcn();
	i_reg(p_n3) = i_reg(p_n1) ^ i_reg(p_n2);
}


void CryptoVM::or(const fs::ui& p_literal)
{
	sfcn();

	i_a() |= p_literal;
}

void CryptoVM::or(size_t p_n1)
{
	sfcn();

	i_a() |= i_reg(p_n1);
}

void CryptoVM::or(size_t p_n1, size_t p_n2)
{
	sfcn();

	i_a() = i_reg(p_n1) | i_reg(p_n2);
}

void CryptoVM::or(size_t p_n1, size_t p_n2, size_t p_n3)
{
	sfcn();

	i_reg(p_n3) = i_reg(p_n1) | i_reg(p_n2);
}


void CryptoVM::and(const fs::ui& p_literal)
{
	sfcn();

	i_a() &= p_literal;
}

void CryptoVM::and(size_t p_n1)
{
	sfcn();

	i_a() &= i_reg(p_n1);
}

void CryptoVM::and(size_t p_n1, size_t p_n2)
{
	sfcn();

	i_a() = i_reg(p_n1) & i_reg(p_n2);
}

void CryptoVM::and(size_t p_n1, size_t p_n2, size_t p_n3)
{
	sfcn();

	i_reg(p_n3) = i_reg(p_n1) & i_reg(p_n2);
}


void CryptoVM::neg()
{
	sfcn();

	i_a().BitwiseNegate();
}

void CryptoVM::neg(size_t p_n1)
{
	sfcn();
	i_a() = ~i_reg(p_n1);
}


void CryptoVM::ShiftRight(const fs::ui& p_literal)
{
	sfcn();
	fs::ui::offset_t n;
	fs::Coerce(p_literal, &n);

	i_a() >>= n;
}

void CryptoVM::ShiftRight(size_t p_nRegister, const fs::ui& p_literal)
{
	sfcn();
	fs::ui::offset_t n;
	fs::Coerce(p_literal, &n);

	i_reg(p_nRegister) >>= n;
}
			  

void CryptoVM::ShiftRight(size_t p_nRegister)
{
	sfcn();

	fs::ui::offset_t n;
	fs::Coerce(i_reg(p_nRegister), &n);

	i_a() >>= n;
}

void CryptoVM::ShiftRight(size_t p_nRegister1, size_t p_nRegister2)
{
	sfcn();


	fs::ui::offset_t n;
	fs::Coerce(i_reg(p_nRegister2), &n);

	i_reg(p_nRegister1) >>= n;
}

void CryptoVM::ShiftLeft(const fs::ui& p_literal)
{
	sfcn();
	fs::ui::offset_t n;
	fs::Coerce(p_literal, &n);

	i_a() <<= n;
}

void CryptoVM::ShiftLeft(size_t p_nRegister, const fs::ui& p_literal)
{
	sfcn();
	fs::ui::offset_t n;
	fs::Coerce(p_literal, &n);

	i_reg(p_nRegister) <<= n;
}

void CryptoVM::ShiftLeft(size_t p_nRegister)
{
	sfcn();
	fs::ui::offset_t n;
	fs::Coerce(i_reg(p_nRegister), &n);

	i_a() <<= n;
}

void CryptoVM::ShiftLeft(size_t p_nRegister1, size_t p_nRegister2)
{
	sfcn();
	fs::ui::offset_t n;
	fs::Coerce(i_reg(p_nRegister2), &n);

	i_reg(p_nRegister1) <<= n;
}


void CryptoVM::ModAdd(const fs::ui& p_a)
{
	sfcn();
	fs::ui tmp = i_a();
	i_a() = fs::ModAdd(tmp, p_a, i_b());
}

void CryptoVM::ModAdd(size_t p_n)
{
	sfcn();

	fs::ui tmp = i_a();
	i_a() = fs::ModAdd(tmp, i_reg(p_n), i_b());
}

void CryptoVM::ModAdd(size_t p_n1, size_t p_n2)
{
	sfcn();

	i_a() = fs::ModAdd(i_reg(p_n1), i_reg(p_n2), i_b());
}

void CryptoVM::ModAdd(size_t p_n1, size_t p_n2, size_t p_n3)
{
	sfcn();
	i_reg(p_n3) = fs::ModAdd(i_reg(p_n1), i_reg(p_n2), i_b());
}

void CryptoVM::ModAdd(size_t p_n1, size_t p_n2, size_t p_n3, size_t p_n4)
{
	sfcn();
	i_reg(p_n3) = fs::ModAdd(i_reg(p_n1), i_reg(p_n2), i_reg(p_n4));
}


void CryptoVM::ModMul(const fs::ui& p_a)
{
	sfcn();
	fs::ui tmp = i_a();

	i_a() = fs::ModMul(tmp, p_a, i_b());
}

void CryptoVM::ModMul(size_t p_n)
{
	sfcn();

	fs::ui tmp = i_a();

	i_a() = fs::ModMul(tmp, i_reg(p_n), i_b());
}

void CryptoVM::ModMul(size_t p_n1, size_t p_n2)
{
	sfcn();

	i_a() = fs::ModMul(i_reg(p_n1), i_reg(p_n2), i_b());
}

void CryptoVM::ModMul(size_t p_n1, size_t p_n2, size_t p_n3)
{
	sfcn();

	i_reg(p_n3) = fs::ModMul(i_reg(p_n1), i_reg(p_n2), i_b());
}

void CryptoVM::ModMul(size_t p_n1, size_t p_n2, size_t p_n3, size_t p_n4)
{
	sfcn();

	i_reg(p_n3) = fs::ModMul(i_reg(p_n1), i_reg(p_n2), i_reg(p_n4));
}


void CryptoVM::ModExp(const fs::ui& p_a)
{
	sfcn();
	fs::ui tmp = i_a();

	i_a() = fs::ModExp(tmp, p_a, i_b());
}

void CryptoVM::ModExp(size_t p_n)
{
	sfcn();

	fs::ui tmp = i_a();
	i_a() = fs::ModExp(tmp, i_reg(p_n), i_b());
}

void CryptoVM::ModExp(size_t p_n1, size_t p_n2)
{
	sfcn();

	i_a() = fs::ModExp(i_reg(p_n1), i_reg(p_n2), i_b());
}

void CryptoVM::ModExp(size_t p_n1, size_t p_n2, size_t p_n3)
{
	sfcn();

	i_reg(p_n3) = fs::ModExp(i_reg(p_n1), i_reg(p_n2), i_b());
}

void CryptoVM::ModExp(size_t p_n1, size_t p_n2, size_t p_n3, size_t p_n4)
{
	sfcn();

	i_reg(p_n3) = fs::ModExp(i_reg(p_n1), i_reg(p_n2), i_reg(p_n4));
}



void CryptoVM::Rnd(const fs::ui& p_kBits)
{
	sfcn();
	
	fs::dword k;
	fs::Coerce(p_kBits, &k);

	i_a() = nth::Random(k);
}

void CryptoVM::Rnd(size_t p_n1, const fs::ui& p_kBits)
{
	sfcn();
	fs::dword k;
	fs::Coerce(p_kBits, &k);
	i_reg(p_n1) = nth::Random(k);
}


void CryptoVM::MillerRabin(const fs::ui& p_n, const fs::ui& p_t)
{
	sfcn();

	fs::dword t;
	fs::Coerce(p_t, &t);
	i_condition() = nth::MillerRabin(p_n, t);
}

void CryptoVM::MillerRabin(const fs::ui& p_t)
{
	sfcn();

	fs::dword t;
	fs::Coerce(p_t, &t);
	i_condition() = nth::MillerRabin(i_a(), t);
}

void CryptoVM::MillerRabin(size_t p_nRegister, const fs::ui& p_t)
{
	sfcn();
	fs::dword t;
	fs::Coerce(p_t, &t);
	i_condition() = nth::MillerRabin(i_reg(p_nRegister), t);
}


/* End of File: CryptoVM.cpp */
