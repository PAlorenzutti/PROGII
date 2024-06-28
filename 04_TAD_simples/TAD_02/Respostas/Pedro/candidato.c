#include <stdio.h>
#include <string.h>

#include "candidato.h"

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id){
    tCandidato candidato;

    strcpy(candidato.nome, nome);
    strcpy(candidato.partido, partido);
    candidato.cargo = cargo;
    candidato.id = id;

    return candidato;
}


tCandidato LeCandidato(){
    char nome[50];
    char partido[50];
    char cargo;
    int id;
    int votos;

    scanf("%[^\n], %[^\n], %c, %d\n", nome, partido, &cargo, &id);

    tCandidato candidato = CriaCandidato(nome, partido, cargo, id);

    return candidato;
}

char ObtemCargo(tCandidato candidato){
    return candidato.cargo;
}

//teste
void ImprimeCandidato (tCandidato candidato){
    printf("%s, %s, %c, %d\n", candidato.nome, candidato.partido, candidato.cargo, candidato.id);
}