#include <stdio.h>
#include "jogada.h"

tJogada LeJogada(){
    tJogada jogada;
    int x, y, sucesso;

    printf("Digite uma posicao (x e y):\n");
    scanf("%d %d\n", &x, &y);
    sucesso = 1;

    jogada.x = x;
    jogada.y = y;
    jogada.sucesso = 1;

    return jogada;
}

int ObtemJogadaX(tJogada jogada){
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada){
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada){
    return jogada.sucesso;
}