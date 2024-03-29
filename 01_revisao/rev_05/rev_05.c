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
    printf("(%d, %d) ", atual.linha + 1, atual.coluna + 1);
}

tipoPosicao removerUm(tipoPosicao posicao)
{
    posicao.linha--;
    posicao.coluna--;
    
    return posicao;
}

int testarMesmaPosicao(tipoPosicao p1, tipoPosicao p2)
{
    if(p1.linha == p2.linha && p1.coluna == p2.coluna){
        return 1;
    }

    return 0;
}

tipoPosicao moverPosicao(int numeroLinhas, int numeroColunas, int matriz[numeroLinhas][numeroColunas], char direcao, tipoPosicao atual)
{
    //aBaixo
    if(direcao == 'B'){
        if(atual.linha + 1 < numeroLinhas && matriz[atual.linha + 1][atual.coluna] == 0){
            matriz[atual.linha][atual.coluna] = 1;
            atual.linha += 1;
        }
    //aCima
    }else if(direcao == 'C'){
        if(atual.linha - 1 >= 0 && matriz[atual.linha - 1][atual.coluna] == 0){
            matriz[atual.linha][atual.coluna] = 1;
            atual.linha -= 1;       
        }
    //Direita
    }else if(direcao == 'D'){
        if(atual.coluna + 1 < numeroColunas && matriz[atual.linha][atual.coluna + 1] == 0){
            matriz[atual.linha][atual.coluna] = 1;
            atual.coluna += 1;
        }
    //Esquerda
    }else if(direcao == 'E'){
        if(atual.coluna - 1 >= 0 && matriz[atual.linha][atual.coluna - 1] == 0){
            matriz[atual.linha][atual.coluna] = 1;
            atual.coluna -= 1;
        }
    }

    return atual;
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
    char direcoes[5];
    scanf(" %s", direcoes);

    //Printando posição inicial
    printarPosicao(atual);

    while(1){
        for(int k = 0; k < 4; k++){
            proximo = moverPosicao(numeroLinhas, numeroColunas, matriz, direcoes[k], atual);

            //se for a mesma posição, sai do loop de teste de cada direção em sua ordem de prioridade.
            if(!testarMesmaPosicao(atual, proximo)){
                break;
            }
        }

        //se o próximo for igual ao final, printar a atual, que é a útlima
        if(testarMesmaPosicao(final, proximo)){
            printarPosicao(proximo);
            break;
        }else if(testarMesmaPosicao(atual, proximo)){
            break;
        }else{
            atual = proximo;
            printarPosicao(atual);
        }  
    }

    return 0;
}