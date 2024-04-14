#include <stdio.h>
#include "product.h"

tProduct leProduto(){
    tProduct produto;

    printf("Nome do Produto: ");
    scanf("%[^\n]\n", produto.nome);

    printf("ID: ");
    scanf("%d\n", &produto.id);

    printf("Preco: ");
    scanf("%f\n", &produto.preco);

    printf("Desconto: ");
    scanf("%f\n", &produto.desconto);

    printf("Estoque: ");
    scanf("%d\n", &produto.estoque);

    produto.vendas = 0;

    return produto;
}

tProduct aumentaEstoqueProduto(tProduct produto, int qtd){
    if(qtd > 0){
        produto.estoque += qtd;
    }else{
        printf("Quantidade inválida.\n");
    }

    return produto;
}

bool ehMesmoId(tProduct produto, int id){
    if(id == produto.id){
        return true;
    }else{
        return false;
    }
}

void imprimeProduto(tProduct produto){
    printf("Produto: %s, Preco atual: %.2f, Qtd no estoque: %d, Qtd vendida: %d\n", produto.nome, produto.preco, produto.estoque, produto.vendas);          
}