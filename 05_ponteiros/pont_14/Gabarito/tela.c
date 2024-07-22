
#include <stdio.h>
#include <stdlib.h>
#include "tela.h"
#include "botao.h"


Tela criarTela (int altura, int largura) {
    Tela t;
    t.altura = altura;
    t.largura = largura;        
    t.qntBotoes = 0;    
    return t;
}

void registraBotaoTela(Tela *t, Botao b) {
    if (t->qntBotoes > MAX_BOTOES) {
        printf("- AVISO: nao cabe mais botao\n");
    } else {
        t->botoes[t->qntBotoes] = b;
        t->qntBotoes++;
    }
}

void desenhaTela (Tela t) {
    printf("##################\n");
    for(int i=0; i<t.qntBotoes; i++){
        desenhaBotao(t.botoes[i], i);
        printf("\n");
    }
    printf("##################\n");
}

void ouvidorEventosTela(Tela t) {
    int acao;
    printf("- Escolha sua acao: ");
    scanf("%d", &acao);
    if (acao > t.qntBotoes){
        printf("AVISO: acao nao reconhecida\n");
        exit(0);
    }
    executaBotao(t.botoes[acao]);
}