
#ifndef _LESAO_H
#define _LESAO_H

#include "constantes.h"

//definicao struct lesao
typedef struct {
    char cartaoSus[MAX_TAM_SUS];
    char id[MAX_TAM_ID];
    char diagnostico[MAX_TAM_DIAG];
    char regiao[MAX_TAM_REGIAO];
    int chanceMalig;    
} Lesao;

Lesao lerLesao(); //já foi
void printLesao(Lesao les); //já foi
int consultaLesao(Lesao lesao[], int qtdLesoes, Lesao les); //já foi
void obtemCartaoSusLesao(Lesao les, char cartaoSus[]); //já foi
int chanceCirurgia(Lesao les[], int qtdLes); //já foi

#endif