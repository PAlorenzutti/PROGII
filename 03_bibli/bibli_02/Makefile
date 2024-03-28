all: geraos geraA main clean

main: main.o
	gcc main.o -o main -L. -lmatrix_utils

geraA: matrix_utils.o
	ar rcs libmatrix_utils.a matrix_utils.o

geraos: matrix_utils.c
	gcc -c matrix_utils.c

clean:
	rm -rf *.o 