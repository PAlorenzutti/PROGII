#include <stdio.h>
#include <string.h>

#include "vendedor.h"

tVendedor RegistraVendedor(char nome[50], float salario, float prct_comissao){
    tVendedor vendedor;

    strcpy(vendedor.nome, nome);
    vendedor.salario = salario;
    vendedor.prct_comissao = prct_comissao;
    vendedor.valor_vendido = 0;

    return vendedor;
}

int VerificaNomeVendedor(tVendedor vendedor, char nome[50]){
    if(!strcmp(vendedor.nome, nome)){
        return 1;
    }else{
        return 0;
    }
}

tVendedor ContabilizaVenda(tVendedor vendedor, float valor){
    vendedor.valor_vendido += valor;

    return vendedor;
}

float GetSalario(tVendedor vendedor){
    return vendedor.salario;
}

float GetComissao(tVendedor vendedor){
    return vendedor.valor_vendido * vendedor.prct_comissao;
}

float GetTotalVendido(tVendedor vendedor){
    return vendedor.valor_vendido;
}

float GetTotalRecebido(tVendedor vendedor){
    return vendedor.salario + GetComissao(vendedor);
}

void ImprimeRelatorioVendedor(tVendedor vendedor){
    printf("	%s > Total vendido: R$%.2f\n", vendedor.nome, vendedor.valor_vendido);
    printf("		Total recebido: R$%.2f\n", GetTotalRecebido(vendedor));
}