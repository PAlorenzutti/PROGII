#include <stdio.h>
#include <stdbool.h>

#include "loja.h"
#include "vendedor.h"

int main(){
    //pega o número de lojas a serem cadastradas
    int numLojas;
    scanf("%d", &numLojas);

    //cria o vetor lojas e o index para cada loja;
    tLoja lojas[numLojas];
    int index = 0;

    while(true){
        int opcao;
        scanf("%d", &opcao);

        //sair do programa
        if(opcao == 0){
            break;
        }

        //abrir loja
        if(opcao == 1){
            int id;
            float aluguel;

            scanf("%d %f\n", &id, &aluguel);

            lojas[index] = AbreLoja(id, aluguel);

            //aumenta index para próxima loja;
            index++;
        }

        //contratar vendedor
        if(opcao == 2){
            char nome[50];
            float salario;
            float prct_comissao;

            scanf("%s %f %f\n", nome, &salario, &prct_comissao);

            tVendedor vendedor = RegistraVendedor(nome, salario, prct_comissao);

            int indexLoja;
            scanf("%d\n", &indexLoja);

            lojas[indexLoja - 1] = ContrataVendedor(lojas[indexLoja - 1], vendedor);
        }

        //registrar venda
        if(opcao == 3){
            int indexLoja;
            char nome[50];
            float valor;

            scanf("%d %s %f\n", &indexLoja, nome, &valor);

            lojas[indexLoja - 1] = RegistraVenda(lojas[indexLoja - 1], nome, valor);
        }

        if(opcao == 4){
            for(int i = 0; i < numLojas; i++){
                //antes de printar calcula lucro loja
                lojas[i] = CalculaLucro(lojas[i]);

                //printa a loja com seu lucro;
                ImprimeRelatorioLoja(lojas[i]);
            }
        }
    }

    return 0;
}