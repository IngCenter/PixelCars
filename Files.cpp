#include "TXLib.h"
#include <Windows.h>
#include <string>
using namespace std;

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

string selectFile(HWND hWnd)
{
	const int SIZE = 100;
	char nameFile[SIZE];
	OPENFILENAMEA ofn;
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFile = nameFile;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = SIZE;
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_CREATEPROMPT;
    ofn.lpstrFilter = "Text\0*.TXT\0";

	GetOpenFileNameA(&ofn);
	return nameFile;
}

string selectFile2(HWND hWnd)
{
	const int SIZE = 100;
	char nameFile[SIZE];
	OPENFILENAMEA ofn;
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFile = nameFile;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = SIZE;
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_CREATEPROMPT;
    ofn.lpstrFilter = "Text\0*.TXT\0";

	GetSaveFileNameA(&ofn);
	return nameFile;
}

