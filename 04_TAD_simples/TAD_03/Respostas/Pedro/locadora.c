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
        //lê a linha toda de entrada;
        fgets(linha, sizeof(linha), stdin);

        //verifica se o primeiro elemento da linha não é o #
        if (linha[0] == '#') {
            break;
        }

        //variáveis para armazenar os valores lidos
        int codigo, valor, quantidade;
        char nome[MAX_CARACTERES];

        //lê os valores da linha
        sscanf(linha, "%d,%49[^,],%d,%d", &codigo, nome, &valor, &quantidade);
        
        //verifica se o código não está cadastrado
        if (!verificarFilmeCadastrado(locadora, codigo)) {
            //cria filme e cadastra
            tFilme filme = criarFilme(nome, codigo, valor, quantidade);
            locadora = cadastrarFilmeLocadora(locadora, filme);
        }else{
            printf("Filme ja cadastrado no estoque\n");
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

tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    int totalAlugados = 0;
    int custoTotal = 0;

    //sentinela para ver se alugou
    int alugou;

    //percorre os códigos
    for(int i = 0; i < quantidadeCodigos; i++){
        //percorre os filmes
        for(int j = 0; j < locadora.numFilmes; j++){
            //se for o mesmo id do filme
            if(ehMesmoCodigoFilme(locadora.filme[j], codigos[i])){
                
                if(obterQtdEstoqueFilme(locadora.filme[j]) > 0){
                    //soma o custo do filme ao custo total
                    custoTotal += obterValorFilme(locadora.filme[j]);

                    //aumenta +1 ao totalalugados;
                    totalAlugados++;

                    //aluga filme;
                    locadora.filme[j] = alugarFilme(locadora.filme[j]);

                    //então alugou;
                    alugou = 1;
                }else{
                    printf("Filme ");
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                }
                
                break;
            }
        }
    }
    

    if(totalAlugados > 0){
        printf("Total de filmes alugados: %d com custo de R$%d\n", totalAlugados, custoTotal);
    }

    locadora.lucro += custoTotal;

    return locadora;
}


tLocadora lerAluguelLocadora (tLocadora locadora){
    int codigos[MAX_FILMES];
    int quantidadeCodigos = 0;

    while(true){
        char linha[100];
        // Lê a linha de entrada
        fgets(linha, sizeof(linha), stdin);

        // Verifica se a linha contém '#'
        if (linha[0] == '#') {
            break;
        }

        //lê código da linha
        int codigo;
        sscanf(linha, "%d", &codigo);

        //verifica se o código corresponde a algum dos filmes cadastrados na locadora

        int existe = 0; //sentinela;

        for(int i = 0; i < locadora.numFilmes; i++){
            if(ehMesmoCodigoFilme(locadora.filme[i], codigo)){
                existe = 1;
                break;
            }
        }

        //se existir coloca o código no vetor
        if(existe){
            //adiciona código no vetor de códigos;
            codigos[quantidadeCodigos] = codigo;
            quantidadeCodigos++;
        }else{
            printf("Filme %d nao cadastrado.\n", codigo);
        }
    }

    locadora = alugarFilmesLocadora(locadora, codigos, quantidadeCodigos);

    return locadora;
}

tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    //percorre os codigos
    for(int i = 0; i < quantidadeCodigos; i++){
        //percorre os filmes
        for(int j = 0; j < locadora.numFilmes; j++){
            //se for o mesmo id do filme
            if(ehMesmoCodigoFilme(locadora.filme[j], codigos[i])){

                if(!obterQtdAlugadaFilme(locadora.filme[j])){
                    printf("Nao e possivel devolver o filme ");
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(".\n");
                }else{
                    //aluga filme;
                    locadora.filme[j] = devolverFilme(locadora.filme[j]);

                    //filme
                    printf("Filme ");

                    //imprime o nome do filme;
                    imprimirNomeFilme(locadora.filme[j]);

                    //devolvido!
                    printf(" Devolvido!\n");
                }

                break;
            }
        }
    }

    return locadora;
}


tLocadora lerDevolucaoLocadora (tLocadora locadora){
    int codigos[MAX_FILMES];
    int quantidadeCodigos = 0;

    while(true){
        char linha[100];
        //lê a linha de entrada
        fgets(linha, sizeof(linha), stdin);

        //verifica se a linha contém '#'
        if (linha[0] == '#') {
            break;
        }

        //lê código da linha
        int codigo;
        sscanf(linha, "%d", &codigo);

        //verifica se o código corresponde a algum dos filmes cadastrados na locadora

        int existe = 0; //sentinela;

        for(int i = 0; i < locadora.numFilmes; i++){
            if(ehMesmoCodigoFilme(locadora.filme[i], codigo)){
                existe = 1;
                break;
            }
        }

        //se existir coloca o código no vetor
        if(existe){
            //adiciona código no vetor de códigos;
            codigos[quantidadeCodigos] = codigo;
            quantidadeCodigos++;
        }else{
            printf("Filme %d nao cadastrado.\n", codigo);
        }
    }

    locadora = devolverFilmesLocadora(locadora, codigos, quantidadeCodigos);

    return locadora;
}


void consultarEstoqueLocadora (tLocadora locadora){
    //ordena locadora;
    locadora = ordenarFilmesLocadora(locadora);
    
    printf("~ESTOQUE~\n");

    for(int i = 0; i < locadora.numFilmes; i++){
        //imprime o nome do filme;
        imprimirNomeFilme(locadora.filme[i]);

        //imprime quantidade no estoque;
        printf(" Fitas em estoque: %d\n", obterQtdEstoqueFilme(locadora.filme[i]));
    }
}

void consultarLucroLocadora (tLocadora locadora){
    printf("\nLucro total R$%d\n", locadora.lucro);
}