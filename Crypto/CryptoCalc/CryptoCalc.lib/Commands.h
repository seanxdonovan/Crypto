
//
// Not a NOP but a line with no content
//
class Blank : public Command
{
public:
	Blank(CryptoVM& p_vm);
	static RCP Make(CryptoVM& p_vm);
	void Execute();
	void Print(fs::Stream& p_s);
};


// add literal to acc
class Add_al : public Command
{
public:
	Add_al(CryptoVM& p_vm, const fs::ui& p_literal);
	static RCP Make(CryptoVM& p_vm, const fs::ui& p_literal);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::ui m_literal;
};

// add register to acc
class Add_ar : public Command
{
public:
	Add_ar(CryptoVM& p_vm, fs::dword p_nRegister);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword m_nRegister;
};

// add two registers and store in acc
class Add_rr : public Command
{
public:
	Add_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword  m_nRegister1;
	fs::dword  m_nRegister2;
};

// add two registers and store in a third
class Add_rrr : public Command
{
public:
	Add_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword  m_nRegister1;
	fs::dword  m_nRegister2;
	fs::dword  m_nRegister3;
};



// Sub literal to acc
class Sub_al : public Command
{
public:
	Sub_al(CryptoVM& p_vm, const fs::ui& p_literal);
	static RCP Make(CryptoVM& p_vm, const fs::ui& p_literal);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::ui m_literal;
};

// Sub register to acc
class Sub_ar : public Command
{
public:
	Sub_ar(CryptoVM& p_vm, fs::dword p_nRegister);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword m_nRegister;
};

// Sub two registers and store in acc
class Sub_rr : public Command
{
public:
	Sub_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword  m_nRegister1;
	fs::dword  m_nRegister2;
};

// Sub two registers and store in a third
class Sub_rrr : public Command
{
public:
	Sub_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword  m_nRegister1;
	fs::dword  m_nRegister2;
	fs::dword  m_nRegister3;
};



// Mul literal to acc
class Mul_al : public Command
{
public:
	Mul_al(CryptoVM& p_vm, const fs::ui& p_literal);
	static RCP Make(CryptoVM& p_vm, const fs::ui& p_literal);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::ui m_literal;
};

// Mul register to acc
class Mul_ar : public Command
{
public:
	Mul_ar(CryptoVM& p_vm, fs::dword p_nRegister);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword m_nRegister;
};

// Mul two registers and store in acc
class Mul_rr : public Command
{
public:
	Mul_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword  m_nRegister1;
	fs::dword  m_nRegister2;
};

// Mul two registers and store in a third
class Mul_rrr : public Command
{
public:
	Mul_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword  m_nRegister1;
	fs::dword  m_nRegister2;
	fs::dword  m_nRegister3;
};






// Div literal to acc
class Div_al : public Command
{
public:
	Div_al(CryptoVM& p_vm, const fs::ui& p_literal);
	static RCP Make(CryptoVM& p_vm, const fs::ui& p_literal);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::ui m_literal;
};

// Div register to acc
class Div_ar : public Command
{
public:
	Div_ar(CryptoVM& p_vm, fs::dword p_nRegister);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword m_nRegister;
};

// Div two registers and store in acc
class Div_rr : public Command
{
public:
	Div_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword  m_nRegister1;
	fs::dword  m_nRegister2;
};

// Div two registers and store in a third
class Div_rrr : public Command
{
public:
	Div_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword  m_nRegister1;
	fs::dword  m_nRegister2;
	fs::dword  m_nRegister3;
};



// Div two registers and store quotient in a third and remainder in a
// fourth
class Div_rrrr : public Command
{
public:
	Div_rrrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3, fs::dword p_nRegister4);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3, fs::dword p_nRegister4);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword  m_nRegister1;
	fs::dword  m_nRegister2;
	fs::dword  m_nRegister3;
	fs::dword  m_nRegister4;
};



class STA_l : public Command
{
public:
	STA_l(CryptoVM& p_vm, const fs::ui& p_literal);
	static RCP Make(CryptoVM& p_vm, const fs::ui& p_literal);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::ui m_literal;
};

class STA_r : public Command
{
public:
	STA_r(CryptoVM& p_vm, fs::dword p_nRegister);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword m_nRegister;
};


class STB_r : public Command
{
public:
	STB_r(CryptoVM& p_vm, fs::dword p_nRegister);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword m_nRegister;
};



class LDA_l : public Command
{
public:
	LDA_l(CryptoVM& p_vm, const fs::ui& p_literal);
	static RCP Make(CryptoVM& p_vm, const fs::ui& p_literal);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::ui m_literal;
};

class LDA_r : public Command
{
public:
	LDA_r(CryptoVM& p_vm, fs::dword p_nRegister);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword m_nRegister;
};



class LDB_l : public Command
{
public:
	LDB_l(CryptoVM& p_vm, const fs::ui& p_literal);
	static RCP Make(CryptoVM& p_vm, const fs::ui& p_literal);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::ui m_literal;
};

class LDB_r : public Command
{
public:
	LDB_r(CryptoVM& p_vm, fs::dword p_nRegister);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword m_nRegister;
};


class MOV_rr : public Command
{
public:
	MOV_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword  m_nRegister1;
	fs::dword  m_nRegister2;
};

class SWP_rr : public Command
{
public:
	SWP_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword  m_nRegister1;
	fs::dword  m_nRegister2;
};

class SWP_r : public Command
{
public:
	SWP_r(CryptoVM& p_vm, fs::dword p_nRegister1);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword  m_nRegister1;
};




class Pow_al : public Command
{
public:
	Pow_al(CryptoVM& p_vm, const fs::ui& p_literal);
	static RCP Make(CryptoVM& p_vm, const fs::ui& p_literal);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::ui m_literal;
};

class Pow_ar : public Command
{
public:
	Pow_ar(CryptoVM& p_vm, fs::dword p_nRegister);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword m_nRegister;
};

class Pow_rr : public Command
{
public:
	Pow_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword  m_nRegister1;
	fs::dword  m_nRegister2;
};

class Pow_rrr : public Command
{
public:
	Pow_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword  m_nRegister1;
	fs::dword  m_nRegister2;
	fs::dword  m_nRegister3;
};






class XOR_al : public Command
{
public:
	XOR_al(CryptoVM& p_vm, const fs::ui& p_literal);
	static RCP Make(CryptoVM& p_vm, const fs::ui& p_literal);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::ui m_literal;
};

class XOR_ar : public Command
{
public:
	XOR_ar(CryptoVM& p_vm, fs::dword p_nRegister);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword m_nRegister;
};

class XOR_rr : public Command
{
public:
	XOR_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword  m_nRegister1;
	fs::dword  m_nRegister2;
};

class XOR_rrr : public Command
{
public:
	XOR_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword  m_nRegister1;
	fs::dword  m_nRegister2;
	fs::dword  m_nRegister3;
};








class OR_al : public Command
{
public:
	OR_al(CryptoVM& p_vm, const fs::ui& p_literal);
	static RCP Make(CryptoVM& p_vm, const fs::ui& p_literal);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::ui m_literal;

};

class OR_ar : public Command
{
public:
	OR_ar(CryptoVM& p_vm, fs::dword p_nRegister);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword m_nRegister;
};

class OR_rr : public Command
{
public:
	OR_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword  m_nRegister1;
	fs::dword  m_nRegister2;
};

class OR_rrr : public Command
{
public:
	OR_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword  m_nRegister1;
	fs::dword  m_nRegister2;
	fs::dword  m_nRegister3;
};








class AND_al : public Command
{
public:
	AND_al(CryptoVM& p_vm, const fs::ui& p_literal);
	static RCP Make(CryptoVM& p_vm, const fs::ui& p_literal);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::ui m_literal;
};

class AND_ar : public Command
{
public:
	AND_ar(CryptoVM& p_vm, fs::dword p_nRegister);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword m_nRegister;
};

class AND_rr : public Command
{
public:
	AND_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword  m_nRegister1;
	fs::dword  m_nRegister2;
};

class AND_rrr : public Command
{
public:
	AND_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword  m_nRegister1;
	fs::dword  m_nRegister2;
	fs::dword  m_nRegister3;
};



class NEG_a : public Command
{
public:
	NEG_a(CryptoVM& p_vm);
	static RCP Make(CryptoVM& p_vm);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::ui m_literal;
};

class NEG_r : public Command
{
public:
	NEG_r(CryptoVM& p_vm, fs::dword p_nRegister);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword m_nRegister;
};







class SHR_al : public Command
{
public:
	SHR_al(CryptoVM& p_vm, const fs::ui& p_literal);
	static RCP Make(CryptoVM& p_vm, const fs::ui& p_literal);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::ui m_literal;

};

class SHR_ar : public Command
{
public:
	SHR_ar(CryptoVM& p_vm, fs::dword p_nRegister);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister);
	void Execute();
	void Print(fs::Stream& p_s);

private:
	fs::dword m_nRegister;
};

class SHR_rl : public Command
{
	public:
		SHR_rl(CryptoVM& p_vm, fs::dword p_nRegister1, const fs::ui& p_literal);
		static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, const fs::ui& p_literal);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::dword  m_nRegister1;
		fs::ui m_literal;
};


class SHR_rr : public Command
{
	public:
		SHR_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
		static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::dword  m_nRegister1;
		fs::dword  m_nRegister2;
};



class SHL_al : public Command
{
	public:
		SHL_al(CryptoVM& p_vm, const fs::ui& p_literal);
		static RCP Make(CryptoVM& p_vm, const fs::ui& p_literal);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::ui m_literal;

};

class SHL_ar : public Command
{
	public:
		SHL_ar(CryptoVM& p_vm, fs::dword p_nRegister);
		static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister);
		void Execute();
		void Print(fs::Stream& p_s);

	private:
		fs::dword m_nRegister;
};

class SHL_rl : public Command
{
	public:
		SHL_rl(CryptoVM& p_vm, fs::dword p_nRegister1, const fs::ui& p_literal);
		static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, const fs::ui& p_literal);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::dword  m_nRegister1;
		fs::ui m_literal;
};


class SHL_rr : public Command
{
	public:
		SHL_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
		static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::dword  m_nRegister1;
		fs::dword  m_nRegister2;
};









class MODADD_al : public Command
{
	public:
		MODADD_al(CryptoVM& p_vm, const fs::ui& p_literal);
		static RCP Make(CryptoVM& p_vm, const fs::ui& p_literal);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::ui m_literal;
};

class MODADD_ar : public Command
{
	public:
		MODADD_ar(CryptoVM& p_vm, fs::dword p_nRegister);
		static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::dword m_nRegister;
};

class MODADD_rr : public Command
{
	public:
		MODADD_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
		static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::dword  m_nRegister1;
		fs::dword  m_nRegister2;
};

class MODADD_rrr : public Command
{
	public:
		MODADD_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
		static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::dword  m_nRegister1;
		fs::dword  m_nRegister2;
		fs::dword  m_nRegister3;
};

class MODADD_rrrr : public Command
{
	public:
		MODADD_rrrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3, fs::dword p_nRegister4);
		static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3, fs::dword p_nRegister4);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::dword  m_nRegister1;
		fs::dword  m_nRegister2;
		fs::dword  m_nRegister3;
		fs::dword  m_nRegister4;
};









class MODMUL_al : public Command
{
	public:
		MODMUL_al(CryptoVM& p_vm, const fs::ui& p_literal);
		static RCP Make(CryptoVM& p_vm, const fs::ui& p_literal);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::ui m_literal;
};

class MODMUL_ar : public Command
{
	public:
		MODMUL_ar(CryptoVM& p_vm, fs::dword p_nRegister);
		static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::dword m_nRegister;
};

class MODMUL_rr : public Command
{
	public:
		MODMUL_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
		static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::dword  m_nRegister1;
		fs::dword  m_nRegister2;
};

class MODMUL_rrr : public Command
{
	public:
		MODMUL_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
		static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::dword  m_nRegister1;
		fs::dword  m_nRegister2;
		fs::dword  m_nRegister3;
};

class MODMUL_rrrr : public Command
{
	public:
		MODMUL_rrrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3, fs::dword p_nRegister4);
		static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3, fs::dword p_nRegister4);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::dword  m_nRegister1;
		fs::dword  m_nRegister2;
		fs::dword  m_nRegister3;
		fs::dword  m_nRegister4;
};










class MODEXP_al : public Command
{
	public:
		MODEXP_al(CryptoVM& p_vm, const fs::ui& p_literal);
		static RCP Make(CryptoVM& p_vm, const fs::ui& p_literal);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::ui m_literal;
};

class MODEXP_ar : public Command
{
	public:
		MODEXP_ar(CryptoVM& p_vm, fs::dword p_nRegister);
		static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::dword m_nRegister;
};

class MODEXP_rr : public Command
{
	public:
		MODEXP_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
		static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::dword  m_nRegister1;
		fs::dword  m_nRegister2;
};

class MODEXP_rrr : public Command
{
	public:
		MODEXP_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
		static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::dword  m_nRegister1;
		fs::dword  m_nRegister2;
		fs::dword  m_nRegister3;
};

class MODEXP_rrrr : public Command
{
	public:
		MODEXP_rrrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3, fs::dword p_nRegister4);
		static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3, fs::dword p_nRegister4);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::dword  m_nRegister1;
		fs::dword  m_nRegister2;
		fs::dword  m_nRegister3;
		fs::dword  m_nRegister4;
};


class RND_al : public Command
{
public:
	RND_al(CryptoVM& p_vm, const fs::ui& p_literal);
	static RCP Make(CryptoVM& p_vm, const fs::ui& p_literal);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::ui m_literal;
};

class RND_rl : public Command
{
public:
	RND_rl(CryptoVM& p_vm, fs::dword p_nRegister, const fs::ui& p_literal);
	static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister, const fs::ui& p_literal);
	void Execute();
	void Print(fs::Stream& p_s);
private:
	fs::dword m_nRegister;
	fs::ui m_literal;
};


class MillerRabin_al : public Command
{
	public:
		MillerRabin_al(CryptoVM& p_vm, const fs::ui& p_literal);
		static RCP Make(CryptoVM& p_vm, const fs::ui& p_literal);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::ui m_literal;
};

class MillerRabin_rl : public Command
{
	public:
		MillerRabin_rl(CryptoVM& p_vm, fs::dword p_nRegister, const fs::ui& p_literal);
		static RCP Make(CryptoVM& p_vm, fs::dword p_nRegister, const fs::ui& p_literal);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::dword m_nRegister;
		fs::ui m_literal;
};

class MillerRabin_ll : public Command
{
	public:
		MillerRabin_ll(CryptoVM& p_vm, const fs::ui& p_literal, const fs::ui& p_literal_t);
		static RCP Make(CryptoVM& p_vm, const fs::ui& p_literal, const fs::ui& p_literal_t);
		void Execute();
		void Print(fs::Stream& p_s);
	private:
		fs::ui m_literal;
		fs::ui m_literal_t;
};

