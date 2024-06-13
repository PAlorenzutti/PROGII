#include <stdio.h>


int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado){
    int numOcorrrencias = 0;
    
    if(numElementos == 0){
        return 0;
    }

    //vet[numElementos - 1] porque são 5 elementos, porém estão posicionados do 0 ao 4, por exemplo.

    if(vet[numElementos - 1] == numeroProcurado){
        numOcorrrencias++;
        return numOcorrrencias + ContaOcorrencias(vet, numElementos - 1, numeroProcurado);
    }else{
        return ContaOcorrencias(vet, numElementos - 1, numeroProcurado);
    }
}

/*
void printarVetor(int *vet, int numElementos){
    for(int i = 0; i < numElementos; i++){
        printf("%d ", vet[i]);
    }

    printf("\n");
}
*/

void lerVetor(){
    int numeroProcurado, numElementos;

    scanf("%d %d", &numeroProcurado, &numElementos);

    int vet[numElementos];

    //lendo os elementos do vetor N;

    for(int i = 0; i < numElementos; i++){
        scanf("%d", &vet[i]);
    }

    //printarVetor(vet, numElementos);

    printf("%d\n", ContaOcorrencias(vet, numElementos, numeroProcurado));
}

int main(){
    int N;

    scanf("%d", &N);

    for(N; N != 0; N--){
        lerVetor();
    }
}