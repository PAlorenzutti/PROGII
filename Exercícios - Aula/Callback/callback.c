#include <stdio.h>

//declara o tipo de ponteiro para função;
//o que retorna, o nome (entre parênteses) e o que recebe;
typedef float (*opCallback) (float, float);

//inicia um vetor de funções do tipo callback declarado como NULL;
opCallback operacoes[128] = {NULL};

//operações a serem feitas na calculadora;
float soma (float num1, float num2){
    return num1 + num2;
}

float subtracao (float num1, float num2){
    return num1 - num2;
}

float produto (float num1, float num2){
    return num1 * num2;
}

float divisao (float num1, float num2){
    return num1 / num2;
}

//inicializa cada posição como deve;
void inicializa_array_operacoes() {
    operacoes['+'] = soma;

    operacoes['-'] = subtracao;

    operacoes['*'] = produto;

    operacoes['/'] = divisao;
}

//função que recebe o operador (+, -, * ou /) e os números;
float calculadora(char op_cod, float num1, float num2) {

    //cria um ponteiro de função;
    opCallback op;

    //aponta para a função determinada;
    op = operacoes[op_cod];

    //retorna o resultado da operação;
    return op(num1, num2);
}

int main(){
    //inicializa o vetor de operações
    inicializa_array_operacoes();
    
    //lê os números e o caractere da operação
    float num1, num2;
    char op_cod;
    scanf("%f %c %f", &num1, &op_cod, &num2);

    if(op_cod == '/' && num2 == 0){
        printf("Divisao por 0, indeterminado");
    }else{
        //imprime o resultado da operação;
        printf("%.2f %c %.2f = %.2f", num1, op_cod, num2, calculadora(op_cod, num1, num2));
    }

    return 0;
}