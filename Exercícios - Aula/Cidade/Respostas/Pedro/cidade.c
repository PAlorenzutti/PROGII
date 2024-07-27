#include "cidade.h"

#include <stdio.h>
#include <stdbool.h>

tCidade criaCidade(){
    tCidade c;

    scanf("C %f %f", &c.X, &c.Y);

    c.qtdDefesas = 0;
    c.qtdMisseis = 0;
    c.efetividade = 0;

    //leitura das defesas e dos mísseis;
    while(true){
        char tipo;

        scanf("%c", &tipo);

        if(tipo == 'D'){
            c.defesas[c.qtdDefesas] = criaDefesa();
            c.qtdDefesas++;
        }

        if(tipo == 'M'){
            c.misseis[c.qtdMisseis] = criaMissil();
            c.qtdMisseis++;
        }

        if(tipo == 'F'){
            break;
        }
    }

    return c;
}

int verificaAtingiuCidade(tCidade c, tMissil m){
    //pega as coordenadas x e y de míssil;
    float x = getAbscMissil(m);
    float y = getOrdeMissil(m);
    
    //se o ponto estiver dentro da área da cidade (um retângulo)
    if( (x >= 0 && x <= c.X) && (y >= 0 && y <= c.Y) ){
        return 1;
    }else{
        return 0;
    }
}

tCidade atualizaCidade(tCidade c){
    float danoTotal = 0;
    for(int i = 0; i < c.qtdMisseis; i++){
        danoTotal += c.misseis[i].poderAtaque;
    }
    
    for(int i = 0; i < c.qtdMisseis; i++){
        //verifica antes se o míssil atingiu de fato a cidade
        if(verificaAtingiuCidade(c, c.misseis[i])){
            //percorre todas as defesas para ver qual ele acertou
            for(int j = 0; j < c.qtdDefesas; j++){
                //verifica se o míssil em questão atingiu a defesa em questão
                opCallback verifica;
                char tipo = getTipoDefesa(c.defesas[j]);

                if(tipo == 'C'){
                    verifica = verificaAreaCirculo;
                }

                if(tipo == 'Q'){
                    verifica = verificaAreaQuadrado;
                }
                
                
                if(verificaAtingiuDefesa(c.defesas[j], c.misseis[i], verifica)){
                    //verifica se a defesa ainda tem missil;
                    if( getQtdMissilDefesa(c.defesas[j]) > 0 ){
                        c.defesas[j] = atualizaDefesa(c.defesas[j]);
                        c.misseis[i] = atualizaMissil(c.misseis[i], getPoderDefesa(c.defesas[j]));
                    }else{
                        c.misseis[i] = atualizaMissil(c.misseis[i], 0);
                        //printf("Defesa não tem mais míssil\n");
                    }

                }
            }
        }else{
            //printf("Não atingiu a cidade\n");
        }
    }

    float danoCausado = 0;
    for(int i = 0; i < c.qtdMisseis; i++){
        danoCausado += c.misseis[i].poderAtaque;
    }

    c.efetividade = ( (danoTotal - danoCausado) / danoTotal ) * 100;

    return c;
}

void printaCidade(tCidade c){
    //printa cidade
    //printf("%.2f %.2f\n", c.X, c.Y);

    //printa defesas
    for(int i = 0; i < c.qtdDefesas; i++){
        printaDefesa(c.defesas[i]);
    }

    //printa mísseis
    for(int i = 0; i < c.qtdMisseis; i++){
        printaMissil(c.misseis[i]);
    }

    //printa efetividade
    printf("Efetividade: %.2f%%\n", c.efetividade);
}