all: geraos geraA main clean

geraos: Respostas/Pedro/main.c Respostas/Pedro/loja.c Respostas/Pedro/vendedor.c
	gcc -c Respostas/Pedro/main.c Respostas/Pedro/loja.c Respostas/Pedro/vendedor.c

geraA: loja.o vendedor.o
	ar rcs libloja.a loja.o vendedor.o

main: main.o
	gcc main.o -o main -L. -lloja

clean:
	rm -rf *.o 

remove:
	rm -rf *.a *.csv *.txt *.json Resultados main