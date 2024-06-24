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
}

int AcabouJogo(tJogo jogo){
    if(TemPosicaoLivreTabuleiro(jogo.tabuleiro)){
        return 0;
    }else{
        return 1;
    }
}