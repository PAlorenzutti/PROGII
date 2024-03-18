//Triângulo de Floyd

#include <stdio.h>

int main(){
    int n, numeroAtual = 1;
    int i, j;

    printf("Digite o número de linhas do triângulo:\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        for(j = 0; j < i; j++){
            printf("%d ", numeroAtual);
            numeroAtual += 1;
        }

        printf("\n");
    }

    return 0;
}