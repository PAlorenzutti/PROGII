all: geraos geraA main clean

geraos: Respostas/Pedro/main.c Respostas/Pedro/eleicao.c Respostas/Pedro/candidato.c Respostas/Pedro/eleitor.c
	gcc -c Respostas/Pedro/main.c Respostas/Pedro/eleicao.c Respostas/Pedro/candidato.c Respostas/Pedro/eleitor.c

geraA: eleicao.o candidato.o eleitor.o
	ar rcs libeleicao.a eleicao.o candidato.o eleitor.o

main: main.o
	gcc main.o -o main -L. -leleicao

clean:
	rm -rf *.o 

remove:
	rm -rf *.a *.csv *.txt *.json Resultados main