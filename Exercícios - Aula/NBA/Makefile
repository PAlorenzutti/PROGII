all: geraos gera main clean

geraos: main.c franquia.c partida.c constantes.c
	gcc -c main.c franquia.c partida.c constantes.c

gera: franquia.o partida.o 
	ar rcs libnba.a franquia.o partida.o constantes.o

main:
	gcc main.o -o main -L. -lnba

clean:
	rm -rf *.o

cleanAll:
	rm -rf *.o *.a main