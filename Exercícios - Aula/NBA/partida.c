#include "partida.h"
#include <stdio.h>
#include <string.h>

tPartida lerPartida(){
    tPartida p;

    scanf("%s @ %s %d %d\n", p.franquiaVisitante, p.franquiaCasa, &p.pontosVisitante, &p.pontosCasa);

    return p;
}

void obtemDadosPartida(tPartida partida, char franquiaVisitante[], int *pontosVisitante, char franquiaCasa[], int *pontosCasa){
    *pontosVisitante = partida.pontosVisitante;
    *pontosCasa = partida.pontosCasa;
    strcpy(franquiaVisitante, partida.franquiaVisitante);
    strcpy(franquiaCasa, partida.franquiaCasa);
}