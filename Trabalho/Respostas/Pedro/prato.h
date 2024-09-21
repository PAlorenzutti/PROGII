#ifndef _PRATO_H
#define _PRATO_H

#include "fornecedor.h"

typedef struct Prato tPrato;

tPrato *criaPrato(tFornecedor **fornecedores, int *qtdFornecedores);

void leIngredientes(tPrato *prato);

char **getIngredientesPrato(tPrato *prato);

int getQtdIngredientesPrato(tPrato *prato);

void imprimeFisicoPrato(void *dado, int qtd);

void imprimeDigitalPrato(void *dado, char *email, int qtd);

int getDisponibilidadePrato(void *dado, int qtd);

void alteraDisponibilidadePrato(void *dado, int qtd);

float getValorPrato(void *dado);

char *getCodPrato(void *dado);

char *getDescPrato(void *dado);

char getTipoPrato(void *dado);

char *getNomePrato(void *dado);

void printaPrato(void *dado);

void liberaPrato(void *prato);

#endif