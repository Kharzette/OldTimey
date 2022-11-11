#include	<stdint.h>
#include	<stdbool.h>
#include	"Registers.h"
#include	"Memory.h"
#include	"AddressModes.h"

//doing these in the order they appear in the OpCode Matrix

//(zp,x)
void	ADC_ZPIndX(Registers *pRegs, const MemModule *pMem, uint8_t argAddr)
{
	uint8_t	arg	=ZPIndirectX8(pRegs, pMem, argAddr);

	ADC(pRegs, pRegs->A, arg, &pRegs->A);
}

//zp
void	ADC_ZP(Registers *pRegs, const MemModule *pMem, uint8_t argAddr)
{
	uint8_t	arg	=ZP(pMem, argAddr);

	ADC(pRegs, pRegs->A, arg, &pRegs->A);
}

//#
void	ADC_Immediate(Registers *pRegs, uint8_t arg)
{
	ADC(pRegs, pRegs->A, arg, &pRegs->A);
}

//a
void	ADC_Absolute(Registers *pRegs, const MemModule *pMem, uint16_t argAddr)
{
	uint8_t	arg	=Absolute8(pMem, argAddr);

	ADC(pRegs, pRegs->A, arg, &pRegs->A);
}

//(zp),y
void	ADC_ZPIndY(Registers *pRegs, const MemModule *pMem, uint8_t argAddr)
{
	uint8_t	arg	=ZPIndirectY8(pRegs, pMem, argAddr);

	ADC(pRegs, pRegs->A, arg, &pRegs->A);
}

//(zp)
void	ADC_ZPIndirect(Registers *pRegs, const MemModule *pMem, uint8_t argAddr)
{
	uint8_t	arg	=ZPIndirect8(pMem, argAddr);

	ADC(pRegs, pRegs->A, arg, &pRegs->A);
}

//zp,x
void	ADC_ZPX(Registers *pRegs, const MemModule *pMem, uint8_t argAddr)
{
	uint8_t	arg	=ZPX(pRegs, pMem, argAddr);

	ADC(pRegs, pRegs->A, arg, &pRegs->A);
}

//a,y
void	ADC_AbsoluteY(Registers *pRegs, const MemModule *pMem, uint16_t argAddr)
{
	uint8_t	arg	=AbsoluteY8(pRegs, pMem, argAddr);
	
	ADC(pRegs, pRegs->A, arg, &pRegs->A);
}

//a,x
void	ADC_AbsoluteX(Registers *pRegs, const MemModule *pMem, uint16_t argAddr)
{
	uint8_t	arg	=AbsoluteX8(pRegs, pMem, argAddr);
	
	ADC(pRegs, pRegs->A, arg, &pRegs->A);
}


//found this good page on flaggery https://www.righto.com/2012/12/the-6502-overflow-flag-explained.html
void	ADC(Registers *pRegs, uint8_t arg0, uint8_t arg1, uint8_t *res)
{
	//add
	uint16_t	result	=arg0 + arg1;

	//add carry bit
	result	+=(pRegs->P & 0x1);

	*res	=result & 0xFF;

	//overflow happens if the sign bit of both inputs differ from the result
	bool	overflow	=((arg0 ^ result) & (arg1 ^ result)) & 0x80;

	if(overflow)
	{
		pRegs->P	|=PFLG_OVERFLOW;
	}
	else
	{
		pRegs->P	&=(!PFLG_OVERFLOW);
	}

	if(result > 0xFF)
	{
		pRegs->P	|=PFLG_CARRY;
	}
	else
	{
		pRegs->P	&=(!PFLG_CARRY);
	}

	FlagResult(pRegs, *res);
}


void	FlagResult(Registers *pRegs, const uint8_t result)
{
	if(result == 0)
	{
		pRegs->P	|=PFLG_ZERO;
	}
	else
	{
		pRegs->P	&=(!PFLG_ZERO);
	}

	if(result >> 7)
	{
		pRegs->P	|=PFLG_NEGATIVE;
	}
	else
	{
		pRegs->P	&=(!PFLG_NEGATIVE);
	}
}