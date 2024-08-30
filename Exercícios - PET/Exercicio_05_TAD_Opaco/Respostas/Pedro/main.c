#include "calculadora_complexos.h"
#include "numeros_complexos.h"

#include <stdio.h>

int main(){
    float real1, imaginary1;
    float real2, imaginary2;

    scanf("%f + (%f)i\n", &real1, &imaginary1);
    scanf("%f + (%f)i\n", &real2, &imaginary2);

    //cria e aloca cada num
    ComplexNum *num1 = complexnum_conscruct(real1, imaginary1);
    ComplexNum *num2 = complexnum_conscruct(real2, imaginary2);

    //cria e aloca calc
    ComplexCalc *calc = complexcalc_conscruct(num1, num2);

    //soma
    ComplexNum *soma = complexcalc_add(calc);
    printf("Soma: ");
    complexnum_print(soma);
    complexnum_destroy(soma);
    printf("\n");

    //subtração
    ComplexNum *subtracao = complexcalc_subtract(calc);
    printf("Subtracao: ");
    complexnum_print(subtracao);
    complexnum_destroy(subtracao);
    printf("\n");

    //multiplicação
    ComplexNum *multiplicacao = complexcalc_multiply(calc);
    printf("Multiplicacao: ");
    complexnum_print(multiplicacao);
    complexnum_destroy(multiplicacao);
    printf("\n");

    //conjugado
    ComplexNum *conjugado1 = complexnum_get_conjugate(num1);
    printf("Conjugado: ");
    complexnum_print(conjugado1);
    complexnum_destroy(conjugado1);
    printf(" / ");
    ComplexNum *conjugado2 = complexnum_get_conjugate(num2);
    complexnum_print(conjugado2);
    complexnum_destroy(conjugado2);
    printf("\n");

    complexcalc_destroy(calc);

    return 0;
}
