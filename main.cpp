
#include "TXLib.h"
void drawButton(int x , int y, const char* text)
{
    txSetFillColor(TX_LIGHTBLUE);
    txRectangle(x + 10,y + 10,x + 100,y + 50);
    txDrawText (x + 10,y + 10,x + 100,y + 50, text);

}

int main()
    {
txCreateWindow (1200, 600);

txSetFillColor(TX_WHITE);

txClear();

txSetColor(TX_PINK);

drawButton(0, 0,   "Кузов");

drawButton(100,10, "Колеса");

drawButton(200,0,  "Спойлер");

drawButton(300,10, "Крыша");

drawButton(400,0,  "Выхлоп");

drawButton(500,10, "Танировка");

drawButton(600,0,  "Двигатель");

drawButton(700,10, "Крылья П.");

drawButton(800,0,  "Крылья З.");

drawButton(900,10, "Пороги");

txRectangle(100,100,825,525);

return 0;
}

