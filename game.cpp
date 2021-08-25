#include "game.h"

FILE* fin = fopen("map.txt", "r");

int map[21][21];
int colormode = 1;


int readMap()
{
	int max = 0;

	for (int i = 1; i <= 20; ++i)
	{
		for (int j = 1; j <= 20; ++j)
		{
			fscanf(fin, "%d", &map[i][j]);
			if (map[i][j] == 1) ++max;
		}
	}

	fseek(fin, 0, SEEK_SET);
	return max;
}


int gameover(Player& p, Enemy* foe)
{
	for (int i = 1; i <= 5; ++i)
		if (p.isXYEqual(foe[i].getX(), foe[i].getY()))
			return true;

	return false;
}



int Game(int trycount)
{
	Player player(2, 2);
	Enemy foe[6] = { Enemy(-2, -2), Enemy(10, 6), Enemy(19, 6), Enemy(2, 19), Enemy(10, 2), Enemy(19, 17) };

	int score = 0, maxscore = readMap();


	while (1)
	{
		for (int i = 1; i <= 5; ++i) ai(foe[i]);
		mapupdate(score, trycount, maxscore, player, foe);


		if (GetAsyncKeyState(VK_UP) & 0x8001 && map[player.getX() - 1][player.getY()] != 2) player.moveUp();
		else if (GetAsyncKeyState(VK_DOWN) & 0x8001 && map[player.getX() + 1][player.getY()] != 2) player.moveDown();
		else if (GetAsyncKeyState(VK_LEFT) & 0x8001 && map[player.getX()][player.getY() - 1] != 2) player.moveLeft();
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8001 && map[player.getX()][player.getY() + 1] != 2) player.moveRight();
		if (GetAsyncKeyState(0x4D) & 0x8001) colormode *= -1; // 1이면 정상 모드, -1이면 무지개 색 모드



		if (gameover(player, foe)) break;
		Sleep(50);


		if (map[player.getX()][player.getY()] == 1)
		{
			map[player.getX()][player.getY()] = 0;
			++score;
		}

		if (score == 10)
		{
			system("cls");
			textcolor(11);
			gotoxy(48, 13);
			std::cout << "Victory!";
			textcolor(7);
			break;
		}
	}

	return score;
}


void ai(Enemy& foe)
{
	int way_cnt = 0;
	int chk[5] = { 0,0,0,0,0 };
	int foeX = foe.getX(), foeY = foe.getY(), foeDir = foe.getDir();
	bool moveSuccess = false;

	chk[getOpposite(foeDir)] = 1;
	
	while (moveSuccess == false)
	{
		if (chk[1] + chk[2] + chk[3] + chk[4] == 4)
		{
			foe.move(getOpposite(foeDir));
			break;
		}


		int dir = rand() % 4 + 1;
		if (chk[dir]) continue;

		if (dir == 1 && map[foeX - 1][foeY] != 2)
		{
			foe.moveUp();
			break;
		}
		else if (dir == 2 && map[foeX + 1][foeY] != 2)
		{
			foe.moveDown();
			break;
		}
		else if (dir == 3 && map[foeX][foeY - 1] != 2)
		{
			foe.moveLeft();
			break;
		}
		else if (dir == 4 && map[foeX][foeY + 1] != 2)
		{
			foe.moveRight();
			break;
		}

		else chk[dir] = 1;
	}

}

void mapupdate(int score, int trycount, int maxscore, Player& player, Enemy* foe)
{
	gotoxy(1, 1);

	for (int i = 1; i <= 20; ++i)
	{
		for (int j = 1; j <= 20; ++j)
		{
			if (player.isXYEqual(i, j))
			{
				if (colormode == -1) textcolor(rand() % 16);
				else textcolor(10);

				cout << "★";
			}

			else if (foe[1].isXYEqual(i, j) || foe[2].isXYEqual(i, j) || foe[3].isXYEqual(i, j) || foe[4].isXYEqual(i, j) || foe[5].isXYEqual(i, j))
			{
				textcolor(12), cout << "●";
			}

			else if (map[i][j] == 0) cout << "  ";
			else if (map[i][j] == 1) textcolor(14), cout << "⊙";
			else if (map[i][j] == 2) textcolor(9), cout << "■";

			textcolor(7);
		}

		cout << endl;
	}

	cout << "Try : " << trycount << endl << endl;
	cout << "Score : " << score << "  /  " << maxscore;
}


int getOpposite(int x)
{
	if (x == 1) return 2;
	if (x == 2) return 1;
	if (x == 3) return 4;
	return 3;
}