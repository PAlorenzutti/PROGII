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
    scanf("%[^\n]\n", (*pessoa).nome);    
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa){
    //verifica pai e mae
    if( (*pessoa).pai == NULL && (*pessoa).mae == NULL ){
        return 0;
    }

    return 1;
}

void ImprimePessoa(tPessoa *pessoa){
    if(VerificaSeTemPaisPessoa(pessoa)){
        printf("NOME COMPLETO: %s\n", (*pessoa).nome);

        //verificação pai
        printf("PAI: ");
        if( (*pessoa).pai == NULL ){
            printf("NAO INFORMADO\n");
        }else{
            printf("%s\n", (*(*pessoa).pai).nome);
        }

        //verificação mae
        printf("MAE: ");
        if( (*pessoa).mae == NULL ){
            printf("NAO INFORMADO\n");
        }else{
            printf("%s\n", (*(*pessoa).mae).nome);
        }

        printf("\n");
    }
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas){
    int associacoes;
    scanf("%d\n", &associacoes);

    for(int i = 0; i < associacoes; i++){
        int mae, pai, filho;
        scanf("mae: %d, pai: %d, filho: %d\n", &mae, &pai, &filho);

        if(mae != -1){
            //filho recebe mãe
            pessoas[filho].mae = &pessoas[mae];
        }

        if(pai != -1){
            //filho recebe pai
            pessoas[filho].pai = &pessoas[pai];
        }
    }
}