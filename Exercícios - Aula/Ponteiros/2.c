#include <stdio.h>

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

    return 0;
}

int main(){
    char strA[100];
    char strB[100];

    scanf("%[^\n]\n", strA);
    scanf("%[^\n]", strB);

    if(string_ocorrencia(strA, strB)){
        printf("string B ocorre dentro de A");
    }else{
        printf("string B não ocorre dentro de A");
    }

    return 0;
}