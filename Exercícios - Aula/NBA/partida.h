#ifndef _PARTIDA_H
#define _PARTIDA_H

#include "constantes.h"

typedef struct{
    char franquiaVisitante[MAX_FRANQUIA_NOME];
    int pontosVisitante;
    char franquiaCasa[MAX_FRANQUIA_NOME];
    int pontosCasa;
}tPartida;

tPartida lerPartida();

#endif
