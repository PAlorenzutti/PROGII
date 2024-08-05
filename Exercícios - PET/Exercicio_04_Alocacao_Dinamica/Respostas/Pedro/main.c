#include "prisao.h"

int main(){
    char nome[MAXTAM_NOME];
    int nCelas;
    int capacidadeCelas;

    scanf("%[^\n]\n", nome);
    scanf("%d %d\n", &nCelas, &capacidadeCelas);

    tPrisao *prisao = criaPrisao(nome, nCelas, capacidadeCelas);

    executaPrisao(prisao);

    desalocaPrisao(prisao);

    return 0;
}