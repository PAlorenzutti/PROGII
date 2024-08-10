#include <stdio.h>
#include <stdlib.h>

#include "circulo.h"

struct Circulo
{
    float raio;
};

tCirculo *criaCirculo()
{
    tCirculo *c = (tCirculo *) malloc (sizeof(tCirculo));
    scanf("%f\n", &c->raio);
    return c;
}

void liberaCirculo(tCirculo *c)
{
    free(c);
}

float multaCirculo(tCirculo *c)
{
    return(((PI*c->raio*c->raio)/10000.0)*6000.0);
}