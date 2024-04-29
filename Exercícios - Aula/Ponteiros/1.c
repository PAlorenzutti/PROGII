#include <stdio.h>

int ordena(int *valor1, int *valor2, int *valor3){
    int temp;
    // 8 5 2
    if(*valor1 > *valor2){
        temp = *valor2;
        *valor2 = *valor1;
        *valor1 = temp;
        //5 8 2
    }

    if(*valor2 > *valor3){
        temp = *valor3;
        *valor3 = *valor2;
        *valor2 = temp;
        // 5 2 8
    }

    if(*valor1 > *valor2){
        temp = *valor2;
        *valor2 = *valor1;
        *valor1 = temp;
        //2 5 8
    }

    if(*valor1 == *valor2 && *valor2 == *valor3){
        return 0;
    }else{
        return 1;
    }
}

int main(){
    int valor1, valor2, valor3;
    
    scanf("%d %d %d", &valor1, &valor2, &valor3);

    int valorOrdem = ordena(&valor1, &valor2, &valor3);

    if(valorOrdem > 0){
        printf("%d < %d < %d", valor1, valor2, valor3);
    }else{
        printf("%d = %d = %d", valor1, valor2, valor3);
    }

    return 0;
}