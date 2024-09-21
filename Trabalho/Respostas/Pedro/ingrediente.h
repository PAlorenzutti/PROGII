#ifndef _INGREDIENTE_H
#define _INGREDIENTE_H

typedef struct Ingrediente tIngrediente;

tIngrediente *criaIngrediente();

char* getNomeIngrediente(tIngrediente *ingrediente);

int getQuantidade(tIngrediente *ingrediente);

int comparaIngrediente(tIngrediente *ingrediente1, tIngrediente *ingrediente2);

void incrementaQtdIngrediente(tIngrediente *ingrediente, int quantidade);

void decrementaQtdIngrediente(tIngrediente *ingrediente, int quantidade);

void printaIngrediente(tIngrediente *ingrediente);

void liberaIngrediente(tIngrediente *ingrediente);

#endif