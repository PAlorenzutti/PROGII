#ifndef _UFOOD_H
#define _UFOOD_H

#include "loja.h"
#include "cliente.h"
#include "fornecedor.h"
#include "ingrediente.h"
#include "produto.h"

typedef struct UfoodES tUfoodES;

tUfoodES *inicializaUfood();

tUfoodES *rodaUfood(tUfoodES *ufood);

int switchOperacao();

int switchAtores();

//funções de loja:

void cadastroLoja(tUfoodES *ufood);

int existeLojaUfood(tUfoodES *ufood, tLoja *loja);

void adicionaLojaUfood(tUfoodES *ufood, tLoja *loja);

void printaLojas(tUfoodES *ufood);

//funções de cliente:

void cadastroCliente(tUfoodES *ufood);

int existeClienteUfood(tUfoodES *ufood, tCliente *cliente);

void adicionaClienteUfood(tUfoodES *ufood, tCliente *cliente);

void printaClientes(tUfoodES *ufood);

//funções de fornecedor

void cadastroFornecedor(tUfoodES *ufood);

int existeFornecedorUfood(tUfoodES *ufood, tFornecedor *fornecedor);

void adicionaFornecedorUfood(tUfoodES *ufood, tFornecedor *fornecedor);

void printaFornecedores(tUfoodES *ufood);

//funções de ingrediente

void cadastroIngrediente(tUfoodES *ufood);

tFornecedor *buscaFornecedorCNPJ(tUfoodES *ufood, char* cnpj);

//funções de produto

tLoja *buscaLojaCNPJ(tUfoodES *ufood, char *cnpj);

tProduto *leituraIndustrializado();

tProduto *leituraPrato(tUfoodES *ufood);

tProduto *leituraProduto(tUfoodES *ufood, char tipoProduto);

void cadastroProduto(tUfoodES *ufood);

int existeIngredientesUfood(tUfoodES *ufood, char **ingredientes, int qtdIngredientes);

//funções de sacola
void adicionarProdutoSacola(tUfoodES *ufood);

tCliente *buscaClienteCPF(tUfoodES *ufood, char *cpf);

tProduto *buscaProdutoCodigo(tUfoodES *ufood, char *codigo);

void removerProdutoSacola(tUfoodES *ufood);

void limparProdutosSacola(tUfoodES *ufood);

void efetuarCompraCliente(tUfoodES *ufood);

//funções de busca
void buscarAvaliacoes(tUfoodES *ufood);

int menuBuscarProdutos();

void buscarProdutos(tUfoodES *ufood);

void buscaProdutoNome(tUfoodES *ufood, char *nome);

void buscaProdutoTipo(tUfoodES *ufood, char tipo);

void buscaProdutoTudo(tUfoodES *ufood);

int menuBuscarIngredientes();

void buscarIngredientes(tUfoodES *ufood);

void buscaIngredienteIdFornecedor(tUfoodES *ufood);

void buscaIngredienteNomeFornecedor(tUfoodES *ufood);

void buscaIngredienteNome(tUfoodES *ufood);

int menuBuscarLojas();

void buscarLojas(tUfoodES *ufood);

void buscaLojasNome(tUfoodES *ufood);

void buscaLojasComProduto(tUfoodES *ufood);

void buscaTodasLojas(tUfoodES *ufood);

void liberaUfood(tUfoodES *ufood);

#endif