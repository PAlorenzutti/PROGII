#include "relatorio.h"
#include "aluno.h"

#include <stdio.h>

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/

float calculaMedia(Vector *alunos){
    float soma = 0;
    int qtdAlunos = VectorSize(alunos);
    
    for(int i = 0; i < qtdAlunos; i++){
        tAluno *a = VectorGet(alunos, i);

        soma += GetNotaAluno(a);
    }

    return (float) soma / qtdAlunos;
}

float porcentagemAlunosAprovados(Vector *alunos){
    int soma = 0;
    int qtdAlunos = VectorSize(alunos);
    
    for(int i = 0; i < qtdAlunos; i++){
        tAluno *a = VectorGet(alunos, i);

        if(GetNotaAluno(a) >= 6){
            soma++;
        }
    }

    printf("%d %d", soma, qtdAlunos);
    return (float)((soma / qtdAlunos) * 100.00);
}

float porcentagemMasculino(Vector *alunos){
    int soma = 0;
    int qtdAlunos = VectorSize(alunos);
    int qtdMasculino = 0;
    
    for(int i = 0; i < qtdAlunos; i++){
        tAluno *a = VectorGet(alunos, i);

        if(GetGeneroAluno(a) == 'M'){
            qtdMasculino++;
            
            if(GetNotaAluno(a) >= 6){
                soma++;
            }
        }
    }

    return (float) soma / qtdMasculino * 100;
}

float porcentagemFeminino(Vector *alunos){
    int soma = 0;
    int qtdAlunos = VectorSize(alunos);
    int qtdFeminino = 0;
    
    for(int i = 0; i < qtdAlunos; i++){
        tAluno *a = VectorGet(alunos, i);

        if(GetGeneroAluno(a) == 'F'){
            qtdFeminino++;
            
            if(GetNotaAluno(a) >= 6){
                soma++;
            }
        }
    }

    return (float) soma / qtdFeminino * 100;
}

float porcentagemOutro(Vector *alunos){
    int soma = 0;
    int qtdAlunos = VectorSize(alunos);
    int qtdOutro = 0;
    
    for(int i = 0; i < qtdAlunos; i++){
        tAluno *a = VectorGet(alunos, i);

        if(GetGeneroAluno(a) == 'O'){
            qtdOutro++;
            
            if(GetNotaAluno(a) >= 6){
                soma++;
            }
        }
    }

    return (float) soma / qtdOutro * 100;
}

void ImprimeRelatorio(Vector *alunos){
    printf("Media das notas: %.2f\n", calculaMedia(alunos));

    printf("Porcentagem de alunos aprovados: %.2f%%\n", porcentagemAlunosAprovados(alunos));

    printf("Porcentagem de cada genero:\n");

    printf("Masculino: %.2f%%\n", porcentagemMasculino(alunos));

    printf("Feminino: %.2f%%\n", porcentagemFeminino(alunos));

    printf("Outro: %.2f%%\n", porcentagemOutro(alunos));
}
