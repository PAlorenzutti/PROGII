#include "franquia.h"

tFranquia lerFranquia(){
    tFranquia franquia;

    scanf("%s %s\n", franquia.nome, franquia.conferencia);

    franquia.vitorias = 0;
    franquia.vitoriasCasa = 0;
    franquia.vitoriasFora = 0;
    franquia.derrotas = 0;

    return franquia;
}



tFranquia associarPontosFranquias(tFranquia franquias[], int qtdFranquias, char franquiaVisitante[], char franquiaCasa[], int pontosVisitante, int pontosCasa){
    int indexCasa;
    int indexVisitante;
}

