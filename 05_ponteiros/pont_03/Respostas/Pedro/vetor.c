#include <stdio.h>
#include "vetor.h"

void LeDadosParaVetor(int * vet, int tam){
    for(int i = 0; i < tam; i++){
        scanf("%d ", &vet[i]);
    }
}

void ImprimeDadosDoVetor(int * n, int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ", n[i]);
    }  

    printf("\n");
}
// Troca o valor de duas variáveis se o segundo for menor que o primeiro
void TrocaSeAcharMenor(int *vet, int tam, int *paraTrocar) {
    for (int i = 0; i < tam; i++) {
        if (vet[i] < *paraTrocar) {
            *paraTrocar = vet[i];
        }
    }
}

// Ordena um vetor em ordem crescente usando a função TrocaSeAcharMenor
void OrdeneCrescente(int *vet, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        int minIndex = i;
        int minValue = vet[i];
        // Use TrocaSeAcharMenor para encontrar o menor valor no sub-vetor restante
        TrocaSeAcharMenor(&vet[i + 1], tam - i - 1, &minValue);

        // Encontre o índice do menor valor no sub-vetor restante
        for (int j = i + 1; j < tam; j++) {
            if (vet[j] == minValue) {
                minIndex = j;
                break;
            }
        }

        // Troque os valores se necessário
        if (minIndex != i) {
            int temp = vet[i];
            vet[i] = vet[minIndex];
            vet[minIndex] = temp;
        }
    }
}