#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "character.h"

using namespace std;


int readMap();
int gameover(Player& p, Enemy* foe); // 적과 플레이어가 닿았는지 확인해주는 함수
int Game(int trycount);
void ai(Enemy& foe);// 적의 움직임을 관장하는 함수
void mapupdate(int score, int trycount, int maxscore, Player& player, Enemy* foe);
int getOpposite(int x);