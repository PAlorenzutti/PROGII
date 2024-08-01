all: geraos geraA main clean

geraos: Respostas/Pedro/main.c Respostas/Pedro/pessoa.c Respostas/Pedro/data.c
	gcc -c Respostas/Pedro/main.c Respostas/Pedro/pessoa.c Respostas/Pedro/data.c

geraA: pessoa.o data.o
	ar rcs libpessoa.a pessoa.o data.o

main: main.o
	gcc main.o -o main -L. -lpessoa

clean:
	rm -rf *.o 

remove:
	rm -rf *.a main

teste:
	./main <teste.txt >saida.txt
	