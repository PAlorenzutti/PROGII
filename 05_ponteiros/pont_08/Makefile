all: geraos geraA main clean

main: main.o
	gcc main.o -o main -L. -ltDepartamento

geraA: tDepartamento.o
	ar rcs libtDepartamento.a tDepartamento.o

geraos: main.c tDepartamento.c
	gcc -c main.c tDepartamento.c

clean:
	rm -rf *.o 

remove:
	rm -rf *.a *.csv *.txt *.json Resultados main