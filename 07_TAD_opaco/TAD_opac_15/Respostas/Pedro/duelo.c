#include "duelo.h"

#include <stdio.h>
#include <stdlib.h>

struct duelo{
    int id;
    int idC1, idC2;
    tCarta c1, c2;
    char atributo;
    int desempate;
};

/**
 * @brief Lê um duelo do usuário.
 * @return Retorna um ponteiro para o duelo lido.
 */
tDuelo LeDuelo(){
    tDuelo d = (tDuelo)malloc(sizeof(struct duelo));

    scanf("%d\n", &d->id);
    scanf("%d %d %c\n", &d->idC1, &d->idC2, &d->atributo);
    d->desempate = 0;
    d->c1 = NULL;
    d->c2 = NULL;

    return d;
}

/**
 * @brief Libera a memória alocada para um duelo.
 * @param d Ponteiro para o duelo a ser liberado.
 */
void LiberaDuelo(tDuelo d){
    free(d);
}

/**
 * @brief Imprime as informações de um duelo.
 * @param d Ponteiro para o duelo a ser impresso.
 */
void ImprimeDuelo(tDuelo d){
    printf("%d\n", d->id);
}

/**
 * @brief Realiza um duelo entre duas cartas.
 * @param d Ponteiro para o duelo.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 */
void RealizaDuelo(tDuelo d, tCarta c1, tCarta c2){
    //aponta pras duas cartas passadas
    d->c1 = c1;
    d->c2 = c2;

    //realiza o duelo de acordo com os atributos
    switch(d->atributo){
        case MAGIA:
            if(ComparaMagiaCarta(c1, c2) == -1){
                AdicionaVitoriaCarta(c2);
            }

            if(ComparaMagiaCarta(c1, c2) == 1){
                AdicionaVitoriaCarta(c1);
            }

            if(ComparaMagiaCarta(c1, c2) == 0){
                d->desempate = 1;
                
                if(ComparaIdCarta(c1, c2) == -1){
                    AdicionaVitoriaCarta(c1);
                }

                if(ComparaIdCarta(c1, c2) == 1){
                    AdicionaVitoriaCarta(c2);
                }
            }

            break;

        case FORCA:
            if(ComparaAtaqueCarta(c1, c2) == -1){
                AdicionaVitoriaCarta(c2);
            }

            if(ComparaAtaqueCarta(c1, c2) == 1){
                AdicionaVitoriaCarta(c1);
            }

            if(ComparaAtaqueCarta(c1, c2) == 0){
                d->desempate = 1;
                
                if(ComparaIdCarta(c1, c2) == -1){
                    AdicionaVitoriaCarta(c1);
                }

                if(ComparaIdCarta(c1, c2) == 1){
                    AdicionaVitoriaCarta(c2);
                }
            }

            break;

        case FOGO:
            if(ComparaFogoCarta(c1, c2) == -1){
                AdicionaVitoriaCarta(c2);
            }

            if(ComparaFogoCarta(c1, c2) == 1){
                AdicionaVitoriaCarta(c1);
            }

            if(ComparaFogoCarta(c1, c2) == 0){
                d->desempate = 1;
                
                if(ComparaIdCarta(c1, c2) == -1){
                    AdicionaVitoriaCarta(c1);
                }

                if(ComparaIdCarta(c1, c2) == 1){
                    AdicionaVitoriaCarta(c2);
                }
            }

            break;
    }
}

/**
 * @brief Retorna o ID da primeira carta do duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna o ID da primeira carta do duelo.
 */
int GetC1Duelo(tDuelo d){
    return d->idC1;
}

/**
 * @brief Retorna o ID da segunda carta do duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna o ID da segunda carta do duelo.
 */
int GetC2Duelo(tDuelo d){
    return d->idC2;
}

/**
 * @brief Retorna se houve desempate no duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna true se houve desempate e false caso contrário.
 */
bool GetDesempateDuelo(tDuelo d){
    if(!d->desempate){
        return false;
    }

    return true;
}

/**
 * @brief Retorna a diferença de pontos entre as cartas no duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna a diferença de pontos entre as cartas no duelo.
 */
int GetDiferencaDuelo(tDuelo d){
    //pega o maior menos o menor;
    
    if(d->atributo == MAGIA){
        if(ComparaMagiaCarta(d->c1, d->c2) == 1){
            return GetMagiaCarta(d->c1) - GetMagiaCarta(d->c2);
        }

        if(ComparaMagiaCarta(d->c1, d->c2) == -1){
            return GetMagiaCarta(d->c2) - GetMagiaCarta(d->c1);
        }
    }

    if(d->atributo == FORCA){
        if(ComparaAtaqueCarta(d->c1, d->c2) == 1){
            return GetAtaqueCarta(d->c1) - GetAtaqueCarta(d->c2);
        }

        if(ComparaAtaqueCarta(d->c1, d->c2) == -1){
            return GetAtaqueCarta(d->c2) - GetAtaqueCarta(d->c1);
        }
    }

    if(d->atributo == FOGO){
        if(ComparaFogoCarta(d->c1, d->c2) == 1){
            return GetFogoCarta(d->c1) - GetFogoCarta(d->c2);
        }

        if(ComparaFogoCarta(d->c1, d->c2) == -1){
            return GetFogoCarta(d->c2) - GetFogoCarta(d->c1);
        }
    }

    return 0;
}

/**
 * @brief Retorna o ID do duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna o ID do duelo.
 */
int GetIdDuelo(tDuelo d){
    return d->id;
}