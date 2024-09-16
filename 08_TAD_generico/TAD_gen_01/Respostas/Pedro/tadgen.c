#include "tadgen.h"

#include <stdlib.h>
#include <stdio.h>

struct generic{
    Type tipo;
    void *dado;
    int numElem;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric *gen = (tGeneric*)malloc(sizeof(tGeneric));

    gen->numElem = numElem;
    gen->tipo = type;

    if(type == FLOAT){
        gen->dado = (float*)malloc(sizeof(float) * gen->numElem);
    }

    if(type == INT){
        gen->dado = (int*)malloc(sizeof(int) * gen->numElem);
    }

    return gen;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen){
    free(gen->dado);

    free(gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen){
    printf("\nDigite o vetor:\n");
    
    if(gen->tipo == FLOAT){
        for(int i = 0; i < gen->numElem; i++){
            if(i != gen->numElem - 1){
                scanf("%f ", &((float*)gen->dado)[i]);
            }else{
                scanf("%f\n", &((float*)gen->dado)[i]);
            }
        }
    }

    if(gen->tipo == INT){
        for(int i = 0; i < gen->numElem; i++){
            if(i != gen->numElem - 1){
                scanf("%d ", &((int*)gen->dado)[i]);
            }else{
                scanf("%d\n", &((int*)gen->dado)[i]);
            }
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen){
    if(gen->tipo == FLOAT){
        for(int i = 0; i < gen->numElem; i++){
            if(i != gen->numElem - 1){
                printf("%.2f ", ((float*)gen->dado)[i]);
            }else{
                printf("%.2f\n", ((float*)gen->dado)[i]);
            }
        }
    }

    if(gen->tipo == INT){
        for(int i = 0; i < gen->numElem; i++){
            if(i != gen->numElem - 1){
                printf("%d ", ((int*)gen->dado)[i]);
            }else{
                printf("%d\n", ((int*)gen->dado)[i]);
            }
        }
    }
}
