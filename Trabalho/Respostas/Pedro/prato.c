#include "prato.h"
#include "fornecedor.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_CODIGO 15
#define TAM_NOME 20
#define TAM_DESCRICAO 100
#define TAM_INGREDIENTE 100

struct Prato{
    char *codigo;
    char *nome;
    char *descricao;
    float valor;
    char **ingredientes;
    int qtdIngredientes;

    tFornecedor **fornecedores;
    int *qtdFornecedores;
};

tPrato *criaPrato(tFornecedor **fornecedores, int *qtdFornecedores){
    tPrato *prato = (tPrato*)malloc(sizeof(tPrato));

    //alocando espaço para atributos de char;
    prato->codigo = (char*)malloc(sizeof(char) * TAM_CODIGO);
    prato->nome = (char*)malloc(sizeof(char) * TAM_NOME);
    prato->descricao = (char*)malloc(sizeof(char) * TAM_DESCRICAO);

    //inicializando prato
    prato->ingredientes = NULL;
    prato->qtdIngredientes = 0;

    //guarda as informações de fornecedores
    prato->fornecedores = fornecedores;
    prato->qtdFornecedores = qtdFornecedores;

    //lê a linha toda até o '\n'
    char linha[500];
    fgets(linha, 500, stdin);

    //lê todos os atributos e já confere se leu corretamente;
    if(sscanf(linha, "%14[^;]; %19[^;]; %99[^;]; %f\n", prato->codigo, prato->nome, prato->descricao, &prato->valor) != 4){
        printf("ATRIBUTO(S) FALTANTE(S), FAVOR INICIAR O CADASTRO NOVAMENTE.\n");
        liberaPrato(prato);
        return NULL;
    }

    return prato;
}

void leIngredientes(tPrato *prato){
    scanf("%d; ", &prato->qtdIngredientes);

    //aloca o ponteiro de ponteiros com o número de ingredientes;
    prato->ingredientes = (char**)malloc(sizeof(char*) * prato->qtdIngredientes);

    //aloca cada string do ponteiro de ponteiro com o TAM_NOME e lê;
    for(int i = 0; i < prato->qtdIngredientes; i++){
        prato->ingredientes[i] = (char*)malloc(sizeof(char) * TAM_INGREDIENTE);
        
        if(i == prato->qtdIngredientes - 1){
            scanf("%99[^\n]", prato->ingredientes[i]);
        }else{
            scanf("%99[^;]; ", prato->ingredientes[i]);
        }
    }
}

char **getIngredientesPrato(tPrato *prato){
    return prato->ingredientes;
}

int getQtdIngredientesPrato(tPrato *prato){
    return prato->qtdIngredientes;
}

void imprimeFisicoPrato(void *dado, int qtd){
    //faz o typecast do void *dado;
    tPrato *p = (tPrato*) dado;

    printf("IMPRESSAO NF FISICA DE PRATO:\n");
    printf("ID DO PRATO: %s\n", p->codigo);
    printf("NOME DO PRATO: %s\n", p->nome);
    printf("DESCRICAO DO PRATO: %s\n", p->descricao);
    printf("VALOR DO PRATO: %.2f\n", p->valor);
    printf("QUANTIDADE: %d\n", qtd);
    printf("VALOR FINAL DO PRATO: %.2f\n", p->valor * qtd);
}

void imprimeDigitalPrato(void *dado, char *email, int qtd){
    //faz o typecast do void *dado;
    tPrato *p = (tPrato*) dado;

    printf("IMPRESSAO NF DIGITAL DE PRATO:\n");
    printf("E-MAIL DE ENVIO: %s\n", email);
    printf("ID DO PRATO: %s\n", p->codigo);
    printf("NOME DO PRATO: %s\n", p->nome);
    printf("DESCRICAO DO PRATO: %s\n", p->descricao);
    printf("VALOR DO PRATO: %.2f\n", p->valor);
    printf("QUANTIDADE: %d\n", qtd);
    printf("VALOR FINAL DO PRATO: %.2f\n", p->valor * qtd);
}

float getValorPrato(void *dado){
    //faz o typecast do void *dado;
    tPrato *p = (tPrato*) dado;

    return p->valor;
}

char* getCodPrato(void *dado){
    //faz o typecast do void *dado;
    tPrato *p = (tPrato*) dado;

    return p->codigo;
}

char* getDescPrato(void *dado){
    //faz o typecast do void *dado;
    tPrato *p = (tPrato*) dado;

    return p->descricao;
}

char getTipoPrato(void *dado){
    return 'P';
}

char * getNomePrato(void *dado){
    //faz o typecast do void *dado;
    tPrato *p = (tPrato*) dado;

    return p->nome;
}

int getDisponibilidadePrato(void *dado, int qtd){
    //faz o typecast do void *dado;
    tPrato *p = (tPrato*) dado;

    //printaPrato(p);
    //printf(" QUANTIDADE EXIGIDA: %d", qtd);
    //printf("\n\n");
    
    
    
    //printa disponibilidade de ingredientes de cada fornecedor;
    /*
    printf("\n\nFORNECEDORES:\n");
    for(int i = 0; i < *p->qtdFornecedores; i++){
        printaFornecedor(p->fornecedores[i]);
    }
    printf("\n\n");
    */

    //cria um vetor pra armazenar quanto tem de cada ingrediente;
    int quantidade[p->qtdIngredientes];

    //inicializa o vetor com zero para cada ingrediente;
    for(int i = 0; i < p->qtdIngredientes; i++){
        quantidade[i] = 0;
    }

    //incrementa a quantidade de ingredientes pra cada pesquisa;
    for(int i = 0; i < p->qtdIngredientes; i++){
        for(int j = 0; j < *p->qtdFornecedores; j++){
            //verifica se existe esse ingrediente no fornecedor específico;
            if(existeIngredienteNome(p->fornecedores[j], p->ingredientes[i])){
                //incrementa a quantidade desse ingrediente
                quantidade[i] += getQuantidadeIngredienteNome(p->fornecedores[j], p->ingredientes[i]);
            }
        }
    }

    //printa a quantidade dos ingredientes
    /*
    printf("\n\nQUANTIDADE INGREDIENTES DE CADA:\n");
    for(int i = 0; i < p->qtdIngredientes; i++){
        printf("%s: %d\n", p->ingredientes[i], quantidade[i]);
    }
    printf("\n\n");
    */

    //pega a menor de ingredientes do vetor;
    int menor = quantidade[0];

    for(int i = 0; i < p->qtdIngredientes; i++){
        if(quantidade[i] < menor){
            menor = quantidade[i];
        }
    }

    //retorna o ingrediente com menor quantidade (fator limitante para fazer o prato) menos a quantidade exigida;
    return menor - qtd;
}

//aqui é certeza que o prato está disponível
void alteraDisponibilidadePrato(void *dado, int qtd){
    //faz o typecast do void *dado;
    tPrato *p = (tPrato*) dado;

    //incrementa a quantidade de ingredientes pra cada pesquisa;
    for(int i = 0; i < p->qtdIngredientes; i++){
        //inicia a quantidade pela quantidade requisitada;
        int quantidade = qtd;
        
        for(int j = 0; j < *p->qtdFornecedores; j++){
            //verifica se existe esse ingrediente no fornecedor específico;
            if(existeIngredienteNome(p->fornecedores[j], p->ingredientes[i])){
                //atualiza esse ingrediente, conforme a quantidade passada;
                int quantidadeFornecedor = getQuantidadeIngredienteNome(p->fornecedores[j], p->ingredientes[i]);

                if(quantidadeFornecedor >= quantidade){
                    //se tiver mais do que o necessário, apenas diminui a qtd desse ingrediente no fornecedor e sai da busca desse ingrediente em fornecedores;
                    alteraQuantidadeIngredienteNome(p->fornecedores[j], p->ingredientes[i], quantidade);
                    break;
                }else{
                    //se tiver menor do que o necessário, usa toda a qtd de ingrediente no fornecedor e continua em busca do próximo;
                    alteraQuantidadeIngredienteNome(p->fornecedores[j], p->ingredientes[i], quantidadeFornecedor);

                    //atualiza a quantidade que falta;
                    quantidade -= quantidadeFornecedor;
                }
            }
        }
    }
}

void printaPrato(void *dado){
    //faz o typecast do void *dado;
    tPrato *p = (tPrato*) dado;

    printf("%s, %s, %s, P, R$%.2f. ", p->nome, p->codigo, p->descricao, p->valor);

    if(p->ingredientes != NULL){
        printf("INGREDIENTES: ");

        for(int i = 0; i < p->qtdIngredientes; i++){
            if(i != p->qtdIngredientes - 1){
                printf("%s, ", p->ingredientes[i]);
            }else{
                printf("%s. ", p->ingredientes[i]);
            }
        }
    }
}

void liberaPrato(void *prato){
    //faz o typecast do void *dado;
    tPrato *p = (tPrato*) prato;

    //libera ingredientes e seu ponteiro de ponteiro;
    if(p->ingredientes != NULL){
        for(int i = 0; i < p->qtdIngredientes; i++){
            free(p->ingredientes[i]);
        }

        free(p->ingredientes);
    }

    //libera cada vetor de caracteres separado;
    free(p->codigo);
    free(p->nome);
    free(p->descricao);

    //libera o ponteiro prato;
    free(p);
}