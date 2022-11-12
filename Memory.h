#ifndef __MEMORY_H__
#define	__MEMORY_H__
#include	<stdint.h>

//a physical hardware chunk of memory
//ram or rom
typedef struct
{
	bool		mbWritable;	//ram or rom?
	uint16_t	mAddrOfs;	//location on the bus of byte 0
	uint8_t		*mpChunk;	//actual memory
	uint16_t	mSize;		//size 
}	MemModule;

uint8_t		FetchValueZP(const MemModule *pMem, uint8_t addr);
uint16_t	FetchValueZP16(const MemModule *pMem, uint8_t addr);
uint8_t		FetchValue(const MemModule *pMem, uint16_t addr);
uint16_t	FetchValue16(const MemModule *pMem, uint16_t addr);

void	WriteZP(MemModule *pMem, uint8_t addr, uint8_t value);
void	WriteAbsolute(MemModule *pMem, uint16_t addr, uint8_t value);

#endif	//__MEMORY_H__