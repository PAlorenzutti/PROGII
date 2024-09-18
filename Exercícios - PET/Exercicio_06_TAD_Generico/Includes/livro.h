#ifndef LIVRO_H
#define LIVRO_H

#define MAXTAM_STRINGS 100

typedef struct Livro Livro;

Livro* livro_construct(char *titulo, char *autor, char *genero, char* editora, int ano);

void livro_print(void* l);

void livro_destroy(void* l);


#endif