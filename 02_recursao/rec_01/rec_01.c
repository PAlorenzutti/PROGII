#include <stdio.h>

void imprimeInvertido(char *string){
    char stringcopy[1000];

    //pegando o espaço

    int i;

    for(i = 0; string[i] != '\0' && string[i] != ' '; i++);

    //printando ao contrário

    int j;

    for(j = i - 1; j >= 0; j--){
        printf("%c", string[j]);
    }

    printf(" ");

    //pegando o resto da string

    i++;

    if(string[i] != '\0'){

        for(j = 0; string[i] != '\0'; i++, j++){
            stringcopy[j] = string[i];
        }

        stringcopy[j] = '\0';

        imprimeInvertido(stringcopy);
    }
}

int main(){

    char string[1000];

    scanf("%[^\n]", string);

    imprimeInvertido(string);

    return 0;
}