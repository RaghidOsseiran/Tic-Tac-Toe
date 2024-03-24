#ifndef TICTACTOE
#define TICTACTOE

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define WIDTH 3
typedef enum {
    O = 'O',
    X = 'X',
    EMPTY = ' '
} XO;


typedef struct {
    char** matrix;
    bool isWon;
} game;

char** createMatrix();
void printMatrix(game* m);
int checkFreeSpace(game* g);
void playerMove(char player, game* g);
void computeMove(game* g);
char checkWinner(game* g);
void game_run(game* g);



#endif