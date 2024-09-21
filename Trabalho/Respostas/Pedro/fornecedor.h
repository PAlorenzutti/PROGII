#ifndef _FORNECEDOR_H
#define _FORNECEDOR_H

#include "ingrediente.h"

typedef struct Fornecedor tFornecedor;

tFornecedor *criaFornecedor();

int comparaFornecedor(tFornecedor *fornecedor1, tFornecedor *fornecedor2);

char *getCnpjFornecedor(tFornecedor *fornecedor);

char *getNomeFornecedor(tFornecedor *fornecedor);

int getQuantidadeIngredienteNome(tFornecedor *fornecedor, char *nome);

void alteraQuantidadeIngredienteNome(tFornecedor *fornecedor, char *nome, int quantidade);

tIngrediente* existeIngrediente(tFornecedor *fornecedor, char *nome);

int existeIngredienteNome(tFornecedor *fornecedor, char *nome);

tIngrediente* existeIngredienteFornecedor(tFornecedor *fornecedor, tIngrediente *ingrediente);

void adicionaIngredienteFornecedor(tFornecedor *fornecedor, tIngrediente *ingrediente);

void printaFornecedor(tFornecedor *fornecedor);

int existeIngredienteComNome(tFornecedor *fornecedor, char *nomeIngrediente);

void printaFornecedorNomeIngrediente(tFornecedor *fornecedor, char *nomeIngrediente, int *quantidadePrintados);

void liberaFornecedor(tFornecedor *fornecedor);

#endif