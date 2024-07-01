#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "locadora.h"
#include "filme.h"

int main(){
    //cria locadora
    tLocadora locadora = criarLocadora();

    //lê a primeira opcao;
    char opcao[50];
    scanf("%[^\n]%*c", opcao);

    while(strcmp(opcao, "#") != 0){    
        if(!strcmp(opcao, "Cadastrar")){
            locadora = lerCadastroLocadora(locadora);
        }

        if(!strcmp(opcao, "Estoque")){
            consultarEstoqueLocadora(locadora);
        }

        if(!strcmp(opcao, "Alugar")){

        }

        if(!strcmp(opcao, "Devolver")){

        }

        scanf("%[^\n]%*c", opcao);
    }
}