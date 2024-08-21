#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"

tAluno** leAlunos(tAluno **alunos, int numAlunos){
    for(int i = 0; i < numAlunos; i++){
        //lê aluno;
        tAluno *aluno = CriaAluno();
        LeAluno(aluno);
        
        //realoca a quantidade de alunos;
        alunos = (tAluno**)realloc(alunos, sizeof(tAluno*) * (i + 1));

        //coloca o aluno na posição;
        alunos[i] = aluno;
    }

    return alunos;
}

void trocaAluno(tAluno **aluno1, tAluno **aluno2){
    tAluno *temp = *aluno1;
    *aluno1 = *aluno2;
    *aluno2 = temp;
}

tAluno** ordenaAlunos(tAluno **alunos, int numAlunos){
    for(int i = 0; i < numAlunos - 1; i++){
        for(int j = 0; j < numAlunos - i - 1; j++){
            if(ComparaMatricula(alunos[j], alunos[j + 1]) == 1){
                trocaAluno(&alunos[j], &alunos[j + 1]);
            }
        }
    }

    return alunos;
}

void imprimeAlunos(tAluno **alunos, int numAlunos){
    for(int i = 0; i < numAlunos; i++){
        if(VerificaAprovacao(alunos[i])){
            ImprimeAluno(alunos[i]);
        }
    }
}

void liberaAlunos(tAluno **alunos, int numAlunos){
    for(int i = 0; i < numAlunos; i++){
        ApagaAluno(alunos[i]);
    }

    free(alunos);
}

int main(){
    tAluno **alunos = NULL;
    
    int numAlunos;
    scanf("%d\n", &numAlunos);

    alunos = leAlunos(alunos, numAlunos);

    alunos = ordenaAlunos(alunos, numAlunos);

    imprimeAlunos(alunos, numAlunos);

    liberaAlunos(alunos, numAlunos);

    return 0;
}