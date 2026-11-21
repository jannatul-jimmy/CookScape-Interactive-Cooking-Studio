
#include <graphics.h>
#include <conio.h>
#include <windows.h>

#include "restaurant.h"
#include "customer.h"
#include "menu.h"

#include "../graphics/restaurant_graphics.h"
#include "../graphics/table_graphics.h"

// --------------------------------------
// DRAW RESTAURANT ENVIRONMENT
// --------------------------------------

void drawRestaurant()
{
    int sw = getmaxx() + 1;
    int sh = getmaxy() + 1;

    cleardevice();

    // Restaurant background, entrance and kitchen
    drawRestaurantEnvironment(sw, sh);

    // Tables and chairs
    drawRestaurantTables();

    // Customer
    drawCustomers();
}

// --------------------------------------
// RUN RESTAURANT
// --------------------------------------

void runRestaurant()
{
    int sw = getmaxx() + 1;
    int sh = getmaxy() + 1;

    // Initialize customer and menu
    initializeCustomers(sw, sh);
    resetFoodMenu();

    int arrivalFrames = 0;

    bool menuActive = false;

    while (true)
    {
        // ESC = Return to Home Screen
        if (kbhit())
        {
            int key = getch();

            if (key == 27)
                break;
        }

        // ----------------------------------
        // CUSTOMER ARRIVAL PHASE
        // ----------------------------------

        if (!menuActive)
        {
            updateCustomers();

            drawRestaurant();

            arrivalFrames++;

            // Open menu after customer arrives
            if (arrivalFrames >= 230)
            {
                menuActive = true;
            }
        }

        // ----------------------------------
        // FOOD MENU PHASE
        // ----------------------------------

        else
        {
            drawFoodMenu(sw, sh);

            // Mouse click detection
            if (ismouseclick(WM_LBUTTONDOWN))
            {
                int mouseX, mouseY;

                getmouseclick(
                    WM_LBUTTONDOWN,
                    mouseX,
                    mouseY
                );

                handleMenuClick(
                    mouseX,
                    mouseY,
                    sw,
                    sh
                );

                // Order confirmation
                if (isOrderConfirmed())
                {
                    drawFoodMenu(sw, sh);

                    delay(1800);

                    // Return to Home Screen
                    break;
                }
            }
        }

        delay(20);
    }
}
