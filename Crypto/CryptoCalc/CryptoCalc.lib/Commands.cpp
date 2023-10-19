#include "precomp.h"
#include "CryptoVM.h"
#include "Command.h"
#include "Commands.h"



Blank::Blank(CryptoVM& p_vm)
: Command(p_vm)
{
	sfcn();
}

Command::RCP Blank::Make(CryptoVM& p_vm)
{
	sfcn();

	return RCP(new Blank(p_vm));
}

void Blank::Execute()
{
	sfcn();
	// do nothing.
}

void Blank::Print(fs::Stream& p_s)
{
	sfcn();

	fs::WriteLn(p_s, "");
}




// Add_al
// add literal to acc
Add_al::Add_al(CryptoVM& p_vm, const fs::ui& p_literal)
    : Command(p_vm)
	, m_literal(p_literal)
{
	sfcn();
}

Command::RCP Add_al::Make(CryptoVM& p_vm, const fs::ui& p_literal)
{
	return RCP(new Add_al(p_vm, p_literal));
}

void Add_al::Execute()
{
	sfcn();

	m_vm.Add(m_literal);
}

void Add_al::Print(fs::Stream& p_s)
{
	sfcn();

	fs::WriteLn(p_s, fs::format("ADD ", m_literal));
}



Add_ar::Add_ar(CryptoVM& p_vm, fs::dword p_nRegister)
    : Command(p_vm)
	, m_nRegister(p_nRegister)
{
	    sfcn();
}

Command::RCP Add_ar::Make(CryptoVM& p_vm, fs::dword p_nRegister)
{
	sfcn();

	return RCP(new Add_ar(p_vm, p_nRegister));
}

void Add_ar::Execute()
{
	sfcn();

	m_vm.Add(m_nRegister);
}

void Add_ar::Print(fs::Stream& p_s)
{
	sfcn();

	fs::WriteLn(p_s, fs::format("ADD r", m_nRegister));
}


Add_rr::Add_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
    : Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
{
	sfcn();
}

Command::RCP Add_rr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
{
	sfcn();
	return RCP(new Add_rr(p_vm, p_nRegister1, p_nRegister2));
}

void Add_rr::Execute()
{
	m_vm.Add(m_nRegister1, m_nRegister2);
}

void Add_rr::Print(fs::Stream& p_s)
{
	sfcn();
	fs::WriteLn(p_s, fs::format("ADD r", m_nRegister1, " r", m_nRegister2));
}



Add_rrr::Add_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
, m_nRegister3(p_nRegister3)
{
	sfcn();
}

Command::RCP Add_rrr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
{
	sfcn();
	return RCP(new Add_rrr(p_vm, p_nRegister1, p_nRegister2, p_nRegister3));
}

void Add_rrr::Execute()
{
	sfcn();

	m_vm.Add(m_nRegister1, m_nRegister2, m_nRegister3);
}
void Add_rrr::Print(fs::Stream& p_s)
{
	sfcn();
	fs::WriteLn(p_s, fs::format("ADD r", m_nRegister1, " r", m_nRegister2, " r", m_nRegister3));
}





// Sub_al
// Sub literal to acc
Sub_al::Sub_al(CryptoVM& p_vm, const fs::ui& p_literal)
: Command(p_vm)
, m_literal(p_literal)
{
    sfcn();
}

Command::RCP Sub_al::Make(CryptoVM& p_vm, const fs::ui& p_literal)
{
    return RCP(new Sub_al(p_vm, p_literal));
}

void Sub_al::Execute()
{
    sfcn();

    m_vm.Sub(m_literal);
}

void Sub_al::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("SUB ", m_literal));
}



Sub_ar::Sub_ar(CryptoVM& p_vm, fs::dword p_nRegister)
: Command(p_vm)
, m_nRegister(p_nRegister)
{
    sfcn();
}

Command::RCP Sub_ar::Make(CryptoVM& p_vm, fs::dword p_nRegister)
{
    sfcn();

    return RCP(new Sub_ar(p_vm, p_nRegister));
}

void Sub_ar::Execute()
{
    sfcn();

    m_vm.Sub(m_nRegister);
}

void Sub_ar::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("SUB r", m_nRegister));
}


Sub_rr::Sub_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
{
    sfcn();
}

Command::RCP Sub_rr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
{
    sfcn();
    return RCP(new Sub_rr(p_vm, p_nRegister1, p_nRegister2));
}

void Sub_rr::Execute()
{
    m_vm.Sub(m_nRegister1, m_nRegister2);
}

void Sub_rr::Print(fs::Stream& p_s)
{
    sfcn();
    fs::WriteLn(p_s, fs::format("SUB r", m_nRegister1, " r", m_nRegister2));
}



Sub_rrr::Sub_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
, m_nRegister3(p_nRegister3)
{
    sfcn();
}

Command::RCP Sub_rrr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
{
    sfcn();
    return RCP(new Sub_rrr(p_vm, p_nRegister1, p_nRegister2, p_nRegister3));
}

void Sub_rrr::Execute()
{
    sfcn();

    m_vm.Sub(m_nRegister1, m_nRegister2, m_nRegister3);
}
void Sub_rrr::Print(fs::Stream& p_s)
{
    sfcn();
    fs::WriteLn(p_s, fs::format("SUB r", m_nRegister1, " r", m_nRegister2, " r", m_nRegister3));
}








Mul_al::Mul_al(CryptoVM& p_vm, const fs::ui& p_literal)
: Command(p_vm)
, m_literal(p_literal)
{
    sfcn();
}

Command::RCP Mul_al::Make(CryptoVM& p_vm, const fs::ui& p_literal)
{
    return RCP(new Mul_al(p_vm, p_literal));
}

void Mul_al::Execute()
{
    sfcn();

    m_vm.Mul(m_literal);
}

void Mul_al::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("Mul ", m_literal));
}



Mul_ar::Mul_ar(CryptoVM& p_vm, fs::dword p_nRegister)
: Command(p_vm)
, m_nRegister(p_nRegister)
{
    sfcn();
}

Command::RCP Mul_ar::Make(CryptoVM& p_vm, fs::dword p_nRegister)
{
    sfcn();

    return RCP(new Mul_ar(p_vm, p_nRegister));
}

void Mul_ar::Execute()
{
    sfcn();

    m_vm.Mul(m_nRegister);
}

void Mul_ar::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("Mul r", m_nRegister));
}


Mul_rr::Mul_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
{
    sfcn();
}

Command::RCP Mul_rr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
{
    sfcn();
    return RCP(new Mul_rr(p_vm, p_nRegister1, p_nRegister2));
}

void Mul_rr::Execute()
{
    m_vm.Mul(m_nRegister1, m_nRegister2);
}

void Mul_rr::Print(fs::Stream& p_s)
{
    sfcn();
    fs::WriteLn(p_s, fs::format("Mul r", m_nRegister1, " r", m_nRegister2));
}



Mul_rrr::Mul_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
, m_nRegister3(p_nRegister3)
{
    sfcn();
}

Command::RCP Mul_rrr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
{
    sfcn();
    return RCP(new Mul_rrr(p_vm, p_nRegister1, p_nRegister2, p_nRegister3));
}

void Mul_rrr::Execute()
{
    sfcn();

    m_vm.Mul(m_nRegister1, m_nRegister2, m_nRegister3);
}
void Mul_rrr::Print(fs::Stream& p_s)
{
    sfcn();
    fs::WriteLn(p_s, fs::format("Mul r", m_nRegister1, " r", m_nRegister2, " r", m_nRegister3));
}














Div_al::Div_al(CryptoVM& p_vm, const fs::ui& p_literal)
: Command(p_vm)
, m_literal(p_literal)
{
    sfcn();
}

Command::RCP Div_al::Make(CryptoVM& p_vm, const fs::ui& p_literal)
{
    return RCP(new Div_al(p_vm, p_literal));
}

void Div_al::Execute()
{
    sfcn();

    m_vm.Div(m_literal);
}

void Div_al::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("Div ", m_literal));
}



Div_ar::Div_ar(CryptoVM& p_vm, fs::dword p_nRegister)
: Command(p_vm)
, m_nRegister(p_nRegister)
{
    sfcn();
}

Command::RCP Div_ar::Make(CryptoVM& p_vm, fs::dword p_nRegister)
{
    sfcn();

    return RCP(new Div_ar(p_vm, p_nRegister));
}

void Div_ar::Execute()
{
    sfcn();

    m_vm.Div(m_nRegister);
}

void Div_ar::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("Div r", m_nRegister));
}

Div_rr::Div_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
{
    sfcn();
}

Command::RCP Div_rr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
{
    sfcn();
    return RCP(new Div_rr(p_vm, p_nRegister1, p_nRegister2));
}

void Div_rr::Execute()
{
    m_vm.Div(m_nRegister1, m_nRegister2);
}

void Div_rr::Print(fs::Stream& p_s)
{
    sfcn();
    fs::WriteLn(p_s, fs::format("Div r", m_nRegister1, " r", m_nRegister2));
}

Div_rrr::Div_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
, m_nRegister3(p_nRegister3)
{
    sfcn();
}

Command::RCP Div_rrr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
{
    sfcn();
    return RCP(new Div_rrr(p_vm, p_nRegister1, p_nRegister2, p_nRegister3));
}

void Div_rrr::Execute()
{
    sfcn();

    m_vm.Div(m_nRegister1, m_nRegister2, m_nRegister3);
}
void Div_rrr::Print(fs::Stream& p_s)
{
    sfcn();
    fs::WriteLn(p_s, fs::format("Div r", m_nRegister1, " r", m_nRegister2, " r", m_nRegister3));
}


Div_rrrr::Div_rrrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3, fs::dword p_nRegister4)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
, m_nRegister3(p_nRegister3)
, m_nRegister4(p_nRegister4)
{
    sfcn();
}

Command::RCP Div_rrrr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3, fs::dword p_nRegister4)
{
    sfcn();
    return RCP(new Div_rrrr(p_vm, p_nRegister1, p_nRegister2, p_nRegister3, p_nRegister4));
}

void Div_rrrr::Execute()
{
    sfcn();

    m_vm.Div(m_nRegister1, m_nRegister2, m_nRegister3, m_nRegister4);
}

void Div_rrrr::Print(fs::Stream& p_s)
{
    sfcn();
    fs::WriteLn(p_s, fs::format("Div r", m_nRegister1, " r", m_nRegister2, " r", m_nRegister3, " r", m_nRegister4));
}





STA_r::STA_r(CryptoVM& p_vm, fs::dword p_nRegister)
    : Command(p_vm)
	, m_nRegister(p_nRegister)
    {
	    sfcn();
    }

    Command::RCP STA_r::Make(CryptoVM& p_vm, fs::dword p_nRegister)
    {
	    sfcn();

	    return RCP(new STA_r(p_vm, p_nRegister));
    }

    void STA_r::Execute()
    {
	    sfcn();

	    m_vm.STA(m_nRegister);
    }

    void STA_r::Print(fs::Stream& p_s)
    {
	    sfcn();

	    fs::WriteLn(p_s, fs::format("STA r", m_nRegister));
    }





STB_r::STB_r(CryptoVM& p_vm, fs::dword p_nRegister)
: Command(p_vm)
, m_nRegister(p_nRegister)
{
    sfcn();
}

Command::RCP STB_r::Make(CryptoVM& p_vm, fs::dword p_nRegister)
{
    sfcn();

    return RCP(new STB_r(p_vm, p_nRegister));
}

void STB_r::Execute()
{
    sfcn();

    m_vm.STA(m_nRegister);
}

void STB_r::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("STA r", m_nRegister));
}


LDA_l::LDA_l(CryptoVM& p_vm, const fs::ui& p_literal)
: Command(p_vm)
, m_literal(p_literal)
{
    sfcn();
}

Command::RCP LDA_l::Make(CryptoVM& p_vm, const fs::ui& p_literal)
{
    return RCP(new LDA_l(p_vm, p_literal));
}

void LDA_l::Execute()
{
    sfcn();

    m_vm.LDA(m_literal);
}

void LDA_l::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("LDA ", m_literal));
}



LDA_r::LDA_r(CryptoVM& p_vm, fs::dword p_nRegister)
: Command(p_vm)
, m_nRegister(p_nRegister)
{
    sfcn();
}

Command::RCP LDA_r::Make(CryptoVM& p_vm, fs::dword p_nRegister)
{
    sfcn();

    return RCP(new LDA_r(p_vm, p_nRegister));
}

void LDA_r::Execute()
{
    sfcn();

    m_vm.LDA(m_nRegister);
}

void LDA_r::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("LDA r", m_nRegister));
}


LDB_l::LDB_l(CryptoVM& p_vm, const fs::ui& p_literal)
: Command(p_vm)
, m_literal(p_literal)
{
    sfcn();
}

Command::RCP LDB_l::Make(CryptoVM& p_vm, const fs::ui& p_literal)
{
    return RCP(new LDB_l(p_vm, p_literal));
}

void LDB_l::Execute()
{
    sfcn();

    m_vm.LDB(m_literal);
}

void LDB_l::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("LDB ", m_literal));
}



LDB_r::LDB_r(CryptoVM& p_vm, fs::dword p_nRegister)
: Command(p_vm)
, m_nRegister(p_nRegister)
{
    sfcn();
}

Command::RCP LDB_r::Make(CryptoVM& p_vm, fs::dword p_nRegister)
{
    sfcn();

    return RCP(new LDB_r(p_vm, p_nRegister));
}

void LDB_r::Execute()
{
    sfcn();

    m_vm.LDB(m_nRegister);
}

void LDB_r::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("LDB r", m_nRegister));
}


MOV_rr::MOV_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
{
    sfcn();
}

Command::RCP MOV_rr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
{
    sfcn();
    return RCP(new MOV_rr(p_vm, p_nRegister1, p_nRegister2));
}

void MOV_rr::Execute()
{
	sfcn();
	m_vm.Move(m_nRegister1, m_nRegister2);
}

void MOV_rr::Print(fs::Stream& p_s)
{
	sfcn();
	fs::WriteLn(p_s, fs::format("MOV r", m_nRegister1, " r", m_nRegister2));
}


SWP_rr::SWP_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
{
    sfcn();
}

Command::RCP SWP_rr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
{
    sfcn();
    return RCP(new SWP_rr(p_vm, p_nRegister1, p_nRegister2));
}

void SWP_rr::Execute()
{
    sfcn();
    m_vm.Swap(m_nRegister1, m_nRegister2);
}

void SWP_rr::Print(fs::Stream& p_s)
{
    sfcn();
    fs::WriteLn(p_s, fs::format("SWP r", m_nRegister1, " r", m_nRegister2));
}


SWP_r::SWP_r(CryptoVM& p_vm, fs::dword p_nRegister1)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
{
    sfcn();
}

Command::RCP SWP_r::Make(CryptoVM& p_vm, fs::dword p_nRegister1)
{
    sfcn();
    return RCP(new SWP_r(p_vm, p_nRegister1));
}

void SWP_r::Execute()
{
    sfcn();
    m_vm.Swap(m_nRegister1);
}

void SWP_r::Print(fs::Stream& p_s)
{
    sfcn();
    fs::WriteLn(p_s, fs::format("SWP r", m_nRegister1));
}






Pow_al::Pow_al(CryptoVM& p_vm, const fs::ui& p_literal)
: Command(p_vm)
, m_literal(p_literal)
{
    sfcn();
}

Command::RCP Pow_al::Make(CryptoVM& p_vm, const fs::ui& p_literal)
{
    return RCP(new Pow_al(p_vm, p_literal));
}

void Pow_al::Execute()
{
    sfcn();

    m_vm.Pow(m_literal);
}

void Pow_al::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("Pow ", m_literal));
}



Pow_ar::Pow_ar(CryptoVM& p_vm, fs::dword p_nRegister)
: Command(p_vm)
, m_nRegister(p_nRegister)
{
    sfcn();
}

Command::RCP Pow_ar::Make(CryptoVM& p_vm, fs::dword p_nRegister)
{
    sfcn();

    return RCP(new Pow_ar(p_vm, p_nRegister));
}

void Pow_ar::Execute()
{
    sfcn();

    m_vm.Pow(m_nRegister);
}

void Pow_ar::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("Pow r", m_nRegister));
}


Pow_rr::Pow_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
{
    sfcn();
}

Command::RCP Pow_rr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
{
    sfcn();
    return RCP(new Pow_rr(p_vm, p_nRegister1, p_nRegister2));
}

void Pow_rr::Execute()
{
    m_vm.Pow(m_nRegister1, m_nRegister2);
}

void Pow_rr::Print(fs::Stream& p_s)
{
    sfcn();
    fs::WriteLn(p_s, fs::format("Pow r", m_nRegister1, " r", m_nRegister2));
}



Pow_rrr::Pow_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
, m_nRegister3(p_nRegister3)
{
    sfcn();
}

Command::RCP Pow_rrr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
{
    sfcn();
    return RCP(new Pow_rrr(p_vm, p_nRegister1, p_nRegister2, p_nRegister3));
}

void Pow_rrr::Execute()
{
    sfcn();

    m_vm.Pow(m_nRegister1, m_nRegister2, m_nRegister3);
}
void Pow_rrr::Print(fs::Stream& p_s)
{
    sfcn();
    fs::WriteLn(p_s, fs::format("Pow r", m_nRegister1, " r", m_nRegister2, " r", m_nRegister3));
}











XOR_al::XOR_al(CryptoVM& p_vm, const fs::ui& p_literal)
: Command(p_vm)
, m_literal(p_literal)
{
    sfcn();
}

Command::RCP XOR_al::Make(CryptoVM& p_vm, const fs::ui& p_literal)
{
    return RCP(new XOR_al(p_vm, p_literal));
}

void XOR_al::Execute()
{
    sfcn();

    m_vm.xor(m_literal);
}

void XOR_al::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("XOR ", m_literal));
}



XOR_ar::XOR_ar(CryptoVM& p_vm, fs::dword p_nRegister)
: Command(p_vm)
, m_nRegister(p_nRegister)
{
    sfcn();
}

Command::RCP XOR_ar::Make(CryptoVM& p_vm, fs::dword p_nRegister)
{
    sfcn();

    return RCP(new XOR_ar(p_vm, p_nRegister));
}

void XOR_ar::Execute()
{
    sfcn();

    m_vm.xor(m_nRegister);
}

void XOR_ar::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("XOR r", m_nRegister));
}


XOR_rr::XOR_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
{
    sfcn();
}

Command::RCP XOR_rr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
{
    sfcn();
    return RCP(new XOR_rr(p_vm, p_nRegister1, p_nRegister2));
}

void XOR_rr::Execute()
{
    m_vm.xor(m_nRegister1, m_nRegister2);
}

void XOR_rr::Print(fs::Stream& p_s)
{
    sfcn();
    fs::WriteLn(p_s, fs::format("XOR r", m_nRegister1, " r", m_nRegister2));
}



XOR_rrr::XOR_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
, m_nRegister3(p_nRegister3)
{
    sfcn();
}

Command::RCP XOR_rrr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
{
    sfcn();
    return RCP(new XOR_rrr(p_vm, p_nRegister1, p_nRegister2, p_nRegister3));
}

void XOR_rrr::Execute()
{
    sfcn();

    m_vm.xor(m_nRegister1, m_nRegister2, m_nRegister3);
}
void XOR_rrr::Print(fs::Stream& p_s)
{
    sfcn();
    fs::WriteLn(p_s, fs::format("XOR r", m_nRegister1, " r", m_nRegister2, " r", m_nRegister3));
}












OR_al::OR_al(CryptoVM& p_vm, const fs::ui& p_literal)
: Command(p_vm)
, m_literal(p_literal)
{
    sfcn();
}

Command::RCP OR_al::Make(CryptoVM& p_vm, const fs::ui& p_literal)
{
    return RCP(new OR_al(p_vm, p_literal));
}

void OR_al::Execute()
{
    sfcn();

    m_vm.or(m_literal);
}

void OR_al::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("OR ", m_literal));
}



OR_ar::OR_ar(CryptoVM& p_vm, fs::dword p_nRegister)
: Command(p_vm)
, m_nRegister(p_nRegister)
{
    sfcn();
}

Command::RCP OR_ar::Make(CryptoVM& p_vm, fs::dword p_nRegister)
{
    sfcn();

    return RCP(new OR_ar(p_vm, p_nRegister));
}

void OR_ar::Execute()
{
    sfcn();

    m_vm.or(m_nRegister);
}

void OR_ar::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("OR r", m_nRegister));
}


OR_rr::OR_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
{
    sfcn();
}

Command::RCP OR_rr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
{
    sfcn();
    return RCP(new OR_rr(p_vm, p_nRegister1, p_nRegister2));
}

void OR_rr::Execute()
{
    m_vm.or(m_nRegister1, m_nRegister2);
}

void OR_rr::Print(fs::Stream& p_s)
{
    sfcn();
    fs::WriteLn(p_s, fs::format("OR r", m_nRegister1, " r", m_nRegister2));
}



OR_rrr::OR_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
, m_nRegister3(p_nRegister3)
{
    sfcn();
}

Command::RCP OR_rrr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
{
    sfcn();
    return RCP(new OR_rrr(p_vm, p_nRegister1, p_nRegister2, p_nRegister3));
}

void OR_rrr::Execute()
{
    sfcn();

    m_vm.or(m_nRegister1, m_nRegister2, m_nRegister3);
}
void OR_rrr::Print(fs::Stream& p_s)
{
    sfcn();
    fs::WriteLn(p_s, fs::format("OR r", m_nRegister1, " r", m_nRegister2, " r", m_nRegister3));
}












AND_al::AND_al(CryptoVM& p_vm, const fs::ui& p_literal)
: Command(p_vm)
, m_literal(p_literal)
{
    sfcn();
}

Command::RCP AND_al::Make(CryptoVM& p_vm, const fs::ui& p_literal)
{
    return RCP(new AND_al(p_vm, p_literal));
}

void AND_al::Execute()
{
    sfcn();

    m_vm.and(m_literal);
}

void AND_al::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("AND ", m_literal));
}



AND_ar::AND_ar(CryptoVM& p_vm, fs::dword p_nRegister)
: Command(p_vm)
, m_nRegister(p_nRegister)
{
    sfcn();
}

Command::RCP AND_ar::Make(CryptoVM& p_vm, fs::dword p_nRegister)
{
    sfcn();

    return RCP(new AND_ar(p_vm, p_nRegister));
}

void AND_ar::Execute()
{
    sfcn();

    m_vm.and(m_nRegister);
}

void AND_ar::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("AND r", m_nRegister));
}


AND_rr::AND_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
{
    sfcn();
}

Command::RCP AND_rr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
{
    sfcn();
    return RCP(new AND_rr(p_vm, p_nRegister1, p_nRegister2));
}

void AND_rr::Execute()
{
    m_vm.and(m_nRegister1, m_nRegister2);
}

void AND_rr::Print(fs::Stream& p_s)
{
    sfcn();
    fs::WriteLn(p_s, fs::format("AND r", m_nRegister1, " r", m_nRegister2));
}



AND_rrr::AND_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
, m_nRegister3(p_nRegister3)
{
    sfcn();
}

Command::RCP AND_rrr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
{
    sfcn();
    return RCP(new AND_rrr(p_vm, p_nRegister1, p_nRegister2, p_nRegister3));
}

void AND_rrr::Execute()
{
    sfcn();

    m_vm.and(m_nRegister1, m_nRegister2, m_nRegister3);
}
void AND_rrr::Print(fs::Stream& p_s)
{
    sfcn();
    fs::WriteLn(p_s, fs::format("AND r", m_nRegister1, " r", m_nRegister2, " r", m_nRegister3));
}




NEG_a::NEG_a(CryptoVM& p_vm)
: Command(p_vm)
{
    sfcn();
}

Command::RCP NEG_a::Make(CryptoVM& p_vm)
{
    return RCP(new NEG_a(p_vm));
}

void NEG_a::Execute()
{
    sfcn();

    m_vm.neg();
}

void NEG_a::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("NEG"));
}


NEG_r::NEG_r(CryptoVM& p_vm, fs::dword p_nRegister)
: Command(p_vm)
, m_nRegister(p_nRegister)
{
    sfcn();
}

Command::RCP NEG_r::Make(CryptoVM& p_vm, fs::dword p_nRegister)
{
    sfcn();

    return RCP(new NEG_r(p_vm, p_nRegister));
}

void NEG_r::Execute()
{
    sfcn();

    m_vm.neg(m_nRegister);
}

void NEG_r::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("NEG r", m_nRegister));
}










SHR_al::SHR_al(CryptoVM& p_vm, const fs::ui& p_literal)
: Command(p_vm)
, m_literal(p_literal)
{
    sfcn();
}

Command::RCP SHR_al::Make(CryptoVM& p_vm, const fs::ui& p_literal)
{
    return RCP(new SHR_al(p_vm, p_literal));
}

void SHR_al::Execute()
{
    sfcn();

    m_vm.ShiftRight(m_literal);
}

void SHR_al::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("SHR ", m_literal));
}



SHR_ar::SHR_ar(CryptoVM& p_vm, fs::dword p_nRegister)
: Command(p_vm)
, m_nRegister(p_nRegister)
{
    sfcn();
}

Command::RCP SHR_ar::Make(CryptoVM& p_vm, fs::dword p_nRegister)
{
    sfcn();

    return RCP(new SHR_ar(p_vm, p_nRegister));
}

void SHR_ar::Execute()
{
    sfcn();

    m_vm.ShiftRight(m_nRegister);
}

void SHR_ar::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("SHR r", m_nRegister));
}


SHR_rl::SHR_rl(CryptoVM& p_vm, fs::dword p_nRegister1, const fs::ui& p_literal)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_literal(p_literal)
{
    sfcn();
}

Command::RCP SHR_rl::Make(CryptoVM& p_vm, fs::dword p_nRegister1, const fs::ui& p_literal)
{
    sfcn();
    return RCP(new SHR_rl(p_vm, p_nRegister1, p_literal));
}

void SHR_rl::Execute()
{
	sfcn();
	m_vm.ShiftRight(m_nRegister1, m_literal);
}

void SHR_rl::Print(fs::Stream& p_s)
{
	sfcn();
	fs::WriteLn(p_s, fs::format("SHR r", m_nRegister1, " ", m_literal));
}



SHR_rr::SHR_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
{
	sfcn();
}

Command::RCP SHR_rr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
{
	sfcn();
	return RCP(new SHR_rr(p_vm, p_nRegister1, p_nRegister2));
}

void SHR_rr::Execute()
{
	sfcn();
	m_vm.ShiftRight(m_nRegister1, m_nRegister2);
}

void SHR_rr::Print(fs::Stream& p_s)
{
	sfcn();
	fs::WriteLn(p_s, fs::format("SHR r", m_nRegister1, " r", m_nRegister2));
}








SHL_al::SHL_al(CryptoVM& p_vm, const fs::ui& p_literal)
: Command(p_vm)
, m_literal(p_literal)
{
	sfcn();
}

Command::RCP SHL_al::Make(CryptoVM& p_vm, const fs::ui& p_literal)
{
	return RCP(new SHL_al(p_vm, p_literal));
}

void SHL_al::Execute()
{
	sfcn();

	m_vm.ShiftLeft(m_literal);
}

void SHL_al::Print(fs::Stream& p_s)
{
	sfcn();

	fs::WriteLn(p_s, fs::format("SHL ", m_literal));
}



SHL_ar::SHL_ar(CryptoVM& p_vm, fs::dword p_nRegister)
: Command(p_vm)
, m_nRegister(p_nRegister)
{
	sfcn();
}

Command::RCP SHL_ar::Make(CryptoVM& p_vm, fs::dword p_nRegister)
{
	sfcn();

	return RCP(new SHL_ar(p_vm, p_nRegister));
}

void SHL_ar::Execute()
{
	sfcn();

	m_vm.ShiftLeft(m_nRegister);
}

void SHL_ar::Print(fs::Stream& p_s)
{
	sfcn();

	fs::WriteLn(p_s, fs::format("SHL r", m_nRegister));
}


SHL_rl::SHL_rl(CryptoVM& p_vm, fs::dword p_nRegister1, const fs::ui& p_literal)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_literal(p_literal)
{
	sfcn();
}

Command::RCP SHL_rl::Make(CryptoVM& p_vm, fs::dword p_nRegister1, const fs::ui& p_literal)
{
	sfcn();
	return RCP(new SHL_rl(p_vm, p_nRegister1, p_literal));
}

void SHL_rl::Execute()
{
	sfcn();
	m_vm.ShiftLeft(m_nRegister1, m_literal);
}

void SHL_rl::Print(fs::Stream& p_s)
{
	sfcn();
	fs::WriteLn(p_s, fs::format("SHL r", m_nRegister1, " ", m_literal));
}



SHL_rr::SHL_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
{
	sfcn();
}

Command::RCP SHL_rr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
{
	sfcn();
	return RCP(new SHL_rr(p_vm, p_nRegister1, p_nRegister2));
}

void SHL_rr::Execute()
{
	sfcn();
	m_vm.ShiftLeft(m_nRegister1, m_nRegister2);
}

void SHL_rr::Print(fs::Stream& p_s)
{
	sfcn();
	fs::WriteLn(p_s, fs::format("SHL r", m_nRegister1, " r", m_nRegister2));
}















MODADD_al::MODADD_al(CryptoVM& p_vm, const fs::ui& p_literal)
: Command(p_vm)
, m_literal(p_literal)
{
	sfcn();
}

Command::RCP MODADD_al::Make(CryptoVM& p_vm, const fs::ui& p_literal)
{
	return RCP(new MODADD_al(p_vm, p_literal));
}

void MODADD_al::Execute()
{
	sfcn();

	m_vm.ModAdd(m_literal);
}

void MODADD_al::Print(fs::Stream& p_s)
{
	sfcn();

	fs::WriteLn(p_s, fs::format("MODADD ", m_literal));
}



MODADD_ar::MODADD_ar(CryptoVM& p_vm, fs::dword p_nRegister)
: Command(p_vm)
, m_nRegister(p_nRegister)
{
	sfcn();
}

Command::RCP MODADD_ar::Make(CryptoVM& p_vm, fs::dword p_nRegister)
{
	sfcn();

	return RCP(new MODADD_ar(p_vm, p_nRegister));
}

void MODADD_ar::Execute()
{
	sfcn();

	m_vm.ModAdd(m_nRegister);
}

void MODADD_ar::Print(fs::Stream& p_s)
{
	sfcn();

	fs::WriteLn(p_s, fs::format("MODADD r", m_nRegister));
}

MODADD_rr::MODADD_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
{
	sfcn();
}

Command::RCP MODADD_rr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
{
	sfcn();
	return RCP(new MODADD_rr(p_vm, p_nRegister1, p_nRegister2));
}

void MODADD_rr::Execute()
{
	sfcn();
	m_vm.ModAdd(m_nRegister1, m_nRegister2);
}

void MODADD_rr::Print(fs::Stream& p_s)
{
	sfcn();
	fs::WriteLn(p_s, fs::format("MODADD r", m_nRegister1, " r", m_nRegister2));
}

MODADD_rrr::MODADD_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
, m_nRegister3(p_nRegister3)
{
	sfcn();
}

Command::RCP MODADD_rrr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
{
	sfcn();
	return RCP(new MODADD_rrr(p_vm, p_nRegister1, p_nRegister2, p_nRegister3));
}

void MODADD_rrr::Execute()
{
	sfcn();
	m_vm.ModAdd(m_nRegister1, m_nRegister2, m_nRegister3);
}
void MODADD_rrr::Print(fs::Stream& p_s)
{
	sfcn();
	fs::WriteLn(p_s, fs::format("MODADD r", m_nRegister1, " r", m_nRegister2, " r", m_nRegister3));
}


MODADD_rrrr::MODADD_rrrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3, fs::dword p_nRegister4)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
, m_nRegister3(p_nRegister3)
, m_nRegister4(p_nRegister4)
{
	sfcn();
}

Command::RCP MODADD_rrrr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3, fs::dword p_nRegister4)
{
	sfcn();
	return RCP(new MODADD_rrrr(p_vm, p_nRegister1, p_nRegister2, p_nRegister3, p_nRegister4));
}

void MODADD_rrrr::Execute()
{
	sfcn();

	m_vm.ModAdd(m_nRegister1, m_nRegister2, m_nRegister3, m_nRegister4);
}

void MODADD_rrrr::Print(fs::Stream& p_s)
{
	sfcn();
	fs::WriteLn(p_s, fs::format("MODADD r", m_nRegister1, " r", m_nRegister2, " r", m_nRegister3, " r", m_nRegister4));
}














MODMUL_al::MODMUL_al(CryptoVM& p_vm, const fs::ui& p_literal)
: Command(p_vm)
, m_literal(p_literal)
{
	sfcn();
}

Command::RCP MODMUL_al::Make(CryptoVM& p_vm, const fs::ui& p_literal)
{
	return RCP(new MODMUL_al(p_vm, p_literal));
}

void MODMUL_al::Execute()
{
	sfcn();

	m_vm.ModMul(m_literal);
}

void MODMUL_al::Print(fs::Stream& p_s)
{
	sfcn();

	fs::WriteLn(p_s, fs::format("MODMUL ", m_literal));
}



MODMUL_ar::MODMUL_ar(CryptoVM& p_vm, fs::dword p_nRegister)
: Command(p_vm)
, m_nRegister(p_nRegister)
{
	sfcn();
}

Command::RCP MODMUL_ar::Make(CryptoVM& p_vm, fs::dword p_nRegister)
{
	sfcn();

	return RCP(new MODMUL_ar(p_vm, p_nRegister));
}

void MODMUL_ar::Execute()
{
	sfcn();

	m_vm.ModMul(m_nRegister);
}

void MODMUL_ar::Print(fs::Stream& p_s)
{
	sfcn();

	fs::WriteLn(p_s, fs::format("MODMUL r", m_nRegister));
}

MODMUL_rr::MODMUL_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
{
	sfcn();
}

Command::RCP MODMUL_rr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
{
	sfcn();
	return RCP(new MODMUL_rr(p_vm, p_nRegister1, p_nRegister2));
}

void MODMUL_rr::Execute()
{
	sfcn();
	m_vm.ModMul(m_nRegister1, m_nRegister2);
}

void MODMUL_rr::Print(fs::Stream& p_s)
{
	sfcn();
	fs::WriteLn(p_s, fs::format("MODMUL r", m_nRegister1, " r", m_nRegister2));
}

MODMUL_rrr::MODMUL_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
, m_nRegister3(p_nRegister3)
{
	sfcn();
}

Command::RCP MODMUL_rrr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
{
	sfcn();
	return RCP(new MODMUL_rrr(p_vm, p_nRegister1, p_nRegister2, p_nRegister3));
}

void MODMUL_rrr::Execute()
{
	sfcn();
	m_vm.ModMul(m_nRegister1, m_nRegister2, m_nRegister3);
}
void MODMUL_rrr::Print(fs::Stream& p_s)
{
	sfcn();
	fs::WriteLn(p_s, fs::format("MODMUL r", m_nRegister1, " r", m_nRegister2, " r", m_nRegister3));
}


MODMUL_rrrr::MODMUL_rrrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3, fs::dword p_nRegister4)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
, m_nRegister3(p_nRegister3)
, m_nRegister4(p_nRegister4)
{
	sfcn();
}

Command::RCP MODMUL_rrrr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3, fs::dword p_nRegister4)
{
	sfcn();
	return RCP(new MODMUL_rrrr(p_vm, p_nRegister1, p_nRegister2, p_nRegister3, p_nRegister4));
}

void MODMUL_rrrr::Execute()
{
	sfcn();

	m_vm.ModMul(m_nRegister1, m_nRegister2, m_nRegister3, m_nRegister4);
}

void MODMUL_rrrr::Print(fs::Stream& p_s)
{
	sfcn();
	fs::WriteLn(p_s, fs::format("MODMUL r", m_nRegister1, " r", m_nRegister2, " r", m_nRegister3, " r", m_nRegister4));
}


















MODEXP_al::MODEXP_al(CryptoVM& p_vm, const fs::ui& p_literal)
: Command(p_vm)
, m_literal(p_literal)
{
	sfcn();
}

Command::RCP MODEXP_al::Make(CryptoVM& p_vm, const fs::ui& p_literal)
{
	return RCP(new MODEXP_al(p_vm, p_literal));
}

void MODEXP_al::Execute()
{
	sfcn();

	m_vm.ModExp(m_literal);
}

void MODEXP_al::Print(fs::Stream& p_s)
{
	sfcn();

	fs::WriteLn(p_s, fs::format("MODEXP ", m_literal));
}



MODEXP_ar::MODEXP_ar(CryptoVM& p_vm, fs::dword p_nRegister)
: Command(p_vm)
, m_nRegister(p_nRegister)
{
	sfcn();
}

Command::RCP MODEXP_ar::Make(CryptoVM& p_vm, fs::dword p_nRegister)
{
	sfcn();

	return RCP(new MODEXP_ar(p_vm, p_nRegister));
}

void MODEXP_ar::Execute()
{
	sfcn();

	m_vm.ModExp(m_nRegister);
}

void MODEXP_ar::Print(fs::Stream& p_s)
{
	sfcn();

	fs::WriteLn(p_s, fs::format("MODEXP r", m_nRegister));
}

MODEXP_rr::MODEXP_rr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
{
	sfcn();
}

Command::RCP MODEXP_rr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2)
{
	sfcn();
	return RCP(new MODEXP_rr(p_vm, p_nRegister1, p_nRegister2));
}

void MODEXP_rr::Execute()
{
	sfcn();
	m_vm.ModExp(m_nRegister1, m_nRegister2);
}

void MODEXP_rr::Print(fs::Stream& p_s)
{
	sfcn();
	fs::WriteLn(p_s, fs::format("MODEXP r", m_nRegister1, " r", m_nRegister2));
}

MODEXP_rrr::MODEXP_rrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
, m_nRegister3(p_nRegister3)
{
	sfcn();
}

Command::RCP MODEXP_rrr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3)
{
	sfcn();
	return RCP(new MODEXP_rrr(p_vm, p_nRegister1, p_nRegister2, p_nRegister3));
}

void MODEXP_rrr::Execute()
{
	sfcn();
	m_vm.ModExp(m_nRegister1, m_nRegister2, m_nRegister3);
}
void MODEXP_rrr::Print(fs::Stream& p_s)
{
	sfcn();
	fs::WriteLn(p_s, fs::format("MODEXP r", m_nRegister1, " r", m_nRegister2, " r", m_nRegister3));
}


MODEXP_rrrr::MODEXP_rrrr(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3, fs::dword p_nRegister4)
: Command(p_vm)
, m_nRegister1(p_nRegister1)
, m_nRegister2(p_nRegister2)
, m_nRegister3(p_nRegister3)
, m_nRegister4(p_nRegister4)
{
	sfcn();
}

Command::RCP MODEXP_rrrr::Make(CryptoVM& p_vm, fs::dword p_nRegister1, fs::dword p_nRegister2, fs::dword p_nRegister3, fs::dword p_nRegister4)
{
	sfcn();
	return RCP(new MODEXP_rrrr(p_vm, p_nRegister1, p_nRegister2, p_nRegister3, p_nRegister4));
}

void MODEXP_rrrr::Execute()
{
	sfcn();

	m_vm.ModExp(m_nRegister1, m_nRegister2, m_nRegister3, m_nRegister4);
}

void MODEXP_rrrr::Print(fs::Stream& p_s)
{
	sfcn();
	fs::WriteLn(p_s, fs::format("MODEXP r", m_nRegister1, " r", m_nRegister2, " r", m_nRegister3, " r", m_nRegister4));
}







RND_al::RND_al(CryptoVM& p_vm, const fs::ui& p_literal)
: Command(p_vm)
, m_literal(p_literal)
{
    sfcn();
}

Command::RCP RND_al::Make(CryptoVM& p_vm, const fs::ui& p_literal)
{
    return RCP(new RND_al(p_vm, p_literal));
}

void RND_al::Execute()
{
    sfcn();

    m_vm.Rnd(m_literal);
}

void RND_al::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("MODEXP ", m_literal));
}



RND_rl::RND_rl(CryptoVM& p_vm, fs::dword p_nRegister, const fs::ui& p_literal)
: Command(p_vm)
, m_nRegister(p_nRegister)
, m_literal(p_literal)
{
    sfcn();
}

Command::RCP RND_rl::Make(CryptoVM& p_vm, fs::dword p_nRegister, const fs::ui& p_literal)
{
    sfcn();

    return RCP(new RND_rl(p_vm, p_nRegister, p_literal));
}

void RND_rl::Execute()
{
    sfcn();

    m_vm.Rnd(m_nRegister, m_literal);
}

void RND_rl::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("RND r", m_nRegister, " ", m_literal));
}










MillerRabin_al::MillerRabin_al(CryptoVM& p_vm, const fs::ui& p_literal)
: Command(p_vm)
, m_literal(p_literal)
{
    sfcn();
}

Command::RCP MillerRabin_al::Make(CryptoVM& p_vm, const fs::ui& p_literal)
{
    return RCP(new MillerRabin_al(p_vm, p_literal));
}

void MillerRabin_al::Execute()
{
    sfcn();

    m_vm.MillerRabin(m_literal);
}

void MillerRabin_al::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("MillerRabin ", m_literal));
}



MillerRabin_rl::MillerRabin_rl(CryptoVM& p_vm, fs::dword p_nRegister, const fs::ui& p_literal)
: Command(p_vm)
, m_nRegister(p_nRegister)
, m_literal(p_literal)
{
    sfcn();
}

Command::RCP MillerRabin_rl::Make(CryptoVM& p_vm, fs::dword p_nRegister, const fs::ui& p_literal)
{
    sfcn();

    return RCP(new MillerRabin_rl(p_vm, p_nRegister, p_literal));
}

void MillerRabin_rl::Execute()
{
    sfcn();

    m_vm.MillerRabin(m_nRegister, m_literal);
}

void MillerRabin_rl::Print(fs::Stream& p_s)
{
    sfcn();

    fs::WriteLn(p_s, fs::format("MillerRabin r", m_nRegister, " ", m_literal));
}
