#include <stdio.h>

int SomaElementosPares(int *vet, int numElementos){
    int soma = 0;

    if(numElementos == 0){
        return 0;
    }

    if(vet[numElementos - 1] % 2 == 0){
        soma += vet[numElementos - 1];
        return soma + SomaElementosPares(vet, numElementos - 1);
    }else{
        return SomaElementosPares(vet, numElementos - 1);
    }
}

void lerVetor(){
    int numElementos;

    scanf("%d", &numElementos);

    int vet[numElementos];

    //lendo os elementos do vetor N;

    for(int i = 0; i < numElementos; i++){
        scanf("%d", &vet[i]);
    }

    printf("%d\n", SomaElementosPares(vet, numElementos));
}

int main(){
    int N;

    scanf("%d", &N);

    for(N; N != 0; N--){
        lerVetor();
    }
    
    return 0;
}