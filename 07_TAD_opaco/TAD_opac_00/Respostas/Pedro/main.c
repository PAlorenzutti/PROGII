#include "circulo.h"
#include "ponto.h"

#include <stdio.h>

int main(){
    float x, y, r;
    scanf("%f %f %f ", &x, &y, &r);
    tCirculo c = Circulo_Cria(x, y, r);


    scanf("%f %f", &x, &y);
    tPonto p = Pto_Cria(x, y);

    printf("%d", Circulo_Interior(c, p));

    Circulo_Apaga(c);
    Pto_Apaga(p);

    return 0;
}