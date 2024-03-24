#ifndef STRUCT
#define STRUCT


#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// #include "../game.h"


#define GRID_SIZE 3

typedef struct Env_t Env;




typedef struct Button{
    Env* env;
    SDL_Color color;
    int width;
    int height;
    SDL_Texture* text;
    void (*action)(Env*, SDL_Point);
    void (*display)(Button*);
} Button ;


struct Env_t{
    SDL_Window* win;
    SDL_Renderer* ren;
    int width;
    int height;
    Button grid[GRID_SIZE][GRID_SIZE];
};



#endif