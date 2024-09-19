#include "pintura.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pintura{
    char *titulo;
    char *artista;
    char *movimento;
    char *material;
    int ano;
};

Pintura* pintura_construct(char *titulo, char *artista, char *movimento, char* material, int ano){
    Pintura *p = (Pintura*)malloc(sizeof(Pintura));

    p->titulo = (char*)malloc(sizeof(char) * MAXTAM_STRINGS);
    p->artista = (char*)malloc(sizeof(char) * MAXTAM_STRINGS);
    p->movimento = (char*)malloc(sizeof(char) * MAXTAM_STRINGS);
    p->material = (char*)malloc(sizeof(char) * MAXTAM_STRINGS);

    strcpy(p->titulo, titulo);
    strcpy(p->artista, artista);
    strcpy(p->movimento, movimento);
    strcpy(p->material, material);
    p->ano = ano;

    return p;
}

void pintura_print(void* p){
    Pintura *pintura = (Pintura*) p;

    printf("PINTURA\n");

    printf("Titulo: %s\n", pintura->titulo);
    printf("Artista: %s\n", pintura->artista);
    printf("Movimento: %s\n", pintura->movimento);
    printf("Material: %s\n", pintura->material);
    printf("Ano: %d\n", pintura->ano);
}

void pintura_destroy(void* p){
    Pintura *pintura = (Pintura*) p;

    free(pintura->titulo);
    free(pintura->artista);
    free(pintura->movimento);
    free(pintura->material);

    free(pintura);
}