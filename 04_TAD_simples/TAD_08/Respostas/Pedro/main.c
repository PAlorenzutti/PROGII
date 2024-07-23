#include "departamento.h"

#include <stdio.h>

int main(){
    int tamanho;
    scanf("%d\n", &tamanho);

    tDepartamento d[tamanho];

    for(int i = 0; i < tamanho; i++){
        char nome[STRING_MAX];
        scanf("%s\n", nome);

        char diretor[STRING_MAX];
        scanf("%s\n", diretor);

        char c1[STRING_MAX];
        scanf("%s\n", c1);

        char c2[STRING_MAX];
        scanf("%s\n", c2);

        char c3[STRING_MAX];
        scanf("%s\n", c3);

        int m1, m2, m3;
        scanf("%d %d %d\n", &m1, &m2, &m3);

        d[i] = criaDepartamento(c1, c2, c3, nome, m1, m2, m3, diretor);
    }

    ordenaPorMediaDepartamentos(d, tamanho);

    for(int i = 0; i < tamanho; i++){
        imprimeAtributosDepartamento(d[i]);
    }

    return 0;
}