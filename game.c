#include "game.h"


typedef enum {
    O = 'O',
    X = 'X',
    EMPTY = ' '
} XO;


typedef struct {
    char** matrix;
    bool isWon;
} game;


char** createMatrix(){
    char** res = malloc(WIDTH * sizeof(char*));
    if (res == NULL){
        return NULL;
    }
    for(int i = 0 ; i < WIDTH; i++){
        res[i] = malloc(WIDTH * sizeof(char));
        if (res[i] == NULL){
            free(res);
            return NULL;
        }
    }
    for(int i = 0; i < WIDTH; i++){
        for(int j = 0 ; j < WIDTH; j++){
            res[i][j] = EMPTY;
        }
    }
    return res;
}


void printMatrix(game* m){
    if (m == NULL){
        exit(EXIT_FAILURE);
    }
    for (int i = 0 ; i < WIDTH; i++){
        for(int j = 0; j < WIDTH; j++){
            printf("|%c ", m->matrix[i][j]);
        }
        printf("|\n");
        printf("---------");
        printf("\n");
    }
}





int checkFreeSpace(game* g){
    for(int i = 0; i < WIDTH; i++){
        for(int j = 0; j < WIDTH; j++){
            if (g->matrix[i][j] == EMPTY){
                return true;
            }
        }
    }
    return false;
}


void playerMove(char player, game* g){
    int i = 0;
    int j = 0;
    printf("\n");
    do {
        printf("Player %c, please enter position of your desired move:\n", player);
        printf("\n");
        printf("x and y coordinates: \n");
        scanf("%d %d", &j, &i);
        printf("\n");

        if (i < 0 || i >= WIDTH || j < 0 || j >= WIDTH || g->matrix[i][j] != EMPTY){
            printf("[-_-] invalid coordinates given or already in use\n");
            printf("\n");
        } else {
            g->matrix[i][j] = player;
            break;
        }
    } while (g->matrix[i][j] != EMPTY);
}

void computeMove(game* g){
    printf("\n");
    printf("XXXXXXXXXXXX\n");
    printMatrix(g);
    printf("XXXXXXXXXXXX\n");
    return;
}



char checkWinner(game* g){
    // rows
    for(int i = 0; i < WIDTH; i++){
        if (g->matrix[i][0] == g->matrix[i][1] && g->matrix[i][0] == g->matrix[i][2]){
            return g->matrix[i][0];
        }
    }

    // collumns
    for(int i = 0; i < WIDTH; i++){
        if (g->matrix[0][i] == g->matrix[1][i] && g->matrix[0][i] == g->matrix[2][i]){
            return g->matrix[0][i];
        }
    }

    // diagonals

    for(int i = 0; i < WIDTH; i++){
        if (g->matrix[0][0] == g->matrix[1][1] && g->matrix[0][0] == g->matrix[2][2]){
            return g->matrix[0][0];
        }
        if (g->matrix[0][2] == g->matrix[1][1] && g->matrix[0][2] == g->matrix[2][0]){
            return g->matrix[0][2];
        }
    }
    return ' ';
}



void game_run(game* g){
    char currentPlayer = X;
    char winner;
    printMatrix(g);
    while(!g->isWon || checkFreeSpace(g) != 0){
        playerMove(currentPlayer, g);
        computeMove(g);
        winner = checkWinner(g);
        if (winner != ' ' || checkFreeSpace(g) == 0){
            break;
        } 
        if (currentPlayer == X){
            currentPlayer = O;
        } else {
            currentPlayer = X;
        }
    }
    if (winner == ' '){
        printf("Its a draw\n!");
    } else {
        printf("the winner is: %c !!!\n", currentPlayer);
    }
}



int main(){
    game* g = malloc(sizeof(game));
    g->matrix = createMatrix();
    g->isWon = false;
    game_run(g);
    return EXIT_SUCCESS;
}