#include <stdio.h>
#include "pessoa.h"

int main(){
    //Pegando o número de pessoas a serem inseridas
    int numPessoas;
    scanf("%d\n", &numPessoas);

    //criando vetor com pessoas
    tPessoa pessoas[numPessoas];

    //loop para ler pessoas
    for(int i = 0; i < numPessoas; i++){
        pessoas[i] = CriaPessoa();

        LePessoa(&pessoas[i]);
    }

    AssociaFamiliasGruposPessoas(pessoas);

    //se não tiver pai nem mãe, não imprime
    for(int i = 0; i < numPessoas; i++){
        ImprimePessoa(&pessoas[i]);
    }

    return 0;
}