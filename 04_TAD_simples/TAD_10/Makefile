all: geraos geraA main clean

geraos: Respostas/Pedro/main.c Respostas/Pedro/livro.c Respostas/Pedro/biblioteca.c
	gcc -c Respostas/Pedro/main.c Respostas/Pedro/livro.c Respostas/Pedro/biblioteca.c

geraA: livro.o biblioteca.o
	ar rcs liblivro.a livro.o biblioteca.o

main: main.o
	gcc main.o -o main -L. -llivro

clean:
	rm -rf *.o 

remove:
	rm -rf *.a *.csv *.txt *.json Resultados main