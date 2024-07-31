#include "pessoa.h"

void setNome(tPessoa *p){
    scanf("%[^\n]\n", p->nome);
}

void setData(tPessoa *p){
    leData(&p->nascimento);
}

void setCPF(tPessoa *p){
    while(true){
        char *CPF = malloc(sizeof(CPF));
        scanf("%s\n", CPF);

        if(verificaCPFValidoPessoa(CPF)){
            printf("CPF válido.\n");

            strcpy(p->CPF, CPF);

            break;
        }else{
            printf("CPF inválido, digite novamente: ");
        }
    }
}

tPessoa* criaPessoa(){
    tPessoa* p = malloc(sizeof(tPessoa));

    setNome(p);
    setData(p);
    setCPF(p);

    return p;
}

char* getNome(tPessoa *p){
    return p->nome;
}

tData* getData(tPessoa *p){
    return &p->nascimento;
}

char* getCPF(tPessoa *p){
    return p->CPF;
}

void printaPessoa(tPessoa *p){
    printf("Nome: %s\n", getNome(p));

    printaData(getData(p));

    printf("CPF: %s\n", getCPF(p));
}

void liberaPessoa(tPessoa *p){
    free(p);
}

int verificaCPFValidoPessoa(char *CPF){
    //extraindo os nove dígitos     
    int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
    sscanf(CPF, "%1d%1d%1d.%1d%1d%1d.%1d%1d%1d-%1d%1d", &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, &d10, &d11);
    
    int primeiro = ( 10 * (d1 * 10 + d2 * 9 + d3 * 8 + d4 * 7 + d5 * 6 + d6 * 5 + d7 * 4 + d8 * 3 + d9 * 2) ) % 11;
    int segundo = ( 10 * (d1 * 11 + d2 * 10 + d3 * 9 + d4 * 8 + d5 * 7 + d6 * 6 + d7 * 5 + d8 * 4 + d9 * 3 + d10 * 2) ) % 11;

    if(primeiro == 10){
        primeiro = 0;
    }

    if(segundo == 10){
        segundo = 0;
    }

    if(primeiro == d10 && segundo == d11){
        return 1;
    }else{
        return 0;
    }
}