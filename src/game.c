#include <stdbool.h>
#include "screen.h"

int carrotCycle = 0;

int random(int min, int max)
{
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

bool isCatched()
{
    if (grunio.y != carrot.y)
    {
        return 0;
    }

    int difference = grunio.x - carrot.x;

    if (difference < 5 && difference > -105)
    {
        return 1;
    }

    return 0;
}

void newCarrot()
{
    carrotColor = random(0, 3);
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

    if (isCatched())
    {
        newCarrot();
        return;
    }

    if (carrot.y == SCREEN_HEIGHT)
    {
        newCarrot();
    }
}

void moveGrunioLeft()
{
    if (grunio.x != 0)
    {
        grunio.x -= 1;
        flipGrunio = true;
        nextGrunioFrame();
    }
}

void moveGrunioRight()
{
    if (grunio.x != SCREEN_WIDTH - 100)
    {
        grunio.x += 1;
        flipGrunio = false;
        nextGrunioFrame();
    }
}

void initializeGame()
{
    newCarrot();
}