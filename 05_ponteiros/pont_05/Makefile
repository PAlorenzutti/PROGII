all: geraos main

main: main.o esfera_utils.o
	gcc main.o esfera_utils.o -o main -lm

geraos: main.c esfera_utils.c
	gcc -c main.c esfera_utils.c

clean:
	rm -rf *.o main