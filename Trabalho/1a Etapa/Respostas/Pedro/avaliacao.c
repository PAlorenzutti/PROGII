#include "avaliacao.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Avaliacao{
    char *cpfUsuario;
    char *comentario;
    int nota;
};

tAvaliacao * criaAvaliacao(char * cpfUsuario){
    tAvaliacao *a = (tAvaliacao*)malloc(sizeof(tAvaliacao));

    //aloca memória e copia o CPF
    a->cpfUsuario = malloc(strlen(cpfUsuario) + 1);
    strcpy(a->cpfUsuario, cpfUsuario);

    //inicializa o comentário como NULL
    a->comentario = NULL;
    int i = 0;

    while(true){
        char caractere;
        scanf("%c", &caractere);

        if(caractere == ';'){
            break;
        }

        i++;
        a->comentario = (char*)realloc(a->comentario, sizeof(char) * (i + 1));
        a->comentario[i - 1] = caractere;
    }
    a->comentario[i] = '\0';

    //leitura da nota
    scanf(" %d", &a->nota);

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