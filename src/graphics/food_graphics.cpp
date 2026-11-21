
#include <graphics.h>
#include "food_graphics.h"

void drawPizza(int x, int y, int size)
{
    // Pizza base
    setcolor(COLOR(120, 65, 35));
    setfillstyle(SOLID_FILL, COLOR(190, 125, 55));
    fillellipse(x, y, size, size);

    // Cheese
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, COLOR(245, 190, 75));
    fillellipse(x, y, size - 8, size - 8);

    // Tomato toppings
    setfillstyle(SOLID_FILL, RED);
    fillellipse(x - 20, y - 10, 8, 8);
    fillellipse(x + 18, y - 15, 8, 8);
    fillellipse(x + 5, y + 22, 8, 8);

    // Green toppings
    setfillstyle(SOLID_FILL, GREEN);
    fillellipse(x - 15, y + 20, 6, 6);
    fillellipse(x + 22, y + 15, 6, 6);
}

void drawPancake(int x, int y, int size)
{
    // Bottom pancake
    setcolor(COLOR(140, 85, 35));
    setfillstyle(SOLID_FILL, COLOR(190, 125, 55));
    fillellipse(x, y + 15, size, size / 2);

    // Middle pancake
    setfillstyle(SOLID_FILL, COLOR(225, 165, 85));
    fillellipse(x, y, size, size / 2);

    // Top pancake
    setfillstyle(SOLID_FILL, COLOR(240, 190, 110));
    fillellipse(x, y - 15, size, size / 2);

    // Butter
    setfillstyle(SOLID_FILL, YELLOW);
    bar(x - 9, y - 27, x + 9, y - 15);
}

void drawSandwich(int x, int y, int size)
{
    // Bread
    setcolor(COLOR(130, 80, 35));
    setfillstyle(SOLID_FILL, COLOR(235, 190, 115));

    int bread1[] = {
        x - size, y,
        x, y - size / 2,
        x + size, y,
        x, y + size / 2,
        x - size, y
    };

    fillpoly(5, bread1);

    // Filling
    setfillstyle(SOLID_FILL, GREEN);
    int filling[] = {
        x - size + 5, y + 5,
        x, y - size / 2 + 10,
        x + size - 5, y + 5,
        x, y + size / 2 - 5,
        x - size + 5, y + 5
    };

    fillpoly(5, filling);

    // Tomato
    setfillstyle(SOLID_FILL, RED);
    fillellipse(x, y + 5, size / 3, size / 6);
}
