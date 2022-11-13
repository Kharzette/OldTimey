#include	<stdint.h>
#include	<stdbool.h>
#include	"../Registers.h"
#include	"../MemController.h"
#include	"../AddressModes.h"

//doing these in the order they appear in the OpCode Matrix

//zp
void	STY_ZP(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	MCWriteZP(pMem, argAddr, pRegs->Y);
}

//a
void	STY_Absolute(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	MCWriteAbsolute(pMem, argAddr, pRegs->Y);
}

//zp,x
void	STY_ZPX(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	MCWriteZP(pMem, argAddr + pRegs->X, pRegs->Y);
}