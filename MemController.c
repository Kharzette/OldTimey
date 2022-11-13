#include	<stdint.h>
#include	<stdbool.h>
#include	<stdatomic.h>
#include	<stdlib.h>
#include	<string.h>
#include	<assert.h>
#include	"Memory.h"


#define	NUM_MEM_SOCKETS	8

typedef struct
{
	//chips in the system, up to 64k each
	MemModule	mModules[NUM_MEM_SOCKETS];

	//true when being used by a device
	atomic_bool	mDeviceBusy[NUM_MEM_SOCKETS];

	uint8_t	mCPUModule;	//which module is active for the CPU?
	uint8_t	mStack;		//which module has the stack?

}	MemController;


void	MCFreeAll(MemController **ppMC)
{
	MemController	*pMC	=*ppMC;

	for(int i=0;i < NUM_MEM_SOCKETS;i++)
	{
		free(pMC->mModules[i].mpChunk);
	}

	free(pMC);

	*ppMC	=NULL;
}


void	CreateMemController(MemController **ppMC)
{
	*ppMC	=calloc(sizeof(MemController), 1);

	MemController	*pMC	=*ppMC;

	for(int i=0;i < NUM_MEM_SOCKETS;i++)
	{
		memset(&pMC->mModules[i], 0, sizeof(MemModule));

		pMC->mDeviceBusy[i]	=false;
	}

	pMC->mCPUModule	=0;
	pMC->mStack		=0;
}

void	InitModule(MemController *pMC, uint8_t index, uint8_t flags, uint16_t addrOffset, uint16_t size)
{
	assert(index < NUM_MEM_SOCKETS);

	pMC->mModules[index].mFlags		=flags;
	pMC->mModules[index].mAddrOfs	=addrOffset;
	pMC->mModules[index].mSize		=size;

	pMC->mModules[index].mpChunk	=calloc(size, 1);

	pMC->mDeviceBusy[index]	=false;

	//assuming for now the caller knows what they are doing
	//but eventually want to error check all this
	if(flags & MM_STACK)
	{
		pMC->mStack	=index;
	}
}


uint8_t	GetActiveModule(const MemController *pMC)
{
	return	pMC->mCPUModule;
}


bool	SetActiveModule(MemController *pMC, uint8_t mod)
{
	if(pMC->mDeviceBusy[mod])
	{
		return	false;
	}

	pMC->mCPUModule	=mod;
}


uint8_t	MCFetchValue(const MemController *pMC, uint16_t addr)
{
	return	FetchValue(&pMC->mModules[pMC->mCPUModule], addr);
}

uint16_t	MCFetchValue16(const MemController *pMC, uint16_t addr)
{
	return	FetchValue16(&pMC->mModules[pMC->mCPUModule], addr);
}

uint8_t	MCFetchValueZP(const MemController *pMC, uint8_t addr)
{
	return	FetchValueZP(&pMC->mModules[pMC->mCPUModule], addr);
}

uint8_t	MCFetchValueZP16(const MemController *pMC, uint8_t addr)
{
	return	FetchValueZP16(&pMC->mModules[pMC->mCPUModule], addr);
}

void	MCWriteZP(MemController *pMC, uint8_t argAddr, uint8_t val)
{
	WriteZP(&pMC->mModules[pMC->mCPUModule], argAddr, val);
}

void	MCWriteAbsolute(MemController *pMC, uint16_t argAddr, uint8_t val)
{
	WriteAbsolute(&pMC->mModules[pMC->mCPUModule], argAddr, val);
}
