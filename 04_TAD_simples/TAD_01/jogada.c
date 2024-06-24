#include <stdio.h>
#include "jogada.h"

tJogada LeJogada(){
    tJogada jogada;
    int x, y, sucesso;

    printf("Digite uma posicao (x e y):\n");
    scanf("%d %d", &x, &y);

    printf("%d %d\n", x, y);

    jogada.x = x;
    jogada.y = y;

    return jogada;
}

int ObtemJogadaX(tJogada jogada){
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada){
    return jogada.y;
}