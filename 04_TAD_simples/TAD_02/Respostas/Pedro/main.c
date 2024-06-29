#include <stdio.h>

#include "eleitor.h"
#include "eleicao.h"
#include "candidato.h"

int main(){
    tEleicao eleicao = InicializaEleicao();

    eleicao = RealizaEleicao(eleicao);

    ImprimeResultadoEleicao(eleicao);

    return 0;
}
