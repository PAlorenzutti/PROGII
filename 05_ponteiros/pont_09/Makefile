all: geraos geraA main clean

main: main.o
	gcc main.o -o main -L. -lpessoa

geraA: pessoa.o
	ar rcs libpessoa.a pessoa.o

geraos: Respostas/Pedro/main.c Respostas/Pedro/pessoa.c
	gcc -c Respostas/Pedro/main.c Respostas/Pedro/pessoa.c

clean:
	rm -rf *.o 

remove:
	rm -rf *.a *.csv *.txt *.json Resultados main