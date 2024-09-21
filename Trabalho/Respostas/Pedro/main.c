#include "ufood.h"

int main(){
    tUfoodES *ufood= inicializaUfood();

    ufood = rodaUfood(ufood);

    liberaUfood(ufood);

    return 0;
}