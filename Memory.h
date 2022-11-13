#ifndef __MEMORY_H__
#define	__MEMORY_H__
#include	<stdint.h>


//memory attribute flags
#define	MM_WRITABLE		(0x1 << 0)	//ram or rom?
#define	MM_STACK		(0x1 << 1)	//stack memory?
#define	MM_SYSTEM		(0x1 << 2)	//System rom routines?  Only one of these
#define	MM_DEVICEREAD	(0x1 << 3)	//Readable by external devices
#define	MM_DEVICEWRITE	(0x1 << 4)	//Writable by external devices
#define	MM_REMOVABLE	(0x1 << 5)	//might plug / unplug

//a physical hardware chunk of memory
//ram or rom
typedef struct
{
	uint8_t		mFlags;		//combinations of MM flags above
	uint16_t	mAddrOfs;	//location on the bus of byte 0
	uint8_t		*mpChunk;	//actual memory
	uint16_t	mSize;		//size  (up to 64k)
}	MemModule;

uint8_t		FetchValueZP(const MemModule *pMem, uint8_t addr);
uint16_t	FetchValueZP16(const MemModule *pMem, uint8_t addr);
uint8_t		FetchValue(const MemModule *pMem, uint16_t addr);
uint16_t	FetchValue16(const MemModule *pMem, uint16_t addr);

void	WriteZP(MemModule *pMem, uint8_t addr, uint8_t value);
void	WriteAbsolute(MemModule *pMem, uint16_t addr, uint8_t value);

#endif	//__MEMORY_H__