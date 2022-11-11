#include	<stdint.h>
#include	<stdbool.h>
#include	<assert.h>
#include	"Memory.h"


uint8_t	FetchValueZP(const MemModule *pMem, uint8_t addr)
{
	assert(pMem->mAddrOfs == 0);
	assert(pMem->mSize < 0xFF);

	if(pMem->mAddrOfs != 0)
	{
		return	0;
	}
	if(pMem->mSize < 0xFF)
	{
		return	0;
	}

	return	pMem->mpChunk[addr];
}

//usually a pointer
uint16_t	FetchValueZP16(const MemModule *pMem, uint8_t addr)
{
	assert(pMem->mAddrOfs == 0);
	assert(pMem->mSize < 0xFF);

	if(pMem->mAddrOfs != 0)
	{
		return	0;
	}
	if(pMem->mSize < 0xFF)
	{
		return	0;
	}

	return	(*((uint16_t *)(pMem->mpChunk + addr)));
}

uint8_t	FetchValue(const MemModule *pMem, uint16_t addr)
{
	int	chunkAddr	=addr - pMem->mAddrOfs;

	assert(chunkAddr >= 0 && chunkAddr < pMem->mSize);

	if(chunkAddr < 0 || chunkAddr > pMem->mSize)
	{
		return	0;
	}

	return	pMem->mpChunk[chunkAddr];
}

uint16_t	FetchValue16(const MemModule *pMem, uint16_t addr)
{
	int	chunkAddr	=addr - pMem->mAddrOfs;

	assert(chunkAddr >= 0 && chunkAddr < pMem->mSize);

	if(chunkAddr < 0 || chunkAddr > pMem->mSize)
	{
		return	0;
	}

	return	(*((uint16_t *)(pMem->mpChunk + addr)));
}

