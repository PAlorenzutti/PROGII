#include <stdio.h>
#include <math.h>

typedef struct{
    int real;
    int imaginario;
}tComplexo;

int menu(){
    int opcao;
    
    printf("1 - Soma de dois numeros complexos\n");
    printf("2 - Produto de dois numeros complexos\n");
    printf("3 - Modulo de um numero complexo\n");
    printf("4 - Encerrar programa\n");
    printf("Digite a opcao desejada: ");
    
    scanf("%d", &opcao);

    return opcao;
}

tComplexo lerNumero(){
    tComplexo c;

    printf("Digite a parte real e imaginaria, respectivamente: ");
    scanf("%d %d", &c.real, &c.imaginario);

    return c;
}

void complexoSoma(tComplexo *c1,tComplexo *c2, tComplexo *s){
    (*s).real = (*c1).real + (*c2).real;
    (*s).imaginario = (*c1).imaginario + (*c2).imaginario;
}

void complexoMult(tComplexo *c1,tComplexo *c2, tComplexo *m){
    //c1 = a + bi
    //c2 = c + di
    (*m).real = ( (*c1).real * (*c2).real ) - ( (*c1).imaginario * (*c2).imaginario );
    //ac - bd
    (*m).imaginario = ( (*c1).real * (*c2).imaginario ) + ( (*c1).imaginario * (*c2).real );
    //ad + bc
}

double modulo(tComplexo *c, double *m){
    *m = sqrt( pow((*c).real, 2) + pow((*c).imaginario, 2) );
}

int main(){
    while(1){
        int opcao = menu();

        if(opcao == 1){
            tComplexo c1 = lerNumero();
            tComplexo c2 = lerNumero();
            tComplexo s;

            complexoSoma(&c1, &c2, &s);

            printf("\nA soma entre os dois números complexos gera: %d + %di\n\n", s.real, s.imaginario);
        }

        if(opcao == 2){
            tComplexo c1 = lerNumero();
            tComplexo c2 = lerNumero();
            tComplexo m;

            complexoMult(&c1, &c2, &m);

            printf("\nO produto entre os dois números complexos gera: %d + %di\n\n", m.real, m.imaginario);
        }

        if(opcao == 3){
            tComplexo c = lerNumero();
            double mod;

            modulo(&c, &mod);

            printf("\nO modulo do numero imaginario corresponde a %.2lf\n\n", mod);
        }

        if(opcao == 4){
            break;
        }
    }

    return 0;
}