
#include <graphics.h>
#include "customer.h"

namespace
{
    int customerX;
    int customerY;
    int targetX;
    int targetY;

    bool customerInitialized = false;
    bool customerSeated = false;

    const int CUSTOMER_SKIN = COLOR(240, 190, 150);
    const int CUSTOMER_SHIRT = COLOR(65, 115, 175);
    const int CUSTOMER_PANTS = COLOR(40, 48, 65);

    void drawCustomer(int x, int y)
    {
        // Head
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, CUSTOMER_SKIN);
        fillellipse(x, y - 35, 13, 13);

        // Hair
        setfillstyle(SOLID_FILL, BLACK);
        fillellipse(x, y - 45, 12, 6);

        // Body
        setfillstyle(SOLID_FILL, CUSTOMER_SHIRT);
        bar(x - 12, y - 21, x + 12, y + 13);

        // Arms
        setcolor(CUSTOMER_SKIN);
        setlinestyle(SOLID_LINE, 0, 3);
        line(x - 12, y - 15, x - 21, y + 3);
        line(x + 12, y - 15, x + 21, y + 3);

        // Legs
        setcolor(CUSTOMER_PANTS);
        setlinestyle(SOLID_LINE, 0, 4);
        line(x - 6, y + 13, x - 8, y + 35);
        line(x + 6, y + 13, x + 8, y + 35);

        setlinestyle(SOLID_LINE, 0, 1);
    }
}

void initializeCustomers(int screenWidth, int screenHeight)
{
    customerX = 40;
    customerY = screenHeight * 65 / 100;

    targetX = screenWidth * 35 / 100;
    targetY = customerY;

    customerSeated = false;
    customerInitialized = true;
}

void updateCustomers()
{
    if (!customerInitialized || customerSeated)
        return;

    if (customerX < targetX)
    {
        customerX += 3;

        if (customerX >= targetX)
        {
            customerX = targetX;
            customerSeated = true;
        }
    }
}

void drawCustomers()
{
    if (!customerInitialized)
        return;

    drawCustomer(customerX, customerY);
}
