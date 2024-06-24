#include "esfera_utils.h"
#include <stdio.h>

int main()
{
    float R, area, volume;
    
    scanf("%f", &R);

    CalculaArea(R, &area);
    CalculaVolume(R, &volume);

    printf("Area: %.2f\n", area);
    printf("Volume: %.2f\n", volume);

    return 0;
}