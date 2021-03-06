#include <stdio.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/ctrl.h>
#include <SDL2/SDL.h>

enum
{
	SCREEN_WIDTH = 960,
	SCREEN_HEIGHT = 544
};

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Rect fillRect = {
	SCREEN_HEIGHT - 50,
	(SCREEN_WIDTH / 2) - 50,
	50,
	50};

SDL_Texture *grunioLeft;
SDL_Texture *grunioRight;

SceCtrlData ctrl;

void draw(int strona)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	if (strona == 0)
	{
		SDL_RenderCopy(renderer, grunioLeft, NULL, &fillRect);
	}
	else
	{
		SDL_RenderCopy(renderer, grunioRight, NULL, &fillRect);
	}

	SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[])
{

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Main", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);

	grunioLeft = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/grunio_left.bmp"));
	grunioRight = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/grunio_right.bmp"));

	draw(0);

	while (1)
	{
		sceCtrlPeekBufferPositive(0, &ctrl, 1);

		switch (ctrl.buttons)
		{
		case SCE_CTRL_LEFT:
			fillRect.x -= 1;
			draw(0);
			break;

		case SCE_CTRL_RIGHT:
			fillRect.x += 1;
			draw(1);
			break;

		default:
			break;
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;
	SDL_Quit();
	sceKernelExitProcess(0);
	return 0;
}
