#include <stdio.h>
#include <string.h>

#include "filme.h"

tFilme criarFilme (char* nome, int codigo, int valor, int quantidade){
    tFilme filme;

    filme.codigo = codigo;
    strcpy(filme.nome, nome);
    filme.valor = valor;
    filme.qtdEstoque = quantidade;
    filme.qtdAlugada = 0;

    return filme;
}

tFilme leFilme(int codigo){
    tFilme filme;

    char nome[MAX_CARACTERES];
    int valor, quantidade;

    scanf("%19[^,],%d,%d\n", nome, &valor, &quantidade);

    filme = criarFilme(nome, codigo, valor, quantidade);

    return filme;
}

int obterCodigoFilme (tFilme filme){
    return filme.codigo;
}

void imprimirNomeFilme (tFilme filme){
    printf("%s", filme.nome);
}

int obterQtdEstoqueFilme (tFilme filme){
    return filme.qtdEstoque;
}

int compararNomesFilmes (tFilme filme1, tFilme filme2){
    return strcmp(filme1.nome, filme2.nome);
}