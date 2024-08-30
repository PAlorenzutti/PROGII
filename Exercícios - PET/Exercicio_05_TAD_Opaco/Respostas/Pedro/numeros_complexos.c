#include "numeros_complexos.h"

struct ComplexNum{
    float real;
    float imaginary;
};

ComplexNum* complexnum_conscruct(float real, float imaginary){
    ComplexNum *num = (ComplexNum*)malloc(sizeof(ComplexNum));

    num->real = real;
    num->imaginary = imaginary;

    return num;
}

float complexnum_get_real(ComplexNum* num){
    return num->real;
}

float complexnum_get_imaginary(ComplexNum* num){
    return num->imaginary;
}

void complexnum_set_real(ComplexNum* num, float real){
    num->real = real;
}

void complexnum_set_imaginary(ComplexNum* num, float imaginary){
    num->imaginary = imaginary;
}

ComplexNum* complexnum_get_conjugate(ComplexNum* num){
    ComplexNum *conjugate = (ComplexNum*)malloc(sizeof(ComplexNum));

    conjugate->real = num->real;
    conjugate->imaginary = num->imaginary * (-1.0);

    return conjugate;
}

void complexnum_print(ComplexNum* num){
    printf("%.2f + (%.2f)i", num->real, num->imaginary);
}

void complexnum_destroy(ComplexNum* num){
    free(num);
}