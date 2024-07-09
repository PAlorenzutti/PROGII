#include <string.h>
#include <stdio.h>

#include "biblioteca.h"

#define MAX_LIVROS 10

tBiblioteca inicializarBiblioteca(){
    tBiblioteca biblioteca;

    biblioteca.tamanho = 0;
    
    return biblioteca;
}

/**
 * Adiciona um livro à biblioteca.
 * Se estiver dentro do tamanho máximo de livros, imprime "Livro adicionado com sucesso!"
 * Senão, imprime "A biblioteca está cheia. Não é possível adicionar mais livros."
 *
 * @param biblioteca A biblioteca onde o livro será adicionado.
 * @param livro O livro a ser adicionado.
 * @return A biblioteca atualizada com o livro adicionado.
 */
tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro){
    if(biblioteca.tamanho + 1 > MAX_LIVROS){
        printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
    }else{
        biblioteca.livros[biblioteca.tamanho] = livro;
        biblioteca.tamanho++;

        printf("Livro adicionado com sucesso!\n");
    }
    
    return biblioteca;
}

tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char *titulo){
    tBiblioteca copia = inicializarBiblioteca();
    
    //procura o livro na biblioteca;
    for(int i = 0; i < biblioteca.tamanho; i++){
        //se for igual a 0, é igual
        //se não for igual, vai copiando os livros para a biblioteca nova;
        if(verificaTituloDoLivroNaBiblioteca(biblioteca.livros[i], titulo)){
            copia.livros[copia.tamanho] = biblioteca.livros[i];
            copia.tamanho++;
        }
    }

    if(copia.tamanho == biblioteca.tamanho - 1){
        printf("Livro removido com sucesso!\n");
    }else{
        printf("Livro nao encontrado na biblioteca.\n");
    }

    return copia;
}

int verificaTituloDoLivroNaBiblioteca(tLivros livro, char* titulo){
    return strcmp(livro.titulo, titulo);
}

void listarLivrosDaBiblioteca(tBiblioteca biblioteca){
    if(biblioteca.tamanho > 0){
        printf("\nLista de Livros na Biblioteca:\n");
        for(int i = 0; i < biblioteca.tamanho; i++){
            imprimeLivro(biblioteca.livros[i]);
            printf("\n");
        }
    }else{
        printf("A biblioteca esta vazia!\n");
    }
}
