#include <stdio.h>
#define MAX 1000

void zerarLista(int lista[]){
    for(int i = 0; i < MAX; i++){
        lista[i] = 0;
    }
}

int main(){
    int n;
    int livros[MAX], identificadores[MAX];
    int i, j;

    zerarLista(livros);
    zerarLista(identificadores);

    printf("Digite o numero de livros a serem contabilizados:\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &livros[i]);

        identificadores[livros[i] - 1] += 1;
    }

    for(i = 0, j = 0; i < MAX; i++){
        if(identificadores[i] == 1){
            printf("%d ", i + 1);
            j += 1;
        }
    }

    if(!j){
        printf("NENHUM");
    }else{
        printf("\b");
    }

    return 0;
}