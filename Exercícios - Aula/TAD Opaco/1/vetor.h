#ifndef _VETOR_H
#define _VETOR_H

typedef struct Vetor tVetor;

int printMenu();

tVetor *criaVetor();

void somaVetores(tVetor *v1, tVetor *v2);

void diferençaVetores(tVetor *v1, tVetor *v2);

void produtoVetores(tVetor *v1, tVetor *v2);

void escalarVetor(tVetor *v);

void printVetor(tVetor *v);

void liberaVetor(tVetor *v);

#endif