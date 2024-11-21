#pragma once

#include "Window.h"
#include "raylib.h"
#include "resource_dir.h"
#include "SpriteRayLib.h"
#include "TextRayLib.h"

class WindowRayLib : public Window
{
public:

	virtual int InitLib() override;
	virtual int CreateWindow() override;
	virtual bool IsWindowCreated() override;
	virtual Player* CreatePlayer() override;
	virtual Ball* CreateBall() override;
	virtual Brick* CreateBrick(int x, int y) override;
	virtual void Draw(std::vector<Sprite*> sprites) override;
	virtual void Clear() override;
	virtual void Kill() override;

private:
	Font m_font;
};