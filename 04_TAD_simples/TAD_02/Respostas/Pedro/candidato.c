#include <stdio.h>
#include <string.h>

#include "candidato.h"

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id){
    tCandidato candidato;

    strcpy(candidato.nome, nome);
    strcpy(candidato.partido, partido);
    candidato.cargo = cargo;
    candidato.id = id;
    candidato.votos = 0;

    return candidato;
}


tCandidato LeCandidato(){
    char nome[50];
    char partido[50];
    char cargo;
    int id;
    int votos;

    scanf("%49[^,], %49[^,], %c, %d\n", nome, partido, &cargo, &id);

    tCandidato candidato = CriaCandidato(nome, partido, cargo, id);

    return candidato;
}

int VerificaIdCandidato(tCandidato candidato, int id){
    if(candidato.id == id){
        return 1;
    }else{
        return 0;
    }
}

char ObtemCargo(tCandidato candidato){
    return candidato.cargo;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato){
    candidato.votos++;
    return candidato;
}

//teste
void ImprimeCandidatoTeste (tCandidato candidato){
    printf("%s, %s, %c, %d, votos: %d\n", candidato.nome, candidato.partido, candidato.cargo, candidato.id, candidato.votos);
}