#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAM_NOME 100
#define TAM_DATA 11
#define TAM_CPF 15


typedef struct{
    char *nome;
    char *dataNascimento;
    char *CPF;
}tPessoa;

void setNome(tPessoa *p){
    p->nome = (char*)malloc(sizeof(char) * TAM_NOME);
    scanf("%99[^\n]\n", p->nome);
}

void setData(tPessoa *p){
    p->dataNascimento = (char*)malloc(sizeof(char) * TAM_DATA);
    scanf("%10s\n", p->dataNascimento);
}

void setCPF(tPessoa *p){
    p->CPF = (char*)malloc(sizeof(char) * TAM_CPF);
    scanf("%14s\n", p->CPF);
}

char* getNome(tPessoa *p){
    return p->nome;
}

char* getData(tPessoa *p){
    return p->dataNascimento;
}

char* getCPF(tPessoa *p){
    return p->CPF;
}

//cria a pessoa, aloca memória e lê as informações
tPessoa* criaPessoa(){
    tPessoa* p = (tPessoa*)malloc(sizeof(tPessoa));

    setNome(p);
    setData(p);
    setCPF(p);

    return p;
}

tPessoa** lePessoas(tPessoa **pessoas, int *numPessoas){
    scanf("%d\n", numPessoas);
    
    //aloca o número de pessoas;
    pessoas = (tPessoa**)malloc(sizeof(tPessoa*) * (*numPessoas));
    
    //lê as informações de cada pessoa;
    for(int i = 0; i < *numPessoas; i++){
        pessoas[i] = criaPessoa();
    }
    
    return pessoas;
}

void printaPessoa(tPessoa *p){
    printf("%s\n", getNome(p));
    printf("%s\n", getData(p));
    printf("%s\n", getCPF(p));
}

void printaPessoas(tPessoa **pessoas, int numPessoas){
    for(int i = 0; i < numPessoas; i++){
        printaPessoa(pessoas[i]);
    }
}

void liberaPessoa(tPessoa *p){
    free(p->nome);
    free(p->dataNascimento);
    free(p->CPF);
    free(p);
}

void liberaPessoas(tPessoa **pessoas, int numPessoas){
    for(int i = 0; i < numPessoas; i++){
        liberaPessoa(pessoas[i]);
    }

    free(pessoas);
}

void salvaArquivo(tPessoa **pessoas, int numPessoas){
    FILE *arquivo;

    arquivo = fopen("dados.bin", "wb");

    //escreve o número de pessoas no arquivo;
    fwrite(&numPessoas, sizeof(int), 1, arquivo);

    //escreve cada pessoa no arquivo;
    fwrite(pessoas, sizeof(tPessoa**), 1, arquivo);

    //fecha arquivo
    fclose(arquivo);
}

void leArquivo(tPessoa **pessoas, int *numPessoas){
    FILE *arquivo;

    arquivo = fopen("dados.bin", "rb");

    //escreve o número de pessoas no arquivo;
    fread(numPessoas, sizeof(int), 1, arquivo);

    //aloca o número de pessoas;
    pessoas = (tPessoa**)malloc(sizeof(tPessoa*) * (*numPessoas));

    //escreve cada pessoa no arquivo;
    fread(pessoas, sizeof(tPessoa**), 1, arquivo);

    //fecha arquivo
    fclose(arquivo);
}

int main(){
    tPessoa **pessoas = NULL;
    int numPessoas;

    int opcao;
    scanf("%d\n", &opcao);

    if(opcao == 1){
        //vai ler pessoas no vetor
        pessoas = lePessoas(pessoas, &numPessoas);

        //vai printar
        printaPessoas(pessoas, numPessoas);

        //vai salvar em um arquivo binário
        salvaArquivo(pessoas, numPessoas);
    }

    if(opcao == 2){
        //vai ler as pesssoas do arquivo
        leArquivo(pessoas, &numPessoas);

        //vai printar
        printaPessoas(pessoas, numPessoas);
    }

    if(pessoas != NULL){
        liberaPessoas(pessoas, numPessoas);
    }

    
    return 0;
}