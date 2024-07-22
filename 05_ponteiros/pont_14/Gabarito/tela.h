#ifndef _TELA_H
#define _TELA_H

#include "botao.h"

#define MAX_BOTOES 10
typedef struct {
    int altura;
    int largura;
    Botao botoes[MAX_BOTOES];
    int qntBotoes;
}Tela;

Tela criarTela (int altura, int largura);
void registraBotaoTela(Tela *t, Botao b);
void desenhaTela (Tela t);
void ouvidorEventosTela(Tela t);

#endif