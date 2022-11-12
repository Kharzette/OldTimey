#include	<stdint.h>
#include	<stdbool.h>
#include	"../Registers.h"
#include	"../Memory.h"
#include	"../AddressModes.h"

//doing these in the order they appear in the OpCode Matrix

//(zp,x)
void	STA_ZPIndirectX(Registers *pRegs, MemModule *pMem, uint8_t argAddr)
{
	uint16_t	pointer	=ZPX16(pRegs, pMem, argAddr);

	WriteAbsolute(pMem, pointer, pRegs->A);
}

//zp
void	STA_ZP(Registers *pRegs, MemModule *pMem, uint8_t argAddr)
{
	WriteZP(pMem, argAddr, pRegs->A);
}

//a
void	STA_Absolute(Registers *pRegs, MemModule *pMem, uint16_t argAddr)
{
	WriteAbsolute(pMem, argAddr, pRegs->A);
}

//(zp),y
void	STA_ZPIndirectY(Registers *pRegs, MemModule *pMem, uint8_t argAddr)
{
	uint16_t	pointer	=ZP16(pMem, argAddr);

	pointer	+=pRegs->Y;

	WriteAbsolute(pMem, pointer, pRegs->A);
}

//(zp)
void	STA_ZPIndirect(Registers *pRegs, MemModule *pMem, uint8_t argAddr)
{
	uint16_t	pointer	=ZP16(pMem, argAddr);

	WriteAbsolute(pMem, pointer, pRegs->A);
}

//zp,x
void	STA_ZPX(Registers *pRegs, MemModule *pMem, uint8_t argAddr)
{
	WriteZP(pMem, argAddr + pRegs->X, pRegs->A);
}

//a,y
void	STA_AbsoluteY(Registers *pRegs, MemModule *pMem, uint16_t argAddr)
{
	WriteAbsolute(pMem, argAddr + pRegs->Y, pRegs->A);
}

//a,x
void	STA_AbsoluteX(Registers *pRegs, MemModule *pMem, uint16_t argAddr)
{
	WriteAbsolute(pMem, argAddr + pRegs->X, pRegs->A);
}


//shift left one bit
void	ASL(Registers *pRegs, uint8_t arg0, uint8_t *res)
{
	//add
	uint16_t	result	=arg0;

	result	<<=1;

	*res	=result & 0xFF;

	if(result & 0x0100)	//bit 8 set?
	{
		pRegs->P	|=PFLG_CARRY;
	}
	else
	{
		pRegs->P	&=(!PFLG_CARRY);
	}

	FlagResultNZ(pRegs, *res);
}