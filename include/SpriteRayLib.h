#pragma once

#include "Sprite.h"
#include "raylib.h"

class SpriteRayLib : public Sprite
{
public:

	SpriteRayLib(std::string path, int x, int y);

	virtual void* Get() override { return (void*)&m_texture; }
	virtual int GetWidth() override;
	virtual int GetHeight() override;

private:

	Texture2D m_texture;
};