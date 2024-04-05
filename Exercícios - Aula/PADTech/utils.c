#include "utils.h"
#include <string.h>

void associaLesaoPaciente(Paciente pacs[], int tamPacs, Lesao les)
{
    char cSusPaciente[MAX_TAM_SUS];
    char cSusLesao[MAX_TAM_SUS];

    obtemCartaoSusLesao(les, cSusLesao);
    
    for (int i=0; i<tamPacs; i++)
    {   
        obtemCartaoSusPaciente(pacs[i], obtemCartaoSusPaciente);
        if (strcmp(cSusLesao, cSusPaciente) == 0)
        {
            //implementar a partir do insereLesaoPaciente
            pacs[i] = insereLesaoPaciente(pacs[i], les);
        }
    }

    printf("Paciente não encontrado para cadastrar lesao.");
}