#include "defesa.h"

#include <stdio.h>

tDefesa criaDefesa(){
    tDefesa d;

    scanf("%d %f %f %c %f %f %d\n", &d.id, &d.X, &d.Y, &d.tipo, &d.tamanho, &d.poder, &d.qtd);

    return d;
}

void printaDefesa(tDefesa d){
    printf("D%d %.2f %.2f %c %.2f %.2f %d\n", d.id, d.X, d.Y, d.tipo, d.tamanho, d.poder, d.qtd);
}