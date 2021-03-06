#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "screen.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

SDL_Rect grunio = {(SCREEN_WIDTH / 2) - 100, SCREEN_HEIGHT - 100, 100, 100};
SDL_Rect carrot = {0, 0, 20, 40};

SDL_Texture *grunioCurrentTexture;
SDL_Texture *grunioLeftTexture;
SDL_Texture *grunioRightTexture;

void draw()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, grunioCurrentTexture, NULL, &grunio);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &carrot);
    SDL_RenderPresent(renderer);
}

void initializeScreen()
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Main", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);
    grunioLeftTexture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/grunio_left.bmp"));
    grunioRightTexture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/grunio_right.bmp"));
    grunioCurrentTexture = grunioRightTexture;
    draw();
}

void quit()
{
    SDL_DestroyTexture(grunioCurrentTexture);
    SDL_DestroyTexture(grunioLeftTexture);
    SDL_DestroyTexture(grunioRightTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;
    SDL_Quit();
}

void showLeftGrunio()
{
    grunioCurrentTexture = grunioLeftTexture;
}

void showRightGrunio()
{
    grunioCurrentTexture = grunioRightTexture;
}