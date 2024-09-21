#include "cliente.h"

#include "sacola.h"
#include "produto.h"
#include "constantes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cliente{
    char *nome;
    char *cpf;
    char *dataNascimento;
    char *telefone;
    char *endereco;
    char *usuario;
    char *senha;
    char *numeroCartao;
    char *email;

    tSacola *sacola;
    tSacola *compra;
};

tCliente *criaCliente(){
    tCliente *cliente = (tCliente*)malloc(sizeof(tCliente));

    //aloca espaço para cada atributo;
    cliente->nome = (char*)malloc(sizeof(char) * TAM_NOME);
    cliente->cpf = (char*)malloc(sizeof(char) * TAM_CPF);
    cliente->dataNascimento = (char*)malloc(sizeof(char) * TAM_DATA);
    cliente->telefone = (char*)malloc(sizeof(char) * TAM_TELEFONE);
    cliente->endereco = (char*)malloc(sizeof(char) * TAM_ENDERECO);
    cliente->email = (char*)malloc(sizeof(char) * TAM_EMAIL);
    cliente->usuario = (char*)malloc(sizeof(char) * TAM_USUARIO);
    cliente->senha = (char*)malloc(sizeof(char) * TAM_SENHA);
    cliente->numeroCartao = (char*)malloc(sizeof(char) * TAM_CARTAO);

    //cria sacola e compra do cliente
    cliente->sacola = criaSacola(cliente->email, cliente->cpf);

    //lê a linha toda até o '\n'
    char linha[500];
    fgets(linha, 500, stdin);

    if(sscanf(linha, "%99[^;]; %12[^;]; %10[^;]; %14[^;]; %149[^;]; %49[^;]; %14[^;]; %19[^;]; %12s\n", cliente->nome, cliente->cpf, cliente->dataNascimento, cliente->telefone, cliente->endereco, cliente->email, cliente->usuario, cliente->senha, cliente->numeroCartao) != 9){
        printf("ATRIBUTO(S) FALTANTE(S), FAVOR INICIAR O CADASTRO NOVAMENTE.\n");
        liberaCliente(cliente);
        return NULL;
    }

    return cliente;
}

int comparaCliente(tCliente *cliente1, tCliente *cliente2){
    return strcmp(cliente1->cpf, cliente2->cpf);
}

char *getCpfCliente(tCliente *cliente){
    return cliente->cpf;
}

void adicionaItemCliente(tCliente *cliente, tItem *item){
    adicionaItemSacola(cliente->sacola, item);
}

void removeItemCliente(tCliente *cliente, tItem *item){
    removeItemSacola(cliente->sacola, item);
}

void limpaSacolaCliente(tCliente *cliente){
    limpaSacola(cliente->sacola);
}

int efetuaCompraCliente(tCliente *cliente){
    //se a sacola não estiver vazia, efetua compra;
    if(!sacolaVazia(cliente->sacola)){
        //cria a sacola de compras do cliente;
        cliente->compra = criaSacola(cliente->email, cliente->cpf);
        
        //efetua a compra;
        return efetuaCompraSacola(cliente->sacola, cliente->compra);
    }else{
        printf("SACOLA DE COMPRAS VAZIA!\n");
        return 0;
    }
}

void printaCliente(tCliente *cliente){
    printf("%s; %s; %s; %s; %s; %s; %s; %s; %s\n", cliente->nome, cliente->cpf, cliente->dataNascimento, cliente->telefone, cliente->endereco, cliente->email, cliente->usuario, cliente->senha, cliente->numeroCartao);
}

void liberaCliente(tCliente *cliente){
    free(cliente->nome);
    free(cliente->cpf);
    free(cliente->dataNascimento);
    free(cliente->telefone);
    free(cliente->endereco);
    free(cliente->email);
    free(cliente->usuario);
    free(cliente->senha);
    free(cliente->numeroCartao);

    liberaSacola(cliente->sacola);

    free(cliente);
}