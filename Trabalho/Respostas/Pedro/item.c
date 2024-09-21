#include "item.h"
#include "produto.h"
#include "constantes.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Item{
    tProduto *produto;
    int quantidade;
};

tItem *criaItem(tProduto *produto, int quantidade){
    tItem *item = (tItem*)malloc(sizeof(tItem));

    item->produto = produto;
    item->quantidade = quantidade;

    return item;
}

int checaDisponibilidadeItem(tItem *item){
    //se a diferença entre a disponibilidade do produto e a quantidade a ser comprada for zero, retorna disponível para venda;
    if(getDisponibilidadeProduto(item->produto, item->quantidade) >= 0){
        return 1;
    }else{
        //não disponível para a venda;
        return 0;
    }
}

void atualizaDisponibilidadeItem(tItem *item){
    alteraDisponibilidadeProduto(item->produto, item->quantidade);
}

char *getIdItem(tItem *item){
    return getCodProduto(item->produto);
}

char *getNomeItem(tItem *item){
    return getNomeProduto(item->produto);
}

int getQtdItem(tItem *item){
    return item->quantidade;
}

float getPrecoItem(tItem *item){
    return getValorProduto(item->produto);
}

void incrementaQtdItem(tItem *item, int quantidade){
    item->quantidade += quantidade;
}

void decrementaQtdItem(tItem *item, int quantidade){
    item->quantidade -= quantidade;
}

int comparaItem(tItem *item1, tItem *item2){
    return strcmp(getCodProduto(item1->produto), getCodProduto(item2->produto));
}

void printaFisicoItem(tItem *item){
    imprimeFisico(item->produto, item->quantidade);
}

void printaDigitalItem(tItem *item, char *email){
    imprimeDigital(item->produto, email, item->quantidade);
}

void avaliaItem(tItem *item, char *cpf){
    //printa index e nome do produto;
    printf("PRODUTO %s, %s:\n", getCodProduto(item->produto), getNomeProduto(item->produto));

    tAvaliacao *avaliacao = criaAvaliacao(cpf);

    insereAvaliacaoProduto(item->produto, avaliacao);

    printf("AVALIACAO REGISTRADA COM SUCESSO!\n");
}

void liberaItem(tItem *item){
    if(item != NULL){
        free(item);
        item = NULL;
    }    
}