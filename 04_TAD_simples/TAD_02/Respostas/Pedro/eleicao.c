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

    //soma dos votos inválidos da presidencia
    int votosInvalidosPresidente = eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente;

    //soma dos votos válidos dos candidatos a presidencia
    int votosValidosPresidente = 0;
    for(int i = 0; i < eleicao.totalPresidentes; i++){
        votosValidosPresidente += ObtemVotos(eleicao.presidentes[i]);
    }

    //soma de TODOS os votos da presidencia
    int totalVotosPresidente = votosInvalidosPresidente + votosValidosPresidente;

    //soma dos votos invalidos do governador
    int votosInvalidosGovernador = eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador;

    //votos válidos dos candidatos a governador
    int votosValidosGovernador = 0;
    for(int i = 0; i < eleicao.totalGovernadores; i++){
        votosValidosGovernador += ObtemVotos(eleicao.governadores[i]);
    }

    //soma de TODOS os votos a governador
    int totalVotosGovernador = votosInvalidosGovernador + votosValidosGovernador;

    //Imprime o presidente, caso não tenha empate ou indecisão.
    printf("- PRESIDENTE ELEITO: ");   

    //se tiver menos votos validos do que invalidos, sem decisão.
    if(votosValidosPresidente <= votosInvalidosPresidente){
        printf("SEM DECISAO\n");
    }else{
        // Procura governador eleito
        int indexPresidenteEleito;
        float percentualVotosPresidente = 0;
        int maxVotosGovernador = -1;

        //procura index do governador eleito
        for(int i = 0; i < eleicao.totalPresidentes; i++){
            //obtem os votos do governador em questão;
            int votos = ObtemVotos(eleicao.presidentes[i]);

            //se os votos do governador forem maiores do que o maior, o eleito é atualizado e calculado;
            if(votos > maxVotosGovernador){
                maxVotosGovernador = votos;
                indexPresidenteEleito = i;
            }
        }

        //procura empate entre presidentes;
        int empatePresidente = 0;
        for(int i = 0; i < eleicao.totalPresidentes; i++){
            //se i for diferente do indexPresidenteEleito, compara
            if(i != indexPresidenteEleito){
                //se os votos forem iguais, aumenta empate;
                if( EhMesmoCandidato(eleicao.presidentes[indexPresidenteEleito], eleicao.presidentes[i]) ){
                    empatePresidente++;
                }
            }
        }

        //se empate for maior que 0, teve empate;
        if(empatePresidente > 0){
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        }else{
            //calcula o percentual do governador eleito;
            percentualVotosPresidente = CalculaPercentualVotos(eleicao.presidentes[indexPresidenteEleito], totalVotosGovernador);

            //imprimindo governador eleito
            ImprimeCandidato(eleicao.presidentes[indexPresidenteEleito], percentualVotosPresidente);
        }
    }

    //Imprime o governador, caso não tenha empate ou indecisão.
    printf("- GOVERNADOR ELEITO: ");

    //se tiver menos votos validos do que invalidos, sem decisão.
    if(votosValidosGovernador <= votosInvalidosGovernador){
        printf("SEM DECISAO\n");
    }else{
        // Procura governador eleito
        int indexGovernadorEleito;
        float percentualVotosGovernador;
        int maxVotosGovernador = -1;

        //procura index do governador eleito
        for(int i = 0; i < eleicao.totalGovernadores; i++){
            //obtem os votos do governador em questão;
            int votos = ObtemVotos(eleicao.governadores[i]);

            //se os votos do governador forem maiores do que o maior, o eleito é atualizado e calculado;
            if(votos > maxVotosGovernador){
                maxVotosGovernador = votos;
                indexGovernadorEleito = i;
            }
        }

        //procura empate entre governadores;
        int empateGovernador = 0;
        for(int i = 0; i < eleicao.totalGovernadores; i++){
            //se i for diferente do indexPresidenteEleito, compara
            if(i != indexGovernadorEleito){
                //se os votos forem iguais, aumenta empate;
                if( EhMesmoCandidato(eleicao.governadores[indexGovernadorEleito], eleicao.governadores[i]) ){
                    empateGovernador++;
                }
            }
        }

        if(empateGovernador > 0){
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        }else{
            //calcula o percentual do governador eleito;
            percentualVotosGovernador = CalculaPercentualVotos(eleicao.governadores[indexGovernadorEleito], totalVotosGovernador);

            //imprimindo governador eleito
            ImprimeCandidato(eleicao.governadores[indexGovernadorEleito], percentualVotosGovernador);
        }
    }

    printf("- NULOS E BRANCOS: %d, %d", votosNulos, votosBrancos);
}