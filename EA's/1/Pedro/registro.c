#include <stdio.h>

#include "registro.h"

/*
Função que lê apenas um registro de partida a partir da entrada padrão. O registro de uma partida
é composto das informações de 5 jogadores. Verifique a especificação da atividade para mais detalhes.

@param idPartida: ID da partida
@return Registro: Registro de uma partida
*/
Registro leRegistro(int idPartida){
    Registro partida;

    partida.idPartida = idPartida;

    for(int i = 0; i < MAX_JOGADOR_PARTIDA; i++){
        int id;
        scanf("%d:", &id);

        Jogador j = leJogador(id);

        partida.jogadores[i] = j;
    }

    return partida;
}

/*
Função que busca um jogador em um registro de partida a partir do ID do jogador.
Se o jogador for encontrado, ele é retornado. Caso contrário, um jogador é criado com ID -1 e retornado.

@param r: Registro de uma partida
@param idJog: ID do jogador a ser buscado
*/
Jogador buscaJogadorRegistro(Registro r, int idJog){
    //busca dados dentro da partida
    for(int i = 0; i < MAX_JOGADOR_PARTIDA; i++){
        //se o id for igual ao do jogador, retorna ele mesmo;
        if(getIdJogador(r.jogadores[i]) == idJog){
            return r.jogadores[i];
        }
    }

    //ele não encontrou, retorna um jogador novo;
    Jogador j = inicializaJogador(-1);

    return j;
}