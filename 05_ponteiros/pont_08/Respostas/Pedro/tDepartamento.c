#include "tDepartamento.h"
#include <stdio.h>
#include <string.h>

tDepartamento CriaDepartamento( char *curso1, char *curso2, char *curso3, char *nome, int m1, int m2, int m3, char *diretor ){
    tDepartamento depto;

    strcpy(depto.nome, nome);

    strcpy(depto.diretor, diretor);

    strcpy(depto.curso1, curso1);
    strcpy(depto.curso2, curso2);
    strcpy(depto.curso3, curso3);

    depto.m1 = m1;
    depto.m2 = m2;
    depto.m3 = m3;

    return depto;
}

void ImprimeAtributosDepartamento(tDepartamento depto){
    printf("\nDepartamento: %s\n", depto.nome);
    printf("	Diretor: %s\n", depto.diretor);

    printf("	1o curso: %s\n", depto.curso1);
    printf("	Media do 1o curso: %d\n", depto.m1);

    printf("	2o curso: %s\n", depto.curso2);
    printf("	Media do 2o curso: %d\n", depto.m2);

    printf("	3o curso: %s\n", depto.curso3);
    printf("	Media do 3o curso: %d\n", depto.m3);

    printf("	Media dos cursos: %.2f", (float) (depto.m1 + depto.m2 + depto.m3)/3);
}

void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos){
    
}