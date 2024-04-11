#ifndef _FRANQUIA_H
#define _FRANQUIA_H

#include "constantes.h"

//TAD
typedef struct{
    char nome[MAX_FRANQUIA_NOME];
    char conferencia[MAX_CONF_NOME];
    int vitorias;
    int vitoriasCasa;
    int vitoriasFora;
    int derrotas;
    float aproveitamento;
}tFranquia;

//Funções
tFranquia lerFranquia();

int pesquisarFranquia(tFranquia franquia, int qtdFranquias, char nomeFranquia[]);

tFranquia associarPontosFranquias(tFranquia franquias[], int qtdFranquias, char franquiaVisitante[], char franquiaCasa[], int pontosVisitante, int pontosCasa);

#endif