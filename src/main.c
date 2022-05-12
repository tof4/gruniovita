#include <stdio.h>
#include <SDL2/SDL.h>
#include "screen.h"
#include "game.h"

#ifdef VITA
#include <psp2/kernel/processmgr.h>
#include <psp2/ctrl.h>

SceCtrlData ctrl;
#endif /* VITA */

int crossButtonThreshold = 0;

#ifdef VITA
void readInput()
{
	sceCtrlPeekBufferPositive(0, &ctrl, 1);

	if (ctrl.buttons & SCE_CTRL_LEFT)
	{
		moveGrunioLeft();
	}

	if (ctrl.buttons & SCE_CTRL_RIGHT)
	{
		moveGrunioRight();
	}

	if (ctrl.buttons & SCE_CTRL_CROSS)
	{
		if (crossButtonThreshold == 0)
		{
			nextGrunioColor();
			crossButtonThreshold++;
		}
	}
	else if (crossButtonThreshold != 0)
	{
		crossButtonThreshold--;
	}
}
#endif /* VITA */

#ifdef LINUX
void readInput()
{
	SDL_PumpEvents();
	const Uint8 *keystate = SDL_GetKeyboardState(NULL);

	if (keystate[SDL_SCANCODE_LEFT])
	{
		moveGrunioLeft();
	}

	if (keystate[SDL_SCANCODE_RIGHT])
	{
		moveGrunioRight();
	}

	if (keystate[SDL_SCANCODE_SPACE])
	{
		if (crossButtonThreshold == 0)
		{
			nextGrunioColor();
			crossButtonThreshold++;
		}
	}
	else if (crossButtonThreshold != 0)
	{
		crossButtonThreshold--;
	}

	if (keystate[SDL_SCANCODE_ESCAPE])
	{
		SDL_Quit();
		exit(0);
	}
}
#endif /* LINUX */

int main(int argc, char *argv[])
{
	initializeScreen();
	initializeGame();

	while (1)
	{
		readInput();
		moveCarrot();
		draw();
	}

	quit();

#ifdef VITA
	sceKernelExitProcess(0);
#endif /* VITA */

	return 0;
}
