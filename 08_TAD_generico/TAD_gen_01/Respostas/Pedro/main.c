#include <stdio.h>
#include "tadgen.h"

int main(){
    printf("tad_gen_01\n");
    
    int tipo, numElem;
    printf("Digite o tipo e numero de elementos:\n");
    scanf("%d %d\n", &tipo, &numElem);
    
    tGeneric *gen = CriaGenerico(tipo, numElem);

    LeGenerico(gen);

    ImprimeGenerico(gen);

    DestroiGenerico(gen);

    return 0;
}