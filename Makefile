all:
	gcc -Wall -o main src/main.c
	dot -Tpng example1.gv -oexample1.png
