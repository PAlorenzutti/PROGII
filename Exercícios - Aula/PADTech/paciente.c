#include <stdio.h>
#include <string.h>
#include "paciente.h"

Paciente lerPaciente()
{
    Paciente p;
    scanf("%[^\n]\n", p.nome);
    p.dataNasc = lerData();
    scanf("%s\n", p.cartaoSus);
    scanf("%c\n", &p.genero);
    p.qntLesao = 0;

    return p;
}

int consultaPaciente(Paciente pacs[], int tamPacs, Paciente p)
{
    for (int i=0; i<tamPacs; i++)
    {
        if (strcmp(pacs[i].cartaoSus, p.cartaoSus) == 0)
        {
            return 0;
        }
    }    
    return 1;        
}

void obtemCartaoSusPaciente(Paciente p, char cartaoSus[])
{
    //Associa o cartão SUS de um paciente ao cartão SUS criado na função associaLesaoPaciente
    strcpy(cartaoSus, p.cartaoSus);
}

Paciente insereLesaoPaciente(Paciente p, Lesao les){
    //Caso não exista lesão igual, inserir lesão.
    if(p.qntLesao >= 10){
        printf("Numero de lesoes excedido pelo paciente.");
    }else if(consultaLesao(p.lesoes, p.qntLesao, les)){
        p.lesoes[p.qntLesao] = les;
        p.qntLesao++;
    }else{
        printf("A lesao ja foi cadastrada no paciente.");
    }

    return p;
}

void printPacienteResumido(Paciente p){
    //Percorrer as lesões do paciente e printar identificador único
    for(int i = 0; i < p.qntLesao; i++){
        printLesao(p.lesoes[i]);
    }
}

void printPaciente(Paciente p){
    printf(" - %s - ", p.nome);
    printPacienteResumido(p);
}

void printDescricao(Paciente pacs[], int tamPacs){
    //Printar total de pacientes
    printf("\nTOTAL PACIENTES: %d", tamPacs);

    //Calcular o número total de lesões e printar total de lesões
    int totalLesoes = 0;

    for(int i = 0; i < tamPacs; i++){
        totalLesoes += pacs[i].qntLesao;
    }

    printf("\nTOTAL LESOES: %d", totalLesoes);

    //Verificar se tem chance de cirurgia, somar ao número de cirurgias e printar total de cirurgias
    int totalCirurgias = 0;

    for(int i = 0; i < tamPacs; i++){
        totalCirurgias += chanceCirurgia(pacs[i].lesoes, pacs[i].qntLesao);
    }

    printf("\nTOTAL CIRURGIAS: %d", totalCirurgias);

    //Printar todos os pacientes cadastrados
    printf("\nLISTA DE PACIENTES:\n");

    for(int i = 0; i < tamPacs; i++){
        if(pacs[i].qntLesao > 0){
            printPaciente(pacs[i]);
            printf("\n");            
        }
    }
}