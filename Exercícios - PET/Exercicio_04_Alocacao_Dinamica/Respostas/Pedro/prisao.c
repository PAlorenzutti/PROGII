#include "prisao.h"

tPrisao* criaPrisao(char* nome, int nCelas, int capacidadeCelas){
    tPrisao* prisao = (tPrisao*)malloc(sizeof(tPrisao));

    strcpy(prisao->nome, nome);
    prisao->dia = 0;
    prisao->nCelas = nCelas;
    prisao->capacidadeCelas = capacidadeCelas;
    prisao->celas = (tCela**)malloc(nCelas * sizeof(tCela*));

    //cria cada cela individualmente;
    for(int i = 0; i < prisao->nCelas; i++){
        prisao->celas[i] = criaCela(capacidadeCelas);
    }

    return prisao;
}

void executaPrisao(tPrisao* prisao){
    while(1){
        imprimeDiaEMenuPrisao(prisao);

        char opcao;
        scanf("%c\n", &opcao);

        if(opcao == 'I'){
            inserePrisioneiroPrisao(prisao);
        }

        if(opcao == 'P'){
            passaDiaPrisao(prisao);
        }

        if(opcao == 'F'){
            registraFugaCelaPrisao(prisao);
        }

        if(obtemNumeroPrisioneirosPrisao(prisao) == (prisao->capacidadeCelas * prisao->nCelas)){
            printf("REBELIAO GERAL\n");
            rebeliaoGeralPrisao(prisao);
            break;
        }

        if(opcao == 'E'){
            break;
        }
    }
}

void imprimeDiaEMenuPrisao(tPrisao* prisao){
    printf("Dia %d na prisao de %s\n", prisao->dia, prisao->nome);
    printf("Menu:\n");
    printf(" I - Inserir detento\n");
    printf(" P - Passar o dia\n");
    printf(" F - Registrar fuga de cela\n");
    printf(" E - Encerrar programa\n");
}

void inserePrisioneiroPrisao(tPrisao* prisao){
    printf("Informe a pena e o nome do prisioneiro:\n");

    char nome[MAXTAM_NOME];
    int pena;

    scanf("%d %[^\n]\n", &pena, nome);

    if(pena < 1){
        printf("Valor invalido\n");
    }else{
        tPrisioneiro *p = criaPrisioneiro(nome, pena);

        for(int i = 0; i < prisao->nCelas; i++){
            if(possuiVagaCela(prisao->celas[i])){
                inserePrisioneiroCela(prisao->celas[i], p);
                printf("Detento %s foi inserido na cela %d\n", nome, i);
                break;
            }
        }
    }
}

void passaDiaPrisao(tPrisao* prisao){
    //passa o dia da prisão
    prisao->dia++;

    //passa o dia das celas
    for(int i = 0; i < prisao->nCelas; i++){
        passaDiaCela(prisao->celas[i]);
    }
}

void registraFugaCelaPrisao(tPrisao* prisao){
    printf("Informe a cela em qual ocorreu a fuga:\n");

    int indexCela;
    scanf("%d\n", &indexCela);

    if(indexCela >= 0 && indexCela < prisao->nCelas){
        fogePrisioneirosCela(prisao->celas[indexCela]);
    }else{
        printf("Valor invalido\n");
    }
}

int obtemNumeroPrisioneirosPrisao(tPrisao* prisao){
    int nPrisioneiros = 0;
    
    for(int i = 0; i < prisao->nCelas; i++){
        nPrisioneiros += obtemNumeroPrisioneirosCela(prisao->celas[i]);
    }

    return nPrisioneiros;
}

void rebeliaoGeralPrisao(tPrisao* prisao){
    for(int i = 0; i < prisao->nCelas; i++){
        fogePrisioneirosCela(prisao->celas[i]);
    }
}

void desalocaPrisao(tPrisao* prisao){
    for(int i = 0; i < prisao->nCelas; i++){
        desalocaCela(prisao->celas[i]);
    }

    free(prisao->celas);
    free(prisao);
}