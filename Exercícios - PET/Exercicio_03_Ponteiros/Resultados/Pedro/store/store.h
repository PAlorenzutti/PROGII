#ifndef _STORE_H_
#define _STORE_H_

#include "product.h"

#define MAX_PRODUCTS 50

typedef struct store{
    tProduct produtos[MAX_PRODUCTS];
    int nmProdutos;
} tStore;

/**
 * @brief Inicia uma struct do tipo tLoja, inicializando seus parâmetros.
 * @param loja O endereço da loja.
*/
void abreLoja(tStore *loja);

/**
 * @brief Adiciona um novo produto à loja.
 * @param loja O endereço da loja.
 * @param produto O produto.
*/
void adicionaProduto(tStore *loja, tProduct produto);

/**
 * @brief Varre a loja em busca do produto com o id desejado.
 * Retorna -1 caso não tenha sido encontrado.
 * @param loja O endereço da loja.
 * @param id O id do produto procurado.
 * @return O produto.
*/
int buscaProduto(tStore *loja, int id);

/**
 * @brief Aumenta o estoque de um produto da loja.
 * @param loja O endereço da loja.
 * @param id O id do produto.
 * @param qtd A quantidade a ser adicionada ao estoque do produto.
*/
void aumentaEstoqueLoja(tStore *loja, int id, int qtd);

/**
 * @brief Realiza a venda de um produto de uma loja.
 * @param loja O endereço da loja.
 * @param id O id do produto.
 * @param qtd A quantidade a ser retirada do estoque.
*/
void vendeProdutoLoja(tStore *loja, int id, int qtd);

/**
 * @brief Atualiza o desconto de um produto de uma loja.
 * @param loja O endereço da loja.
 * @param id O id do produto.
 * @param desconto O novo desconto.
*/
void atualizaDescontoLoja(tStore *loja, int id, float desconto);

/**
 * @brief Imprime todos os produtos atuais de uma loja
 * @brief Deve possuir quebra de linha ao final
 * @param loja O endereço da loja.
*/
void imprimeProdutosLoja(tStore *loja);

/**
 * @brief Ordena a loja na ordem DECRESCENTE de numero de vendas
 * @param loja O endereço da loja.
*/
void ordenaLojaVendas(tStore *loja);

/**
 * @brief Ordena a loja na ordem DECRESCENTE de preço (levando em conta o desconto)
 * @param loja O endereço da loja.
*/
void ordenaLojaPreco(tStore *loja);

/**
 * @brief Ordena a loja na ordem DECRESCENTE de numero de estoque
 * @param loja O endereço da loja.
*/
void ordenaLojaEstoque(tStore *loja);

/**
 * @brief Ordena a loja na ordem CRESCENTE de ID
 * @param loja O endereço da loja.
*/
void ordenaLojaID(tStore *loja);

#endif