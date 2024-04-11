#include "franquia.h"
#include "string.h"

tFranquia lerFranquia(){
    tFranquia franquia;

    scanf("%s %s\n", franquia.nome, franquia.conferencia);

    franquia.vitorias = 0;
    franquia.vitoriasCasa = 0;
    franquia.vitoriasFora = 0;
    franquia.derrotas = 0;

    return franquia;
}

void somaVitorias(tFranquia *franquias[], int qtdFranquias){
    for(int i = 0; i < qtdFranquias; i++){
        franquias[i]->vitorias = franquias[i]->vitoriasCasa + franquias[i]->vitoriasFora;
    }
}

//Calcula aproveitamento de cada franquia
void calculaAproveitamentoFranquia(tFranquia *franquias[], int qtdFranquias){
    for(int i = 0; i < qtdFranquias; i++){
        franquias[i]->aproveitamento = franquias[i]->vitorias / (franquias[i]->vitorias + franquias[i]->derrotas);
    }
}

int pesquisarFranquia(tFranquia franquias[], int qtdFranquias, char nomeFranquia[]){
    //Descobrir a posição da franquia no vetor de franquias.
    for(int i = 0; i < qtdFranquias; i++){
        if(!strcmp(franquias[i].nome, nomeFranquia)){
            return i;
        }
    }
}

void associarPontosFranquias(tFranquia *franquias[], int qtdFranquias, char franquiaVisitante[], int pontosVisitante, char franquiaCasa[], int pontosCasa){
    //Pegando o index de cada time;
    int indexCasa = pesquisarFranquia(franquias, qtdFranquias, franquiaCasa);
    int indexVisitante = pesquisarFranquia(franquias, qtdFranquias, franquiaVisitante);

    //Atualizando de acordo com o resultado
    if(pontosVisitante > pontosCasa){
        franquias[indexVisitante]->vitoriasFora++;
        franquias[indexCasa]->derrotas++;
    }

    if(pontosCasa > pontosVisitante){
        franquias[indexCasa]->vitoriasCasa++;
        franquias[indexVisitante]->derrotas++;
    }
}

