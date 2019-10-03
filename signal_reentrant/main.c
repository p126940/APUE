#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../common.h"

pthread_mutexattr_t attr;
pthread_mutex_t mutex;

void handler()
{
	printf("in handler  , pid:%d  tid:0x%x\n",getpid(),pthread_self());
	pthread_mutex_lock(&mutex);
	printf("signal handler get lock\n");
}

void t_handler()
{
	printf("in t_handler, pid:%d  tid:0x%x\n",getpid(),pthread_self());
	pthread_mutex_lock(&mutex);
	printf("t_handler get lock\n");
}

void thread()
{
	signal(SIGQUIT,t_handler);
	printf("in thread, pid:%d  tid:0x%x\n",getpid(),pthread_self());
	pthread_mutex_lock(&mutex);
	printf("thread get lock\n");
	while(1);
}

void main()
{
	int ret;
	pthread_t pid;

	signal(SIGINT,handler);

	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&mutex,&attr);
	
	printf("in main, pid:%d  tid:0x%x\n",getpid(),pthread_self());

	pthread_mutex_lock(&mutex);
	printf("first get lock\n");


	pthread_mutex_lock(&mutex);
	printf("second get lock\n");

	pthread_create(&pid,NULL,thread,NULL);

	while(1);
}

