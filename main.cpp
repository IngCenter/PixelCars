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

struct MapObject
{
    int x;
    int y;
    int shirina;
    int visota;
    HDC image;
    bool visible;
};

void drawPicture(MapObject pic)
{
    if (pic.visible)
    {
        Win32::TransparentBlt (txDC(), pic.x, pic.y, pic.shirina, pic.visota, pic.image, 0, 0, 21, 21, TX_WHITE);
    }
}

int main()
{
    txCreateWindow (1200, 600);



    HDC image = txLoadImage ("Pics\\Wheel1.bmp");
    HDC imaje = txLoadImage ("Pics\\Wheel2.bmp");
    HDC image2 = txLoadImage ("Pics\\Wheel3.bmp");

    Knopka knop[10];
    knop[0] = {0, 0,   "�����"};
    knop[1] = {100, 10, "������"};
    knop[2] = {200, 0, "�������"};
    knop[3] = {300,10, "�����"};
    knop[4] = {400,0,  "������"};
    knop[5] = {500,10, "���������"};
    knop[6] = {600,0,  "���������"};
    knop[7] = {700,10, "������ �."};
    knop[8] = {800,0, "������ �."};
    knop[9] = {900,10, "������"};

    MapObject pic[8];
    pic[0] = {1030,80,70,70,image,false};
    pic[1] = {1110,80,70,70,image,true};
    pic[2] = {1030,160,70,70,imaje,true};
    pic[3] = {1110,160,70,70,imaje,true};
    pic[4] = {1030,240,70,70,image2,true};
    pic[5] = {1110,240,70,70,image2,true};
    pic[6] = {1030,320,70,70,image,false};
    pic[7] = {1110,320,70,70,image,false};

    while (true)
    {
        txBegin();
        txSetFillColor(TX_WHITE);
        txClear();
        txSetColor(TX_PINK);

        for (int nomer = 0; nomer < 10; nomer = nomer + 1)
        {
            drawButton(knop[nomer]);
            if (click(knop[nomer]))
            {
                txTextOut(knop[nomer].x, knop[nomer].y + 100, "�� ���");
            }
        }

        txSetFillColor(TX_BLUE);
        txSetColor(TX_PINK);
        txRectangle(100,100,825,525);

        txSetFillColor(TX_WHITE);
        txSetColor(TX_RED);
        txRectangle(1020,10,1190,590);

        if (GetAsyncKeyState('A'))
        {
            pic[0].visible = !pic[0].visible;
        }
        if (GetAsyncKeyState('S'))
        {
            pic[1].visible = !pic[1].visible;
        }

        for (int nomer = 0; nomer < 8; nomer = nomer + 1)
        {
            drawPicture (pic[nomer]);
        }

        txSleep(10);
        txEnd();

    }

    return 0;
}
