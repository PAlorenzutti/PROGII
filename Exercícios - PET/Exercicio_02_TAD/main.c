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

    scanf("%c", &option);

    return option;
}

int main(){
    tStore store;

    store = abreLoja();

    while(true){
        char option = menu();

        if(option == 'C'){
            tProduct produto;

            produto = leProduto();

            store = adicionaProduto(store, produto);
        }

        if(option == 'E'){

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
}