#include "mini_string.h"
#include <stdio.h>

int menu(){
    int option;

    printf("Escolha uma funcao e forneca duas strings:");
    printf("\n    1 - Concatenar Strings");
    printf("\n    2 - Comparar Strings");
    printf("\n    3 - Buscar ocorrencia de string em outra string");
    printf("\n    4 - Encerrar programa\n");
    scanf("%d\n", &option);

    return option;
}

int main(){
    while(1){
        int option = menu();

        char strA[50];
        char strB[50];

        if(option == 1){
            scanf("%s\n", strA);
            scanf("%s\n", strB);

            char strCat[100];

            string_concatenar(strA, strB, strCat);

            printf("Strings:\n");
            printf("  %s\n", strA);
            printf("  %s\n", strB);
            printf("\n%s\n", strCat);
        }

        if(option == 2){
            scanf("%s\n", strA);
            scanf("%s\n", strB);

            printf("Strings:\n");
            printf("  %s\n", strA);
            printf("  %s\n", strB);

            int result = string_comparar(strA, strB);

            if(result == -1){
                printf("\n%s eh anterior a %s\n", strA, strB);
            }else if(result == 1){
                printf("\n%s eh posterior a %s\n", strA, strB);
            }else{
                printf("\n%s eh igual a %s\n", strA, strB);
            }
        }

        if(option == 3){
            scanf("%s\n", strA);
            scanf("%s\n", strB);

            printf("Strings:\n");
            printf("  %s\n", strA);
            printf("  %s\n", strB);

            if(string_ocorrencia(strA, strB)){
                printf("\n%s ocorre em %s\n", strB, strA);
            }else{
                printf("\n%s nao ocorre em %s\n", strB, strA);
            }
        }

        if(option == 4){
            break;
        }

        printf("\n");
    }
}