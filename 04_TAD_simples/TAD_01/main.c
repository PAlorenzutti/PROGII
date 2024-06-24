#include <stdio.h>
#include <stdbool.h>
#include "jogo.h"
#include "jogada.h"
#include "jogador.h"
#include "tabuleiro.h"

int main(){
    //loop externo para os jogos
    while(true){
        tJogo jogo = CriaJogo();

        ComecaJogo(jogo);

        if(!ContinuaJogo()){
            break;
        }
    }

    return 0;
}