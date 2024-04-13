#include <stdio.h>
#include "constantes.h"
#include "franquia.h"
#include "partida.h"

int main(){
    tFranquia franquias[MAX_FRANQUIAS];
    int qtdFranquias = 0;

    tPartida partidas[MAX_PARTIDAS];
    int qtdPartidas = 0;

    while(1){
        char opcao;
        scanf("%c\n", &opcao);

        if(opcao == 'F'){
            if(qtdFranquias >= MAX_FRANQUIAS){
                printf("Excedido numero maximo de franquias permitidas.");
                break;
            }else{
                franquias[qtdFranquias] = lerFranquia();
                qtdFranquias++;
            }
        }

        if(opcao == 'P'){
            if(qtdPartidas >= MAX_PARTIDAS){
                printf("Excedido numero maximo de partidas permitidas");
                break;
            }else{
                //criando espelhos para acessar dados da tPartida dentro de franquia.
                char franquiaVisitante[MAX_FRANQUIA_NOME];
                int pontosVisitante;
                char franquiaCasa[MAX_FRANQUIA_NOME];
                int pontosCasa;

                partidas[qtdPartidas] = lerPartida();

                obtemDadosPartida(partidas[qtdPartidas], franquiaVisitante, &pontosVisitante, franquiaCasa, &pontosCasa);

                associarPontosFranquias(franquias, qtdFranquias, franquiaVisitante, pontosVisitante, franquiaCasa, pontosCasa);

                qtdPartidas++;
            }
        }

        if(opcao == 'E'){
    
            if(qtdPartidas > 0){
                somaVitoriasFranquias(franquias, qtdFranquias);

                calculaAproveitamentoFranquias(franquias, qtdFranquias);
            }
            
            break;
        }
    }

    if(qtdFranquias > 0){
        printFranquias(franquias, qtdFranquias);
    }

    printAproveitamentoConferencias(franquias, qtdFranquias);

    return 0;
}
