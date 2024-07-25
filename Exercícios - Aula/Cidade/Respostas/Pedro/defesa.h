#ifndef _DEFESA_H_
#define _DEFESA_H_

#define MAX_DEFESAS 100

typedef struct{
    int id;
    float X, Y;
    char tipo;
    float tamanho;
    float poder;
    int qtd;
}tDefesa;

tDefesa criaDefesa();

void printaDefesa(tDefesa d);

#endif