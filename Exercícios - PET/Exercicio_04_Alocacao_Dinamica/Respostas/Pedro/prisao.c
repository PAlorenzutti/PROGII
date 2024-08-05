#include "prisao.h"

tPrisao* criaPrisao(char* nome, int nCelas, int capacidadeCelas){
    tPrisao* prisao = malloc(sizeof(tPrisao));

    strcpy(prisao->nome, nome);
    prisao->dia = 0;
    prisao->nCelas = nCelas;
    prisao->capacidadeCelas = capacidadeCelas;
    prisao->celas = (tCela**) malloc(capacidadeCelas * sizeof(tCela**));

    return prisao;
}

void executaPrisao(tPrisao* prisao){
    printf("Informe a pena e o nome do prisioneiro:\n");

    char nome[MAXTAM_NOME];
    int pena;

    scanf("%d %[^\n]\n", &pena, nome);

    tPrisioneiro *p = criaPrisioneiro(nome, pena);
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

}

void passaDiaPrisao(tPrisao* prisao){
    prisao->dia++;
}

void registraFugaCelaPrisao(tPrisao* prisao){
    printf("Informe a cela em qual ocorreu a fuga:\n");

    int indexCela;
    scanf("%d\n", &indexCela);

    if(indexCela > 0 || indexCela < prisao->nCelas - 1){
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

    prisao->nCelas = 0;
}

void desalocaPrisao(tPrisao* prisao){
    for(int i = 0; i < prisao->nCelas; i++){
        desalocaCela(prisao->celas[i]);
    }

    free(prisao->celas);
    free(prisao);
}
