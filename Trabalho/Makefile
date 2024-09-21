all: compila

compila:
	gcc Respostas/Pedro/*.c -o main

#teste1 (teste geral reduzido)

teste1:
	./main <Entradas/1/entrada.txt >saida.txt

valgrind1:
	valgrind --leak-check=full --show-leak-kinds=all ./main <Casos/1/entrada.txt >saida.txt 

diff1:
	diff saida.txt Entradas/1/saida/saida.txt

#teste2 (teste leitura cliente)

teste2:
	./main <Entradas/2/entrada.txt >saida.txt

valgrind2:
	valgrind ./main <Entradas/2/entrada.txt >saida.txt

#teste3 (teste leitura fornecedor)

teste3:
	./main <Entradas/3/entrada.txt >saida.txt

valgrind3:
	valgrind ./main <Entradas/3/entrada.txt >saida.txt

#teste4 (teste leitura ingrediente)

teste4:
	./main <Entradas/4/entrada.txt >saida.txt

valgrind4:
	valgrind --leak-check=full ./main <Entradas/4/entrada.txt >saida.txt

#teste5 (teste leitura loja)

teste5:
	./main <Entradas/5/entrada.txt >saida.txt

valgrind5:
	valgrind --leak-check=full ./main <Entradas/5/entrada.txt >saida.txt

#teste6 (teste leitura produto)

teste6:
	./main <Entradas/6/entrada.txt >saida.txt

valgrind6:
	valgrind --leak-check=full ./main <Entradas/6/entrada.txt >saida.txt

#teste 8 (teste adicionar produtos sacola)

teste8:
	./main <Entradas/8/entrada.txt >saida.txt

valgrind8:
	valgrind --leak-check=full ./main <Entradas/8/entrada.txt >saida.txt

diff8:
	diff saida.txt Entradas/8/saida/saida.txt

#teste 7 (teste consulta lojas disponíveis)

teste7:
	./main <Entradas/7/entrada.txt >saida.txt

valgrind7:
	valgrind --leak-check=full ./main <Entradas/7/entrada.txt >saida.txt

diff7:
	diff saida.txt Entradas/7/saida/saida.txt

#teste 9 (teste remover produtos sacola)

teste9:
	./main <Entradas/9/entrada.txt >saida.txt

valgrind9:
	valgrind --leak-check=full ./main <Entradas/9/entrada.txt >saida.txt

diff9:
	diff saida.txt Entradas/9/saida/saida.txt

#teste 10 (teste limpa produtos sacola)

teste10:
	./main <Entradas/10/entrada.txt >saida.txt

valgrind10:
	valgrind --track-origins=yes -s ./main <Casos/10/entrada.txt >saida.txt

diff10:
	diff saida.txt Entradas/10/saida/saida.txt

#teste 11 (teste COI)

teste11:
	./main <Entradas/11/entrada.txt >saida.txt

valgrind11:
	valgrind --leak-check=full --track-origins=yes ./main <Entradas/11/entrada.txt >saida.txt

diff11:
	diff saida.txt Entradas/11/saida/saida.txt

remove:
	rm -rf main saida.txt valgrind.txt Resultados log.txt Resultado.csv saida.json
	clear