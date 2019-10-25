all:
	rm -f lib.so main
	gcc -fPIC -shared -o lib.so lib.c
	gcc -o main main.c ./lib.so
