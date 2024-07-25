#ifndef _MISSIL_H_
#define _MISSIL_H_

#define MAX_MISSEIS 100

typedef struct{
    int id;
    float X, Y;
    float poder;
}tMissil;

tMissil criaMissil();

void printaMissil(tMissil m);

#endif