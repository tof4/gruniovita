#include <SDL2/SDL.h>
#include <stdbool.h>

#ifndef SCREEN
#define SCREEN

enum
{
    SCREEN_WIDTH = 960,
    SCREEN_HEIGHT = 544
};

extern SDL_Rect grunio;
extern SDL_Rect carrot;
extern bool flipGrunio;

void initializeScreen();
void draw();
void quit();
void nextGrunioFrame();
void nextGrunioColor();

#endif