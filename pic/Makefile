all:
	rm *.so -f
	gcc -o a.so a.c -fPIC -shared
	gcc -o b.so b.c a.so -fPIC -shared
	gcc -o c.so c.c a.so -fPIC -shared
	gcc -g -o main main.c /lib/libdl.so.2
