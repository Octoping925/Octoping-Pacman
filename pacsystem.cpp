#include "pacsystem.h"

void textcolor(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
};
enum
{
	BLACK,//0
	DARK_BLUE,//1
	DARK_GREEN,//2
	DARK_SKY_BLUE,//3
	DARK_RED,//4
	DARK_VOILET,//5
	DARK_YELLOW,//6
	GRAY,//7
	DARK_GRAY,//8
	BLUE,//9
	GREEN,//10
	SKY_BLUE,//11
	RED,//12
	VIOLET,//13
	YELLOW,//14
	WHITE,//15
};


void gotoxy(int xx, int yy)
{
	COORD Pos = { xx - 1, yy - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
} // 커서 위치 설정


void initCursor()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1, cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int restart()
{
	textcolor(10);
	std::cout << "\n\t\t\t\t\t다시 하겠습니까? Y/N";

	while (true)
	{
		if (GetAsyncKeyState(0x59) & 0x8001) return true; // Y
		if (GetAsyncKeyState(0x4E) & 0x8001) return false; // N
	}
}