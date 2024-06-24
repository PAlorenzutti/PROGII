#include "utils.h"

int TrocaInterios(int * n1, int * n2){
    if(*n1 > *n2){
        int temp;
        temp = *n1;
        *n1 = *n2;
        *n2 = temp;

        return 1;
    }

    return 0;
}