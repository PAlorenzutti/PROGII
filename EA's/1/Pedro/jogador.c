#include <stdio.h>

#include "jogador.h"
/*
Função que inicializa um jogador com ID passado por parâmetro
Todas as estatísticas do jogador são inicializadas com 0
e o valor do KDA é inicializado com -1

@param id: ID do jogador
@return Jogador: Jogador inicializado
*/
Jogador inicializaJogador(int id){
    Jogador j;

    j.id = id;
    j.kills = 0;
    j.deaths = 0;
    j.assists = 0;
    j.valorKDA = -1;

    return j;
}

/*
Função que lê as estatísticas de um jogador a partir da entrada padrão e retorna um jogador inicializado
com essas estatísticas. O ID do jogador é passado por parâmetro. Uma vez lido as estatísticas, o valor do KDA
é calculado e armazenado no jogador.

@param id: ID do jogador
@return Jogador: Jogador inicializado com as estatísticas lidas e o valor do KDA calculado
*/
Jogador leJogador(int id){
    Jogador j = inicializaJogador(id);

    scanf("%d %d %d\n", &j.kills, &j.deaths, &j.assists);

    j.valorKDA = calculaKDA(j);

    return j;
}

/*
Função que calcula o valor do KDA de um jogador e armazena no campo valorKDA do próprio jogador

@param j: Jogador
@return float: Valor do KDA do jogador
*/
float calculaKDA(Jogador j){
    float valorKDA;
    
    if(j.deaths > 0){
        valorKDA = (float) (j.kills + j.assists) / j.deaths;
    }else{
        valorKDA = (float) j.kills + j.assists;
    }

    return valorKDA;
} 

/*
Essa função recebe um jogador cadastrado e atualiza suas estatísticas de acordo com os valores passados por parâmetro.
O ID do jogador é sempre igualado ao ID passado por parâmetro e as estatísticas de kills, deaths e assists são incrementadas
pelos valores passados por parâmetro. O valor do KDA é recalculado e armazenado no campo valorKDA do jogador.

@param j: Jogador
@param id: ID do jogador
@param k: Kills a serem incrementadas
@param d: Deaths a serem incrementadas
@param a: Assists a serem incrementadas
@return Jogador: Jogador atualizado
*/
Jogador atualizaJogador(Jogador j, int id, int k, int d, int a){
    j.id = id;
    j.kills += k;
    j.assists += a;
    j.deaths += d;

    j.valorKDA = calculaKDA(j);

    return j;
}

/*
Funçao que recebe um jogador e retorna o valor de kills do jogador

@param j: Jogador
@return int: Kills do jogador
*/
int getKillsJogador(Jogador j){
    return j.kills;
}

/*
Funçao que recebe um jogador e retorna o valor de deaths do jogador

@param j: Jogador
@return int: deaths do jogador
*/
int getDeathsJogador(Jogador j){
    return j.deaths;
}

/*
Funçao que recebe um jogador e retorna o valor de assists do jogador

@param j: Jogador
@return int: Assists do jogador
*/
int getAssistsJogador(Jogador j){
    return j.assists;
}

/*
Funçao que recebe um jogador e retorna o valor de ID do jogador

@param j: Jogador
@return int: ID do jogador
*/
int getIdJogador(Jogador j){
    return j.id;
}

/*
Funçao que recebe um jogador e imprime suas informações conforme o formato especificado

@param j: Jogador
*/
void printaJogador(Jogador j){
    printf("Jogador %d: %d/%d/%d (%.2f)\n", j.id, j.kills, j.deaths, j.assists, j.valorKDA);
}