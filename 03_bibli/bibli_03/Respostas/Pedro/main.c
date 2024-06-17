#include <stdio.h>
#include "data.h"

typedef struct{
    int dia, mes, ano;
}tData;

int main(){
    int dia1, mes1, ano1;
    int dia2, mes2, ano2;

    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);

    //se a função retornar 0, a data não é válida.
    if(!verificaDataValida(dia1, mes1, ano1) || !verificaDataValida(dia2, mes2, ano2)){
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 1;
    }

    //printar primeira data
    printf("Primeira data: ");
    imprimeDataExtenso(dia1, mes1, ano1);

    //printar segunda data
    printf("Segunda data: ");
    imprimeDataExtenso(dia2, mes2, ano2);

    //comparar datas
    if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1){
        printf("A segunda data eh mais antiga\n");
    }else if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == -1){
        printf("A primeira data eh mais antiga\n");
    }else{
        printf("As datas sao iguais\n");
    }

    printf("A diferenca em dias entre as datas eh: %02d dias\n", calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2));

    return 0;
}