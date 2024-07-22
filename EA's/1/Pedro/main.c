#include "servidor.h"

int main(){
    Servidor s;

    s = leRegistrosServidor();

    criaRelatorioServidor(s);

    return 0;
}