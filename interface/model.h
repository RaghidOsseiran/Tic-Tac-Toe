#ifndef MODEL
#define MODEL


#include "struct.h"

#define APP_NAME "TICTACTOE"
#define WINDOW_X SDL_WINDOWPOS_UNDEFINED
#define WINDOW_Y SDL_WINDOWPOS_UNDEFINED
#define ERROR(STR, ...) do { fprintf(stderr, STR, ##__VA_ARGS__); exit(EXIT_FAILURE); } while(0)
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600
#define BACKGROUND_COLOR 255,255,255
#define DELAY 100


Env* init(SDL_Window* win, SDL_Renderer* ren);
bool process(Env* env, SDL_Event* e);
void render(Env* env);
void clean(Env* env);


/* utilitarie function */

void check_pointer(void *ptr);



#endif 