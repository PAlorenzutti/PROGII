#ifndef _PESSOA_H
#define _PESSOA_H

#include "data.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NOME 50
#define MAX_CPF 14

typedef struct{
    char nome[MAX_NOME];
    tData nascimento;
    char CPF[MAX_CPF];
}tPessoa;

void setNome(tPessoa *p);

void setData(tPessoa *p);

void setCPF(tPessoa *p);

tPessoa* criaPessoa();

char* getNome(tPessoa *p);

tData* getData(tPessoa *p);

char* getCPF(tPessoa *p);

void printaPessoa(tPessoa *p);

void liberaPessoa(tPessoa *p);

int verificaCPFValidoPessoa(char *CPF);

#endif