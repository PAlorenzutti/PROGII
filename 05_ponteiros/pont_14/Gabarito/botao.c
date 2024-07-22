
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "botao.h"


void setarTexto(Botao *b, char *novoTexto) {
    if (strlen(novoTexto) > MAX_TAM_TEXTO) {
        printf("-ERRO: texto do botao e maior do que o permitido\n");
        exit(1);
    }
    strcpy(b->texto, novoTexto);
}

void setarTamFonte(Botao *b, int novoTamFonte) {
    if (novoTamFonte <= 0) {
        printf("-ERRO: o tamanho da fonte deve ser maior do que zero\n");
        exit(1);
    }
    b->tamFonte = novoTamFonte;
}

void setarCor(Botao *b, char *novaCor) {
    strcpy(b->corHex, novaCor);
}

void setarTipo(Botao *b, int novoTipo) {
    if (novoTipo != CLICK && novoTipo != LONGO_CLICK && novoTipo != HOVER){
        printf("-ERRO: tipo de botao inexistente\n");
        exit(1);
    }
    b->tipo = novoTipo;
}

Botao criarBotao(char *texto, int tamFonte, char *cor, int tipo, void (*executa)(void)) {
    Botao b;
    setarTexto(&b, texto);
    strcpy(b.corHex, cor);
    b.tamFonte = tamFonte;
    b.tipo = tipo;
    b.executa = executa;
    return b;
}

void desenhaBotao(Botao b, int idx) {
    printf("-------------\n");
    printf("- Botao [%d]:\n", idx);
    printf("(%s | %s | %d | %d)\n", b.texto, b.corHex, b.tamFonte, b.tipo);
    printf("-------------\n");
}

void executaBotao(Botao b) {
    if (b.tipo == CLICK) {
        printf("- Executando o botao com evento de click\n");
    } else if (b.tipo == LONGO_CLICK) {
        printf("- Executando o botao com evento de longo click\n");
    } else if (b.tipo == HOVER) {
        printf("- Executando o botao com evento de hover\n");
    } else {
        printf("ERRO: evento nao existe!");
        exit(1);
    }
    b.executa();
}