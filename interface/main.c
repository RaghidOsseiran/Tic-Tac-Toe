#include "model.h"





int main(){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (SDL_INIT_EVERYTHING < 0){
        ERROR("ERROR: SDL_INIT_VIDEO (%s)", SDL_GetError());
    }

    window = SDL_CreateWindow(
        APP_NAME,
        WINDOW_X,
        WINDOW_Y,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_RESIZABLE
    );

    if (!window){
        ERROR("ERROR: null window (%s)", SDL_GetError());
    }

    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if(!renderer){
        ERROR("ERROR: null renderer (%s)", SDL_GetError());
    }

   
  /* initialize your environment */
    Env* env = init(window, renderer);

    /* main render loop */
    SDL_Event e;
    bool running = false;
    while (!running) {
        /* manage events */
        while (SDL_PollEvent(&e)) {
        /* process your events */
        running = process(env, &e);
        if (running) break;
    }

        /* background in gray */
        SDL_SetRenderDrawColor(renderer, BACKGROUND_COLOR, 0xFF);
        SDL_RenderClear(renderer);

        /* render all what you want */
        render(env);
        SDL_RenderPresent(renderer);
        SDL_Delay(DELAY);
    }

    /* clean your environment */
    clean(env);
    SDL_Quit();

    return EXIT_SUCCESS;


}