#ifndef _CIDADE_H_
#define _CIDADE_H_

#include "defesa.h"
#include "missil.h"

typedef struct{
    float X, Y;
    tDefesa defesas[MAX_DEFESAS];
    int qtdDefesas;
    tMissil misseis[MAX_MISSEIS];
    int qtdMisseis;
}tCidade;

tCidade criaCidade();

void printaCidade(tCidade cidade);

#endif