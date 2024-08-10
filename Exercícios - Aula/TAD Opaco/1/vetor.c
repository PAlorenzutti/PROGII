#include "vetor.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Vetor{
    //ponteiro de floats, representando um vetor no Rn;
    float *coordenadas;

    //dimensão do vetor;
    int dimensao;
};

int printMenu(){
    printf("Menu:\n");
    printf(" 1 - Soma entre vetores do Rn\n");
    printf(" 2 - Diferença entre vetores do Rn\n");
    printf(" 3 - Produto entre vetores do Rn\n");
    printf(" 4 - Produto escalar do vetor do Rn\n");
    printf("Escolha uma opcao: ");

    int opcao;
    scanf("%d\n", &opcao);

    return opcao;
}

void somaVetores(tVetor *v1, tVetor *v2){
    printf("\n");

    if(v1->dimensao != v2->dimensao){
        printf("Vetores de dimensões diferentes.\n");
    }else{
        //aloca um vetor result;
        tVetor *result = (tVetor*) malloc(sizeof(tVetor));

        //cria um ponteiro de vetores com o tamanho dos dois vetores dados;
        result->coordenadas = (float*) malloc(sizeof(float) * (v1->dimensao));
        result->dimensao = v1->dimensao;

        //realiza a soma
        for(int i = 0; i < result->dimensao; i++){
            result->coordenadas[i] = v1->coordenadas[i] + v2->coordenadas[i];
        }

        //printa o vetor resultado
        printf("Resultado: ");
        printVetor(result);

        //desaloca resultado
        liberaVetor(result);
    }
}

void diferençaVetores(tVetor *v1, tVetor *v2){
    printf("\n");

    if(v1->dimensao != v2->dimensao){
        printf("Vetores de dimensões diferentes.\n");
    }else{
        //aloca um vetor result;
        tVetor *result = (tVetor*) malloc(sizeof(tVetor));

        //cria um ponteiro de vetores com o tamanho dos dois vetores dados;
        result->coordenadas = (float*) malloc(sizeof(float) * (v1->dimensao));
        result->dimensao = v1->dimensao;

        //realiza a soma
        for(int i = 0; i < result->dimensao; i++){
            result->coordenadas[i] = v1->coordenadas[i] - v2->coordenadas[i];
        }

        //printa o vetor resultado
        printf("Resultado: ");
        printVetor(result);

        //desaloca resultado
        liberaVetor(result);
    }
}

void produtoVetores(tVetor *v1, tVetor *v2){
    printf("\n");

    if(v1->dimensao != v2->dimensao){
        printf("Vetores de dimensões diferentes.\n");
    }else{
        //aloca um vetor result;
        tVetor *result = (tVetor*) malloc(sizeof(tVetor));

        //cria um ponteiro de vetores com o tamanho dos dois vetores dados;
        result->coordenadas = (float*) malloc(sizeof(float) * (v1->dimensao));
        result->dimensao = v1->dimensao;

        //realiza a soma
        for(int i = 0; i < result->dimensao; i++){
            result->coordenadas[i] = v1->coordenadas[i] * v2->coordenadas[i];
        }

        //printa o vetor resultado
        printf("Resultado: ");
        printVetor(result);

        //desaloca resultado
        liberaVetor(result);
    }
}

void escalarVetor(tVetor *v){
    printf("Digite o escalar que deseja: ");
    int escalar;
    scanf("%d\n", &escalar);
    
    //aloca um vetor result;
    tVetor *result = (tVetor*) malloc(sizeof(tVetor));

    //cria um ponteiro de vetores com o tamanho dos dois vetores dados;
    result->coordenadas = (float*) malloc(sizeof(float) * (v->dimensao));
    result->dimensao = v->dimensao;

    for(int i = 0; i < result->dimensao; i++){
        result->coordenadas[i] = v->coordenadas[i] * escalar;
    }

    //printa o vetor resultado
    printf("Resultado: ");
    printVetor(result);

    //desaloca resultado
    liberaVetor(result);
}

tVetor *criaVetor(){
    tVetor *v = (tVetor*) malloc(sizeof(tVetor));

    //inicializa o vetor com dimensão 0;
    v->dimensao = 0;

    //aloca somente uma posição no ponteiro de floats;
    v->coordenadas = (float*) malloc(sizeof(float) * (v->dimensao + 1));

    while(true){
        float numero;
        scanf("%f\n", &numero);

        if(numero == -1){
            break;
        }

        //coloca o numero na posição atual;
        v->coordenadas[v->dimensao] = numero;
        
        //aumenta a dimensão do vetor;
        v->dimensao++;

        //aumenta o vetor de floats;
        v->coordenadas = (float*) realloc(v->coordenadas, sizeof(float) * (v->dimensao + 1));
    }

    return v;
}

void printVetor(tVetor *v){
    printf("[");

    for(int i = 0; i < v->dimensao; i++){
        if(i == v->dimensao - 1){   
            printf("%.2f", v->coordenadas[i]);
        }else{
            printf("%.2f, ", v->coordenadas[i]);
        }
    }

    printf("]\n");
}

void liberaVetor(tVetor *v){
    //libera o ponteiro de floats
    free(v->coordenadas);
    
    free(v);
}