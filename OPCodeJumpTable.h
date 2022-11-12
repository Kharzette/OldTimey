#ifndef __OPCODEJUMPTABLE_H__
#define	__OPCODEJUMPTABLE_H__
#include	<stdint.h>
#include	"Instructions.h"

typedef	struct	Registers;
typedef	struct	MemModule;

//need a catch all func pointer.
//conjunction junction
typedef	void(*InstructionFunction)(Registers *, MemModule *, uint16_t arg);

InstructionFunction	OPCJumpTable[256]	=
{
	Missing,			//BRK s
	Missing,			//ORA (zp,x)
	Missing,	//nothing https://youtu.be/De4fBi5kRDI
	Missing,	//nothing
	Missing,			//TSB zp (W65C02S instruction)
	Missing,			//ORA zp
	ASL_ZP,				//ASL zp (14/f/Cali)
	Missing,			//RMB0 zp (first blood)
	Missing,			//PHP s
	Missing,			//ORA #
	ASL_Accumulator,	//ASL A
	Missing,	//nothing
	Missing,			//TSB a (W65C02S instruction)
	Missing,			//ORA a
	ASL_Absolute,		//ASL a
	Missing,			//BBR0 r (W65C02S instruction)
	Missing,			//BPL r
	Missing,			//ORA (zp),y
	Missing,			//ORA (zp)
	Missing,	//nothing
	Missing,			//TRB zp (W65C02S instruction)
	Missing,			//ORA zp,x
	ASL_ZPX,			//ASL zp,x
	Missing,			//RMB1 zp (W65C02S instruction)
	Missing,			//CLC i
	Missing,			//ORA a,y
	Missing,			//INC A
	Missing,	//nothing
	Missing,			//TRB a (W65C02S instruction)
	Missing,			//ORA a,x
	ASL_AbsoluteX,		//ASL a,x
	Missing,			//BBR1 r (W65C02S instruction)
	Missing,			//JSR a
	AND_ZPIndX,			//AND (zp,x)
	Missing,	//nothing
	Missing,	//nothing
	Missing,			//BIT zp
	AND_ZP,				//AND zp
	Missing,			//ROL zp
	Missing,			//RMB2 zp (W65C02S instruction)
	Missing,			//PLP s
	AND_Immediate,		//AND #
	Missing,			//ROL A
	Missing,	//nothing
	Missing,			//BIT a
	AND_Absolute,		//AND a
	Missing,			//ROL a
	Missing,			//BBR2 r (W65C02S instruction)
	Missing,			//BMI r
	AND_ZPIndY,			//AND (zp),y
	AND_ZPIndirect,		//AND (zp)
	Missing,	//nothing
	Missing,			//BIT zp,x
	AND_ZPX,			//AND zp,x
	Missing,			//ROL zp,x
	Missing,			//RMB3 zp (W65C02S instruction)
	Missing,			//SEC i
	AND_AbsoluteY,		//AND a,y
	Missing,			//DEC A
	Missing,	//nothing
	Missing,			//BIT a,x
	AND_AbsoluteX,		//AND a,x
	Missing,			//ROL a,x
	Missing,			//BBR3 r (W65C02S instruction)
	Missing,			//RTI s
	Missing,			//EOR (zp,x)
	Missing,	//nothing
	Missing,	//nothing
	Missing,	//nothing
	Missing,			//EOR zp
	Missing,			//LSR zp
	Missing,			//RMB4 zp (W65C02S instruction)
	Missing,			//PHA s
	Missing,			//EOR #
	Missing,			//LSR A
	Missing,	//nothing
	Missing,			//jmp a
	Missing,			//EOR a
	Missing,			//LSR a
	Missing,			//BBR4 r (W65C02S instruction)
	Missing,			//BVC r
	Missing,			//EOR (zp),y
	Missing,			//EOR (zp)
	Missing,	//nothing
	Missing,	//nothing
	Missing,			//EOR zp,x
	Missing,			//LSR zp,x
	Missing,			//RMB5 zp (W65C02S instruction)
	Missing,			//CLI
	Missing,			//EOR a,y
	Missing,			//PHY s
	Missing,	//nothing
	Missing,	//nothing
	Missing,			//EOR a,x
	Missing,			//LSR a,x
	Missing,			//BBR5 r (W65C02S instruction)
	Missing,			//RTS s
	ADC_ZPIndX,			//ADC (zp,x)
	Missing,	//nothing
	Missing,	//nothing
	Missing,			//STZ zp (W65C02S instruction)
	ADC_ZP,		//ADC zp
	Missing,			//ROR zp
	Missing,			//RMB6 zp
	Missing,			//PLA s
	ADC_Immediate,		//ADC #
	Missing,			//ROR A
	Missing,	//nothing
	Missing,			//jmp (a)
	ADC_Absolute,		//ADC a
	Missing,			//ROR a
	Missing,			//BBR6 r (W65C02S instruction)
	Missing,			//BVS r
	ADC_ZPIndY,			//ADC (zp),y
	ADC_ZPIndirect,		//ADC (zp)
	Missing,	//nothing
	Missing,			//STZ zp,x (W65C02S instruction)
	ADC_ZPX,			//ADC zp,x
	Missing,			//ROR zp,x
	Missing,			//RMB7 zp (W65C02S instruction)
	Missing,			//SEI i
	ADC_AbsoluteY,		//ADC a,y
	Missing,			//PLY s
	Missing,	//nothing
	Missing,			//JMP (a,x)
	ADC_AbsoluteX,		//ADC a,x
	Missing,			//ROR a,x
	Missing,			//BBR7 r (W65C02S instruction)
	Missing,			//BRA r (W65C02S instruction)
	STA_ZPIndirectX,	//STA (zp,x)
	Missing,	//nothing
	Missing,	//nothing
	STY_ZP,				//STY zp
	STA_ZP,				//STA zp
	STX_ZP,				//STX zp
	Missing,			//SMB0 zp (W65C02S instruction)
	Missing,			//DEY i
	Missing,			//BIT #
	Missing,			//TXA i
	Missing,	//nothing
	STY_Absolute,		//STY a
	STA_Absolute,		//STA a
	STX_Absolute,		//STX a
	Missing,			//BBS0 r (W65C02S instruction)
	Missing,			//BCC r
	STA_ZPIndirectY,	//STA (zp),y
	STA_ZPIndirect,		//STA (zp)
	Missing,	//nothing
	STY_ZPX,			//STY zp,x
	STA_ZPX,			//STA zp,x
	STX_ZPY,			//STX zp,y
	Missing,			//SMB1 zp (W65C02S instruction)
	Missing,			//TYA i
	STA_AbsoluteY,		//STA a,y
	Missing,			//TXS i
	Missing,	//nothing
	Missing,			//STZ a (W65C02S instruction)
	STA_AbsoluteX,		//STA a,x
	Missing,			//STZ a,x (W65C02S instruction)
	Missing,			//BBS1 r (W65C02S instruction)
	LDY_Immediate,		//LDY #
	LDA_ZPIndirectX,	//LDA (zp,x)
	LDX_Immediate,		//LDX #
	Missing,	//nothing
	LDY_ZP,				//LDY zp
	LDA_ZP,				//LDA zp
	LDX_ZP,				//LDX zp
	Missing,			//SMB2 zp (W65C02S instruction)
	Missing,			//TAY i (can't swim)
	LDA_Immediate,		//LDA #
	Missing,			//TAX i
	Missing,	//nothing
	LDY_Absolute,		//LDY a
	LDA_Absolute,		//LDA a
	LDX_Absolute,		//LDX a
	Missing,			//BBS2 r (W65C02S instruction)
	Missing,			//BCS r
	LDA_ZPIndirectY,	//LDA (zp),y
	LDA_ZPIndirect,		//LDA (zp)
	Missing,	//nothing
	LDY_ZPX,			//LDY zp,x
	LDA_ZPX,			//LDA zp,x
	LDX_ZPY,			//LDX zp,y
	Missing,			//SMB3 zp (W65C02S instruction)
	Missing,			//CLV i
	LDA_AbsoluteY,		//LDA a,y
	Missing,			//TSX i
	Missing,	//nothing
	LDY_AbsoluteX,		//LDY a,x
	LDA_AbsoluteX,		//LDA a,x
	LDX_AbsoluteY,		//LDX a,y
	Missing,			//BBS3 r (W65C02S instruction)
	Missing,			//CPY #
	Missing,			//CMP (zp,x)
	Missing,	//nothing
	Missing,	//nothing
	Missing,			//CPY zp
	Missing,			//CMP zp
	Missing,			//DEC zp
	Missing,			//SMB4 zp (W65C02S instruction)
	Missing,			//INY i
	Missing,			//CMP #
	Missing,			//DEX i
	Missing,			//WAI i (W65C02S instruction)
	Missing,			//CPY a
	Missing,			//CMP a
	Missing,			//DEC a
	Missing,			//BBS4 r (W65C02S instruction)
	Missing,			//BNE r
	Missing,			//CMP (zp),y
	Missing,			//COMP (zp)
	Missing,	//nothing
	Missing,	//nothing
	Missing,			//CMP zp,x
	Missing,			//DEC zp,x
	Missing,			//SMB5 zp (W65C02S instruction)
	Missing,			//CLD i
	Missing,			//CMP a,y
	Missing,			//PHX s (W65C02S instruction)
	Missing,			//STP i (W65C02S instruction)
	Missing,	//nothing
	Missing,			//CMP a,x
	Missing,			//DEC a,x
	Missing,			//BBS5 r (W65C02S instruction)
	Missing,			//CPX #
	Missing,			//SBC (zp,x)
	Missing,	//nothing
	Missing,	//nothing
	Missing,			//CPX zp
	Missing,			//SBC zp
	Missing,			//INC zp
	Missing,			//SMB6 zp (W65C02S instruction)
	Missing,			//INX i
	Missing,			//SBC #
	Missing,			//NOP i
	Missing,	//nothing
	Missing,			//CPX a
	Missing,			//SBC a
	Missing,			//INC a
	Missing,			//BBS6 r (W65C02S instruction)
	Missing,			//BEQ r
	Missing,			//SBC (zp),y
	Missing,			//SBC (zp)
	Missing,	//nothing
	Missing,	//nothing
	Missing,			//SBC zp,x
	Missing,			//INC zp,x
	Missing,			//SMB7 zp (W65C02S instruction)
	Missing,			//SED i
	Missing,			//SBC a,y
	Missing,			//PLX s
	Missing,	//nothing
	Missing,	//nothing
	Missing,			//SBC a,x
	Missing,			//INC a,x
	Missing				//BBS7 r (W65C02S instruction)}
};
#endif	//__OPCODEJUMPTABLE_H__