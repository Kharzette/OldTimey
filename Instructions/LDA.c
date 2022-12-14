#include	<stdint.h>
#include	<stdbool.h>
#include	"../Registers.h"
#include	"../MemController.h"
#include	"../AddressModes.h"

//doing these in the order they appear in the OpCode Matrix

//(zp,x)
void	LDA_ZPIndirectX(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	pRegs->A	=ZPIndirectX8(pRegs, pMem, argAddr);
	FlagResultNZ(pRegs, pRegs->A);
}

//zp
void	LDA_ZP(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	pRegs->A	=ZP(pMem, argAddr);
	FlagResultNZ(pRegs, pRegs->A);
}

//#
void	LDA_Immediate(Registers *pRegs, MemController *pUnUsed, uint16_t arg)
{
	pRegs->A	=arg;
	FlagResultNZ(pRegs, arg);
}

//a
void	LDA_Absolute(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	pRegs->A	=Absolute8(pMem, argAddr);
	FlagResultNZ(pRegs, pRegs->A);
}

//(zp),y
void	LDA_ZPIndirectY(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	pRegs->A	=ZPIndirectY8(pRegs, pMem, argAddr);
	FlagResultNZ(pRegs, pRegs->A);
}

//(zp)
void	LDA_ZPIndirect(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	pRegs->A	=ZPIndirect8(pMem, argAddr);
	FlagResultNZ(pRegs, pRegs->A);
}

//zp,x
void	LDA_ZPX(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	pRegs->A	=ZPX(pRegs, pMem, argAddr);
	FlagResultNZ(pRegs, pRegs->A);
}

//a,y
void	LDA_AbsoluteY(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	pRegs->A	=AbsoluteY8(pRegs, pMem, argAddr);
	FlagResultNZ(pRegs, pRegs->A);
}

//a,x
void	LDA_AbsoluteX(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	pRegs->A	=AbsoluteX8(pRegs, pMem, argAddr);
	FlagResultNZ(pRegs, pRegs->A);
}