#include <stdio.h>
#include <string.h>
#include "product.h"

tProduct leProduto(){
    char nome[MAX_NOME];
    int id;
    float preco;
    float desconto;
    int estoque;

    printf("Nome do Produto: ");
    scanf("%[^\n]\n", nome);

    printf("ID: ");
    scanf("%d\n", &id);

    printf("Preco: ");
    scanf("%f\n", &preco);

    printf("Desconto: ");
    scanf("%f\n", &desconto);

    printf("Estoque: ");
    scanf("%d\n", &estoque);

    tProduct produto = criaProduto(nome, desconto, preco, estoque, id);

    return produto;
}

tProduct criaProduto(char* nome, float desconto, float preco, int estoque, int id){
    tProduct produto;

    strcpy(produto.nome, nome);
    produto.id = id;
    produto.preco = preco;
    produto.desconto = desconto;
    produto.estoque = estoque;
    produto.vendas = 0;

    return produto;
}

float obtemPrecoComDesconto(tProduct produto){
    float precoComDesconto;

    precoComDesconto = produto.preco * (1 - produto.desconto);

    return precoComDesconto;
}

int obtemId(tProduct produto){
    return produto.id;
}

tProduct aumentaEstoqueProduto(tProduct produto, int qtd){
    if(qtd > 0){
        produto.estoque += qtd;
    }else{
        printf("Quantidade inválida.\n");
    }

    return produto;
}

tProduct vendeProduto(tProduct produto, int qtd){
    if(produto.estoque - qtd >= 0){
        produto.estoque -= qtd;
        produto.vendas += qtd;
    }else{
        printf("Quantidade inválida.\n");
    }

    return produto;
}

tProduct atualizaDesconto(tProduct produto, float desconto){
    if(desconto >= 0 && desconto <= 1){
        produto.desconto = desconto;
    }else{
        printf("Quantidade inválida.\n");
    }

    return produto;
}

bool ehMesmoId(tProduct produto, int id){
    int idProduto = obtemId(produto);
    
    if(idProduto == id){
        return true;
    }else{
        return false;
    }
}

void imprimeProduto(tProduct produto){
    float precoAtual = obtemPrecoComDesconto(produto);

    printf("Produto: %s, Preco atual: %.2f, Qtd no estoque: %d, Qtd vendida: %d\n", produto.nome, precoAtual, produto.estoque, produto.vendas);          
}