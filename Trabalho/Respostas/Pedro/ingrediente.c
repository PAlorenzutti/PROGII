#include "ingrediente.h"
#include "constantes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ingrediente{
    char *nome;
    int codigoBarras;
    char tipo;
    int quantidade;
};

tIngrediente *criaIngrediente(){
    tIngrediente *ingrediente = (tIngrediente*)malloc(sizeof(tIngrediente));

    //alocando espaço para nome
    ingrediente->nome = (char*)malloc(sizeof(char) * TAM_NOME);

    //lê a linha toda até o '\n'
    char linha[500];
    fgets(linha, 500, stdin);

    if(sscanf(linha, "%99[^;]; %d; %c; %d\n", ingrediente->nome, &ingrediente->codigoBarras, &ingrediente->tipo, &ingrediente->quantidade) != 4){
        liberaIngrediente(ingrediente);
        return NULL;
    }

    return ingrediente;
}

char* getNomeIngrediente(tIngrediente *ingrediente){
    return ingrediente->nome;
}

int getQuantidade(tIngrediente *ingrediente){
    return ingrediente->quantidade;
}

int comparaIngrediente(tIngrediente *ingrediente1, tIngrediente *ingrediente2){
    return strcmp(ingrediente1->nome, ingrediente2->nome);
}

void incrementaQtdIngrediente(tIngrediente *ingrediente, int quantidade){
    ingrediente->quantidade += quantidade;
}

void decrementaQtdIngrediente(tIngrediente *ingrediente, int quantidade){
    ingrediente->quantidade -= quantidade;
}

void printaIngrediente(tIngrediente *ingrediente){
    printf("%s, %d, %c, QUANTIDADE DISPONIVEL: %d UNIDADE(S).\n", ingrediente->nome, ingrediente->codigoBarras, ingrediente->tipo, ingrediente->quantidade);
}

void liberaIngrediente(tIngrediente *ingrediente){
    free(ingrediente->nome);

    free(ingrediente);
}