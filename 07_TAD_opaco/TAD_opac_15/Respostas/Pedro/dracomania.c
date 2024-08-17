#include "dracomania.h"
#include "duelo.h"
#include "carta.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct dracomania{
    tCarta *cartas;
    int numCartas;
    tDuelo *duelos;
    int numDuelos;
    int descartes;
    int desempates;
};

/**
 * @brief Cria uma nova instância do jogo Dracomania.
 * @return Retorna um ponteiro para a estrutura criada.
 */
tDracomania CriaDracomania(){
    tDracomania d = (tDracomania)malloc(sizeof(struct dracomania));

    d->cartas = NULL;
    d->duelos = NULL;
    d->numCartas = 0;
    d->numDuelos = 0;
    d->descartes = 0;
    d->desempates = 0;

    return d;
}

/**
 * @brief Roda o jogo Dracomania.
 * @param d Ponteiro para a instância do jogo.
 * @return Retorna um ponteiro para a instância do jogo atualizada.
 */
tDracomania RodaDracomania(tDracomania d){
    while(true){
        char opcao;
        scanf("%c\n", &opcao);

        if(opcao == CADASTRAR){
            tCarta carta = LeCarta();

            if(EhCartaValida(carta)){
                //sentinela para verificar se encontrou a carta
                int encontrou = 0;
                
                //laço para verificar se a carta já existe
                for(int i = 0; i < d->numCartas; i++){
                    if(GetIdCarta(carta) == GetIdCarta(d->cartas[i])){
                        LiberaCarta(d->cartas[i]);
                        d->cartas[i] = carta;
                        encontrou = 1;
                        break;
                    }
                }

                //se não encontrou, adiciona a nova carta ao baralho;
                if(!encontrou){
                    d->numCartas++;
                    d->cartas = (tCarta*)realloc(d->cartas, sizeof(tCarta) * d->numCartas);
                    d->cartas[d->numCartas - 1] = carta;
                }

            }else{
                LiberaCarta(carta);
                d->descartes++;
            }
        }

        if(opcao == LUTAR){
            tDuelo duelo = LeDuelo();
            tCarta c1 = NULL;
            tCarta c2 = NULL; 
            //cartas do duelo;

            for(int i = 0; i < d->numCartas; i++){
                if(GetC1Duelo(duelo) == GetIdCarta(d->cartas[i])){
                    c1 = d->cartas[i];
                }

                if(GetC2Duelo(duelo) == GetIdCarta(d->cartas[i])){
                    c2 = d->cartas[i];
                }

                //se já tiver encontrado as duas cartas, sai;
                if(c1 != NULL && c2 != NULL){
                    break;
                }
            }

            RealizaDuelo(duelo, c1, c2);

            d->numDuelos++;
            d->duelos = (tDuelo*)realloc(d->duelos, sizeof(tDuelo) * d->numDuelos);
            d->duelos[d->numDuelos - 1] = duelo;
        }

        if(opcao == FINALIZAR){
            break;
        }
    }

    return d;
}

/**
 * @brief Imprime o relatório final do jogo Dracomania.
 * @param d Ponteiro para a instância do jogo.
 */
void ImprimeRelatorioDracomania(tDracomania d){
    printf("Quantidade de Cartas: %d\n", d->numCartas);
    printf("Quantidade de descartadas: %d\n", d->descartes);
    printf("Quantidade de lutas: %d\n", d->numDuelos);
    
    if(d->numDuelos > 0){
        printf("Lutas que foram desempatadas: %d\n", d->desempates);

        //laço para procurar a carta mais vitoriosa;
        tCarta vitoriosa = d->cartas[0];

        for(int i = 0; i < d->numCartas; i++){
            if(GetNumVitCarta(d->cartas[i]) > GetNumVitCarta(vitoriosa)){
                vitoriosa = d->cartas[i];
            }
        }

  
        printf("Carta mais vitoriosa: %s\n", GetNomeCarta(vitoriosa));
        

        //laço para pegar a luta com maior diferença;
        tDuelo diferenca = d->duelos[0];

        for(int i = 0; i < d->numDuelos; i++){
            if(GetDiferencaDuelo(d->duelos[i]) > GetDiferencaDuelo(diferenca)){
                diferenca = d->duelos[i];
            }
        }
        

        printf("Luta com Maior Diferença: %d\n", GetIdDuelo(diferenca));
    }
}

/**
 * @brief Libera a memória alocada para a instância do jogo Dracomania.
 * @param d Ponteiro para a instância do jogo.
 */
void LiberaDracomania(tDracomania d){
    //laço para liberar cada carta;
    for(int i = 0; i < d->numCartas; i++){
        LiberaCarta(d->cartas[i]);
    }

    free(d->cartas);

    //laço para liberar cada duelo;
    for(int i = 0; i < d->numDuelos; i++){
        LiberaDuelo(d->duelos[i]);
    }

    free(d->duelos);

    free(d);
}
