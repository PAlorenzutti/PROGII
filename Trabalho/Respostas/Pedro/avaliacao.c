#include "avaliacao.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_CPF 13
#define TAM_COMENTARIO 200

struct Avaliacao{
    char *cpfUsuario;
    char *comentario;
    int nota;
};

tAvaliacao * criaAvaliacao(char * cpfUsuario){
    tAvaliacao *a = (tAvaliacao*)malloc(sizeof(tAvaliacao));

    //aloca memória e copia o CPF
    a->cpfUsuario = malloc(sizeof(char) * TAM_CPF);

    //lê o cpf do usuário
    strcpy(a->cpfUsuario, cpfUsuario);

    //aloca memória para o comentário
    a->comentario = (char*)malloc(sizeof(char) * TAM_COMENTARIO);

    //lê a linha toda até o '\n'
    char linha[500];
    fgets(linha, 500, stdin);

    //lê todos os atributos e já confere se leu corretamente;
    if(sscanf(linha, "%199[^;]; %d", a->comentario, &a->nota) != 2){
        printf("AVALIACAO INVALIDA! FAVOR INICIAR A AVALIACAO NOVAMENTE!\n");
        liberaAvaliacao(a);
        return criaAvaliacao(cpfUsuario);
    }

    return a;
}

char * getComentarioAvaliacao(tAvaliacao * a){
    return a->comentario;
}

int getNotaAvaliacao(tAvaliacao * a){
    return a->nota;
}

char * getCpfClienteAvaliacao(tAvaliacao * a){
    return a->cpfUsuario;
}

void liberaAvaliacao(tAvaliacao * a){
    free(a->cpfUsuario);
    free(a->comentario);
    free(a);
}