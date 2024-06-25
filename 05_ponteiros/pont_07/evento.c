#include <stdio.h>
#include <string.h>
#include "evento.h"

void cadastrarEvento(Evento* eventos, int* numEventos){
    //pegando e cadastrando nome do evento;
    char nome[50];
    scanf("%s", nome);
    
    strcpy(eventos[*numEventos].nome, nome);

    //pegando e cadastrando dia do evento;
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);

    eventos[*numEventos].dia = dia;
    eventos[*numEventos].mes = mes;
    eventos[*numEventos].ano = ano;

    *numEventos += 1;

    printf("Evento cadastrado com sucesso!\n");
}

void exibirEventos(Evento* eventos, int* numEventos){
    printf("Eventos cadastrados:\n");
    for(int i = 0; i < *numEventos; i++){
        printf("%d - %s - %d/%d/%d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }
}