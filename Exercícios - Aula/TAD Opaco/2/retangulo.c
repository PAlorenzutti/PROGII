#include <stdio.h>
#include <stdlib.h>

#include "retangulo.h"

struct Retangulo
{
    float comprimento, largura;
};

tRetangulo *criaRetantulo()
{
    tRetangulo *r = (tRetangulo *) malloc (sizeof(tRetangulo));
    scanf("%f %f\n", &r->comprimento, &r->largura);
    return r;
}

void liberaRetangulo(tRetangulo *r)
{
    free(r);
}

float multaRetangulo(tRetangulo *r)
{
    return(((r->comprimento * r->largura)/10000.0)*8000.0);
}