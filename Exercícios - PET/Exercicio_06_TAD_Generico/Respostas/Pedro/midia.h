#ifndef MIDIA_H 
#define MIDIA_H

typedef void (*PrintFunction)(void* data);
typedef void (*FreeFunction)(void* data);

typedef struct Midia Midia;

Midia *midia_construct(void *dado, PrintFunction print_fn, FreeFunction free_fn);

void midia_print(Midia* m);

void midia_destroy(Midia* m);


#endif