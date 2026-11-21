
#include <graphics.h>
#include "table_graphics.h"

void drawRestaurantTables()
{
    int tableY = 420;

    for (int i = 0; i < 3; i++)
    {
        int x = 180 + i * 350;

        // Back chairs
        setfillstyle(SOLID_FILL, COLOR(190, 145, 95));
        fillellipse(x + 65, tableY - 55, 28, 22);
        fillellipse(x + 155, tableY - 55, 28, 22);

        // Table shadow
        setfillstyle(SOLID_FILL, COLOR(75, 60, 50));
        bar(x + 8, tableY + 12, x + 192, tableY + 112);

        // Table surface
        setfillstyle(SOLID_FILL, COLOR(150, 95, 55));
        bar(x, tableY, x + 200, tableY + 95);

        setcolor(COLOR(235, 190, 115));
        rectangle(x, tableY, x + 200, tableY + 95);

        // Table center decoration
        setfillstyle(SOLID_FILL, COLOR(60, 130, 85));
        fillellipse(x + 100, tableY + 45, 12, 12);

        // Front chairs
        setfillstyle(SOLID_FILL, COLOR(190, 145, 95));
        fillellipse(x + 65, tableY + 145, 28, 22);
        fillellipse(x + 155, tableY + 145, 28, 22);
    }
}
