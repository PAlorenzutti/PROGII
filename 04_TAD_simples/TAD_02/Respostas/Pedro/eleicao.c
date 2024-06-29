#include <stdio.h>
#include <stdlib.h>

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
            eleicao.presidentes[eleicao.totalPresidentes] = candidato;
            eleicao.totalPresidentes++;
        }
        
        if(ObtemCargo(candidato) == 'G'){
            //se o cargo for de governador, coloca na lista de governadores e aumenta o número;
            eleicao.governadores[eleicao.totalGovernadores] = candidato;
            eleicao.totalGovernadores++;
        }
    }

    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao){
    //lê o número de eleitores;
    int numEleitores;
    scanf("%d\n", &numEleitores);

    //se o número de eleitores for maior do que o máximo, a eleição é anulada.
    if(numEleitores > MAX_ELEITORES){
        printf("ELEICAO ANULADA\n");
        exit(0);
    }

    //lendo cada eleitor
    for(int i = 0; i < numEleitores; i++){
        tEleitor eleitor = LeEleitor();

        //verifica se eleitor já existe, fraude é sentinela;
        int fraude = 0;

        for(int j = 0; j < i; j++){
            if(EhMesmoEleitor(eleitor, eleicao.eleitores[j]) == 1){
                fraude++;
                break;
            }
        }

        //se fraude for maior que 1, significa que o eleitor não existe na lista e pode ser adicionado
        if(fraude > 0){
           printf("ELEICAO ANULADA\n");
           exit(0);
        }else{
            eleicao.eleitores[eleicao.totalEleitores] = eleitor;
            eleicao.totalEleitores++;
        }
    }

    // Apuração dos votos de cada eleitor, caso a eleição não tenha sido fraudada
    for(int i = 0; i < numEleitores; i++){
        int votoP = ObtemVotoPresidente(eleicao.eleitores[i]);
        int votoG = ObtemVotoGovernador(eleicao.eleitores[i]);

        //varredura para incrementar voto em presidente;
        int encontrouP = 0;

        for(int j = 0; j < eleicao.totalPresidentes; j++){
            if(VerificaIdCandidato(eleicao.presidentes[j], votoP)){
                eleicao.presidentes[j] = IncrementaVotoCandidato(eleicao.presidentes[j]);
                encontrouP = 1;
                break;
            }
        }

        //se o votoP for igual a 0, incrementa votos brancos em presidente 
        if(votoP == 0){
            eleicao.votosBrancosPresidente++;
        }else if(!encontrouP){
            //se encontrouP for igual a 0, significa que o voto é nulo, ele não encontrou nenhum candidato com aquele id
            eleicao.votosNulosPresidente++;
        }

        //varredura para incrementar voto em governador;
        int encontrouG = 0;

        for(int j = 0; j < eleicao.totalGovernadores; j++){
            if(VerificaIdCandidato(eleicao.governadores[j], votoG)){
                eleicao.governadores[j] = IncrementaVotoCandidato(eleicao.governadores[j]);
                encontrouG = 1;
                break;
            }
        }

        //se votoG for igual a 0, incrementa votos brancos em governadores
        if(votoG == 0){
            eleicao.votosBrancosGovernador++;
        }else if(!encontrouG){
            //se encontrouG for igual a 0, incrementa votos nulos em governadores
            eleicao.votosNulosGovernador++;
        }
    }

    return eleicao;
}

void ImprimeResultadoEleicao(tEleicao eleicao){
    //soma de todos os votos nulos e brancos;
    int votosNulos = eleicao.votosNulosPresidente + eleicao.votosNulosGovernador;
    int votosBrancos = eleicao.votosBrancosPresidente + eleicao.votosBrancosGovernador;

    printf("- PRESIDENTE ELEITO:\n");

    printf("- GOVERNADOR ELEITO:\n");

    printf("- NULOS E BRANCOS: %d, %d", votosNulos, votosBrancos);
}

//teste
void ImprimeEleicao(tEleicao eleicao){
    //imprime governadores
    for(int i = 0; i < eleicao.totalGovernadores; i++){
        ImprimeCandidatoTeste(eleicao.governadores[i]);
    }

    //imprime presidentes
    for(int i = 0; i < eleicao.totalPresidentes; i++){
        ImprimeCandidatoTeste(eleicao.presidentes[i]);
    }

    //imprime eleitores
    for(int i = 0; i < eleicao.totalEleitores; i++){
        ImprimeEleitor(eleicao.eleitores[i]);
    }
}