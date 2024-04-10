#ifndef _FRANQUIA_H
#define _FRANQUIA_H

#include "constantes.h"

typedef struct{
    char nome[MAX_FRANQUIA_NOME];
    char conferencia[MAX_CONF_NOME];
    int vitorias;
    int vitoriasCasa;
    int vitoriasFora;
    int derrotas;
    float aproveitamento;
}tFranquia;

tFranquia lerFranquia();
//implementar um obtem dados partida
tFranquia associarPontosFranquias(tFranquia franquias[], char timeVisitante[], char timeCasa[], int pontosVisitante, int pontosCasa);

#endif