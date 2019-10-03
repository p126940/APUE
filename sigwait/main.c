#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <pthread.h>


void main()
{
	sigset_t mask;
	int signo;

	sigemptyset(&mask);
	sigaddset(&mask,SIGINT);
	pthread_sigmask(SIG_BLOCK,&mask,NULL);
	
	while(1)
	{
		sigwait(&mask,&signo);
		switch(signo)
		{
			case SIGINT:
				printf("catch SIGINT\n");
				break;
			default:
				printf("something others\n");
				break;
		}
	}
}
