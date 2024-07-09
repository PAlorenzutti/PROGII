#include "loja.h"

tLoja AbreLoja(int id, float aluguel){
    tLoja loja;

    loja.id = id;
    loja.aluguel = aluguel;
    loja.totalVendedores = 0;
    loja.lucro = 0 - aluguel;

    return loja;
}

/**
 * @brief Verifica se o ID de uma loja é igual a outro.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja a ser verificada.
 * @param id ID da loja a ser comparado.
 * @return int Retorna 1 se o ID da loja é igual ao ID passado como parâmetro, ou 0 caso contrário.
 */
int VerificaIdLoja(tLoja loja, int id);

tLoja ContrataVendedor(tLoja loja, tVendedor vendedor){
    loja.vendedores[loja.totalVendedores] = vendedor;
    loja.totalVendedores++;

    return loja;
}

/**
 * @brief Registra uma nova venda para um vendedor da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @param nome Nome do vendedor que realizou a venda.
 * @param valor Valor da venda a ser registrada.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com a venda registrada.
 */
tLoja RegistraVenda(tLoja loja, char nome[50], float valor){
    //no que concerne a loja
    loja.lucro += valor;

    //no que concerne ao vendedor
    for(int i = 0; i < loja.totalVendedores; i++){
        //se for igual, retorna 1 e entra
        if(VerificaNomeVendedor(loja.vendedores[i], nome)){
            loja.vendedores[i] = ContabilizaVenda(loja.vendedores[i], valor);
        }
    }

    return loja;
}

/**
 * @brief Calcula o lucro da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com o lucro calculado.
 */
tLoja CalculaLucro(tLoja loja);

/**
 * @brief Imprime o relatório da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 */
void ImprimeRelatorioLoja(tLoja loja);