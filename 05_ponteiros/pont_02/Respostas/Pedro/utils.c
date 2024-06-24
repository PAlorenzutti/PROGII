#include "utils.h"
#include <stdio.h>

void LeIntervalo(int * m, int * n){
    scanf("%d %d", m, n);
}

int EhPrimo(int n){
    int divisiores = 0;
    
    for(int i = 1; i < n; i++){
        if(n % i == 0){
            divisiores++;
        }
    }

    if(divisiores == 1){
        return 1;
    }else{
        return 0;
    }
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior){
    *menor = n;
    *maior = m;
    
    for(int i = m; i <= n; i++){
        if(EhPrimo(i)){
            if(i < *menor){
                *menor = i;
            }

            if(i > *maior){
                *maior = i;
            }
        }
    }
}