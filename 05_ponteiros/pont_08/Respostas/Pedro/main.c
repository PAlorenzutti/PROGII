#include <stdio.h>
#include "tDepartamento.h"

int main(){
    //numero de departamentos a serem inseridos;
    int num_dptos;
    scanf("%d", &num_dptos);

    tDepartamento depto[num_dptos];

    int i = 0;

    while(i < num_dptos){        
        //pega o nome do departamento;
        char nome[STRING_MAX];
        scanf("%s", nome);

        //pega o nome do diretor do departamento;
        char diretor[STRING_MAX];
        scanf("%s", diretor);

        //pega o nome do curso 1;
        char curso1[STRING_MAX];
        scanf("%s", curso1);

        //pega o nome do curso2;
        char curso2[STRING_MAX];
        scanf("%s", curso2);

        //pega o nome do curso3;
        char curso3[STRING_MAX];
        scanf("%s", curso3);

        //pega as notas dos três cursos;
        int m1, m2, m3;
        scanf("%d %d %d", &m1, &m2, &m3);

        if(m1 > 0 && m2 > 0 && m3 > 0){
            //atualiza o departamento em questão com as informações inseridas
            depto[i] = CriaDepartamento(curso1, curso2, curso3, nome, m1, m2, m3, diretor);

            //imprime o departamento
            ImprimeAtributosDepartamento(depto[i]); 

            i++;
        }else{
            printf("\nDigite um departamento com médias válidas");
        }
    }

    printf("\n");
    
    return 0;
}