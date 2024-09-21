#include "ufood.h"
#include "loja.h"
#include "cliente.h"
#include "fornecedor.h"
#include "ingrediente.h"
#include "produto.h"
#include "industrializado.h"
#include "prato.h"
#include "item.h"
#include "constantes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct UfoodES{
    tLoja **lojas;
    int qtdLojas;

    tCliente **clientes;
    int qtdClientes;

    tFornecedor **fornecedores;
    int qtdFornecedores;
};

int switchOperacao(){
    //pega o código da operação
    char operacao[TAM_OPERACOES];
    scanf("%3s", operacao);

    //se for igual a CAT;
    if(!strcmp(operacao, ATORES)){
        return 1;
    } 

    //se for igual a CAI;
    if(!strcmp(operacao, INGREDIENTES)){
        return 2;
    }

    //se for igual a CAP;
    if(!strcmp(operacao, PRODUTOS)){
        return 3;
    }

    //se for igual a COP;
    if(!strcmp(operacao, BUSCAPRODUTOS)){
        return 4;
    }

    //se for igual a COL;
    if(!strcmp(operacao, BUSCALOJAS)){
        return 5;
    }

    //se for igual a COI;
    if(!strcmp(operacao, BUSCAINGREDIENTES)){
        return 6;
    }

    //se for igual a APS
    if(!strcmp(operacao, ADICIONARSACOLA)){
        return 7;
    }

    //se for igual a RPS;
    if(!strcmp(operacao, REMOVERSACOLA)){
        return 8;
    }

    //se for igual a ECS
    if(!strcmp(operacao, EFETUARCOMPRA)){
        return 9;
    }

    //se for igual a LSC
    if(!strcmp(operacao, LIMPARSACOLA)){
        return 10;
    }

    //se for igual a BAP
    if(!strcmp(operacao, AVALIACOES)){
        return 11;
    }

    //se for igual a OUT;
    if(!strcmp(operacao, SAIDA)){
        return 0;
    }  

    //default;
    //return 0;
}

int switchAtores(){
    char opcao[TAM_OPCOES];
    scanf(" %11s\n", opcao);

    //se for igual a loja;
    if(!strcmp(opcao, LOJA)){
        return 1;
    }

    //se for igual a cliente;
    if(!strcmp(opcao, CLIENTE)){
        return 2;
    }

    //se for igual a fornecedor;
    if(!strcmp(opcao, FORNECEDOR)){
        return 3;
    }

    //default
    return 0;
}

tUfoodES *inicializaUfood(){
    tUfoodES *ufood = (tUfoodES*)malloc(sizeof(tUfoodES));

    ufood->lojas = NULL;
    ufood->clientes = NULL;
    ufood->fornecedores = NULL;

    ufood->qtdLojas = 0;
    ufood->qtdClientes = 0;
    ufood->qtdFornecedores = 0;

    return ufood;
}

tUfoodES *rodaUfood(tUfoodES *ufood){
    while(true){
        int operacao = switchOperacao();

        //cadastro de atores (CAT);
        if(operacao == 1){
            int atores = switchAtores();

            //cadastro de loja;
            if(atores == 1){
                cadastroLoja(ufood);
            }

            //cadastro de cliente;
            if(atores == 2){
                cadastroCliente(ufood);
            }

            //cadastro de fornecedor;
            if(atores == 3){
                cadastroFornecedor(ufood);
            }
        }

        //cadastro de ingredientes (CAI)
        if(operacao == 2){
            cadastroIngrediente(ufood);
        }

        //cadastro de produtos (CAP)
        if(operacao == 3){
            cadastroProduto(ufood);
        }

        //busca de produtos (COP)
        if(operacao == 4){
            buscarProdutos(ufood);
        }

        //busca de lojas (COI)
        if(operacao == 5){
            buscarLojas(ufood);
        }

        //busca de ingredientes (COI)
        if(operacao == 6){
            buscarIngredientes(ufood);
        }

        //adicionar produtos a sacola de compras (APS)
        if(operacao == 7){
            adicionarProdutoSacola(ufood);
        }

        //remover produtos da sacola de compras (RPS)
        if(operacao == 8){
            removerProdutoSacola(ufood);
        }

        //efetuar compras da sacola (ECS)
        if(operacao == 9){
            efetuarCompraCliente(ufood);
        }

        //limpar sacola de compras (LSC)
        if(operacao == 10){
            limparProdutosSacola(ufood);
        }

        //busca de avaliações (BAP)
        if(operacao == 11){
            buscarAvaliacoes(ufood);
        }

        //saída do programa (OUT);
        if(!operacao){
            break;
        }
    }

    return ufood;
}

void cadastroLoja(tUfoodES *ufood){
    while(true){
        tLoja* loja = criaLoja();

        if(loja != NULL){
            adicionaLojaUfood(ufood, loja);
            break;
        }
    }
}

int existeLojaUfood(tUfoodES *ufood, tLoja *loja){
    for(int i = 0; i < ufood->qtdLojas; i++){
        if(!comparaLoja(ufood->lojas[i], loja)){
            return 1;
        }
    }

    return 0;
}

void adicionaLojaUfood(tUfoodES *ufood, tLoja *loja){
    //se não existe, adiciona;
    if(!existeLojaUfood(ufood, loja)){
        ufood->qtdLojas++;
        ufood->lojas = (tLoja**)realloc(ufood->lojas, sizeof(tLoja*) * (ufood->qtdLojas));
        ufood->lojas[ufood->qtdLojas - 1] = loja;

        printf("LOJA CADASTRADA COM SUCESSO!\n");
    }else{
        printf("CNPJ JA EXISTENTE! OPERACAO NAO PERMITIDA!\n");
        liberaLoja(loja);
    }
}

void printaLojas(tUfoodES *ufood){
    for(int i = 0; i < ufood->qtdLojas; i++){
        printaLoja(ufood->lojas[i]);
        printf("\n");
    }
}

void cadastroCliente(tUfoodES *ufood){
    while(true){
        tCliente *cliente = criaCliente();

        if(cliente != NULL){
            adicionaClienteUfood(ufood, cliente);
            break;
        }
    }
}

int existeClienteUfood(tUfoodES *ufood, tCliente *cliente){
    for(int i = 0; i < ufood->qtdClientes; i++){
        if(!comparaCliente(cliente, ufood->clientes[i])){
            return 1;
        }
    }

    return 0;
}

void adicionaClienteUfood(tUfoodES *ufood, tCliente *cliente){
    //se não existe, adiciona;
    if(!existeClienteUfood(ufood, cliente)){
        ufood->qtdClientes++;
        ufood->clientes = (tCliente**)realloc(ufood->clientes, sizeof(tCliente*) * (ufood->qtdClientes));
        ufood->clientes[ufood->qtdClientes - 1] = cliente;

        printf("CLIENTE CADASTRADO COM SUCESSO!\n");
    }else{
        printf("CPF JA EXISTENTE! OPERACAO NAO PERMITIDA!\n");
        liberaCliente(cliente);
    }
}

void printaClientes(tUfoodES *ufood){
    for(int i = 0; i < ufood->qtdClientes; i++){
        printaCliente(ufood->clientes[i]);
    }
}

void cadastroFornecedor(tUfoodES *ufood){
    while(true){
        tFornecedor *fornecedor = criaFornecedor();

        if(fornecedor != NULL){
            adicionaFornecedorUfood(ufood, fornecedor);
            break;
        }
    }
}

int existeFornecedorUfood(tUfoodES *ufood, tFornecedor *fornecedor){
    for(int i = 0; i < ufood->qtdFornecedores; i++){
        if(!comparaFornecedor(fornecedor, ufood->fornecedores[i])){
            return 1;
        }
    }

    return 0;
}

void adicionaFornecedorUfood(tUfoodES *ufood, tFornecedor *fornecedor){
    //se não existe, adiciona;
    if(!existeFornecedorUfood(ufood, fornecedor)){
        ufood->qtdFornecedores++;
        ufood->fornecedores = (tFornecedor**)realloc(ufood->fornecedores, sizeof(tFornecedor*) * (ufood->qtdFornecedores));
        ufood->fornecedores[ufood->qtdFornecedores - 1] = fornecedor;

        printf("FORNECEDOR CADASTRADO COM SUCESSO!\n");
    }else{
        printf("CNPJ JA EXISTENTE! OPERACAO NAO PERMITIDA!\n");
        liberaFornecedor(fornecedor);
    }
}

void printaFornecedores(tUfoodES *ufood){
    for(int i = 0; i < ufood->qtdFornecedores; i++){
        printaFornecedor(ufood->fornecedores[i]);
    }
}

void cadastroIngrediente(tUfoodES *ufood){
    char cnpj[TAM_CNPJ];
    scanf("  %18s\n", cnpj);

    tFornecedor *fornecedor = buscaFornecedorCNPJ(ufood, cnpj);

    tIngrediente *ingrediente;

    if(fornecedor != NULL){
        //loop para garantir que vai ler corretamente;
        while(true){
            ingrediente = criaIngrediente();

            if(ingrediente != NULL){
                break;
            }
            
            printf("ATRIBUTO(S) FALTANTE(S), FAVOR INICIAR O CADASTRO NOVAMENTE.\n");
        }

        adicionaIngredienteFornecedor(fornecedor, ingrediente);
    }else{
        printf("FORNECEDOR SEM CADASTRO!\n");

        //loop para ler o resto das linhas;
        while(true){
            ingrediente = criaIngrediente();

            if(ingrediente != NULL){
                break;
            }
        }

        liberaIngrediente(ingrediente);
    }
}

tFornecedor *buscaFornecedorCNPJ(tUfoodES *ufood, char* cnpj){
    for(int i = 0; i < ufood->qtdFornecedores; i++){
        if(!strcmp(cnpj, getCnpjFornecedor(ufood->fornecedores[i]))){
            return ufood->fornecedores[i];
        }
    }

    return NULL;
}

tLoja *buscaLojaCNPJ(tUfoodES *ufood, char *cnpj){
    for(int i = 0; i < ufood->qtdLojas; i++){
        if(!strcmp(cnpj, getCnpjLoja(ufood->lojas[i]))){
            return ufood->lojas[i];
        }
    }

    return NULL;
}

tProduto *leituraIndustrializado(){
    tIndustrializado *industrializado = criaIndustrializado();

    tProduto *produto = criaProduto(industrializado, imprimeFisicoIndustrializado, imprimeDigitalIndustrializado, liberaIndustrializado, getValorIndustrializado, getCodIndustrializado, getNomeIndustrializado, getTipoIndustrializado, getDescIndustrializado, getDisponibilidadeIndustrializado, alteraDisponibilidadeIndustrializado, printaIndustrializado);

    return produto;
}

tProduto *leituraPrato(tUfoodES *ufood){
    tPrato *prato;

    //garantindo a leitura dos atributos do prato
    while(true){
        prato = criaPrato(ufood->fornecedores, &ufood->qtdFornecedores);

        if(prato != NULL){
            leIngredientes(prato);
            break;
        }
    }

    //se não existir, libera produto e retorna NULL;
    if(!existeIngredientesUfood(ufood, getIngredientesPrato(prato), getQtdIngredientesPrato(prato))){
        liberaPrato(prato);
        return NULL;
    }else{
        return criaProduto(prato, imprimeFisicoPrato, imprimeDigitalPrato, liberaPrato, getValorPrato, getCodPrato, getNomePrato, getTipoPrato, getDescPrato, getDisponibilidadePrato, alteraDisponibilidadePrato, printaPrato);
    }
}

tProduto *leituraProduto(tUfoodES *ufood, char tipoProduto){
    tProduto *produto;
    
    if(tipoProduto == INDUSTRIALIZADO){
        produto = leituraIndustrializado();
    }

    if(tipoProduto == PRATO){
        produto = leituraPrato(ufood);
    }

    return produto;
}

int existeIngredientesUfood(tUfoodES *ufood, char **ingredientes, int qtdIngredientes){
    //percorre cada ingrediente;
    for(int i = 0; i < qtdIngredientes; i++){
        int existe = 0;
        
        //percorre cada fornecedor;
        for(int j = 0; j < ufood->qtdFornecedores; j++){
            if(existeIngredienteNome(ufood->fornecedores[j], ingredientes[i])){
                existe = 1;
            }
        }

        //se não existir, printa a mensagem;
        if(!existe){
            printf("INGREDIENTE %s INDISPONIVEL! CADASTRO DE PRODUTO CANCELADO!\n", ingredientes[i]);
            return 0;
        }
    }

    //se passou por tudo, significa que existe;
    return 1;
}

void cadastroProduto(tUfoodES *ufood){    
    char cnpj[TAM_CNPJ];
    char tipoProduto;

    scanf("%18s %c\n", cnpj, &tipoProduto);

    tLoja *loja = buscaLojaCNPJ(ufood, cnpj);

    tProduto *produto;

    if(loja != NULL){
        produto = leituraProduto(ufood, tipoProduto);

        if(produto != NULL){
            adicionaProdutoLoja(loja, produto);
        }
            
    }else{
        produto = leituraProduto(ufood, tipoProduto);
        liberaProduto(produto);
        printf("LOJA SEM CADASTRO!\n");
    }
}

void adicionarProdutoSacola(tUfoodES *ufood){
    char cpf[TAM_CPF];
    char codigo[TAM_CODIGO];
    int quantidade;

    scanf(" %s %s %d\n", cpf, codigo, &quantidade);

    tCliente *cliente = buscaClienteCPF(ufood, cpf);

    if(cliente != NULL){
        tProduto *produto = buscaProdutoCodigo(ufood, codigo);

        //se o cliente e o produto existem, cria item e adiciona item ao cliente;
        if(produto != NULL){
            //cria um item com o produto;
            tItem *item = criaItem(produto, quantidade);
            
            adicionaItemCliente(cliente, item);
        }else{
            printf("O PRODUTO NAO ESTA CADASTRADO EM NENHUMA LOJA!\n");
        }
    }else{
        printf("CLIENTE SEM CADASTRO!\n");
    }
}

tCliente *buscaClienteCPF(tUfoodES *ufood, char *cpf){
    for(int i = 0; i < ufood->qtdClientes; i++){
        //se o cpf for igual ao cpf passado, retorna o cliente em questão;
        if(!strcmp(cpf, getCpfCliente(ufood->clientes[i]))){
            return ufood->clientes[i];
        }
    }

    //se não encontrou, retorna nada;
    return NULL;
}

tProduto *buscaProdutoCodigo(tUfoodES *ufood, char *codigo){
    tProduto *produto;
    
    for(int i = 0; i < ufood->qtdLojas; i++){
        produto = existeProdutoLoja(ufood->lojas[i], codigo);

        //se for diferente de NULL, encontrou e retorna produto;
        if(produto != NULL){
            return produto;
        }
    }

    //se não tiver achado, retorna nada;
    return NULL;
}

void removerProdutoSacola(tUfoodES *ufood){
    char cpf[TAM_CPF];
    char codigo[TAM_CODIGO];
    int quantidade;

    scanf(" %s %s %d\n", cpf, codigo, &quantidade);

    tCliente *cliente = buscaClienteCPF(ufood, cpf);

    if(cliente != NULL){
        tProduto *produto = buscaProdutoCodigo(ufood, codigo);

        //se o cliente e o produto existem, cria item e remove item do cliente;
        if(produto != NULL){
            //cria um item com o produto;
            tItem *item = criaItem(produto, quantidade);
            
            removeItemCliente(cliente, item);
        }else{
            printf("O PRODUTO NAO ESTA CADASTRADO EM NENHUMA LOJA!\n");
        }
    }else{
        printf("CLIENTE SEM CADASTRO!\n");
    }
}

void limparProdutosSacola(tUfoodES *ufood){
    char cpf[TAM_CPF];
    scanf(" %12s\n", cpf);

    tCliente *cliente = buscaClienteCPF(ufood, cpf);

    if(cliente != NULL){
        limpaSacolaCliente(cliente);
    }else{
        printf("CLIENTE SEM CADASTRO!\n");
    }
}

void efetuarCompraCliente(tUfoodES *ufood){
    char cpf[TAM_CPF];
    scanf(" %12s\n", cpf);

    tCliente *cliente = buscaClienteCPF(ufood, cpf);

    if(cliente != NULL){
        //se retornar 1, encerra o programa;
        if(efetuaCompraCliente(cliente)){
            liberaUfood(ufood);
            exit(1);
        }
    }else{
        printf("CLIENTE SEM CADASTRO!\n");
    }
}

void buscarAvaliacoes(tUfoodES *ufood){
    char codigo[TAM_CODIGO];
    scanf(" %14s\n", codigo);

    tProduto *produto = buscaProdutoCodigo(ufood, codigo);

    if(produto != NULL){
        printaAvaliacoesProduto(produto);
    }else{
        printf("PRODUTO NAO EXISTENTE! TENTE NOVAMENTE!\n");
    }
}

int menuBuscarProdutos(){
    char operacao[TAM_OPCOES];
    scanf(" %12s ", operacao);

    //se for igual a NOME;
    if(!strcmp(operacao, "NOME")){
        return 1;
    }

    //se for igual a TIPO
    if(!strcmp(operacao, "TIPO")){
        return 2;
    }

    //se for igual a TUDO
    if(!strcmp(operacao, "TUDO")){
        return 3;
    }
}

void buscarProdutos(tUfoodES *ufood){
    int opcao = menuBuscarProdutos();

    //busca pelo nome;
    if(opcao == 1){
        char nome[TAM_NOME];
        scanf("%99[^\n]\n", nome);

        buscaProdutoNome(ufood, nome);
    }

    //busca pelo tipo
    if(opcao == 2){
        char tipo;
        scanf("%c\n", &tipo);

        buscaProdutoTipo(ufood, tipo);
    }

    //busca tudo;
    if(opcao == 3){
        buscaProdutoTudo(ufood);
    }
}

void buscaProdutoNome(tUfoodES *ufood, char *nome){
    int quantidadeProdutos = 0;
    
    for(int i = 0; i < ufood->qtdLojas; i++){
        //verifica se a loja apresenta um produto com esse nome; se o produto existir;
        if(existeProdutoNomeLoja(ufood->lojas[i], nome)){
            //printa todos os produtos da loja com esse nome e incrementa o número de produtos printados;
            printaProdutosNomeLoja(ufood->lojas[i], nome, &quantidadeProdutos);
        }
    }
}

void buscaProdutoTipo(tUfoodES *ufood, char tipo){
    int quantidadeProdutos = 0;
    
    for(int i = 0; i < ufood->qtdLojas; i++){
        //verifica se a loja apresenta um produto com esse tipo; se o produto existir;
        if(existeProdutoTipoLoja(ufood->lojas[i], tipo)){
            //printa todos os produtos da loja com esse nome e incrementa o número de produtos printados;
            printaProdutosTipoLoja(ufood->lojas[i], tipo, &quantidadeProdutos);
        }
    }
}

void buscaProdutoTudo(tUfoodES *ufood){
    int quantidadeProdutos = 0;
    
    for(int i = 0; i < ufood->qtdLojas; i++){
        //verifica se a loja apresenta produtos para imprimir
        if(existeProdutosLoja(ufood->lojas[i])){
            //printa todos os produtos da loja;
            printaProdutosLoja(ufood->lojas[i], &quantidadeProdutos);
        }
    }
}

int menuBuscarIngredientes(){
    char operacao[17];
    scanf(" %16s ", operacao);

    //se for igual a ID_FORNECEDOR;
    if(!strcmp(operacao, "ID_FORNECEDOR")){
        return 1;
    }   

    //se for igual a NOME_FORNECEDOR
    if(!strcmp(operacao, "NOME_FORNECEDOR")){
        return 2;
    }

    //se for igual a NOME_INGREDIENTE;
    if(!strcmp(operacao, "NOME_INGREDIENTE")){
        return 3;
    }

    //se for igual a TUDO;
    if(!strcmp(operacao, "TUDO")){
        return 4;
    }
}

void buscarIngredientes(tUfoodES *ufood){
    int opcao = menuBuscarIngredientes();

    if(opcao == 1){
        buscaIngredienteIdFornecedor(ufood);
    }

    if(opcao == 2){
        buscaIngredienteNomeFornecedor(ufood);
    }

    if(opcao == 3){
        buscaIngredienteNome(ufood);
    }

    if(opcao == 4){
        printaFornecedores(ufood);
    }
}

void buscaIngredienteIdFornecedor(tUfoodES *ufood){
    char cnpj[TAM_CNPJ];
    scanf("%18s\n", cnpj);
    
    tFornecedor *fornecedor = buscaFornecedorCNPJ(ufood, cnpj);

    if(fornecedor != NULL){
        printaFornecedor(fornecedor);
    }
}

void buscaIngredienteNomeFornecedor(tUfoodES *ufood){
    char nome[TAM_NOME];
    scanf("%99[^\n]\n", nome);

    //printa todos fornecedores com esse nome;
    for(int i = 0; i < ufood->qtdFornecedores; i++){
        if(strstr(getNomeFornecedor(ufood->fornecedores[i]), nome) != NULL){
            printaFornecedor(ufood->fornecedores[i]);
        }
    }
}

void buscaIngredienteNome(tUfoodES *ufood){
    char nomeIngrediente[TAM_NOME];
    scanf("%99[^\n]\n", nomeIngrediente);

    int quantidadePrintados = 0;

    for(int i = 0; i < ufood->qtdFornecedores; i++){
        //se existir ingrediente com esse nome ou substring, printa fornecedor e os ingredientes com esse nome
        if(existeIngredienteComNome(ufood->fornecedores[i], nomeIngrediente)){
            printaFornecedorNomeIngrediente(ufood->fornecedores[i], nomeIngrediente, &quantidadePrintados);
        }
    }
}

int menuBuscarLojas(){
    char operacao[17];
    scanf(" %16s ", operacao);

    if(!strcmp(operacao, "NOME_LOJA")){
        return 1;
    }

    if(!strcmp(operacao, "NOME_PRODUTO")){
        return 2;
    }

    if(!strcmp(operacao, "TUDO")){
        return 3;
    }

    //default;
    return 0;
}

void buscarLojas(tUfoodES *ufood){
    int opcao = menuBuscarLojas();

    if(opcao == 1){
        buscaLojasNome(ufood);
    }

    if(opcao == 2){
        buscaLojasComProduto(ufood);
    }

    if(opcao == 3){
        buscaTodasLojas(ufood);
    }

    if(opcao == 0){
        //pega o buffer;
        char linha[500];
        fgets(linha, sizeof(linha), stdin);
    }
}

void buscaLojasNome(tUfoodES *ufood){
    char nome[TAM_NOME];
    scanf("%99[^\n]\n", nome);

    for(int i = 0; i < ufood->qtdLojas; i++){
        if(strstr(getNomeLoja(ufood->lojas[i]), nome) != NULL){
            printaLoja(ufood->lojas[i]);
        }
    }
}

void buscaLojasComProduto(tUfoodES *ufood){
    char nome[TAM_NOME];
    scanf("%99[^\n]\n", nome);

    int quantidadePrintados = 0;

    for(int i = 0; i < ufood->qtdLojas; i++){
        if(existeProdutoNomeLoja(ufood->lojas[i], nome)){
            quantidadePrintados++;

            printf("%d - %s, %s, %s, %s\n", quantidadePrintados, getNomeLoja(ufood->lojas[i]), getCnpjLoja(ufood->lojas[i]), getTelefoneLoja(ufood->lojas[i]), getEnderecoLoja(ufood->lojas[i]));
        }
    }
}

void buscaTodasLojas(tUfoodES *ufood){
    for(int i = 0; i < ufood->qtdLojas; i++){
        printf("%d - %s, %s, %s, %s\n", i + 1, getNomeLoja(ufood->lojas[i]), getCnpjLoja(ufood->lojas[i]), getTelefoneLoja(ufood->lojas[i]), getEnderecoLoja(ufood->lojas[i]));
    }
}

void liberaUfood(tUfoodES *ufood){
    //libera lojas e seu ponteiro de ponteiros;
    if(ufood->lojas != NULL){
        for(int i = 0; i < ufood->qtdLojas; i++){
            liberaLoja(ufood->lojas[i]);
        }

        free(ufood->lojas);
    }

    //libera clientes e seu ponteiro de ponteiros;
    if(ufood->clientes != NULL){
        for(int i = 0; i < ufood->qtdClientes; i++){
            liberaCliente(ufood->clientes[i]);
        }

        free(ufood->clientes);
    }

    //libera fornecedores e seu ponteiro de ponteiros;
    if(ufood->fornecedores != NULL){
        for(int i = 0; i < ufood->qtdFornecedores; i++){
            liberaFornecedor(ufood->fornecedores[i]);
        }

        free(ufood->fornecedores);
    }

    free(ufood);
}