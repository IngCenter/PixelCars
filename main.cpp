
#include "TXLib.h"
void drawButton(int x , int y, const char* text)
{
    txSetFillColor(TX_LIGHTBLUE);
    txRectangle(x + 10,y + 10,x + 100,y + 50);
    txDrawText (x + 10,y + 10,x + 100,y + 50, text);

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

    while (true)
    {

        txBegin();

        txSetFillColor(TX_WHITE);

        txClear();

        txSetColor(TX_PINK);

        drawButton(0, 0,   "�����");

        if (Click(0, 0))
        {
            txTextOut(400, 10, "�� ���");
        }

        drawButton(100,10, "������");

        if (Click(100, 10))
        {
            txTextOut(500, 10, "�� ���");
        }

        drawButton(200,0,  "�������");

        if (Click(200, 0))
        {
            txTextOut(600, 10, "�� ���");
        }

        drawButton(300,10, "�����");

        if (Click(300, 10))
        {
            txTextOut(700, 10, "�� ���");
        }

        drawButton(400,0,  "������");

        if (Click(400, 0))
        {
            txTextOut(800, 10, "�� ���");
        }

        drawButton(500,10, "���������");

        if (Click(500, 10))
        {
            txTextOut(900, 10, "�� ���");
        }

        drawButton(600,0,  "���������");

        if (Click(600, 0))
        {
            txTextOut(1000, 10, "�� ���");
        }

        drawButton(700,10, "������ �.");

        if (Click(700, 10))
        {
            txTextOut(1000, 10, "�� ���");
        }

        drawButton(800,0,  "������ �.");

        if (Click(800, 0))
        {
            txTextOut(1000, 10, "�� ���");
        }

        drawButton(900,10, "������");

        if (Click(900, 10))
        {
            txTextOut(1000, 10, "�� ���");
        }


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



        txSleep(10);
        txEnd();






    }
    return 0;
}

