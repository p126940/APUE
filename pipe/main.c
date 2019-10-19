#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

#define MAXS 100

void handle()
{
	printf("get SIGPIPE\n");
}

void main()
{
	int fd[2];
	int ret;
	char buf[MAXS];

	signal(SIGPIPE,handle);	

	pipe(fd);

	ret=fork();
	if(ret==0)
	{
		int num;
		close(fd[1]);
		while(num=read(fd[0],buf,MAXS)>0)
		{
			if(strcmp(buf,"abc\n")==0)
			{
				close(fd[0]);
			}
			printf("child: %s",buf);	
		}
		exit(0);
	}

//	close(fd[0]);

	while(fgets(buf,MAXS,stdin))
	{
		write(fd[1],buf,strlen(buf)+1);	
	}

	exit(0);
}
