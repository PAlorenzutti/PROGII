#include <stdio.h>
#include "store.h"

tStore abreLoja(){
    tStore store;

    store.nmProdutos = 0;

    return store;
}

tStore adicionaProduto(tStore loja, tProduct produto){
    loja.produtos[loja.nmProdutos] = produto;
    loja.nmProdutos++;

    return loja;
}

int buscaProduto(tStore loja, int id){
    for(int i = 0; i < loja.nmProdutos; i++){
        if(ehMesmoId(loja.produtos[i], id)){
            return i;
        }
    }

    return -1;
}

tStore aumentaEstoqueLoja(tStore loja, int id, int qtd){
    int index = buscaProduto(loja, id);
    
    if(index != -1){
        loja.produtos[index] = aumentaEstoqueProduto(loja.produtos[index], qtd);
    }else{
        printf("Id invalido\n");
    }

    return loja;
}



void imprimeProdutosLoja(tStore loja){
    for(int i = 0; i < loja.nmProdutos; i++){
        imprimeProduto(loja.produtos[i]);
    }
}