#include "vetor.h"
#include <stdio.h>

void LeVetor(Vetor *vetor){
    scanf("%d\n", &(*vetor).tamanhoUtilizado);
    
    for(int i = 0; i < (*vetor).tamanhoUtilizado; i++){
        scanf("%d ", &(*vetor).elementos[i]);
    }
}

int AplicarOperacaoVetor(Vetor *vetor, Operation op){
    int resultado = 1;

    for(int i = 0; i < (*vetor).tamanhoUtilizado; i++){
        resultado = op(resultado, (*vetor).elementos[i]);
    }


    if( op(resultado, (*vetor).elementos[(*vetor).tamanhoUtilizado]) == resultado * (*vetor).elementos[(*vetor).tamanhoUtilizado]) 
        return resultado;
    else{
        return resultado - 1;
    }
}

void printVetor(Vetor *vetor){
    for(int i = 0; i < (*vetor).tamanhoUtilizado; i++){
        printf("%d ", (*vetor).elementos[i]);
    }
}