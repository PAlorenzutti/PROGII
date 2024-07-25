#include <stdio.h>
#include <math.h>

typedef struct{
    float x, y, r;
}tipoCirculo;

int main(){
    tipoCirculo alvo, tiro;
    float distRaio, distCentro;

    printf("Digite as coordenadas do centro do alvo e seu raio, respectivamente:\n");
    scanf("%f %f %f", &alvo.x, &alvo.y, &alvo.r);

    printf("Digite as coordenadas do centro do tiro e seu raio, respectivamente:\n");
    scanf("%f %f %f", &tiro.x, &tiro.y, &tiro.r);

    distRaio = alvo.r + tiro.r;

    //se a distancia do ponto do tiro até o centro do alvo for maior do que a distancia do centro do alvo até a circunferencia
    distCentro = sqrt(pow(tiro.x - alvo.x, 2) + pow(tiro.y - alvo.y, 2));

    if(distCentro < distRaio){
        printf("ACERTOU!");
    }else{
        printf("ERROU!");
    }

    return 0;
}