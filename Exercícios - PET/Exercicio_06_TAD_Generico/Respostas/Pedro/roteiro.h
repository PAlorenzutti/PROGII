#ifndef ROTEIRO_H
#define ROTEIRO_H

#include "midia.h"

typedef struct Roteiro Roteiro;

Roteiro *roteiro_construct();

void roteiro_inserir_midia(Roteiro* r, void *dado,  PrintFunction print_fn, FreeFunction free_fn);

void roteiro_imprimir_midias(Roteiro *r);

void roteiro_destroy(Roteiro *r);

#endif