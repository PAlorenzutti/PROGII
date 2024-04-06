
#ifndef _DATA_H
#define _DATA_H

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

Data lerData(); //já foi
void printData(Data d);
//Dúvida se pode implementar mais uma função pra calculdar idade e média de idade.

#endif