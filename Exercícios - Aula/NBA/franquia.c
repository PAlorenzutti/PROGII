#include "franquia.h"
#include <stdio.h>
#include <string.h>

tFranquia lerFranquia(){
    tFranquia franquia;

    scanf("%s %s\n", franquia.nome, franquia.conferencia);

    if(!strcmp(franquia.conferencia, "OESTE")){
        strcpy(franquia.sigla, "[CO]");
        //Para corrigir bug de concatenação pós strcmp;
    }

    if(!strcmp(franquia.conferencia, "LESTE")){
        strcpy(franquia.sigla, "[CL]");
        //Para corrigir bug de concatenação pós strcmp;
    }

    franquia.partidas = 0;
    franquia.vitorias = 0;
    franquia.vitoriasCasa = 0;
    franquia.vitoriasFora = 0;
    franquia.derrotas = 0;
    franquia.aproveitamento = 0;

    return franquia;
}

void somaVitoriasFranquias(tFranquia franquias[], int qtdFranquias){
    for(int i = 0; i < qtdFranquias; i++){
        franquias[i].vitorias = franquias[i].vitoriasCasa + franquias[i].vitoriasFora;
    }
}

//Calcula aproveitamento de cada franquia
void calculaAproveitamentoFranquias(tFranquia franquias[], int qtdFranquias){
    for(int i = 0; i < qtdFranquias; i++){
        if(franquias[i].partidas){
            franquias[i].aproveitamento = ((float) franquias[i].vitorias / (float) franquias[i].partidas) * 100;
        }else{
            franquias[i].aproveitamento = 0;
        }
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

int somaVitoriasConferencia(tFranquia franquias[], int qtdFranquias, char conferencia[]){
    int vitorias = 0;
    
    for(int i = 0; i < qtdFranquias; i++){
        if(!strcmp(franquias[i].conferencia, conferencia)){
            vitorias += franquias[i].vitorias;
        }
    }

    return vitorias;
}

int somaDerrotasConferencia(tFranquia franquias[], int qtdFranquias, char conferencia[]){
    int derrotas = 0;
    
    for(int i = 0; i < qtdFranquias; i++){
        if(!strcmp(franquias[i].conferencia, conferencia)){
            derrotas += franquias[i].derrotas;
        }
    }

    return derrotas;
}

void printFranquias(tFranquia franquias[], int qtdFranquias){
    for(int i = 0; i < qtdFranquias; i++){
        printf("%s %s %d %d %.2f %d %d\n", franquias[i].nome, franquias[i].sigla, 
        franquias[i].vitorias, franquias[i].derrotas, franquias[i].aproveitamento,
        franquias[i].vitoriasCasa, franquias[i].vitoriasFora);
    }
}

void printAproveitamentoConferencias(tFranquia franquias[], int qtdFranquias){

    //CL e CO adicionados a string para corrigir bug de concatenação
    int vitoriasLeste = somaVitoriasConferencia(franquias, qtdFranquias, "LESTE[CL]");
    int vitoriasOeste = somaVitoriasConferencia(franquias, qtdFranquias, "OESTE[CO]");

    int derrotasLeste = somaDerrotasConferencia(franquias, qtdFranquias, "LESTE[CL]");
    int derrotasOeste = somaDerrotasConferencia(franquias, qtdFranquias, "OESTE[CO]");

    int partidasLeste = vitoriasLeste + derrotasLeste;
    int partidasOeste = vitoriasOeste + derrotasOeste;

    float aproveitamentoLeste;
    float aproveitamentoOeste;
    
    if(!partidasLeste){
        aproveitamentoLeste = 0;
    }else{
        aproveitamentoLeste = ((float) vitoriasLeste / (float) (partidasLeste)) * 100;
    }

    if(!partidasOeste){
        aproveitamentoOeste = 0;
    }else{
        aproveitamentoOeste = ((float) vitoriasOeste / (float) (partidasOeste)) * 100;
    }


    printf("LESTE %d %d %.2f\n", vitoriasLeste, derrotasLeste, aproveitamentoLeste);
    printf("OESTE %d %d %.2f\n", vitoriasOeste, derrotasOeste, aproveitamentoOeste);
}

void associarPontosFranquias(tFranquia franquias[], int qtdFranquias, char franquiaVisitante[], int pontosVisitante, char franquiaCasa[], int pontosCasa){
    //Pegando o index de cada time;
    int indexCasa = pesquisarFranquia(franquias, qtdFranquias, franquiaCasa);
    int indexVisitante = pesquisarFranquia(franquias, qtdFranquias, franquiaVisitante);

    //Atualizando de acordo com o resultado
    if(pontosVisitante > pontosCasa){
        franquias[indexVisitante].partidas++;
        franquias[indexVisitante].vitoriasFora++;

        franquias[indexCasa].partidas++;
        franquias[indexCasa].derrotas++;
    }

    if(pontosCasa > pontosVisitante){
        franquias[indexCasa].partidas++;
        franquias[indexCasa].vitoriasCasa++;

        franquias[indexVisitante].partidas++;
        franquias[indexVisitante].derrotas++;
    }
}