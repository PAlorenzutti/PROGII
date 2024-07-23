#include "tela.h"

#include <stdio.h>

/*
Funcao que cria uma tela de acordo com a altura e largura passadas por parametro

@param altura: Inteiro que define a altura da tela
@param largura: Inteiro que define a largura da tela

@return Tela: Tela criada
*/
Tela criarTela (int altura, int largura){
    Tela t;

    t.altura = altura;
    t.largura = largura;
    t.qntBotoes = 0;

    return t;
}

/*
Funcao que adiciona um novo botao a tela

@param t: Tela a ser atualizada com o novo botao
@param b: Botao a ser adicionado a tela

@return Tela: Tela criada
*/
void registraBotaoTela(Tela *t, Botao b){
    //coloca o botão na posição atual;
    (*t).botoes[(*t).qntBotoes] = b;

    //incrementa a posição do vetor;
    (*t).qntBotoes++;
}

/*
Funcao que desenha a tela

@param t: Tela a ser desenhada (e seus respectivos botoes)
*/
void desenhaTela (Tela t){
    printf("##################\n");
    for(int i = 0; i < t.qntBotoes; i++){
        desenhaBotao(t.botoes[i], i);
        printf("\n");
    }
    printf("##################\n");
}

/*
Funcao que aguarda um evento de clique (simulado pela leitura do teclado)

@param t: Tela criada que aguarda um evento para executar uma funcao de Callback
*/
void ouvidorEventosTela(Tela t){
    printf("- Escolha sua acao: ");
    
    int opcao;
    scanf("%d", &opcao);

    executaBotao(t.botoes[opcao]);
}