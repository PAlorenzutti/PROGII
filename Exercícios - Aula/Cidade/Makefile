all: geraos geraA main clean

geraos: Respostas/Pedro/*.c
	gcc -c Respostas/Pedro/*.c

geraA: cidade.o defesa.o missil.o
	ar rcs libcidade.a cidade.o defesa.o missil.o

main: main.o 
	gcc main.o -o main -L. -lcidade

clean:
	rm -rf *.o 

remove:
	rm -rf *.a *.csv *.txt *.json Resultados main

teste2:
	./main <Casos/2/entrada.txt >saida.txt

diff2:
	./main <Casos/2/entrada.txt >saida.txt
	diff saida.txt Casos/2/saida.txt

diff3:
	./main <Casos/3/entrada.txt >saida.txt
	diff saida.txt Casos/3/saida.txt

diffAll:
	make diff2
	make diff3