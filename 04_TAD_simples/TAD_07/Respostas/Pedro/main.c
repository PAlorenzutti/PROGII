#include <stdio.h>

#include "data.h"

int main(){
    //cria data1
    int dia1, mes1, ano1;
    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    tData data1 = CriaData(dia1, mes1, ano1);

    //cria data2;
    int dia2, mes2, ano2;
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);
    tData data2 = CriaData(dia2, mes2, ano2);

    //se a função retornar 0, a data não é válida.
    if(!VerificaDataValida(data1) || !VerificaDataValida(data2)){
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 1;
    }

    //printar primeira data
    printf("Primeira data: ");
    ImprimeDataExtenso(data1);

    //printar segunda data
    printf("Segunda data: ");
    ImprimeDataExtenso(data2);

    //comparar datas
    if(ComparaData(data1, data2) == 1){
        printf("A segunda data eh mais antiga\n");
    }else if(ComparaData(data1, data2) == -1){
        printf("A primeira data eh mais antiga\n");
    }else{
        printf("As datas sao iguais\n");
    }

    printf("A diferenca em dias entre as datas eh: %02d dias\n", CalculaDiferencaDias(data1, data2));

    return 0;
}