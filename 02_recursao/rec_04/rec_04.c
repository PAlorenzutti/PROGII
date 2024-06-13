#include <stdio.h>

int palindromo(char *string, int tamanho){
    if(tamanho <= 1){
        return 1;
    }
    
    if(string[0] != string[tamanho - 1]){
        return 0;
    }

    //pegar o resto da string
    char stringcopy[1000];

    int i, j;

    for(i = 1, j = 0; i < tamanho - 1; i++, j++){
        stringcopy[j] = string[i];
    }

    stringcopy[j] = '\0';

    return palindromo(stringcopy, tamanho - 2);
}

int pegarTamanho(char *string){
    int tamanho;

    for(tamanho = 0; string[tamanho] != '\0'; tamanho++);

    return tamanho;
}

int main(){
    char string[1000];

    while(scanf("%[^\n]\n", string) == 1){
        int tamanho;

        tamanho = pegarTamanho(string);

        if(palindromo(string, tamanho)){
            printf("SIM\n");
        }else{
            printf("NAO\n");
        }
    }

    return 0;
}