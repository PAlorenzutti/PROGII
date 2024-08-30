#include "calculadora_complexos.h"

struct ComplexCalc{
    ComplexNum *num1;
    ComplexNum *num2;
};


ComplexCalc* complexcalc_conscruct(ComplexNum* num1, ComplexNum* num2){
    ComplexCalc *calc = (ComplexCalc*)malloc(sizeof(ComplexCalc));

    calc->num1 = num1;
    calc->num2 = num2;

    return calc;
}

ComplexNum* complexcalc_add(ComplexCalc* calc){
    //soma as partes reais
    float real = complexnum_get_real(calc->num1) + complexnum_get_real(calc->num2);

    //soma as partes imaginárias
    float imaginary = complexnum_get_imaginary(calc->num1) + complexnum_get_imaginary(calc->num2);

    ComplexNum *num = complexnum_conscruct(real, imaginary);

    return num;
}

ComplexNum* complexcalc_subtract(ComplexCalc* calc){
    //subtrai as partes reais
    float real = complexnum_get_real(calc->num1) - complexnum_get_real(calc->num2);

    //subtrai as partes imaginárias
    float imaginary = complexnum_get_imaginary(calc->num1) - complexnum_get_imaginary(calc->num2);

    ComplexNum *num = complexnum_conscruct(real, imaginary);

    return num;
}

ComplexNum* complexcalc_multiply(ComplexCalc* calc){
    //(a + bi)*(c + di) = (ac-bd) + (ad+cb)i
    
    //multiplica as partes reais
    float real = (complexnum_get_real(calc->num1) * complexnum_get_real(calc->num2)) - (complexnum_get_imaginary(calc->num1) * complexnum_get_imaginary(calc->num2));

    //multiplica as partes imaginárias
    float imaginary = (complexnum_get_real(calc->num1) * complexnum_get_imaginary(calc->num2)) + (complexnum_get_real(calc->num2) * (complexnum_get_imaginary(calc->num1)));

    ComplexNum *num = complexnum_conscruct(real, imaginary);

    return num;
}

void complexcalc_destroy(ComplexCalc* calc){
    complexnum_destroy(calc->num1);
    complexnum_destroy(calc->num2);
    free(calc);
}