all: geraos geraA main clean

main: main.o
	gcc main.o -o main -L. -lstr

geraA: string_utils.o
	ar rcs libstr.a string_utils.o

geraos: string_utils.c
	gcc -c string_utils.c

clean:
	rm -rf *.o 

remove:
	rm -rf *.a main saida.txt