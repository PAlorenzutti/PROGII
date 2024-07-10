all: geraos geraA main clean

geraos: Respostas/Pedro/main.c Respostas/Pedro/string_utils.c 
	gcc -c Respostas/Pedro/main.c Respostas/Pedro/string_utils.c

geraA: string_utils.o 
	ar rcs libstring_utils.a string_utils.o 

main: main.o
	gcc main.o -o main -L. -lstring_utils

clean:
	rm -rf *.o 

remove:
	rm -rf *.a *.csv *.txt *.json Resultados main