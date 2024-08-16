#include "gerenciadorpacotes.h"
#include "pacote.h"

#include <stdio.h>
#include <stdbool.h>

int menu(){
    printf("\nEscolha uma opcao:\n");
    printf("	(1) Cadastrar um novo pacote\n");
    printf("	(2) Imprimir um pacote específico\n");
    printf("	(3) Imprimir todos os pacotes e sair\n");

    int opcao;
    scanf("%d", &opcao);

    return opcao;
}

int main(){
    printf("tad_gen_02\n");

    //cria o gerenciador;
    tGerenciador *geren = CriaGerenciador();

    while(true){
        int opcao = menu();

        if(opcao == 1){
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem:");

            int type, numElem;
            scanf("%d %d", &type, &numElem);

            if(type == 0){
                tPacote *pac = CriaPacote(CHAR, numElem);
                LePacote(pac);
                AdicionaPacoteNoGerenciador(geren, pac);
            }else if(type == 1){
                tPacote *pac = CriaPacote(INT, numElem);
                LePacote(pac);
                AdicionaPacoteNoGerenciador(geren, pac);
            }else{
                printf("\nDigite um tipo valido!\n");
            }

        }else if(opcao == 2){
            printf("Digite o index do pacote que deseja imprimir:\n");

            int idx;
            scanf("%d", &idx);

            ImprimirPacoteNoIndice(geren, idx);
        }else if(opcao == 3){
            ImprimirTodosPacotes(geren);
            DestroiGerenciador(geren);
            break;
        }else{
            printf("Escolha uma opcao valida para o menu!\n");
        }
    }

    return 0;
}