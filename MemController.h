#ifndef	__MEMCONTROLLER_H__
#define	__MEMCONTROLLER_H__
#include	<stdint.h>
#include	<stdbool.h>


typedef struct	MemController_s	MemController;

//init
void	CreateMemController(MemController **ppMC);
void	InitModule(MemController *pMC, uint8_t index, uint8_t flags, uint16_t addrOffset, uint16_t size);
void	MCFreeAll(MemController **ppMC);

//control memory page stuff
uint8_t	GetActiveModule(const MemController *pMC);
bool	SetActiveModule(MemController *pMC, uint8_t mod);

//reads and writes
uint8_t		MCFetchValue(const MemController *pMC, uint16_t addr);
uint16_t	MCFetchValue16(const MemController *pMC, uint16_t addr);
uint8_t		MCFetchValueZP(const MemController *pMC, uint8_t addr);
uint16_t	MCFetchValueZP16(const MemController *pMC, uint8_t addr);
void		MCWriteZP(MemController *pMC, uint8_t argAddr, uint8_t val);
void		MCWriteAbsolute(MemController *pMC, uint16_t argAddr, uint8_t val);

#endif	//__MEMCONTROLLER_H__
