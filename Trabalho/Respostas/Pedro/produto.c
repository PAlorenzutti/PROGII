#include "produto.h"

#include <stdio.h>
#include <stdlib.h>

struct Produto{
    void *dado;
    
    func_ptr_imprimeFisico imprimeFisico;
    func_ptr_imprimeDigital imprimeDigital;
    func_ptr_libera libera;
    func_ptr_valor valor;
    func_ptr_codProduto codProduto;
    func_ptr_nomeProduto nomeProduto;
    func_ptr_tipoProduto tipoProduto;
    func_ptr_descProduto descProduto;
    func_ptr_disponibilidade disponibilidade;
    func_ptr_atualizaDisponibilidade atualizaDisponibilidade;
    func_ptr_printaProduto printaProduto;

    tAvaliacao **avaliacoes;
    int qtdAvaliacoes;
    float mediaAvaliacoes;
};

tProduto *criaProduto(void *dado, func_ptr_imprimeFisico imprimeFisico, func_ptr_imprimeDigital ImprimeDigital, func_ptr_libera libera, func_ptr_valor valor, func_ptr_codProduto codProduto, func_ptr_nomeProduto nomeProduto, func_ptr_tipoProduto tipoProduto, func_ptr_descProduto descProduto, func_ptr_disponibilidade disponibilidade, func_ptr_atualizaDisponibilidade atualizaDisponibilidade, func_ptr_printaProduto printaProduto){
    tProduto *prod = (tProduto*)malloc(sizeof(tProduto));

    //aloca o dado, sendo prato ou industrializado;
    prod->dado = dado;

    //coloca todas as funções passadas em seus respectivos lugares;
    prod->imprimeFisico = imprimeFisico;
    prod->imprimeDigital = ImprimeDigital;
    prod->libera = libera;
    prod->valor = valor;
    prod->codProduto = codProduto;
    prod->nomeProduto = nomeProduto;
    prod->tipoProduto = tipoProduto;
    prod->descProduto = descProduto;
    prod->disponibilidade = disponibilidade;
    prod->atualizaDisponibilidade = atualizaDisponibilidade;
    prod->printaProduto = printaProduto;

    //inicia avaliações como nada, quantidade como 0 e média como 0;
    prod->avaliacoes = NULL;
    prod->qtdAvaliacoes = 0;
    prod->mediaAvaliacoes = 0;

    return prod;
}

void liberaProduto(tProduto *prod){
    if(prod != NULL){
        if(prod->avaliacoes != NULL){
            //percorre todo o ponteiro de ponteiros "avaliações para ir desalocando cada avaliação"
            for(int i = 0; i < prod->qtdAvaliacoes; i++){
                liberaAvaliacao(prod->avaliacoes[i]);
            }
        }

        //desaloca o ponteiro de ponteiros
        free(prod->avaliacoes);

        //desaloca dado;
        prod->libera(prod->dado);

        //desaloca o ponteiro produto;
        free(prod);
    }
}

void insereAvaliacaoProduto(tProduto *prod, tAvaliacao *avaliacao){
    //aumenta o número de avaliações;
    prod->qtdAvaliacoes++;

    //realoca o ponteiro de ponteiros avaliações para alocar a avaliação passada;
    prod->avaliacoes = (tAvaliacao**)realloc(prod->avaliacoes, sizeof(tAvaliacao*) * (prod->qtdAvaliacoes));

    //coloca no index - 1 a avaliação passada;
    prod->avaliacoes[prod->qtdAvaliacoes - 1] = avaliacao;
}

void imprimeFisico(tProduto *prod, int qtd){
    prod->imprimeFisico(prod->dado, qtd);
}

void imprimeDigital(tProduto *prod, char *email, int qtd){
    prod->imprimeDigital(prod->dado, email, qtd);
}

void *getItemProduto(tProduto *prod){
    return prod->dado;
}

float getValorProduto(tProduto *prod){
    return prod->valor(prod->dado);
}

char *getCodProduto(tProduto *prod){
    return prod->codProduto(prod->dado);
}

char *getNomeProduto(tProduto *prod){
    return prod->nomeProduto(prod->dado);
}

char *getDescProduto(tProduto *prod){
    return prod->descProduto(prod->dado);
}

char getTipoProduto(tProduto *prod){
    return prod->tipoProduto(prod->dado);
}

int getDisponibilidadeProduto(tProduto *prod, int qtd){
    return prod->disponibilidade(prod->dado, qtd);
}

void alteraDisponibilidadeProduto(tProduto *prod, int qtd){
    return prod->atualizaDisponibilidade(prod->dado, qtd);
}

void calculaMediaAvaliacoes(tProduto *prod){
    //calcula a média:
    float somaNotas = 0;
    
    //percorre o vetor de avaliações e imprime o comentário de cada avaliação
    for(int i = 0; i < prod->qtdAvaliacoes; i++){
        //soma o valor da nota ao soma para fazer a média;
        somaNotas += getNotaAvaliacao(prod->avaliacoes[i]);
    }

    //realiza a média;
    prod->mediaAvaliacoes = (float) (somaNotas / prod->qtdAvaliacoes);
}

void printaAvaliacoesProduto(tProduto *produto){
    if(produto->avaliacoes != NULL){   
        //percorre o vetor de avaliações e imprime o comentário de cada avaliação
        for(int i = 0; i < produto->qtdAvaliacoes; i++){
            printf("AVALIACAO #%d: %s\n", i + 1, getComentarioAvaliacao(produto->avaliacoes[i]));
        }

        //calcula a média
        calculaMediaAvaliacoes(produto);

        //printa a média no momento;
        printf("AVALIACAO MEDIA: %.2f.\n", produto->mediaAvaliacoes); 
    }else{
        printf("AVALIACOES INEXISTENTES PARA O PRODUTO CONSULTADO!\n");
    }
}

void printaProduto(tProduto *prod){
    //printa as informações do produto de acordo com o seu tipo;
    prod->printaProduto(prod->dado);

    if(prod->avaliacoes != NULL){
        //calcula a média;
        calculaMediaAvaliacoes(prod);

        //printa a média no momento;
        printf("AVALIACAO MEDIA: %.2f.\n", prod->mediaAvaliacoes);
    }else{
        printf("AVALIACAO MEDIA: NAO DISPONIVEL.\n");
    }
}