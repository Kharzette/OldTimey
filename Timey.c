#include	<stdio.h>
#include	<time.h>
#include	<threads.h>
#include	<stdint.h>
#include	<stdbool.h>
#include	<stdatomic.h>
#include	"CPU.h"

#define	TICRATE		1000


//test main
int	main(void)
{
	thrd_t	threadID;
	int		res;
	bool	bActive	=true;	//just send cpu a bool for now

	res	=thrd_create(&threadID, CPUThreadProc, &bActive);

	if(res != thrd_success)
	{
		printf("Failed to create thread!\n");
		return	0;
	}

	printf("Thread launched with ID: %d\n", threadID);

    struct timespec ts;

	clock_gettime(CLOCK_REALTIME, &ts);

	printf("Time in seconds is %d\n\n", ts.tv_sec);

	printf("Press enter to stop CPU and exit...\n");

	int	ch	=getc(stdin);

	struct timespec	ts2;

	clock_gettime(CLOCK_REALTIME, &ts2);

	printf("Seconds elapsed on the main thread is %d\n\n", ts2.tv_sec - ts.tv_sec);

	//wait for exits
	int	result;
	thrd_join(threadID, &result);

	return	1;
}