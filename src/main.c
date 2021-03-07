#include <stdio.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/ctrl.h>
#include "screen.h"
#include "game.h"

SceCtrlData ctrl;
int crossButtonThreshold = 0;

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
	sceKernelExitProcess(0);
	return 0;
}
