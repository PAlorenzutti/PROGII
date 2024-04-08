
#ifndef _UTILS_H
#define _UTILS_H

#include "paciente.h"
#include "lesao.h"
#include "data.h"


void associaLesaoPaciente(Paciente pacs[], int tamPacs, Lesao les); //já foi
int calcularIdadePaciente(Data d);
int calcularMediaIdade(Paciente pacs[], int tamPacs);
#endif
