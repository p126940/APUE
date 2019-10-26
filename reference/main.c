#include <cstdio>

void get(int a,int b,int &c)
{
	c=a+b;
}

int main()
{
	int res;

//	get(1,2,res);
	
	asm(
	"movl %0,8(%%esp)\n\t"
	"movl $2,4(%%esp)\n\t"
	"movl $1,(%%esp)\n\t"
	"call _Z3getiiRi\n\t" /* _Z3getiiRi is a decorated symbol of "get" function in assemble code */ 
	::"r" (&res));

	printf("%d\n",res);

	return 0;
}
