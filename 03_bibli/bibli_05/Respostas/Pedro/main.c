#include <stdio.h>
#include "string_utils.h"

int menu(){
    int opcao;

    printf("1 - Tamanho da string\n");
    printf("2 - Copiar string\n");
    printf("3 - Converter string para letras maiusculas\n");
    printf("4 - Converter string para letras minusculas\n");
    printf("5 - Imprimir string ao contrario\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: \n");

    scanf("%d", &opcao);

    return opcao;
}

int main(){
    char str[1000];

    scanf("%[^\n]", str);
    
    int option = menu();

    while(option != 6){
        if(option == 1){
            printf("Tamanho da string: %d\n", string_length(str));
        }

        if(option == 2){
            char dest[1000];

            string_copy(str, dest);
            
            printf("String copiada: %s\n", dest);
        }

        if(option == 3){
            string_upper(str);
            
            printf("String convertida para maiusculas: %s\n", str);
        }

        if(option == 4){
            string_lower(str);

            printf("String convertida para minusculas: %s\n", str);
        }

        if(option == 5){
            string_reverse(str);

            printf("String invertida: %s\n", str);
        }

        printf("\n");

        option = menu();
    }

    return 0;
}