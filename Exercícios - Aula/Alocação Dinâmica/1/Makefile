all: geraos main clean

geraos: main.c
	gcc -c main.c

main: main.o
	gcc main.o -o main -lm

clean:
	rm -rf *.o 

remove:
	rm -rf main

teste:
	./main <teste.txt >saida.txt
