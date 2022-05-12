#include <SDL2/SDL.h>
#include "screen.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

SDL_Rect grunio = {(SCREEN_WIDTH / 2) - 100, SCREEN_HEIGHT - 100, 100, 70};
SDL_Rect carrot = {0, 0, 50, 80};

SDL_Texture *grunioTextures[4][3];
SDL_Texture *carrotTextures[4];

int grunioFrame, grunioColor, carrotColor = 0;
_Bool flipGrunio = false;

SDL_Texture *loadTexture(char *path)
{
    SDL_Surface *surface = SDL_LoadBMP(path);
    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 0, 0));
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void draw()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    if (flipGrunio)
    {
        SDL_RenderCopyEx(renderer, grunioTextures[grunioColor][grunioFrame], NULL, &grunio, 0, NULL, SDL_FLIP_HORIZONTAL);
    }
    else
    {
        SDL_RenderCopy(renderer, grunioTextures[grunioColor][grunioFrame], NULL, &grunio);
    }
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderCopy(renderer, carrotTextures[carrotColor], NULL, &carrot);
    SDL_RenderPresent(renderer);
}

void initializeScreen()
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Main", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);

    grunioTextures[0][0] = loadTexture("assets/grunio_red_1.bmp");
    grunioTextures[0][1] = loadTexture("assets/grunio_red_1.bmp");
    grunioTextures[0][2] = loadTexture("assets/grunio_red_3.bmp");

    grunioTextures[1][0] = loadTexture("assets/grunio_blue_1.bmp");
    grunioTextures[1][1] = loadTexture("assets/grunio_blue_2.bmp");
    grunioTextures[1][2] = loadTexture("assets/grunio_blue_3.bmp");

    grunioTextures[2][0] = loadTexture("assets/grunio_green_1.bmp");
    grunioTextures[2][1] = loadTexture("assets/grunio_green_2.bmp");
    grunioTextures[2][2] = loadTexture("assets/grunio_green_3.bmp");

    grunioTextures[3][0] = loadTexture("assets/grunio_gray_1.bmp");
    grunioTextures[3][1] = loadTexture("assets/grunio_gray_2.bmp");
    grunioTextures[3][2] = loadTexture("assets/grunio_gray_3.bmp");

    carrotTextures[0] = loadTexture("assets/carrot_red.bmp");
    carrotTextures[1] = loadTexture("assets/carrot_blue.bmp");
    carrotTextures[2] = loadTexture("assets/carrot_green.bmp");
    carrotTextures[3] = loadTexture("assets/carrot_gray.bmp");

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