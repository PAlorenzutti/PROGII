#include <stdio.h>
#define MAX_LIN 1000
#define MAX_COL 1000

typedef struct{
    int lin, col;
}tipoPosicao;

//verificar tipo de posição, se a porção da string for igual a B, abaixar e retornar a posição

int main(){
    int linhas, colunas;
    int i, j;
    tipoPosicao inicial, final, atual;

    scanf("%d %d", &linhas, &colunas);

    int matriz[linhas][colunas];

    //pegando a matriz
    for(i = 0; i < linhas; i++){
        for(j = 0; j < linhas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    //pegando a posição inicial e final
    scanf("%d %d", &inicial.lin, &inicial.col);
    scanf("%d %d", &final.lin, &final.col);

    //pegando a direção
    char direcao[4];
    scanf("%s", direcao);

    //enquanto a posição final não bater o número de linhas ou colunas
    

    return 0;
}