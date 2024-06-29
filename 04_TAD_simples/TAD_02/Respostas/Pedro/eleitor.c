#include <stdio.h>

#include "eleitor.h"

tEleitor CriaEleitor(int id, int votoP, int votoG){
    tEleitor eleitor;

    eleitor.id = id;
    eleitor.votoP = votoP;
    eleitor.votoG = votoG;

    return eleitor;
}

tEleitor LeEleitor(){
    tEleitor eleitor;

    int id, votoP, votoG;

    scanf("%d %d %d\n", &id, &votoP, &votoG);
    printf("%d %d %d\n", id, votoP, votoG);

    eleitor = CriaEleitor(id, votoP, votoG);

    return eleitor;
}