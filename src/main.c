#include <stdio.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/ctrl.h>
#include "screen.h"
#include "game.h"

SceCtrlData ctrl;

void readInput()
{
	sceCtrlPeekBufferPositive(0, &ctrl, 1);

	switch (ctrl.buttons)
	{

	case SCE_CTRL_LEFT:
		moveGrunioLeft();
		break;

	case SCE_CTRL_RIGHT:
		moveGrunioRight();
		break;
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
