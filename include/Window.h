#pragma once

#include <iostream>

class Window
{
public:
	virtual int InitLib() = 0;
	virtual int CreateWindow() = 0;
	virtual bool IsWindowCreated() = 0;
	virtual void Draw() = 0;
	virtual void Clear() = 0;
	virtual void Kill() = 0;
};

