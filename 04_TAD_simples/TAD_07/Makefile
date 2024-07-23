all: geraos geraA main clean

geraos: Respostas/Pedro/main.c Respostas/Pedro/data.c
	gcc -c Respostas/Pedro/main.c Respostas/Pedro/data.c

geraA: data.o
	ar rcs libdata.a data.o

main: main.o
	gcc main.o -o main -L. -ldata

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

diff4:
	./main <Casos/4/entrada.txt >saida.txt
	diff saida.txt Casos/4/saida/saida.txt

diff5:
	./main <Casos/5/entrada.txt >saida.txt
	diff saida.txt Casos/5/saida/saida.txt

diff6:
	./main <Casos/6/entrada.txt >saida.txt
	diff saida.txt Casos/6/saida/saida.txt

diffAll:
	make diff1
	make diff2
	make diff3
	make diff4
	make diff5
	make diff6