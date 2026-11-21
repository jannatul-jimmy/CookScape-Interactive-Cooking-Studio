
#include <graphics.h>
#include "menu.h"
#include "../graphics/food_graphics.h"

namespace
{
    int selectedFood = 0;
    bool orderConfirmed = false;

    const int FOOD_PIZZA = 1;
    const int FOOD_PANCAKE = 2;
    const int FOOD_SANDWICH = 3;
}

void drawFoodMenu(int screenWidth, int screenHeight)
{
    int cardWidth = 220;
    int cardHeight = 270;
    int gap = 35;

    int totalWidth = cardWidth * 3 + gap * 2;
    int startX = (screenWidth - totalWidth) / 2;
    int cardY = screenHeight / 2 - 100;

    // Menu background
    setfillstyle(SOLID_FILL, COLOR(35, 31, 43));
    bar(0, 0, screenWidth, screenHeight);

    // Heading
    setcolor(YELLOW);
    settextstyle(3, HORIZ_DIR, 5);
    outtextxy(screenWidth / 2 - 120, 45, (char*)"FOOD MENU");

    for (int i = 0; i < 3; i++)
    {
        int x = startX + i * (cardWidth + gap);

        // Card
        setfillstyle(SOLID_FILL, COLOR(245, 235, 215));
        bar(x, cardY, x + cardWidth, cardY + cardHeight);

        if (selectedFood == i + 1)
            setcolor(YELLOW);
        else
            setcolor(WHITE);

        rectangle(x, cardY, x + cardWidth, cardY + cardHeight);

        // Food illustrations
        if (i == 0)
            drawPizza(x + cardWidth / 2, cardY + 95, 55);
        else if (i == 1)
            drawPancake(x + cardWidth / 2, cardY + 95, 55);
        else
            drawSandwich(x + cardWidth / 2, cardY + 95, 55);

        // Food names
        setcolor(BLACK);
        settextstyle(3, HORIZ_DIR, 3);

        if (i == 0)
            outtextxy(x + 65, cardY + 175, (char*)"PIZZA");
        else if (i == 1)
            outtextxy(x + 50, cardY + 175, (char*)"PANCAKE");
        else
            outtextxy(x + 55, cardY + 175, (char*)"SANDWICH");

        // Price
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        if (i == 0)
            outtextxy(x + 85, cardY + 215, (char*)"Tk. 350");
        else if (i == 1)
            outtextxy(x + 85, cardY + 215, (char*)"Tk. 180");
        else
            outtextxy(x + 85, cardY + 215, (char*)"Tk. 150");
    }

    // Confirm button
    setfillstyle(SOLID_FILL, COLOR(205, 145, 55));
    bar(screenWidth / 2 - 110, screenHeight - 100,
        screenWidth / 2 + 110, screenHeight - 45);

    setcolor(WHITE);
    settextstyle(3, HORIZ_DIR, 3);
    outtextxy(screenWidth / 2 - 82, screenHeight - 88,
              (char*)"CONFIRM ORDER");

    // Selection status
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    if (orderConfirmed)
        outtextxy(30, screenHeight - 35, (char*)"ORDER CONFIRMED!");
    else
        outtextxy(30, screenHeight - 35, (char*)"SELECT YOUR FOOD");
}

int handleMenuClick(int mouseX, int mouseY,
                    int screenWidth, int screenHeight)
{
    int cardWidth = 220;
    int cardHeight = 270;
    int gap = 35;

    int totalWidth = cardWidth * 3 + gap * 2;
    int startX = (screenWidth - totalWidth) / 2;
    int cardY = screenHeight / 2 - 100;

    if (orderConfirmed)
        return selectedFood;

    // Food selection
    for (int i = 0; i < 3; i++)
    {
        int x = startX + i * (cardWidth + gap);

        if (mouseX >= x && mouseX <= x + cardWidth &&
            mouseY >= cardY && mouseY <= cardY + cardHeight)
        {
            selectedFood = i + 1;
            return selectedFood;
        }
    }

    // Confirm order
    if (mouseX >= screenWidth / 2 - 110 &&
        mouseX <= screenWidth / 2 + 110 &&
        mouseY >= screenHeight - 100 &&
        mouseY <= screenHeight - 45)
    {
        if (selectedFood != 0)
            orderConfirmed = true;
    }

    return selectedFood;
}

int getSelectedFood()
{
    return selectedFood;
}

bool isOrderConfirmed()
{
    return orderConfirmed;
}


void resetFoodMenu()
{
    selectedFood = 0;
    orderConfirmed = false;
}
