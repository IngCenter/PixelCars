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
        Win32::TransparentBlt (txDC(), pic.x, pic.y, pic.shirina, pic.visota, pic.image, 0, 0, 40, 40, TX_WHITE);
    }
}

int main()
{
    txCreateWindow (1200, 600);

    HDC image = txLoadImage ("apple.bmp");

    Knopka knop[10];
    knop[0] = {0, 0,   "Êóçîâ"};
    knop[1] = {100, 10, "Êîëåñà"};
    knop[2] = {200, 0, "Ñïîéëåð"};
    knop[3] = {300,10, "Êðûøà"};
    knop[4] = {400,0,  "Âûõëîï"};
    knop[5] = {500,10, "Òàíèðîâêà"};
    knop[6] = {600,0,  "Äâèãàòåëü"};
    knop[7] = {700,10, "Êðûëüÿ Ï."};
    knop[8] = {800,0, "Êðûëüÿ Ç."};
    knop[9] = {900,10, "Ïîðîãè"};

        MapObject pic[8];
        pic[0] = {1030,20,70,70,image,false};
        pic[1] = {1110,20,70,70,image,false};
        pic[2] = {1030,100,70,70,image,false};
        pic[3] = {1110,100,70,70,image,false};
        pic[4] = {1030,180,70,70,image,false};
        pic[5] = {1110,180,70,70,image,false};
        pic[6] = {1030,260,70,70,image,false};
        pic[7] = {1110,260,70,70,image,false};

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
                txTextOut(knop[nomer].x, knop[nomer].y + 100, "òû ëîõ");
            }
        }

        txSetFillColor(TX_BLUE);
        txSetColor(TX_PINK);
        txRectangle(100,100,825,525);

        txSetFillColor(TX_WHITE);
        txSetColor(TX_RED);
        txRectangle(1020,10,1190,590);

        if (GetAsyncKeyState('0'))
        {
            pic[0].visible = !pic[0].visible;
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