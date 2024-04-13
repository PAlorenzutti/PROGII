#include <stdio.h>
#include <string.h>

#define MAX_FRANQUIAS 100
#define MAX_PARTIDAS 100
#define MAX_CONF_NOME 5
#define MAX_FRANQUIA_NOME 32

typedef struct{
    char nome[MAX_FRANQUIA_NOME];
    char conferencia[MAX_CONF_NOME];
    char sigla[4];
    int partidas;
    int vitorias;
    int vitoriasCasa;
    int vitoriasFora;
    int derrotas;
    float aproveitamento;
}tFranquia;

typedef struct{
    char franquiaVisitante[MAX_FRANQUIA_NOME];
    int pontosVisitante;
    char franquiaCasa[MAX_FRANQUIA_NOME];
    int pontosCasa;
}tPartida;

tFranquia lerFranquia(){
    tFranquia franquia;

    scanf("%s %s\n", franquia.nome, franquia.conferencia);

    if(!strcmp(franquia.conferencia, "OESTE")){
        strcpy(franquia.sigla, "[CO]");
    }

    if(!strcmp(franquia.conferencia, "LESTE")){
        strcpy(franquia.sigla, "[CL]");
    }

    franquia.partidas = 0;
    franquia.vitorias = 0;
    franquia.vitoriasCasa = 0;
    franquia.vitoriasFora = 0;
    franquia.derrotas = 0;
    franquia.aproveitamento = 0;

    return franquia;
}

void somaVitoriasFranquias(tFranquia franquias[], int qtdFranquias){
    for(int i = 0; i < qtdFranquias; i++){
        franquias[i].vitorias = franquias[i].vitoriasCasa + franquias[i].vitoriasFora;
    }
}

//Calcula aproveitamento de cada franquia   
void calculaAproveitamentoFranquias(tFranquia franquias[], int qtdFranquias){
    for(int i = 0; i < qtdFranquias; i++){
        if(franquias[i].partidas > 0){
            franquias[i].aproveitamento = franquias[i].vitorias / franquias[i].partidas;
        }else{
            franquias[i].aproveitamento = 0;
        }
    }
}

int pesquisarFranquia(tFranquia franquias[], int qtdFranquias, char nomeFranquia[]){
    //Descobrir a posição da franquia no vetor de franquias.
    for(int i = 0; i < qtdFranquias; i++){
        if(!strcmp(franquias[i].nome, nomeFranquia)){
            return i;
        }
    }
}

int somaVitoriasConferencia(tFranquia franquias[], int qtdFranquias, char conferencia[]){
    int vitorias = 0;
    
    for(int i = 0; i < qtdFranquias; i++){
        if(!strcmp(franquias[i].conferencia, conferencia)){
            vitorias += franquias[i].vitorias;
        }
    }

    return vitorias;
}

int somaDerrotasConferencia(tFranquia franquias[], int qtdFranquias, char conferencia[]){
    int derrotas = 0;
    
    for(int i = 0; i < qtdFranquias; i++){
        if(!strcmp(franquias[i].conferencia, conferencia)){
            derrotas += franquias[i].derrotas;
        }
    }

    return derrotas;
}

void printFranquias(tFranquia franquias[], int qtdFranquias){
    for(int i = 0; i < qtdFranquias; i++){
        printf("%s %s %d %d %.2f %d %d\n", franquias[i].nome, franquias[i].sigla, 
        franquias[i].vitorias, franquias[i].derrotas, franquias[i].aproveitamento,
        franquias[i].vitoriasCasa, franquias[i].vitoriasFora);
    }
}

void printAproveitamentoConferencias(tFranquia franquias[], int qtdFranquias){
    int vitoriasLeste = somaVitoriasConferencia(franquias, qtdFranquias, "LESTE");
    int vitoriasOeste = somaVitoriasConferencia(franquias, qtdFranquias, "OESTE");

    int derrotasLeste = somaDerrotasConferencia(franquias, qtdFranquias, "LESTE");
    int derrotasOeste = somaDerrotasConferencia(franquias, qtdFranquias, "OESTE");
    
    float aproveitamentoLeste = vitoriasLeste / (vitoriasLeste + derrotasLeste);
    float aproveitamentoOeste = vitoriasOeste / (vitoriasOeste + derrotasOeste);

    printf("LESTE: %d %d %.2f\n", vitoriasLeste, derrotasLeste, aproveitamentoLeste);
    printf("OESTE: %d %d %.2f\n", vitoriasOeste, derrotasOeste, aproveitamentoOeste);
}


void associarPontosFranquias(tFranquia franquias[], int qtdFranquias, char franquiaVisitante[], int pontosVisitante, char franquiaCasa[], int pontosCasa){
    //Pegando o index de cada time;
    int indexCasa = pesquisarFranquia(franquias, qtdFranquias, franquiaCasa);
    int indexVisitante = pesquisarFranquia(franquias, qtdFranquias, franquiaVisitante);

    //Atualizando de acordo com o resultado
    if(pontosVisitante > pontosCasa){
        franquias[indexVisitante].vitoriasFora++;
        franquias[indexVisitante].partidas++;

        franquias[indexCasa].partidas++;
        franquias[indexCasa].derrotas++;
    }

    if(pontosCasa > pontosVisitante){
        franquias[indexVisitante].partidas++;
        franquias[indexCasa].vitoriasCasa++;

        franquias[indexVisitante].partidas++;
        franquias[indexVisitante].derrotas++;
    }
}

tPartida lerPartida(){
    tPartida p;

    scanf("%s @ %s %d %d\n", p.franquiaVisitante, p.franquiaCasa, &p.pontosVisitante, &p.pontosCasa);

    return p;
}

void obtemDadosPartida(tPartida partida, char franquiaVisitante[], int *pontosVisitante, char franquiaCasa[], int *pontosCasa){
    *pontosVisitante = partida.pontosVisitante;
    *pontosCasa = partida.pontosCasa;
    strcpy(franquiaVisitante, partida.franquiaVisitante);
    strcpy(franquiaCasa, partida.franquiaCasa);
}

int main(){
    tFranquia franquias[MAX_FRANQUIAS];
    int qtdFranquias = 0;

    tPartida partidas[MAX_PARTIDAS];
    int qtdPartidas = 0;

    while(1){
        char opcao;
        scanf("%c\n", &opcao);

        if(opcao == 'F'){
            if(qtdFranquias >= MAX_FRANQUIAS){
                printf("Excedido numero maximo de franquias permitidas.");
                break;
            }else{
                franquias[qtdFranquias] = lerFranquia();
                qtdFranquias++;
            }
        }

        if(opcao == 'P'){
            if(qtdPartidas >= MAX_PARTIDAS){
                printf("Excedido numero maximo de partidas permitidas");
                break;
            }else{
                //criando espelhos para acessar dados da tPartida dentro de franquia.
                char franquiaVisitante[MAX_FRANQUIA_NOME];
                int pontosVisitante;
                char franquiaCasa[MAX_FRANQUIA_NOME];
                int pontosCasa;

                partidas[qtdPartidas] = lerPartida();

                obtemDadosPartida(partidas[qtdPartidas], franquiaVisitante, &pontosVisitante, franquiaCasa, &pontosCasa);

                associarPontosFranquias(franquias, qtdFranquias, franquiaVisitante, pontosVisitante, franquiaCasa, pontosCasa);

                qtdPartidas++;
            }
        }

        if(opcao == 'E'){
            if(qtdPartidas > 0){
                somaVitoriasFranquias(franquias, qtdFranquias);
            
                calculaAproveitamentoFranquias(franquias, qtdFranquias);
            }   
            
            break;
        }
    }

    printAproveitamentoConferencias(franquias, qtdFranquias);

    if(qtdFranquias > 0){
        printFranquias(franquias, qtdFranquias);
    }

    return 0;
}