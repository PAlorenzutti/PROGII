#ifndef _MISSIL_H_
#define _MISSIL_H_

#define MAX_MISSEIS 100

typedef struct{
    int id;
    float X, Y;
    float poderAtaque;
}tMissil;

tMissil criaMissil();

float getAbscMissil(tMissil m);

float getOrdeMissil(tMissil m);

tMissil atualizaMissil(tMissil m, float poderDefesa);

void printaMissil(tMissil m);

#endif