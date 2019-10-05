#include <stdio.h>
#include <unistd.h>
#include "../common.h"

#define BUFSIZE 1024
static  char buf[BUFSIZE];
void main(int argc)
{
	FILE *fp=fopen("./tem.file","w+");
	if(fp==NULL)
		err_sys("fopen");
	
	if(argc==1)	/* line buffer */
		setvbuf(fp,buf,_IOLBF,BUFSIZE);
	else 		/* full buffer */
		setvbuf(fp,buf,_IOFBF,BUFSIZE);
	

	fputc('a',fp);
	fputc('a',fp);
	fputc('\n',fp);
	fputc('a',fp);
	fputc('a',fp);
	fputc('\n',fp);

	if(feof(fp))
		printf("reach end of file\n");
	if(ferror(fp))
		printf("error occur\n");
}
