#ifndef NUMEROS_COMPLEXOS_H
#define NUMEROS_COMPLEXOS_H

#include <stdlib.h>
#include <stdio.h>

typedef struct ComplexNum ComplexNum;

ComplexNum* complexnum_conscruct(float real, float imaginary);

float complexnum_get_real(ComplexNum* num);

float complexnum_get_imaginary(ComplexNum* num);

void complexnum_set_real(ComplexNum* num, float real);

void complexnum_set_imaginary(ComplexNum* num, float imaginary);

ComplexNum* complexnum_get_conjugate(ComplexNum* num);

void complexnum_print(ComplexNum* num);

void complexnum_destroy(ComplexNum* num);

#endif