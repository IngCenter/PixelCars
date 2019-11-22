#include "TXLib.h"
#include "Button.cpp"
#include "Files.cpp"
#include "MapObject.cpp"
#include <fstream>
#include <string.h>
using namespace std;

const int SPRAVKA = 1;
const int REDACTOR = 0;

int main()
{
    txCreateWindow (1200, 600);

    txPlaySound("erondondon.wav");
    txSelectFont ("Comic Sans MS", 20);
    Knopka knop[6];
    knop[0] = {0, 0,   "Кузов", "Car" , "Car"};
    knop[1] = {100, 10, "Колеса", "WheelLeft" , "WheelRight" };
    knop[2] = {200, 0, "Спойлер", "Spoler" , "Spoler" };
    //knop[3] = {300,10, "Крыша", "Krisha" , "Krisha" };
    //knop[4] = {400,0,  "Выхлоп", "Vihlop" , "Vihlop" };
    //knop[5] = {500,10, "Тонировка", "Tonirovka" , "Tonirovka" };
    //knop[6] = {600,0,  "Двигатель", "Dvigatel" , "Dvigatel" };
    knop[3] = {700,10, "Справка", "Krilia P." , "Krilia P." };
    knop[4] = {800,0, "Крылья З.", "Krilia S." , "Krilia S." };
    knop[5] = {900,10, "Пороги", "Porogi" , "Porogi" };


    string category;
    string category2;
    int pageSpravka = 0;
    int COUNT_PICS = 0;

    MapObject pic[1000];

    //Марсель все стало проще,МАРСЕЛЬ ДАБАВЬ КАРТИНКИ.
    COUNT_PICS = readPics(L"Pics\\Car\\*"       ,"Pics\\Car\\"       , COUNT_PICS, pic);
    COUNT_PICS = readPics(L"Pics\\Spoler\\*"    ,"Pics\\Spoler\\"    , COUNT_PICS, pic);
    COUNT_PICS = readPics(L"Pics\\Porogi\\*"    ,"Pics\\Porogi\\"    , COUNT_PICS, pic);
    COUNT_PICS = readPics(L"Pics\\WheelRight\\*","Pics\\WheelRight\\", COUNT_PICS, pic);
    COUNT_PICS = readPics(L"Pics\\WheelLeft\\*" ,"Pics\\WheelLeft\\" , COUNT_PICS, pic);
  //COUNT_PICS = readPics(L"Pics\\WheelLeft\\*" ,"Pics\\WheelLeft\\" , COUNT_PICS, pic);

    int yCar = 30;
    int yWheelLeft = 80;
    int yWheelRight= 80;
    int ySpoler = 80;
    int yPorogi = 400;

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

        if (pic[i].category == "Car")
        {
            pic[i].x = 1030;
            pic[i].y = yCar;
            yCar = yCar + 80;
            pic[i].shirina = 140;
            pic[i].visota = 70;
        }

        if (pic[i].category == "WheelLeft")
        {
            pic[i].x = 1030;
            pic[i].y = yWheelLeft;
            yWheelLeft = yWheelLeft + 80;
            pic[i].shirina = 70;
            pic[i].visota = 70;
        }

        if (pic[i].category == "WheelRight")
        {
            pic[i].x = 1110;
            pic[i].y = yWheelRight;
            yWheelRight = yWheelRight + 80;
            pic[i].shirina = 70;
            pic[i].visota = 70;
        }

        if (pic[i].category == "Spoler")
        {
            pic[i].x = 1030;
            pic[i].y = ySpoler;
            ySpoler = ySpoler + 80;
            pic[i].shirina = 70;
            pic[i].visota = 70;
        }

        if (pic[i].category == "Porogi")
        {
            pic[i].x = 1030;
            pic[i].y = yPorogi;
            yPorogi = yPorogi + 50;
            pic[i].shirina = 70;
            pic[i].visota = 30;
        }
    }

    MapObject mapParts[COUNT_PICS];

    for (int i = 0; i < COUNT_PICS; i++)
    {
        mapParts[i].adress = pic[i].adress;
        mapParts[i].image = pic[i].image;
        mapParts[i].scr_heigth = pic[i].scr_heigth;
        mapParts[i].scr_width = pic[i].scr_width;
        mapParts[i].visible = false;
        mapParts[i].category = pic[i].category;

        if (pic[i].category == "Car")
        {
            mapParts[i].x = 210;
            mapParts[i].y = 383;
            mapParts[i].shirina = 500;
            mapParts[i].visota = 140;
        }

        if (pic[i].category == "Spoler")
        {
            mapParts[i].x = 600;
            mapParts[i].y = 353;
            mapParts[i].shirina = 100;
            mapParts[i].visota = 100;
        }

        if (pic[i].category == "Porogi")
        {
            mapParts[i].x = 350;
            mapParts[i].y = 485;
            mapParts[i].shirina = 200;
            mapParts[i].visota = 17;
        }

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

    string stroka;
    string stroka_x;
    string stroka_y;
    string stroka_adress;
    ifstream file ("1.txt");

    while (file.good())
    {
        getline(file, stroka_x);
        getline(file, stroka_y);
        getline(file, stroka_adress);
        getline(file, stroka);

        for (int i = 0; i < COUNT_PICS; i++)
        {
            if (stroka_adress == mapParts[i].adress)
            {
                mapParts[i].x = atoi(stroka_x.c_str());
                mapParts[i].y = atoi(stroka_y.c_str());
                mapParts[i].visible = true;
            }
        }
    }

    file.close();



    int nomer_Pics = -5;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();

        if ( pageSpravka == REDACTOR )
        {
            drawFon(6, knop);

            RisovanieVsehCortinok(mapParts, pic, COUNT_PICS, category, category2);

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

            Dvizenie(mapParts, nomer_Pics);

            //Select a category
            category  = selectCategory(knop, 6, category);
            category2  = selectCategory2(knop, 6, category2);

            if (click(knop[3]))
            {
                pageSpravka = 1;
                knop[3].text = "Назад";
                txSleep(200);
            }

        }

        if ( pageSpravka == SPRAVKA )
        {
            txSetFillColor(TX_WHITE);
            txClear();
            txSetColor(TX_BLUE);

            drawButton(knop[3]);

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
            if (click(knop[3]))
            {
                pageSpravka = 0;
                knop[3].text = "Справка";
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
