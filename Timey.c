#include	<stdio.h>
#include	<time.h>
#include	<threads.h>
#include	<stdint.h>
#include	<stdbool.h>
#include	<stdatomic.h>


typedef struct
{
	int			usTicRate;	//frequency in microseconds
	atomic_bool	mbActive;

	atomic_uint_fast64_t	mTics;
} TimeyThreadContext;


int	TimeyThreadProc(void *context)
{
	TimeyThreadContext	*ttc	=(TimeyThreadContext *)context;

	struct	timespec	start, end, tiny;
	uint64_t			usDiff, diff	=0;
	uint64_t			ticUps, ticTotal;

	//tiny interval for sleep
	tiny.tv_nsec	=100;
	tiny.tv_sec		=0;

	ticUps	=ticTotal	=0;
	while(ttc->mbActive)
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
		if(usDiff > ttc->usTicRate)
		{
			//how many tics elapsed?
			int	ticsUp	=(usDiff / ttc->usTicRate);

			//tracking jitteryness
			ticUps++;
			ticTotal	+=ticsUp;

			//increment tics
			ttc->mTics	+=ticsUp;

			//reduce diff by tics elapsed converted to nanoseconds
			diff	-=(ticsUp * ttc->usTicRate * 1000);
		}
	}

	double	ratio	=(double)ticTotal / (double)ticUps;

	printf("Exiting thread with ratio: %f\n", ratio);

	return	thrd_success;
}


#define	NTHREADS	10
#define	TICRATE		1000

int	main(void)
{
	TimeyThreadContext	ttc[NTHREADS];
	thrd_t				threadID[NTHREADS];
	int					res[NTHREADS];

	for(int i=0;i < NTHREADS;i++)
	{
		ttc[i].mbActive		=true;
		ttc[i].usTicRate	=TICRATE;	//microseconds
		ttc[i].mTics		=0;

		res[i]	=thrd_create(&threadID[i], TimeyThreadProc, &ttc[i]);

		if(res[i] != thrd_success)
		{
			printf("Failed to create thread!\n");
			return	0;
		}

		printf("Thread launched with ID: %d\n", threadID[i]);
	}

    struct timespec ts;

	clock_gettime(CLOCK_REALTIME, &ts);

	printf("Time in seconds is %d\n\n", ts.tv_sec);

	printf("Press enter to stop timer and calculate accuracy...\n");

	uint64_t	tics[NTHREADS];

	int	ch	=getc(stdin);

	for(int i=0;i < NTHREADS;i++)
	{
		tics[i]			=ttc[i].mTics;
		ttc[i].mbActive	=false;
	}

	struct timespec	ts2;

	clock_gettime(CLOCK_REALTIME, &ts2);

	printf("Seconds elapsed on the main thread is %d\n\n", ts2.tv_sec - ts.tv_sec);

	for(int i=0;i < NTHREADS;i++)
	{
		printf("Thread %d tics elapsed: %ld, seconds: %ld\n", threadID[i], tics[i], (tics[i] * ttc[i].usTicRate) / 1000000);
	}

	//wait for exits
	for(int i=0;i < NTHREADS;i++)
	{
		int	result;
		thrd_join(threadID[i], &result);
	}

	return	1;
}