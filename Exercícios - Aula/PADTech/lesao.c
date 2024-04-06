#include <stdio.h>
#include <string.h>
#include "lesao.h"

Lesao lerLesao()
{
    Lesao l;
    scanf("%s\n", l.cartaoSus);
    scanf("%s\n", l.id);
    scanf("%[^\n]\n", l.diagnostico);
    scanf("%s\n", l.regiao);
    scanf("%d\n", &l.chanceMalig);

    return l;
}

void obtemCartaoSusLesao(Lesao les, char cartaoSus[])
{
    //Copia o cartão SUS que acabou de ser inserido para o char criado na função associaLesaoPaciente
    strcpy(cartaoSus, les.cartaoSus);
}

int consultaLesao(Lesao lesao[], int qtdLesoes, Lesao les){
    for(int i = 0; i < qtdLesoes; i++){
        if(strcmp(lesao[i].id, les.id) == 0){
            return 0;
        }
    }

    return 1;
}

int chanceCirurgia(Lesao les[], int qtdLes){
    int numeroCirurgias = 0;

    for(int i = 0; i < qtdLes; i++){
        if(les[i].chanceMalig > 50){
            numeroCirurgias++;
        }
    }

    return numeroCirurgias;
}

void printLesao(Lesao les){
    printf("%s ", les.id);
}
