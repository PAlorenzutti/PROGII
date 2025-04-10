#include "pacote.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    pac->soma = 0;
    
    if(pac->type == INT){
        pac->data = malloc(pac->numElem * sizeof(int));
    }

    if(pac->type == CHAR){
        pac->data = malloc(pac->numElem + 1* sizeof(char));
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
        getchar();
        fgets(pac->data, pac->numElem + 1, stdin);

        size_t len = strlen((char*)pac->data);
        if (len > 0 && ((char*)pac->data)[len - 1] == '\n') {
            ((char*)pac->data)[len - 1] = '\0';
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
        printf("%s", pac->data);
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
