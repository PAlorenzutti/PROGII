#include <stdio.h>

void string_concatenar(char* s1, char* s2, char* s3){
    int i, j;
    
    for(i = 0; s1[i] != '\0'; i++){
        s3[i] = s1[i];
    }

    for(j = 0; s2[j] != '\0'; j++){
        s3[i + j] = s2[j];
    }

    s3[i + j] = '\0';
} 

int main(){
    char s1[100], s2[100], s3[200];

    scanf("%[^\n]\n", s1);
    scanf("%[^\n]", s2);

    string_concatenar(s1, s2, s3);

    printf("%s", s3);

    return 0;
}