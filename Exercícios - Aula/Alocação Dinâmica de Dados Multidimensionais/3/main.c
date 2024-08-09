#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct{
    float *notas;
    int qtdNotas;
    float media;
    float desvio;
}Turma;

//pra deixar mais limpo, seria melhor fazer um TAD colégio com ponteiro pra turma, qtdNotasColegio, media e desvio;

void mediaTurma(Turma *turma){
    float soma = 0;
    
    for(int i = 0; i < turma->qtdNotas; i++){
        soma += turma->notas[i];
    }

    turma->media = (float) soma / turma->qtdNotas;
}

void desvioTurma(Turma *turma){
    float soma = 0;

    for(int i = 0; i < turma->qtdNotas; i++){
        soma += pow(turma->notas[i] - turma->media, 2);
    }

    turma->desvio = sqrt(soma / turma->qtdNotas);
}

float mediaTurmas(Turma *turmas, int qtdTurmas, int totalNotas){
    float soma = 0;
    
    for(int i = 0; i < qtdTurmas; i++){
        for(int j = 0; j < turmas[i].qtdNotas; j++){
            soma += turmas[i].notas[j];
        }
    }

    return (float) soma / totalNotas;
}

float desvioTurmas(Turma *turmas, int qtdTurmas, int totalNotas, float media){
    float soma = 0;

    for(int i = 0; i < qtdTurmas; i++){
        for(int j = 0; j < turmas[i].qtdNotas; j++){
            soma += pow(turmas[i].notas[j] - media, 2);
        }
    }

    return (float) sqrt(soma / totalNotas);
}   

void printNotas(float *notas, int qtdNotas){
    for(int i = 0; i < qtdNotas; i++){
        printf("%.2f ", notas[i]);
    }
}

void printTurmas(Turma *turmas, int qtdTurmas){
    for(int i = 0; i < qtdTurmas; i++){
        printf("Turma %d: ", i);
        printNotas(turmas[i].notas, turmas[i].qtdNotas);

        mediaTurma(&turmas[i]);
        printf(", Media: %.2f", turmas[i].media);

        desvioTurma(&turmas[i]);
        printf(", Desvio: %.2f\n", turmas[i].desvio);
    }
}

int main(){
    Turma *turmas = NULL;
    int qtdTurmas = 0;
    int totalNotas = 0;

    //para ler a linha
    char linha[1024];

    while(true){
        fgets(linha, sizeof(linha), stdin);

        //se o usuário digitar -1, para de ler;
        if(!strcmp(linha, "-1")){
            break;
        }

        //realoca a memória para quantidade de turmas inseridas
        turmas = realloc(turmas, (qtdTurmas + 1) * sizeof(Turma));

        //pega a quantidade de notas digitadas
        int qtdNotas = 0;

        for(int i = 0; linha[i] != '\0'; i++){
            if(linha[i] == ' ' || linha[i] == '\n'){
                qtdNotas++;
            }
        }

        //pega a quantidade de notas e aloca memória para a quantidade de notas inseridas;
        turmas[qtdTurmas].qtdNotas = qtdNotas;
        turmas[qtdTurmas].notas = malloc(turmas[qtdTurmas].qtdNotas * sizeof(float));

        //lê as notas a partir de um ponteiro de char;
        char* temp = linha;

        for(int i = 0; *temp != '\0'; i++){
            sscanf(temp, "%f", &turmas[qtdTurmas].notas[i]);

            //pula os espaços e \n
            while (*temp != ' ' && *temp != '\n') {
                temp++;
            }

            temp++;
        }

        //incrementa a quantidade de turmas;
        qtdTurmas++;

        //incrementa a quantidade de notas;
        totalNotas += qtdNotas;
    }

    printTurmas(turmas, qtdTurmas);

    //Média de todas as turmas juntas:
    float media = mediaTurmas(turmas, qtdTurmas, totalNotas);
    printf("Media das Turmas: %.2f\n", media);

    //Desvio de todas as turmas juntas;
    float desvio = desvioTurmas(turmas, qtdTurmas, totalNotas, media);
    printf("Desvio Padrao das Turmas: %.2f\n", desvio);

    return 0;
}