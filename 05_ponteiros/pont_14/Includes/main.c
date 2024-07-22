#include <stdio.h>
#include "tela.h"
#include "botao.h"

/*
Possiveis funcoes de Callback a serem armazenadas pelos ponteiros de funcao e executadas de acordo com eventos
realizados na tela
*/
void salvarDados () {
    printf("- Botao de SALVAR dados ativado!\n");
}

void excluirDados () {
    printf("- Botao de EXCLUIR dados ativado!\n");
}

void abrirMenuOpcoes () {
    printf("- Botao de OPCOES ativado!\n");
}

int main() {

    return 0;
}
