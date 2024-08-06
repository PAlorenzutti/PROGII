#include <stdio.h>
#include <stdlib.h>

#define NUM_DISC 4
#define NUM_ALUN 3

void leNotas(int *notas){
    for(int i = 0; i < NUM_ALUN; i++){
        for(int j = 0; j < NUM_DISC; j++){
            scanf("%d", &notas[NUM_DISC * i + j]);
        }
    }
}

void printNotas(int *notas){
    for(int i = 0; i < NUM_ALUN; i++){
        for(int j = 0; j < NUM_DISC; j++){
            printf("%d ", notas[NUM_DISC * i + j]);
        }
        printf("\n");
    }
}

void freeNotas(int *notas){
    free(notas);
}

int main(){
    int *notas = (int*) malloc((NUM_ALUN * NUM_DISC) * sizeof(int));

    leNotas(notas);

    printNotas(notas);

    freeNotas(notas);

    return 0;
}