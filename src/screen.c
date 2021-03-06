#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include "screen.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

SDL_Rect grunio = {(SCREEN_WIDTH / 2) - 100, SCREEN_HEIGHT - 100, 100, 70};
SDL_Rect carrot = {0, 0, 20, 40};

SDL_Texture *grunioTextures[4][3];

int grunioFrame = 0;
int grunioColor = 0;

bool flipGrunio = false;

SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;

void draw()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    if (flipGrunio)
    {
        SDL_RenderCopyEx(renderer, grunioTextures[grunioColor][grunioFrame], NULL, &grunio, 0, NULL, flip);
    }
    else
    {
        SDL_RenderCopy(renderer, grunioTextures[grunioColor][grunioFrame], NULL, &grunio);
    }
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &carrot);
    SDL_RenderPresent(renderer);
}

void initializeScreen()
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Main", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);

    grunioTextures[0][0] = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/grunio_red_1.bmp"));
    grunioTextures[0][1] = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/grunio_red_1.bmp"));
    grunioTextures[0][2] = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/grunio_red_3.bmp"));
    grunioTextures[1][0] = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/grunio_blue_1.bmp"));
    grunioTextures[1][1] = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/grunio_blue_2.bmp"));
    grunioTextures[1][2] = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/grunio_blue_3.bmp"));
    grunioTextures[2][0] = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/grunio_green_1.bmp"));
    grunioTextures[2][1] = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/grunio_green_2.bmp"));
    grunioTextures[2][2] = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/grunio_green_3.bmp"));
    grunioTextures[3][0] = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/grunio_green_1.bmp"));
    grunioTextures[3][1] = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/grunio_gray_2.bmp"));
    grunioTextures[3][2] = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/grunio_gray_3.bmp"));

    draw();
}

void quit()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;
    SDL_Quit();
}

void nextGrunioFrame()
{
    grunioFrame++;
    if (grunioFrame == 3)
    {
        grunioFrame = 0;
    }
}

void nextGrunioColor()
{
    grunioColor++;
    if (grunioColor == 4)
    {
        grunioColor = 0;
    }
}