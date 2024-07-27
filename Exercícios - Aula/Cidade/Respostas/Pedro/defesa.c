#include "defesa.h"

#include <stdio.h>
#include <math.h>

tDefesa criaDefesa(){
    tDefesa d;

    scanf("%d %f %f %c %f %f %d\n", &d.id, &d.X, &d.Y, &d.tipo, &d.tamanho, &d.poderDefesa, &d.qtd);

    return d;
}

int verificaAtingiuDefesa(tDefesa d, tMissil m, opCallback verifica){
    return verifica(d, m);
}

int verificaAreaCirculo(tDefesa d, tMissil m){
    //ponto 1 = defesa
    float x1 = d.X;
    float y1 = d.Y;

    //ponto 2 = missil
    float x2 = getAbscMissil(m);
    float y2 = getOrdeMissil(m);

    //distancia euclidiana entre ponto 1 e ponto2
    float distancia = sqrt( pow(x1 - x2, 2) + pow(y1 - y2, 2) );

    //se a distancia for menor ou igual ao raio;
    if(distancia <= d.tamanho){
        return 1;
    }else{
        return 0;
    }
}

int verificaAreaQuadrado(tDefesa d, tMissil m){
    //ponto = missil
    float x = getAbscMissil(m);
    float y = getOrdeMissil(m);

    //pegar o tamanho do lado do quadrado;
    float lado = (d.tamanho * sqrt(2));

    //pegando os limites do quadrado, a partir do centro;
    float menorX = d.X - (lado / 2);
    float maiorX = d.X + (lado / 2);
    float menorY = d.Y - (lado / 2);
    float maiorY = d.Y + (lado / 2);

    //se estiver dentro dos limites retorna 1
    if( (x >= menorX && x <= maiorX) && (y >= menorY && y <= maiorY) ){
        return 1;
    }else{
        return 0;
    }
}

char getTipoDefesa(tDefesa d){
    return d.tipo;
}

int getQtdMissilDefesa(tDefesa d){
    return d.qtd;
}

float getPoderDefesa(tDefesa d){
    return d.poderDefesa;
}

tDefesa atualizaDefesa(tDefesa d){
    d.qtd--;

    return d;
}

void printaDefesa(tDefesa d){
    printf("D%d: %d\n", d.id, d.qtd);
    //printf("D%d %.2f %.2f %c %.2f %.2f %d\n", d.id, d.X, d.Y, d.tipo, d.tamanho, d.poder, d.qtd);
}