#include "cela.h"

tCela* criaCela(int capacidade){
    tCela * cela = (tCela*)malloc(sizeof(tCela));

    cela->capacidade = capacidade;
    cela->nPresidiarios = 0;
    cela->prisioneiros = (tPrisioneiro**)malloc(capacidade * sizeof(tPrisioneiro*));

    return cela;
}

int possuiVagaCela(tCela* cela){
    if(cela->capacidade > cela->nPresidiarios){
        return 1;
    }else{
        return 0;
    }
}

int obtemNumeroPrisioneirosCela(tCela* cela){
    return cela->nPresidiarios;
}


void inserePrisioneiroCela(tCela* cela, tPrisioneiro* prisioneiro){
    cela->prisioneiros[cela->nPresidiarios] = prisioneiro;
    cela->nPresidiarios++;
}

tPrisioneiro* obtemPrisioneiroCela(tCela* cela, int i){
    return cela->prisioneiros[i];
}

void fogePrisioneirosCela(tCela* cela){
    for(int i = 0; i < cela->nPresidiarios; i++){
        fogePrisioneiro(cela->prisioneiros[i]);
    }

    cela->nPresidiarios = 0;
}

void passaDiaCela(tCela* cela){
    for(int i = 0; i < cela->nPresidiarios; i++){
        passaTempoPrisioneiro(cela->prisioneiros[i]);

        if(acabouPenaPrisioneiro(cela->prisioneiros[i])){
            liberaPrisioneiroCumpriuPena(cela->prisioneiros[i]);
            
            for (int j = i; j < cela->nPresidiarios - 1; j++){  
                cela->prisioneiros[j] = cela->prisioneiros[j + 1]; 
            }  

            cela->nPresidiarios--;
            i--;
        }
    }
}

void desalocaCela(tCela* cela){
    for(int i = 0; i < cela->nPresidiarios; i++){
        liberaPrisioneiroFimPrograma(cela->prisioneiros[i]);
    }

    free(cela->prisioneiros);
    free(cela);
}