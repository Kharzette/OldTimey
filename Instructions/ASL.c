#include	<stdint.h>
#include	<stdbool.h>
#include	"../Registers.h"
#include	"../Memory.h"
#include	"../AddressModes.h"


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


//doing these in the order they appear in the OpCode Matrix

//zp
void	ASL_ZP(Registers *pRegs, MemModule *pMem, uint16_t argAddr)
{
	uint8_t	arg	=ZP(pMem, argAddr);

	ASL(pRegs, arg, &arg);

	WriteZP(pMem, argAddr, arg);
}

//A
void	ASL_Accumulator(Registers *pRegs, MemModule *pUnUsed, uint16_t argUnUsed)
{
	ASL(pRegs, pRegs->A, &pRegs->A);
}

//a
void	ASL_Absolute(Registers *pRegs, MemModule *pMem, uint16_t argAddr)
{
	uint8_t	arg	=Absolute8(pMem, argAddr);

	ASL(pRegs, arg, &arg);

	WriteAbsolute(pMem, argAddr, arg);
}

//zp,x
void	ASL_ZPX(Registers *pRegs, MemModule *pMem, uint16_t argAddr)
{
	uint8_t	arg	=ZPX(pRegs, pMem, argAddr);

	ASL(pRegs, arg, &arg);

	WriteZP(pMem, argAddr + pRegs->X, arg);
}

//a,x
void	ASL_AbsoluteX(Registers *pRegs, MemModule *pMem, uint16_t argAddr)
{
	uint8_t	arg	=AbsoluteX8(pRegs, pMem, argAddr);
	
	ASL(pRegs, arg, &arg);

	WriteAbsolute(pMem, argAddr + pRegs->X, arg);
}