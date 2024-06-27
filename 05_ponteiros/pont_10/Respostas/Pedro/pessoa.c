#include "pessoa.h"
#include <stdio.h>
#include <string.h>

tPessoa CriaPessoa(){
    tPessoa pessoa;

    pessoa.nome[0] = '\0';
    pessoa.pai = NULL;
    pessoa.mae = NULL;
    pessoa.irmao = NULL;

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

        printf("IRMAO: ");
        if( (*pessoa).irmao == NULL ){
            printf("NAO INFORMADO\n");
        }else{
            printf("%s\n", (*(*pessoa).irmao).nome);
        }

        printf("\n");
    }
}

int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2){
    if( (*pessoa1).pai == (*pessoa2).pai && (*pessoa1).mae == (*pessoa2).mae ){
        return 1;
    }else{
        return 0;
    }
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas){
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

    for(int i = 0; i < numPessoas; i++){
        for(int j = 0; j < numPessoas - 1; j++){
            if(VerificaIrmaoPessoa(&pessoas[i], &pessoas[j]) && &pessoas[i] != &pessoas[j]){
                pessoas[i].irmao = &pessoas[j];
            } 
        }
    }
}