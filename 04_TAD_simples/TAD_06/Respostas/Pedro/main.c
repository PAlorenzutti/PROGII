#include "matrix_utils.h"
#include <stdio.h>
#define MAX_ROWS 1000
#define MAX_COLS 1000

int show_menu(){
    int option;
    
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: \n");

    scanf("%d", &option);

    return option;
}

int main(){
    //lendo a primeira matriz

    tMatrix matrix1 = MatrixRead(matrix1);

    //lendo a segunda matriz

    tMatrix matrix2 = MatrixRead(matrix2);

    while(1){
        int option;
        
        option = show_menu();

        if(option == 1){
            if(PossibleMatrixSum(matrix1, matrix2)){
                tMatrix result;
                result = MatrixAdd(matrix1, matrix2);
                MatrixPrint(result);
            }else{
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }else if(option == 2){
            if(PossibleMatrixSub(matrix1, matrix2)){
                tMatrix result;
                result = MatrixSub(matrix1, matrix2);
                MatrixPrint(result);
            }else{
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }else if(option == 3){
            if(PossibleMatrixMultiply(matrix1, matrix2)){
                tMatrix result;
                result = MatrixMultiply(matrix1, matrix2);
                MatrixPrint(result);
            }else{
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
            }
        }else if(option == 4){
            int scalar;
            //printf("Digite o escalar que deseja: ");
            scanf("%d", &scalar);

            int whichMatrix;
            //printf("Digite qual matriz voce deseja multiplicar por %d: ", scalar);
            scanf("%d", &whichMatrix);

            if(whichMatrix == 1){
                //int result[rows1][cols1];
                scalar_multiply(rows1, cols1, matrix1, scalar);
                matrix_print(rows1, cols1, matrix1);
            }

            if(whichMatrix == 2){
                //int result[rows2][cols2];
                scalar_multiply(rows2, cols2, matrix2, scalar);
                matrix_print(rows2, cols2, matrix2);
            }
        }else if(option == 5){
            //printf("Digite qual matriz voce deseja transpor: ");
            //scanf("%d", &whichMatrix);

            //fazendo a transposta da primeira matriz           
            int result1[cols1][rows1];
            transpose_matrix(rows1, cols1, matrix1, result1);
            matrix_print(cols1, rows1, result1);
            
            printf("\n");

            int result2[cols2][rows2];
            transpose_matrix(rows2, cols2, matrix2, result2);
            matrix_print(cols2, rows2, result2);
        }else if(option == 6){
            break;
        }else{
            printf("Opcao invalida.");
        }
        
        printf("\n");
    }

    return 0;
}