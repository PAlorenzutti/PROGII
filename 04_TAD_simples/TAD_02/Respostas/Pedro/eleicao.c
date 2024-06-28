#include <stdio.h>

#include "candidato.h"
#include "eleicao.h"

tEleicao InicializaEleicao(){
    tEleicao eleicao;

    //zerando total de presidentes e seus votos nulos e brancos;
    eleicao.totalPresidentes = 0;
    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosPresidente = 0;

    //zerando total de governadores e seus votos nulos e brancos;
    eleicao.totalGovernadores = 0;
    eleicao.votosBrancosGovernador = 0;
    eleicao.votosNulosGovernador = 0;

    //zerando total de eleitores
    eleicao.totalEleitores = 0;

    //pegando o numero de candidatos;
    int numCandidatos;
    scanf("%d\n", &numCandidatos);

    //lendo o candidato;
    for(int i = 0; i < numCandidatos; i++){
        tCandidato candidato = LeCandidato();

        if(ObtemCargo(candidato) == 'P'){
            //se o cargo for de presidente, coloca na lista de presidentes e aumenta o número;
            eleicao.presidentes[i] = candidato;
            eleicao.totalPresidentes++;
        }else{
            //se o cargo for de governador, coloca na lista de governadores e aumenta o número;
            eleicao.governadores[i] = candidato;
            eleicao.totalGovernadores++;
        }
    }

    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao){
    //lê o número de eleitores;
    int numEleitores;
    scanf("%d\n", &numEleitores);
}

void ImprimeEleicao(tEleicao eleicao){
    //imprime governadores
    for(int i = 0; i < eleicao.totalGovernadores; i++){
        ImprimeCandidato(eleicao.governadores[i]);
    }

    //imprime presidentes
    for(int i = 0; i < eleicao.totalPresidentes; i++){
        ImprimeCandidato(eleicao.presidentes[i]);
    }
}