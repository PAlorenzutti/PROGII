#ifndef _SACOLA_H
#define _SACOLA_H

#include "item.h"

typedef struct Sacola tSacola;

tSacola *criaSacola(char *email, char *cpf);

tItem* existeItemSacola(tSacola *sacola, tItem *item);

void adicionaItemSacola(tSacola *sacola, tItem *item);

int sacolaVazia(tSacola *sacola);

int indexItem(tSacola *sacola, tItem *item);

void removeItem(tSacola *sacola, tItem *item);

void removeItemSacola(tSacola *sacola, tItem *item);

void limpaSacola(tSacola *sacola);

void adicionaItemCompra(tSacola *compra, tItem *item);

int efetuaCompraSacola(tSacola *sacola, tSacola *compra);

void atualizaPrecoSacola(tSacola *sacola);

void atualizaSacolaPosCompra(tSacola *sacola, tSacola *compra);

void printaNotaFiscal(tSacola *compra);

void printaSacola(tSacola *sacola);

void liberaCompra(tSacola *compra);

int menuAvaliacoes(tSacola *compra);

void avaliaItensComprados(tSacola *compra);

void liberaSacola(tSacola *sacola);

#endif