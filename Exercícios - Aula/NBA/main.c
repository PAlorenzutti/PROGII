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
                printf("Lido franquia numero %d", qtdFranquias);
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
                printf("Lido partida numero %d", qtdPartidas);
            }
        }

        if(opcao == 'E'){
    
            if(qtdPartidas > 0){
                somaVitoriasFranquias(franquias, qtdFranquias);

                calculaAproveitamentoFranquias(franquias, qtdFranquias);
            }
            
            break;
        }

        printf("\n");
    }

    printf("\n");

    for(int i = 0; i < qtdFranquias; i++){
        printf("%s %s %d %d %.2f %d %d\n", franquias[i].nome, franquias[i].sigla, 
        franquias[i].vitorias, franquias[i].derrotas, franquias[i].aproveitamento,
        franquias[i].vitoriasCasa, franquias[i].vitoriasFora);
    }

    int vitoriasLeste = somaVitoriasConferencia(franquias, qtdFranquias, "LESTE[CL]");
    int vitoriasOeste = somaVitoriasConferencia(franquias, qtdFranquias, "OESTE[CO]");

    int derrotasLeste = somaDerrotasConferencia(franquias, qtdFranquias, "LESTE[CL]");
    int derrotasOeste = somaDerrotasConferencia(franquias, qtdFranquias, "OESTE[CO]");

    int partidasLeste = vitoriasLeste + derrotasLeste;
    int partidasOeste = vitoriasOeste + derrotasOeste;

    float aproveitamentoLeste;
    float aproveitamentoOeste;
    
    if(!partidasLeste){
        aproveitamentoLeste = 0;
    }else{
        aproveitamentoLeste = (float) vitoriasLeste / (float) (partidasLeste);
    }

    if(!partidasOeste){
        aproveitamentoOeste = 0;
    }else{
        aproveitamentoOeste = (float) vitoriasOeste / (float) (partidasOeste);
    }


    printf("\nLESTE: %d %d %.2f\n", vitoriasLeste, derrotasLeste, aproveitamentoLeste);
    printf("OESTE: %d %d %.2f\n", vitoriasOeste, derrotasOeste, aproveitamentoOeste);

    /*
    printAproveitamentoConferencias(franquias, qtdFranquias);

    if(qtdFranquias > 0){
        printFranquias(franquias, qtdFranquias);
    }
    */

    return 0;
}
