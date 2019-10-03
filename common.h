void err_sys(char *s)
{
	printf(s);
	printf(" error\n");
	exit(0);
}

void err_exit(int err,char *s)
{
	printf("errno:%d ,caused by %s\n",err,s);
}
