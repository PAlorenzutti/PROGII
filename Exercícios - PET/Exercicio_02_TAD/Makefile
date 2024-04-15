all: geraos gera main clean

geraos: main.c store.c product.c
	gcc -c main.c store.c product.c

gera: store.o product.o 
	ar rcs libloja.a store.o product.o

main:
	gcc main.o -o main -L. -lloja

clean:
	rm -rf *.o

remove:
	rm -rf *.o *.a *.txt main