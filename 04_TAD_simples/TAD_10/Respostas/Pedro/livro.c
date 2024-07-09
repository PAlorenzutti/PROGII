#include <stdio.h>

#include "livro.h"

tLivros lerLivro(){
    tLivros livro;

    scanf("%99[^\n]\n", livro.titulo);
    scanf("%49[^\n]\n", livro.autor);
    scanf("%d\n", &livro.anoPublicacao);

    return livro;
}

void imprimeLivro(tLivros livro){
    printf("Titulo: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Ano de Publicacao: %d\n", livro.anoPublicacao);
}