all: geraos geraA main clean

main: main.o
	gcc main.o -o main -L. -lvetor -lm

geraA: vetor.o
	ar rcs libvetor.a vetor.o

geraos: vetor.c
	gcc -c vetor.c

clean:
	rm -rf *.o 

remove:
	rm -rf *.a *.csv *.txt *.json Resultados main