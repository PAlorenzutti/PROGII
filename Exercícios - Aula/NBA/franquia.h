#ifndef _FRANQUIA_H
#define _FRANQUIA_H

#include "constantes.h"

//TAD
typedef struct{
    char nome[MAX_FRANQUIA_NOME];
    char conferencia[MAX_CONF_NOME];
    char sigla[5];
    int partidas;
    int vitorias;
    int vitoriasCasa;
    int vitoriasFora;
    int derrotas;
    float aproveitamento;
}tFranquia;

//Funções
tFranquia lerFranquia();

void somaVitoriasFranquias(tFranquia franquias[], int qtdFranquias);

void calculaAproveitamentoFranquias(tFranquia franquias[], int qtdFranquias);

int pesquisarFranquia(tFranquia franquias[], int qtdFranquias, char nomeFranquia[]);

//Implementar aproveitamento conferencia
int somaVitoriasConferencia(tFranquia franquias[], int qtdFranquias, char conferencia[]);

int somaDerrotasConferencia(tFranquia franquias[], int qtdFranquias, char conferencia[]);

void printFranquias(tFranquia franquias[], int qtdFranquias);

void printAproveitamentoConferencias(tFranquia franquias[], int qtdFranquias);

void associarPontosFranquias(tFranquia franquias[], int qtdFranquias, char franquiaVisitante[], int pontosVisitante, char franquiaCasa[], int pontosCasa);

#endif