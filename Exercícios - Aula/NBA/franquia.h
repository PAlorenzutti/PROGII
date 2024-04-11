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

void somaVitorias(tFranquia *franquias[], int qtdFranquias);

void calculaAproveitamentoFranquia(tFranquia *franquias[], int qtdFranquias);

//Implementar aproveitamento conferencia
void printAproveitamentoConferencia(tFranquia *franquias[], int qtdFranquias, char conferencia[]);

int pesquisarFranquia(tFranquia franquias[], int qtdFranquias, char nomeFranquia[]);

void associarPontosFranquias(tFranquia *franquias[], int qtdFranquias, char franquiaVisitante[], int pontosVisitante, char franquiaCasa[], int pontosCasa);

#endif