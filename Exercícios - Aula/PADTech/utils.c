#include "utils.h"
#include <stdio.h>
#include <string.h>
#include "data.h"

void associaLesaoPaciente(Paciente pacs[], int tamPacs, Lesao les)
{
    char cSusPaciente[MAX_TAM_SUS];
    char cSusLesao[MAX_TAM_SUS];

    obtemCartaoSusLesao(les, cSusLesao);
    
    for (int i=0; i<tamPacs; i++)
    {   
        obtemCartaoSusPaciente(pacs[i], cSusPaciente);
        if (strcmp(cSusLesao, cSusPaciente) == 0)
        {
            //implementar a partir do insereLesaoPaciente
            pacs[i] = insereLesaoPaciente(pacs[i], les);
        }
    }
}

int calcularIdadePaciente(Data d){
    int idade;

    idade = ANO - d.ano;

    if(d.mes > MES || (d.mes == MES && d.dia > DIA)){
        idade--;
    }

    return idade;
}

int calcularMediaIdade(Paciente pacs[], int tamPacs){
    int mediaIdade = 0;
    
    for(int i = 0; i < tamPacs; i++){
        mediaIdade += calcularIdadePaciente(pacs[i].dataNasc);
    }

    if(tamPacs > 0){
        return mediaIdade / tamPacs;
    }else{
        return 0;
    }
}
