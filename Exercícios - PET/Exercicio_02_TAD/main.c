#include <stdio.h>
#include <stdbool.h>
#include "store.h"
#include "product.h"

char menu(){
    char option;

    printf("Menu:\n");
    printf(" C - Cadastrar Produto\n");
    printf(" E - Estocar Produto\n");
    printf(" V - Vender Produto\n");
    printf(" D - Atualizar desconto de Produto\n");
    printf(" I - Imprimir Produtos\n");
    printf(" F - Finalizar Programa\n");

    scanf("%c\n", &option);

    return option;
}

int main(){
    tStore loja;

    loja = abreLoja();

    while(true){
        char option = menu();

        if(option == 'C'){
            tProduct produto;

            produto = leProduto();

            loja = adicionaProduto(loja, produto);
        }

        if(option == 'E'){
            int id, qtd;
            
            printf("Digite o id do produto: ");
            scanf("%d\n", &id);

            printf("Digite o numero de unidades: ");
            scanf("%d\n", &qtd);

            loja = aumentaEstoqueLoja(loja, id, qtd);
        }

        if(option == 'V'){

        }

        if(option == 'D'){

        }

        if(option == 'I'){

        }

        if(option == 'F'){
            break;
        }
    }

    imprimeProdutosLoja(loja);

    return 0;
}