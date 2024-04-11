#ifndef _PARTIDA_H
#define _PARTIDA_H

#include "constantes.h"

//TAD
typedef struct{
    char franquiaVisitante[MAX_FRANQUIA_NOME];
    int pontosVisitante;
    char franquiaCasa[MAX_FRANQUIA_NOME];
    int pontosCasa;
}tPartida;

//Funções
tPartida lerPartida();

void obtemDadosPartida(tPartida partida, char *franquiaVisitante, int *pontosVisitante, char *franquiaCasa, int *pontosCasa);

#endif