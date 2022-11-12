#include	<stdint.h>
#include	<stdbool.h>
#include	<stdlib.h>
#include	<time.h>
#include	<threads.h>
#include	<stdatomic.h>
#include	"Registers.h"
#include	"Memory.h"
#include	"OPCodeSizeTable.h"
#include	"OPCodeJumpTable.h"


#define	MAX_MEMORY_MODULES	8

typedef struct
{
	atomic_bool	mbOn;	//powered?

	Registers	mRegs;
	MemModule	mMem[MAX_MEMORY_MODULES];

	int			mNumModules;
}	CPU;


int	CPUThreadProc(void *context)
{
	CPU	cpu;

	//set up memory
	//hard code for now

	//standard c64 ram
	//contains zero page, stack, screen, etc
	cpu.mMem[0].mbWritable	=true;
	cpu.mMem[0].mAddrOfs	=0x0000;
	cpu.mMem[0].mpChunk		=calloc(65536, 1);	//64k of ram

	//ROM stuff
	cpu.mMem[1].mbWritable	=false;		//rom
	cpu.mMem[1].mAddrOfs	=0xF000;	//top 4k
	cpu.mMem[1].mpChunk		=calloc(4096, 1);

	cpu.mNumModules	=2;

	//boot!
	cpu.mRegs.S		=0x01FF;	//top of stack
	cpu.mRegs.PC	=0xFFFC;	//C64 first instruction spot

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
	while(cpu.mbOn)
	{
		clock_gettime(CLOCK_REALTIME, &start);

//		thrd_yield();
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

	return	thrd_success;
}


bool	CPUTick(CPU *cpu)
{
	bool	bFound	=false;

	//find the right memory chunk
	uint8_t	*pChunk	=NULL;

	//see if rom has the address
	for(int i=0;i < cpu->mNumModules;i++)
	{
		if(cpu->mMem[i].mbWritable)
		{
			continue;	//skip RAM for now
		}

		uint16_t	pc	=cpu->mRegs.PC;
		uint16_t	ofs	=cpu->mMem[i].mAddrOfs;

		if(cpu->mRegs.PC >= ofs
			&& cpu->mRegs.PC < (ofs + cpu->mMem[i].mSize))
		{
			pChunk	=&cpu->mMem[i].mpChunk[pc - ofs];
			bFound	=true;
			break;
		}
	}

	if(!bFound)
	{
		//see if ram has the address
		for(int i=0;i < cpu->mNumModules;i++)
		{
			if(!cpu->mMem[i].mbWritable)
			{
				continue;	//skip ROM
			}

			uint16_t	pc	=cpu->mRegs.PC;
			uint16_t	ofs	=cpu->mMem[i].mAddrOfs;

			if(cpu->mRegs.PC >= ofs
				&& cpu->mRegs.PC < (ofs + cpu->mMem[i].mSize))
			{
				pChunk	=&cpu->mMem[i].mpChunk[pc - ofs];
				bFound	=true;
				break;
			}
		}
	}

	if(!bFound)
	{
		printf("No memory at address %d\n", cpu->mRegs.PC);
		return	false;
	}

	//fetch instruction
	uint8_t	instruction	=*pChunk;

	//advance program counter
	cpu->mRegs.PC++;
	pChunk++;

	//see how many arguments are needed
	uint8_t	argBytes	=OPCArgSizeTable[instruction];

	uint8_t		byteArg;
	uint16_t	wordArg;

	if(argBytes == 1)
	{
		byteArg	=*pChunk;

		//stuff in word for jump table
		wordArg	=byteArg;

		//advance program counter
		cpu->mRegs.PC++;
		pChunk++;
	}
	else if(argBytes == 2)
	{
		wordArg	=*((uint16_t *)pChunk);

		//advance program counter
		cpu->mRegs.PC++;
		pChunk++;
	}
	else
	{
		assert(false);
	}
	
	OPCJumpTable[instruction](&cpu->mRegs, &cpu->mMem, wordArg);
}