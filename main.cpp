#include "TXLib.h"
#include "Struct.cpp"

int main()
{
    txCreateWindow (1200, 600);

    txSelectFont ("Comic Sans MS", 20);
    Knopka knop[10];
    knop[0] = {0, 0,   "Кузов"};
    knop[1] = {100, 10, "Колеса"};
    knop[2] = {200, 0, "Спойлер"};
    knop[3] = {300,10, "Крыша"};
    knop[4] = {400,0,  "Выхлоп"};
    knop[5] = {500,10, "Тонировка"};
    knop[6] = {600,0,  "Двигатель"};
    knop[7] = {700,10, "Крылья П."};
    knop[8] = {800,0, "Крылья З."};
    knop[9] = {900,10, "Пороги"};


    char* category;
    char* category2;
    int COUNT_PICS = 500;

    MapObject pic[COUNT_PICS];
    pic[0] = {1030,80,140,70,  txLoadImage ("Pics\\Car1.bmp"),  true,486,138,"Car"};
    pic[1] = {1030,160,140,70, txLoadImage ("Pics\\Car2.bmp"),  true,363,113,"Car"};
    pic[2] = {1030,240,140,70, txLoadImage ("Pics\\Car3.bmp"),  true,525,151,"Car"};
    pic[3] = {1030,320,140,70, txLoadImage ("Pics\\Car4.bmp"),  true,457,135,"Car"};
    pic[4] = {1030,400,140,70, txLoadImage ("Pics\\Car5.bmp"),  true,311,89,"Car"};
    pic[5] = {1030,480,140,70, txLoadImage ("Pics\\Car6.bmp"),  true,311,89,"Car"};
    pic[6] = {1030,80,70,70,   txLoadImage ("Pics\\Wheel2.bmp"),true,21,21,"WheelLeft"};
    pic[7] = {1110,80,70,70,   txLoadImage ("Pics\\Wheel2.bmp"),true,21,21,"WheelRight"};
    pic[8] = {1030,160,70,70,  txLoadImage ("Pics\\Wheel3.bmp"),true,21,21,"WheelLeft"};
    pic[9] = {1110,160,70,70,  txLoadImage ("Pics\\Wheel3.bmp"),true,21,21,"WheelRight"};
    pic[10]= {1030,240,70,70,  txLoadImage ("Pics\\Wheel1.bmp"),true,21,21,"WheelLeft"};
    pic[11]= {1110,240,70,70,  txLoadImage ("Pics\\Wheel1.bmp"),true,21,21,"WheelRight"};
    pic[12]= {1030,320,70,70,  txLoadImage ("Pics\\Wheel4.bmp"),true,21,21,"WheelLeft"};
    pic[13]= {1110,320,70,70,  txLoadImage ("Pics\\Wheel4.bmp"),true,21,21,"WheelRight"};
    pic[14]= {1030,400,70,70,  txLoadImage ("Pics\\Wheel5.bmp"),true,21,21,"WheelLeft"};
    pic[15]= {1110,400,70,70,  txLoadImage ("Pics\\Wheel5.bmp"),true,21,21,"WheelRight"};
    pic[16]= {1030,80,70,70,   txLoadImage ("Pics\\Spoler.bmp"),true,40,40,"Spoler"};
    pic[17]= {1030,160,70,30,  txLoadImage ("Pics\\Spoler2.bmp"),true,25,8,"Spoler"};
    pic[18]= {1030,240,70,30,  txLoadImage ("Pics\\Spoler3.bmp"),true,64,30,"Spoler"};
    pic[19]= {1030,320,70,30,  txLoadImage ("Pics\\Spoler4.bmp"),true,30,52,"Spoler"};

    MapObject mapParts[COUNT_PICS];
    mapParts[0] =  {205,380,486,138,pic[0].image ,false,486,138,""};
    mapParts[1] =  {190,370,510,155,txLoadImage ("Pics\\Car2.bmp")  ,false,363,113,""};
    mapParts[2] =  {225,378,450,140,txLoadImage ("Pics\\Car3.bmp")  ,false,525,151,""};
    mapParts[3] =  {230,385,470,130,txLoadImage ("Pics\\Car4.bmp")  ,false,457,135,""};
    mapParts[4] =  {210,383,500,140,txLoadImage ("Pics\\Car5.bmp")  ,false,311,89,""};
    mapParts[5] =  {210,383,500,140,txLoadImage ("Pics\\Car6.bmp")  ,false,311,89,""};
    mapParts[6] =  {280,450,63,63,  txLoadImage ("Pics\\Wheel2.bmp"),false,21,21,""};
    mapParts[7] =  {560,450,63,63,  txLoadImage ("Pics\\Wheel2.bmp"),false,21,21,""};
    mapParts[8] =  {280,450,63,63,  txLoadImage ("Pics\\Wheel3.bmp"),false,21,21,""};
    mapParts[9] =  {560,450,63,63,  txLoadImage ("Pics\\Wheel3.bmp"),false,21,21,""};
    mapParts[10]=  {280,450,63,63,  txLoadImage ("Pics\\Wheel1.bmp"),false,21,21,""};
    mapParts[11]=  {560,450,63,63,  txLoadImage ("Pics\\Wheel1.bmp"),false,21,21,""};
    mapParts[12]=  {280,450,63,63,  txLoadImage ("Pics\\Wheel4.bmp"),false,21,21,""};
    mapParts[13]=  {560,450,63,63,  txLoadImage ("Pics\\Wheel4.bmp"),false,21,21,""};
    mapParts[14]=  {280,450,63,63,  txLoadImage ("Pics\\Wheel5.bmp"),false,21,21,""};
    mapParts[15]=  {560,450,63,63,  txLoadImage ("Pics\\Wheel5.bmp"),false,21,21,""};
    mapParts[16]=  {600,353,100,100,txLoadImage ("Pics\\Spoler.bmp"),false,40,40,""};
    mapParts[17]=  {600,353,100,100,txLoadImage ("Pics\\Spoler2.bmp"),false,25,8,""};
    mapParts[18]=  {640,300,137,137,txLoadImage ("Pics\\Spoler3.bmp"),false,64,30,""};
    mapParts[19]=  {680,253,174,174,txLoadImage ("Pics\\Spoler4.bmp"),false,30,52,""};

    int nomer_Pics = -5;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_WHITE);
        txClear();
        txSetColor(TX_BLUE);

        for (int nomer = 0; nomer < 10; nomer = nomer + 1)
        {
            drawButton(knop[nomer]);
        }

        for (int a = 0; a < COUNT_PICS; a++)
        {

            if (txMouseButtons() == 1 &&
                txMouseX() > pic[a].x &&
                txMouseX() < pic[a].x + pic[a].shirina &&
                txMouseY() > pic[a].y &&
                txMouseY() < pic[a].y + pic[a].visota)
            {
            }
        }

        txSetFillColor(TX_LIGHTGRAY);
        txSetColor(TX_BLUE);
        txRectangle(100,100,825,525);

        txSetFillColor(TX_WHITE);
        txSetColor(TX_RED);
        txRectangle(1020,10,1190,590);

        for (int nomer = 0; nomer < COUNT_PICS; nomer = nomer + 1)
        {
            if (pic[nomer].category == category || pic[nomer].category == category2)
            {
                drawPicture2 (pic[nomer]);
            }
            drawPicture2 (mapParts[nomer]);
        }


        for (int a = 0; a < COUNT_PICS; a++)
        {
            if (txMouseButtons() == 1 &&
                txMouseX() > pic[a].x &&
                txMouseX() < pic[a].x + pic[a].shirina &&
                txMouseY() > pic[a].y &&
                txMouseY() < pic[a].y + pic[a].visota &&
                (pic[a].category == category || pic[a].category == category2))
            {
                mapParts[a].visible = !mapParts[a].visible;

                for (int n = 0; n < COUNT_PICS; n++)
                {
                    if (mapParts[a].visible &&
                        a != n &&
                        pic[n].category == pic[a].category)
                    {
                        mapParts[n].visible = false;
                    }
                }

                txSleep(200);
            }
        }


       if (click(knop[3]))
        {
            category = "Roof";
            category2 = "Roof";
            txSleep(200);
        }

        if (click(knop[2]))
        {
            category = "Spoler";
            category2 = "Spoler";
            txSleep(200);
        }

        if (click(knop[1]))
        {
            category = "WheelLeft";
            category2 = "WheelRight";
            txSleep(200);
        }

        if (click(knop[0]))
        {
            category = "Car";
            category2 = "Car";
            txSleep(200);
        }

        txSleep(10);
        txEnd();

    }

    for (int nomer = 0; nomer < COUNT_PICS; nomer++)
    {
        txDeleteDC(pic[nomer].image);
        txDeleteDC(mapParts[nomer].image);
    }

    return 0;
}

