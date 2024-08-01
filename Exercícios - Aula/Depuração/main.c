#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char *nome = (char*) malloc(100 * sizeof(char));

    strcpy(nome, "Anakin");

    printf("- Nome salvo: %s\n", nome);

    //abre o arquivo para fazer a escrita;
    FILE *f = fopen("saida.txt", "w");

    fprintf(f, "%s", nome);

    free(f);

    free(nome);

    return 0;
}