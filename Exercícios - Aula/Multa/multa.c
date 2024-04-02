#include "multa.h"
#include <math.h>

float multaCircular(tCirculo c){
    return 6000 * ((PI * pow(c.raio, 2)) / 10000);
}

float multaRetangular(tRetangulo r){
    return 8000 * ((r.comprimento * r.largura) / 10000);
}

float multaTriangular(tTriangulo t){
    return (7000 * ((t.base * t.altura)/2) / 10000);
}
