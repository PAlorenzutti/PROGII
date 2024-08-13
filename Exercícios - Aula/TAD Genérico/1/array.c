#include "array.h"

struct Array {
    void *dado;
    int tam;
    TipoArray tipo;
};

Array *criaArray(int tam, TipoArray tipo){
    Array *a = (Array *)malloc(sizeof(Array));

    a->tam = tam;
    a->tipo = tipo;

    switch (tipo) {
        case INT:
            a->dado = malloc(tam * sizeof(int));
            break;

        case FLOAT:
            a->dado = malloc(tam * sizeof(float));
            break;

        case DOUBLE:
            a->dado = malloc(tam * sizeof(double));
            break;

        case CHAR:
            a->dado = malloc(tam * sizeof(char));
            break;
    }

    return a;
}

void lerArray(Array *a){
    int i;

    switch (a->tipo) {
        case INT:
            for (i = 0; i < a->tam; i++) {
                scanf("%d", (int *)a->dado + i);
            }

            break;

        case FLOAT:
            for (i = 0; i < a->tam; i++) {
                scanf("%f", (float *)a->dado + i);
            }

            break;

        case DOUBLE:
            for (i = 0; i < a->tam; i++) {
                scanf("%lf", (double *)a->dado + i);
            }

            break;

        case CHAR:
            for (i = 0; i < a->tam; i++) {
                scanf("%c*", (char *)a->dado + i);
            }

            break;
    }
}