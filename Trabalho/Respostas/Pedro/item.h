#ifndef _ITEM_H
#define _ITEM_H

#include "produto.h"

typedef struct Item tItem;

tItem *criaItem(tProduto *produto, int quantidade);

void incrementaQtdItem(tItem *item, int quantidade);

int checaDisponibilidadeItem(tItem *item);

void atualizaDisponibilidadeItem(tItem *item);

void decrementaQtdItem(tItem *item, int quantidade);

int comparaItem(tItem *item1, tItem *item2);

char *getNomeItem(tItem *item);

int getQtdItem(tItem *item);

char *getIdItem(tItem *item);

float getPrecoItem(tItem *item);

void printaFisicoItem(tItem *item);

void printaDigitalItem(tItem *item, char *email);

void avaliaItem(tItem *item, char *cpf);

void liberaItem(tItem *item);

#endif