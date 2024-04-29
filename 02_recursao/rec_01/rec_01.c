#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void imprimeInvertido(char *string){
    char stringcopy[1000];

    int i;

    //encontrar o espaço.
    for(i = 0; string[i] != '\0' || string[i] != ' '; i++);

    int j;

    //printando a string do espaço encontado até a primeira posição
    for(j = i - 1; j >= 0; j--){
        printf("%c", string[j]);
    }

    //aumentando i para não pegar o espaço antes encontrado;
    i++;

    //copiando a string
    /*
    for(j = 0; string[i] != '\0'; j++, i++){
        stringcopy[j] = string[i];
    }

    //fechando a copia
    stringcopy[j] = '\0';

    if(stringcopy[j] != '\0'){
        printf(" ");
        imprimeInvertido(stringcopy);
    }
    */

}

int main(){

    char string[1000];

    scanf("%[^\n]", string);

    imprimeInvertido(string);

    return 0;
}