#include "cidade.h"

int main(){
    tCidade cidade = criaCidade();

    cidade = atualizaCidade(cidade);

    printaCidade(cidade);

    return 0;
}