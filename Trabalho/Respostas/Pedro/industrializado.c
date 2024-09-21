#include "industrializado.h"

#include <stdio.h>
#include <stdlib.h>

#define TAM_CODIGO 15
#define TAM_NOME 20
#define TAM_DESCRICAO 100
#define TAM_TIPO 4

struct Industrializado{
    char *codigo;
    char *nome;
    char *descricao;
    float valor;
    char *tipo;
    int quantidade;
};

tIndustrializado* criaIndustrializado(){
    tIndustrializado *i = (tIndustrializado*)malloc(sizeof(tIndustrializado));

    //aloca espaço para todos os atributos de char;
    i->codigo = (char*)malloc(sizeof(char) * TAM_CODIGO);
    i->nome = (char*)malloc(sizeof(char) * TAM_NOME);
    i->descricao = (char*)malloc(sizeof(char) * TAM_DESCRICAO);
    i->tipo = (char*)malloc(sizeof(char) * TAM_TIPO);

    //lê a linha toda até o '\n'
    char linha[500];
    fgets(linha, 500, stdin);

    //lê todos os atributos e já confere se leu corretamente;
    if(sscanf(linha, "%14[^;]; %19[^;]; %99[^;]; %f; %3[^;]; %d", i->codigo, i->nome, i->descricao, &i->valor, i->tipo, &i->quantidade) != 6){
        printf("ATRIBUTO(S) FALTANTE(S), FAVOR INICIAR O CADASTRO NOVAMENTE.\n");
        liberaIndustrializado(i);
        return criaIndustrializado();
    }

    return i;
}

void imprimeFisicoIndustrializado(void *dado, int qtd){
    //faz o typecast do void *dado;
    tIndustrializado* i = (tIndustrializado*) dado;

    printf("IMPRESSAO NF FISICA DE INDUSTRIALIZADO:\n");
    printf("ID DO INDUSTRIALIZADO: %s\n", i->codigo);
    printf("NOME DO INDUSTRIALIZADO: %s\n", i->nome);
    printf("DESCRICAO DO PRATO: %s\n", i->descricao);
    printf("VALOR DO INDUSTRIALIZADO: %.2f\n", i->valor);
    printf("QUANTIDADE: %d\n", qtd);
    printf("VALOR FINAL DO INDUSTRIALIZADO: %.2f\n", i->valor * qtd);
}

void imprimeDigitalIndustrializado(void *dado, char *email, int qtd){
    //faz o typecast do void *dado;
    tIndustrializado* i = (tIndustrializado*) dado;

    printf("IMPRESSAO NF DIGITAL DE INDUSTRIALIZADO:\n");
    printf("E-MAIL DE ENVIO: %s\n", email);
    printf("ID DO INDUSTRIALIZADO: %s\n", i->codigo);
    printf("NOME DO INDUSTRIALIZADO: %s\n", i->nome);
    printf("DESCRICAO DO PRATO: %s\n", i->descricao);
    printf("VALOR DO INDUSTRIALIZADO: %.2f\n", i->valor);
    printf("QUANTIDADE: %d\n", qtd);
    printf("VALOR FINAL DO INDUSTRIALIZADO: %.2f\n", i->valor * qtd);
}

float getValorIndustrializado(void *dado){
    //faz o typecast do void *dado;
    tIndustrializado *i = (tIndustrializado*) dado;

    return i->valor;
}

char* getCodIndustrializado(void *dado){
    //faz o typecast do void *dado;
    tIndustrializado *i = (tIndustrializado*) dado;

    return i->codigo;
}

char* getDescIndustrializado(void *dado){
    //faz o typecast do void *dado;
    tIndustrializado *i = (tIndustrializado*) dado;

    return i->descricao;
}

char getTipoIndustrializado(void *dado){
    return 'I';
}

char * getNomeIndustrializado(void *dado){
    //faz o typecast do void *dado;
    tIndustrializado *i = (tIndustrializado*) dado;

    return i->nome;
}

int getDisponibilidadeIndustrializado(void *dado, int qtd){
    //faz o typecast do void *dado;
    tIndustrializado *i = (tIndustrializado*) dado;

    return i->quantidade - qtd;
}

void alteraDisponibilidadeIndustrializado(void *dado, int qtd){
    //faz o typecast do void *dado;
    tIndustrializado *i = (tIndustrializado*) dado;

    i->quantidade -= qtd;
}

void printaIndustrializado(void *dado){
    //faz o typecast do void *dado;
    tIndustrializado *i = (tIndustrializado*) dado;

    printf("%s, %s, %s, %s, I, R$%.2f. ", i->nome, i->codigo, i->descricao, i->tipo, i->valor);
}

void liberaIndustrializado(void * industrializado){
    //faz o typecast do void *dado;
    tIndustrializado *i = (tIndustrializado*) industrializado;

    //libera cada vetor de caracteres alocado separadamente (string);
    free(i->codigo);
    free(i->nome);
    free(i->descricao);
    free(i->tipo);

    //libera o ponteiro industrializado;
    free(i);
}