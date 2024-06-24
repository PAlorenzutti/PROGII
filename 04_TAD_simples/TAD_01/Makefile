all: geraos geraA main clean

geraos: jogo.c tabuleiro.c jogador.c jogada.c main.c
	gcc -c main.c jogo.c tabuleiro.c jogador.c jogada.c

geraA: jogo.o tabuleiro.o jogador.o jogada.o
	ar rcs libvelha.a jogo.o tabuleiro.o jogador.o jogada.o

main: main.o
	gcc main.o -o main -L. -lvelha

clean:
	rm -rf *.o 

remove:
	rm -rf *.a *.csv *.txt *.json Resultados main