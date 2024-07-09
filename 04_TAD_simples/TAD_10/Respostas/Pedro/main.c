#include <stdio.h>

#include "biblioteca.h"
#include "livro.h"

int main(){
    //número de operações a serem realizadas.
    int N;
    scanf("%d\n", &N);

    tBiblioteca biblioteca = inicializarBiblioteca();

    //printa menu
    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n\n");

    while(N > 0){
        int opcao;
        scanf("%d\n", &opcao);

        if(opcao == 1){
            tLivros livro = lerLivro();
            biblioteca = adicionarLivroNaBiblioteca(biblioteca, livro);
        }

        if(opcao == 2){
            char titulo[100];
            scanf("%[^\n]\n", titulo);

            biblioteca = removerLivroDaBiblioteca(biblioteca, titulo);
        }

        if(opcao == 3){
            listarLivrosDaBiblioteca(biblioteca);
        }

        if(opcao > 3){
            printf("Operacao invalida!\n");
            break;
        }

        //decresce o número de operações;
        N--;
    }

    return 0;
}