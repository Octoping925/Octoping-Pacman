#pragma once
#include "pacsystem.h"

class Player
{
public:
	Player(int xx, int yy);

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void setxy(int xx, int yy);
	bool isXYEqual(int xx, int yy);

	int getX();
	int getY();

private:
	int x, y;
};

class Enemy
{
public:
	Enemy(int xx, int yy);

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void move(int x);
	void foeset(int xx, int yy);
	void setMovedir(int x);

	int getX();
	int getY();
	int getDir();
	bool isXYEqual(int xx, int yy);


private:
	int x, y;
	int movedir;
};
