#include <graphics.h>
#include "restaurant_graphics.h"

void drawRestaurantEnvironment(int screenWidth, int screenHeight)
{
    // Background wall
    setfillstyle(SOLID_FILL, COLOR(35, 42, 58));
    bar(0, 0, screenWidth, screenHeight);

    // Floor
    setfillstyle(SOLID_FILL, COLOR(225, 211, 185));
    bar(0, screenHeight * 35 / 100,
        screenWidth, screenHeight);

    // Kitchen counter
    setfillstyle(SOLID_FILL, COLOR(100, 65, 48));
    bar(screenWidth * 65 / 100,
        screenHeight * 12 / 100,
        screenWidth * 92 / 100,
        screenHeight * 29 / 100);

    // Entrance
    setfillstyle(SOLID_FILL, COLOR(75, 110, 130));
    bar(screenWidth * 4 / 100,
        screenHeight * 5 / 100,
        screenWidth * 17 / 100,
        screenHeight * 34 / 100);

    // Entrance border
    setcolor(WHITE);
    rectangle(screenWidth * 4 / 100,
              screenHeight * 5 / 100,
              screenWidth * 17 / 100,
              screenHeight * 34 / 100);

    // Labels
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(screenWidth * 6 / 100,
              screenHeight * 7 / 100,
              (char*)"ENTRANCE");

    outtextxy(screenWidth * 72 / 100,
              screenHeight * 18 / 100,
              (char*)"KITCHEN");
}