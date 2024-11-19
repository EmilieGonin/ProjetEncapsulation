#pragma once

#include "Window.h"
#include "raylib.h"
#include "resource_dir.h"
#include "SpriteRayLib.h"

class WindowRayLib : public Window
{
public:
	virtual int InitLib() override;
	virtual int CreateWindow() override;
	virtual bool IsWindowCreated() override;
	virtual void Draw() override;
	virtual void Clear() override;
	virtual void Kill() override;
};