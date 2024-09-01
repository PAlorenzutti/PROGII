all: compila

compila:
	gcc main.c -o main

teste1:
	./main <entrada1.txt >saida.txt

teste2:
	make teste1
	./main <entrada2.txt >saida.txt

remove:
	rm -rf main dados.bin saida.txt
	clear

valgrind:
	valgrind ./main <entrada2.txt