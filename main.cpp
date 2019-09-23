#include "TXLib.h"

struct Knopka
{
     int x;
     int y;
     const char* text;

};

void drawButton(Knopka knop)
{

    txSetFillColor(TX_LIGHTBLUE);
    txRectangle(knop.x + 10,knop.y + 10,knop.x + 100,knop.y + 50);
    txDrawText (knop.x + 10,knop.y + 10,knop.x + 100,knop.y + 50, knop.text);

}

void drawButton(int x , int y, const char* text)
{
    txSetFillColor(TX_LIGHTBLUE);
    txRectangle(x + 10,y + 10,x + 100,y + 50);
    txDrawText (x + 10,y + 10,x + 100,y + 50, text);

}

bool Click (Knopka knop)
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


bool Click (int x, int y)
{
 if(txMouseButtons() == 1 &&
    txMouseX() > x + 10 &&
    txMouseX() < x + 100 &&
    txMouseY() > y + 10 &&
    txMouseY() < y + 50)
 {
  return true;
 }

  return false;
}

int main()
{
    txCreateWindow (1200, 600);

    HDC image = txLoadImage ("apple.bmp");

    Knopka knop[10];
    knop[0] = {0, 0,   "Кузов"};
    knop[1] = {100, 10, "Колеса"};
    knop[2] = {200, 0, "Спойлер"};
    knop[3] = {300,10, "Крыша"};
    knop[4] = {400,0,  "Выхлоп"};
    knop[5] = {500,10, "Танировка"};
    knop[6] = {600,0,  "Двигатель"};
    knop[7] = {700,10, "Крылья П."};
    knop[8] = {800,0, "Крылья З."};
    knop[9] = {900,10, "Пороги"};

    while (true)
    {
        txBegin();
        txSetFillColor(TX_WHITE);
        txClear();
        txSetColor(TX_PINK);

        for (int nomer = 0; nomer < 10; nomer = nomer + 1)
        {
            drawButton(knop[nomer]);
            if (Click(knop[nomer]))
            {
                txTextOut(knop[nomer].x, knop[nomer].y + 100, "ты лох");
            }
        }

        /*
        txSetFillColor(TX_BLUE);
        txSetColor(TX_PINK);
        txRectangle(100,100,825,525);

        txSetFillColor(TX_WHITE);
        txSetColor(TX_RED);
        txRectangle(1020,10,1190,590);

        Win32::TransparentBlt (txDC(), 1030, 20, 70, 70, image, 0, 0, 40, 40, TX_WHITE);
        Win32::TransparentBlt (txDC(), 1110, 20, 70, 70, image, 0, 0, 40, 40, TX_WHITE);
        Win32::TransparentBlt (txDC(), 1030,100, 70, 70, image, 0, 0, 40, 40, TX_WHITE);
        Win32::TransparentBlt (txDC(), 1110,100, 70, 70, image, 0, 0, 40, 40, TX_WHITE);
        Win32::TransparentBlt (txDC(), 1030,180, 70, 70, image, 0, 0, 40, 40, TX_WHITE);
        Win32::TransparentBlt (txDC(), 1110,180, 70, 70, image, 0, 0, 40, 40, TX_WHITE);
        Win32::TransparentBlt (txDC(), 1030,260, 70, 70, image, 0, 0, 40, 40, TX_WHITE);
        Win32::TransparentBlt (txDC(), 1110,260, 70, 70, image, 0, 0, 40, 40, TX_WHITE);
         */


        txSleep(10);
        txEnd();






    }
    return 0;
}

