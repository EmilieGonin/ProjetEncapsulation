#pragma once

#include <iostream>
#include <vector>

#include "Player.h"
#include "Brick.h"

#define W_WINDOW 500
#define H_WINDOW 800

class Window
{
public:

	virtual int InitLib() = 0;
	virtual int CreateWindow() = 0;
	virtual bool IsWindowCreated() = 0;
	virtual Player* CreatePlayer() = 0;
	virtual Brick* CreateBrick(int x, int y) = 0;
	virtual void Draw(std::vector<Sprite*> sprites) = 0;
	virtual void Clear() = 0;
	virtual void Kill() = 0;
};