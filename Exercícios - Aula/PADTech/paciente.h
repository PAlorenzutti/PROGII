
#ifndef _PACIENTE_H
#define _PACIENTE_H

#include "lesao.h"
#include "data.h"
#include "constantes.h"

//definicao struct Paciente
typedef struct {
    char nome[MAX_TAM_NOME];
    Data dataNasc;
    char cartaoSus[MAX_TAM_SUS];
    char genero;
    Lesao lesoes[MAX_TAM_LES];
    int qntLesao;
} Paciente;

Paciente lerPaciente(); //já foi
int consultaPaciente(Paciente *pacs, int tamPacs, Paciente p); //já foi
void printPaciente(Paciente p); //já foi
void printPacienteResumido(Paciente p); //já foi
void printDescricao(Paciente pacs[], int tamPacs); //já foi
void obtemCartaoSusPaciente(Paciente p, char cartaoSus[]); //já foi
Paciente insereLesaoPaciente(Paciente p, Lesao les); //já foi

#endif