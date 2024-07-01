all: geraos geraA main clean

geraos: Respostas/Pedro/main.c Respostas/Pedro/locadora.c Respostas/Pedro/filme.c
	gcc -c Respostas/Pedro/main.c Respostas/Pedro/locadora.c Respostas/Pedro/filme.c

geraA: locadora.o filme.o
	ar rcs liblocadora.a locadora.o filme.o

main: main.o
	gcc main.o -o main -L. -llocadora

clean:
	rm -rf *.o 

remove:
	rm -rf *.a *.csv *.txt *.json Resultados main