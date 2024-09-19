#include <stdio.h>

#include "roteiro.h"
#include "midia.h"
#include "livro.h"
#include "musica.h"
#include "pintura.h"

void cadastroLivro(Roteiro *r){
    char titulo[MAXTAM_STRINGS];
    char autor[MAXTAM_STRINGS];
    char genero[MAXTAM_STRINGS];
    char editora[MAXTAM_STRINGS];
    int ano;

    scanf("%s %s %s %s %d\n", titulo, autor, genero, editora, &ano);

    Livro *l = livro_construct(titulo, autor, genero, editora, ano);

    roteiro_inserir_midia(r, l, livro_print, livro_destroy);
}

void cadastroMusica(Roteiro *r){
    char titulo[MAXTAM_STRINGS];
    char artista[MAXTAM_STRINGS];
    int nParticipantes;
    char participantes[MAXTAM_PARTICIPANTES][MAXTAM_STRINGS];
    char album[MAXTAM_STRINGS];
    char genero[MAXTAM_STRINGS];

    scanf("%s %s %d ", titulo, artista, &nParticipantes);

    if(nParticipantes){
        for(int i = 0; i < nParticipantes; i++){
            scanf("%s ", participantes[i]);
        }
    }

    scanf("%s %s\n", album, genero);

    Musica *m = musica_construct(titulo, artista, nParticipantes, participantes, album, genero);

    roteiro_inserir_midia(r, m, musica_print, musica_destroy);
}

void cadastroPintura(Roteiro *r){
    char titulo[MAXTAM_STRINGS];
    char artista[MAXTAM_STRINGS];
    char movimento[MAXTAM_STRINGS];
    char material[MAXTAM_STRINGS];
    int ano;

    scanf("%s %s %s %s %d\n", titulo, artista, movimento, material, &ano);

    Pintura *p = pintura_construct(titulo, artista, movimento, material, ano);

    roteiro_inserir_midia(r, p, pintura_print, pintura_destroy);    
}

int main(){
    Roteiro *r = roteiro_construct();

    int qtdMidias;
    scanf("%d\n", &qtdMidias);

    for(int i = 0; i < qtdMidias; i++){
        char tipo;
        scanf("%c ", &tipo);

        if(tipo == 'L'){
            cadastroLivro(r);
        }else if(tipo == 'M'){
            cadastroMusica(r);
        }else if(tipo == 'P'){
            cadastroPintura(r);
        }else{
            char linha[500];
            fgets(linha, sizeof(linha), stdin);

            printf("Nao e uma midia valida\n");
        }
    }

    roteiro_imprimir_midias(r);

    roteiro_destroy(r);

    return 0;
}