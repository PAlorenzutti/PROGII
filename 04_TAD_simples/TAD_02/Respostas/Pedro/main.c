#include <stdio.h>

#include "eleitor.h"
#include "eleicao.h"
#include "candidato.h"

int main(){
    tEleicao eleicao = InicializaEleicao();

    eleicao = RealizaEleicao(eleicao);

    ImprimeEleicao(eleicao);

    return 0;
}
