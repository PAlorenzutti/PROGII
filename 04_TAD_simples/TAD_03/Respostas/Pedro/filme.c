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

int obterValorFilme (tFilme filme){
    return filme.valor;
}

int obterQtdEstoqueFilme (tFilme filme){
    return filme.qtdEstoque;
}

int ehMesmoCodigoFilme (tFilme filme, int codigo){
    if(filme.codigo == codigo){
        return 1;
    }else{
        return 0;
    }
}

tFilme alugarFilme (tFilme filme){
    filme.qtdEstoque--;
    filme.qtdAlugada++;

    return filme;
}

int compararNomesFilmes (tFilme filme1, tFilme filme2){
    return strcmp(filme1.nome, filme2.nome);
}