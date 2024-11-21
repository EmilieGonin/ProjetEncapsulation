#pragma once

#include <iostream>
#include <vector>

#include "Text.h"
#include "PlayerInput.h"
#include "Player.h"
#include "Ball.h"
#include "Brick.h"

#define W_WINDOW 500
#define H_WINDOW 800

class Window
{
public:
	virtual int InitLib() = 0;
	virtual int CreateWindow() = 0;
	virtual bool IsWindowCreated() = 0;
	virtual PlayerInput* InitPlayerInput() = 0;
	virtual Player* CreatePlayer() = 0;
	virtual Ball* CreateBall() = 0;
	virtual Brick* CreateBrick(int x, int y, std::string filename) = 0;
	virtual void Draw(std::vector<Sprite*> sprites) = 0;
	virtual void Clear() = 0;
	virtual void Kill() = 0;

protected:
	Text* m_fps = nullptr;
};