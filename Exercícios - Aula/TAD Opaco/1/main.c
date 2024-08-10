#include "vetor.h"

#include <stdio.h>

int main(){
    tVetor *v1 = criaVetor();
    tVetor *v2 = criaVetor();

    printf("Vetor 1: ");
    printVetor(v1);

    printf("Vetor 2: ");
    printVetor(v2);

    int opcao = printMenu();

    switch(opcao){
        case 1:
            somaVetores(v1, v2);

        case 2:
            diferençaVetores(v1, v2);

        case 3:
            produtoVetores(v1, v2);

        case 4:
            printf("Escolha o vetor que deseja multiplicar por um escalar (1 ou 2): ");
            int opcaoEscalar;
            scanf("%d\n", &opcaoEscalar);

            if(opcaoEscalar == 1){
                escalarVetor(v1);
            }

            if(opcaoEscalar == 2){
                escalarVetor(v2);
            }
    }

    liberaVetor(v1);
    liberaVetor(v2);

    return 0;
}