#include "pessoa.h"
#include <stdio.h>
#include <string.h>

tPessoa CriaPessoa(){
    tPessoa pessoa;

    pessoa.nome[0] = '\0';
    pessoa.pai = NULL;
    pessoa.mae = NULL;

    return pessoa;
}

void LePessoa(tPessoa *pessoa){
    char nome[100];
    scanf("%s", nome);

    strcpy((*pessoa).nome, nome);
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa){
}

void ImprimePessoa(tPessoa *pessoa){
    printf("NOME COMPLETO: %s\n", (*pessoa).nome);
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas){
    int associacoes;
    scanf("%d", &associacoes);

    for(int i = 0; i < associacoes; i++){
        int mae, pai, filho;
        scanf("mae: %d, pai: %d, filho: %d", &mae, &pai, &filho);

        if(mae != -1){
            //filho recebe mãe
            *pessoas[filho].mae = pessoas[mae];
        }

        if(pai != -1){
            //filho recebe pai
            *pessoas[filho].pai = pessoas[pai];
        }
    }
}