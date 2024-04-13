#include "product.h"

tProduct leProduto(){
    tProduct produto;

    printf("Nome do Produto: ");
    scanf("%[^\n]\n", produto.nome);

    printf("ID: ");
    scanf("%d\n", produto.id);

    printf("Preco: ");
    scanf("%f\n", produto.preco);

    printf("Desconto: ");
    scanf("%f\n", produto.desconto);

    printf("Estoque: ");
    scanf("%d\n", produto.estoque);

    return produto;
}