#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAX_DIR 4

//definição do tipo posicao
typedef struct Pos{
    int x, y;
} tPos;

//leitura da matriz de ocupacoes do tabuleiro
void read_map(int m, int n, int map[m][n]) {
    for (int i=0; i < m; i++){
        for (int j=0; j < n; j++){
            scanf("%d ", &map[i][j]);
        }
    }
}

//impressao da matriz de ocupacoes (nao ocupado e ocupado, 0 e 1 respectivamente)
void print_map(int m, int n, int map[m][n]) {
    for (int i=0; i < m; i++){
        for (int j=0; j < n; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

//impressao de posicao
void print_pos (tPos p) {
    printf("(%d,%d) ", p.x+1, p.y+1);
}

//remocao de um ponto - note que basicamente remover eh voltar uma posicao na matriz em x e y
tPos remove_1(tPos p) {
    p.x--; p.y--;
    return p;
}

//compara duas posicoes
int is_same_position(tPos p1, tPos p2) {
    if (p1.x == p2.x && p1.y == p2.y)
        return TRUE;
    return FALSE;
}

//movimentacao na matriz - verificacao do tamanho total da matriz, da ocupacao da celula para a movimencao e tambem da prioridade de movimentacao
tPos move_player(int m, int n, int map[m][n], char dir, tPos player_pos) {

    if (dir == 'B') {
        if (player_pos.x+1 < m && map[player_pos.x+1][player_pos.y] == 0) {
            map[player_pos.x][player_pos.y] = 1;
            player_pos.x += 1;  
            // printf("BAIXO\n");
        }
    } else if (dir == 'C') {
        if (player_pos.x-1 > -1 && map[player_pos.x-1][player_pos.y] == 0) {
            map[player_pos.x][player_pos.y] = 1;
            player_pos.x -= 1;    
            // printf("CImA\n");        
        }
    } else if (dir == 'D') {
        if (player_pos.y+1 < n && map[player_pos.x][player_pos.y+1] == 0) {
            map[player_pos.x][player_pos.y] = 1;
            player_pos.y += 1;            
            // printf("DIREITA\n");
        }
    } else if (dir == 'E') {
        if (player_pos.y-1 > -1 && map[player_pos.x][player_pos.y-1] == 0) {
            map[player_pos.x][player_pos.y] = 1;
            player_pos.y -= 1; 
            // printf("ESQUERDA\n");           
        }
    }

    return player_pos;
}

//programa principal
int main() {

    int m, n;
    scanf("%d %d", &m, &n);
    int mapa[m][n];

    //importante - temp_pos guarda as posicoes de movimento do jogo, e player_pos eh atualizado a cada iteracao/movimento bem sucedido
    tPos start_pos, final_pos, player_pos, temp_pos;
    char prio_move[5];

    read_map(m, n, mapa);
    // print_map(m, n, mapa);

    scanf("%d %d", &start_pos.x, &start_pos.y);
    scanf("%d %d", &final_pos.x, &final_pos.y);
    start_pos = remove_1(start_pos); 
    final_pos = remove_1(final_pos);

    scanf("%s", prio_move);

    player_pos = start_pos;
    print_pos(player_pos);
    while(TRUE) 
    {        
        //verifica vetor de prioridades e tenta realizar a movimentacao - nova posicao fica em temp_pos
        for (int k=0; k<MAX_DIR; k++) {
            temp_pos = move_player(m, n, mapa, prio_move[k], player_pos);
            if (!is_same_position(temp_pos, player_pos)) {
                break;
            }                
        }        

        if (is_same_position(temp_pos, final_pos)) 
        {
            //chegou ao final do percurso desejado respeitando a prioridade
            print_pos(temp_pos);
            break;
        } else if (is_same_position(temp_pos, player_pos)) 
                {
                    //nao foi possivel fazer mais movimentos, portanto, nao eh possivel solucionar o problema
                    break;
                } else 
                {
                    //atualiza a posicao do jogador e tenta continuar movimentando
                    player_pos = temp_pos;
                    print_pos(temp_pos);
                } 
    }
    return 0;
}