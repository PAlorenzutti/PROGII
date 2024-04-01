#ifndef _MULTA_H
#define _MULTA_H

#define PI 3.1416

typedef struct{
    float raio;
}tCirculo;

typedef struct{
    float comprimento;
    float largura;
}tRetangulo;

typedef struct{
    float base;
    float altura;
}

float multaCircular(tCirculo c);
float multaRetangular(tRetangulo r);
float multaTriangular(tTriangulo t);

#endif
