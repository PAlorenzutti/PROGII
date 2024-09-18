#ifndef PINTURA_H
#define PINTURA_H

#define MAXTAM_STRINGS 100

typedef struct Pintura Pintura;

Pintura* pintura_construct(char *titulo, char *artista, char *movimento, char* material, int ano);

void pintura_print(void* p);

void pintura_destroy(void* p);


#endif