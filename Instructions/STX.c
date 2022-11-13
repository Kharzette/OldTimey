#include	<stdint.h>
#include	<stdbool.h>
#include	"../Registers.h"
#include	"../MemController.h"
#include	"../AddressModes.h"

//doing these in the order they appear in the OpCode Matrix

//zp
void	STX_ZP(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	MCWriteZP(pMem, argAddr, pRegs->X);
}

//a
void	STX_Absolute(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	MCWriteAbsolute(pMem, argAddr, pRegs->X);
}

//zp,y
void	STX_ZPY(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	MCWriteZP(pMem, argAddr + pRegs->Y, pRegs->X);
}