#include	<stdint.h>
#include	<stdbool.h>
#include	"Registers.h"
#include	"MemController.h"


//a
uint8_t	Absolute8(const MemController *pMem, uint16_t argAddr)
{
	return	MCFetchValue(pMem, argAddr);
}

//a
uint16_t	Absolute16(const MemController *pMem, uint16_t argAddr)
{
	return	MCFetchValue16(pMem, argAddr);
}

//(a,x)
uint16_t	AbsoluteIndirectX(const Registers *pRegs, const MemController *pMem, uint16_t argAddr)
{
	uint16_t	pointer	=MCFetchValue16(pMem, argAddr + pRegs->X);

	return	MCFetchValue16(pMem, pointer);
}

//a,x
uint8_t	AbsoluteX8(const Registers *pRegs, const MemController *pMem, uint16_t argAddr)
{
	return	MCFetchValue(pMem, argAddr + pRegs->X);
}

//a,x
uint16_t	AbsoluteX16(const Registers *pRegs, const MemController *pMem, uint16_t argAddr)
{
	return	MCFetchValue16(pMem, argAddr + pRegs->X);
}

//a,y
uint16_t	AbsoluteY16(const Registers *pRegs, const MemController *pMem, uint16_t argAddr)
{
	return	MCFetchValue16(pMem, argAddr + pRegs->Y);
}

//a,y
uint8_t	AbsoluteY8(const Registers *pRegs, const MemController *pMem, uint16_t argAddr)
{
	return	MCFetchValue(pMem, argAddr + pRegs->Y);
}

//(a)
uint16_t	AbsoluteIndirect(const MemController *pMem, uint16_t argAddr)
{
	uint16_t	pointer	=MCFetchValue16(pMem, argAddr);

	return	MCFetchValue16(pMem, pointer);
}

//zp
uint8_t	ZP(const MemController *pMem, uint8_t argAddr)
{
	return	MCFetchValueZP(pMem, argAddr);
}

//zp
uint16_t	ZP16(const MemController *pMem, uint8_t argAddr)
{
	return	MCFetchValueZP16(pMem, argAddr);
}

//(zp,x)
uint8_t	ZPIndirectX8(const Registers *pRegs, const MemController *pMem, uint8_t argAddr)
{
	uint16_t	pointer	=MCFetchValueZP16(pMem, argAddr + pRegs->X);

	return	MCFetchValue(pMem, pointer);
}

//(zp,x)
uint16_t	ZPIndirectX16(const Registers *pRegs, const MemController *pMem, uint8_t argAddr)
{
	uint16_t	pointer	=MCFetchValueZP16(pMem, argAddr + pRegs->X);

	return	MCFetchValue16(pMem, pointer);
}

//zp,x
uint8_t	ZPX(const Registers *pRegs, const MemController *pMem, uint8_t argAddr)
{
	return	MCFetchValueZP(pMem, argAddr + pRegs->X);
}

uint16_t	ZPX16(const Registers *pRegs, const MemController *pMem, uint8_t argAddr)
{
	return	MCFetchValueZP16(pMem, argAddr + pRegs->X);
}

//zp,y
uint8_t	ZPY(const Registers *pRegs, const MemController *pMem, uint8_t argAddr)
{
	return	MCFetchValueZP(pMem, argAddr + pRegs->Y);
}

//(zp)
uint8_t	ZPIndirect8(const MemController *pMem, uint8_t argAddr)
{
	uint16_t	pointer	=MCFetchValueZP16(pMem, argAddr);

	return	MCFetchValue(pMem, pointer);
}

//(zp)
uint8_t	ZPIndirect16(const MemController *pMem, uint8_t argAddr)
{
	uint16_t	pointer	=MCFetchValueZP16(pMem, argAddr);

	return	MCFetchValue16(pMem, pointer);
}

//(zp),y
uint8_t	ZPIndirectY8(const Registers *pRegs, const MemController *pMem, uint8_t argAddr)
{
	uint16_t	pointer	=MCFetchValueZP16(pMem, argAddr);

	return	MCFetchValue(pMem, pointer + pRegs->Y);
}

//(zp),y
uint8_t	ZPIndirectY16(const Registers *pRegs, const MemController *pMem, uint8_t argAddr)
{
	uint16_t	pointer	=MCFetchValueZP16(pMem, argAddr);

	return	MCFetchValue16(pMem, pointer + pRegs->Y);
}

