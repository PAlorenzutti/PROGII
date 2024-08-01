#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int tamanho = 0;
    float *vetor = malloc((tamanho + 1) * sizeof(float));

    while(true){
        float nota;
        scanf("%f\n", &nota);

        if(nota < 0){
            break;
        }

        //o primeiro fica na posição 0;
        vetor[tamanho] = nota;

        //outra notação:
        //*(vetor + tamanho) = nota;

        tamanho++;
        vetor = realloc(vetor, (tamanho + 1) * sizeof(int));
    }

    //calcular a média
    float media = 0;
    
    for(int i = 0; i < tamanho; i++){
        media += vetor[i];
    }

    media /= tamanho;

    //calcular o desvio padrão;
    float desvio = 0;

    for(int i = 0; i < tamanho; i++){
        desvio += pow(vetor[i] - media, 2);
    }

    desvio = sqrt(desvio / tamanho);

    //printar média e desvio;

    printf("Media = %.2f\n", media);

    printf("Desvio Padrao = %.2f\n", desvio);

    return 0;
}
