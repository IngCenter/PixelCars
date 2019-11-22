#include "TXLib.h"

int get_height  (string adress)
{
  unsigned char info[54];
  FILE*f = fopen (adress.c_str() , "r");
  fread (info, sizeof (unsigned char), 54, f);
  int height =* (int*) &info[22];

  return height;
}

int get_widht  (string adress)
{
  unsigned char info[54];
  FILE*f = fopen (adress.c_str() , "r");
  fread (info, sizeof (unsigned char), 54, f);
  int widht =* (int*) &info[18];

  return widht;
}

struct MapObject
{
    string adress;
    string category;
    int x;
    int y;
    int shirina;
    int visota;
    HDC image;
    bool visible;
    int scr_width;
    int scr_heigth;
};

void drawPicture2(MapObject pic)
{
    if (pic.visible)
    {
        Win32::TransparentBlt (txDC(), pic.x, pic.y, pic.shirina, pic.visota, pic.image, 0, 0, pic.scr_width, pic.scr_heigth, TX_WHITE);
    }
}

void Dvizenie(MapObject mapParts[], int nomer_Pics)
{
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
}

void RisovanieVsehCortinok(MapObject mapParts[], MapObject pic[], int COUNT_PICS, string category, string category2)
{
        for (int nomer = 0; nomer < COUNT_PICS; nomer = nomer + 1)
        {
            if (pic[nomer].category == category || pic[nomer].category == category2)
                {
                    drawPicture2 (pic[nomer]);
                }
            drawPicture2 (mapParts[nomer]);
        }
}



