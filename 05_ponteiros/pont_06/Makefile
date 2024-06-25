all: geraos geraA main clean

main: main.o
	gcc main.o -o main -L. -ldata

geraA: data.o
	ar rcs libdata.a data.o

geraos: main.c data.c
	gcc -c main.c data.c

clean:
	rm -rf *.o 

remove:
	rm -rf *.a *.csv *.txt *.json Resultados main