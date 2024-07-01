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

tLocadora lerCadastroLocadora (tLocadora locadora){
    //cria um filme
    tFilme filme;

    //lê o código do filme
    int codigo;
    scanf("%d,", &codigo);

    //verifica se o filme já não está cadastrado na locadora, se não estiver entra;
    if( !verificarFilmeCadastrado(locadora, codigo) ){
        filme = leFilme(codigo);
        cadastrarFilmeLocadora(locadora, filme);
    }

    return locadora;

}