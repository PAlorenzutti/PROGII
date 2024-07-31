#include "pessoa.h"

int main(){
    tPessoa *p = criaPessoa();

    printaPessoa(p);

    liberaPessoa(p);

    return 0;
}