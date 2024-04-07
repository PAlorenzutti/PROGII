#include "mini_string.h"
#include <stdio.h>

void string_concatenar(char* strA, char* strB, char* strCat){
    int i, j;
    
    for(i = 0; strA[i] != '\0'; i++){
        strCat[i] = strA[i];
    }

    for(j = 0; strB[j] != '\0'; j++){
        strCat[i + j] = strB[j];
    }

    strCat[i + j] = '\0';
} 

int string_comparar(char* strA, char* strB){
    int i;
    
    for(i = 0; strA[i] != '\0' || strB[i] != '\0'; i++){
        if(strA[i] < strB[i]){
            return -1;
        } 
        
        if(strA[i] > strB[i]){
            return 1;
        }
    }

    if(strA[i] == '\0' && strB[i] != '\0'){
        return -1; //strA é menor
    }
    
    if(strA[i] != '\0' && strB[i] == '\0'){
        return 1; //strA é maior
    }

    return 0; //As strings são iguais
}


int string_ocorrencia(char* strA, char* strB){    
    for(int i = 0; strA[i] != '\0'; i++){
        if(strB[0] == strA[i]){
            int j = 0;

            for(j = 0; strB[j] != '\0'; j++){
                if(strB[j] != strA[i + j]){
                    break;
                }
            }

            if(strB[j] == '\0'){
                return 1;
            }
        }
    }
}