#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
#include "data.h"
#include "lesao.h"
#include "paciente.h"
#include "utils.h"

int main(){
    Paciente pacs[MAX_TAM_PACIENTES];
    int tamPacs = 0;

    while(1){
        char option;
        scanf("%c\n", &option);
    
        if(option == 'P'){
            //Cadastro de paciente
            Paciente p;
            p = lerPaciente();

            //Se a quantidade de pacs tiver excedido o máximo, para o programa
            if(tamPacs > MAX_TAM_PACIENTES){
                break;
            }else{
                //Consulta se o paciente já está na lista
                if(consultaPaciente(pacs, tamPacs, p)){
                    pacs[tamPacs] = p;
                    tamPacs++;
                }
            }
        }else if(option == 'L'){
            //Cadastro de lesão
            Lesao les;
            les = lerLesao();
            associaLesaoPaciente(pacs, tamPacs, les);
        }else if(option == 'F'){
            //Se a opção for F, ele sai do loop e, caso tenha cadastrado pacientes e/ou lesões, será printado tais informações.
            break;
        }
    }

    
    printDescricao(pacs, tamPacs);
}