#include <stdio.h>
#include <string.h>
#include "evento.h"

void cadastrarEvento(Evento* eventos, int* numEventos){
    if(*numEventos < MAX_EVENTOS){
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
    }else{
        printf("Limite de eventos atingido!\n");
    }

}

void exibirEventos(Evento* eventos, int* numEventos){
    if(*numEventos > 0){
        printf("Eventos cadastrados:\n");
        for(int i = 0; i < *numEventos; i++){
            printf("%d - %s - %d/%d/%d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
        }
    }else{
        printf("Nenhum evento cadastrado.\n");
    }
}

void trocarDataEvento(Evento* eventos, int* numEventos){
    //pegando o indice do evento que deseja trocar
    int indice;
    scanf("%d", &indice);

    if(indice < *numEventos){
        //pegando a data do evento que deseja trocar
        int dia, mes, ano;
        scanf("%d %d %d", &dia, &mes, &ano);

        //trocando a data;
        eventos[indice].dia = dia;
        eventos[indice].mes = mes;
        eventos[indice].ano = ano;

        printf("Data modificada com sucesso!\n");
    }else{
        printf("Indice invalido!\n");
    }
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    if(*indiceA < *numEventos && *indiceB < *numEventos){
        //trocando os nomes
        char temp[50];
        strcpy(temp, eventos[*indiceA].nome);
        strcpy(eventos[*indiceA].nome, eventos[*indiceB].nome);
        strcpy(eventos[*indiceB].nome, temp);

        //trocando os dias
        int tempDia = eventos[*indiceA].dia;
        eventos[*indiceA].dia = eventos[*indiceB].dia;
        eventos[*indiceB].dia = tempDia;

        //trocando os meses
        int tempMes = eventos[*indiceA].mes;
        eventos[*indiceA].mes = eventos[*indiceB].mes;
        eventos[*indiceB].mes = tempMes;

        //trocando os anos
        int tempAno = eventos[*indiceA].ano;
        eventos[*indiceA].ano = eventos[*indiceB].ano;
        eventos[*indiceB].ano = tempMes;

        printf("Eventos trocados com sucesso!\n");
    }else{
        printf("Indices invalidos!\n");
    }

}