#pragma once

#include <iostream>
#include <vector>
#include "Sprite.h"

class Window
{
public:

	virtual int InitLib() = 0;
	virtual int CreateWindow() = 0;
	virtual bool IsWindowCreated() = 0;
	virtual void Draw() = 0;
	virtual void Clear() = 0;
	virtual void Kill() = 0;

protected:

	std::vector<Sprite*> m_sprites;
	const int W_WINDOW = 500;
	const int H_WINDOW = 800;
};