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

    abreLoja(&loja);

    while(true){
        char option = menu();

        if(option == 'C'){
            tProduct produto;

            leProduto(&produto);

            adicionaProduto(&loja, produto);
        }

        if(option == 'E'){
            int id, qtd;
            
            printf("Digite o id do Produto: ");
            scanf("%d\n", &id);

            printf("Digite o numero de unidades: ");
            scanf("%d\n", &qtd);

            aumentaEstoqueLoja(&loja, id, qtd);
        }

        if(option == 'V'){
            int id, qtd;
            
            printf("Digite o id do Produto: ");
            scanf("%d\n", &id);

            printf("Digite o numero de unidades: ");
            scanf("%d\n", &qtd);

            vendeProdutoLoja(&loja, id, qtd);
        }

        if(option == 'D'){
            int id;
            float desconto;
            
            printf("Digite o id do Produto: ");
            scanf("%d\n", &id);

            printf("Digite o novo desconto: ");
            scanf("%f\n", &desconto);

            atualizaDescontoLoja(&loja, id, desconto);
        }

        if(option == 'I'){
            imprimeProdutosLoja(&loja);
        }

        if(option == 'F'){
            break;
        }

        printf("\n");
    }

    return 0;
}