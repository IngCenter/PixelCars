#include "TXLib.h"
#include "Struct.cpp"

int main()
{
    txCreateWindow (1200, 600);

    txSelectFont ("Comic Sans MS", 20);
    Knopka knop[10];
    knop[0] = {0, 0,   "Кузов", "Car" , "Car"};
    knop[1] = {100, 10, "Колеса", "WheelLeft" , "WheelRight" };
    knop[2] = {200, 0, "Спойлер", "Spoler" , "Spoler" };
    knop[3] = {300,10, "Крыша", "Krisha" , "Krisha" };
    knop[4] = {400,0,  "Выхлоп", "Vihlop" , "Vihlop" };
    knop[5] = {500,10, "Тонировка", "Tonirovka" , "Tonirovka" };
    knop[6] = {600,0,  "Двигатель", "Dvigatel" , "Dvigatel" };
    knop[7] = {700,10, "Крылья П.", "Krilia P." , "Krilia P." };
    knop[8] = {800,0, "Крылья З.", "Krilia S." , "Krilia S." };
    knop[9] = {900,10, "Пороги", "Porogi" , "Porogi" };


    char* category;
    char* category2;
    int COUNT_PICS = 20;

    MapObject pic[COUNT_PICS];
    pic[0] = {1030, 80,140,70,"Pics\\Car1.bmp", "Car"};
    pic[1] = {1030,160,140,70,"Pics\\Car2.bmp", "Car"};
    pic[2] = {1030,240,140,70,"Pics\\Car3.bmp", "Car"};
    pic[3] = {1030,320,140,70,"Pics\\Car4.bmp", "Car"};
    pic[4] = {1030,400,140,70,"Pics\\Car5.bmp","Car"};
    pic[5] = {1030,480,140,70,"Pics\\Car6.bmp","Car"};
    pic[6] = {1030,80,70,70,  "Pics\\Wheel2.bmp","WheelLeft"};
    pic[7] = {1110,80,70,70,  "Pics\\Wheel2.bmp","WheelRight"};
    pic[8] = {1030,160,70,70, "Pics\\Wheel3.bmp","WheelLeft"};
    pic[9] = {1110,160,70,70, "Pics\\Wheel3.bmp","WheelRight"};
    pic[10]= {1030,240,70,70,"Pics\\Wheel1.bmp","WheelLeft"};
    pic[11]= {1110,240,70,70,"Pics\\Wheel1.bmp","WheelRight"};
    pic[12]= {1030,320,70,70,"Pics\\Wheel4.bmp","WheelLeft"};
    pic[13]= {1110,320,70,70,"Pics\\Wheel4.bmp","WheelRight"};
    pic[14]= {1030,400,70,70,"Pics\\Wheel5.bmp","WheelLeft"};
    pic[15]= {1110,400,70,70,"Pics\\Wheel5.bmp","WheelRight"};
    pic[16]= {1030,80,70,70,  "Pics\\Spoler.bmp","Spoler"};
    pic[17]= {1030,160,70,70, "Pics\\Spoler2.bmp","Spoler"};
    pic[18]= {1030,240,70,30, "Pics\\Spoler3.bmp","Spoler"};
    pic[19]= {1030,320,70,30, "Pics\\Spoler4.bmp","Spoler"};

    for (int i = 0; i < COUNT_PICS; i++)
    {
        pic[i].image   = txLoadImage(pic[i].adress.c_str());
        pic[i].scr_width  = get_widht(pic[i].adress);
        pic[i].scr_heigth = get_height(pic[i].adress);
        pic[i].visible    = true;
    }

    MapObject mapParts[COUNT_PICS];
    mapParts[0]  =  {205,380,486,138};
    mapParts[1]  =  {190,370,510,155};
    mapParts[2]  =  {225,378,450,140};
    mapParts[3]  =  {230,385,470,130};
    mapParts[4]  =  {210,383,500,140};
    mapParts[5]  =  {210,383,500,140};

    mapParts[16] =  {600,353,100,100};
    mapParts[17] =  {600,353,100,100};
    mapParts[18]=  {640,300,137,137};
    mapParts[19]=  {680,253,174,174};

    for (int i = 0; i < COUNT_PICS; i++)
    {
        mapParts[i].image = pic[i].image;
        mapParts[i].scr_heigth = pic[i].scr_heigth;
        mapParts[i].scr_width = pic[i].scr_width;
        mapParts[i].visible = false;
        mapParts[i].category = pic[i].category;

        if (pic[i].category == "WheelLeft")
        {
            mapParts[i].x = 280;
            mapParts[i].y = 450;
            mapParts[i].shirina = 63;
            mapParts[i].visota = 63;
        }
        if (pic[i].category == "WheelRight")
        {
            mapParts[i].x = 560;
            mapParts[i].y = 450;
            mapParts[i].shirina = 63;
            mapParts[i].visota = 63;
        }
    }

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

        for(int a = 0; a < COUNT_PICS; a++)
        {
          if (mapParts[a].visible &&
               (txMouseButtons() == 1 &&
                txMouseX() > mapParts[a].x &&
                txMouseX() < mapParts[a].x + mapParts[a].shirina &&
                txMouseY() > mapParts[a].y &&
                txMouseY() < mapParts[a].y + mapParts[a].visota))
          {
              nomer_Pics = a;
          }
        }

        if (nomer_Pics >= 0 && GetAsyncKeyState(VK_LEFT))
           {
             mapParts[nomer_Pics].x -= 3;

           }
        if (nomer_Pics >= 0 && GetAsyncKeyState(VK_RIGHT))
           {
             mapParts[nomer_Pics].x += 3;
           }

        if (nomer_Pics >= 0 && GetAsyncKeyState(VK_UP))
           {
             mapParts[nomer_Pics].y -= 3;
           }

        if (nomer_Pics >= 0 && GetAsyncKeyState(VK_DOWN))
           {
             mapParts[nomer_Pics].y += 3;
           }

        if (nomer_Pics >= 0 && GetAsyncKeyState('X'))
           {
             mapParts[nomer_Pics].shirina = mapParts[nomer_Pics].shirina * 1.03;
             mapParts[nomer_Pics].visota  = mapParts[nomer_Pics].visota * 1.03;
           }

        if (nomer_Pics >= 0 && GetAsyncKeyState('Z'))
           {
             mapParts[nomer_Pics].shirina = mapParts[nomer_Pics].shirina * 0.99;
             mapParts[nomer_Pics].visota  = mapParts[nomer_Pics].visota * 0.99;
           }

        //выбор категории
        for (int nomer = 0; nomer < 10; nomer = nomer + 1)
        {
            if (click(knop[nomer]))
            {
                category  = knop[nomer].category;
                category2 = knop[nomer].category2;
            }
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
;;
