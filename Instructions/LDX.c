#include	<stdint.h>
#include	<stdbool.h>
#include	"../Registers.h"
#include	"../MemController.h"
#include	"../AddressModes.h"

//doing these in the order they appear in the OpCode Matrix

//#
void	LDX_Immediate(Registers *pRegs, MemController *pUnUsed, uint8_t arg)
{
	pRegs->X	=arg;
	FlagResultNZ(pRegs, arg);
}

//zp
void	LDX_ZP(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	pRegs->X	=ZP(pMem, argAddr);
	FlagResultNZ(pRegs, pRegs->X);
}

//a
void	LDX_Absolute(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	pRegs->X	=Absolute8(pMem, argAddr);
	FlagResultNZ(pRegs, pRegs->X);
}

//zp,y
void	LDX_ZPY(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	pRegs->X	=ZPY(pRegs, pMem, argAddr);
	FlagResultNZ(pRegs, pRegs->X);
}

//a,y
void	LDX_AbsoluteY(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	pRegs->X	=AbsoluteY8(pRegs, pMem, argAddr);
	FlagResultNZ(pRegs, pRegs->X);
}