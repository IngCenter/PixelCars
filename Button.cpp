#include "TXLib.h"

struct Knopka
{
     int x;
     int y;
     const char* text;
     string category;
     string category2;
};

void drawButton(Knopka knop)
{
    txSetFillColor(TX_LIGHTGRAY);
    txRectangle(knop.x + 10,knop.y + 10,knop.x + 100,knop.y + 50);
    txDrawText (knop.x + 10,knop.y + 10,knop.x + 100,knop.y + 50, knop.text);
}

bool click (Knopka knop)
{
    if(txMouseButtons() == 1 &&
        txMouseX() > knop.x + 10 &&
        txMouseX() < knop.x + 100 &&
        txMouseY() > knop.y + 10 &&
        txMouseY() < knop.y + 50)
    {
        return true;
    }

    return false;
}

string selectCategory(Knopka knop[], int count_btn, string category)
{
    for (int nomer = 0; nomer < count_btn; nomer = nomer + 1)
    {
        if (click(knop[nomer]))
        {
            category  = knop[nomer].category;
        }
    }

    return category;
}

string selectCategory2(Knopka knop[], int count_btn, string category2)
{

    for (int nomer = 0; nomer < count_btn; nomer = nomer + 1)
    {
        if (click(knop[nomer]))
        {
            category2 = knop[nomer].category2;
        }
    }

    return category2;
}

void drawFon(int count_btn, Knopka knop[])
{
    txSetFillColor(TX_WHITE);
    txClear();
    txSetColor(TX_BLUE);

    for (int nomer = 0; nomer < count_btn; nomer = nomer + 1)
    {
        drawButton(knop[nomer]);
    }

    txSetFillColor(TX_LIGHTGRAY);
    txSetColor(TX_BLUE);
    txRectangle(100,100,825,525);

    txSetFillColor(TX_WHITE);
    txSetColor(TX_RED);
    txRectangle(1020,10,1190,590);
}

