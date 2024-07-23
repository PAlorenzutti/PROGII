all: geraos geraA main clean

geraos: Respostas/Pedro/main.c Respostas/Pedro/rolagem.c
	gcc -c Respostas/Pedro/main.c Respostas/Pedro/rolagem.c

geraA: rolagem.o
	ar rcs librolagem.a rolagem.o

main: main.o
	gcc main.o -o main -L. -lrolagem

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

diffAll:
	make diff1
	make diff2