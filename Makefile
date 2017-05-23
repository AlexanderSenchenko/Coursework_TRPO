##.PHOMY: all clean test

##all: bin/graph

##clean:
##	rm -rf build/src/*.o

##bin/graph: build/src/main.o build/src/functions.o src/graph.h
##	gcc -Wall -Werror build/src/main.o build/src/functions.o -o bin/graph

##build/src/main.o: src/main.c src/graph.h
##	gcc -Wall -Werror -c src/main.c -o build/src/main.o

##build/src/functions.o: src/functions.c src/graph.h
##	gcc -Wall -Werror -c src/functions.c -o build/src/functions.o
all:
	gcc -Wall -g -o main src/*.c
