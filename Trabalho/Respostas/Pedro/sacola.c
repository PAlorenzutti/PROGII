#include "sacola.h"

#include "constantes.h"
#include "item.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sacola{
    tItem **itens;
    int qtdItens;

    char *email;
    char *cpf;

    float total;
};

tSacola *criaSacola(char *email, char *cpf){
    tSacola *sacola = (tSacola*)malloc(sizeof(tSacola));

    sacola->cpf = cpf;
    sacola->email = email;

    sacola->itens = NULL;
    sacola->qtdItens = 0;

    sacola->total = 0;

    return sacola;
}

tItem* existeItemSacola(tSacola *sacola, tItem *item){
    for(int i = 0; i < sacola->qtdItens; i++){
        //se os itens forem iguais, retorna o item em questão;
        if(!comparaItem(sacola->itens[i], item)){
            return sacola->itens[i];
        }
    }

    //se não encontrar, retorna NULL;
    return NULL;
}

int sacolaVazia(tSacola *sacola){
    //se o número de itens for diferente de 0, retorna não
    if(sacola->qtdItens > 0){
        //sim
        return 0;
    }else{
        //não
        return 1;
    }
}

void atualizaPrecoSacola(tSacola *sacola){
    //reinicia o valor de sacola;
    sacola->total = 0;
    
    for(int i = 0; i < sacola->qtdItens; i++){
        sacola->total += getPrecoItem(sacola->itens[i]) * getQtdItem(sacola->itens[i]);
    }
}

void adicionaItemSacola(tSacola *sacola, tItem *item){
    //verifica se não já existe o item em questão na sacola;
    tItem *i = existeItemSacola(sacola, item);

    //se existir
    if(i != NULL){
        //incrementa
        incrementaQtdItem(i, getQtdItem(item));
        liberaItem(item);
    }else{
        //adiciona item na sacola
        sacola->qtdItens++;
        sacola->itens = (tItem**)realloc(sacola->itens, sizeof(tItem*) * sacola->qtdItens);
        sacola->itens[sacola->qtdItens - 1] = item;
    }

    //atualiza preço da sacola
    atualizaPrecoSacola(sacola);

    printaSacola(sacola);
}

int indexItem(tSacola *sacola, tItem *item){
    //procura o index do item na sacola
    for(int i = 0; i < sacola->qtdItens; i++){
        if(!comparaItem(item, sacola->itens[i])){
            return i;
        }
    }

    //se não encontrar, retorna -1;
    return -1;
}

void removeItem(tSacola *sacola, tItem *item){
    //libera o item da sacola com o index encontrado;
    int index = indexItem(sacola, item);
    liberaItem(sacola->itens[index]);

    //desloca os itens posteriores a ele para posição - 1;
    for(int i = index; i < sacola->qtdItens - 1; i++){
        sacola->itens[i] = sacola->itens[i + 1];
    }

    //diminui a quantidade de itens e realoca;
    sacola->qtdItens--;
    
    //se a quantidade de produtos for igual a 0:
    sacola->itens = (tItem**)realloc(sacola->itens, sizeof(tItem*) * sacola->qtdItens);
}

void removeItemSacola(tSacola *sacola, tItem *item){
    //verifica se não já existe o item em questão na sacola;
    tItem *i = existeItemSacola(sacola, item);

    //se existir
    if(i != NULL){
        //se a quantidade atual menos a passada ainda for maior que 0, apenas decrementa;
        if(getQtdItem(i) - getQtdItem(item) > 0){
            decrementaQtdItem(i, getQtdItem(item));
        }else{
            //remove o item da sacola;
            removeItem(sacola, i);
        }

        printf("O PRODUTO FOI REMOVIDO DA SACOLA DE COMPRAS!\n");

        liberaItem(item);
    }else{
        //printa mensagem de que o item não existe na sacola
        printf("O PRODUTO NAO ESTA PRESENTE NA SACOLA DE COMPRAS!\n");
        liberaItem(item);
    }

    //atualiza preço da sacola
    atualizaPrecoSacola(sacola);

    printaSacola(sacola);
}

void adicionaItemCompra(tSacola *compra, tItem *item){
    //adiciona item ao vetor de compras;
    compra->qtdItens++;
    compra->itens = (tItem**)realloc(compra->itens, sizeof(tItem*) * compra->qtdItens);
    compra->itens[compra->qtdItens - 1] = item;

    //atualiza disponibilidade de item;
    atualizaDisponibilidadeItem(item);
}

int efetuaCompraSacola(tSacola *sacola, tSacola *compra){
    for(int i = 0; i < sacola->qtdItens; i++){
        //printa checando
        //printf("\n\nCHECANDO PRODUTO %d:\n", i + 1);
        
        //se o item da sacola estiver disponível;
        if(checaDisponibilidadeItem(sacola->itens[i])){
            //adiciona item no comprados;
            adicionaItemCompra(compra, sacola->itens[i]);

            //atualiza preço da compra;
            atualizaPrecoSacola(compra);
        }else{
            printf("PRODUTO %s ESTA INDISPONIVEL NO MOMENTO!\n", getIdItem(sacola->itens[i]));
        }
    }

    int encerra = 0;

    //se o número de comprados for igual ao número de itens que tinha na sacola
    if(compra->qtdItens == sacola->qtdItens){
        printf("COMPRA EFETUADA COM SUCESSO!\n");
        printaNotaFiscal(compra);
        encerra = menuAvaliacoes(compra);
    }
    
    //se o número de comprados for menor que o número de itens que tinha na sacola, porém diferente de 0;
    if((compra->qtdItens > 0) && (compra->qtdItens < sacola->qtdItens)){
        printf("COMPRA EFETUADA COM SUCESSO (PARCIALMENTE)!\n");
        printaNotaFiscal(compra);
        encerra = menuAvaliacoes(compra);
    }

    //se o número de comprados for 0;
    if(compra->qtdItens == 0){
        printf("COMPRA CANCELADA POR INDISPONIBILIDADE DE PRODUTOS!\n");
    }

    atualizaSacolaPosCompra(sacola, compra);

    return encerra;
}

int menuAvaliacoes(tSacola *compra){
    printf("DESEJA REALIZAR A AVALIAÇÃO DO(S) PRODUTO(S) COMPRADO(S)? (SIM/NAO/OUT)\n");

    char opcao[TAM_OPERACOES];
    scanf("%3s\n", opcao);

    if(!strcmp(opcao, SIM)){
        //efetua avaliações sobre todos os produtos comprados;
        avaliaItensComprados(compra);
        return 0;
    }

    if(!strcmp(opcao, NAO)){
        //não faz nada;
        return 0;
    }

    if(!strcmp(opcao, SAIDA)){
        //encerra o programa;
        return 1;
    }

    return 0;
}

void avaliaItensComprados(tSacola *compra){
    for(int i = 0; i < compra->qtdItens; i++){
        //avalia cada item separadamente;
        avaliaItem(compra->itens[i], compra->cpf);
    }
}

void atualizaSacolaPosCompra(tSacola *sacola, tSacola *compra){
    //remove produtos comprados da sacola;
    for(int i = 0; i < compra->qtdItens; i++){
        for(int j = 0; j < sacola->qtdItens; j++){
            if(!comparaItem(compra->itens[i], sacola->itens[j])){
                removeItem(sacola, sacola->itens[j]);
                j--;
                break;
            }
        }
    }

    liberaCompra(compra);
}

void printaNotaFiscal(tSacola *compra){
    printf("------------------------------------------\n");
    printf("NOTA FISCAL DE COMPRA:\n");
    printf("------------------------------------------\n");
    
    for(int i = 0; i < compra->qtdItens; i++){
        printaFisicoItem(compra->itens[i]);
        printf("\n");
        printaDigitalItem(compra->itens[i], compra->email);
        printf("------------------------------------------\n");
    }
    
    printf("VALOR TOTAL DA NOTA FISCAL: %.2f\n", compra->total);
    printf("------------------------------------------\n");
}

void limpaSacola(tSacola *sacola){
    //remove item um por um;
    for(int i = 0; i < sacola->qtdItens; i++){
        removeItem(sacola, sacola->itens[i]);
    }

    //atualiza a quantidade de item;
    sacola->qtdItens = 0;

    printf("SACOLA DE COMPRAS ESVAZIADA!\n");
}

void printaSacola(tSacola *sacola){
    printf("SACOLA DE COMPRAS:\n");

    for(int i = 0; i < sacola->qtdItens; i++){
        printf("PRODUTO %s, %s, %d UNIDADE(S)\n", getIdItem(sacola->itens[i]), getNomeItem(sacola->itens[i]), getQtdItem(sacola->itens[i]));
    }

    printf("(TOTAL: R$ %.2f)\n", sacola->total);
}

void liberaCompra(tSacola *compra){
    //se a sacola não estiver vazia, libera os vetores;
    if(compra->itens != NULL){
        free(compra->itens);
        compra->itens = NULL;
    }

    free(compra);
}

void liberaSacola(tSacola *sacola){
    //se a sacola não estiver vazia, esvazia os itens;
    if(sacola->itens != NULL){
        //libera item por item;
        for(int i = 0; i < sacola->qtdItens; i++){
            liberaItem(sacola->itens[i]);
            sacola->itens[i] = NULL;
        }

        //libera vetor item;
        free(sacola->itens);
        sacola->itens = NULL;
    }
    
    free(sacola);
}