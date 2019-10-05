#include <errno.h>
#include <string.h>

void err_sys(char *s)
{
	printf("%s , errstr:%s\n",s,strerror(errno));
	exit(0);
}

void err_exit(int err,char *s)
{
	printf("errno:%d ,caused by %s\n",err,s);
}
