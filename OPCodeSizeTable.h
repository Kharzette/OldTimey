#ifndef __OPCODESIZETABLE_H__
#define	__OPCODESIZETABLE_H__
#include	<stdint.h>


//how many code bytes in arguments for a particular opcode
//Addressing Modes taken from the w65c02s datasheet
//a				Absolute 2 byte address
//(a,x)			Absolute indexed indirect
//a,x or a,y	Absolute indexed with x or y
//(a)			Absolute indirect
//A				Accumulator register
//#				Immediate
//i				Implied, no argument needed
//r				Program Counter Relative
//s				Stack
//zp			Zero Page
//(zp,x)		Zero Page Indexed Indirect
//zp,x or zp,y	Zero Page Indexed with x or y
//(zp)			Zero Page Indirect
//(zp),y		Zero Page Indirect Indexed with Y
uint8_t	OPCArgSizeTable[256]	=
{
	0,		//BRK s
	1,		//ORA (zp,x)
	0, 0,	//nothing https://youtu.be/De4fBi5kRDI
	1,		//TSB zp (W65C02S instruction)
	1,		//ORA zp
	1,		//ASL zp (14/f/Cali)
	1,		//RMB0 zp (first blood)
	0,		//PHP s
	1,		//ORA #
	0,		//ASL A
	0,		//nothing
	2,		//TSB a (W65C02S instruction)
	2,		//ORA a
	2,		//ASL a
	1,		//BBR0 r (W65C02S instruction)
	1,		//BPL r
	1,		//ORA (zp),y
	1,		//ORA (zp)
	0,		//nothing
	1,		//TRB zp (W65C02S instruction)
	1,		//ORA zp,x
	1,		//ASL zp,x
	1,		//RMB1 zp (W65C02S instruction)
	0,		//CLC i
	2,		//ORA a,y
	0,		//INC A
	0,		//nothing
	2,		//TRB a (W65C02S instruction)
	2,		//ORA a,x
	2,		//ASL a,x
	1,		//BBR1 r (W65C02S instruction)
	2,		//JSR a
	1,		//AND (zp,x)
	0, 0,	//nothing
	1,		//BIT zp
	1,		//AND zp
	1,		//ROL zp
	1,		//RMB2 zp (W65C02S instruction)
	0,		//PLP s
	1,		//AND #
	0,		//ROL A
	0,		//nothing
	2,		//BIT a
	2,		//AND a
	2,		//ROL a
	1,		//BBR2 r (W65C02S instruction)
	1,		//BMI r
	1,		//AND (zp),y
	1,		//AND (zp)
	0,		//nothing
	1,		//BIT zp,x
	1,		//AND zp,x
	1,		//ROL zp,x
	1,		//RMB3 zp (W65C02S instruction)
	0,		//SEC i
	2,		//AND a,y
	0,		//DEC A
	0,		//nothing
	2,		//BIT a,x
	2,		//AND a,x
	2,		//ROL a,x
	1,		//BBR3 r (W65C02S instruction)
	0,		//RTI s
	1,		//EOR (zp,x)
	0, 0, 0,//nothing
	1,		//EOR zp
	1,		//LSR zp
	1,		//RMB4 zp (W65C02S instruction)
	0,		//PHA s
	1,		//EOR #
	0,		//LSR A
	0,		//nothing
	2,		//jmp a
	2,		//EOR a
	2,		//LSR a
	1,		//BBR4 r (W65C02S instruction)
	1,		//BVC r
	1,		//EOR (zp),y
	1,		//EOR (zp)
	0, 0,	//nothing
	1,		//EOR zp,x
	1,		//LSR zp,x
	1,		//RMB5 zp (W65C02S instruction)
	0,		//CLI
	2,		//EOR a,y
	0,		//PHY s
	0, 0,	//nothing
	2,		//EOR a,x
	2,		//LSR a,x
	1,		//BBR5 r (W65C02S instruction)
	0,		//RTS s
	1,		//ADC (zp,x)
	0, 0,	//nothing
	1,		//STZ zp (W65C02S instruction)
	1,		//ADC zp
	1,		//ROR zp
	1,		//RMB6 zp
	0,		//PLA s
	1,		//ADC #
	0,		//ROR A
	0,		//nothing
	2,		//jmp (a)
	2,		//ADC a
	2,		//ROR a
	1,		//BBR6 r (W65C02S instruction)
	1,		//BVS r
	1,		//ADC (zp),y
	1,		//ADC (zp)
	0,		//nothing
	1,		//STZ zp,x (W65C02S instruction)
	1,		//ADC zp,x
	1,		//ROR zp,x
	1,		//RMB7 zp (W65C02S instruction)
	0,		//SEI i
	2,		//ADC a,y
	0,		//PLY s
	0,		//nothing
	2,		//JMP (a,x)
	2,		//ADC a,x
	2,		//ROR a,x
	1,		//BBR7 r (W65C02S instruction)
	1,		//BRA r (W65C02S instruction)
	1,		//STA (zp,x)
	0, 0,	//nothing
	1,		//STY zp
	1,		//STA zp
	1,		//STX zp
	1,		//SMB0 zp (W65C02S instruction)
	0,		//DEY i
	1,		//BIT #
	0,		//TXA i
	0,		//nothing
	2,		//STY a
	2,		//STA a
	2,		//STX a
	1,		//BBS0 r (W65C02S instruction)
	1,		//BCC r
	1,		//STA (zp),y
	1,		//STA (zp)
	0,		//nothing
	1,		//STY zp,x
	1,		//STA zp,x
	1,		//STX zp,y
	1,		//SMB1 zp (W65C02S instruction)
	0,		//TYA i
	2,		//STA a,y
	0,		//TXS i
	0,		//nothing
	2,		//STZ a (W65C02S instruction)
	2,		//STA a,x
	2,		//STZ a,x (W65C02S instruction)
	1,		//BBS1 r (W65C02S instruction)
	1,		//LDY #
	1,		//LDA (zp,x)
	1,		//LDX #
	0,		//nothing
	1,		//LDY zp
	1,		//LDA zp
	1,		//LDX zp
	1,		//SMB2 zp (W65C02S instruction)
	0,		//TAY i (can't swim)
	1,		//LDA #
	0,		//TAX i
	0,		//nothing
	2,		//LDY a
	2,		//LDA a
	2,		//LDX a
	1,		//BBS2 r (W65C02S instruction)
	1,		//BCS r
	1,		//LDA (zp),y
	1,		//LDA (zp)
	0,		//nothing
	1,		//LDY zp,x
	1,		//LDA zp,x
	1,		//LDX zp,y
	1,		//SMB3 zp (W65C02S instruction)
	0,		//CLV i
	2,		//LDA a,y
	0,		//TSX i
	0,		//nothing
	2,		//LDY a,x
	2,		//LDA a,x
	2,		//LDX a,y
	1,		//BBS3 r (W65C02S instruction)
	1,		//CPY #
	1,		//CMP (zp,x)
	0, 0,	//nothing
	1,		//CPY zp
	1,		//CMP zp
	1,		//DEC zp
	1,		//SMB4 zp (W65C02S instruction)
	0,		//INY i
	1,		//CMP #
	0,		//DEX i
	0,		//WAI i (W65C02S instruction)
	2,		//CPY a
	2,		//CMP a
	2,		//DEC a
	1,		//BBS4 r (W65C02S instruction)
	1,		//BNE r
	1,		//CMP (zp),y
	1,		//COMP (zp)
	0, 0,	//nothing
	1,		//CMP zp,x
	1,		//DEC zp,x
	1,		//SMB5 zp (W65C02S instruction)
	0,		//CLD i
	2,		//CMP a,y
	0,		//PHX s (W65C02S instruction)
	0,		//STP i (W65C02S instruction)
	0,		//nothing
	2,		//CMP a,x
	2,		//DEC a,x
	1,		//BBS5 r (W65C02S instruction)
	1,		//CPX #
	1,		//SBC (zp,x)
	0, 0,	//nothing
	1,		//CPX zp
	1,		//SBC zp
	1,		//INC zp
	1,		//SMB6 zp (W65C02S instruction)
	0,		//INX i
	1,		//SBC #
	0,		//NOP i
	0,		//nothing
	2,		//CPX a
	2,		//SBC a
	2,		//INC a
	1,		//BBS6 r (W65C02S instruction)
	1,		//BEQ r
	1,		//SBC (zp),y
	1,		//SBC (zp)
	0, 0,	//nothing
	1,		//SBC zp,x
	1,		//INC zp,x
	1,		//SMB7 zp (W65C02S instruction)
	0,		//SED i
	2,		//SBC a,y
	0,		//PLX s
	0, 0,	//nothing
	2,		//SBC a,x
	2,		//INC a,x
	1,		//BBS7 r (W65C02S instruction)
};

#endif	//__OPCODESIZETABLE_H__