#include "aluno.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct Aluno{
    char *nome;
    int tamanhoNome;
    int matricula;
    int n1, n2, n3;
};

/**
 * @brief Cria um novo aluno vazio. Os atributos inteiros devem receber valor -1, e o ponteiro do nome deve apontar para NULL;
 * 
 * @return tAluno Retorna uma estrutura tAluno com os dados do aluno criado.
 */
tAluno* CriaAluno(){
    tAluno *aluno = (tAluno*)malloc(sizeof(tAluno));

    aluno->nome = NULL;
    aluno->tamanhoNome = 0;
    aluno->matricula = -1;
    aluno->n1 = -1;
    aluno->n2 = -1;
    aluno->n3 = -1;

    return aluno;
}

/**
 * @brief Função para liberar toda a memória alocada dinamicamente para estrututas do tipo tAluno
 * 
 * @param aluno Ponteiro para estrutura do tipo tAluno a ser apagada.
 */
void ApagaAluno(tAluno *aluno){
    free(aluno->nome);
    free(aluno);
}


/**
 * @brief Lê os dados de um aluno.
 * 
 * @param Ponteiro para aluno (alocado dinamicamente), cujos dados serão preenchidos nessa função
 */
void LeAluno(tAluno *aluno){
    //laço para ler o nome do aluno;
    char caractere;

    while(true){
        scanf("%c", &caractere);

        if(caractere == '\n'){
            break;
        }

        aluno->tamanhoNome++;
        aluno->nome = (char*)realloc(aluno->nome, sizeof(char) * aluno->tamanhoNome + 1);
        aluno->nome[aluno->tamanhoNome - 1] = caractere;
    }

    //adiciona o '\0'
    aluno->nome[aluno->tamanhoNome] = '\0';

    scanf("%d\n", &aluno->matricula);
    scanf("%d %d %d\n", &aluno->n1, &aluno->n2, &aluno->n3);
}

/**
 * @brief Compara as matrículas de dois alunos.
 * 
 * @param aluno1 Ponteiro para o primeiro aluno a ser comparado.
 * @param aluno2 Ponteiro para o segundo aluno a ser comparado.
 * @return int Retorna 1 se a matrícula do aluno1 é maior que a do aluno2, -1 se a matrícula do aluno1 é menor que a do aluno2 e 0 se as matrículas são iguais.
 */
int ComparaMatricula(tAluno* aluno1, tAluno* aluno2){
    if(aluno1->matricula > aluno2->matricula){
        return 1;
    }

    if(aluno1->matricula < aluno2->matricula){
        return -1;
    }

    return 0;
}

/**
 * @brief Calcula a média das notas de um aluno.
 * 
 * @param aluno Ponteiro para aluno a ter a média calculada.
 * @return int Retorna a média das notas do aluno.
 */
int CalculaMediaAluno(tAluno* aluno){
    return (aluno->n1 + aluno->n2 + aluno->n3)/3;
}

/**
 * @brief Verifica se um aluno foi aprovado ou reprovado.
 * 
 * @param aluno Ponteiro para aluno a ser verificado.
 * @return int Retorna 1 se o aluno foi aprovado e 0 se foi reprovado.
 */
int VerificaAprovacao(tAluno* aluno){
    if(CalculaMediaAluno(aluno) >= 7){
        return 1;
    }else{
        return 0;
    }
}

/**
 * @brief Imprime os dados de um aluno.
 * 
 * @param aluno Ponteiro para aluno a ser impresso.
 */
void ImprimeAluno(tAluno* aluno){
    printf("%s\n", aluno->nome);
}
