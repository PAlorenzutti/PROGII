#include <stdio.h>
#include <stdlib.h>

#include "triangulo.h"

struct Triangulo
{
    float base, altura;
};

tTriangulo *criaTriangulo()
{
    tTriangulo *t = (tTriangulo *) malloc (sizeof(tTriangulo));
    scanf("%f %f\n", &t->base, &t->altura);
    return t;
}

void liberaTriangulo(tTriangulo *t)
{
    free(t);
}

float multaTriangulo(tTriangulo *t)
{
    return((((t->base * t->altura)/2)/10000.0)*7000.0);
}