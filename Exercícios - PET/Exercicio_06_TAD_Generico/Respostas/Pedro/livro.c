#include "livro.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Livro{
    char *titulo;
    char *autor;
    char *genero;
    char *editora;
    int ano;
};

Livro* livro_construct(char *titulo, char *autor, char *genero, char* editora, int ano){
    Livro *l = (Livro*)malloc(sizeof(Livro));

    l->titulo = (char*)malloc(sizeof(char) * MAXTAM_STRINGS);
    l->autor = (char*)malloc(sizeof(char) * MAXTAM_STRINGS);
    l->genero = (char*)malloc(sizeof(char) * MAXTAM_STRINGS);
    l->editora = (char*)malloc(sizeof(char) * MAXTAM_STRINGS);
    
    strcpy(l->titulo, titulo);
    strcpy(l->autor, autor);
    strcpy(l->genero, genero);
    strcpy(l->editora, editora);
    l->ano = ano;

    return l;
}

void livro_print(void* l){
    Livro *livro = (Livro*) l;
    
    printf("LIVRO\n");
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Genero: %s\n", livro->genero);
    printf("Editora: %s\n", livro->editora);
    printf("Ano: %d\n", livro->ano);
}

void livro_destroy(void* l){
    Livro *livro = (Livro*) l;

    free(livro->titulo);
    free(livro->autor);
    free(livro->genero);
    free(livro->editora);

    free(l);
}
