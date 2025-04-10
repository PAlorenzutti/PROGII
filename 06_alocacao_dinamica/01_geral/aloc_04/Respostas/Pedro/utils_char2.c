#include "utils_char2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Cria um vetor de caracteres que consegue armazenar uma string de tamanho igual a "TAM_PADRAO", alocado dinamicamente.
 * Neste caso, a string deve ser inicializada com todas as suas "TAM_PADRAO" posições com "_", e a última posição deve conter '\0'.
 * Se houver erro na alocação, imprime uma mensagem de erro e encerra o programa.
 * 
 * @return Ponteiro para o vetor criado.
 */
char *CriaVetorTamPadrao(){
    //aloca uma string;
    char *vetor = (char*) malloc(TAM_PADRAO + 1 * sizeof(char));

    for(int i = 0; i < TAM_PADRAO; i++){
        vetor[i] = '_';
    }

    vetor[TAM_PADRAO] = '\0';

    return vetor;
}

/**
 * Aumenta o tamanho de um vetor alocado dinamicamente
 * O vetor deve ser aumentado para conseguir alocar mais "TAM_PADRAO" caracteres (o vetor só pode ter tamanhos múltiplos de "TAM_PADRAO")
 * Preencha as novas posições com "_", e lembre-se que a última deve conter '\0'.
 * 
 * @param tamanhoantigo Tamanho do vetor a ser modificado
 * @return Ponteiro para o novo vetor.
 */
char *AumentaTamanhoVetor(char* vetor, int tamanhoantigo){
    vetor = (char*) realloc(vetor, (tamanhoantigo + TAM_PADRAO + 1) * sizeof(char));

    for(int i = tamanhoantigo; i < tamanhoantigo + TAM_PADRAO; i++){
        vetor[i] = '_';
    }

    vetor[TAM_PADRAO + tamanhoantigo] = '\0';

    return vetor;
}

/**
 * Lê uma string do tamanho especificado até um enter ser apertado.
 * Caso seja necessário alterar o tamanho do vetor, o tamanho deve ser atualizado para que o programa
 * saiba o novo tamanho do vetor.
 *
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho* Ponteiro para uma variável do tipo inteiro que armazena o tamanho atual do vetor.
 * @return Um ponteiro para o vetor lido.
*/
char* LeVetor(char *vetor, int *tamanho){
    char tecla;

    int i = 0;

    while(1){
        scanf("%c", &tecla);

        if(i == *tamanho){
            vetor = AumentaTamanhoVetor(vetor, *tamanho);
            *tamanho += TAM_PADRAO;
        }

        if(tecla == '\n'){
            break;
        }else{
            vetor[i] = tecla;
        }

        i++;
    }

    return vetor;
}

/**
 * Imprime a string
 * 
 * @param vetor Ponteiro para o vetor a ser imprimido.
*/
void ImprimeString(char *vetor){
    printf("%s", vetor);
}

/**
 * Libera a memória alocada para um vetor de caracteres.
 * 
 * @param vetor Ponteiro para o vetor a ser liberado.
*/
void LiberaVetor(char *vetor){
    free(vetor);
}
