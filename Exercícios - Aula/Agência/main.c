#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CHAR 100

typedef struct{
    char nome[MAX_CHAR];
    char cpf[MAX_CHAR];
    char nascimento[MAX_CHAR];
    char endereco[MAX_CHAR];
    char celular[MAX_CHAR];
    char email[MAX_CHAR];
    float saldo;
}tConta;

typedef struct{
    tConta correntista[100];
    int index;
}tAgencia;

int menu(){
    int option;

    printf("\n1 - Cadastrar novo cliente");
    printf("\n2 - Inserir dinheiro");
    printf("\n3 - Remover dinheiro");
    printf("\n4 - Remover cliente");
    printf("\n5 - Encerrar o programa");
    printf("\nDigite a opcao desejada: ");
    scanf("%d", &option);

    return option;
}

tAgencia cadastrarNovoCliente(tAgencia agencia){
    getchar();

    printf("\nDigite o nome do cliente: ");
    fgets(agencia.correntista[agencia.index].nome, MAX_CHAR, stdin);
    agencia.correntista[agencia.index].nome[strcspn(agencia.correntista[agencia.index].nome, "\n")] = 0;

    printf("\nDigite o CPF (apenas numeros): ");
    scanf("%s", agencia.correntista[agencia.index].cpf);

    printf("\nDigite a data de nascimento (apenas numeros): ");
    scanf("%s", agencia.correntista[agencia.index].nascimento);

    getchar();

    printf("\nDigite o endereco: ");
    fgets(agencia.correntista[agencia.index].endereco, MAX_CHAR, stdin);
    agencia.correntista[agencia.index].endereco[strcspn(agencia.correntista[agencia.index].endereco, "\n")] = 0;

    printf("\nDigite o celular (apenas numeros): ");
    scanf("%s", agencia.correntista[agencia.index].celular);

    printf("\nDigite o endereco de e-mail: ");
    scanf("%s", agencia.correntista[agencia.index].email);

    printf("\nDigite o saldo da conta: ");
    scanf("%f", &agencia.correntista[agencia.index].saldo);

    agencia.index++;

    return agencia;
}

tAgencia removerCliente(tAgencia agencia, char cpfExclude[MAX_CHAR]){
    tAgencia temp;
    temp.index = 0;
    
    for(int i = 0; i < agencia.index; i++){
        if(strcmp(agencia.correntista[i].cpf, cpfExclude) != 0){
            temp.correntista[temp.index] = agencia.correntista[i];
            temp.index++;
        }
    }

    return temp;
}

tAgencia inserirDinheiro(tAgencia agencia, char cpf[MAX_CHAR], float quantia){
    for(int i = 0; i < agencia.index; i++){
        if(strcmp(agencia.correntista[i].cpf, cpf) == 0){
            agencia.correntista[i].saldo += quantia;
            break;
        }
    }

    return agencia;
}

tAgencia removerDinheiro(tAgencia agencia, char cpf[MAX_CHAR], float quantia){
    for(int i = 0; i < agencia.index; i++){
        if(strcmp(agencia.correntista[i].cpf, cpf) == 0){
            agencia.correntista[i].saldo -= quantia;
            break;
        }
    }

    return agencia;
}

void printarAgencia(tAgencia agencia){
    for(int i = 0; i < agencia.index; i++){
        printf("\nCliente n° %d", i + 1);
        printf("\nNome: %s", agencia.correntista[i].nome);
        printf("\nCPF: %s", agencia.correntista[i].cpf);
        printf("\nData de Nascimento: %s", agencia.correntista[i].nascimento);
        printf("\nEndereço: %s", agencia.correntista[i].endereco);
        printf("\nCelular: %s", agencia.correntista[i].celular);
        printf("\nE-mail: %s", agencia.correntista[i].email);
        printf("\nSaldo: %.2f", agencia.correntista[i].saldo);
    }
}

int main(){
    tAgencia agencia;

    //Inicializando a agencia com nenhum cliente.
    agencia.index = 0;

    while(agencia.index < 100){
        int option;
        option = menu();

        if(option == 1){
            agencia = cadastrarNovoCliente(agencia);
            printarAgencia(agencia);
        }

        if(option == 2){
            char cpf[MAX_CHAR];
            printf("Digite o CPF do cliente que deseja inserir dinheiro: ");
            scanf("%s", cpf);

            float quantia;
            printf("Digite a quantia: ");
            scanf("%f", &quantia);

            agencia = inserirDinheiro(agencia, cpf, quantia);
            printarAgencia(agencia);
        }

        if(option == 3){
            char cpf[MAX_CHAR];
            printf("Digite o CPF do cliente que deseja remover dinheiro: ");
            scanf("%s", cpf);

            float quantia;
            printf("Digite a quantia: ");
            scanf("%f", &quantia);

            agencia = removerDinheiro(agencia, cpf, quantia);
            printarAgencia(agencia);
        }

        if(option == 4){
            char cpfExclude[MAX_CHAR];
            printf("Digite o CPF do cliente que deseja remover: ");
            scanf("%s", cpfExclude);

            agencia = removerCliente(agencia, cpfExclude);
            printarAgencia(agencia);
        }

        if(option == 5){
            break;
        }
    }

    return 0;
}