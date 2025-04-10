#include "departamento.h"

#include <string.h>
#include <stdio.h>
#include <math.h>

tDepartamento criaDepartamento(char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor){
    tDepartamento depto;

    //atribui o nome do departamento
    strcpy(depto.nome, nome);

    //atribui o nome do diretor do departamento;
    strcpy(depto.diretor, diretor);

    //atribui os nomes aos respectivos cursos;
    strcpy(depto.c1, c1);
    strcpy(depto.c2, c2);
    strcpy(depto.c3, c3);

    //atribui as médias de cada curso;
    depto.m1 = m1;
    depto.m2 = m2;
    depto.m3 = m3;

    //calcula média geral do departamento;
    depto.media_geral = calculaMediaGeralDepartamento(depto);

    return depto;
}   

void imprimeAtributosDepartamento (tDepartamento depto){
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n", depto.nome);
    printf("diretor => %s\n", depto.diretor);
    printf("curso1 => %s, media1 => %d\n", depto.c1, depto.m1);
    printf("curso2 => %s, media2 => %d\n", depto.c2, depto.m2);
    printf("curso3 => %s, media3 => %d\n", depto.c3, depto.m3);
    printf("media geral => %.2f\n", depto.media_geral);
    printf("desvio padrao => %.2lf\n\n", calculaDesvioPadraoDepartamento(depto));
}

int validaMediaDepartamento (int media){
    if(media >= 0 && media <= 10){
        return 1;
    }else{
        return 0;
    }
}

double calculaDesvioPadraoDepartamento(tDepartamento depto){ 
    return (double) sqrt( ( pow(depto.m1 - depto.media_geral, 2) + pow(depto.m2 - depto.media_geral, 2) + pow(depto.m3 - depto.media_geral, 2) ) /3 );
}

double calculaMediaGeralDepartamento(tDepartamento depto){
    return (double) (depto.m1 + depto.m2 + depto.m3) / 3;
}

void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho){
    //ordena em ordem crescente;    
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho - i - 1; j++){
            if(d[j].media_geral < d[j + 1].media_geral){
                tDepartamento temp = d[j];
                d[j] = d[j + 1];
                d[j + 1] = temp;
            }
        }
    }
}