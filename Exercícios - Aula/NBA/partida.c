#include "partida.h"

tPartida lerPartida(){
    tPartida p;

    scanf("%s @ %s %d %d\n", p.franquiaVisitante, p.franquiaCasa, p.pontosVisitante, p.pontosCasa);
}