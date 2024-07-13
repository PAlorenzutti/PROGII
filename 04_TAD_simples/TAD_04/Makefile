all: geraos geraA main clean

geraos: Respostas/Pedro/main.c Respostas/Pedro/aluno.c
	gcc -c Respostas/Pedro/main.c Respostas/Pedro/aluno.c

geraA: aluno.o
	ar rcs libaluno.a aluno.o

main: main.o
	gcc main.o -o main -L. -laluno

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