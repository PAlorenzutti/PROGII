#include "missil.h"

#include <stdio.h>

tMissil criaMissil(){
    tMissil m;

    scanf("%d %f %f %f\n", &m.id, &m.X, &m.Y, &m.poder);

    return m;
}

void printaMissil(tMissil m){
    printf("M%d %.2f %.2f %.2f\n", m.id, m.X, m.Y, m.poder);
}