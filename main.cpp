#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

int main()
{
	int trycount = 0;

	initCursor();

	while (++trycount)
	{
		Game(trycount);
		if (!restart()) break;
		system("cls");
	}

	return 0;
}