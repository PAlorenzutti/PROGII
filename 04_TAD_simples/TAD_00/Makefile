all: geraos geraA main clean

main: main.o
	gcc main.o -o main -L. -lponto -lm

geraA: ponto.o
	ar rcs libponto.a ponto.o

geraos: ponto.c
	gcc -c ponto.c

clean:
	rm -rf *.o 

remove:
	rm -rf *.a *.csv *.txt *.json Resultados main