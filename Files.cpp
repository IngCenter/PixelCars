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
