#ifndef __ADDRESSMODES_H__
#define	__ADDRESSMODES_H__
#include	<stdint.h>
#include	<stdbool.h>

typedef	struct	Registers;
typedef	struct	MemModule;

//a
uint8_t	Absolute8(const MemModule *pMem, uint16_t argAddr);

//a
uint16_t	Absolute16(const MemModule *pMem, uint16_t argAddr);

//(a,x)
uint16_t	AbsoluteIndirectX(const Registers *pRegs, const MemModule *pMem, uint16_t argAddr);

//a,x
void	AbsoluteX(const Registers *pRegs, const MemModule *pMem, uint16_t argAddr);

//a,y
void	AbsoluteY(const Registers *pRegs, const MemModule *pMem, uint16_t argAddr);

//(a)
uint16_t	AbsoluteIndirect(const MemModule *pMem, uint16_t argAddr);

//zp
uint8_t	ZP(const MemModule *pMem, uint8_t argAddr);

//zp
uint8_t	ZP16(const MemModule *pMem, uint8_t argAddr);

//(zp,x)
uint8_t	ZPIndirectX8(const Registers *pRegs, const MemModule *pMem, uint8_t argAddr);

//(zp,x)
uint16_t	ZPIndirectX16(const Registers *pRegs, const MemModule *pMem, uint8_t argAddr);

//zp,x
uint8_t	ZPX(const Registers *pRegs, const MemModule *pMem, uint8_t argAddr);

//zp,x
uint16_t	ZPX16(const Registers *pRegs, const MemModule *pMem, uint8_t argAddr);

//zp,y
uint8_t	ZPY(const Registers *pRegs, const MemModule *pMem, uint8_t argAddr);

//(zp)
uint8_t	ZPIndirect8(const MemModule *pMem, uint8_t argAddr);

//(zp)
uint8_t	ZPIndirect16(const MemModule *pMem, uint8_t argAddr);

//(zp),y
uint8_t	ZPIndirectY8(const Registers *pRegs, const MemModule *pMem, uint8_t argAddr);

//(zp),y
uint8_t	ZPIndirectY16(const Registers *pRegs, const MemModule *pMem, uint8_t argAddr);

#endif	//__ADDRESSMODES_H__