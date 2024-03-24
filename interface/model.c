#include "model.h"




void check_pointer(void* ptr){
    if (ptr == NULL){
        fprintf(stderr, "Invalid Pointer");
        exit(EXIT_FAILURE);
    }
}





Env* init(SDL_Window* win, SDL_Renderer* ren){
    Env* res = malloc(sizeof(Env));
    check_pointer(res);
    // res->g = malloc(sizeof(game));
    // check_pointer(res->g);
    // res->g->matrix = createMatrix();
    // res->g->isWon = false;
    res->win = win;
    res->ren = ren;
    res->width = WINDOW_WIDTH;
    res->height = WINDOW_HEIGHT;
    for(int i = 0 ; i < GRID_SIZE; i++){
        for(int j = 0 ; j < GRID_SIZE; j++){
            Button* button = &res->grid[i][j];
        }
    }
    return res;
}




bool process(Env* env, SDL_Event* e){
    if (e->type == SDL_QUIT){
        return true;
    }

    return false;
}

void render(Env* env){
    return;
}


void clean(Env* env){
    SDL_DestroyRenderer(env->ren);
    SDL_DestroyWindow(env->win);
}