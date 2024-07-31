#ifndef _DATA_H
#define _DATA_H

#include <stdio.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}tData;

void leData(tData *d);


void printaData(tData *d);

#endif