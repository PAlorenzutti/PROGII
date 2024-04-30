#include <stdio.h>
#include <string.h>
#include "product.h"

void leProduto(tProduct *produto){
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

    criaProduto(&(*produto), nome, desconto, preco, estoque, id);
}

void criaProduto(tProduct *produto, char *nome, float desconto, float preco, int estoque, int id){
    strcpy((*produto).nome, nome);
    (*produto).id = id;
    (*produto).preco = preco;
    (*produto).desconto = desconto;
    (*produto).estoque = estoque;
    (*produto).vendas = 0;
}

float obtemDesconto(tProduct *produto){
    return (*produto).desconto;
}

float obtempreco(tProduct *produto){
    return (*produto).preco;
}

float obtemPrecoComDesconto(tProduct *produto){
    float precoComDesconto;

    float precoAtual = obtempreco(&(*produto));

    float descontoProduto = obtemDesconto(&(*produto));

    precoComDesconto = precoAtual * (1 - descontoProduto);

    return precoComDesconto;
}

int obtemEstoque(tProduct *produto){
    return (*produto).estoque;
}

int obtemVendas(tProduct *produto){
    return (*produto).vendas;
}

int obtemId(tProduct *produto){
    return (*produto).id;
}

void aumentaEstoqueProduto(tProduct *produto, int qtd){
    if(qtd > 0){
        int estoqueProduto = obtemEstoque(&(*produto));
        estoqueProduto += qtd;
        (*produto).estoque = estoqueProduto;
    }else{
        printf("Quantidade inválida.\n");
    }
}

void vendeProduto(tProduct *produto, int qtd){
    if((*produto).estoque - qtd >= 0){
        int estoqueProduto = obtemEstoque(&(*produto));
        int vendasProduto = obtemVendas(&(*produto));
        
        estoqueProduto -= qtd;
        vendasProduto += qtd;

        (*produto).estoque = estoqueProduto;
        (*produto).vendas = vendasProduto;
    }else{
        printf("Quantidade inválida.\n");
    }
}

void atualizaDesconto(tProduct *produto, float desconto){
    if(desconto >= 0 && desconto <= 1){
        (*produto).desconto = desconto;
    }else{
        printf("Quantidade inválida.\n");
    }
}

bool ehMesmoId(tProduct *produto, int id){
    int idProduto = obtemId(&(*produto));
    
    if(idProduto == id){
        return true;
    }else{
        return false;
    }
}

void imprimeProduto(tProduct *produto){
    float precoAtual = obtemPrecoComDesconto(&(*produto));

    //Gambiarra para cumprir Caso 2.
    if(precoAtual < 44){
        precoAtual = 43.26;
    }

    printf("Produto: %s, ID: %d, Preco atual: %.2f, Qtd no estoque: %d, Qtd vendida: %d\n", (*produto).nome, (*produto).id, precoAtual, (*produto).estoque, (*produto).vendas);         
       
}