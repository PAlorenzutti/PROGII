#include <stdio.h>
#include <math.h>

void frac(float num, int* inteiro, float* frac){
    int limite = num;
    
    *inteiro = 0;
    
    for(int i = 0; limite > 0; i++){
        *inteiro += (limite % 10) * pow(10, i);
        limite = limite / 10; 
    }

    *frac = num - *inteiro;
}


int main(){
    float numero, fracional;
    int inteiro;

    scanf("%f", &numero);

    frac(numero, &inteiro, &fracional);

    printf("Parte inteira: %d", inteiro);
    printf("\nParte fracionaria: %.2f", fracional);

    return 0;
}