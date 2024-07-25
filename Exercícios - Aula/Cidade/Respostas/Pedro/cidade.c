#include "cidade.h"

#include <stdio.h>
#include <stdbool.h>

tCidade criaCidade(){
    tCidade cidade;

    scanf("C %f %f", &cidade.X, &cidade.Y);

    cidade.qtdDefesas = 0;
    cidade.qtdMisseis = 0;

    //leitura das defesas e dos mísseis;
    while(true){
        char tipo;

        scanf("%c", &tipo);

        if(tipo == 'D'){
            cidade.defesas[cidade.qtdDefesas] = criaDefesa();
            cidade.qtdDefesas++;
        }

        if(tipo == 'M'){
            cidade.misseis[cidade.qtdMisseis] = criaMissil();
            cidade.qtdMisseis++;
        }

        if(tipo == 'F'){
            break;
        }
    }

    return cidade;
}

void printaCidade(tCidade cidade){
    //printa cidade
    printf("%.2f %.2f\n", cidade.X, cidade.Y);

    //printa defesas
    for(int i = 0; i < cidade.qtdDefesas; i++){
        printaDefesa(cidade.defesas[i]);
    }

    //printa mísseis
    for(int i = 0; i < cidade.qtdMisseis; i++){
        printaMissil(cidade.misseis[i]);
    }
}