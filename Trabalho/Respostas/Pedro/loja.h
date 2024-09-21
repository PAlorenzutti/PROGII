#ifndef _LOJA_H
#define _LOJA_H

#include "produto.h"

typedef struct Loja tLoja;

tLoja *criaLoja();

int comparaLoja(tLoja *loja1, tLoja *loja2);

char *getNomeLoja(tLoja *loja);

char *getCnpjLoja(tLoja *loja);

char *getTelefoneLoja(tLoja *loja);

char *getEnderecoLoja(tLoja *loja);

void adicionaProdutoLoja(tLoja *loja, tProduto *produto);

tProduto *existeProdutoLoja(tLoja* loja, char *codigo);

int existeProdutoNomeLoja(tLoja *loja, char *nome);

void printaProdutosNomeLoja(tLoja *loja, char *nome, int *quantidadeProdutos);

int existeProdutoTipoLoja(tLoja *loja, char tipo);

void printaProdutosTipoLoja(tLoja *loja, char tipo, int *quantidadeProdutos);

int existeProdutosLoja(tLoja *loja);

void printaProdutosLoja(tLoja *loja, int *quantidadeProdutos);

void printaLoja(tLoja *loja);

void liberaLoja(tLoja *loja);

#endif