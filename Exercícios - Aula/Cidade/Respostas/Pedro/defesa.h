#ifndef _DEFESA_H_
#define _DEFESA_H_

#define MAX_DEFESAS 100

#include "missil.h"

typedef struct{
    int id;
    float X, Y;
    char tipo;

    //raio, se C
    //metade da diagonal do quadrado, se Q
    float tamanho;

    float poderDefesa;
    int qtd;
}tDefesa;

typedef int (*opCallback) (tDefesa, tMissil);

tDefesa criaDefesa();

int verificaAtingiuDefesa(tDefesa d, tMissil m, opCallback verifica);

int verificaAreaCirculo(tDefesa d, tMissil m);

int verificaAreaQuadrado(tDefesa d, tMissil m);

char getTipoDefesa(tDefesa d);

int getQtdMissilDefesa(tDefesa d);

float getPoderDefesa(tDefesa d);

tDefesa atualizaDefesa(tDefesa d);

void printaDefesa(tDefesa d);

#endif