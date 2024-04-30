#include <stdio.h>
#include "store.h"

void abreLoja(tStore *loja){
    (*loja).nmProdutos = 0;
}

void adicionaProduto(tStore *loja, tProduct produto){
    (*loja).produtos[(*loja).nmProdutos] = produto;
    (*loja).nmProdutos++;
}

int buscaProduto(tStore *loja, int id){
    for(int i = 0; i < (*loja).nmProdutos; i++){
        if(ehMesmoId(&(*loja).produtos[i], id)){
            return i;
        }
    }

    return -1;
}

void aumentaEstoqueLoja(tStore *loja, int id, int qtd){
    int indexProduto = buscaProduto(&(*loja), id);
    
    if(indexProduto != -1){
        aumentaEstoqueProduto(&(*loja).produtos[indexProduto], qtd);
    }else{
        printf("Id invalido\n");
    }
}

void vendeProdutoLoja(tStore *loja, int id, int qtd){
    int indexProduto = buscaProduto(&(*loja), id);

    if(indexProduto != -1){
        vendeProduto(&(*loja).produtos[indexProduto], qtd);
    }else{
        printf("Id invalido\n");
    }
}

void atualizaDescontoLoja(tStore *loja, int id, float desconto){
    int indexProduto = buscaProduto(&(*loja), id);

    if(indexProduto != -1){
        atualizaDesconto(&(*loja).produtos[indexProduto], desconto);
    }else{
        printf("Id invalido\n");
    }
}


void imprimeProdutosLoja(tStore *loja){
    for(int i = 0; i < (*loja).nmProdutos; i++){
        imprimeProduto(&(*loja).produtos[i]);
    }
}