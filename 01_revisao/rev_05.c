#include <stdio.h>

#define MAX_LIN 1000
#define MAX_COL 1000

typedef struct {
    int linha, coluna;
} tipoPosicao;

int main() {
    int numeroLinhas, numeroColunas;
    int i, j;
    tipoPosicao inicial, final, atual, proximo;

    scanf("%d %d", &numeroLinhas, &numeroColunas);

    int matriz[MAX_LIN][MAX_COL];

    // Pegando a matriz
    for (i = 0; i < numeroLinhas; i++) {
        for (j = 0; j < numeroColunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Pegando a posição inicial e final
    scanf("%d %d", &inicial.linha, &inicial.coluna);
    scanf("%d %d", &final.linha, &final.coluna);

    // Atualizando posição inicial
    atual.linha = inicial.linha;
    atual.coluna = inicial.coluna;

    // Pegando a direção
    char caracteres[4];
    scanf("%s", caracteres);

    return 0;
}