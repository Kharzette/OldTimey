#include	<stdint.h>
#include	<stdbool.h>
#include	"../Registers.h"
#include	"../Memory.h"
#include	"../AddressModes.h"

//doing these in the order they appear in the OpCode Matrix

//zp
void	STX_ZP(Registers *pRegs, MemModule *pMem, uint8_t argAddr)
{
	WriteZP(pMem, argAddr, pRegs->X);
}

//a
void	STX_Absolute(Registers *pRegs, MemModule *pMem, uint16_t argAddr)
{
	WriteAbsolute(pMem, argAddr, pRegs->X);
}

//zp,y
void	STX_ZPY(Registers *pRegs, MemModule *pMem, uint8_t argAddr)
{
	WriteZP(pMem, argAddr + pRegs->Y, pRegs->X);
}