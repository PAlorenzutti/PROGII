#ifndef MUSICA_H
#define MUSICA_H

#define MAXTAM_STRINGS 100
#define MAXTAM_PARTICIPANTES 5

typedef struct Musica Musica;

Musica* musica_construct(char *titulo, char *artista, int nParticipantes, char participantes[MAXTAM_PARTICIPANTES][MAXTAM_STRINGS], char *album, char *genero);

void musica_print(void* m);

void musica_destroy(void* m);


#endif