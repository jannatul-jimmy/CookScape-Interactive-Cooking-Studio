
#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <algorithm>

#include "modules/restaurant.h"

using namespace std;

int SW, SH;

// --------------------------------------
// COLOR PALETTE
// --------------------------------------

const int BG        = COLOR(14, 19, 29);
const int HEADER    = COLOR(22, 30, 43);
const int PANEL     = COLOR(27, 37, 52);
const int PANEL2    = COLOR(34, 45, 61);

const int GOLD      = COLOR(226, 174, 83);
const int LIGHTGOLD = COLOR(244, 204, 125);
const int CREAM     = COLOR(247, 240, 225);
const int MUTED     = COLOR(174, 185, 198);

const int CRUST     = COLOR(177, 112, 57);
const int CHEESE    = COLOR(241, 190, 93);
const int TOMATO    = COLOR(174, 57, 48);
const int BASIL     = COLOR(75, 126, 83);
const int APP_WHITE = COLOR(255, 255, 255);

// --------------------------------------
// FUNCTION DECLARATIONS
// --------------------------------------

void drawMenu();
void drawHeader();
void drawHero();
void drawFoodPanel();
void drawHomePizza(int cx, int cy, int r);
void drawFeatureCards();

void drawFeatureCard(
    int x, int y, int w, int h,
    const char* number,
    const char* heading,
    const char* description
);

void drawButton(
    int x, int y, int w, int h,
    const char* label
);

void drawText(
    int x, int y,
    const char* message,
    int font, int size,
    int color, int background
);

void drawLine(
    int x1, int y1,
    int x2, int y2,
    int color
);

// --------------------------------------
// MAIN FUNCTION
// --------------------------------------

int main()
{
    char title[] = "CookScape - Interactive Cooking Studio";

    int screenW = GetSystemMetrics(SM_CXSCREEN);
    int screenH = GetSystemMetrics(SM_CYSCREEN);

    initwindow(
        screenW,
        screenH,
        title,
        0, 0,
        false, true
    );

    HWND hwnd = FindWindowA(NULL, title);

    if (hwnd != NULL)
    {
        SetWindowLongPtr(
            hwnd,
            GWL_STYLE,
            WS_POPUP | WS_VISIBLE
        );

        SetWindowPos(
            hwnd,
            HWND_TOP,
            0, 0,
            screenW, screenH,
            SWP_FRAMECHANGED | SWP_SHOWWINDOW
        );
    }

    SW = getmaxx() + 1;
    SH = getmaxy() + 1;

    drawMenu();

    bool running = true;

    while (running)
    {
        // ESC = Exit application
        if (kbhit())
        {
            int key = getch();

            if (key == 27)
            {
                running = false;
                break;
            }
        }

        // Mouse click detection
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int mouseX, mouseY;

            getmouseclick(
                WM_LBUTTONDOWN,
                mouseX,
                mouseY
            );

            // START RESTAURANT button
            int buttonX = 65;
            int buttonY = SH - 265;
            int buttonW = 285;
            int buttonH = 65;

            if (
                mouseX >= buttonX &&
                mouseX <= buttonX + buttonW &&
                mouseY >= buttonY &&
                mouseY <= buttonY + buttonH
            )
            {
                runRestaurant();

                // Return to Home Screen
                drawMenu();
            }
        }

        delay(20);
    }

    closegraph();

    return 0;
}

// --------------------------------------
// MAIN MENU
// --------------------------------------

void drawMenu()
{
    cleardevice();

    setbkcolor(BG);

    setfillstyle(SOLID_FILL, BG);
    bar(0, 0, SW, SH);

    drawHeader();
    drawHero();
    drawFoodPanel();
    drawFeatureCards();
}

// --------------------------------------
// HEADER
// --------------------------------------

void drawHeader()
{
    setfillstyle(SOLID_FILL, HEADER);
    bar(0, 0, SW, 92);

    drawText(
        118, 22,
        "COOKSCAPE",
        SANS_SERIF_FONT, 4,
        CREAM, HEADER
    );

    drawText(
        120, 62,
        "INTERACTIVE COOKING STUDIO",
        SANS_SERIF_FONT, 1,
        MUTED, HEADER
    );

    int navY = 40;

    drawText(
        SW - 440, navY,
        "HOME",
        SANS_SERIF_FONT, 2,
        GOLD, HEADER
    );

    drawText(
        SW - 320, navY,
        "RESTAURANT",
        SANS_SERIF_FONT, 2,
        CREAM, HEADER
    );

    drawText(
        SW - 155, navY,
        "ABOUT",
        SANS_SERIF_FONT, 2,
        CREAM, HEADER
    );

    drawLine(0, 92, SW, 92, GOLD);
}

// --------------------------------------
// HERO SECTION
// --------------------------------------

void drawHero()
{
    int left = 65;

    drawText(
        left, 155,
        "WELCOME TO YOUR RESTAURANT",
        SANS_SERIF_FONT, 2,
        GOLD, BG
    );

    drawText(
        left, 215,
        "COOKSCAPE",
        BOLD_FONT, 7,
        CREAM, BG
    );

    drawText(
        left, 325,
        "CREATE. COOK. SERVE.",
        SANS_SERIF_FONT, 3,
        LIGHTGOLD, BG
    );

    drawText(
        left, 395,
        "Your restaurant journey starts here.",
        SANS_SERIF_FONT, 2,
        MUTED, BG
    );

    drawText(
        left, 432,
        "Manage orders, prepare delicious food",
        SANS_SERIF_FONT, 2,
        MUTED, BG
    );

    drawText(
        left, 469,
        "and make every customer happy.",
        SANS_SERIF_FONT, 2,
        MUTED, BG
    );

    int buttonY = SH - 265;

    drawButton(
        left, buttonY,
        285, 65,
        "START RESTAURANT"
    );

    drawText(
        left + 5, SH - 185,
        "PRESS ESC TO EXIT",
        SANS_SERIF_FONT, 1,
        MUTED, BG
    );
}

// --------------------------------------
// BUTTON DESIGN
// --------------------------------------

void drawButton(
    int x, int y, int w, int h,
    const char* label
)
{
    // Shadow
    setfillstyle(SOLID_FILL, BLACK);
    bar(
        x + 5, y + 5,
        x + w + 5, y + h + 5
    );

    // Button body
    setfillstyle(SOLID_FILL, GOLD);
    bar(x, y, x + w, y + h);

    setcolor(LIGHTGOLD);
    rectangle(x, y, x + w, y + h);

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    setbkcolor(GOLD);
    setcolor(BG);

    int tw = textwidth((char*)label);

    outtextxy(
        x + (w - tw) / 2,
        y + (h - 24) / 2,
        (char*)label
    );
}

// --------------------------------------
// RIGHT FOOD PANEL
// --------------------------------------

void drawFoodPanel()
{
    int panelX = SW * 57 / 100;
    int panelY = 130;

    int panelW = SW - panelX - 55;
    int panelH = SH - 330;

    setfillstyle(SOLID_FILL, PANEL);

    bar(
        panelX, panelY,
        panelX + panelW,
        panelY + panelH
    );

    setcolor(PANEL2);

    rectangle(
        panelX, panelY,
        panelX + panelW,
        panelY + panelH
    );

    int cx = panelX + panelW / 2;
    int cy = panelY + panelH / 2 + 5;

    int radius = min(
        panelW / 3,
        panelH / 3
    );

    drawHomePizza(cx, cy, radius);

    drawText(
        panelX + 30,
        panelY + panelH - 65,
        "FRESH  |  DELICIOUS  |  MADE WITH PASSION",
        SANS_SERIF_FONT, 1,
        CREAM, PANEL
    );
}

// --------------------------------------
// HOME SCREEN PIZZA
// --------------------------------------

void drawHomePizza(int cx, int cy, int r)
{
    // Plate shadow
    setfillstyle(SOLID_FILL, BLACK);

    fillellipse(
        cx + 8, cy + 10,
        r + 8, r + 8
    );

    // Outer plate
    setcolor(CREAM);
    setfillstyle(SOLID_FILL, CREAM);

    fillellipse(
        cx, cy,
        r + 5, r + 5
    );

    // Plate border
    setcolor(GOLD);

    ellipse(
        cx, cy,
        0, 360,
        r - 2, r - 2
    );

    // Inner plate
    setfillstyle(SOLID_FILL, APP_WHITE);

    fillellipse(
        cx, cy,
        r * 88 / 100,
        r * 88 / 100
    );

    // Pizza crust
    setfillstyle(SOLID_FILL, CRUST);

    fillellipse(
        cx, cy,
        r * 72 / 100,
        r * 72 / 100
    );

    // Cheese
    setfillstyle(SOLID_FILL, CHEESE);

    fillellipse(
        cx, cy,
        r * 64 / 100,
        r * 64 / 100
    );

    // Pepperoni
    setfillstyle(SOLID_FILL, TOMATO);

    fillellipse(cx - r / 3, cy - r / 4, r / 11, r / 11);
    fillellipse(cx + r / 4, cy - r / 3, r / 11, r / 11);
    fillellipse(cx + r / 3, cy + r / 5, r / 11, r / 11);
    fillellipse(cx - r / 5, cy + r / 3, r / 11, r / 11);
    fillellipse(cx + r / 10, cy + r / 10, r / 11, r / 11);

    // Basil leaves
    setfillstyle(SOLID_FILL, BASIL);

    fillellipse(cx, cy - r / 5, r / 22, r / 22);
    fillellipse(cx - r / 3, cy + r / 10, r / 22, r / 22);
    fillellipse(cx + r / 5, cy + r / 3, r / 22, r / 22);

    // Cheese highlights
    setcolor(LIGHTGOLD);

    ellipse(
        cx, cy,
        0, 360,
        r * 67 / 100,
        r * 67 / 100
    );
}

// --------------------------------------
// FEATURE CARDS
// --------------------------------------

void drawFeatureCards()
{
    int margin = 50;
    int gap = 22;

    int y = SH - 165;
    int h = 105;

    int availableW =
        SW - (margin * 2) - (gap * 2);

    int cardW = availableW / 3;

    drawFeatureCard(
        margin, y, cardW, h,
        "01",
        "DIGITAL MENU",
        "Explore food and choose your favourites"
    );

    drawFeatureCard(
        margin + cardW + gap,
        y, cardW, h,
        "02",
        "SMART KITCHEN",
        "Manage orders and prepare meals"
    );

    drawFeatureCard(
        margin + (cardW + gap) * 2,
        y, cardW, h,
        "03",
        "CUSTOMER SERVICE",
        "Serve food and complete orders"
    );
}

// --------------------------------------
// SINGLE FEATURE CARD
// --------------------------------------

void drawFeatureCard(
    int x, int y, int w, int h,
    const char* number,
    const char* heading,
    const char* description
)
{
    setfillstyle(SOLID_FILL, PANEL);

    bar(x, y, x + w, y + h);

    setcolor(GOLD);

    rectangle(
        x, y,
        x + w, y + h
    );

    drawText(
        x + 17, y + 17,
        number,
        SANS_SERIF_FONT, 2,
        GOLD, PANEL
    );

    drawText(
        x + 65, y + 17,
        heading,
        SANS_SERIF_FONT, 2,
        CREAM, PANEL
    );

    drawText(
        x + 17, y + 63,
        description,
        SANS_SERIF_FONT, 1,
        MUTED, PANEL
    );
}

// --------------------------------------
// TEXT HELPER
// --------------------------------------

void drawText(
    int x, int y,
    const char* message,
    int font, int size,
    int color, int background
)
{
    setbkcolor(background);
    setcolor(color);

    settextstyle(
        font,
        HORIZ_DIR,
        size
    );

    outtextxy(
        x, y,
        (char*)message
    );
}

// --------------------------------------
// LINE HELPER
// --------------------------------------

void drawLine(
    int x1, int y1,
    int x2, int y2,
    int color
)
{
    setcolor(color);

    line(x1, y1, x2, y2);
}
