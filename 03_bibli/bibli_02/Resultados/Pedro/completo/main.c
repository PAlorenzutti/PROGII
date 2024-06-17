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
    int rows1, cols1, rows2, cols2; 

    //lendo a primeira matriz

    scanf("%d %d", &rows1, &cols1);

    int matrix1[rows1][cols1];

    matrix_read(rows1, cols1, matrix1);

    //lendo a segunda matriz

    scanf("%d %d", &rows2, &cols2);

    int matrix2[rows2][cols2];

    matrix_read(rows2, cols2, matrix2);

    while(1){
        int option;
        
        option = show_menu();

        if(option == 1){
            if(possible_matrix_sum(rows1, cols1, rows2, cols2)){
                int result[rows1][cols1];
                matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols1, result);
            }else{
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }else if(option == 2){
            if(possible_matrix_sub(rows1, cols1, rows2, cols2)){
                int result[rows1][cols1];
                matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols1, result);
            }else{
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }else if(option == 3){
            if(possible_matrix_multiply(cols1, rows2)){
                int result[rows1][cols2];
                matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols2, result);
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