#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    int linhas;

    int colunas;

    int elemento[100][100];

} matriz;

typedef struct {

    int entradaLinha;
    int entradaColuna;
    int saidaLinha;
    int saidaColuna;

    bool visitado[100][100];

    int linhaAtual;
    int colunaAtual;

} salvaCaminho;

typedef struct 
{
    char pref[4];
}preferencia;

matriz leMatriz(){

    matriz matriz;

    scanf("%d%d", &matriz.linhas, &matriz.colunas);

    for (int i = 0; i < matriz.linhas; i++){

        for (int j=0; j<matriz.colunas; j++){

            scanf("%d", &matriz.elemento[i][j]);
        }
    }

    return matriz;
}

salvaCaminho defineEntrada(){
    salvaCaminho s;

    scanf("%d%d", &s.entradaLinha, &s.entradaColuna);
    scanf("%d%d", &s.saidaLinha, &s.saidaColuna);
    s.entradaLinha = s.entradaLinha - 1;
    s.entradaColuna = s.entradaColuna - 1;
    s.saidaLinha = s.saidaLinha - 1;
    s.saidaColuna = s.saidaColuna - 1;
    return s; 
}

preferencia definePreferencia(){

    preferencia p;

    scanf("%s", p.pref);

    return p;
}

void imprimeMatriz(matriz m, preferencia p, salvaCaminho s){

    printf("A matriz tem dimensões:%dx%d\n", m.linhas, m.colunas);

    for (int i = 0; i < m.linhas; i++){

        for (int j=0; j<m.colunas; j++){

            printf("%d ", m.elemento[i][j]);
        }
        printf("\n");
    }

    printf("\nDe inicio em:[%d][%d]\n", s.entradaLinha + 1, s.entradaColuna + 1);
    printf("Saida em: [%d][%d]\n", s.saidaLinha + 1, s.saidaColuna + 1);

    printf("De preferencia em:%s\n", p.pref);
}

void movimentaJogador(matriz m, preferencia p, salvaCaminho s){
    int posicaoAtual = 0;
    int iteracao = 0;
    s.linhaAtual = s.entradaLinha;
    
    s.colunaAtual = s.entradaColuna;

    while(s.linhaAtual != s.saidaLinha || s.colunaAtual != s.saidaColuna){

        
        switch (p.pref[posicaoAtual])

        {
        case 'B':
             
            if (s.linhaAtual + 1 < m.linhas && m.elemento[s.linhaAtual + 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual + 1][s.colunaAtual] == false){
                printf("(%d,%d) ", s.linhaAtual + 1, s.colunaAtual + 1);
                s.visitado[s.linhaAtual][s.colunaAtual] = true; //Atualiza a posicao
                s.linhaAtual++;
                posicaoAtual--;
            }
        
        case 'D':
             
            if (s.colunaAtual + 1 < m.colunas && m.elemento[s.linhaAtual][s.colunaAtual + 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual + 1] == false){
                printf("(%d,%d) ", s.linhaAtual + 1, s.colunaAtual + 1);
                s.visitado[s.linhaAtual][s.colunaAtual] = true;
                //printf("%c", p.pref[posicaoAtual]);
                posicaoAtual--;
                //printf("%c", p.pref[posicaoAtual]);
                s.colunaAtual++;
            }
        case 'E':
            
            if(s.colunaAtual - 1 >= 0 && m.elemento[s.linhaAtual][s.colunaAtual - 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual - 1] == false){
                printf("(%d,%d) ", s.linhaAtual + 1, s.colunaAtual + 1);              
                s.visitado[s.linhaAtual][s.colunaAtual] = true;
                posicaoAtual--;             
                s.colunaAtual--;
            }
        case 'C':
            
            if (s.linhaAtual - 1 >= 0 && m.elemento[s.linhaAtual - 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual - 1][s.colunaAtual] == false){
                
                printf("(%d,%d) ", s.linhaAtual + 1, s.colunaAtual + 1);              
                s.visitado[s.linhaAtual][s.colunaAtual] = true;       
                s.linhaAtual--;
                posicaoAtual--;
            }
        default:
            if (posicaoAtual < 4){
                //printf("\n%c", p.pref[posicaoAtual]);
                posicaoAtual = posicaoAtual + 1;
                //printf("\n%c", p.pref[posicaoAtual]);
            }
            else{
                printf("EXCEDEU");
                exit(1);
            }
        }
    //iteracao++;
    }

    printf("(%d,%d)\n", s.linhaAtual + 1, s.colunaAtual + 1);
    printf("%c", p.pref[posicaoAtual]);
}
int main(){

    matriz novoMapa = leMatriz();
    salvaCaminho caminho = defineEntrada();
    preferencia pref = definePreferencia();
    //imprimeMatriz(novoMapa, pref, caminho);
    movimentaJogador(novoMapa, pref, caminho);
    //jogaJogo(novoMapa, posIniX, posIniY, posFiX, posFiY, pr1, pr2,  pr3, pr4);

    return 0;
}