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
    knop[7] = {700,10, "Справка", "Krilia P." , "Krilia P." };
    knop[8] = {800,0, "Крылья З.", "Krilia S." , "Krilia S." };
    knop[9] = {900,10, "Пороги", "Porogi" , "Porogi" };


    string category;
    string category2;
    int pageSpravka = 0;
    int COUNT_PICS = 20;

    MapObject pic[COUNT_PICS];
    pic[0] = {1030, 80,140,70,"Pics\\Car\\Car1.bmp"};
    pic[1] = {1030,160,140,70,"Pics\\Car\\Car2.bmp"};
    pic[2] = {1030,240,140,70,"Pics\\Car\\Car3.bmp"};
    pic[3] = {1030,320,140,70,"Pics\\Car\\Car4.bmp"};
    pic[4] = {1030,400,140,70,"Pics\\Car\\Car5.bmp"};
    pic[5] = {1030,480,140,70,"Pics\\Car\\Car6.bmp"};
    pic[6] = {1030,80,70,70,  "Pics\\Wheel\\Wheel2.bmp","WheelLeft"};
    pic[7] = {1110,80,70,70,  "Pics\\Wheel\\Wheel2.bmp","WheelRight"};
    pic[8] = {1030,160,70,70, "Pics\\Wheel\\Wheel3.bmp","WheelLeft"};
    pic[9] = {1110,160,70,70, "Pics\\Wheel\\Wheel3.bmp","WheelRight"};
    pic[10]= {1030,240,70,70,"Pics\\Wheel\\Wheel1.bmp","WheelLeft"};
    pic[11]= {1110,240,70,70,"Pics\\Wheel\\Wheel1.bmp","WheelRight"};
    pic[12]= {1030,320,70,70,"Pics\\Wheel\\Wheel4.bmp","WheelLeft"};
    pic[13]= {1110,320,70,70,"Pics\\Wheel\\Wheel4.bmp","WheelRight"};
    pic[14]= {1030,400,70,70,"Pics\\Wheel\\Wheel5.bmp","WheelLeft"};
    pic[15]= {1110,400,70,70,"Pics\\Wheel\\Wheel5.bmp","WheelRight"};
    pic[16]= {1030,80,70,70,  "Pics\\Spoler\\Spoler.bmp","Spoler"};
    pic[17]= {1030,160,70,70, "Pics\\Spoler\\Spoler2.bmp","Spoler"};
    pic[18]= {1030,240,70,30, "Pics\\Spoler\\Spoler3.bmp","Spoler"};
    pic[19]= {1030,320,70,30, "Pics\\Spoler\\Spoler4.bmp","Spoler"};



    for (int i = 0; i < COUNT_PICS; i++)
    {
        pic[i].image   = txLoadImage(pic[i].adress.c_str());
        pic[i].scr_width  = get_widht(pic[i].adress);
        pic[i].scr_heigth = get_height(pic[i].adress);
        pic[i].visible    = true;

        string stroka = pic[i].adress;
        int pos1 = stroka.find("\\");
        int pos2 = stroka.find("\\", pos1 + 1);
        pic[i].category = stroka.substr(pos1 + 1, pos2 - pos1 - 1);

        if (pic[i].category == "Wheel" && i % 2 == 1)
        {
            pic[i-1].category ="WheelLeft";
            pic[i].category ="WheelRight";
        }
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

//Форма выбора картинок
    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();

        if ( pageSpravka == 0 )
        {

            txSetFillColor(TX_WHITE);
            txClear();
            txSetColor(TX_BLUE);

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

            if (click(knop[7]))
            {
                pageSpravka = 1;
                knop[7].text = "назад";
                txSleep(200);
            }

        }

        if ( pageSpravka == 1 )

        {

            txSetFillColor(TX_WHITE);
            txClear();
            txSetColor(TX_BLUE);

            drawButton(knop[7]);

            txSetFillColor(TX_LIGHTGRAY);
            txSetColor(TX_BLUE);
            txRectangle(100,100,825,525);
            txDrawText ( 300, 100 , 800 , 450 ,
                "Данная программа позволяет сделать машину\n"
                " из различных деталей ,\n"
                " \n"
                " Авторы: Великий Марсель и просто Дима\n"
                " \n"
                " Найдете косяк - пинайте Диму\n"
                " Хотите поблагодарить - вот номер карты Марселя\n"
                " 4276 6900 1234 5678\n");
            if (click(knop[7]))
            {
                pageSpravka = 0;
                knop[7].text = "Справка";
                txSleep(200);
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
