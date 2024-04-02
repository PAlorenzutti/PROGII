#include <stdio.h>
#include "multa.h"

int main(){
    int quantidade;

    printf("Digite a quantidade de terrenos a serem lidos: ");
    scanf("%d", &quantidade);
    getchar();

    tCirculo c;
    tRetangulo r;
    tTriangulo t;

    float multas[quantidade];

    //Pegando as informações de todos os terrenos.
    for(int i = 0; i < quantidade; i++){
        char tipo;
        printf("\nC - Circular");
        printf("\nR - Retangular");
        printf("\nT - Triangular");
        printf("\nDigite o tipo de terreno: ");
        scanf(" %c", &tipo);
        getchar();

        if(tipo == 'C'){
            printf("\nDigite o raio do terreno circular: ");
            scanf("%f", &c.raio);
            multas[i] = multaCircular(c);
        }

        if(tipo == 'R'){
            printf("\nDigite o comprimento e largura do terreno retangular, respectivamente: ");
            scanf("%f %f", &r.comprimento, &r.largura);
            multas[i] = multaRetangular(r);
        }

        if(tipo == 'T'){
            printf("\nDigite a base e altura do terreno triangular, respectivamente: ");
            scanf("%f %f", &t.base, &t.altura);
            multas[i] = multaTriangular(t);
        }
    }

    //Printando todas as multas em lista.
    for(int i = 0; i < quantidade; i++){
        printf("\nPreco: %.2f", multas[i]);
    }


    return 0;
}