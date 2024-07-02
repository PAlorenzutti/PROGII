#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    char linha[100];
    while (true) {
        // Lê a entrada
        if (!fgets(linha, sizeof(linha), stdin)) {
            break;
        }

        // Verifica se a entrada é '#'
        if (linha[0] == '#') {
            break;
        }

        // Variáveis para armazenar os valores lidos
        int codigo, valor, quantidade;
        char nome[MAX_CARACTERES];

        // Lê os valores da linha
        if (sscanf(linha, "%d,%49[^,],%d,%d", &codigo, nome, &valor, &quantidade) == 4) {
            // Verifica se o código não está cadastrado
            if (!verificarFilmeCadastrado(locadora, codigo)) {
                // Cria filme e cadastra
                tFilme filme = criarFilme(nome, codigo, valor, quantidade);
                locadora = cadastrarFilmeLocadora(locadora, filme);
            }
        }
    }

    return locadora;
}

tLocadora ordenarFilmesLocadora (tLocadora locadora){
    for(int i = 0; i < locadora.numFilmes - 1; i++){
        for(int j = 0; j < locadora.numFilmes - 1 - i; j++){
            //se for positivo, significa que o primeiro está mais a frente do segundo;
            if( compararNomesFilmes(locadora.filme[j], locadora.filme[j + 1]) > 0){
                //troca o primeiro com o segundo
                tFilme temp = locadora.filme[j];
                locadora.filme[j] = locadora.filme[j + 1];
                locadora.filme[j + 1] = temp;
            }
        }
    }

    return locadora;
}

void consultarEstoqueLocadora (tLocadora locadora){
    //ordena locadora;
    locadora = ordenarFilmesLocadora(locadora);
    
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