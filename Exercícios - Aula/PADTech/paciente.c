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
    if(consultaLesao(p.lesoes, p.qntLesao, les)){
        p.lesoes[p.qntLesao] = les;
        p.qntLesao++;
    }else{
        printf("A lesao ja foi cadastrada no paciente.");
    }

    return p;
}

