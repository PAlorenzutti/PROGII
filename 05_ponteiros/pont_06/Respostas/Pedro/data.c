#include <stdio.h>
#include "data.h"

void InicializaDataParam( int dia, int mes, int ano, tData *data){
    (*data).dia = dia;
    (*data).mes = mes;
    (*data).ano = ano;
}

void LeData( tData *data ){
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);

    InicializaDataParam(dia, mes, ano, data);

    //correção
    int diaCorreto = InformaQtdDiasNoMes(data);

    if((*data).dia > diaCorreto){
        (*data).dia = diaCorreto;
        
    }

    if((*data).mes > 12){
        (*data).mes = 12;
    }
}

void ImprimeData( tData *data ){
    printf("'%02d/%02d/%04d'", (*data).dia, (*data).mes, (*data).ano);
}

int EhBissexto( tData *data ){
    if((*data).ano % 4 == 0 && (*data).ano % 100 != 0 || (*data).ano % 400 == 0){
        return 1;
    }else{
        return 0;
    }
}

int InformaQtdDiasNoMes( tData *data ){
    if((*data).mes == 2){
        if(EhBissexto(data)){
            return 29;
        }else{
            return 28;
        }
    }

    //verificação dos dias
    if((*data).mes == 1 || (*data).mes == 3 || (*data).mes == 5 || (*data).mes == 7 || (*data).mes == 8 || (*data).mes == 10 || (*data).mes == 12){
        return 31;
    }else{
        return 30;
    }
}

void AvancaParaDiaSeguinte( tData *data ){
    //avanço
    if((*data).dia + 1 > InformaQtdDiasNoMes(data)){
        (*data).dia = 1;

        if((*data).mes + 1 > 12){
            (*data).mes = 1;
            (*data).ano += 1;
        }else{
            (*data).mes += 1;
        }
    }else{
        (*data).dia += 1;
    }
}

int EhIgual( tData *data1, tData *data2 ){
    if((*data1).dia == (*data2).dia && (*data1).ano == (*data2).ano && (*data1).mes == (*data2).mes){
        return 1;
    }else{
        return 0;
    }
}