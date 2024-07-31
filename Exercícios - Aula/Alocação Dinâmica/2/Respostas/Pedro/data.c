#include "data.h"

void leData(tData *d){
    scanf("%d/%d/%d\n", &d->dia, &d->mes, &d->ano);
}

void printaData(tData *d){
    printf("Data de nascimento: %d/%d/%d\n", d->dia, d->mes, d->ano);
}