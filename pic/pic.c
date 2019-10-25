static int a;
extern int b;
extern void ext();

void bar()
{
	static int k=&a;
	a=5566;
	b=2;
}

void foo()
{
	bar();
	ext();
}
