#include <stdio.h>
#include "jogada.h"

tJogada LeJogada(){
    tJogada jogada;
    int x, y, sucesso;

    scanf("%d %d", x, y);

    jogada.x = x;
    jogada.y = y;

    return jogada;
}