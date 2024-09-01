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
    scanf("%99[^\n]\n", p->nome);
}

void setData(tPessoa *p){
    scanf("%10s\n", p->dataNascimento);
}

void setCPF(tPessoa *p){
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

    p->nome = (char*)malloc(sizeof(char) * TAM_NOME);
    p->dataNascimento = (char*)malloc(sizeof(char) * TAM_DATA);
    p->CPF = (char*)malloc(sizeof(char) * TAM_CPF);

    return p;
}

tPessoa* lePessoa(tPessoa *p){
    setNome(p);
    setData(p);
    setCPF(p);

    return p;
}

tPessoa** criaPessoas(tPessoa **pessoas, int numPessoas){
    //aloca o número de pessoas;
    pessoas = (tPessoa**)malloc(sizeof(tPessoa*) * (numPessoas));

    //aloca cada pessoa do vetor;
    for(int i = 0; i < numPessoas; i++){
        pessoas[i] = criaPessoa();
    }

    return pessoas;
}

tPessoa** lePessoas(tPessoa **pessoas, int numPessoas){
    //lê as informações de cada pessoa;
    for(int i = 0; i < numPessoas; i++){
        pessoas[i] = lePessoa(pessoas[i]);
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
    FILE *arquivo = fopen("dados.bin", "wb");

    fwrite(&numPessoas, sizeof(int), 1, arquivo);

    for(int i = 0; i < numPessoas; i++){
        fwrite(pessoas[i]->nome, sizeof(char) * TAM_NOME, 1, arquivo);
        fwrite(pessoas[i]->dataNascimento, sizeof(char) * TAM_DATA, 1, arquivo);
        fwrite(pessoas[i]->CPF, sizeof(char) * TAM_CPF, 1, arquivo);
    }

    fclose(arquivo);
}

tPessoa** leArquivo(tPessoa **pessoas, int *numPessoas){
    FILE *arquivo = fopen("dados.bin", "rb");

    fread(numPessoas, sizeof(int), 1, arquivo);

    pessoas = criaPessoas(pessoas, *numPessoas);

    for(int i = 0; i < *numPessoas; i++){
        fread(pessoas[i]->nome, sizeof(char) * TAM_NOME, 1, arquivo);
        
        fread(pessoas[i]->dataNascimento, sizeof(char) * TAM_DATA, 1, arquivo);
        
        fread(pessoas[i]->CPF, sizeof(char) * TAM_CPF, 1, arquivo);
       
    }

    

    fclose(arquivo);

    return pessoas;
}

int main(){
    tPessoa **pessoas = NULL;
    int numPessoas;

    int opcao;
    scanf("%d\n", &opcao);

    if(opcao == 1){
        //lê o número de pessoas da entrada padrão
        scanf("%d\n", &numPessoas);

        //cria as pessoas do vetor;
        pessoas = criaPessoas(pessoas, numPessoas);

        //vai ler pessoas no vetor
        pessoas = lePessoas(pessoas, numPessoas);

        //vai printar
        printaPessoas(pessoas, numPessoas);

        //vai salvar em um arquivo binário
        salvaArquivo(pessoas, numPessoas);
    }

    if(opcao == 2){
        //lê o arquivo
        pessoas = leArquivo(pessoas, &numPessoas);

        //vai printar
        printaPessoas(pessoas, numPessoas);
    }

    if(pessoas != NULL){
        liberaPessoas(pessoas, numPessoas);
    }

    return 0;
}