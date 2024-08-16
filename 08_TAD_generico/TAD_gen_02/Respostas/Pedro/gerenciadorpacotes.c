#include "gerenciadorpacotes.h"

#include <stdlib.h>

/**
 * @brief Cria uma TAD que gerencia pacotes. O pacote é um TAD genérico.
 *
 *
 * @return O gerenciador de pacotes
 */

struct gerenciadorpacotes{
    tPacote **pacotes;
    int numPacotes;
};

tGerenciador* CriaGerenciador(){
    tGerenciador *geren = (tGerenciador*)malloc(sizeof(tGerenciador));

    geren->numPacotes = 0;
    geren->pacotes = (tPacote**)malloc(sizeof(tPacote*));

    return geren;
}

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote 
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac){
    //coloca o pacote na atual posição do vetor;
    geren->pacotes[geren->numPacotes] = pac;
    
    //aumenta o numero de pacotes;
    geren->numPacotes++;

    //realoca o ponteiro de ponteiro de pacotes;
    geren->pacotes = (tPacote**)realloc(geren->pacotes, (geren->numPacotes + 1) * sizeof(tPacote*));
}


/**
 * @brief Destrói um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que será destruído (memória liberada)
 *
 */
void DestroiGerenciador(tGerenciador* geren){
    for(int i = 0; i < geren->numPacotes; i++){
        DestroiPacote(geren->pacotes[i]);
    }

    free(geren->pacotes);
    free(geren);
}

/**
 * @brief Imprime um pacote específico do gerenciador de pacotes.
 *
 * @param geren - O gerenciador de pacotes que terá um pacote impresso
 * @param idx - O índice do pacote a ser impresso (começa em zero!)
 *
 */
void ImprimirPacoteNoIndice(tGerenciador* geren, int idx){
    ImprimePacote(geren->pacotes[idx]);
}


/**
 * @brief Imprime todos os pacotes de um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que terá seus pacotes impressos
 *
 */
void ImprimirTodosPacotes(tGerenciador* geren){
    for(int i = 0; i < geren->numPacotes; i++){
        ImprimirPacoteNoIndice(geren, i);
    }
}