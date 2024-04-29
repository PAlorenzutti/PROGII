#include <stdio.h>

int main(){
    int A, *B, **C, ***D;

    scanf("%d", &A);

    B = &A;
    C = &B;
    D = &C;

    printf("\nDobro: %d", 2*(*B));
    printf("\nTriplo: %d", 3*(**C));
    printf("\nQuadruplo: %d", 4*(***D));

    return 0;
}