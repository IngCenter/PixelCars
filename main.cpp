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

    MapObject pic[10];
    pic[0] = {1030,80,70,70,image,false};
    pic[1] = {1110,80,70,70,image,true};
    pic[2] = {1030,160,70,70,imaje,true};
    pic[3] = {1110,160,70,70,imaje,true};
    pic[4] = {1030,240,70,70,image2,true};
    pic[5] = {1110,240,70,70,image2,true};
    pic[6] = {1030,320,70,70,image,false};
    pic[7] = {1110,320,70,70,image,false};
    pic[8] = {205,380,486,138,txLoadImage ("Pics\\Car1.bmp"),false,486,138};
    pic[9] = {205,180,363,113,txLoadImage ("Pics\\Car2.bmp"),false,363,113};
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
                txTextOut(knop[nomer].x, knop[nomer].y + 100, "Г’Г» Г«Г®Гµ");
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

        drawPicture2 (pic[8]);
        drawPicture2 (pic[9]);

     if(txMouseButtons() == 1 &&
        txMouseX() > pic[1].x &&
        txMouseX() < pic[1].x + pic[1].shirina &&
        txMouseY() > pic[1].y &&
        txMouseY() < pic[1].y + pic[1].visota)
     {
        pic[8].visible = !pic[8].visible;
        pic[9].visible = !pic[9].visible;
        txSleep(200);
     }

      txSleep(10);
        txEnd();

    }

    return 0;
}
