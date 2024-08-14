#include "pacote.h"

#include <stdio.h>
#include <stdlib.h>

struct pacote{
    void *data;
    Type type;
    int numElem;
    int soma;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem){
    tPacote *pac = (tPacote*)malloc(sizeof(tPacote));

    pac->numElem = numElem;
    pac->type = type;
    
    if(pac->type == INT){
        pac->data = malloc(pac->numElem * sizeof(int));
    }

    if(pac->type == CHAR){
        pac->data = malloc(pac->numElem * sizeof(char));
    }

    return pac;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac){
    free(pac->data);
    free(pac);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac){
    printf("\nDigite o conteúdo do vetor/mensagem: ");
    
    if(pac->type == INT) {
        for(int i = 0; i < pac->numElem; i++) {
            scanf("%d", &((int*)pac->data)[i]);
        }
    }
    
    if(pac->type == CHAR) {
        for(int i = 0; i < pac->numElem; i++) {
            scanf("%c", &((char*)pac->data)[i]); 
        }
    }

    
        CalculaSomaVerificacaoPacote(pac);
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac){
    printf("%d ", pac->soma);

    if(pac->type == INT){
        for(int i = 0; i < pac->numElem; i++){
            printf("%d ", ((int*)pac->data)[i]);
        }
    }

    if(pac->type == CHAR){
        for(int i = 0; i < pac->numElem; i++){
            printf("%c", ((char*)pac->data)[i]);
        }
    }

    printf("\n");
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac){
    pac->soma = 0;

    if (pac->type == INT) {
        for(int i = 0; i < pac->numElem; i++) {
            pac->soma += ((int*)pac->data)[i];
        }
    }
    
    if (pac->type == CHAR) {
        for(int i = 0; i < pac->numElem; i++) {
            pac->soma += ((char*)pac->data)[i];
        }
    }
}
