#include "data.h"

#include <stdio.h>

tData CriaData(int dia, int mes, int ano){
    tData data;

    data.dia = dia;
    data.mes = mes;
    data.ano = ano;

    return data;
}

int VerificaDataValida(tData data){
    if(data.dia > NumeroDiasMes(data)){
        return 0;
    }

    if(data.mes < 1 && data.mes > 12){
        return 0;
    }

    if(data.ano < 0){
        return 0;
    }
    
    return 1;   
}

void ImprimeMesExtenso(tData data){
    char *meses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    
    printf("%s ", meses[data.mes - 1]);
}

void ImprimeDataExtenso(tData data){
    printf("%02d de ", data.dia);
    ImprimeMesExtenso(data);
    printf("de %d\n", data.ano);
}

int VerificaBissexto(tData data){
    if((data.ano % 4 == 0 && data.ano % 100 != 0) || data.ano % 400 == 0){
        return 1;
    }else{
        return 0;
    }
}

int NumeroDiasMes(tData data){
    //verificação de fevereiro em caso de bissexto ou não;
    if(data.mes == 2){
        if(VerificaBissexto(data)){
            return 29;
        }else{
            return 28;
        }
    }

    //verificação dos dias
    if(data.mes == 1 || data.mes == 3 || data.mes == 5 || data.mes == 7 || data.mes == 8 || data.mes == 10 || data.mes == 12){
        return 31;
    }else{
        return 30;
    }
}

int ComparaData(tData data1, tData data2){
    //se retornar 1 significa que a primeira data é maior que a segunda, ou seja, mais recente que a segunda
    //se retornar -1 significa que a primeira data é menor que a segunda, ou seja, mais antiga que a segunda
    
    if(data1.ano > data2.ano){
        return 1;
    }

    if(data1.ano < data2.ano){
        return -1;
    }

    if(data1.mes > data2.mes){
        return 1;
    }

    if(data1.mes < data2.mes){
        return -1;
    }

    if(data1.dia > data2.dia){
        return 1;
    }

    if(data1.dia < data2.dia){
        return -1;
    }

    return 0;
}

int CalculaDiasAteMes(tData data){
    int somaDias = 0;

    for(int i = 1; i < data.mes; i++){
        //cria uma data com o mes de acordo com o valor de i;
        tData datai = CriaData(data.dia, i, data.ano);
        somaDias += NumeroDiasMes(datai);
    }

    return somaDias;
}

int CalculaDiferencaDias(tData data1, tData data2){
    //maior (recente) menos a menor (antiga)
    
    //troca a menor (primeira) com a maior (segunda)
    if(ComparaData(data1, data2) == -1){
        //trocar a primeira com a segunda
        tData temp;

        //trocando data1 pela data2
        temp = data1;
        data1 = data2;
        data2 = temp;
    }

    if(data1.ano == data2.ano){    
        return (CalculaDiasAteMes(data1) + data1.dia) - (CalculaDiasAteMes(data2) + data2.dia); 
    }else{
        int somaDias = 0;
        
        //cria uma data para calcular o número de dia 
        tData dataDoze = CriaData(data2.dia, 12, data2.ano);

        somaDias = ( CalculaDiasAteMes(data1) + data1.dia ) + ( (CalculaDiasAteMes(dataDoze) + 31) - (CalculaDiasAteMes(data2) + data2.dia) );
        
        for(int i = data2.ano + 1; i < data1.ano; i++){
            //cria uma data com o mês 12 pra calcular o número de dias até dia 1 de dezembro de acordo com cada ano;
            tData datai = CriaData(data2.dia, 12, i);
            somaDias += CalculaDiasAteMes(datai) + 31;
        }

        return somaDias;
    }
}