all: geraos geraA main clean

main: main.o
	gcc main.o -o main -L. -lcalculadora

geraA: calculadora.o
	ar rcs libcalculadora.a calculadora.o

geraos: Respostas/Pedro/main.c Respostas/Pedro/calculadora.c
	gcc -c Respostas/Pedro/main.c Respostas/Pedro/calculadora.c

clean:
	rm -rf *.o 

remove:
	rm -rf *.a *.csv *.txt *.json Resultados main