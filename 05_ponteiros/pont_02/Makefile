all: geraos geraA main clean

main: main.o
	gcc main.o -o main -L. -lutils -lm

geraA: utils.o
	ar rcs libutils.a utils.o

geraos: utils.c
	gcc -c utils.c

clean:
	rm -rf *.o 

remove:
	rm -rf *.a *.csv *.txt *.json Resultados main