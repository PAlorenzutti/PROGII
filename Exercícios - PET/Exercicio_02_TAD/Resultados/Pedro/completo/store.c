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
    int indexProduto = buscaProduto(loja, id);
    
    if(indexProduto != -1){
        loja.produtos[indexProduto] = aumentaEstoqueProduto(loja.produtos[indexProduto], qtd);
    }else{
        printf("Id invalido\n");
    }

    return loja;
}

tStore vendeProdutoLoja(tStore loja, int id, int qtd){
    int indexProduto = buscaProduto(loja, id);

    if(indexProduto != -1){
        loja.produtos[indexProduto] = vendeProduto(loja.produtos[indexProduto], qtd);
    }else{
        printf("Id invalido\n");
    }

    return loja;
}

tStore atualizaDescontoLoja(tStore loja, int id, float desconto){
    int indexProduto = buscaProduto(loja, id);

    if(indexProduto != -1){
        loja.produtos[indexProduto] = atualizaDesconto(loja.produtos[indexProduto], desconto);
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