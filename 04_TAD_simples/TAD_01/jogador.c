#include <stdio.h>
#include <stdbool.h>
#include "jogador.h"
#include "jogada.h"

tJogador CriaJogador(int idJogador){
    tJogador jogador;

    jogador.id = idJogador;

    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    printf("Jogador %d\n", jogador.id);

    int x;
    int y;

    //enquanto o jogador não fizer uma jogada digna, não sai
    while(true){
        //pega a jogada e suas coordenadas;
        tJogada jogada = LeJogada();
        x = ObtemJogadaX(jogada);
        y = ObtemJogadaY(jogada);

        if(EhPosicaoValidaTabuleiro(y,x) && EstaLivrePosicaoTabuleiro(tabuleiro, y, x)){
            break;
        }
    }

    if(jogador.id == ID_JOGADOR_1){
        tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, tabuleiro.peca1, y, x);
    }

    if(jogador.id == ID_JOGADOR_2){
        tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, tabuleiro.peca2, y, x);
    }

    //printa jogada no tabuleiro;
    printf("Jogada [%d,%d]!\n", x, y);
    ImprimeTabuleiro(tabuleiro);

    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){
    char peca;

    if(jogador.id == ID_JOGADOR_1){
        peca = 'X';
    }

    if(jogador.id == ID_JOGADOR_2){
        peca = '0';
    }

    int somaPecas; //somatorio de peças iguais em sequência no tabuleiro

    //verificacao por linhas
    for(int i = 0; i < TAM_TABULEIRO; i++){
        somaPecas = 0;

        for(int j = 0; j < TAM_TABULEIRO; j++){
            if(tabuleiro.posicoes[i][j] == peca){
                somaPecas++;
            }
        }

        if(somaPecas == 3){
            printf("entrou linha\n");
            printf("JOGADOR %d Venceu!\n", jogador.id);
            return 1;
        }
    }

    //verificacao por colunas
    for(int j = 0; j < TAM_TABULEIRO; j++){
        somaPecas = 0;

        for(int i = 0; i < TAM_TABULEIRO; i++){
            if(tabuleiro.posicoes[i][j] == peca){
                somaPecas++;
            }
        }

        if(somaPecas == 3){
            printf("entrou coluna\n");
            printf("JOGADOR %d Venceu!\n", jogador.id);
            return 1;
        }
    }

    //verificacao diagonal primaria
    somaPecas = 0;

    for(int i = 0; i < TAM_TABULEIRO; i++){
        if(tabuleiro.posicoes[i][i] == peca){
            somaPecas++;
        }
    }

    if(somaPecas == 3){
        printf("entrou diagonal\n");
        printf("JOGADOR %d Venceu!\n", jogador.id);
        return 1;
    }


    //verificação diagonal secundária
    somaPecas = 0;

    for(int i = 0; i < TAM_TABULEIRO; i++){
        if(tabuleiro.posicoes[i][2 - i] == peca){
            somaPecas++;
        }
    }

    if(somaPecas == 3){
        printf("entrou diagonal sec\n");
        printf("JOGADOR %d Venceu!\n", jogador.id);
        return 1;
    }

    //se passou por todas verificações e o somatório continou sendo menor que 3, não venceu.
    return 0;
}