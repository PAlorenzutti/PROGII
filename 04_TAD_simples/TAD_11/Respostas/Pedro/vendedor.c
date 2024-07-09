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

/**
 * @brief Obtém o salário de um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna o salário do vendedor.
 */
float GetSalario(tVendedor vendedor);

/**
 * @brief Obtém a comissão de um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna a comissão do vendedor.
 */
float GetComissao(tVendedor vendedor);

/**
 * @brief Obtém o total vendido por um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna o total vendido pelo vendedor.
 */
float GetTotalVendido(tVendedor vendedor);

/**
 * @brief Obtém o total recebido por um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna o total recebido pelo vendedor (salário + comissão).
 */
float GetTotalRecebido(tVendedor vendedor);

/**
 * @brief Imprime o relatório de um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 */
void ImprimeRelatorioVendedor(tVendedor vendedor);