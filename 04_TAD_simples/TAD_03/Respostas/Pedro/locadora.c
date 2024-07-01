#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "locadora.h"

tLocadora criarLocadora (){
    tLocadora locadora;

    locadora.numFilmes = 0;
    locadora.lucro = 0;

    return locadora;
}

int verificarFilmeCadastrado (tLocadora locadora, int codigo){
    for(int i = 0; i < locadora.numFilmes; i++){
        //se o código do filme em questão for igual ao código parâmetro, retorna 1;
        if( obterCodigoFilme(locadora.filme[i]) == codigo){
            return 1;
        }
    }

    return 0;
}

tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme){
    //cadastro do filme
    locadora.filme[locadora.numFilmes] = filme;

    //confirmação do filme cadastrado
    printf("Filme cadastrado %d - %s\n", filme.codigo, filme.nome);

    //aumento do numero de filmes
    locadora.numFilmes++;

    return locadora;
}

tLocadora lerCadastroLocadora (tLocadora locadora){
    //cria um filme
    tFilme filme;

    //lê a entrada
    char entrada[50];

    scanf("%49[^,],", entrada);
    printf("%s\n", entrada);

    //se o codigo for diferente de 35 (#, na tabela ASCII)
    while( strcmp(entrada, "#") != 0 ){
        //substitui a entrada por inteiro se não for #
        int codigo = atoi(entrada);

        //verifica se o filme já não está cadastrado na locadora, se não estiver entra;
        if( !verificarFilmeCadastrado(locadora, codigo) ){
            //leitura do filme
            filme = leFilme(codigo);

            //cadastro do filme
            locadora = cadastrarFilmeLocadora(locadora, filme);
        }

        //lê o código dos próximos filmes
        scanf("%49[^,],", entrada);
    }

    return locadora;
}

void consultarEstoqueLocadora (tLocadora locadora){
    printf("\n~ESTOQUE~\n");

    for(int i = 0; i < locadora.numFilmes; i++){
        //imprime o código do filme;
        printf("%d - ", obterCodigoFilme(locadora.filme[i]));

        //imprime o nome do filme;
        imprimirNomeFilme(locadora.filme[i]);

        //imprime quantidade no estoque;
        printf(" Fitas em estoque: %d\n", obterQtdEstoqueFilme(locadora.filme[i]));
    }

}