#include <stdio.h>
#include <signal.h>
#include "../common.h"
#include <unistd.h>

#define MAXLINE 100
#define BZ 10

int fd[2];

void handle()
{
	//write(fd[1],"a\n",2);	
	fputs("a\n",stdout);
}

void main()
{
	int ret;
	char line[MAXLINE];
	char buf[BZ];

	if(pipe(fd))
		err_sys("pipe");		
	
	signal(SIGURG,handle);

	ret=fork();

	int count=0;

	if(ret==0)
	{
		dup2(fd[0],STDIN_FILENO);
		while(1)
		{
			fgets(line,MAXLINE,stdin);
			//printf("%3d:%s",++count,line);
		}
	}
	dup2(fd[1],STDOUT_FILENO);
	setvbuf(stdout,buf,_IOFBF,BZ);
	while(1);
}
