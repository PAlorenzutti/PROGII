#include <stdio.h>
#include <stdbool.h>

#include "servidor.h"

/*
Função que lê todos os registros de partidas de um servidor a partir da entrada padrão e retorna um servidor
com todos os registros de partidas lidos. Conforme a especificação da atividade, a leitura é encerrada quando
um ID de partida igual a -1 é lido.

@return Servidor: Servidor com todos os registros de partidas lidos
*/
Servidor leRegistrosServidor(){
    Servidor s;
    s.nPartidas = 0;

    while(true){
        int idPartida;
        scanf("%d\n", &idPartida);

        if(idPartida == -1){
            break;
        }

        s.partidas[idPartida] = leRegistro(idPartida);
        s.nPartidas++;
    }

    return s;
}

/*
Função que recebe um servidor já preenchido com os dados de todas as partidas e um ID de jogador.
A partir dessas informações, ela busca as estatísticas do jogador em todas as partidas que ele participou.
Se o jogar não for encontrado, um jogador com ID -1 é criado e retornado.
Se o jogador for encontrado em apenas uma partida, ele é retornado.
Se o jogador for encontrado em mais de uma partida, suas estatísticas são agregadas e o jogador é retornado.

@param s: Servidor
@param idJog: ID do jogador
*/
Jogador buscaDadosJogadorServidor(Servidor s, int idJog){
    Jogador j = inicializaJogador(idJog);

    //sentinela existe
    int existe = 0;

    //busca dados do jogador na partida dada
    for(int i = 0; i < s.nPartidas; i++){
        Jogador jogador = buscaJogadorRegistro(s.partidas[i], idJog);
        
        //se o jogador existe naquela partida, atualiza o jogador dado com os dados desse jogador na partida
        if(getIdJogador(jogador) != -1){
            int kills = getKillsJogador(jogador);
            int deaths = getDeathsJogador(jogador);
            int assists = getAssistsJogador(jogador);

            j = atualizaJogador(j, idJog, kills, deaths, assists);

            existe = 1;
        }
    }

    if(existe == 1){
        return j;
    }else{
        //se o jogador não existe, retorna um jogador com id -1
        Jogador jogador = inicializaJogador(-1);
        return jogador;
    }
}

/*
Função que recebe um servidor já criado e preenchido e imprime um relatório com as estatísticas de um conjunto de jogadores
solicitados a partir da entrada padrão. O relatório é impresso conforme o formato especificado na descrição da atividade.
*/
void criaRelatorioServidor(Servidor s){
    int qtdJogadores;
    
    scanf("%d\n", &qtdJogadores);

    for(int i = 0; i < qtdJogadores; i++){
        int idJogador;
        scanf("%d", &idJogador);

        Jogador j = buscaDadosJogadorServidor(s, idJogador);

        if(getIdJogador(j) != -1){
            printaJogador(j);
        }else{
            printf("Jogador %d: -\n", idJogador);
        }
    }
}