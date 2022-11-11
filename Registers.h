#ifndef __REGISTERS_H__
#define	__REGISTERS_H__
#include	<stdint.h>

typedef struct
{
	uint16_t	PC;	//program counter

	uint8_t		A;	//accumulator
	uint8_t		X;	//index X
	uint8_t		Y;	//index Y

	uint8_t		P;	//status register (flags)

	uint8_t		S;	//stack pointer
}	Registers;

//flags register bits
#define	PFLG_CARRY			(0x1 << 0)
#define	PFLG_ZERO			(0x1 << 1)
#define	PFLG_IRQB_DISABLE	(0x1 << 2)
#define	PFLG_DECIMAL_MODE	(0x1 << 3)
#define	PFLG_BRK_COMMAND	(0x1 << 4)
#define	PFLG_FLAG_UNUSED	(0x1 << 5)
#define	PFLG_OVERFLOW		(0x1 << 6)
#define	PFLG_NEGATIVE		(0x1 << 7)

#endif	//__REGISTERS_H__