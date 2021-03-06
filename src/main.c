#include <stdio.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/ctrl.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

enum
{
	SCREEN_WIDTH = 960,
	SCREEN_HEIGHT = 544
};

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

SDL_Rect grunio = {SCREEN_HEIGHT, (SCREEN_WIDTH / 2) - 100, 100, 100};
SDL_Rect carrot = {0, 0, 20, 40};

SDL_Texture *grunioCurrentTexture;
SDL_Texture *grunioLeftTexture;
SDL_Texture *grunioRightTexture;

SceCtrlData ctrl;

int carrotCycle = 0;

void draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, grunioCurrentTexture, NULL, &grunio);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &carrot);
	SDL_RenderPresent(renderer);
}

void readInput()
{
	sceCtrlPeekBufferPositive(0, &ctrl, 1);

	switch (ctrl.buttons)
	{

	case SCE_CTRL_LEFT:
		if (grunio.x != 0)
		{
			grunio.x -= 1;
			grunioCurrentTexture = grunioLeftTexture;
		}
		break;

	case SCE_CTRL_RIGHT:
		if (grunio.x != SCREEN_WIDTH - 50)
		{
			grunio.x += 1;
			grunioCurrentTexture = grunioRightTexture;
		}
		break;
	}
}

int random(int min, int max)
{
	return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int isCatched()
{
	if (grunio.y != carrot.y)
	{
		return 0;
	}

	int difference = grunio.x - carrot.x;

	if (difference < 90 && difference > -90)
	{
		return 1;
	}

	return 0;
}

void newCarrot()
{
	carrot.x = random(0, SCREEN_WIDTH - 20);
	carrot.y = 0;
}

void moveCarrot()
{
	if (carrotCycle != 2)
	{
		carrotCycle++;
		return;
	}

	carrotCycle = 0;
	carrot.y++;

	if (isCatched() == 1)
	{
		newCarrot();
		return;
	}

	if (carrot.y == SCREEN_HEIGHT)
	{
		newCarrot();
	}
}

int main(int argc, char *argv[])
{

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Main", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);

	grunioLeftTexture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/grunio_left.bmp"));
	grunioRightTexture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/grunio_right.bmp"));
	grunioCurrentTexture = grunioLeftTexture;

	newCarrot();
	draw();

	while (1)
	{
		readInput();
		moveCarrot();
		draw();
	}

	SDL_DestroyTexture(grunioCurrentTexture);
	SDL_DestroyTexture(grunioLeftTexture);
	SDL_DestroyTexture(grunioRightTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;
	SDL_Quit();
	sceKernelExitProcess(0);
	return 0;
}
