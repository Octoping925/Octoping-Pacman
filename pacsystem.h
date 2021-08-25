#pragma once
#include <windows.h>
#include <iostream>

// 0 = 공백, 1 = 동전, 2 = 벽, 20x20 크기 맵

void textcolor(int a);
void gotoxy(int xx, int yy); // 커서 위치 설정
void initCursor();
int restart();