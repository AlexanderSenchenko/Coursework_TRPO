all:
	gcc -Wall -o main src/*.c
	dot -Tpng example1.gv -oexample1.png
