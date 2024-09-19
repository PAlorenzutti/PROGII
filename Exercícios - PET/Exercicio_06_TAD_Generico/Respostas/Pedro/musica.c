#include "musica.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Musica{
    char *titulo;
    char *artista;
    int nParticipantes;
    char **participantes;
    char *album;
    char *genero;
};

Musica* musica_construct(char *titulo, char *artista, int nParticipantes, char participantes[MAXTAM_PARTICIPANTES][MAXTAM_STRINGS], char *album, char *genero){
    Musica *m = (Musica*)malloc(sizeof(Musica));

    m->titulo = (char*)malloc(sizeof(char) * MAXTAM_STRINGS);
    m->artista = (char*)malloc(sizeof(char) * MAXTAM_STRINGS);
    m->album = (char*)malloc(sizeof(char) * MAXTAM_STRINGS);
    m->genero = (char*)malloc(sizeof(char) * MAXTAM_STRINGS);

    strcpy(m->titulo, titulo);
    strcpy(m->artista, artista);
    m->nParticipantes = nParticipantes;

    if(nParticipantes){
        m->participantes = (char**)malloc(sizeof(char*) * m->nParticipantes);

        for(int i = 0; i < m->nParticipantes; i++){
            m->participantes[i] = (char*)malloc(sizeof(char) * MAXTAM_STRINGS);

            strcpy(m->participantes[i], participantes[i]);
        }
    }else{
        m->participantes = NULL;
    }

    strcpy(m->album, album);
    strcpy(m->genero, genero);

    return m;
}

void musica_print(void* m){
    Musica *musica = (Musica*) m;

    printf("MUSICA\n");

    printf("%s - %s", musica->artista, musica->titulo);

    if(musica->participantes != NULL){
        printf(" (feat. ");

        for(int i = 0; i < musica->nParticipantes; i++){
            if(i == musica->nParticipantes - 1){
                printf("%s)", musica->participantes[i]);
            }else{
                printf("%s, ", musica->participantes[i]);
            }
        }
    }

    printf("\n");

    printf("Album: %s\n", musica->album);
    printf("Genero: %s\n", musica->genero);
}

void musica_destroy(void* m){
    Musica *musica = (Musica*) m;

    free(musica->titulo);
    free(musica->artista);

    for(int i = 0; i < musica->nParticipantes; i++){
        free(musica->participantes[i]);
    }

    free(musica->participantes);
    free(musica->album);
    free(musica->genero);

    free(musica);
}
