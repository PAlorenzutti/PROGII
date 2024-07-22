#ifndef _BOTAO_H
#define _BOTAO_H

#define MAX_TAM_TEXTO 30
#define CLICK 1
#define LONGO_CLICK 2
#define HOVER 3

typedef struct {
    char texto[MAX_TAM_TEXTO];
    int tamFonte;
    char corHex[7];
    int tipo;
    void (*executa)(void);
}Botao;

void setarTexto(Botao *b, char *novoTexto);
void setarTamFonte(Botao *b, int novoTamFonte);
void setarCor(Botao *b, char *novaCor);
void setarTipo(Botao *b, int novoTipo);
Botao criarBotao(char *texto, int tamFonte, char *cor, int tipo, void (*executa)(void));
void executaBotao(Botao b);
void desenhaBotao(Botao b, int idx);

#endif