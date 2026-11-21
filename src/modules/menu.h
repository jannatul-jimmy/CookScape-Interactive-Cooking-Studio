#ifndef MENU_H
#define MENU_H

void drawFoodMenu(int screenWidth, int screenHeight);

int handleMenuClick(
    int mouseX,
    int mouseY,
    int screenWidth,
    int screenHeight
);

int getSelectedFood();

bool isOrderConfirmed();

void resetFoodMenu();

#endif