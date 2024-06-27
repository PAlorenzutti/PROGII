#include <stdio.h>
#include "calculadora.h"

float adicao(float num1, float num2){
    return num1 + num2;
}

float subtracao(float num1, float num2){
    return num1 - num2;
}

float multi(float num1, float num2){
    return num1 * num2;
}

float divisao(float num1, float num2){
    return num1 / num2;
}

int main(){
    //pegando o primeiro caractere
    char opcao;
    scanf("%c\n", &opcao);

    while(opcao != 'f'){
        //pegando os dois numeros;
        float num1, num2;
        scanf("%f %f", &num1, &num2);
        
        if(opcao == 'a'){
            printf("%.2f + %.2f = %.2f\n", num1, num2, Calcular(num1, num2, adicao));
        }

        if(opcao == 's'){
            printf("%.2f - %.2f = %.2f\n", num1, num2, Calcular(num1, num2, subtracao));
        }

        if(opcao == 'm'){
            printf("%.2f x %.2f = %.2f\n", num1, num2, Calcular(num1, num2, multi));
        }

        if(opcao == 'd'){
            printf("%.2f / %.2f = %.2f\n", num1, num2, Calcular(num1, num2, divisao));
        }

        if(opcao == 'f'){
            break;
        }

        scanf("%c\n", &opcao);
    }

    return 0;
}