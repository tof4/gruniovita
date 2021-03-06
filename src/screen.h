#include <SDL2/SDL.h>

#ifndef SCREEN
#define SCREEN

enum
{
    SCREEN_WIDTH = 960,
    SCREEN_HEIGHT = 544
};

extern SDL_Rect grunio;
extern SDL_Rect carrot;

void initializeScreen();
void draw();
void quit();
void showLeftGrunio();
void showRightGrunio();

#endif