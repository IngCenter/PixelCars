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

