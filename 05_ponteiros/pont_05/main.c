#include "esfera_utils.h"
#include <stdio.h>

int main()
{
    float R, area, volume;

    printf("Digite o raio da esfera:\n");
    scanf("%f", &R);

    CalculaArea(R, &area);
    CalculaVolume(R, &volume);

    printf("Area: %.2f\n", area);
    printf("Volume: %.2f\n", volume);

    return 0;
}