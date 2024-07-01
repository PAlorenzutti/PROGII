#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "locadora.h"
#include "filme.h"

int main(){
    
    //lê a primeira opcao;
    char opcao[50];
    scanf("%[^\n]%*c", opcao);

    while(strcmp(opcao, "#") != 0){    
        if(!strcmp(opcao, "Cadastrar")){
            printf("entrou Cadastrar");
        }

        if(!strcmp(opcao, "Estoque")){
            printf("entrou Estoque");
        }

        if(!strcmp(opcao, "Alugar")){
            printf("entrou Alugar");
        }

        if(!strcmp(opcao, "Devolver")){
            printf("entrou Devolver");
        }

        scanf("%[^\n]%*c", opcao);
    }
}