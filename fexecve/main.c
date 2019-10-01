#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

#define EXEF "test"

void main()
{
	int fd;
	int ret;
	char *argv[]={EXEF,NULL};
	char *env[]={NULL};
	
#if 1	
	fd=open(EXEF,O_RDONLY);
	if(fd<0)
	{
		printf("open error\n");
	}

	getc(stdin);
	
	fexecve(fd,argv,env);
#else
	execv(EXEF,argv);
#endif
	printf("fexecve error:%d\n",errno);
}
