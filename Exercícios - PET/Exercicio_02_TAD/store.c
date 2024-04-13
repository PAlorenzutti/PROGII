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