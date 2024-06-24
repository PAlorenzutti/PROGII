#include <stdio.h>
#include "tabuleiro.h"

tTabuleiro CriaTabuleiro(){
    tTabuleiro tabuleiro;

    //criando as peças
    tabuleiro.peca1 = 'X';
    tabuleiro.peca2 = '0';
    tabuleiro.pecaVazio = '-';

    //criando o tabuleiro zerado;
    for(int i = 0; i < TAM_TABULEIRO; i++){
        for(int j = 0; j < TAM_TABULEIRO; j++){
            tabuleiro.posicoes[i][j] = tabuleiro.pecaVazio;
        }
    }

    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    tabuleiro.posicoes[x][y] == peca;

    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
    for(int i = 0; i < TAM_TABULEIRO; i++){
        for(int j = 0; j < TAM_TABULEIRO; j++){
            if(EstaLivrePosicaoTabuleiro(tabuleiro, i, j)){
                return 1;
            }
        }
    }

    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca){
    if(tabuleiro.posicoes[x][y] == peca){
        return 1;
    }else{
        return 0;
    } 
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
    if(tabuleiro.posicoes[x][y] == tabuleiro.pecaVazio){
        return 1;
    }else{
        return 0;
    }
}

int EhPosicaoValidaTabuleiro(int x, int y){
    if(x > 2 || y > 2){
        return 0;
    }

    if(x < 0 || y < 0){
        return 0;
    }

    return 1;
}

void ImprimeTabuleiro(tTabuleiro tabuleiro){
    for(int i = 0; i < TAM_TABULEIRO; i++){
        for(int j = 0; j < TAM_TABULEIRO; j++){
            printf("%c", tabuleiro.posicoes[i][j]);
        }
        printf("\n");
    }
}