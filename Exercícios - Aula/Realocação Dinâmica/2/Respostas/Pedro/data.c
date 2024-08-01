#include "data.h"

void leData(tData *d){
    scanf("%d/%d/%d\n", &d->dia, &d->mes, &d->ano);
}

void printaData(tData *d){
    printf("Data de nascimento: %02d/%02d/%02d\n", d->dia, d->mes, d->ano);
}