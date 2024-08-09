#include "utils_char2.h"

int main(){
    char *vetor = CriaVetorTamPadrao();
    int tamanho = TAM_PADRAO;

    vetor = LeVetor(vetor, &tamanho);

    ImprimeString(vetor);

    LiberaVetor(vetor);

    return 0;
}