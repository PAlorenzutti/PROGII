#include <stdio.h>
#include <stdlib.h>

#include "circulo.h"
#include "triangulo.h"
#include "retangulo.h"

int main()
{
    int n, i=0;
    scanf("%d", &n);
    float *multas = (float *) malloc (sizeof(float));

    while(i<n)
    {
        char tipo;
        scanf("%c", &tipo);
        if(tipo == 'C')
        {
            tCirculo *c = criaCirculo();
            multas[i] = multaCirculo(c);
            i++;
            multas = (float *) realloc (multas, sizeof(float) * (i + 1));
            liberaCirculo(c);
        }
        else
        {
            if(tipo == 'R')
            {
                tRetangulo *r = criaRetantulo();
                multas[i] = multaRetangulo(r);
                i++;
                multas = (float *) realloc (multas, sizeof(float) * (i + 1));
                liberaRetangulo(r);
            }
            else
            {
                if(tipo == 'T')
                {
                    tTriangulo *t = criaTriangulo();
                    multas[i] = multaTriangulo(t);
                    i++;
                    multas = (float *) realloc (multas, sizeof(float) * (i + 1));
                    liberaTriangulo(t);
                }
            }
        }        
    }
    for(i=0; i<n; i++)
        printf("Preço: %.2f\n", multas[i]);

    free(multas);    
    return 0;
}