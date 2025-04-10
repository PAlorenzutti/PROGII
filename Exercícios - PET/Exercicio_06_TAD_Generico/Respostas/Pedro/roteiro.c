#include "roteiro.h"

#include <stdlib.h>
#include <stdio.h>

struct Roteiro{
    Midia **midias;
    int qtdMidias;
};

Roteiro *roteiro_construct(){
    Roteiro *r = (Roteiro*)malloc(sizeof(Roteiro));

    //inicializa roteiro;
    r->midias = NULL;
    r->qtdMidias = 0;

    return r;
}

void roteiro_inserir_midia(Roteiro* r, void *dado,  PrintFunction print_fn, FreeFunction free_fn){
    r->qtdMidias++;
    r->midias = (Midia**)realloc(r->midias, sizeof(Midia*) * r->qtdMidias);
    r->midias[r->qtdMidias - 1] = midia_construct(dado, print_fn, free_fn);
}

void roteiro_imprimir_midias(Roteiro *r){
    if(r->midias != NULL){
        printf("IMPRIMINDO MIDIAS\n");
        
        for(int i = 0; i < r->qtdMidias; i++){
            printf("MIDIA %d: ", i + 1);
            
            midia_print(r->midias[i]);

            printf("\n");
        }
    }else{
        printf("SEM MIDIAS PARA IMPRIMIR\n");
    }
}

void roteiro_destroy(Roteiro *r){
    if(r->midias != NULL){
        for(int i = 0; i < r->qtdMidias; i++){
            midia_destroy(r->midias[i]);
        }

        free(r->midias);
    }

    free(r);
}
