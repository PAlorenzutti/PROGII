all: geraos geraA main clean

geraos: Respostas/Pedro/main.c Respostas/Pedro/tela.c Respostas/Pedro/botao.c
	gcc -c Respostas/Pedro/main.c Respostas/Pedro/tela.c Respostas/Pedro/botao.c

geraA: tela.o botao.o
	ar rcs libtela.a tela.o botao.o

main: main.o
	gcc main.o -o main -L. -ltela

clean:
	rm -rf *.o 

remove:
	rm -rf *.a *.csv *.txt *.json Resultados main

diff1:
	./main <Casos/1/entrada.txt >saida.txt
	diff saida.txt Casos/1/saida/saida.txt

diff2:
	./main <Casos/2/entrada.txt >saida.txt
	diff saida.txt Casos/2/saida/saida.txt

diff3:
	./main <Casos/3/entrada.txt >saida.txt
	diff saida.txt Casos/3/saida/saida.txt

diffAll:
	make diff1
	make diff2
	make diff3

correcao: Respostas/Pedro/main.c Respostas/Pedro/tela.c Respostas/Pedro/botao.c
	mkdir -p Gabarito-obj
	gcc -c Respostas/Pedro/main.c -o Gabarito-obj/main.o
	gcc -c Respostas/Pedro/tela.c -o Gabarito-obj/tela.o
	gcc -c Respostas/Pedro/botao.c -o Gabarito-obj/botao.o
