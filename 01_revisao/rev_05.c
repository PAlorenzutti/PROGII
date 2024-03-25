#include <stdio.h>

typedef struct
{
    int linha, coluna;
}
tipoPosicao;

void lerMatriz(int numeroLinhas, int numeroColunas, int matriz[numeroLinhas][numeroColunas])
{
    for(int i = 0; i < numeroLinhas; i++){
        for(int j = 0; j < numeroColunas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

void printarMatriz(int numeroLinhas, int numeroColunas, int matriz[numeroLinhas][numeroColunas])
{
    for(int i = 0; i < numeroLinhas; i++){
        for(int j = 0; j < numeroColunas; j++){
            printf("%d ", matriz[i][j]);
        }

        printf("\n");
    }
}

void printarPosicao(tipoPosicao atual)
{
    printf("(%d, %d) ", atual.linha + 1, atual.linha + 1);
}

tipoPosicao removerUm(tipoPosicao posicao)
{
    posicao.linha--;
    posicao.coluna--;
    
    return posicao;
}

int main() {
    int numeroLinhas, numeroColunas;
    tipoPosicao inicial, final, atual, proximo;

    //Pegando o número de linhas e colunas
    scanf("%d %d", &numeroLinhas, &numeroColunas);

    int matriz[numeroLinhas][numeroColunas];

    //Pegando a matriz
    lerMatriz(numeroLinhas, numeroColunas, matriz);

    // Pegando a posição inicial e final
    scanf("%d %d", &inicial.linha, &inicial.coluna);
    scanf("%d %d", &final.linha, &final.coluna);

    //Remover uma unidade das posições inicial e final para igualar com o index da matriz
    inicial = removerUm(inicial);
    final = removerUm(final);

    // Atualizando posição inicial
    atual = inicial;

    // Pegando a direção
    char caracteres[5];
    scanf("%s", caracteres);

    return 0;
}