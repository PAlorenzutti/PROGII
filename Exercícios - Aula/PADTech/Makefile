all: geraos gera main clean

geraos: constantes.c data.c paciente.c lesao.c utils.c
	gcc -c main.c constantes.c data.c paciente.c lesao.c utils.c

gera: constantes.o data.o paciente.o lesao.o utils.o
	ar rcs libpad.a constantes.o data.o paciente.o lesao.o utils.o

main:
	gcc main.o -o main -L. -lpad

clean:
	rm -rf *.o

cleanAll:
	rm -rf *.a main