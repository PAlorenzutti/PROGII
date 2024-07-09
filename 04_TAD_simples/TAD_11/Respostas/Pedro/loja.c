#include <stdio.h>

#include "loja.h"

tLoja AbreLoja(int id, float aluguel){
    tLoja loja;

    loja.id = id;
    loja.aluguel = aluguel;
    loja.totalVendedores = 0;
    loja.lucro = 0;

    return loja;
}

int VerificaIdLoja(tLoja loja, int id){
    if(loja.id == id){
        return 1;
    }else{
        return 0;
    }
}

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
    //no que concerne ao vendedor
    for(int i = 0; i < loja.totalVendedores; i++){
        //se for igual, retorna 1 e entra
        if(VerificaNomeVendedor(loja.vendedores[i], nome)){
            loja.vendedores[i] = ContabilizaVenda(loja.vendedores[i], valor);
        }
    }

    return loja;
}

tLoja CalculaLucro(tLoja loja){
    float totalVendido = 0;
    float totalSalarios = 0;
    float totalComissoes = 0;
    
    
    for(int i = 0; i < loja.totalVendedores; i++){
        totalVendido += GetTotalVendido(loja.vendedores[i]);
        totalSalarios += GetSalario(loja.vendedores[i]);
        totalComissoes += GetComissao(loja.vendedores[i]);
    }

    loja.lucro = totalVendido - totalSalarios - totalComissoes - loja.aluguel;

    return loja;
}

/**
 * @brief Imprime o relatório da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 */
void ImprimeRelatorioLoja(tLoja loja){
    //imprime informações da loja em si
    printf("Loja %d: Lucro total: R$ %.2f\n", loja.id, loja.lucro);

    //imprime informações dos vendedores da loja;
    for(int i = 0; i < loja.totalVendedores; i++){
        ImprimeRelatorioVendedor(loja.vendedores[i]);
    }
}