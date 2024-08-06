all: compiler

compiler:
	gcc main.c -o main -lm

teste:
	./main <entrada.txt >saida.txt

remove:
	rm -rf main saida.txt

diff:
	diff saida.txt entrada.txt