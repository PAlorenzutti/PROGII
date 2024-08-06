#include <stdio.h>
#include <stdlib.h>

#define NUM_DISC 4
#define NUM_ALUN 3

void leNotas(int **notas){
    for(int i = 0; i < NUM_ALUN; i++){
        for(int j = 0; j < NUM_DISC; j++){
            scanf("%d", &notas[i][j]);
        }
    }
}

void printNotas(int **notas){
    for(int i = 0; i < NUM_ALUN; i++){
        for(int j = 0; j < NUM_DISC; j++){
            printf("%d ", notas[i][j]);
        }
        printf("\n");
    }
}

void freeNotas(int **notas){
    //desaloca primeiro as colunas
    for(int i = 0; i < NUM_ALUN; i++) {
        free(notas[i]);
    }

    free(notas);
}

int main(){
    int **notas = (int**) malloc(NUM_ALUN * sizeof(int*));

    //aloca as colunas para cada linha
    for(int i = 0; i < NUM_ALUN; i++) {
        notas[i] = (int*) malloc(NUM_DISC * sizeof(int));
    }

    leNotas(notas);

    printNotas(notas);

    freeNotas(notas);

    return 0;
}