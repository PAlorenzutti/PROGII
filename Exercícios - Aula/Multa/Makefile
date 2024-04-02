all: geraos gera main clean run

main: main.o
	gcc main.o -o main -L. -lmulta -lm

gera: multa.o
	ar rcs libmulta.a multa.o

geraos: multa.c
	gcc -c multa.c

run: main
	./main

clean: 
	rm -rf *.o