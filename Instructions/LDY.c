#include	<stdint.h>
#include	<stdbool.h>
#include	"../Registers.h"
#include	"../MemController.h"
#include	"../AddressModes.h"

//doing these in the order they appear in the OpCode Matrix

//#
void	LDY_Immediate(Registers *pRegs, MemController *pUnUsed, uint16_t arg)
{
	pRegs->Y	=arg;
	FlagResultNZ(pRegs, arg);
}

//zp
void	LDY_ZP(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	pRegs->Y	=ZP(pMem, argAddr);
	FlagResultNZ(pRegs, pRegs->Y);
}

//a
void	LDY_Absolute(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	pRegs->Y	=Absolute8(pMem, argAddr);
	FlagResultNZ(pRegs, pRegs->Y);
}

//zp,x
void	LDY_ZPX(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	pRegs->Y	=ZPX(pRegs, pMem, argAddr);
	FlagResultNZ(pRegs, pRegs->Y);
}

//a,x
void	LDY_AbsoluteX(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	pRegs->Y	=AbsoluteX8(pRegs, pMem, argAddr);
	FlagResultNZ(pRegs, pRegs->Y);
}