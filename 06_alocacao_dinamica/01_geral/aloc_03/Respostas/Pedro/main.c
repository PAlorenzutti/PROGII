#include "utils_char.h"

#include <stdio.h>

int main(){
    int tamanho;
    scanf("%d\n", &tamanho);
    
    char *vetor = CriaVetor(tamanho);

    ImprimeString(vetor, tamanho);

    LeVetor(vetor, tamanho);

    ImprimeString(vetor, tamanho);

    LiberaVetor(vetor);

    return 0;
}