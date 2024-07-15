#include "matrix_utils.h"
#include <stdio.h>

tMatrix MatrixCreate(int rows, int cols){
    tMatrix matrix;

    matrix.rows = rows;
    matrix.cols = cols;

    return matrix;
}

tMatrix MatrixRead(tMatrix matrix){
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    matrix = MatrixCreate(rows, cols);

    //leitura dos dados
    for(int i = 0; i < matrix.rows; i++){
        for(int j = 0; j < matrix.cols; j++){
            scanf("%d", &matrix.data[i][j]);
        }
    }
    
    return matrix;
}

void MatrixPrint(tMatrix matrix){
    for(int i = 0; i < matrix.rows; i++){
        printf("|");

        for(int j = 0; j < matrix.cols; j++){
            if(j + 1 == matrix.cols){
                printf("%d", matrix.data[i][j]);
            }else{
                printf("%d ", matrix.data[i][j]);
            }
        }

        printf("|\n");
    }
}

int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2){
    if(matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols){
        return 1;
    }else{
        return 0;
    }
}

int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2){
    if(matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols){
        return 1;
    }else{
        return 0;
    }
}

int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2){
    if(matrix1.cols == matrix2.rows){
        return 1;
    }else{
        return 0;
    }
}

tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2){
    tMatrix result = MatrixCreate(matrix1.rows, matrix1.cols);
    
    for(int i = 0; i < matrix1.rows; i++){
        for(int j = 0; j < matrix1.cols; j++){
            result.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
        }
    }

    return result;
}

tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2){
    tMatrix result = MatrixCreate(matrix1.rows, matrix1.cols);
    
    for(int i = 0; i < matrix1.rows; i++){
        for(int j = 0; j < matrix1.cols; j++){
            result.data[i][j] = matrix1.data[i][j] - matrix2.data[i][j];
        }
    }

    return result;
}

tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2){
    tMatrix result = MatrixCreate(matrix1.rows, matrix1.cols);

    for(int i = 0; i < matrix1.rows; i++){
        for(int j = 0; j < matrix2.cols; j++){
            result.data[i][j] = 0;

            for(int k = 0; k < matrix1.cols; k++){
                result.data[i][j] += matrix1.data[i][k] * matrix2.data[k][j];
            }
        }
    }

    return result;
}

tMatrix TransposeMatrix(tMatrix matrix){
    tMatrix result = MatrixCreate(matrix.cols, matrix.rows);
    
    for(int i = 0; i < matrix.rows; i++){
        for(int j = 0; j < matrix.cols; j++){
            result.data[j][i] = matrix.data[i][j];
        }
    }

    return matrix;
}

tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar){
    for (int i = 0; i < matrix.rows; i++){
        for(int j = 0; j < matrix.cols; j++){
            matrix.data[i][j] = matrix.data[i][j] * scalar;
        }
    }
    
    return matrix;
}


