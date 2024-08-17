#include "dracomania.h"
#include "duelo.h"
#include "carta.h"

int main(){
    tDracomania d = CriaDracomania();

    d = RodaDracomania(d);

    ImprimeRelatorioDracomania(d);

    LiberaDracomania(d);

    return 0;
}