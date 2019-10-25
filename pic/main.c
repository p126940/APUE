#include <stdio.h>
#include <dlfcn.h>

#define SETUP_STACK		\
i=2;					\
while(++i < argc -1) {	\
	switch(argv[i][0]){	\
	case 'i':			\
		asm volatile("push %0"::	\
		"r" (atoi(&argv[i][1])) );	\
		esp+=4;                          \
		break;                           \
	case 'd':                            \
		atof(&argv[i][1]);               \
		asm volatile("subl $8,%esp\n"    \
		"fstpl (%esp)");                 \
		esp+=8;                          \
		break;                           \
	case 's':                            \
		asm volatile("push %0"::         \
		"r" (&argv[i][1]) );             \
		esp+=4;                          \
		break;                           \
	default:                             \
		printf("error argument type:%d  %c\n",argv[i][0],argv[i][0]); \
		goto exit_runso;                 \
	}                                    \
}

#define RESTORE_STACK \
	asm volatile("add %0, %%esp"::"r" (esp))
	
int main(int argc, char **argv)
{
		void * handle;
		char * error;
		int i;
		int esp=0;
		int (*func)(int,int);
		int ret;
		
		handle=dlopen(argv[1],RTLD_NOW);
		if(handle==0)
		{
			printf("can't find library:%s\n",argv[1]);
			return -1;
		}
		
		func=dlsym(handle,argv[2]);
		if((error=dlerror())!=NULL)
		{
			printf("find symbol %s error:%s\n",argv[2],error);
			goto exit_runso;
		}
		
		ret=func(atoi(argv[3]),atoi(argv[4]));
		printf("ret:%d\n",ret);
exit_runso:
	dlclose(handle);
}