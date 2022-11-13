#include	<stdint.h>
#include	<stdbool.h>
#include	"../Registers.h"
#include	"../MemController.h"
#include	"../AddressModes.h"


void	AND(Registers *pRegs, uint8_t arg0, uint8_t arg1, uint8_t *res)
{
	//and
	uint8_t	result	=arg0 & arg1;

	*res	=result;

	FlagResultNZ(pRegs, result);
}


//doing these in the order they appear in the OpCode Matrix

//(zp,x)
void	AND_ZPIndX(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	uint8_t	arg	=ZPIndirectX8(pRegs, pMem, argAddr);

	AND(pRegs, pRegs->A, arg, &pRegs->A);
}

//zp
void	AND_ZP(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	uint8_t	arg	=ZP(pMem, argAddr);

	AND(pRegs, pRegs->A, arg, &pRegs->A);
}

//#
void	AND_Immediate(Registers *pRegs, MemController *pMem, uint16_t arg)
{
	AND(pRegs, pRegs->A, arg, &pRegs->A);
}

//a
void	AND_Absolute(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	uint8_t	arg	=Absolute8(pMem, argAddr);

	AND(pRegs, pRegs->A, arg, &pRegs->A);
}

//(zp),y
void	AND_ZPIndY(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	uint8_t	arg	=ZPIndirectY8(pRegs, pMem, argAddr);

	AND(pRegs, pRegs->A, arg, &pRegs->A);
}

//(zp)
void	AND_ZPIndirect(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	uint8_t	arg	=ZPIndirect8(pMem, argAddr);

	AND(pRegs, pRegs->A, arg, &pRegs->A);
}

//zp,x
void	AND_ZPX(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	uint8_t	arg	=ZPX(pRegs, pMem, argAddr);

	AND(pRegs, pRegs->A, arg, &pRegs->A);
}

//a,y
void	AND_AbsoluteY(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	uint8_t	arg	=AbsoluteY8(pRegs, pMem, argAddr);
	
	AND(pRegs, pRegs->A, arg, &pRegs->A);
}

//a,x
void	AND_AbsoluteX(Registers *pRegs, MemController *pMem, uint16_t argAddr)
{
	uint8_t	arg	=AbsoluteX8(pRegs, pMem, argAddr);
	
	AND(pRegs, pRegs->A, arg, &pRegs->A);
}