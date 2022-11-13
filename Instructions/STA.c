#include	<stdint.h>
#include	<stdbool.h>
#include	"../Registers.h"
#include	"../MemController.h"
#include	"../AddressModes.h"

//doing these in the order they appear in the OpCode Matrix

//(zp,x)
void	STA_ZPIndirectX(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	uint16_t	pointer	=ZPX16(pRegs, pMem, argAddr);

	MCWriteAbsolute(pMem, pointer, pRegs->A);
}

//zp
void	STA_ZP(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	MCWriteZP(pMem, argAddr, pRegs->A);
}

//a
void	STA_Absolute(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	MCWriteAbsolute(pMem, argAddr, pRegs->A);
}

//(zp),y
void	STA_ZPIndirectY(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	uint16_t	pointer	=ZP16(pMem, argAddr);

	pointer	+=pRegs->Y;

	MCWriteAbsolute(pMem, pointer, pRegs->A);
}

//(zp)
void	STA_ZPIndirect(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	uint16_t	pointer	=ZP16(pMem, argAddr);

	MCWriteAbsolute(pMem, pointer, pRegs->A);
}

//zp,x
void	STA_ZPX(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	MCWriteZP(pMem, argAddr + pRegs->X, pRegs->A);
}

//a,y
void	STA_AbsoluteY(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	MCWriteAbsolute(pMem, argAddr + pRegs->Y, pRegs->A);
}

//a,x
void	STA_AbsoluteX(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	MCWriteAbsolute(pMem, argAddr + pRegs->X, pRegs->A);
}