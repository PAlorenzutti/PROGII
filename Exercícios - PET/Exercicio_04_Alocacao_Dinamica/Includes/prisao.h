#ifndef TPRISAO_H
#define TPRISAO_H

#include "cela.h"
#include "prisioneiro.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define MAXTAM_NOME 100

typedef struct
{
    char nome[MAXTAM_NOME];
    int dia;
    int nCelas;
    int capacidadeCelas;
    tCela** celas;
}tPrisao;

/**
 * @brief Cria a prisão usada no programa
 * @param nome Nome da prisão
 * @param nCelas Numero de celas na prisão
 * @param capacidadeCelas Capacidade de prisioneiros por cela
*/
tPrisao* criaPrisao(char* nome, int nCelas, int capacidadeCelas);

/**
 * @brief Função principal para execução do programa e utilização do menu
*/
void executaPrisao(tPrisao* prisao);

/**
 * @brief Imrpime o dia do programa e o menu na tela
*/
void imprimeDiaEMenuPrisao(tPrisao* prisao);

/**
 * @brief Cria um prisioneiro e o insere na próxima cela disponível
*/
void inserePrisioneiroPrisao(tPrisao* prisao);

/**
 * @brief Passa um dia no programa
*/
void passaDiaPrisao(tPrisao* prisao);

/**
 * @brief Realiza a fuga dos prisioneiros da cela indicada.
*/
void registraFugaCelaPrisao(tPrisao* prisao);

/**
 * @brief Retorna o numero total de prisioneiros atualmente na prisão
*/
int obtemNumeroPrisioneirosPrisao(tPrisao* prisao);

/**
 * @brief Realiza a funcao de rebelião geral.
*/
void rebeliaoGeralPrisao(tPrisao* prisao);

/**
 * @brief Desaloca a prisao
*/
void desalocaPrisao(tPrisao* prisao);
#endif
