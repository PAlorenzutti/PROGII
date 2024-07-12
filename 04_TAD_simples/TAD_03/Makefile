all: geraos geraA main clean

geraos: Respostas/Pedro/main.c Respostas/Pedro/locadora.c Respostas/Pedro/filme.c
	gcc -c Respostas/Pedro/main.c Respostas/Pedro/locadora.c Respostas/Pedro/filme.c

geraA: locadora.o filme.o
	ar rcs liblocadora.a locadora.o filme.o

main: main.o
	gcc main.o -o main -L. -llocadora

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

diff7:
	./main <Casos/7/entrada.txt >saida.txt
	diff saida.txt Casos/7/saida/saida.txt

diff8:
	./main <Casos/8/entrada.txt >saida.txt
	diff saida.txt Casos/8/saida/saida.txt

diff9:
	./main <Casos/9/entrada.txt >saida.txt
	diff saida.txt Casos/9/saida/saida.txt

diff10:
	./main <Casos/10/entrada.txt >saida.txt
	diff saida.txt Casos/10/saida/saida.txt

diff11:
	./main <Casos/11/entrada.txt >saida.txt
	diff saida.txt Casos/11/saida/saida.txt

diff12:
	./main <Casos/12/entrada.txt >saida.txt
	diff saida.txt Casos/12/saida/saida.txt

diff13:
	./main <Casos/13/entrada.txt >saida.txt
	diff saida.txt Casos/13/saida/saida.txt

diff14:
	./main <Casos/14/entrada.txt >saida.txt
	diff saida.txt Casos/14/saida/saida.txt

diff15:
	./main <Casos/15/entrada.txt >saida.txt
	diff saida.txt Casos/15/saida/saida.txt

diff16:
	./main <Casos/16/entrada.txt >saida.txt
	diff saida.txt Casos/16/saida/saida.txt

diff17:
	./main <Casos/17/entrada.txt >saida.txt
	diff saida.txt Casos/17/saida/saida.txt

diff18:
	./main <Casos/18/entrada.txt >saida.txt
	diff saida.txt Casos/18/saida/saida.txt

diff19:
	./main <Casos/19/entrada.txt >saida.txt
	diff saida.txt Casos/19/saida/saida.txt

diffAll:
	make diff1
	make diff2
	make diff3
	make diff4
	make diff5
	make diff6
	make diff7
	make diff8
	make diff9
	make diff10 
	make diff11 
	make diff12 
	make diff13
	make diff14
	make diff15
	make diff16
	make diff17
	make diff18
	make diff19