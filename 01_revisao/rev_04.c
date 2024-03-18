#include <stdio.h>
#include <math.h>

int main(){
    int decimal;
    int octal = 0;
    int i = 0;
    
    printf("Digite o numero que deseja converter de decimal para octal:\n");
    scanf("%d", &decimal);

    while(decimal){
        octal += (decimal % 8) * pow(10, i);
        decimal /= 8;
        i++;
    }

    printf("%d", octal);
}