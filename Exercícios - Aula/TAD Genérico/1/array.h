#ifndef _ARRAY_H

#define _ARRAY_H

typedef enum {
    INT,

    FLOAT,

    DOUBLE,

    CHAR
} TipoArray;

typedef struct Array Array;

Array *criaArray(int tam, TipoArray tipo);

void lerArray(Array *a);

void imprimeArray(Array *a);

int tamanhoArray(Array *a);

void desalocaArray(Array *a);

#endif