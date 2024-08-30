#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int m, n;
    int tipo;
    int **v;
}tImagem;

tImagem* leImagem(){
    tImagem *img = (tImagem*)malloc(sizeof(tImagem));

    //abre o arquivo de imagem;
    FILE *arquivo = fopen("img-1-int.bin", "rb");

    //lê o número de linhas;
    fread(&img->m, sizeof(int), 1, arquivo);

    //lê o número de colunas;
    fread(&img->n, sizeof(int), 1, arquivo);

    //lê o tipo da imagem;
    fread(&img->tipo, sizeof(int), 1, arquivo);

    //aloca o vetor da imagem
    img->v = (int**)malloc(sizeof(int*) * img->m);

    for(int i = 0; i < img->m; i++){
        img->v[i] = (int*)malloc(sizeof(int) * img->n);
    }

    //lê a imagem e coloca no vetor da imagem;
    for(int i = 0; i < img->m; i++){
        for(int j = 0; j < img->n; j++){
            fread(&img->v[i][j], sizeof(int), 1, arquivo);
        }
    }

    return img;
}

void maiorMenorPixel(tImagem *img){
    //inicializa o menor com o primeiro elemento da imagem
    int maiorPixel = img->v[0][0];

    //inicializa o menor com o primeiro elemento da imagem
    int menorPixel = img->v[0][0];

    //soma;
    int soma = 0;
    
    for(int i = 0; i < img->m; i++){
        for(int j = 0; j < img->n; j++){
            if(img->v[i][j] > maiorPixel){
                maiorPixel = img->v[i][j];
            }
            
            if(img->v[i][j] < menorPixel){
                menorPixel = img->v[i][j];
            }

            soma += img->v[i][j];
        }
    }

    //printa o pixel médio
    printf("Pixel Medio: %d\n", soma/(img->m * img->n));

    //printa o menor pixel;
    printf("Menor Pixel: %d\n", menorPixel);

    //printa o maior pixel;
    printf("Maior Pixel: %d", maiorPixel);
}

void printaImagem(tImagem *img){
    //printa cada elemento
    for(int i = 0; i < img->m; i++){
        for(int j = 0; j < img->n; j++){
            if(j == img->n - 1){
                printf("%d", img->v[i][j]);
            }else{
                printf("%d; ", img->v[i][j]);
            }
        }

        printf("\n");
    }
}

void liberaImagem(tImagem *img){
    for(int i = 0; i < img->m; i++){
        free(img->v[i]);
    }

    free(img->v);
    free(img);
}

int main(){
    tImagem *img = leImagem();

    //printaImagem(img);

    //imprime pixel medio, menor e maior pixel;
    maiorMenorPixel(img);

    liberaImagem(img);

    return 0;
}