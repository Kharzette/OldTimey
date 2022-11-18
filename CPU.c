#include	<stdint.h>
#include	<stdbool.h>
#include	<stdlib.h>
#include	<assert.h>
#include	<stdio.h>
#include	<time.h>
#include	<threads.h>
#include	<stdatomic.h>
#include	"Registers.h"
#include	"MemController.h"
#include	"Memory.h"
#include	"OPCodeSizeTable.h"
#include	"OPCodeJumpTable.h"


#define	MAX_MEMORY_MODULES	8

typedef struct
{
	atomic_bool	mbOn;	//powered?

	Registers		mRegs;
	MemController	*mpMC;

}	CPU;


bool	CPUTick(CPU *cpu)
{
	uint8_t	curModule	=GetActiveModule(cpu->mpMC);

	//fetch instruction
	uint8_t	instruction	=MCFetchValue(cpu->mpMC, cpu->mRegs.PC);

	//advance program counter
	cpu->mRegs.PC++;
	
	//see how many arguments are needed
	uint8_t	argBytes	=OPCArgSizeTable[instruction];

	uint8_t		byteArg;
	uint16_t	wordArg;

	if(argBytes == 1)
	{
		byteArg	=MCFetchValue(cpu->mpMC, cpu->mRegs.PC);

		//stuff in word for jump table
		wordArg	=byteArg;

		//advance program counter
		cpu->mRegs.PC++;
	}
	else if(argBytes == 2)
	{
		wordArg	=MCFetchValue16(cpu->mpMC, cpu->mRegs.PC);

		//advance program counter
		cpu->mRegs.PC++;
	}
	else
	{
		assert(false);
	}

	OPCJumpTable[instruction](&cpu->mRegs, cpu->mpMC, wordArg);
}


int	CPUThreadProc(void *context)
{
	CPU	cpu;

	//context is just an active bool for now
	bool	*bActive	=(bool *)context;

	//set up memory
	CreateMemController(&cpu.mpMC);

	//Main sytem mem
	InitModule(cpu.mpMC, 0, MM_SYSTEM | MM_WRITABLE, 0, 0xFFFF);

	//Stack
	InitModule(cpu.mpMC, 1, MM_STACK | MM_WRITABLE, 0, 0xFFFF);

	//vid screen mem
	InitModule(cpu.mpMC, 2, MM_DEVICEREAD | MM_WRITABLE, 0, 0xFFFF);

	//need to load a program

	//boot!
	cpu.mRegs.S		=0xFFFF;	//top of stack
	cpu.mRegs.PC	=0xFFFC;	//6502 first instruction spot

	//clock speed
	int	usTicRate	=1000;	//tic per millisecond for now

	//start clock
	struct	timespec	start, end, tiny;
	uint64_t			usDiff, diff	=0;
	uint64_t			ticUps, ticTotal;

	//tiny interval for sleep
	tiny.tv_nsec	=100;
	tiny.tv_sec		=0;

	ticUps	=ticTotal	=0;
	while(cpu.mbOn && *bActive)
	{
		clock_gettime(CLOCK_REALTIME, &start);

		thrd_sleep(&tiny, NULL);

		clock_gettime(CLOCK_REALTIME, &end);

		if(end.tv_nsec <= start.tv_nsec)
		{
			continue;
		}

		//time elapsed in loop so far in nanoseconds
		diff	+=(end.tv_nsec - start.tv_nsec);

		//convert to microseconds
		usDiff	=(diff / 1000);

		//more microseconds elapsed than ticrate?
		if(usDiff > usTicRate)
		{
			//how many tics elapsed?
			int	ticsUp	=(usDiff / usTicRate);

			//tracking jitteryness
			ticUps++;
			ticTotal	+=ticsUp;

			//Tick!
			CPUTick(&cpu);			

			//reduce diff by tics elapsed converted to nanoseconds
			diff	-=(ticsUp * usTicRate * 1000);
		}
	}

	double	ratio	=(double)ticTotal / (double)ticUps;

	printf("Exiting thread with ratio: %f\n", ratio);

	MCFreeAll(&cpu.mpMC);
	
	//by Crom, I need to test another with SourceTree

	return	thrd_success;
}