#include	<stdint.h>
#include	<stdbool.h>
#include	"../Registers.h"
#include	"../Memory.h"
#include	"../AddressModes.h"

//doing these in the order they appear in the OpCode Matrix

//zp
void	STY_ZP(Registers *pRegs, MemModule *pMem, uint16_t argAddr)
{
	WriteZP(pMem, argAddr, pRegs->Y);
}

//a
void	STY_Absolute(Registers *pRegs, MemModule *pMem, uint16_t argAddr)
{
	WriteAbsolute(pMem, argAddr, pRegs->Y);
}

//zp,x
void	STY_ZPX(Registers *pRegs, MemModule *pMem, uint16_t argAddr)
{
	WriteZP(pMem, argAddr + pRegs->X, pRegs->Y);
}