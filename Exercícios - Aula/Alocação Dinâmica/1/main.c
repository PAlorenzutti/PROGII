#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int nota;
}tAluno;

void leTurma(tAluno alunos[], int qtdAlunos){
    for(int i = 0; i < qtdAlunos; i++){
        scanf("%d\n", &alunos[i].nota);
    }
}

float calculaMedia(tAluno alunos[], int qtdAlunos){
    float media = 0;
    
    for(int i = 0; i < qtdAlunos; i++){
        media += alunos[i].nota;
    }

    return media /= qtdAlunos;
}

float calculaDesvio(tAluno alunos[], int qtdAlunos, float media){
    float desvio = 0;

    for(int i = 0; i < qtdAlunos; i++){
        desvio += pow(alunos[i].nota - media, 2);
    }

    return sqrt(desvio / qtdAlunos);
}

void printTurma(tAluno alunos[], int qtdAlunos){
    for(int i = 0; i < qtdAlunos; i++){
        printf("%d\n", alunos[i].nota);
    }

    float media = calculaMedia(alunos, qtdAlunos);
    float desvio = calculaDesvio(alunos, qtdAlunos, media);

    printf("Media: %.2f\n", media);

    printf("Desvio Padrao: %.2f\n", desvio);
}


int main(){
    int qtdAlunos;
    scanf("%d\n", &qtdAlunos);

    tAluno* alunos = (tAluno*) malloc(qtdAlunos * sizeof(tAluno));

    leTurma(alunos, qtdAlunos);

    printTurma(alunos, qtdAlunos);

    free(alunos);

    return 0;
}
