#include "prisioneiro.h"

tPrisioneiro* criaPrisioneiro(char* nome, int pena){
    tPrisioneiro *prisioneiro = malloc(sizeof(tPrisioneiro));

    strcpy(prisioneiro->nome, nome);
    prisioneiro->pena = pena;
    prisioneiro->tempoPassado = 0;

    return prisioneiro;
}

void passaTempoPrisioneiro(tPrisioneiro* prisioneiro){
    prisioneiro->tempoPassado++;
}

void fogePrisioneiro(tPrisioneiro* prisioneiro){
    printf("Detento %s fugiu!\n", prisioneiro->nome);
    desalocaPrisioneiro(prisioneiro);
}

int acabouPenaPrisioneiro(tPrisioneiro* prisioneiro){
    if(prisioneiro->tempoPassado == prisioneiro->pena || prisioneiro->tempoPassado > prisioneiro->pena){
        return 1;
    }else{
        return 0;
    }
}

void liberaPrisioneiroCumpriuPena(tPrisioneiro* prisioneiro){
    printf("Detento %s cumpriu sua pena e foi liberado\n", prisioneiro->nome);
    desalocaPrisioneiro(prisioneiro);
}

void liberaPrisioneiroFimPrograma(tPrisioneiro* prisioneiro){
    printf("Detento %s liberado para finalizar o programa\n", prisioneiro->nome);
    desalocaPrisioneiro(prisioneiro);
}

void desalocaPrisioneiro(tPrisioneiro* prisioneiro){
    free(prisioneiro);
}