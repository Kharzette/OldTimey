#ifndef __INSTRUCTIONS_H__
#define	__INSTRUCTIONS_H__
#include	<stdint.h>


typedef	struct	Registers;
typedef	struct	MemModule;

void	Missing(Registers *pRegs, MemModule *pMem, uint16_t arg);

void	ADC_ZPIndX(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	ADC_ZP(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	ADC_Immediate(Registers *pRegs, MemModule *pMem, uint16_t arg);
void	ADC_Absolute(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	ADC_ZPIndY(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	ADC_ZPIndirect(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	ADC_ZPX(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	ADC_AbsoluteY(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	ADC_AbsoluteX(Registers *pRegs, MemModule *pMem, uint16_t argAddr);

void	AND_ZPIndX(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	AND_ZP(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	AND_Immediate(Registers *pRegs, MemModule *pMem, uint16_t arg);
void	AND_Absolute(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	AND_ZPIndY(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	AND_ZPIndirect(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	AND_ZPX(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	AND_AbsoluteY(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	AND_AbsoluteX(Registers *pRegs, MemModule *pMem, uint16_t argAddr);

void	ASL_ZP(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	ASL_Accumulator(Registers *pRegs, MemModule *pNotUsed, uint16_t argNotUsedEither);
void	ASL_Absolute(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	ASL_ZPX(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	ASL_AbsoluteX(Registers *pRegs, MemModule *pMem, uint16_t argAddr);

void	LDA_ZPIndirectX(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	LDA_ZP(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	LDA_Immediate(Registers *pRegs, MemModule *pUnused, uint16_t arg);
void	LDA_Absolute(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	LDA_ZPIndirectY(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	LDA_ZPIndirect(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	LDA_ZPX(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	LDA_AbsoluteY(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	LDA_AbsoluteX(Registers *pRegs, MemModule *pMem, uint16_t argAddr);

void	LDX_Immediate(Registers *pRegs, MemModule *pUnused, uint16_t arg);
void	LDX_ZP(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	LDX_Absolute(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	LDX_ZPY(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	LDX_AbsoluteY(Registers *pRegs, MemModule *pMem, uint16_t argAddr);

void	LDY_Immediate(Registers *pRegs, MemModule *pUnused, uint16_t arg);
void	LDY_ZP(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	LDY_Absolute(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	LDY_ZPX(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	LDY_AbsoluteX(Registers *pRegs, MemModule *pMem, uint16_t argAddr);

void	STA_ZPIndirectX(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	STA_ZP(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	STA_Absolute(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	STA_ZPIndirectY(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	STA_ZPIndirect(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	STA_ZPX(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	STA_AbsoluteY(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	STA_AbsoluteX(Registers *pRegs, MemModule *pMem, uint16_t argAddr);

void	STX_ZP(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	STX_Absolute(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	STX_ZPY(Registers *pRegs, MemModule *pMem, uint16_t argAddr);

void	STY_ZP(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	STY_Absolute(Registers *pRegs, MemModule *pMem, uint16_t argAddr);
void	STY_ZPX(Registers *pRegs, MemModule *pMem, uint16_t argAddr);

#endif	//__INSTRUCTIONS_H__