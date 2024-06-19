#include "data.h"
#include <stdio.h>

int verificaDataValida(int dia, int mes, int ano){
    if(dia > numeroDiasMes(mes, ano)){
        return 0;
    }

    if(mes < 1 && mes > 12){
        return 0;
    }

    if(ano < 0){
        return 0;
    }
    
    return 1;   
}

void imprimeData(int dia, int mes, int ano){
    printf("%02d/%02d/%d", dia, mes, ano);
}

void imprimeMesExtenso(int mes){
    char *meses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    
    printf("%s ", meses[mes - 1]);
}

void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf("de %d\n", ano);
}

int verificaBissexto(int ano){
    if(ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0){
        return 1;
    }else{
        return 0;
    }
}

int numeroDiasMes(int mes, int ano){
    //verificação de fevereiro em caso de bissexto ou não;
    if(mes == 2){
        if(verificaBissexto(ano)){
            return 29;
        }else{
            return 28;
        }
    }

    //verificação dos dias
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        return 31;
    }else{
        return 30;
    }
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    //se retornar 1 significa que a primeira data é maior que a segunda, ou seja, mais recente que a segunda
    //se retornar -1 significa que a primeira data é menor que a segunda, ou seja, mais antiga que a segunda
    
    if(ano1 > ano2){
        return 1;
    }

    if(ano1 < ano2){
        return -1;
    }

    if(mes1 > mes2){
        return 1;
    }

    if(mes1 < mes2){
        return -1;
    }

    if(dia1 > dia2){
        return 1;
    }

    if(dia1 < dia2){
        return -1;
    }

    return 0;
}

int calculaDiasAteMes(int mes, int ano){
    int somaDias = 0;

    for(int i = 1; i < mes; i++){
        somaDias += numeroDiasMes(i, ano);
    }

    return somaDias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    //maior (recente) menos a menor (antiga)
    
    if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == -1){
        //trocar a primeira com a segunda
        int temp;  

        //trocando o dia1 pelo dia2
        temp = dia1;
        dia1 = dia2;
        dia2 = temp;

        //trocando o mes1 pelo mes2
        temp = mes1;
        mes1 = mes2;
        mes2 = temp;

        //trocando o ano1 pelo ano2
        temp = ano1;
        ano1 = ano2;
        ano2 = temp;
    }

    if(ano1 == ano2){    
        return (calculaDiasAteMes(mes1, ano1) + dia1) - (calculaDiasAteMes(mes2, ano2) + dia2); 
    }else{
        int somaDias = 0;

        somaDias = ( calculaDiasAteMes(mes1, ano1) + dia1 ) + ( (calculaDiasAteMes(12, ano2) + 31) - (calculaDiasAteMes(mes2, ano2) + dia2) );
        
        for(int i = ano2 + 1; i < ano1; i++){
            somaDias += calculaDiasAteMes(12, i) + 31;
        }

        return somaDias;
    }
}

void imprimeProximaData(int dia, int mes, int ano){
    if(dia + 1 > numeroDiasMes(mes, ano)){
        if(mes + 1 > 12){
            mes = 1;
        }else{
            mes += 1;
        }

        dia = 1;
    }else{
        dia += 1;
    }

    printf("%02d/%02d/%d", dia, mes, ano);
}