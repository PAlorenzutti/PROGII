#ifndef CALCULADORA_COMPLEXOS_H
#define CALCULADORA_COMPLEXOS_H

#include "numeros_complexos.h"
#include <stdlib.h>

typedef struct ComplexCalc ComplexCalc;

ComplexCalc* complexcalc_conscruct(ComplexNum* num1, ComplexNum* num2);

ComplexNum* complexcalc_add(ComplexCalc* calc);

ComplexNum* complexcalc_subtract(ComplexCalc* calc);

ComplexNum* complexcalc_multiply(ComplexCalc* calc);

void complexcalc_destroy(ComplexCalc* calc);

#endif