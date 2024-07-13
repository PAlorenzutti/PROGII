#include <stdio.h>
#include <stdbool.h>

#include "conta.h"
#include "usuario.h"

int main(){
    int numContas;
    scanf("%d\n", &numContas);

    tConta contas[numContas];
    int indexContas = 0;
    
    while(true){
        int opcao;
        scanf("%d\n", &opcao);

        if(opcao == 0){
            break;
        }

        //saque em conta;
        if(opcao == 1){
            int numero;
            float valor;
            scanf("%d %f", &numero, &valor);

            //verifica qual é conta que tem esse número
            for(int i = 0; i < numContas; i++){
                //verifica se a conta é desse numero;
                if(VerificaConta(contas[i], numero)){
                    //se for, deposita;
                    contas[i] = SaqueConta(contas[i], valor);
                }
            }            
        }

        //depósito em conta
        if(opcao == 2){
            int numero;
            float valor;
            scanf("%d %f", &numero, &valor);

            //verifica qual é conta que tem esse número
            for(int i = 0; i < numContas; i++){
                //verifica se a conta é desse numero;
                if(VerificaConta(contas[i], numero)){
                    //se for, deposita;
                    contas[i] = DepositoConta(contas[i], valor);
                }
            }
        }

        //cadastro de usuário
        if(opcao == 3){
            char nome[20];
            char cpf[15];
            scanf("%s %s ", nome, cpf);

            int numero;
            scanf("%d\n", &numero);

            tUsuario user = CriaUsuario(nome, cpf);

            contas[indexContas] = CriaConta(numero, user);

            indexContas++;
        }

        //imprime relatório
        if(opcao == 4){
            printf("===| Imprimindo Relatorio |===\n");
            
            //percorre todas as contas
            for(int i = 0; i < numContas; i++){
                ImprimeConta(contas[i]);
                printf("\n");
            }
        }

    }
    
    return 0;
}