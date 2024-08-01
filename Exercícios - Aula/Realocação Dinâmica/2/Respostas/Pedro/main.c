#include "pessoa.h"

int main(){
    //aloca um ponteiro para o tamanho;
    int *tamanho = malloc(sizeof(int));

    //inicia o tamanho do vetor como 0;
    *tamanho = 0;

    //aloca um ponteiro de ponteiros para pessoas com tamanho igual a 1;
    tPessoa** pessoas = malloc( (*tamanho + 1) * sizeof(tPessoa*) );
    
    while(true){
        tPessoa* p = criaPessoa();

        //se tiver lido um -1, sai do loop;
        if(p == NULL){
            break;
        }else{
            //adiciona a pessoa no vetor de pessoas;
            *(pessoas + *tamanho) = p;

            //aumenta o tamanho do vetor;
            *tamanho += 1;

            //aumenta o vetor de pessoas;
            pessoas = realloc(pessoas, (*tamanho + 1) * sizeof(tPessoa*));
        }
    }
  
    printaPessoas(pessoas, tamanho);

    pessoas = retiraPessoaFila(pessoas, tamanho, "175.407.147-35");

    printaPessoas(pessoas, tamanho);

    liberaPessoas(pessoas, tamanho);

    free(tamanho);

    return 0;
}