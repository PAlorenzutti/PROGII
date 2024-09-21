#include "fornecedor.h"
#include "ingrediente.h"
#include "constantes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fornecedor{
    char *nome;
    char *cnpj;
    char *telefone;
    char *endereco;
    char *usuario;
    char *senha;

    tIngrediente **ingredientes;
    int qtdIngredientes;
};

tFornecedor *criaFornecedor(){
    tFornecedor *fornecedor = (tFornecedor*)malloc(sizeof(tFornecedor));
    
    //inicializa ingredientes;
    fornecedor->ingredientes = NULL;
    fornecedor->qtdIngredientes = 0;

    //aloca espaço na memória para cada atributo;
    fornecedor->nome = (char*)malloc(sizeof(char) * TAM_NOME);
    fornecedor->cnpj = (char*)malloc(sizeof(char) * TAM_CNPJ);
    fornecedor->telefone = (char*)malloc(sizeof(char) * TAM_TELEFONE);
    fornecedor->endereco = (char*)malloc(sizeof(char) * TAM_ENDERECO);
    fornecedor->usuario = (char*)malloc(sizeof(char) * TAM_USUARIO);
    fornecedor->senha = (char*)malloc(sizeof(char) * TAM_SENHA);

    //lê a linha toda até o '\n'
    char linha[500];
    fgets(linha, 500, stdin);

    //lê os atributos que aparecem na linha
    if(sscanf(linha, "%99[^;]; %18[^;]; %14[^;]; %149[^;]; %14[^;]; %19s\n", fornecedor->nome, fornecedor->cnpj, fornecedor->telefone, fornecedor->endereco, fornecedor->usuario, fornecedor->senha) != 6){
        printf("ATRIBUTO(S) FALTANTE(S), FAVOR INICIAR O CADASTRO NOVAMENTE.\n");
        liberaFornecedor(fornecedor);
        return NULL;
    }

    return fornecedor;
}

int comparaFornecedor(tFornecedor *fornecedor1, tFornecedor *fornecedor2){
    return strcmp(fornecedor1->cnpj, fornecedor2->cnpj);
}

char *getCnpjFornecedor(tFornecedor *fornecedor){
    return fornecedor->cnpj;
}

char *getNomeFornecedor(tFornecedor *fornecedor){
    return fornecedor->nome;
}

int getQuantidadeIngredienteNome(tFornecedor *fornecedor, char *nome){
    tIngrediente *ingrediente = existeIngrediente(fornecedor, nome);
    
    return getQuantidade(ingrediente);
}

void alteraQuantidadeIngredienteNome(tFornecedor *fornecedor, char *nome, int qtd){
    tIngrediente *ingrediente = existeIngrediente(fornecedor, nome);

    decrementaQtdIngrediente(ingrediente, qtd);
}

tIngrediente* existeIngrediente(tFornecedor *fornecedor, char *nome){
    for(int i = 0; i < fornecedor->qtdIngredientes; i++){
        if(!strcmp(nome, getNomeIngrediente(fornecedor->ingredientes[i]))){
            return fornecedor->ingredientes[i];
        }
    }

    return NULL;
}

int existeIngredienteNome(tFornecedor *fornecedor, char *nome){
    for(int i = 0; i < fornecedor->qtdIngredientes; i++){
        if(!strcmp(nome, getNomeIngrediente(fornecedor->ingredientes[i]))){
            //printf("\n\nCOMPAROU %s\n\n", getNomeIngrediente(fornecedor->ingredientes[i]));
            return 1;
        }
    }

    return 0;
}

tIngrediente* existeIngredienteFornecedor(tFornecedor *fornecedor, tIngrediente *ingrediente){
    for(int i = 0; i < fornecedor->qtdIngredientes; i++){
        if(!comparaIngrediente(ingrediente, fornecedor->ingredientes[i])){
            return fornecedor->ingredientes[i];
        }
    }

    return NULL;
}

void adicionaIngredienteFornecedor(tFornecedor *fornecedor, tIngrediente *ingrediente){
    tIngrediente *i = existeIngredienteFornecedor(fornecedor, ingrediente);
    
    //printf("\n\n");

    //se i for diferente de NULL, existe e incrementa
    if(i != NULL){
        incrementaQtdIngrediente(i, getQuantidade(ingrediente));
        liberaIngrediente(ingrediente);

        //printaIngrediente(i);

        printf("INGREDIENTE JA CADASTRADO, ATUALIZANDO QUANTIDADE DISPONIVEL!\n");
    }else{
        fornecedor->qtdIngredientes++;
        fornecedor->ingredientes = (tIngrediente**)realloc(fornecedor->ingredientes, sizeof(tIngrediente*) * (fornecedor->qtdIngredientes));
        fornecedor->ingredientes[fornecedor->qtdIngredientes - 1] = ingrediente;

        //printaIngrediente(ingrediente);

        printf("INGREDIENTE CADASTRADO COM SUCESSO!\n");
    }

    

}

void printaFornecedor(tFornecedor *fornecedor){
    printf("FORNECEDOR: %s (%s)\n", fornecedor->nome, fornecedor->cnpj);

    if(fornecedor->ingredientes != NULL){
        for(int i = 0; i < fornecedor->qtdIngredientes; i++){
            //printa index;
            printf("%d - ", i + 1);

            //printa ingrediente;
            printaIngrediente(fornecedor->ingredientes[i]);
        }
    }
}

int existeIngredienteComNome(tFornecedor *fornecedor, char *nomeIngrediente){
    for(int i = 0; i < fornecedor->qtdIngredientes; i++){
        if(strstr(getNomeIngrediente(fornecedor->ingredientes[i]), nomeIngrediente) != NULL){
            return 1;
        }   
    }

    return 0;
}

void printaFornecedorNomeIngrediente(tFornecedor *fornecedor, char *nomeIngrediente, int *quantidadePrintados){
    printf("FORNECEDOR: %s (%s)\n", fornecedor->nome, fornecedor->cnpj);

    for(int i = 0; i < fornecedor->qtdIngredientes; i++){
        if(strstr(getNomeIngrediente(fornecedor->ingredientes[i]), nomeIngrediente) != NULL){
            //incrementa printados;
            (*quantidadePrintados)++;
            
            //printa index;
            printf("%d - ", *quantidadePrintados);
            //printf("%d - ", i + 1);

            //printa ingrediente;
            printaIngrediente(fornecedor->ingredientes[i]);
        }
    }
}

void liberaFornecedor(tFornecedor *fornecedor){
    //libera ingredientes e seu ponteiro de ponteiros:
    if(fornecedor->ingredientes != NULL){
        for(int i = 0; i < fornecedor->qtdIngredientes; i++){
            liberaIngrediente(fornecedor->ingredientes[i]);
        }     

        free(fornecedor->ingredientes);
    }
    
    free(fornecedor->nome);
    free(fornecedor->cnpj);
    free(fornecedor->telefone);
    free(fornecedor->endereco);
    free(fornecedor->usuario);
    free(fornecedor->senha);

    free(fornecedor);
}