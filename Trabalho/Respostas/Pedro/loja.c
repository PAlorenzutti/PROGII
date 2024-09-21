#include "loja.h"
#include "constantes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Loja{
    char *nome;
    char *cnpj;
    char *telefone;
    char *endereco;
    char *usuario;
    char *senha;

    tProduto **produtos;
    int qtdProdutos;
};

tLoja *criaLoja(){
    tLoja *loja = (tLoja*)malloc(sizeof(tLoja));

    //inicializa os produtos;
    loja->produtos = NULL;
    loja->qtdProdutos = 0;

    //aloca espaço na memória para cada atributo;
    loja->nome = (char*)malloc(sizeof(char) * TAM_NOME);
    loja->cnpj = (char*)malloc(sizeof(char) * TAM_CNPJ);
    loja->telefone = (char*)malloc(sizeof(char) * TAM_TELEFONE);
    loja->endereco = (char*)malloc(sizeof(char) * TAM_ENDERECO);
    loja->usuario = (char*)malloc(sizeof(char) * TAM_USUARIO);
    loja->senha = (char*)malloc(sizeof(char) * TAM_SENHA);

    //lê a linha toda até o '\n'
    char linha[500];
    fgets(linha, 500, stdin);

    //lê os atributos que aparecem na linha
    if(sscanf(linha, "%99[^;]; %18[^;]; %14[^;]; %149[^;]; %14[^;]; %19s\n", loja->nome, loja->cnpj, loja->telefone, loja->endereco, loja->usuario, loja->senha) != 6){
        printf("ATRIBUTO(S) FALTANTE(S), FAVOR INICIAR O CADASTRO NOVAMENTE.\n");
        liberaLoja(loja);
        return NULL;
    }

    return loja;
}

int comparaLoja(tLoja *loja1, tLoja *loja2){
    return strcmp(loja1->cnpj, loja2->cnpj);
}

char *getCnpjLoja(tLoja *loja){
    return loja->cnpj;
}

char *getNomeLoja(tLoja *loja){
    return loja->nome;
}

char *getTelefoneLoja(tLoja *loja){
    return loja->telefone;
}

char *getEnderecoLoja(tLoja *loja){
    return loja->endereco;
}

void adicionaProdutoLoja(tLoja *loja, tProduto *produto){
    loja->qtdProdutos++;
    loja->produtos = (tProduto**)realloc(loja->produtos, sizeof(tProduto*) * loja->qtdProdutos);
    loja->produtos[loja->qtdProdutos - 1] = produto;

    //printf("\n\n");
    //printaProduto(produto);

    printf("PRODUTO CADASTRADO COM SUCESSO!\n");
}

tProduto *existeProdutoLoja(tLoja* loja, char *codigo){
    for(int i = 0; i < loja->qtdProdutos; i++){
        //se o código for igual ao código do produto em questão, retorna o produto;
        if(!strcmp(getCodProduto(loja->produtos[i]), codigo)){
            return loja->produtos[i];
        }
    }

    //se não encontrar, retorna nada;
    return NULL;
}

int existeProdutoNomeLoja(tLoja *loja, char *nome){
    for(int i = 0; i < loja->qtdProdutos; i++){
        //se o nome passado for igual ao nome ou subnome do produto da loja, existe;
        if(strstr(getNomeProduto(loja->produtos[i]), nome) != NULL){
            return 1;
        }
    }

    //se não encontrou nenhum produto com nome ou subnome igual, não existe;
    return 0;
}

void printaProdutosNomeLoja(tLoja *loja, char *nome, int *quantidadeProdutos){
    for(int i = 0; i < loja->qtdProdutos; i++){
        //compara se o nome do produto contém o nome passado;
        if(strstr(getNomeProduto(loja->produtos[i]), nome) != NULL){
            //incrementa a quantidade de produtos buscados (resultados);
            (*quantidadeProdutos)++;

            //printa a loja e o index do produto na pesquisa;
            printf("%d - %s, ", *quantidadeProdutos, loja->nome);

            //printa o produto;
            printaProduto(loja->produtos[i]);
        }
    }
}

int existeProdutoTipoLoja(tLoja *loja, char tipo){
    for(int i = 0; i < loja->qtdProdutos; i++){
        //se o tipo passado for igual ao tipo do produto da loja, existe;
        if(getTipoProduto(loja->produtos[i]) == tipo){
            return 1;
        }
    }

    //se não encontrou nenhum produto com o tipo, não existe;
    return 0;
}

void printaProdutosTipoLoja(tLoja *loja, char tipo, int *quantidadeProdutos){
    for(int i = 0; i < loja->qtdProdutos; i++){
        //compara se o produto é do mesmo tipo;
        if(getTipoProduto(loja->produtos[i]) == tipo){
            //incrementa a quantidade de produtos buscados (resultados);
            (*quantidadeProdutos)++;

            //printa a loja e o index do produto na pesquisa;
            printf("%d - %s, ", *quantidadeProdutos, loja->nome);

            //printa o produto;
            printaProduto(loja->produtos[i]);
        }
    }
}

int existeProdutosLoja(tLoja *loja){
    if(loja->produtos != NULL){
        return 1;
    }else{
        return 0;
    }
}

void printaProdutosLoja(tLoja *loja, int *quantidadeProdutos){
    for(int i = 0; i < loja->qtdProdutos; i++){
            //incrementa a quantidade de produtos buscados (resultados);
            (*quantidadeProdutos)++;

            //printa a loja e o index do produto na pesquisa;
            printf("%d - %s, ", *quantidadeProdutos, loja->nome);

            //printa o produto;
            printaProduto(loja->produtos[i]);
    }
}

void printaLoja(tLoja *loja){
    printf("LOJA: %s (%s): \n", loja->nome, loja->cnpj);

    //printa produtos
    if(loja->produtos != NULL){
        for(int i = 0; i < loja->qtdProdutos; i++){
            printf("%d - ", i + 1);
            printaProduto(loja->produtos[i]);
        }
    }
}

void liberaLoja(tLoja *loja){
    free(loja->nome);
    free(loja->cnpj);
    free(loja->telefone);
    free(loja->endereco);
    free(loja->usuario);
    free(loja->senha);

    //libera produtos e seu ponteiro de ponteiros;
    if(loja->produtos != NULL){
        for(int i = 0; i < loja->qtdProdutos; i++){
            liberaProduto(loja->produtos[i]);
        }

        free(loja->produtos);
    }

    free(loja);
}