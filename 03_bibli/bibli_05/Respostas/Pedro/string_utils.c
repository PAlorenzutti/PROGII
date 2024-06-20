#include <stdio.h>
#include "string_utils.h"

int string_length(char *str){
    int tamanho;

    for(tamanho = 0; str[tamanho] != 0; tamanho++);

    return tamanho;
}

void string_copy(char *src, char *dest){
    int i;
    
    for(i = 0; i < string_length(src); i++){
        dest[i] = src[i];
    }

    dest[i] = '\0';
}

void string_upper(char *str){
    for(int i = 0; i < string_length(str); i++){
        if(str[i] > 96 && str[i] < 123){
            str[i] -= 32;
        }
    }
}

void string_lower(char *str){
    for(int i = 0; i < string_length(str); i++){
        if(str[i] > 64 && str[i] < 91){
            str[i] += 32;
        }
    }  
}

void string_reverse(char *str){
    //criando uma nova string com base no tamanho da src
    int i = string_length(str) - 1;

    char copy[i];

    //copiando a string
    int j;

    for(j = 0; j < string_length(str); i--, j++){
        copy[j] = str[i];   
    }

    copy[j] = '\0';

    //jogando a nova string reverse em cima da original
    string_copy(copy, str);
}