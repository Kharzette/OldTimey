#ifndef __ADDRESSMODES_H__
#define	__ADDRESSMODES_H__
#include	<stdint.h>
#include	<stdbool.h>
#include	"MemController.h"


//a
uint8_t	Absolute8(const MemController *pMem, uint16_t argAddr);

//a
uint16_t	Absolute16(const MemController *pMem, uint16_t argAddr);

//(a,x)
uint16_t	AbsoluteIndirectX(const Registers *pRegs, const MemController *pMem, uint16_t argAddr);

//a,x
uint8_t	AbsoluteX8(const Registers *pRegs, const MemController *pMem, uint16_t argAddr);

//a,x
uint16_t	AbsoluteX16(const Registers *pRegs, const MemController *pMem, uint16_t argAddr);

//a,y
uint8_t	AbsoluteY8(const Registers *pRegs, const MemController *pMem, uint16_t argAddr);

//a,y
uint16_t	AbsoluteY16(const Registers *pRegs, const MemController *pMem, uint16_t argAddr);

//(a)
uint16_t	AbsoluteIndirect(const MemController *pMem, uint16_t argAddr);

//zp
uint8_t	ZP(const MemController *pMem, uint8_t argAddr);

//zp
uint8_t	ZP16(const MemController *pMem, uint8_t argAddr);

//(zp,x)
uint8_t	ZPIndirectX8(const Registers *pRegs, const MemController *pMem, uint8_t argAddr);

//(zp,x)
uint16_t	ZPIndirectX16(const Registers *pRegs, const MemController *pMem, uint8_t argAddr);

//zp,x
uint8_t	ZPX(const Registers *pRegs, const MemController *pMem, uint8_t argAddr);

//zp,x
uint16_t	ZPX16(const Registers *pRegs, const MemController *pMem, uint8_t argAddr);

//zp,y
uint8_t	ZPY(const Registers *pRegs, const MemController *pMem, uint8_t argAddr);

//(zp)
uint8_t	ZPIndirect8(const MemController *pMem, uint8_t argAddr);

//(zp)
uint8_t	ZPIndirect16(const MemController *pMem, uint8_t argAddr);

//(zp),y
uint8_t	ZPIndirectY8(const Registers *pRegs, const MemController *pMem, uint8_t argAddr);

//(zp),y
uint8_t	ZPIndirectY16(const Registers *pRegs, const MemController *pMem, uint8_t argAddr);

#endif	//__ADDRESSMODES_H__