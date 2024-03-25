all: geraos principal

principal: principal.o esfera_utils.o
	gcc principal.o esfera_utils.o -o principal -lm

geraos: principal.c esfera_utils.c
	gcc -c principal.c esfera_utils.c

clean:
	rm -rf *.o principal