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
    scanf("%[^\n]%*c", opcao);

    while(strcmp(opcao, "#") != 0){    
        if(!strcmp(opcao, "Cadastrar")){
            locadora = lerCadastroLocadora(locadora);
        }

        if(!strcmp(opcao, "Estoque")){
            consultarEstoqueLocadora(locadora);
            scanf("%[^\n]%*c", opcao);
        }

        if(!strcmp(opcao, "Alugar")){
            locadora = lerAluguelLocadora(locadora);
        }

        if(!strcmp(opcao, "Devolver")){

        }

        scanf("%[^\n]%*c", opcao);
    }
}