#include <stdio.h>

int fibonacci(int n){

    if(!n){
        return 0;
    }

    if(n > 0 && n < 3){
        return 1;
    }

    n = fibonacci(n - 1) + fibonacci(n - 2);

    return n;
}

int main(){
    int n;

    scanf("%d", &n);

    printf("%d\n", fibonacci(n));

    return 0;
}