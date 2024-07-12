#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "locadora.h"
#include "filme.h"

int main(){
    //cria locadora
    tLocadora locadora = criarLocadora();

    //lê a primeira opcao;
    char opcao[20];
    scanf("%[^\n]\n", opcao);

    //sentinelas para operações
    int i = 0; //alugar
    int j = 0; //devolver;

    while(true){    
        if(!strcmp(opcao, "Cadastrar")){
            locadora = lerCadastroLocadora(locadora);
        }

        if(!strcmp(opcao, "Estoque")){
            consultarEstoqueLocadora(locadora);
            scanf("%[^\n]\n", opcao);
        }

        if(!strcmp(opcao, "Alugar")){
            locadora = lerAluguelLocadora(locadora);
            i = 1;
        }

        if(!strcmp(opcao, "Devolver")){
            locadora = lerDevolucaoLocadora(locadora);
            j = 1;
        }

        scanf("%[^\n]\n", opcao);

        if(strcmp(opcao, "#") == 0){
            break;
        }

        printf("\n");
    }

    if(i == 1 && j == 1){
        consultarLucroLocadora(locadora);
    }

    return 0;
}