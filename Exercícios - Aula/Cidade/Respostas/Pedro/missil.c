#include "missil.h"

#include <stdio.h>

tMissil criaMissil(){
    tMissil m;

    scanf("%d %f %f %f\n", &m.id, &m.X, &m.Y, &m.poderAtaque);

    return m;
}

float getAbscMissil(tMissil m){
    return m.X;
}

float getOrdeMissil(tMissil m){
    return m.Y;
}

tMissil atualizaMissil(tMissil m, float poderDefesa){
    //essa diferença representa o dano causado
    if(m.poderAtaque - poderDefesa < 0){
       m.poderAtaque = 0;
    }else{
        m.poderAtaque -= poderDefesa;
    }

    return m;
}

void printaMissil(tMissil m){
    printf("M%d: %.2f\n", m.id, m.poderAtaque);
    //printf("M%d %.2f %.2f %.2f\n", m.id, m.X, m.Y, m.poderAtaque);
}