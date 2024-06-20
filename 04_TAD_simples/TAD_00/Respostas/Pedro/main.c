#include <stdio.h>
#include "ponto.h"

int main(){
    float x, y;

    //lendo ponto 1
    scanf("%f %f", &x, &y);

    //criando ponto 1
    Ponto p1 = pto_cria(x, y);

    //lendo ponto 2
    scanf("%f %f", &x, &y);

    //criando ponto 2
    Ponto p2 = pto_cria(x, y);

    printf("%g", pto_distancia(p1, p2));

    return 0;
}