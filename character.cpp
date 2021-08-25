#include "character.h"

Player::Player(int xx, int yy)
{
	this->x = xx;
	this->y = yy;
}

void Player::setxy(int xx, int yy)
{
	this->x = xx;
	this->y = yy;
}


bool Player::isXYEqual(int xx, int yy)
{
	return this->x == xx && this->y == yy;
}


void Player::moveLeft() { this->y -= 1; }
void Player::moveRight() { this->y += 1; }
void Player::moveUp() { this->x -= 1; }
void Player::moveDown() { this->x += 1; }
void Player::playerMove()
{


	// 벽 생각!
}

int Player::getX() { return x; }
int Player::getY() { return y; }



Enemy::Enemy(int xx, int yy)
{
	this->x = xx;
	this->y = yy;
	movedir = 1;
}

void Enemy::moveUp() { this->x -= 1, movedir = 1; }
void Enemy::moveDown() { this->x += 1, movedir = 2; }
void Enemy::moveLeft() { this->y -= 1, movedir = 3; }
void Enemy::moveRight() { this->y += 1, movedir = 4; }

void Enemy::move(int x)
{
	if (x == 1) moveUp();
	else if (x == 2) moveDown();
	else if (x == 3) moveLeft();
	else if (x == 4) moveRight();
}

void Enemy::foeset(int xx, int yy)
{
	this->x = xx;
	this->y = yy;
}

void Enemy::setMovedir(int x) { movedir = x; }

int Enemy::getX() { return x; }
int Enemy::getY() { return y; }
int Enemy::getDir() { return movedir; }
bool Enemy::isXYEqual(int xx, int yy)
{
	return this->x == xx && this->y == yy;
}