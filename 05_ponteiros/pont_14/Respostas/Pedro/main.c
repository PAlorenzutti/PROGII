#include <stdio.h>
#include "tela.h"
#include "botao.h"

/*
Possiveis funcoes de Callback a serem armazenadas pelos ponteiros de funcao e executadas de acordo com eventos
realizados na tela
*/
void salvarDados(){
    printf("- Botao de SALVAR dados ativado!\n");
}

void excluirDados(){
    printf("- Botao de EXCLUIR dados ativado!\n");
}

void abrirMenuOpcoes(){
    printf("- Botao de OPCOES ativado!\n");
}

int main(){
    //criando tela full HD;
    Tela t = criarTela(1920, 1080);

    //criando três tipos de botão: salvar, excluir e opções
    Botao salvar = criarBotao("Salvar", 12, "FFF", 1, salvarDados);
    Botao excluir = criarBotao("Excluir", 18, "000", 1, excluirDados);
    Botao opcoes = criarBotao("Opcoes", 10, "FF0000", 2, abrirMenuOpcoes);

    //registrando os três botões
    registraBotaoTela(&t, salvar);
    registraBotaoTela(&t, excluir);
    registraBotaoTela(&t, opcoes);

    //desenhando a tela
    desenhaTela(t);

    //pega a opção escolhida pelo usuário
    ouvidorEventosTela(t);

    return 0;
}
