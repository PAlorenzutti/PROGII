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
        scanf("%d\n", &opcao);

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
                partidas[qtdPartidas] = lerPartida();
                qtdPartidas++;
            }
        }

        if(opcao == 'E'){
            break;
        }
    }
}
