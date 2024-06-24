#include <stdio.h>
#include <stdbool.h>
#include "jogo.h"

tJogo CriaJogo(){
    tJogo jogo;

    return jogo;
}

void ComecaJogo(tJogo jogo){
    //definindo tabuleiro
    tTabuleiro tabuleiro = CriaTabuleiro();
    jogo.tabuleiro = tabuleiro;

    //definindo jogadores
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);

    while(true){
        jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);

        if(AcabouJogo(jogo)){
            break;
        }

        jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);

        if(AcabouJogo(jogo)){
            break;
        }
    }
}

int AcabouJogo(tJogo jogo){
    if(!TemPosicaoLivreTabuleiro(jogo.tabuleiro)){
        return 1;
    }

    if(VenceuJogador(jogo.jogador1, jogo.tabuleiro)){
        return 1;
    }
    
    if(VenceuJogador(jogo.jogador2, jogo.tabuleiro)){
        return 1;
    }

    return 0;
}

int ContinuaJogo(){
    char opcao;

    printf("Jogar novamente? (s,n)\n");

    scanf("%c", &opcao);

    if(opcao == 's'){
        return 1;
    }

    if(opcao == 'n'){
        return 0;
    }

    return 0;
}