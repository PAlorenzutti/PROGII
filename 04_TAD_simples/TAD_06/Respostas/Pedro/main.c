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

    scanf("%d\n", &option);

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

        //soma de matrizes
        if(option == 1){
            if(PossibleMatrixSum(matrix1, matrix2)){
                tMatrix result;
                result = MatrixAdd(matrix1, matrix2);
                MatrixPrint(result);
            }else{
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }
    
        //subtração de matrizes
        if(option == 2){
            if(PossibleMatrixSub(matrix1, matrix2)){
                tMatrix result;
                result = MatrixSub(matrix1, matrix2);
                MatrixPrint(result);
            }else{
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }
        
        //multiplicação de matrizes
        if(option == 3){
            if(PossibleMatrixMultiply(matrix1, matrix2)){
                tMatrix result;
                result = MatrixMultiply(matrix1, matrix2);
                MatrixPrint(result);
            }else{
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
            }
        }
        
        //multiplicação por escalar
        if(option == 4){
            int scalar;
            scanf("%d", &scalar);

            int whichMatrix;
            scanf("%d", &whichMatrix);

            if(whichMatrix == 1){
                matrix1 = MatrixMultiplyByScalar(matrix1, scalar);
                MatrixPrint(matrix1);
            }

            if(whichMatrix == 2){
                matrix2 = MatrixMultiplyByScalar(matrix2, scalar);
                MatrixPrint(matrix2);
            }
        }
        
        //transposta de matrizes
        if(option == 5){
            tMatrix result;

            //transposta da primeira matriz           
            result = TransposeMatrix(matrix1);
            MatrixPrint(result);
            
            printf("\n");

            //transposta da segunda matriz;
            result = TransposeMatrix(matrix2);
            MatrixPrint(result);
        }
        
        //encerra o programa
        if(option == 6){
            break;
        }
        
        printf("\n");
    }

    return 0;
}