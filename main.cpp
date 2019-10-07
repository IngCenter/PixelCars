#include "TXLib.h"
#include "Struct.cpp"

int main()
{
    txCreateWindow (1200, 600);

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

    MapObject pic[15];
    pic[0] = {1030,80,140,70,  txLoadImage ("Pics\\Car1.bmp"),  false,486,138};
    pic[1] = {1030,160,140,70, txLoadImage ("Pics\\Car2.bmp"),  false,363,113};
    pic[2] = {1030,240,140,70,  txLoadImage ("Pics\\Car3.bmp"),  false,525,151};
    pic[3] = {1030,320,140,70,  txLoadImage ("Pics\\Car4.bmp"),  false,457,135};
    pic[4] = {1030,400,140,70,  txLoadImage ("Pics\\Car5.bmp"),  false,311,89};
    pic[5] = {1030,480,140,70, txLoadImage ("Pics\\Car6.bmp"),  false,311,89};
    pic[6] = {1030,160,70,70,  txLoadImage ("Pics\\Wheel2.bmp"),false,21,21};
    pic[7] = {1110,160,70,70,  txLoadImage ("Pics\\Wheel2.bmp"),false,21,21};
    pic[8] = {1030,240,70,70,  txLoadImage ("Pics\\Wheel3.bmp"),false,21,21};
    pic[9] = {1110,240,70,70,  txLoadImage ("Pics\\Wheel3.bmp"),false,21,21};
    pic[10] ={1030,80,70,70,   txLoadImage ("Pics\\Spoler.bmp"),false,40,40};


    MapObject mapParts[15];
    mapParts[0] =  {205,380,486,138,txLoadImage ("Pics\\Car1.bmp")  ,false,486,138};
    mapParts[1] =  {205,180,363,113,txLoadImage ("Pics\\Car2.bmp")  ,false,363,113};
    mapParts[2] =  {225,378,450,140,txLoadImage ("Pics\\Car3.bmp")  ,false,525,151};
    mapParts[3] =  {600,351,457,135,txLoadImage ("Pics\\Car4.bmp")  ,false,457,135};
    mapParts[4] =  {600,351,311,89, txLoadImage ("Pics\\Car5.bmp")  ,false,311,89};
    mapParts[5] =  {600,351,311,89, txLoadImage ("Pics\\Car6.bmp")  ,false,311,89};
    mapParts[6] =  {280,450,63,63,  txLoadImage ("Pics\\Wheel2.bmp"),false,21,21};
    mapParts[7] =  {560,450,63,63,  txLoadImage ("Pics\\Wheel2.bmp"),false,21,21};
    mapParts[8] =  {280,450,63,63,  txLoadImage ("Pics\\Wheel3.bmp"),false,21,21};
    mapParts[9] =  {560,450,63,63,  txLoadImage ("Pics\\Wheel3.bmp"),false,21,21};
    mapParts[10] = {600,353,100,100,txLoadImage ("Pics\\Spoler.bmp"),false,40,40};






    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_WHITE);
        txClear();
        txSetColor(TX_GRAY);

        for (int nomer = 0; nomer < 10; nomer = nomer + 1)
        {
            drawButton(knop[nomer]);
        }

        txSetFillColor(TX_LIGHTGRAY);
        txSetColor(TX_BLUE);
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

        for (int nomer = 0; nomer < 15; nomer = nomer + 1)
        {
            drawPicture2 (pic[nomer]);
            drawPicture2 (mapParts[nomer]);
        }

        for (int a = 0; a < 15; a++)
        {
            if (txMouseButtons() == 1 &&
                txMouseX() > pic[a].x &&
                txMouseX() < pic[a].x + pic[a].shirina &&
                txMouseY() > pic[a].y &&
                txMouseY() < pic[a].y + pic[a].visota &&
                pic[a].visible)
            {
                mapParts[a].visible = !mapParts[a].visible;
                txSleep(200);
            }
        }


        if (click(knop[0]))
        {
            for (int nomer = 0; nomer < 15; nomer = nomer + 1)
            {
                pic[nomer].visible = false;
            }
            pic[0].visible = true;
            pic[1].visible = true;
            pic[2].visible = true;
            pic[3].visible = true;
            pic[4].visible = true;
            pic[5].visible = true;
            txSleep(200);
        }

        if (click(knop[1]))
        {
            for (int nomer = 0; nomer < 15; nomer = nomer + 1)
            {
                pic[nomer].visible = false;
            }
            pic[6].visible = true;
            pic[7].visible = true;
            pic[8].visible = true;
            pic[9].visible = true;
            txSleep(200);
        }


        if (click(knop[2]))
        {
            for (int nomer = 0; nomer < 15; nomer = nomer + 1)
            {
                pic[nomer].visible = false;
            }
            pic[10].visible = true;
            txSleep(200);
        }

      txSleep(10);
        txEnd();

    }

    return 0;
}
