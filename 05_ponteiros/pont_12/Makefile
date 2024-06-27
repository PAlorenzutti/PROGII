all: geraos geraA main clean

main: main.o
	gcc main.o -o main -L. -lvetor

geraA: vetor.o
	ar rcs libvetor.a vetor.o

geraos: Respostas/Pedro/main.c Respostas/Pedro/vetor.c
	gcc -c Respostas/Pedro/main.c Respostas/Pedro/vetor.c

clean:
	rm -rf *.o 

remove:
	rm -rf *.a *.csv *.txt *.json Resultados main