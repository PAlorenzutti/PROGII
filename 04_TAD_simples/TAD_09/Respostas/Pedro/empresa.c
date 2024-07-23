#include "empresa.h"

#include <stdio.h>

tEmpresa criaEmpresa(int id){
    tEmpresa empresa;

    empresa.id = id;
    empresa.qtdFuncionarios = 0;

    return empresa;
}

tEmpresa leEmpresa(){
    int id, qtdFuncionarios;
    scanf("%d %d\n", &id, &qtdFuncionarios);

    tEmpresa empresa = criaEmpresa(id);

    //lê os funcionários
    for(int i = 0; i < qtdFuncionarios; i++){
        empresa = contrataFuncionarioEmpresa(empresa, leFuncionario());
    }

    return empresa;
}

tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario){
    //sentinela
    int existe = 0;
    
    //procura entre os funcionários
    for(int i = 0; i < empresa.qtdFuncionarios; i++){
        if(getIdFuncionario(funcionario) == getIdFuncionario(empresa.funcionarios[i])){
            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, getIdFuncionario(funcionario));
            existe = 1;
            return empresa;
        }
    }

    //se não existir (existe == 0), então contrata
    if(!existe){
        empresa.funcionarios[empresa.qtdFuncionarios] = funcionario;
        empresa.qtdFuncionarios++;
    }

    return empresa;
}

void imprimeEmpresa(tEmpresa empresa){
    printf("Empresa %d:\n", empresa.id);
    
    //imprime todos os funcionários;
    for(int i = 0; i < empresa.qtdFuncionarios; i++){
        imprimeFuncionario(empresa.funcionarios[i]);
    }
}