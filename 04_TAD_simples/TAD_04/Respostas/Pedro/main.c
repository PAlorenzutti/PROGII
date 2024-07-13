#include <stdio.h>

#include "aluno.h"

int main(){
    int numAlunos;
    scanf("%d\n", &numAlunos);

    //cria um vetor de aluno;
    tAluno aluno[numAlunos];

    //lê os alunos;
    for(int i = 0; i < numAlunos; i++){
        aluno[i] = LeAluno();
    }

    //ordena os alunos por matricula
    for(int i = 0; i < numAlunos; i++){
        for(int j = 0; j < numAlunos - i - 1; j++){
            //se for maior do que a seguinte, troca
            if(ComparaMatricula(aluno[j], aluno[j + 1]) == 1){
                tAluno temp = aluno[j];
                aluno[j] = aluno[j + 1];
                aluno[j + 1] = temp;
            }
        }
    }

    //imprime nome de alunos caso aprovados
    for(int i = 0; i < numAlunos; i++){
        if(VerificaAprovacao(aluno[i])){
            ImprimeAluno(aluno[i]);
        }
    }
    
    return 0;
}