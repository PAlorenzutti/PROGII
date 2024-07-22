#include <stdio.h>
#include "tela.h"
#include "botao.h"

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

    Botao btnSalvar = criarBotao("Salvar", 12, "FFF", CLICK, salvarDados);
    Botao btnExcluir = criarBotao("Excluir", 18, "000", CLICK, excluirDados);
    Botao btnOpcoes = criarBotao("Opcaoes", 10, "FF0000", LONGO_CLICK, abrirMenuOpcoes);
    Tela t1 = criarTela(200, 400);

    registraBotaoTela(&t1, btnSalvar);
    registraBotaoTela(&t1, btnExcluir);
    registraBotaoTela(&t1, btnOpcoes);

    desenhaTela(t1);

    ouvidorEventosTela(t1);


    return 0;
}