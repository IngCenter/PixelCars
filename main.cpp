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
    int scr_width;
    int scr_heigth;

};

void drawPicture(MapObject pic)
{
    if (pic.visible)
    {
        Win32::TransparentBlt (txDC(), pic.x, pic.y, pic.shirina, pic.visota, pic.image, 0, 0, 21, 21, TX_WHITE);
    }
}

void drawPicture2(MapObject pic)
{
    if (pic.visible)
    {
        Win32::TransparentBlt (txDC(), pic.x, pic.y, pic.shirina, pic.visota, pic.image, 0, 0, pic.scr_width, pic.scr_heigth, TX_WHITE);
    }
}

int main()
{
    txCreateWindow (1200, 600);



    HDC image = txLoadImage ("Pics\\Wheel1.bmp");
    HDC imaje = txLoadImage ("Pics\\Wheel2.bmp");
    HDC image2 = txLoadImage ("Pics\\Wheel3.bmp");
    HDC image3 = txLoadImage ("Pics\\Car1.bmp");


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

    MapObject pic[10];
    pic[0] = {1030,80,70,70,txLoadImage ("Pics\\Wheel1.bmp"),false};
    pic[1] = {1110,80,70,70,txLoadImage ("Pics\\Wheel1.bmp"),true};
    pic[2] = {1030,160,70,70,txLoadImage ("Pics\\Wheel2.bmp"),true};
    pic[3] = {1110,160,70,70,txLoadImage ("Pics\\Wheel2.bmp"),true};
    pic[4] = {1030,240,70,70,txLoadImage ("Pics\\Wheel3.bmp"),true};
    pic[5] = {1110,240,70,70,txLoadImage ("Pics\\Wheel3.bmp"),true};
    pic[6] = {1030,320,70,70,txLoadImage ("Pics\\Wheel1.bmp"),false};
    pic[7] = {1110,320,70,70,txLoadImage ("Pics\\Wheel1.bmp"),false};

    MapObject mapParts[10];
    mapParts[0] = {205,380,486,138,txLoadImage ("Pics\\Car1.bmp"),false,486,138};
    mapParts[1] = {205,180,363,113,txLoadImage ("Pics\\Car2.bmp"),false,363,113};
    mapParts[2] = {280,450,63,63,txLoadImage ("Pics\\Wheel2.bmp"),false,21,21};
    mapParts[3] = {560,450,63,63,txLoadImage ("Pics\\Wheel2.bmp"),false,21,21};
    mapParts[4] = {280,450,63,63,txLoadImage ("Pics\\Wheel3.bmp"),false,21,21};
    mapParts[5] = {560,450,63,63,txLoadImage ("Pics\\Wheel3.bmp"),false,21,21};

    while (!GetAsyncKeyState(VK_ESCAPE))
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
                txTextOut(knop[nomer].x, knop[nomer].y + 100, "Òû ëîõ");
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

        drawPicture2 (mapParts[0]);
        drawPicture2 (mapParts[1]);
        drawPicture2 (mapParts[2]);
        drawPicture2 (mapParts[3]);
        drawPicture2 (mapParts[4]);
        drawPicture2 (mapParts[5]);

        if (txMouseButtons() == 1 &&
            txMouseX() > pic[1].x &&
            txMouseX() < pic[1].x + pic[1].shirina &&
            txMouseY() > pic[1].y &&
            txMouseY() < pic[1].y + pic[1].visota)
        {
            mapParts[0].visible = !mapParts[0].visible;
            mapParts[1].visible = !mapParts[1].visible;
            txSleep(200);
        }

        if (txMouseButtons() == 1 &&
            txMouseX() > pic[2].x &&
            txMouseX() < pic[2].x + pic[2].shirina &&
            txMouseY() > pic[2].y &&
            txMouseY() < pic[2].y + pic[2].visota)
        {
            mapParts[2].visible = !mapParts[2].visible;
            txSleep(200);
        }

        if (txMouseButtons() == 1 &&
            txMouseX() > pic[3].x &&
            txMouseX() < pic[3].x + pic[3].shirina &&
            txMouseY() > pic[3].y &&
            txMouseY() < pic[3].y + pic[3].visota)
        {
            mapParts[3].visible = !mapParts[3].visible;
            txSleep(200);
        }

        if (txMouseButtons() == 1 &&
            txMouseX() > pic[4].x &&
            txMouseX() < pic[4].x + pic[4].shirina &&
            txMouseY() > pic[4].y &&
            txMouseY() < pic[4].y + pic[4].visota)
        {
            mapParts[4].visible = !mapParts[4].visible;
            txSleep(200);
        }

        if (txMouseButtons() == 1 &&
            txMouseX() > pic[5].x &&
            txMouseX() < pic[5].x + pic[5].shirina &&
            txMouseY() > pic[5].y &&
            txMouseY() < pic[5].y + pic[5].visota)
        {
            mapParts[5].visible = !mapParts[5].visible;
            txSleep(200);
        }

      txSleep(10);
        txEnd();

    }

    return 0;
}
