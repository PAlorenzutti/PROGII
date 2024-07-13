#include <stdio.h>
#include <string.h>

#include "aluno.h"

/**
 * @brief Cria um novo aluno com os dados informados.
 * 
 * @param nome Nome do aluno.
 * @param matricula Matrícula do aluno.
 * @param n1 Nota da primeira avaliação.
 * @param n2 Nota da segunda avaliação.
 * @param n3 Nota da terceira avaliação.
 * @return tAluno Retorna uma estrutura tAluno com os dados do aluno criado.
 */
tAluno CriaAluno(char *nome, int matricula, int n1, int n2, int n3){
    tAluno aluno;

    strcpy(aluno.nome, nome);
    aluno.matricula = matricula;
    aluno.n1 = n1;
    aluno.n2 = n2;
    aluno.n3 = n3;

    return aluno;
}

tAluno LeAluno(){
    char nome[50];
    int matricula;
    int n1, n2, n3;

    scanf("%s\n", nome);

    scanf("%d\n", &matricula);

    scanf("%d %d %d\n", &n1, &n2, &n3);

    tAluno aluno = CriaAluno(nome, matricula, n1, n2, n3);

    return aluno;
}

int ComparaMatricula(tAluno aluno1, tAluno aluno2){
    if(aluno1.matricula > aluno2.matricula){
        return 1;
    }

    if(aluno1.matricula < aluno2.matricula){
        return -1;
    }

    return 0;
}

int CalculaMediaAluno(tAluno aluno){
    return (aluno.n1 + aluno.n2 + aluno.n3) / 3;
}

int VerificaAprovacao(tAluno aluno){
    if(CalculaMediaAluno(aluno) >= 7){
        return 1;
    }else{
        return 0;
    }
}

void ImprimeAluno(tAluno aluno){
    printf("%s\n", aluno.nome);
}